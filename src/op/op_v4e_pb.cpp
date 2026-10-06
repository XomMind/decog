// op_v4e_pb: protobuf 3.5.1 Arena::AllocateInternal instance over an 8-byte placeholder record type
// (the exe's InternalMetadataWithArena Container), matched against COGMIND.exe.
// NOTE: placeholder names
#define NDEBUG
#include <string>
#include <typeinfo>
#include <new>
#include <limits>
#include <vector>
#include <algorithm>
#include <iosfwd>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <iostream>
#include <memory>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define private public
#define protected public
#include <google/protobuf/arena.h>
#undef private
#undef protected

using namespace google::protobuf;

struct OpV4e_Meta	// NOTE: placeholder name; 8-byte arena-allocated record
{
	int a;
	int b;
	~OpV4e_Meta();
};

struct OpV4e_Arena : public Arena	// NOTE: placeholder name
{
	template <class T> void* AllocateInternal(bool skip_explicit_ownership)
	{
		const size_t n = internal::AlignUpTo8(sizeof(T));
		AllocHook(&typeid(T),n);
		if (skip_explicit_ownership)
		{
			return impl_.AllocateAligned(n);
		}
		else
		{
			return impl_.AllocateAlignedAndAddCleanup(n,&internal::arena_destruct_object<T>);
		}
	}
};

template void* OpV4e_Arena::AllocateInternal<OpV4e_Meta>(bool);	// 0x9f9f10
template void internal::arena_destruct_object<OpV4e_Meta>(void*);	// 0x9ff1d0 (aliases op_h's _Destroy<OpH_CDA10_1>)
