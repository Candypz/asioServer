#include "SocketBase.h"

CSocketBase::CSocketBase() {
    m_initSuccess = false;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
    WORD wVersionRequested;
    wVersionRequested = MAKEWORD(2, 0);
    WSADATA wsaData;
    int nRet = WSAStartup(wVersionRequested, &wsaData);
    if (nRet != 0) {
        fprintf(stderr, "Initilize Error!\n");
        return;
    }
    m_initSuccess = true;
#endif  
}

CSocketBase::~CSocketBase() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
    if (m_initSuccess) {
        WSACleanup();
    }
#endif  
}

void CSocketBase::closeConnect(CSocket socket) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
    close(socket);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
    closesocket(socket);
#endif  
}

bool CSocketBase::error(CSocket socket) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
    return socket == SOCKET_ERROR;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
    return socket < 0;
#endif  
}