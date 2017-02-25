/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: SocketClientTool.h
Date: 2016-9-1
Description: socketClient¡¥Ω”
**************************************************/

#ifndef SOCKETCLIENTTOOL_H_
#define SOCKETCLIENTTOOL_H_

#include "SocketClient.h"

class CSocketClientTool {
public:
    static bool connectServer(const char *serverIp, unsigned short port);
    static void closeConnect();
    static void sendMessage(const char *data, int count);
private:
    CSocketClientTool();
    ~CSocketClientTool();
    static void socketClientMessageCallBack(const char *data, int count);
    static void socketClientOnDisconnectCallBack();

    static CSocketClient *m_socketClient;
};

#endif