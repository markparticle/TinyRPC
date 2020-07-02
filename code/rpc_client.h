/*
 * @Author       : mark
 * @Date         : 2020-07-02
 * @copyleft Apache 2.0
 */ 
#ifndef RPC_CLIENT_H
#define RPC_CLIENT_H

#include "common.h"

class RpcClient: public boost::enable_shared_from_this<RpcClient> 
{
public:
    RpcClient(boost::asio::io_service& io_service, tcp::endpoint& endpointe);
    int add(int a, int b);
    int minus(int a, int b);
    int multi(int a, int b);
    int div(int a, int b);
    int start(int opt, int a, int b);
public:
    construct_data_(size_t opt, int a, int b);
    void send_receive_data_(const boost::system::error_code& ec);
    void receive_data_(const boost::system::error_code& ec);
    void handle_data_(const boost::system::error_code& ec);

    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    tcp::endpoint& endpoint_;
    std::shared_ptr<std::array<char, MAX_PACK_SIZE>> buffer_;
    int result_;
};


#endif //RPC_CLIENT_H