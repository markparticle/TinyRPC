/*
 * @Author       : mark
 * @Date         : 2020-07-02
 * @copyleft Apache 2.0
 */ 
#ifndef RPC_SERVER_H
#define RPC_SERVER_H

#include "connection.h"

typedef boost::shared_ptr<Connection> conn_ptr;
class RpcServer 
{
public:
    server(boost::asio::io_service& io_service, tcp::endpoint& endpoint)
        : io_service_(io_service), acceptor_(io_service, endpoint);

    void handle_accept(conn_ptr conn, const boost::system::error_code& ec);
    void run() {
        io_service_.run();
    }
private:
    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
};

#endif //RPC_SERVER_H