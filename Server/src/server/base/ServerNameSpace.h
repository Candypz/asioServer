/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: 
Date: 2016-11-
Description: 
**************************************************/
#ifndef SERVERNAMESPACE_H_
#define SERVERNAMESPACE_H_

#include <boost/asio.hpp>
#include <memory>

namespace Server {
    using ipTcp = boost::asio::ip::tcp;
    using ioService = boost::asio::io_service;
    using tcpAcceptor = ipTcp::acceptor;
    using tcpEndPoint = ipTcp::endpoint;
    using tcpSocket = ipTcp::socket;
    using asioSterambuf = boost::asio::streambuf;
    using boostError = boost::system::error_code;
};

#endif // SERVERNAMESPACE_H_

