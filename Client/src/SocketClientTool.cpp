#include "SocketClientTool.h"

CSocketClient *CSocketClientTool::m_socketClient = NULL;

CSocketClientTool::CSocketClientTool() {

}

CSocketClientTool::~CSocketClientTool() {

}

bool CSocketClientTool::connectServer(const char *serverIp, unsigned short port) {
    if (m_socketClient == NULL) {
        m_socketClient = new CSocketClient();
    }

    if (m_socketClient->connectServer(serverIp, port)) {
        m_socketClient->onRecv = CSocketClientTool::socketClientMessageCallBack;
        m_socketClient->onDisconnect = CSocketClientTool::socketClientOnDisconnectCallBack;
        return true;
    }

    delete m_socketClient;
    m_socketClient = nullptr;

    return false;
}

void CSocketClientTool::sendMessage(const char *data, int count) {
    if (m_socketClient) {
        m_socketClient->sendMessage(data, count);
    }
}

void CSocketClientTool::closeConnect() {
    m_socketClient->closeSocket();
}

void CSocketClientTool::socketClientMessageCallBack(const char *data, int count) {
    printf("%s\n", data);
}

void CSocketClientTool::socketClientOnDisconnectCallBack() {

}