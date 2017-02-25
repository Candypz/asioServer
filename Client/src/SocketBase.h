/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: SocketBase.h
Date: 2016-8-31
Description: 
**************************************************/

#ifndef SOCKETBASE_H_
#define SOCKETBASE_H_

#include <thread>
#include <mutex>

#define CC_PLATFORM_WIN32  1
#define CC_PLATFORM_ANDROID  2
#define CC_TARGET_PLATFORM  1

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
#include <WinSock2.h>  
#pragma comment(lib, "WS2_32.lib")  
#define CSocket SOCKET 
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
#include <arpa/inet.h>     
#include <netdb.h>   
#include <netinet/in.h>   
#include <sys/types.h>   
#include <sys/socket.h>     
#include <unistd.h>  
#include <stdio.h>         
#include <stdlib.h>   
#include <string.h>   
#define CSocket int  
#endif   

class CSocketBase {
public:
    CSocketBase();
    virtual ~CSocketBase();
protected:
    void closeConnect(CSocket socket);
    bool error(CSocket socket);
    std::mutex m_mutex;
private:
    bool m_initSuccess;
};

#endif