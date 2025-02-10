#pragma once
//모든 프로젝트에서 참조할 헤더이므로 많이 쓰이는 헤더들을 넣는다.
#include "Types.h"
#include "CoreGlobal.h"
#include "CoreTLS.h"
#include "CoreMacro.h"
#include "Memory.h"
#include "Container.h"

#include <memory>

#include <Windows.h>
#include <winsock2.h>
#include <MSWSock.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
using namespace std;
