/*************************************************************************
	> File Name: first_asio.cpp
	> Author: 刘傲天
	> Mail: 1151172004@qq.com
	> Created Time: Fri 07 Sep 2018 11:02:42 AM CST
 ************************************************************************/

#include<iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::tcp;

/*接受程序运行时传递的参数*/
int main(int argc, char * argv[])
{
    try{
        if (argc != 2){
            /*argc是main入口的参数个数*/
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }

        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(argv[1], "daytime");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);

        while (true){
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            if (error == boost::asio::error::eof){
                break;
            }
            else if(error){
                throw boost::system::system_error(error);
            }
            std::cout.write(buf.data(), len);
        }
    }

    catch (std::exception& e){
        std::cerr << "Error" << argc << std::endl;
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
