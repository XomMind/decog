// op_q5_pb: protobuf 3.5.1 RepeatedPtrField<Message>::Add, GenericTypeHandler and
// Arena::Create* chains for the scoresheet repeated message types, matched against COGMIND.exe.
// Every function in these chains has one copy per message type in the exe, so the chain
// below is reproduced with placeholder-named wrappers (OpQ5p_*) that each pair to one address.
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
#include "../web/scoresheet.pb.h"
#undef private
#undef protected

using namespace google::protobuf;

struct OpQ5p_Arena : public Arena	// NOTE: placeholder name
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

	template <class T> T* CreateInternal(bool skip_explicit_ownership)
	{
		return new (AllocateInternal<T>(skip_explicit_ownership)) T();
	}

	template <class T> static T* Create(Arena* arena)
	{
		if (arena == NULL)
		{
			return new T();
		}
		else
		{
			return ((OpQ5p_Arena*)arena)->CreateInternal<T>(internal::has_trivial_destructor<T>::value);
		}
	}

	template <class T> static T* CreateMaybeMessage(Arena* arena, internal::false_type)
	{
		return Create<T>(arena);
	}
};

template <class T> class OpQ5p_TypeHandler	// NOTE: placeholder name
{
public:
	typedef T Type;

	static T* New(Arena* arena)
	{
		return Arena::CreateMaybeMessage<T>(arena);
	}

	static T* NewFromPrototype(const T* prototype, Arena* arena)
	{
		return New(arena);
	}
};

template <class T> class OpQ5p_RepeatedPtrField : public RepeatedPtrField<T>	// NOTE: placeholder name
{
public:
	T* Add()
	{
		return internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<T> >();
	}
};

