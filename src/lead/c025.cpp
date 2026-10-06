#include "../web/scoresheet.pb.h"

void c025_refs(Protobuf::Stats_Player2* a, Protobuf::Stats_Polymind* b, Protobuf::Stats* c)
{
	a->mutable_slots_evolved();
	a->mutable_damage_taken();
	a->mutable_damage_inflicted();
	a->mutable_combat_hostiles_destroyed();
	b->mutable_hosts();
	b->mutable_average_suspicion();
	b->mutable_protomatter_created();
	c->mutable_build();
	c->mutable_resources();
	c->mutable_kills();
	c->mutable_combat();
	c->mutable_alert();
	c->mutable_stealth();
	c->mutable_traps();
	c->mutable_machines();
	c->mutable_hacking();
	c->mutable_bothacking();
	c->mutable_allies();
	c->mutable_intel();
	c->mutable_exploration();
	c->mutable_actions();
	c->mutable_rpglike();
	c->mutable_player2();
	c->mutable_polymind();
}
