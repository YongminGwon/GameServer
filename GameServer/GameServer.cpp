#include "pch.h"
#include "ThreadManager.h"

#include "SocketUtils.h"

int main()
{
	SOCKET socket = SocketUtils::CreateSocket();

	SocketUtils::BindAnyAddress(socket, 9999);

	SocketUtils::Listen(socket);

	SOCKET clientSocket = ::accept(socket, nullptr, nullptr);

	cout << "Client Connected" << endl;

	while (true)
	{
		char command;
		if (cin >> command && command == 'q') break;
	}
}