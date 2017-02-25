/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: Session.h
Date: 2016-12-6
Description: 
**************************************************/

#ifndef SESSION_H_
#define SESSION_H_

#include "ServerNameSpace.h"

namespace Server {
    class CSession :public std::enable_shared_from_this<CSession> {
    public:
        CSession(ioService &io);
        ~CSession();

        void start();
        tcpSocket &getSocket();
        void stop();

        void send(const std::string &data);
    private:
        void receiveHandler(const boostError &error, size_t bytes);
        void sendHandler(const boostError &error, const std::string data);
        void parseFrame(const boostError &error, size_t bytes);

        tcpSocket m_socket;
        unsigned char m_readBuffer[1024];
        unsigned char m_writeBuffer[1024];
    };
}

#endif // SESSION_H_