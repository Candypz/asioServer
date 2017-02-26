#include "boost/asio.hpp"
#include "addressbook.pb.h"
#include "MessageDataBase.h"
#include "MessageBase.h"
#include "OneMessage.h"
#include "Logger.h"
#include "MessageManage.h"
#include "Singleton.h"
#include "ServerBase.h"
#include <vector>

using MessagePtr = std::shared_ptr<Message::CMessageData>;
using MessageBasePtr = std::shared_ptr<Message::CMessageBase>;
using OneMessagePtr = std::shared_ptr<Message::COneMessage>;

using namespace Server;

void text() {
    helloworld _re;
    _re.set_id(100000);
    _re.set_str("100000000000");
    _re.set_opt(100000);

    std::string _buff;
    _re.SerializePartialToString(&_buff);

    MessagePtr _me(new Message::CMessageData(123, _buff.c_str(), _re.ByteSize()));
    MessageBasePtr it(new Message::COneMessage(_me, "helloworld"));
}

int main(int argc, char* argv[]) {
    try {
        GOOGLE_PROTOBUF_VERIFY_VERSION;

        //Log::CLogger::initLog("serverLog");
        LOG_INFO << "server start";

        CSingleton<Message::CMessageManage>::initInstance();

        boost::asio::io_service _io;
        boost::asio::ip::tcp::endpoint _endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8081);
        CServerBase _server(_io, _endpoint);
        _server.run();

        //free protobuf
        google::protobuf::ShutdownProtobufLibrary();
    }
    catch (std::exception &e) {
        LOG_ERROR << e.what();
    }

    return 0;
}