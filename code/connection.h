/*
 * @Author       : mark
 * @Date         : 2020-07-02
 * @copyleft Apache 2.0
 */ 
#ifndef CONNECTION_H
#define CONNECTION_H

#include "common.h"



class Connection
    : public boost::enable_shared_from_this<Connection> {
public:
    Connection(boost::asio::io_service &io_service) :io_service_(io_service) , socket_(io_serverice) {
        buffer_ = std::make_shared<std::array<char, MAX_PACK_SIZE>>();
        len_ = { 0 };
        opt_ = { 0 };
    }

    void start() {
        static tcp::no_delay option(true);
        socket_.set_option(option);
        start_chains();
    }
    
    tcp::socket& socket() {
        return socket_;
    }

private:
    void Start_Chains_() {
        read_opt_();
    }
    void read_opt() {

    }

    void read_msgpack_len_() {
        auto self = this->shared_from_this();
        auto async_buffer = buffer_; 

        boost::asio::async_read(socket_, boost::asio::buffer(len_, 4)),
            [this, self, asyncBuffer] (const boost::system::error_code& ec, std::size_t size) {
                std::cout << socket_.remote_endpoint().address() << ":"
                         << socket_.remote_endpoint().port() << " len data rec finish!" << std::endl;
                std::cout << socket_.remote_endpoint().address() << ":"
                         << socket_.remote_endpoint().port() << " original  data " << len_ << std::endl;  
                len = boost::asio::detail::socket_ops::network_to_host_long(int(*(int*)len_));
                std::cout << socket_.remote_endpoint().address() << ":" 
                        << socket_.remote_endpoint().port() << " len " << opt << std::endl;
                
                read_msgpack_();

            }
    }
    void read_msgpack_();

    void rpc_calculate_return_();
    
private:
    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    boost::asio::streambuf s_buff_;
    std::shared_ptr<std::array<char, MAX_PACK_SIZE>> buffer_;
    char lens_[4];
    int len_;
    char opts_[4];
    int opt_;
    msgpack::object_handle msg_;
};

#endif //CONNECTION_H