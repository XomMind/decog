// team_c_37: Scorekeeper::createProtobuf (0x480100): fills the scoresheet protobuf from the scorekeeper's run data
//	and optionally writes it out as JSON next to the text scoresheet
// NOTE: member names are placeholders (f<offset>); protobuf classes are redeclared here (accessors only, no bodies)
#include <string>
#include <vector>
#include <fstream>
using namespace std;

namespace google
{
namespace protobuf
{
typedef int int32;
class FieldDescriptor;
class EnumValueDescriptor { public: int number() const; };
class EnumDescriptor { public: const EnumValueDescriptor *FindValueByName(const string &name) const; };
class Descriptor { public: const FieldDescriptor *FindFieldByName(const string &name) const; };
class Message;
class Reflection	// NOTE: vtable slots as used here (SetInt32 0x70, SetString 0x8c)
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
	virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
	virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50();
	virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
	virtual void SetInt32(Message *message, const FieldDescriptor *field, int32 value) const;
	virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88();
	virtual void SetString(Message *message, const FieldDescriptor *field, const string &value) const;
};
class Message	// NOTE: vtable slots as used here (GetReflection 0x58)
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
	virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
	virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50();
	virtual void v54();
	virtual const Reflection *GetReflection() const;
	const Descriptor *GetDescriptor() const;
};
}
}

