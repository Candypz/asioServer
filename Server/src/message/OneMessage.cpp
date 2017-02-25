#include "OneMessage.h"
#include "addressbook.pb.h"

using namespace Message;

COneMessage::COneMessage(std::shared_ptr<CMessageData> data, const char *messageName) :CMessageBase(data, messageName) {
    assert(typeid(*m_message) == typeid(helloworld::default_instance()));
    doSomething();
}

COneMessage::~COneMessage() {

}

void COneMessage::doSomething() {

}