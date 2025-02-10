#pragma once
#include "Allocator.h"

template<typename Type, typename... Args>
Type* xnew(Args&&... args)
{
	Type* memory = static_cast<Type*>(my_alloc(sizeof(Type)));

	//placement new (�Ҵ�� �޸� ���� �����ڸ� ȣ��)
	new(memory)Type(std::forward<Args>(args)...);
	return memory;
}

template<typename Type>
void xdelete(Type* obj)
{
	//�Ҹ��� ȣ��
	obj->~Type();
	my_release(obj);
}