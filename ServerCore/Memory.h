#pragma once
#include "Allocator.h"

template<typename Type, typename... Args>
Type* xnew(Args&&... args)
{
	Type* memory = static_cast<Type*>(my_alloc(sizeof(Type)));

	//placement new (할당된 메모리 위에 생성자를 호출)
	new(memory)Type(std::forward<Args>(args)...);
	return memory;
}

template<typename Type>
void xdelete(Type* obj)
{
	//소멸자 호출
	obj->~Type();
	my_release(obj);
}