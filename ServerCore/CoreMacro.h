#pragma once

/*---------------
	  Crash
---------------*/

#define CRASH(cause)						\
{											\
	uint32* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr)			\
{									\
	if (!(expr))					\
	{								\
		CRASH("ASSERT_CRASH");		\
		__analysis_assume(expr);	\
	}								\
}

/*------------------
        Memory
--------------------*/

#ifdef _DEBUG
#define my_alloc(size) StompAllocator::Alloc(size)
#define my_release(ptr) StompAllocator::Release(ptr)
#else
#define my_alloc(size) BaseAllocator::Alloc(size)
#define my_release(ptr) BaseAllocator::Release(ptr)
#endif