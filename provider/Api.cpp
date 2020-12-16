#include "Api.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define WIN32_LEAN_AND_MEAN

Api::Api():
    mConnectSocket{ INVALID_SOCKET },
    mPort{ "80" },
    mHost{ "wider.ntigskovde.se" }
{
    //connecting to the server via the constructor
    mIResult = WSAStartup(MAKEWORD(2, 2), &mWsaData);
    if (mIResult != 0)
        std::cout << "wsa startup failed with error " << mIResult << '\n';
    //we fill the memmory block that hints uses with 0's. this is to make sure we don't get any errors later.
    ZeroMemory(&mHints, sizeof(mHints));
    mHints.ai_family = AF_INET;
    mHints.ai_socktype = SOCK_STREAM;
    mHints.ai_protocol = IPPROTO_TCP;
    mIResult = getaddrinfo(mHost, mPort, &mHints, &mResult);
    if (mIResult != 0)
    {
        std::cout << "getadrinfo failed with error: " << mIResult << '\n';
        WSACleanup();
    }
    //atempting to connect to an address until we succeed
    for (mPtr = mResult; mPtr != nullptr; mPtr = mPtr->ai_next)
    {
        mConnectSocket = socket(mPtr->ai_family, mPtr->ai_socktype, mPtr->ai_protocol);
        if (mConnectSocket == INVALID_SOCKET)
        {
            std::cout << "socket failed with error " << WSAGetLastError() << '\n';
            WSACleanup();
        }
        mIResult = connect(mConnectSocket, mPtr->ai_addr, (int)mPtr->ai_addrlen);
        if (mIResult == SOCKET_ERROR)
        {
            closesocket(mConnectSocket);
            mConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;

    }
    freeaddrinfo(mResult);
    if (mConnectSocket == INVALID_SOCKET)
    {
        std::cout << "unable to connect to server\n";
        WSACleanup();
    }
}
Api::~Api()
{
    //the destructor will shut down the connection when the object goes out of scope. this is to make sure that as long as the program is running that it will have a connection to the server.
    mIResult = shutdown(mConnectSocket, SD_SEND);
    if (mIResult == SOCKET_ERROR)
    {
        std::cout << "shut down failed with error " << mIResult << '\n';
        closesocket(mConnectSocket);
        WSACleanup();
    }
}
//this function expects a path, data and a key. since key is a default argument if nothing is provided the string will be empty
std::string Api::sendData(std::string path, std::string data, std::string key)
{

    std::string header{ "POST " + path + "?" + key + " HTTP/1.1\r\nHost: wider.ntigskovde.se\r\n\rConnection: close\r\nContent-Length: " + std::to_string(data.size()) + "\r\nContent-Type: application/json\r\n\r\n" + data };
    const char* sendBuff{ header.c_str() };
    const int buffLength{ 50 };
    char recBuff[buffLength];
    mIResult = send(mConnectSocket, sendBuff, static_cast<int>(strlen(sendBuff)), 0);
    if (mIResult == SOCKET_ERROR)
    {
        std::cout << "send failed with error " << WSAGetLastError() << '\n';
        closesocket(mConnectSocket);
        WSACleanup();

    }
    do
    {
        mIResult = recv(mConnectSocket, recBuff, buffLength, 0);
        recBuff[buffLength - 1] = '\0';

    } while (mIResult > 0);
    std::string response = recBuff;
    parseString(response);
    return response;
}
void Api::parseString(std::string& data)
{
    //this function removes abit of server response that we don't need. it expects the data so you can performe the change on
    std::string serverStr{ "Server: LiteSpeed" };

    std::string::size_type i = data.find(serverStr);

    if (i != std::string::npos)
        data.erase(i, serverStr.length());
}