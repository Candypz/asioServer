#include "Session.h"
#include "addressbook.pb.h"
#include "Logger.h"
#include "ConfigDefin.h"
#include <boost/bind.hpp>
#include <boost/progress.hpp>
#include <boost/date_time.hpp>


using namespace Server;

CSession::CSession(ioService &io):m_socket(io) {

}

CSession::~CSession() {

}

void CSession::start() {
    static ipTcp::no_delay _option(true);
    m_socket.set_option(_option);

    m_connectTime = boostSecondClock::local_time();

    m_socket.async_receive(boost::asio::buffer(m_readBuffer),
        boost::bind(&CSession::receiveHandler,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void CSession::close() {
    m_socket.close();
}

tcpSocket &CSession::getSocket() {
    return m_socket;
}


void CSession::receiveHandler(const boostError &error, size_t bytes) {
    if (error) return;

    boost::asio::async_read(m_socket, boost::asio::buffer(m_readBuffer), boost::bind(&CSession::parseFrame,
        shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));

    m_socket.async_receive(boost::asio::buffer(m_readBuffer),
        boost::bind(&CSession::receiveHandler,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));

    helloworld _re;
    _re.set_id(100000);
    _re.set_str("100000000000");
    _re.set_opt(100000);

    std::string _buff;
    _re.SerializePartialToString(&_buff);

    send(_buff);
}

void CSession::parseFrame(const boostError &error, size_t bytes) {
    if (error) return;

    m_socket.async_receive(boost::asio::buffer(m_readBuffer),
        boost::bind(&CSession::receiveHandler,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    
}

void CSession::send(const std::string &data) {
    std::copy(data.begin(), data.end(), m_writeBuffer);
    m_socket.async_write_some(boost::asio::buffer(m_writeBuffer, data.size()), boost::bind(&CSession::sendHandler,
        shared_from_this(),
        boost::asio::placeholders::error,
        data));
}

void CSession::sendHandler(const boostError &error,const std::string data) {
    if (!error) {
        auto _connectDiff = boostSecondClock::local_time() - m_connectTime;
        LOG_INFO << _connectDiff.total_seconds();
    }
    else {
        //send(data);
        LOG_ERROR << "send error:" << error;
    }
}

void CSession::listenShutdown() {
    auto _connectDiff = boostSecondClock::local_time() - m_connectTime;
    if (_connectDiff.total_seconds() > CLIENT_TIMEOUT) {
        //do close;
    }
}