#include "pch.h"
#include "ThreadManager.h"

int main()
{
	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Socket ErrorCode : " << errCode << endl;
		return 0;
	}

	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(8000);

	::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	::listen(listenSocket, 10);

	while (true)
	{
		SOCKADDR_IN clientAddr;
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int32 addrLen = sizeof(clientAddr);

		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);

		char ipAddress[16];
		::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
		cout << "Client Connected! IP : " << ipAddress << endl;
	}
	::WSACleanup();
}