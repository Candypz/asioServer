#ifndef MESSAGE_H_
#define MESSAGE_H_

//command + length + data
//2+4+n

#include "ConfigDefin.h"
#include <string>

namespace Message {
    struct MessageStruct {
        short _command = 0;
        int   _length = 0;
        char  _data[MESSAGE_DATA_MAX_LENGTH] = { 0 };
    };

    class CMessageData {
    public:
        CMessageData(short command, const char *data, int dataSize);
        CMessageData(const char *data);
        ~CMessageData();

        //序列化
        void  createMessageData(short command, const char *data, int dataSize);
        //反序列化
        void  initMessageData(const char *data);
        const MessageStruct &getMessageDataStr()const;

        const short &getCommand()const;
        const int   &getLength()const;
        const char  *getMessageData()const;
        const char  *getData()const;
    private:
        MessageStruct m_messageDataStr;
        char m_byteData[MESSAGE_DATA_MAX_LENGTH] = { 0 };
    };
};

#endif // MESSAGE_H_