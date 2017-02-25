#include "Session.h"
#include <boost/bind.hpp>


using namespace Server;

CSession::CSession(ioService &io):m_socket(io) {

}

CSession::~CSession() {

}

void CSession::start() {
    static ipTcp::no_delay _option(true);
    m_socket.set_option(_option);

    m_socket.async_receive(boost::asio::buffer(m_readBuffer),
        boost::bind(&CSession::receiveHandler,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void CSession::stop() {
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

    send("111");
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

    }
    else {
        send(data);
    }
}