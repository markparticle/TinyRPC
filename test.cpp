/*
 * @Author       : mark
 * @Date         : 2020-07-02
 * @copyleft Apache 2.0
 */ 

#include <msgpack.hpp>
#include <string>
#include <iostream>
#include <sstream>

int main() {
    msgpack::type::tuple<bool, char, std::string> src(true, 'i', "mark");
    std::stringstream buffer;
    msgpack::pack(buffer, src);
    std::string str(buffer.str());

    msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());
    msgpack::object deserialized = oh.get();
    std::cout << deserialized << std::endl;

    msgpack::type::tuple<bool, char, std::string>dst;
    deserialized.convert(dst);

    msgpack::type::tuple<bool, char, std::string> dst2 = deserialized.as<msgpack::type::tuple<bool, char, std::string> >();
    return 0;
}