template string* RepeatedPtrField<string>::Add();
template void RepeatedField<int>::Add(const int&);
template void RepeatedField<int>::Reserve(int);
template class OpQ5p_TypeHandler<Protobuf::ClassDistribution_ClassEntry>;
template Protobuf::ClassDistribution_ClassEntry* OpQ5p_RepeatedPtrField<Protobuf::ClassDistribution_ClassEntry>::Add();
template Protobuf::ClassDistribution_ClassEntry* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::ClassDistribution_ClassEntry> >(Protobuf::ClassDistribution_ClassEntry*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::ClassDistribution_ClassEntry>(bool);
template Protobuf::ClassDistribution_ClassEntry* OpQ5p_Arena::CreateInternal<Protobuf::ClassDistribution_ClassEntry>(bool);
template Protobuf::ClassDistribution_ClassEntry* OpQ5p_Arena::Create<Protobuf::ClassDistribution_ClassEntry>(Arena*);
template Protobuf::ClassDistribution_ClassEntry* OpQ5p_Arena::CreateMaybeMessage<Protobuf::ClassDistribution_ClassEntry>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::CogshopPurchases_Purchase>;
template Protobuf::CogshopPurchases_Purchase* OpQ5p_RepeatedPtrField<Protobuf::CogshopPurchases_Purchase>::Add();
template Protobuf::CogshopPurchases_Purchase* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::CogshopPurchases_Purchase> >(Protobuf::CogshopPurchases_Purchase*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::CogshopPurchases_Purchase>(bool);
template Protobuf::CogshopPurchases_Purchase* OpQ5p_Arena::CreateInternal<Protobuf::CogshopPurchases_Purchase>(bool);
template Protobuf::CogshopPurchases_Purchase* OpQ5p_Arena::Create<Protobuf::CogshopPurchases_Purchase>(Arena*);
template Protobuf::CogshopPurchases_Purchase* OpQ5p_Arena::CreateMaybeMessage<Protobuf::CogshopPurchases_Purchase>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::PolymindHostKillLeaderboard_HostRecord>;
template Protobuf::PolymindHostKillLeaderboard_HostRecord* OpQ5p_RepeatedPtrField<Protobuf::PolymindHostKillLeaderboard_HostRecord>::Add();
template Protobuf::PolymindHostKillLeaderboard_HostRecord* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::PolymindHostKillLeaderboard_HostRecord> >(Protobuf::PolymindHostKillLeaderboard_HostRecord*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::PolymindHostKillLeaderboard_HostRecord>(bool);
template Protobuf::PolymindHostKillLeaderboard_HostRecord* OpQ5p_Arena::CreateInternal<Protobuf::PolymindHostKillLeaderboard_HostRecord>(bool);
template Protobuf::PolymindHostKillLeaderboard_HostRecord* OpQ5p_Arena::Create<Protobuf::PolymindHostKillLeaderboard_HostRecord>(Arena*);
template Protobuf::PolymindHostKillLeaderboard_HostRecord* OpQ5p_Arena::CreateMaybeMessage<Protobuf::PolymindHostKillLeaderboard_HostRecord>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_DiscoveredExit>;
template Protobuf::Route_Entry_DiscoveredExit* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_DiscoveredExit>::Add();
template Protobuf::Route_Entry_DiscoveredExit* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_DiscoveredExit> >(Protobuf::Route_Entry_DiscoveredExit*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_DiscoveredExit>(bool);
template Protobuf::Route_Entry_DiscoveredExit* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_DiscoveredExit>(bool);
template Protobuf::Route_Entry_DiscoveredExit* OpQ5p_Arena::Create<Protobuf::Route_Entry_DiscoveredExit>(Arena*);
template Protobuf::Route_Entry_DiscoveredExit* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_DiscoveredExit>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_HistoryEvent>;
template Protobuf::Route_Entry_HistoryEvent* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_HistoryEvent>::Add();
template Protobuf::Route_Entry_HistoryEvent* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_HistoryEvent> >(Protobuf::Route_Entry_HistoryEvent*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_HistoryEvent>(bool);
template Protobuf::Route_Entry_HistoryEvent* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_HistoryEvent>(bool);
template Protobuf::Route_Entry_HistoryEvent* OpQ5p_Arena::Create<Protobuf::Route_Entry_HistoryEvent>(Arena*);
template Protobuf::Route_Entry_HistoryEvent* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_HistoryEvent>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_ObtainedSchematic>;
template Protobuf::Route_Entry_ObtainedSchematic* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_ObtainedSchematic>::Add();
template Protobuf::Route_Entry_ObtainedSchematic* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_ObtainedSchematic> >(Protobuf::Route_Entry_ObtainedSchematic*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_ObtainedSchematic>(bool);
template Protobuf::Route_Entry_ObtainedSchematic* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_ObtainedSchematic>(bool);
template Protobuf::Route_Entry_ObtainedSchematic* OpQ5p_Arena::Create<Protobuf::Route_Entry_ObtainedSchematic>(Arena*);
template Protobuf::Route_Entry_ObtainedSchematic* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_ObtainedSchematic>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_FabricatedObject>;
template Protobuf::Route_Entry_FabricatedObject* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_FabricatedObject>::Add();
template Protobuf::Route_Entry_FabricatedObject* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_FabricatedObject> >(Protobuf::Route_Entry_FabricatedObject*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_FabricatedObject>(bool);
template Protobuf::Route_Entry_FabricatedObject* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_FabricatedObject>(bool);
template Protobuf::Route_Entry_FabricatedObject* OpQ5p_Arena::Create<Protobuf::Route_Entry_FabricatedObject>(Arena*);
template Protobuf::Route_Entry_FabricatedObject* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_FabricatedObject>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_RepairedObject>;
template Protobuf::Route_Entry_RepairedObject* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_RepairedObject>::Add();
template Protobuf::Route_Entry_RepairedObject* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_RepairedObject> >(Protobuf::Route_Entry_RepairedObject*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_RepairedObject>(bool);
template Protobuf::Route_Entry_RepairedObject* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_RepairedObject>(bool);
template Protobuf::Route_Entry_RepairedObject* OpQ5p_Arena::Create<Protobuf::Route_Entry_RepairedObject>(Arena*);
template Protobuf::Route_Entry_RepairedObject* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_RepairedObject>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry_ObtainedStudy>;
template Protobuf::Route_Entry_ObtainedStudy* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry_ObtainedStudy>::Add();
template Protobuf::Route_Entry_ObtainedStudy* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry_ObtainedStudy> >(Protobuf::Route_Entry_ObtainedStudy*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry_ObtainedStudy>(bool);
template Protobuf::Route_Entry_ObtainedStudy* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry_ObtainedStudy>(bool);
template Protobuf::Route_Entry_ObtainedStudy* OpQ5p_Arena::Create<Protobuf::Route_Entry_ObtainedStudy>(Arena*);
template Protobuf::Route_Entry_ObtainedStudy* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry_ObtainedStudy>(Arena*,internal::false_type);
template class OpQ5p_TypeHandler<Protobuf::Route_Entry>;
template Protobuf::Route_Entry* OpQ5p_RepeatedPtrField<Protobuf::Route_Entry>::Add();
template Protobuf::Route_Entry* internal::RepeatedPtrFieldBase::Add<OpQ5p_TypeHandler<Protobuf::Route_Entry> >(Protobuf::Route_Entry*);
template void* OpQ5p_Arena::AllocateInternal<Protobuf::Route_Entry>(bool);
template Protobuf::Route_Entry* OpQ5p_Arena::CreateInternal<Protobuf::Route_Entry>(bool);
template Protobuf::Route_Entry* OpQ5p_Arena::Create<Protobuf::Route_Entry>(Arena*);
template Protobuf::Route_Entry* OpQ5p_Arena::CreateMaybeMessage<Protobuf::Route_Entry>(Arena*,internal::false_type);
