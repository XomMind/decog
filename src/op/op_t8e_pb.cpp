// op_t8e_pb: protobuf 3.5.1 Arena template instances, 0x9f6000-0x9fd000
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
using namespace std;

struct OpT8e_Arena : public Arena	// NOTE: placeholder name
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
			return impl_.AllocateAlignedAndAddCleanup(n,(void (*)(void*))&_Destroy<T>);
		}
	}
};

template void* OpT8e_Arena::AllocateInternal<string>(bool);
