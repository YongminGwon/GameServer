#include "pch.h"

int main()
{
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	//다음 방법이 추후에 deprecated기 때문에 아래 방법으로 진행
	//serverAddr.sin_addr.s_addr = ::inet_addr("127.0.0.1");
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	//엔디안 이슈를 막기위해 htonl 사용
	serverAddr.sin_port = htons(8000);

	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)))
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Connect ErrorCode : " << errCode << endl;
		return 0;
	}

	cout << "Connected To Server" << endl;

	while (true)
	{
		this_thread::sleep_for(1s);
	}

	::closesocket(clientSocket);
	::WSACleanup();
}