namespace Protobuf
{
using ::google::protobuf::int32;
const ::google::protobuf::EnumDescriptor *MapType_descriptor();
class Location;
class Header { public: void set_filename(const string &v); void set_version(const string &v); void set_build(const string &v); void set_difficulty(int v); void set_run_end_date(const string &v); void set_run_end_time(const string &v); void set_special_mode(int v); void set_player_name(const string &v); void set_run_result(const string &v); void set_win(bool v); };
class Performance_Entry { public: void set_count(int32 v); void set_points(int32 v); };
class Performance { public: void set_total_score(int32 v); Performance_Entry *mutable_evolutions(); Performance_Entry *mutable_regions_visited(); Performance_Entry *mutable_robots_destroyed(); Performance_Entry *mutable_value_destroyed(); Performance_Entry *mutable_prototypes_identified(); Performance_Entry *mutable_alien_tech_used(); Performance_Entry *mutable_bonus(); };
class Bonus : public ::google::protobuf::Message { };
class Cogmind_VariableValue { public: void set_current(int32 v); void set_maximum(int32 v); };
class Cogmind_Corruption { public: void set_value(int32 v); void set_membrane(bool v); };
class Cogmind_Temperature { public: void set_heat(int v); void set_value(int32 v); void set_thermoelectric_network(bool v); };
class Cogmind_Movement { public: void set_mode(int v); void set_speed(int32 v); void set_overweight_factor(int32 v); void set_teleportitis_level(int32 v); };
class Cogmind { public: Cogmind_VariableValue *mutable_core_integrity(); Cogmind_VariableValue *mutable_matter(); Cogmind_VariableValue *mutable_energy(); Cogmind_Corruption *mutable_corruption(); Cogmind_Temperature *mutable_temperature(); Cogmind_Movement *mutable_movement(); void set_allocated_location(Location *location); };
class PartSection { public: void set_slots(int32 v); void add_parts(const string &v); };
class Parts { public: PartSection *mutable_power(); PartSection *mutable_propulsion(); PartSection *mutable_utility(); PartSection *mutable_weapon(); PartSection *mutable_inventory(); };
class PeakState { public: PartSection *mutable_power(); PartSection *mutable_propulsion(); PartSection *mutable_utility(); PartSection *mutable_weapon(); PartSection *mutable_inventory(); void set_rating(int32 v); };
class Favorites_Power : public ::google::protobuf::Message { public: void set_overall(const string &v); };
class Favorites_Propulsion : public ::google::protobuf::Message { public: void set_overall(const string &v); };
class Favorites_Utility : public ::google::protobuf::Message { public: void set_overall(const string &v); };
class Favorites_Weapon : public ::google::protobuf::Message { public: void set_overall(const string &v); };
class Favorites { public: Favorites_Power *mutable_power(); Favorites_Propulsion *mutable_propulsion(); Favorites_Utility *mutable_utility(); Favorites_Weapon *mutable_weapon(); };
class ClassDistribution_ClassEntry { public: void set_name(const string &v); void set_percent(int32 v); };
class ClassDistribution { public: ClassDistribution_ClassEntry *add_classes(); };
class HistoryEventWin { public: void set_turn(int32 v); void set_event(const string &v); };
class LastMessages { public: void add_messages(const string &v); };
class Map { public: void add_lines(const string &v); };
class BestStates : public ::google::protobuf::Message { };
class AlienTechUsed { public: void add_parts(const string &v); };
class Achievements { public: void add_achievements(const string &v); };
class Challenges { public: void add_challenges(const string &v); };
class CogshopPurchases_Purchase { public: void set_name(const string &v); void set_cost(int32 v); };
class CogshopPurchases { public: CogshopPurchases_Purchase *add_purchases(); };
class PolymindHostKillLeaderboard_HostRecord { public: void set_name(const string &v); void set_allocated_location(Location *location); void set_kills(int32 v); };
class PolymindHostKillLeaderboard { public: PolymindHostKillLeaderboard_HostRecord *add_host_records(); };
class Game { public: void set_world_seed(const string &v); void set_world_seed_is_manual(bool v); void set_run_time(const string &v); void set_cumulative_hours(const string &v); void set_run_start_date(const string &v); void set_run_end_date(const string &v); void set_run_sessions(int32 v); void set_run_loads(int32 v); void set_difficulty(int v); void set_special_mode(int v); void set_game_number(int32 v); void add_game_counts(int32 v); void set_win_type(int32 v); void set_win_total(int32 v); void add_win_type_history(int32 v); void set_lore_percent(int32 v); void set_gallery_percent(int32 v); void set_achievement_percent(int32 v); void set_wizard_mode_run(bool v); };
class Options { public: void set_layout(int v); void set_ascii(bool v); void set_keyboard(bool v); void set_movement(int v); void set_keybinds(bool v); void set_fullscreen(int v); void set_font_set(const string &v); void set_map_width(int32 v); void set_map_height(int32 v); void set_zoom_use(int32 v); void set_tactical_hud(bool v); void set_render_filters_map(const string &v); void set_render_filters(const string &v); void set_steam(int v); };
class Meta { public: void set_run_guid(const string &v); void set_player_public_key(const void *v, size_t size); void set_player_guid(const string &v); void set_player_id(int32 v); void set_run_id(int32 v); };
class Stats_Kills { public: void add_list_of_uniques_npcs_destroyed(const string &v); };
class Stats { public: Stats_Kills *mutable_kills(); };
class Route_Entry_DiscoveredExit { public: void set_destination(int v); void set_destination_known(bool v); void set_reached(bool v); void set_count(int32 v); };
class Route_Entry_HistoryEvent { public: void set_turn(int32 v); void set_event(const string &v); };
class Route_Entry_ObtainedSchematic { public: void set_name(const string &v); void set_type(int v); void set_method(int v); };
class Route_Entry_FabricatedObject { public: void set_name(const string &v); void set_count(int32 v); void set_preloaded(bool v); void set_authchip(bool v); };
class Route_Entry_RepairedObject { public: void set_name(const string &v); void set_integrity(int32 v); void set_broken(bool v); void set_corrupted(bool v); };
class Route_Entry_ObtainedStudy { public: void set_name(const string &v); void set_method(int v); };
class Route_Entry_Factors { public: void add_factor_one(int32 v); };
class Route_Entry { public: void set_allocated_location(Location *location); Route_Entry_DiscoveredExit *add_discovered_exits(); void set_dominant_class(const string &v); Route_Entry_HistoryEvent *add_history_events(); Route_Entry_ObtainedSchematic *add_obtained_schematics(); Route_Entry_FabricatedObject *add_fabricated_objects(); Route_Entry_RepairedObject *add_repaired_objects(); Route_Entry_ObtainedStudy *add_obtained_studies(); Route_Entry_Factors *mutable_factors(); Stats *mutable_stats(); };
class Route { public: Route_Entry *add_entries(); };
class Scoresheet
{
public:
	Header *mutable_header();
	Performance *mutable_performance();
	Bonus *mutable_bonus();
	Cogmind *mutable_cogmind();
	Parts *mutable_parts();
	PeakState *mutable_peak_state();
	Favorites *mutable_favorites();
	ClassDistribution *mutable_class_distribution();
	HistoryEventWin *mutable_history_event_win();
	LastMessages *mutable_last_messages();
	Map *mutable_map();
	BestStates *mutable_best_states();
	AlienTechUsed *mutable_alien_tech_used();
	Achievements *mutable_achievements();
	Challenges *mutable_challenges();
	CogshopPurchases *mutable_cogshop_purchases();
	PolymindHostKillLeaderboard *mutable_polymind_host_kill_leaderboard();
	Game *mutable_game();
	Options *mutable_options();
	Meta *mutable_meta();
	Stats *mutable_stats();
	Route *mutable_route();
};
}

