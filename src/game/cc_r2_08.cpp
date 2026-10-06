// Protobuf::Stats_Kills_ClassesDestroyed scalar setters (second batch) and
// Protobuf::Stats_Resources::mutable_*() (scoresheet.pb.h, protoc 3.5.1 output), matched
// against COGMIND.exe (Beta 17.1). The generated accessors are header inlines, emitted only
// where game code calls them (GameMetaData::unserializeOldMetaBin()). The classes are
// redeclared here (layout only).

#include <stddef.h>

namespace google
{
namespace protobuf
{
typedef int int32;
}
}

namespace Protobuf
{

class Stats_Resources_SalvageCreated
{
public:
	Stats_Resources_SalvageCreated();
private:
	char pad[0x14];
};

class Stats_Resources_PartsFieldRecycled
{
public:
	Stats_Resources_PartsFieldRecycled();
private:
	char pad[0x14];
};

class Stats_Resources_PartsSelfDestructed
{
public:
	Stats_Resources_PartsSelfDestructed();
private:
	char pad[0x14];
};

class Stats_Resources_PartsRestored
{
public:
	Stats_Resources_PartsRestored();
private:
	char pad[0x18];
};

class Stats_Resources
{
public:
	Stats_Resources_SalvageCreated* mutable_salvage_created();
	Stats_Resources_PartsFieldRecycled* mutable_parts_field_recycled();
	Stats_Resources_PartsSelfDestructed* mutable_parts_self_destructed();
	Stats_Resources_PartsRestored* mutable_parts_restored();

private:
	char pad0[0xc];	// vptr, _internal_metadata_, _has_bits_ etc.
	Stats_Resources_SalvageCreated* salvage_created_;
	Stats_Resources_PartsFieldRecycled* parts_field_recycled_;
	Stats_Resources_PartsSelfDestructed* parts_self_destructed_;
	Stats_Resources_PartsRestored* parts_restored_;
};

Stats_Resources_SalvageCreated* Stats_Resources::mutable_salvage_created()
{
	if (salvage_created_ == NULL)
	{
		salvage_created_ = new Stats_Resources_SalvageCreated;
	}
	return salvage_created_;
}

Stats_Resources_PartsFieldRecycled* Stats_Resources::mutable_parts_field_recycled()
{
	if (parts_field_recycled_ == NULL)
	{
		parts_field_recycled_ = new Stats_Resources_PartsFieldRecycled;
	}
	return parts_field_recycled_;
}

Stats_Resources_PartsSelfDestructed* Stats_Resources::mutable_parts_self_destructed()
{
	if (parts_self_destructed_ == NULL)
	{
		parts_self_destructed_ = new Stats_Resources_PartsSelfDestructed;
	}
	return parts_self_destructed_;
}

Stats_Resources_PartsRestored* Stats_Resources::mutable_parts_restored()
{
	if (parts_restored_ == NULL)
	{
		parts_restored_ = new Stats_Resources_PartsRestored;
	}
	return parts_restored_;
}

class Stats_Kills_ClassesDestroyed
{
public:
	void set_cutter(::google::protobuf::int32 value);
	void set_heavy(::google::protobuf::int32 value);
	void set_armor_guard(::google::protobuf::int32 value);
	void set_m_shell_atk(::google::protobuf::int32 value);
	void set_m_shell_def(::google::protobuf::int32 value);
	void set_enhanced_sentry(::google::protobuf::int32 value);
	void set_enhanced_demolisher(::google::protobuf::int32 value);
	void set_enhanced_qseries(::google::protobuf::int32 value);
	void set_clone_special(::google::protobuf::int32 value);
	void set_hotshot(::google::protobuf::int32 value);
	void set_decapitator(::google::protobuf::int32 value);
	void set_immortal(::google::protobuf::int32 value);
	void set_overlord(::google::protobuf::int32 value);
	void set_combat_programmer(::google::protobuf::int32 value);
	void set_investigator(::google::protobuf::int32 value);
	void set_striker(::google::protobuf::int32 value);
	void set_superbehemoth(::google::protobuf::int32 value);
	void set_fortress(::google::protobuf::int32 value);
	void set_vseries(::google::protobuf::int32 value);
	void set_protovariant_l(::google::protobuf::int32 value);
	void set_protovariant_y(::google::protobuf::int32 value);
	void set_protovariant_x(::google::protobuf::int32 value);
	void set_protovariant_p(::google::protobuf::int32 value);
	void set_artisan(::google::protobuf::int32 value);

private:
	char pad0[8];	// vptr (::google::protobuf::Message), _internal_metadata_
	::google::protobuf::int32 overall_;
	::google::protobuf::int32 worker_;
	::google::protobuf::int32 builder_;
	::google::protobuf::int32 tunneler_;
	::google::protobuf::int32 hauler_;
	::google::protobuf::int32 recycler_;
	::google::protobuf::int32 carrier_;
	::google::protobuf::int32 minesweeper_;
	::google::protobuf::int32 mechanic_;
	::google::protobuf::int32 operator__;
	::google::protobuf::int32 drone_;
	::google::protobuf::int32 turret_;
	::google::protobuf::int32 watcher_;
	::google::protobuf::int32 swarmer_;
	::google::protobuf::int32 saboteur_;
	::google::protobuf::int32 grunt_;
	::google::protobuf::int32 brawler_;
	::google::protobuf::int32 duelist_;
	::google::protobuf::int32 protector_;
	::google::protobuf::int32 researcher_;
	::google::protobuf::int32 sentry_;
	::google::protobuf::int32 demolisher_;
	::google::protobuf::int32 specialist_;
	::google::protobuf::int32 hunter_;
	::google::protobuf::int32 programmer_;
	::google::protobuf::int32 q_series_;
	::google::protobuf::int32 behemoth_;
	::google::protobuf::int32 compactor_;
	::google::protobuf::int32 cetus_guard_;
	::google::protobuf::int32 quarantine_guard_;
	::google::protobuf::int32 s7_guard_;
	::google::protobuf::int32 m_guard_;
	::google::protobuf::int32 enhanced_grunt_;
	::google::protobuf::int32 enhanced_sentry_;
	::google::protobuf::int32 enhanced_hunter_;
	::google::protobuf::int32 enhanced_programmer_;
	::google::protobuf::int32 lightning_;
	::google::protobuf::int32 tracker_;
	::google::protobuf::int32 combat_programmer_;
	::google::protobuf::int32 investigator_;
	::google::protobuf::int32 striker_;
	::google::protobuf::int32 executioner_;
	::google::protobuf::int32 superbehemoth_;
	::google::protobuf::int32 alpha_7_;
	::google::protobuf::int32 fortress_;
	::google::protobuf::int32 protovariant_g_;
	::google::protobuf::int32 protovariant_l_;
	::google::protobuf::int32 protovariant_y_;
	::google::protobuf::int32 protovariant_d_;
	::google::protobuf::int32 protovariant_x_;
	::google::protobuf::int32 protovariant_h_;
	::google::protobuf::int32 protovariant_p_;
	::google::protobuf::int32 zionite_;
	::google::protobuf::int32 z_technician_;
	::google::protobuf::int32 z_courier_;
	::google::protobuf::int32 z_light_;
	::google::protobuf::int32 z_heavy_;
	::google::protobuf::int32 z_ex_;
	::google::protobuf::int32 decomposer_;
	::google::protobuf::int32 packrat_;
	::google::protobuf::int32 samaritan_;
	::google::protobuf::int32 tinkerer_;
	::google::protobuf::int32 demented_;
	::google::protobuf::int32 furnace_;
	::google::protobuf::int32 parasite_;
	::google::protobuf::int32 thief_;
	::google::protobuf::int32 master_thief_;
	::google::protobuf::int32 assembler_;
	::google::protobuf::int32 assembled_;
	::google::protobuf::int32 golem_;
	::google::protobuf::int32 surgeon_;
	::google::protobuf::int32 wasp_;
	::google::protobuf::int32 thug_;
	::google::protobuf::int32 savage_;
	::google::protobuf::int32 butcher_;
	::google::protobuf::int32 bouncer_;
	::google::protobuf::int32 martyr_;
	::google::protobuf::int32 guerrilla_;
	::google::protobuf::int32 wizard_;
	::google::protobuf::int32 marauder_;
	::google::protobuf::int32 fireman_;
	::google::protobuf::int32 mutant_;
	::google::protobuf::int32 commander_;
	::google::protobuf::int32 knight_;
	::google::protobuf::int32 troll_;
	::google::protobuf::int32 dragon_;
	::google::protobuf::int32 hydra_;
	::google::protobuf::int32 borebot_;
	::google::protobuf::int32 revision_;
	::google::protobuf::int32 abomination_;
	::google::protobuf::int32 anomaly_;
	::google::protobuf::int32 player_;
	::google::protobuf::int32 enhanced_qseries_;
	::google::protobuf::int32 enhanced_demolisher_;
	::google::protobuf::int32 heavy_;
	::google::protobuf::int32 cutter_;
	::google::protobuf::int32 sapper_;
	::google::protobuf::int32 m_shell_atk_;
	::google::protobuf::int32 m_shell_def_;
	::google::protobuf::int32 infiltrator_;
	::google::protobuf::int32 subdweller_;
	::google::protobuf::int32 artisan_;
	::google::protobuf::int32 cobbler_;
	::google::protobuf::int32 scrapper_;
	::google::protobuf::int32 elite_;
	::google::protobuf::int32 scrapoid_;
	::google::protobuf::int32 scraphulk_;
	::google::protobuf::int32 bolteater_;
	::google::protobuf::int32 federalist_;
	::google::protobuf::int32 explorer_;
	::google::protobuf::int32 ranger_;
	::google::protobuf::int32 guru_;
	::google::protobuf::int32 scientist_;
	::google::protobuf::int32 armor_guard_;
	::google::protobuf::int32 botcube_;
	::google::protobuf::int32 hotshot_;
	::google::protobuf::int32 decapitator_;
	::google::protobuf::int32 immortal_;
	::google::protobuf::int32 overlord_;
	::google::protobuf::int32 vseries_;
	::google::protobuf::int32 unchained_;
	::google::protobuf::int32 clone_special_;
	mutable int _cached_size_;
};

void Stats_Kills_ClassesDestroyed::set_cutter(::google::protobuf::int32 value)
{
	cutter_ = value;
}

void Stats_Kills_ClassesDestroyed::set_heavy(::google::protobuf::int32 value)
{
	heavy_ = value;
}

void Stats_Kills_ClassesDestroyed::set_armor_guard(::google::protobuf::int32 value)
{
	armor_guard_ = value;
}

void Stats_Kills_ClassesDestroyed::set_m_shell_atk(::google::protobuf::int32 value)
{
	m_shell_atk_ = value;
}

void Stats_Kills_ClassesDestroyed::set_m_shell_def(::google::protobuf::int32 value)
{
	m_shell_def_ = value;
}

void Stats_Kills_ClassesDestroyed::set_enhanced_sentry(::google::protobuf::int32 value)
{
	enhanced_sentry_ = value;
}

void Stats_Kills_ClassesDestroyed::set_enhanced_demolisher(::google::protobuf::int32 value)
{
	enhanced_demolisher_ = value;
}

void Stats_Kills_ClassesDestroyed::set_enhanced_qseries(::google::protobuf::int32 value)
{
	enhanced_qseries_ = value;
}

void Stats_Kills_ClassesDestroyed::set_clone_special(::google::protobuf::int32 value)
{
	clone_special_ = value;
}

void Stats_Kills_ClassesDestroyed::set_hotshot(::google::protobuf::int32 value)
{
	hotshot_ = value;
}

void Stats_Kills_ClassesDestroyed::set_decapitator(::google::protobuf::int32 value)
{
	decapitator_ = value;
}

void Stats_Kills_ClassesDestroyed::set_immortal(::google::protobuf::int32 value)
{
	immortal_ = value;
}

void Stats_Kills_ClassesDestroyed::set_overlord(::google::protobuf::int32 value)
{
	overlord_ = value;
}

void Stats_Kills_ClassesDestroyed::set_combat_programmer(::google::protobuf::int32 value)
{
	combat_programmer_ = value;
}

void Stats_Kills_ClassesDestroyed::set_investigator(::google::protobuf::int32 value)
{
	investigator_ = value;
}

void Stats_Kills_ClassesDestroyed::set_striker(::google::protobuf::int32 value)
{
	striker_ = value;
}

void Stats_Kills_ClassesDestroyed::set_superbehemoth(::google::protobuf::int32 value)
{
	superbehemoth_ = value;
}

void Stats_Kills_ClassesDestroyed::set_fortress(::google::protobuf::int32 value)
{
	fortress_ = value;
}

void Stats_Kills_ClassesDestroyed::set_vseries(::google::protobuf::int32 value)
{
	vseries_ = value;
}

void Stats_Kills_ClassesDestroyed::set_protovariant_l(::google::protobuf::int32 value)
{
	protovariant_l_ = value;
}

void Stats_Kills_ClassesDestroyed::set_protovariant_y(::google::protobuf::int32 value)
{
	protovariant_y_ = value;
}

void Stats_Kills_ClassesDestroyed::set_protovariant_x(::google::protobuf::int32 value)
{
	protovariant_x_ = value;
}

void Stats_Kills_ClassesDestroyed::set_protovariant_p(::google::protobuf::int32 value)
{
	protovariant_p_ = value;
}

void Stats_Kills_ClassesDestroyed::set_artisan(::google::protobuf::int32 value)
{
	artisan_ = value;
}

}
