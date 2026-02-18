#include "..\pch.h"
#include "umvc3utils.h"
#include "sigscan.h"

int64 GetUMVC3EntryPoint()
{
	static __int64 addr = reinterpret_cast<__int64>(GetModuleHandle(nullptr));
	return addr;
}

//unsigned long long start = 0;
//unsigned long long _adjust(unsigned long long addr) {
//	if (start == 0) {
//		start = sigscan::get().start;
//	}
//	return start + addr;

//}

int64 _addr(__int64 addr)
{
	return GetUMVC3EntryPoint() - 0x140000000 + addr;
}

unsigned long long baseaddr(unsigned long long addr)
{
	return (unsigned long long)GetUMVC3EntryPoint() + addr;
}