struct Point { int x; int y; Point(const Point &p); };	// NOTE: placeholder
Protobuf::Location *OpR1g_createLocation(Point pos);
string intToString(int value);
string floatToString(float value, int unknown1, int unknown2);
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
string OpC_getRecordFileName_471c50(int index);	// NOTE: placeholder name
string OpC_getFileName_471dd0(const string &name);	// NOTE: placeholder name
void logFatal(string location, string message);
struct OpC_D4S { int code; string message; ~OpC_D4S(); };	// NOTE: placeholder layout
OpC_D4S c37_toJson_4326e0(Protobuf::Scoresheet *sheet, string &out);	// NOTE: placeholder name (0x4326e0)
class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;
extern const float c30_c37020, c30_c37024;	// NOTE: placeholder names
extern string gameStrings_d293c0[], gameStrings_cfe140[];	// global_string_arrays.cpp
struct C37_Location { Point getPos(); };	// NOTE: placeholder (Location_46ecb0::unknown46ee50)
struct C37_Handle { int v; C37_Location *get23c(); };	// NOTE: placeholder
extern vector<C37_Handle> c37_d1e88c;	// NOTE: placeholder names below
extern string c37_cfd42c, c37_d21928, c37_cf33fc;
extern int c37_cf4718, c37_cf462c, c37_cf4b38, c37_ba0028[];
extern bool c37_d28dec, c37_d28ded;
struct C37_Flags { bool getField(); };
extern C37_Flags c37_cf45d8;
struct C37_Grid { int width, height; char *cells; int getWidth(); int getHeight(); char *at(int x, int y); };	// NOTE: placeholder (Array2D<char>)
struct C37_Exit { int map; bool known; bool reached; int count; };	// NOTE: placeholder layout
class OpR1h_StatSet;

