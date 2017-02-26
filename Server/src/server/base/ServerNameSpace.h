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
    using boostTime = boost::posix_time::ptime;
    using boostTimeDuration = boost::posix_time::millisec_posix_time_system_config::time_duration_type;
    using boostSecondClock = boost::posix_time::second_clock;
};

#endif // SERVERNAMESPACE_H_

