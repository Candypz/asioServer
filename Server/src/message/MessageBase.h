/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: MessageBase.h
Date: 2016-11-16
Description: 消息处理转发基类
**************************************************/

#ifndef MESSAGEBASE_H_
#define MESSAGEBASE_H_

#include <memory>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>


namespace Message {
    class CMessageData;

    class CMessageBase {
    public:
        CMessageBase(std::shared_ptr<CMessageData> data, const char *messageName);
        virtual ~CMessageBase();
        const short &getCommand()const;
        void initMessage(const char *messageName);
        virtual void doSomething() = 0;
        google::protobuf::Message *createMessage(const std::string &type_name);
    protected:
        std::shared_ptr<CMessageData> m_messageData;
        google::protobuf::Message *m_message = nullptr;
    };
}

#endif // MESSAGEBASE_H_