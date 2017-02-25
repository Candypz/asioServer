/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: ServerBase.h
Date: 2016-12-6
Description: 
**************************************************/

#ifndef SERVERBASE_H_
#define SERVERBASE_H_

#include "ServerNameSpace.h"
#include <unordered_map>

namespace Server {
    class CSession;
    using sessionPtr = std::shared_ptr<CSession>;
    class CServerBase:public std::enable_shared_from_this<CServerBase> {
    public:
        CServerBase(ioService &io, tcpEndPoint port);
        virtual ~CServerBase();
        void handleAccept(sessionPtr ptr, const boostError &error);
        void run();
    private:
        ioService &m_ioServer;
        tcpAcceptor m_acceptor;
        std::list<sessionPtr> m_sessionList;
    };

};

#endif // SERVERBASE_H_