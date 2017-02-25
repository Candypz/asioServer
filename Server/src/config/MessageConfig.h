/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: MessageConfig.h
Date: 2016-12-1
Description: 
**************************************************/

#ifndef MESSAGECONFIG_H_
#define MESSAGECONFIG_H_

namespace Message {

    struct _MESSAGEHEAD {
        short cmd;
        int   dataSize;
    }MessageHead;


    enum _S_COMMAND {
        S_LOGIN_COMMAND = 0
    }S_COMMAND;

};

#endif // MESSAGECONFIG_H_