class Scorekeeper	// NOTE: placeholder layout
{
public:
	OpR1h_StatSet *f0;
	vector<OpR1h_StatSet *> f4;
	char pad14[0x7c];
	string f90;
	string fac;
	string fc8;
	string fe4;
	vector<int> f100;
	int f110;
	int f114;
	int f118;
	int f11c;
	int f120;
	int f124;
	int f128;
	int f12c;
	bool f130;
	int f134;
	int f138;
	bool f13c;
	int f140;
	int f144;
	int f148;
	int f14c;
	Point f150;
	vector<int> f158;
	vector<int> f168;
	vector< vector<string> > f178;
	vector< vector<int> > f188;
	vector< vector<int> > f198;
	char pad1a8[0x4];
	int f1ac;
	vector<string> f1b0;
	vector<int> f1c0;
	C37_Grid f1d0;
	int f1dc;
	vector< vector<string> > f1e0;
	vector< vector<int> > f1f0;
	vector<int> f200;
	vector<string> f210;
	vector<int> f220;
	int f230;
	vector<string> f234;
	vector<string> f244;
	vector<string> f254;
	vector<int> f264;
	vector<string> f274;
	int f284;
	vector<int> f288;
	vector<string> f298;
	vector<int> f2a8;
	vector<int> f2b8;
	vector< vector<int> > f2c8;
	vector<string> f2d8;
	vector< vector<C37_Exit> > f2e8;
	vector<int> f2f8;
	vector<int> f308;
	vector<string> f318;
	vector<string> f328;
	vector<string> f338;
	vector<int> f348;
	vector<int> f358;
	vector<string> f368;
	vector<int> f378;
	vector<int> f388;
	vector<string> f398;
	vector<int> f3a8;
	vector<int> f3b8;
	vector<int> f3c8;
	vector<int> f3d8;
	vector<string> f3e8;
	vector<int> f3f8;
	vector<int> f408;
	vector<int> f418;
	vector<int> f428;
	vector<string> f438;
	vector<int> f448;
	vector<int> f458;
	vector< vector<int> > f468;
	vector<string> f478;
	vector<string> f488;
	vector<string> f498;
	vector<string> f4a8;
	vector<int> f4b8;
	vector<string> f4c8;
	vector<int> f4d8;
	vector<int> f4e8;
	string f4f8;
	bool f514;
	unsigned int f518;
	unsigned int f51c;
	string f520;
	string f53c;
	int f558;
	int f55c;
	string f560;
	int f57c;
	int f580;
	int f584;
	int f588;
	int f58c;
	int f590;
	vector<int> f594;
	int f5a4;
	int f5a8;
	int f5ac;
	bool f5b0;
	int f5b4;
	bool f5b8;
	bool f5b9;
	int f5bc;
	bool f5c0;
	int f5c4;
	string f5c8;
	int f5e4;
	int f5e8;
	int f5ec;
	bool f5f0;
	string f5f4;
	string f610;
	int f62c;
	string f630;
	unsigned char f64c[0x20];
	string f66c;
	int f688;
	int f68c;

	int delegate(int index);	// NOTE: placeholder name
	void opG1_fillStats(OpR1h_StatSet *stats, Protobuf::Stats *out);
	void createProtobuf(Protobuf::Scoresheet *sheet, string filename, bool isDump);
};

