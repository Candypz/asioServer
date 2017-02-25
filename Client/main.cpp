#include "src/SocketClientTool.h"

int main(int argc, char* argv[]) {

    CSocketClientTool::connectServer("127.0.0.1", 8081);
    CSocketClientTool::sendMessage("10000", sizeof("10000"));

    while (1) {
        Sleep(100);
    }

    return 0;
}