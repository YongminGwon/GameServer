#pragma once

#include "IocpCore.h"
#include "IocpEvent.h"
#include "NetworkAddress.h"

class Session : public IocpObject
{
public:
	Session();
	virtual ~Session();

	void SetNetAddress(NetworkAddress address) { _netAddress = address; }
	NetworkAddress GetAddress() { return _netAddress; }
	SOCKET GetSocket() { return _socket; }

	HANDLE GetHandle() override;
	void Dispatch(class IocpEvent* iocpEvent, int32 numofBytes = 0) override;

	// TEMP
	char _recvBuffer[1000];
private:
	SOCKET _socket = INVALID_SOCKET;
	NetworkAddress _netAddress = {};
	Atomic<bool> _connected = false;
};

