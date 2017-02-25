#include "Tools.h"
#include "ConfigDefin.h"
#include <string>

int CTools::byteToInt(char *bytes, int size /* = 4 */) {
    char _data[INT_SIZE] = { 0 };
    memcpy(_data, bytes, size);
    int addr = _data[0] & 0xFF;
    addr |= ((_data[1] << 8) & 0xFF00);
    addr |= ((_data[2] << 16) & 0xFF0000);
    addr |= ((_data[3] << 24) & 0xFF000000);
    return addr;
}

short CTools::byteToShort(char *bytes, int size /* = 2 */) {
    char _data[SHORT_SIZE] = { 0 };
    memcpy(_data, bytes, size);
    return (_data[1] << 8) | (_data[0] & 0xFF);
}