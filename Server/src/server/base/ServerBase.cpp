#include "ServerBase.h"
#include "Session.h"
#include "Logger.h"
#include <boost/bind.hpp>

using namespace Server;


CServerBase::CServerBase(ioService &io, tcpEndPoint port):
    m_ioServer(io),
    m_acceptor(io, port){

    sessionPtr _session(new CSession(m_ioServer));
    m_acceptor.async_accept(_session->getSocket(),
        boost::bind(&CServerBase::handleAccept,
            this,
            _session,
            boost::asio::placeholders::error));
}

CServerBase::~CServerBase() {

}

void CServerBase::handleAccept(sessionPtr session, const boostError &error) {
    if (error) {
        LOG_ERROR << error;
        return;
    }

    session->start();

    sessionPtr nextSession(new CSession(m_ioServer));
    m_sessionList.push_back(session);

    m_acceptor.async_accept(nextSession->getSocket(), boost::bind(&CServerBase::handleAccept,
        this,
        nextSession,
        boost::asio::placeholders::error));

}

void CServerBase::run() {
    m_ioServer.run();
}