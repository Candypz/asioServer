#include "MessageDataBase.h"
#include "Tools.h"

using namespace Message;

CMessageData::CMessageData(short command, const char *data, int dataSize) {
    createMessageData(command, data, dataSize);
}

CMessageData::CMessageData(const char *data) {
    initMessageData(data);
}

CMessageData::~CMessageData() {

}

void CMessageData::createMessageData(short command, const char *data, int dataSize) {
    m_messageDataStr._command = command;
    m_messageDataStr._length = dataSize;
    memcpy(m_messageDataStr._data, data, m_messageDataStr._length);

    memcpy(m_byteData, &command, SHORT_SIZE);
    memcpy(m_byteData + SHORT_SIZE, &m_messageDataStr._length, INT_SIZE);
    memcpy(m_byteData + SHORT_SIZE + INT_SIZE, &m_messageDataStr._data, m_messageDataStr._length);
}

void CMessageData::initMessageData(const char *data) {
    char _data[MESSAGE_DATA_MAX_LENGTH] = { 0 };
    memcpy(_data, data, MESSAGE_DATA_MAX_LENGTH);
    char _commbuf[SHORT_SIZE];
    memcpy(_commbuf, &_data, SHORT_SIZE);
    m_messageDataStr._command = CTools::byteToShort(_commbuf);
    char _length[INT_SIZE];
    memcpy(_length, &_data[SHORT_SIZE], INT_SIZE);
    m_messageDataStr._length = CTools::byteToInt(_length);
    memcpy(m_messageDataStr._data, &_data[SHORT_SIZE + INT_SIZE], m_messageDataStr._length);
}

const MessageStruct &CMessageData::getMessageDataStr()const {
    return m_messageDataStr;
}

const short &CMessageData::getCommand()const {
    return m_messageDataStr._command;
}

const int &CMessageData::getLength()const {
    return m_messageDataStr._length;
}

const char *CMessageData::getMessageData()const {
    return m_messageDataStr._data;
}

const char *CMessageData::getData()const {
    return m_byteData;
}