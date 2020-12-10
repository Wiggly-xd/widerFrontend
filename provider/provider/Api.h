#pragma once
#include <WinSock2.h>
#include <string>
class Api
{
private:
    WSADATA mWsaData;
    SOCKET mConnectSocket;
    struct addrinfo* mResult = NULL,
        * mPtr = NULL,
        mHints;
    int mIResult;
    LPCSTR mHost;
    LPCSTR mPort;
    void parseString(std::string &data);
public:
    Api();
    std::string sendData(std::string path, std::string data, std::string key="");
    ~Api();
};

