#include "MessageBase.h"
#include "MessageDataBase.h"

using namespace Message;

CMessageBase::CMessageBase(std::shared_ptr<CMessageData> data, const char *messageName) {
    if (data) {
        m_messageData = std::move(data);
        initMessage(messageName);
    }
}

CMessageBase::~CMessageBase() {
    if (m_message) {
        delete m_message;
        m_message = nullptr;
    }
}

const short & CMessageBase::getCommand() const {
    return m_messageData->getCommand();
}

void CMessageBase::initMessage(const char *messageName) {
    m_message = createMessage(messageName);
    m_message->ParseFromString(m_messageData->getMessageData());
    assert(m_message != nullptr);
}

google::protobuf::Message * CMessageBase::createMessage(const std::string &type_name) {
    google::protobuf::Message* message = nullptr;
    auto descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
    if (descriptor)
    {
        auto prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if (prototype)
        {
            message = prototype->New();
        }
    }
    return message;
}