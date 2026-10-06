// std::_Construct / std::_Destroy instantiations over vectors, and
// google::protobuf::Arena::CreateMaybeMessage<T>() for the scoresheet messages,
// matched against COGMIND.exe (Beta 17.1). All are header-inline/template code.

#include <vector>
#include <memory>
#include "web/scoresheet.pb.h"

using namespace std;

class HExplosive	// NOTE: placeholder name
{
public:
	int ID;	// NOTE: placeholder layout
};

struct Elem_9c2320	// NOTE: placeholder name
{
	Elem_9c2320(const Elem_9c2320& from);
	char pad[64];
};

struct Elem_9c5cd0	// NOTE: placeholder name
{
	Elem_9c5cd0(const Elem_9c5cd0& from);
	char pad[16];
};

struct Elem_9c61e0	// NOTE: placeholder name
{
	Elem_9c61e0(const Elem_9c61e0& from);
	char pad[16];
};

struct Elem_9ffe80	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9ffeb0	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9ffee0	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9fff10	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9e7600	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9fff40	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9fff70	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9e7390	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9fffa0	// NOTE: placeholder name
{
	int pad;
};

struct Elem_9fffd0	// NOTE: placeholder name
{
	int pad;
};

struct Elem_a00030	// NOTE: placeholder name
{
	int pad;
};

struct Elem_a00060	// NOTE: placeholder name
{
	int pad;
};

struct Elem_a00090	// NOTE: placeholder name
{
	int pad;
};

void cc_r2_32_instantiate()
{
	Elem_9c2320 *c9c2320 = NULL;
	const Elem_9c2320 *v9c2320 = NULL;
	std::_Construct(c9c2320, *v9c2320);
	Elem_9c5cd0 *c9c5cd0 = NULL;
	const Elem_9c5cd0 *v9c5cd0 = NULL;
	std::_Construct(c9c5cd0, *v9c5cd0);
	Elem_9c61e0 *c9c61e0 = NULL;
	const Elem_9c61e0 *v9c61e0 = NULL;
	std::_Construct(c9c61e0, *v9c61e0);
	{ vector<Elem_9ffe80> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9ffeb0> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9ffee0> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9fff10> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9e7600> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9fff40> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9fff70> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9e7390> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9fffa0> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_9fffd0> *p = NULL; std::_Destroy(p); }
	{ vector<HExplosive> *p = NULL; std::_Destroy(p); }
	{ vector<int> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_a00030> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_a00060> *p = NULL; std::_Destroy(p); }
	{ vector<Elem_a00090> *p = NULL; std::_Destroy(p); }
}

namespace google
{
namespace protobuf
{
template Protobuf::ClassDistribution_ClassEntry* Arena::CreateMaybeMessage<Protobuf::ClassDistribution_ClassEntry>(Arena*);
template Protobuf::CogshopPurchases_Purchase* Arena::CreateMaybeMessage<Protobuf::CogshopPurchases_Purchase>(Arena*);
template Protobuf::PolymindHostKillLeaderboard_HostRecord* Arena::CreateMaybeMessage<Protobuf::PolymindHostKillLeaderboard_HostRecord>(Arena*);
template Protobuf::Route_Entry_DiscoveredExit* Arena::CreateMaybeMessage<Protobuf::Route_Entry_DiscoveredExit>(Arena*);
template Protobuf::Route_Entry_HistoryEvent* Arena::CreateMaybeMessage<Protobuf::Route_Entry_HistoryEvent>(Arena*);
template Protobuf::Route_Entry_ObtainedSchematic* Arena::CreateMaybeMessage<Protobuf::Route_Entry_ObtainedSchematic>(Arena*);
template Protobuf::Route_Entry_FabricatedObject* Arena::CreateMaybeMessage<Protobuf::Route_Entry_FabricatedObject>(Arena*);
template Protobuf::Route_Entry_RepairedObject* Arena::CreateMaybeMessage<Protobuf::Route_Entry_RepairedObject>(Arena*);
template Protobuf::Route_Entry_ObtainedStudy* Arena::CreateMaybeMessage<Protobuf::Route_Entry_ObtainedStudy>(Arena*);
template Protobuf::Route_Entry* Arena::CreateMaybeMessage<Protobuf::Route_Entry>(Arena*);
}
}