void Scorekeeper::createProtobuf(Protobuf::Scoresheet *sheet, string filename, bool isDump)
{
	int a;
	Protobuf::CogshopPurchases_Purchase *a1;
	Protobuf::PolymindHostKillLeaderboard_HostRecord *center;
	Protobuf::Route_Entry *amount;
	Protobuf::Header *answer = sheet->mutable_header();
	answer->set_filename(filename);
	answer->set_version(c37_d21928);
	answer->set_build(c37_cf33fc);
	answer->set_difficulty(c37_cf45d8.getField() ? 3 : c37_cf4718);
	answer->set_run_end_date(f90);
	answer->set_run_end_time(fac);
	answer->set_special_mode(c37_cf462c);
	answer->set_player_name(fc8);
	answer->set_run_result(fe4);
	answer->set_win(c37_cf4b38 <= 9);
	Protobuf::Performance *adj = sheet->mutable_performance();
	adj->set_total_score(f110);
	Protobuf::Performance_Entry *ally = adj->mutable_evolutions();
	ally->set_count(delegate(0));
	ally->set_points(f100[0]);
	ally = adj->mutable_regions_visited();
	ally->set_count(delegate(1));
	ally->set_points(f100[1]);
	ally = adj->mutable_robots_destroyed();
	ally->set_count(delegate(2));
	ally->set_points(f100[2]);
	ally = adj->mutable_value_destroyed();
	ally->set_count(delegate(3));
	ally->set_points(f100[3]);
	ally = adj->mutable_prototypes_identified();
	ally->set_count(delegate(4));
	ally->set_points(f100[4]);
	ally = adj->mutable_alien_tech_used();
	ally->set_count(delegate(5));
	ally->set_points(f100[5]);
	ally = adj->mutable_bonus();
	ally->set_count(delegate(6));
	ally->set_points(f100[6]);
	const ::google::protobuf::FieldDescriptor *adjacent;
	Protobuf::Bonus *area = sheet->mutable_bonus();
	const ::google::protobuf::Descriptor *base = area->GetDescriptor();
	const ::google::protobuf::Reflection *bestDistance = area->GetReflection();
	for (int cols = 7; cols <= 106; cols++)
	{
		adjacent = base->FindFieldByName(OpC_getRecordFileName_471c50(cols));
		if (adjacent == NULL)
			logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getRecordFileName_471c50(cols));
		bestDistance->SetInt32(area,adjacent,delegate(cols));
	}
	Protobuf::Cogmind *areas = sheet->mutable_cogmind();
	areas->mutable_core_integrity()->set_current(f114);
	areas->mutable_core_integrity()->set_maximum(f118);
	areas->mutable_matter()->set_current(f11c);
	areas->mutable_matter()->set_maximum(f120);
	areas->mutable_energy()->set_current(f124);
	areas->mutable_energy()->set_maximum(f128);
	areas->mutable_corruption()->set_value(f12c);
	areas->mutable_corruption()->set_membrane(f130);
	areas->mutable_temperature()->set_heat(f134);
	areas->mutable_temperature()->set_value(f138);
	areas->mutable_temperature()->set_thermoelectric_network(f13c);
	areas->mutable_movement()->set_mode(f140);
	areas->mutable_movement()->set_speed(f144);
	areas->mutable_movement()->set_overweight_factor(f14c);
	areas->mutable_movement()->set_teleportitis_level(f148);
	areas->set_allocated_location(OpR1g_createLocation(f150));
	Protobuf::Parts *bestDist = sheet->mutable_parts();
	bestDist->mutable_power()->set_slots(f158[0]);
	for (unsigned int cols = 0; cols < f178[0].size(); cols++)
		bestDist->mutable_power()->add_parts(f178[0][cols]);
	bestDist->mutable_propulsion()->set_slots(f158[1]);
	for (unsigned int cols = 0; cols < f178[1].size(); cols++)
		bestDist->mutable_propulsion()->add_parts(f178[1][cols]);
	bestDist->mutable_utility()->set_slots(f158[2]);
	for (unsigned int cols = 0; cols < f178[2].size(); cols++)
		bestDist->mutable_utility()->add_parts(f178[2][cols]);
	bestDist->mutable_weapon()->set_slots(f158[3]);
	for (unsigned int cols = 0; cols < f178[3].size(); cols++)
		bestDist->mutable_weapon()->add_parts(f178[3][cols]);
	bestDist->mutable_inventory()->set_slots(f1ac);
	for (unsigned int cols = 0; cols < f1b0.size(); cols++)
		bestDist->mutable_inventory()->add_parts(f1b0[cols]);
	Protobuf::PeakState *active = sheet->mutable_peak_state();
	if (!f200.empty())
	{
		active->mutable_power()->set_slots(f200[0]);
		for (unsigned int current = 0; current < f1e0[0].size(); current++)
			active->mutable_power()->add_parts(f1e0[0][current]);
		active->mutable_propulsion()->set_slots(f200[1]);
		for (unsigned int current = 0; current < f1e0[1].size(); current++)
			active->mutable_propulsion()->add_parts(f1e0[1][current]);
		active->mutable_utility()->set_slots(f200[2]);
		for (unsigned int current = 0; current < f1e0[2].size(); current++)
			active->mutable_utility()->add_parts(f1e0[2][current]);
		active->mutable_weapon()->set_slots(f200[3]);
		for (unsigned int current = 0; current < f1e0[3].size(); current++)
			active->mutable_weapon()->add_parts(f1e0[3][current]);
		active->mutable_inventory()->set_slots(f230);
		for (unsigned int current = 0; current < f210.size(); current++)
			active->mutable_inventory()->add_parts(f210[current]);
		active->set_rating(f1dc);
	}
	Protobuf::Favorites *added = sheet->mutable_favorites();
	if (!f234[0].empty())
	{
		added->mutable_power()->set_overall(f234[0]);
		for (int distanceSq = 0; distanceSq < 31; distanceSq++)
		{
			if (c37_ba0028[distanceSq] == 0 && !f244[distanceSq].empty())
			{
				adjacent = added->mutable_power()->GetDescriptor()->FindFieldByName(OpC_getFileName_471dd0(gameStrings_d293c0[distanceSq]));
				if (adjacent == NULL)
					logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getFileName_471dd0(gameStrings_d293c0[distanceSq]));
				added->mutable_power()->GetReflection()->SetString(added->mutable_power(),adjacent,f244[distanceSq]);
			}
		}
	}
	if (!f234[1].empty())
	{
		added->mutable_propulsion()->set_overall(f234[1]);
		for (int cols = 0; cols < 31; cols++)
		{
			if (c37_ba0028[cols] == 1 && !f244[cols].empty())
			{
				adjacent = added->mutable_propulsion()->GetDescriptor()->FindFieldByName(OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				if (adjacent == NULL)
					logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				added->mutable_propulsion()->GetReflection()->SetString(added->mutable_propulsion(),adjacent,f244[cols]);
			}
		}
	}
	if (!f234[2].empty())
	{
		added->mutable_utility()->set_overall(f234[2]);
		for (int cols = 0; cols < 31; cols++)
		{
			if (c37_ba0028[cols] == 2 && !f244[cols].empty())
			{
				adjacent = added->mutable_utility()->GetDescriptor()->FindFieldByName(OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				if (adjacent == NULL)
					logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				added->mutable_utility()->GetReflection()->SetString(added->mutable_utility(),adjacent,f244[cols]);
			}
		}
	}
	if (!f234[3].empty())
	{
		added->mutable_weapon()->set_overall(f234[3]);
		for (int cols = 0; cols < 31; cols++)
		{
			if (c37_ba0028[cols] == 3 && !f244[cols].empty())
			{
				adjacent = added->mutable_weapon()->GetDescriptor()->FindFieldByName(OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				if (adjacent == NULL)
					logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getFileName_471dd0(gameStrings_d293c0[cols]));
				added->mutable_weapon()->GetReflection()->SetString(added->mutable_weapon(),adjacent,f244[cols]);
			}
		}
	}
	Protobuf::ClassDistribution *bestIndex = sheet->mutable_class_distribution();
	for (unsigned int cols = 0; cols < f254.size(); cols++)
	{
		Protobuf::ClassDistribution_ClassEntry *clean = bestIndex->add_classes();
		clean->set_name(f254[cols]);
		clean->set_percent(f264[cols]);
	}
	if (!f2f8.empty() && f308.back() == -1)
	{
		Protobuf::HistoryEventWin *cols = sheet->mutable_history_event_win();
		cols->set_turn(f2f8.back());
		cols->set_event(f318.back());
	}
	Protobuf::LastMessages *buf = sheet->mutable_last_messages();
	for (unsigned int cols = 0; cols < f328.size(); cols++)
		buf->add_messages(f328[cols]);
	Protobuf::Map *action = sheet->mutable_map();
	for (int cols = 0; cols < f1d0.getHeight(); cols++)
	{
		string clean;
		for (int current = 0; current < f1d0.getWidth(); current++)
			clean += *f1d0.at(current,cols);
		action->add_lines(clean);
	}
	Protobuf::BestStates *armor = sheet->mutable_best_states();
	base = armor->GetDescriptor();
	const ::google::protobuf::Reflection *attempts = armor->GetReflection();
	for (int cols = 1121; cols <= 1184; cols++)
	{
		adjacent = base->FindFieldByName(OpC_getRecordFileName_471c50(cols));
		if (adjacent == NULL)
			logFatal("Scorekeeper::createProtobuf()","Field not found: " + OpC_getRecordFileName_471c50(cols));
		attempts->SetInt32(armor,adjacent,delegate(cols));
	}
	Protobuf::AlienTechUsed *bestScore = sheet->mutable_alien_tech_used();
	for (unsigned int cols = 0; cols < f478.size(); cols++)
		bestScore->add_parts(f478[cols]);
	Protobuf::Achievements *avg = sheet->mutable_achievements();
	for (unsigned int cols = 0; cols < f488.size(); cols++)
		avg->add_achievements(f488[cols]);
	Protobuf::Challenges *bestEntity = sheet->mutable_challenges();
	for (unsigned int cols = 0; cols < f498.size(); cols++)
		bestEntity->add_challenges(f498[cols]);
	Protobuf::CogshopPurchases *behaviour = sheet->mutable_cogshop_purchases();
	for (unsigned int cols = 0; cols < f4a8.size(); cols++)
	{
		a1 = behaviour->add_purchases();
		a1->set_name(f4a8[cols]);
		a1->set_cost(f4b8[cols]);
	}
	Protobuf::PolymindHostKillLeaderboard *allies = sheet->mutable_polymind_host_kill_leaderboard();
	for (unsigned int cols = 0; cols < f4c8.size(); cols++)
	{
		center = allies->add_host_records();
		center->set_name(f4c8[cols]);
		center->set_allocated_location(OpR1g_createLocation(c37_d1e88c[f4d8[cols]].get23c()->getPos()));
		center->set_kills(f4e8[cols]);
	}
	Protobuf::Game *bits = sheet->mutable_game();
	bits->set_world_seed(f4f8);
	bits->set_world_seed_is_manual(f514);
	bits->set_run_time(padLeft_408090(intToString(f518 / 3600),2,'0') + ":" + padLeft_408090(intToString(f518 / 60 % 60),2,'0') + ":" + padLeft_408090(intToString(f518 % 60),2,'0'));
	bits->set_cumulative_hours(floatToString(f51c / 60.0,1,1));
	bits->set_run_start_date(f520);
	bits->set_run_end_date(f90);
	bits->set_run_sessions(f558);
	bits->set_run_loads(f55c);
	bits->set_difficulty(c37_cf45d8.getField() ? 3 : c37_cf4718);
	bits->set_special_mode(c37_cf462c);
	bits->set_game_number(f57c);
	bits->add_game_counts(f580);
	bits->add_game_counts(f584);
	bits->add_game_counts(f588);
	bits->set_win_type(f58c);
	bits->set_win_total(f590);
	for (unsigned int cols = 0; cols < f594.size(); cols++)
		bits->add_win_type_history(f594[cols]);
	bits->set_lore_percent(f5a4);
	bits->set_gallery_percent(f5a8);
	bits->set_achievement_percent(f5ac);
	bits->set_wizard_mode_run(f5b0);
	Protobuf::Options *bestPoint = sheet->mutable_options();
	bestPoint->set_layout(f5b4);
	bestPoint->set_ascii(f5b8);
	bestPoint->set_keyboard(f5b9);
	bestPoint->set_movement(f5bc);
	bestPoint->set_keybinds(f5c0);
	bestPoint->set_fullscreen(f5c4);
	bestPoint->set_font_set(f5c8);
	bestPoint->set_map_width(f5e4);
	bestPoint->set_map_height(f5e8);
	bestPoint->set_zoom_use(f5ec);
	bestPoint->set_tactical_hud(f5f0);
	bestPoint->set_render_filters_map(f5f4);
	bestPoint->set_render_filters(f610);
	bestPoint->set_steam(f62c);
	Protobuf::Meta *col = sheet->mutable_meta();
	col->set_run_guid(f630);
	col->set_player_public_key(f64c,32);
	col->set_player_guid(f66c);
	col->set_player_id(f688);
	col->set_run_id(f68c);
	opG1_fillStats(f0,sheet->mutable_stats());
	int bonus = 0;
	int bottom = 0;
	int child = 0;
	int ax = 0;
	int enemy = 0;
	int c = 0;
	int arr = 0;
	const ::google::protobuf::EnumValueDescriptor *c2;
	Protobuf::Route *found2 = sheet->mutable_route();
	for (unsigned int cols = 0; cols < f4.size(); cols++)
	{
		int clean = cols;
		amount = found2->add_entries();
		Point branch = c37_d1e88c[cols].get23c()->getPos();
		amount->set_allocated_location(OpR1g_createLocation(branch));
		Protobuf::Route_Entry_DiscoveredExit *desc = amount->add_discovered_exits();
		for (unsigned int current = 0; current < f2e8[cols].size(); current++)
		{
			c2 = Protobuf::MapType_descriptor()->FindValueByName("MAP_" + gameStrings_cfe140[f2e8[cols][current].map]);
			desc->set_destination(c2->number());
			desc->set_destination_known(f2e8[cols][current].known);
			desc->set_reached(f2e8[cols][current].reached);
			desc->set_count(f2e8[cols][current].count);
		}
		amount->set_dominant_class(f274[cols]);
		for (unsigned int current = bonus; current < f2f8.size(); current++)
		{
			if (f308[current] != clean)
			{
				bonus = current;
				break;
			}
			Protobuf::Route_Entry_HistoryEvent *element = amount->add_history_events();
			element->set_turn(f2f8[current]);
			element->set_event(f318[current]);
		}
		for (unsigned int current = bottom; current < f338.size(); current++)
		{
			if (f348[current] != clean)
			{
				bottom = current;
				break;
			}
			Protobuf::Route_Entry_ObtainedSchematic *element = amount->add_obtained_schematics();
			element->set_name(f338[current]);
			element->set_type(0);
			element->set_method(f358[current]);
		}
		for (unsigned int current = child; current < f368.size(); current++)
		{
			if (f378[current] != clean)
			{
				child = current;
				break;
			}
			Protobuf::Route_Entry_ObtainedSchematic *element = amount->add_obtained_schematics();
			element->set_name(f368[current]);
			element->set_type(1);
			element->set_method(f388[current]);
		}
		for (unsigned int current = ax; current < f398.size(); current++)
		{
			if (f3b8[current] != clean)
			{
				ax = current;
				break;
			}
			Protobuf::Route_Entry_FabricatedObject *element = amount->add_fabricated_objects();
			element->set_name(f398[current]);
			element->set_count(f3a8[current]);
			element->set_preloaded(f3c8[current] != 0);
			element->set_authchip(f3d8[current] != 0);
		}
		for (unsigned int current = enemy; current < f3e8.size(); current++)
		{
			if (f408[current] != clean)
			{
				enemy = current;
				break;
			}
			Protobuf::Route_Entry_RepairedObject *element = amount->add_repaired_objects();
			element->set_name(f3e8[current]);
			element->set_integrity(f3f8[current]);
			element->set_broken(f418[current] != 0);
			element->set_corrupted(f428[current] != 0);
		}
		for (unsigned int current = c; current < f438.size(); current++)
		{
			if (f448[current] != clean)
			{
				c = current;
				break;
			}
			Protobuf::Route_Entry_ObtainedStudy *element = amount->add_obtained_studies();
			element->set_name(f438[current]);
			element->set_method(f458[current]);
		}
		Protobuf::Route_Entry_Factors *dy = amount->mutable_factors();
		if (!f468.empty() && clean != 0 && !f468[clean - 1].empty())
		{
			for (unsigned int current = 0; current < f468[clean - 1].size(); current++)
			{
				if (rng.chance(33))
					dy->add_factor_one(rng.rangeInt(c30_c37020,c30_c37024));
				dy->add_factor_one(f468[clean - 1][current]);
			}
		}
		opG1_fillStats(f4[cols],amount->mutable_stats());
		for (unsigned int current = arr; current < f298.size(); current++)
		{
			if (f2a8[current] != clean)
			{
				arr = current;
				break;
			}
			amount->mutable_stats()->mutable_kills()->add_list_of_uniques_npcs_destroyed(f298[current]);
		}
	}
	if (isDump ? c37_d28ded : c37_d28dec)
	{
		string cols = (isDump ? c37_cfd42c + "dumps" : c37_cfd42c + "scores") + "/" + filename;
		unsigned int clean = cols.rfind('.');
		cols.erase(cols.begin() + clean,cols.end());
		cols += ".json";
		ofstream current(cols.c_str(),ios::out | ios::trunc);
		if (current.is_open())
		{
			string distanceSq;
			c37_toJson_4326e0(sheet,distanceSq);
			current << distanceSq;
			current.close();
		}
	}
}
