#include "MessageManage.h"
#include "MessageConfig.h"
#include "MessageBase.h"
#include "OneMessage.h"

using namespace Message;

using MessageBasePtr = std::shared_ptr<Message::CMessageBase>;

void CMessageManage::providedByEvent(const short &command, const std::shared_ptr<Message::CMessageData> &data) {
    switch (command) {
        case S_LOGIN_COMMAND:
            MessageBasePtr it(new Message::COneMessage(data, "helloworld"));
            break;
    }
}