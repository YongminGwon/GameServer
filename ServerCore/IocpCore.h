#pragma once

class IocpObject
{
public:
	virtual HANDLE GetHandle() = 0;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numofBytes = 0) = 0;
private:
};

class IocpCore
{
public:
	IocpCore();
	~IocpCore();

	HANDLE GetHandle() { return _iocpHandle; }

	bool Register(class IocpObject* iocpObject);
	bool Dispatch(uint32 timeoutMs = INFINITE);
private:
	HANDLE _iocpHandle;
};

// Temp
extern IocpCore GiocpCore;