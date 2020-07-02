/*
 * @Author       : mark
 * @Date         : 2020-07-02
 * @copyleft Apache 2.0
 */ 
#ifndef COMMON_H
#define COMMON_H


#include<boost/asio/io_service.hpp>
#include<boost/asio/ip/tcp.hpp>
#include<boost/bind.hpp>
#include<boost/shared_ptr.hpp>
#include<boost/enable_shared_from_this.hpp>
#include<boost/asio/streambuf.hpp>
#include<boost/asio/placeholders.hpp>
#include<boost/asio.hpp>

#include <msgpack.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip::address;


/* 双方需要约定的常量 */
const int NOT_APPLICATED -3000
const int MAX_PACK_SIZE 1024

const int ADD = 1;
const int MINUS = 2;
const int MULTI = 3;
const int DIV = 4;



#endif //COMMON_H