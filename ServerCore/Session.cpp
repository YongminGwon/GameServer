#include "pch.h"
#include "Session.h"

Session::Session()
{
}

Session::~Session()
{
}

HANDLE Session::GetHandle()
{
	return HANDLE();
}

void Session::Dispatch(IocpEvent* iocpEvent, int32 numofBytes)
{
}
