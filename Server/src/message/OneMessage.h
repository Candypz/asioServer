/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: OneMessage.h
Date: 2016-11-16
Description: 
**************************************************/

#ifndef ONEMESSAGE_H_
#define ONEMESSAGE_H_

#include "MessageBase.h"

namespace Message {

    class COneMessage :public CMessageBase {
    public:
        COneMessage(std::shared_ptr<CMessageData> data, const char *messageName);
        virtual ~COneMessage();
        virtual void doSomething();
    };

}

#endif // ONEMESSAGE_H_