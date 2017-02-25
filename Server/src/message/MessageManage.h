/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: MessageManage.h
Date: 2016-11-23
Description: 
**************************************************/

#ifndef MESSAGEMANAGE_H_
#define MESSAGEMANAGE_H_

#include <memory>

namespace Message {
    class CMessageData;

    class CMessageManage {
    public:
        CMessageManage() {}
        virtual ~CMessageManage() {}

        void providedByEvent(const short &commd, const std::shared_ptr<Message::CMessageData> &data);
    };


}

#endif // MESSAGEMANAGE_H_