// Scorekeeper: copies one stat set into the scoresheet protobuf (Stats message), 0x7a0e80.
//	Called twice from Scorekeeper::createProtobuf (0x480100): for the run totals (statSets[0]) and
//	for each map of the route (statSets[i] -> Route_Entry::stats). Straight-line code: one
//	set_<field>(stats->get(<stat ID>)) per scoresheet field, 1013 of them.
// NOTE: generated from the exe disassembly (native/giants/tools/lift_7a0e80.py); stat IDs are kept numeric
//	(the stat enum is not recovered yet).
// The protobuf message classes are declared here (accessors only, no bodies): the generated header's inline
//	accessors would be emitted in this TU and collide with the non-inline definitions in src/game/cc_r*.cpp.
namespace google
{
namespace protobuf
{
typedef int int32;
}
}

namespace Protobuf
{

class Stats;
class Stats_Build;
class Stats_Build_PartsAttached;
class Stats_Resources;
class Stats_Kills;
class Stats_Combat;
class Stats_Combat_HostileShotsFired;
class Stats_Combat_ShotsFired;
class Stats_Combat_ShotsHitRobots;
class Stats_Combat_MeleeAttacks;
class Stats_Combat_HighestCorruption;
class Stats_Combat_OverloadShots;
class Stats_Combat_HighestTemperature;
class Stats_Alert;
class Stats_Stealth;
class Stats_Traps;
class Stats_Machines;
class Stats_Hacking;
class Stats_Hacking_TotalHacks;
class Stats_Hacking_UnauthorizedHacks;
class Stats_Hacking_HackingDetections;
class Stats_Hacking_RobotSchematicsAcquired;
class Stats_Hacking_PartSchematicsAcquired;
class Stats_Bothacking;
class Stats_Allies;
class Stats_Intel;
class Stats_Exploration;
class Stats_Exploration_ExplorationRatePercent;
class Stats_Actions;
class Stats_Rpglike;
class Stats_Rpglike_ProtomatterCreated;
class Stats_Player2;
class Stats_Player2_DamageTaken;
class Stats_Polymind;
class Stats_Build_SlotsEvolved;
class Stats_Build_PartsAttached_Power;
class Stats_Build_PartsAttached_Propulsion;
class Stats_Build_PartsAttached_Utility;
class Stats_Build_PartsAttached_Weapon;
class Stats_Build_PartsAttached_CorruptedParts;
class Stats_Build_PartsLost;
class Stats_Build_AverageSpares;
class Stats_Build_UnusedSpares;
class Stats_Build_AverageSlotUsagePercent;
class Stats_Build_PeakBuildRating;
class Stats_Build_HeaviestBuild;
class Stats_Build_LargestInventoryCapacity;
class Stats_Build_ScrapEngineConsumption;
class Stats_Build_ScrapSuitUsage;
class Stats_Build_TransmogrifiedParts;
class Stats_Resources_MatterCollected;
class Stats_Resources_SalvageCreated;
class Stats_Resources_PartsFieldRecycled;
class Stats_Resources_PartsSelfDestructed;
class Stats_Resources_PartsRestored;
class Stats_Kills_CombatHostilesDestroyed;
class Stats_Kills_ClassesDestroyed;
class Stats_Kills_BestKillStreak;
class Stats_Kills_MaxKillsInSingleTurn;
class Stats_Combat_HostileShotsFired_Hits;
class Stats_Combat_HostileShotsFired_CriticalStrikes;
class Stats_Combat_HostileShotsFired_PartDisruptions;
class Stats_Combat_DamageTaken;
class Stats_Combat_VolleysFired;
class Stats_Combat_ShotsFired_SecondaryTargets;
class Stats_Combat_ShotsHitRobots_CriticalStrikes;
class Stats_Combat_MeleeAttacks_SneakAttacks;
class Stats_Combat_DamageInflicted;
class Stats_Combat_HighestCorruption_Effects;
class Stats_Combat_OverloadShots_Effects;
class Stats_Combat_OverflowDamage;
class Stats_Combat_Knockbacks;
class Stats_Combat_SelfInflictedDamage;
class Stats_Combat_TargetsRammed;
class Stats_Combat_HighestTemperature_Effects;
class Stats_Combat_SiegeActivations;
class Stats_Combat_MartialActivations;
class Stats_Combat_ShieldingActivations;
class Stats_Combat_RobotsDisrupted;
class Stats_Combat_RobotsCorrupted;
class Stats_Combat_RobotsMelted;
class Stats_Combat_LatentEnergyUsed;
class Stats_Alert_MaximumAlertLevel;
class Stats_Alert_PeakInfluence;
class Stats_Alert_InfluenceIncreases;
class Stats_Alert_InfluenceDecreases;
class Stats_Alert_SquadsDispatched;
class Stats_Stealth_CommunicationsJammed;
class Stats_Stealth_TimesSpotted;
class Stats_Stealth_IdMasksUsed;
class Stats_Traps_TrapsTriggered;
class Stats_Traps_TrapHackAttempts;
class Stats_Traps_TrapsExtracted;
class Stats_Traps_ObjectsRigged;
class Stats_Traps_TimeBombsActivated;
class Stats_Machines_MachinesDisabled;
class Stats_Hacking_MachinesAccessed;
class Stats_Hacking_TotalHacks_Failed;
class Stats_Hacking_TerminalHacks;
class Stats_Hacking_FabricatorHacks;
class Stats_Hacking_RepairStationHacks;
class Stats_Hacking_RecyclingUnitHacks;
class Stats_Hacking_Scanalyzer;
class Stats_Hacking_GarrisonAccessHacks;
class Stats_Hacking_UnauthorizedHacks_Terminals;
class Stats_Hacking_UnauthorizedHacks_Fabricators;
class Stats_Hacking_UnauthorizedHacks_RepairStations;
class Stats_Hacking_UnauthorizedHacks_RecyclingUnits;
class Stats_Hacking_UnauthorizedHacks_Scanalyzers;
class Stats_Hacking_UnauthorizedHacks_GarrisonAccess;
class Stats_Hacking_DataCoresRecovered;
class Stats_Hacking_HackingDetections_FeedbackEvents;
class Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt;
class Stats_Hacking_PartSchematicsAcquired_PartsBuilt;
class Stats_Hacking_PartsRepaired;
class Stats_Hacking_PartsRecycled;
class Stats_Hacking_PartsScanalyzed;
class Stats_Bothacking_UsedRifInstaller;
class Stats_Bothacking_RobotsHacked;
class Stats_Bothacking_RobotHacksApplied;
class Stats_Bothacking_RelayCouplersReleased;
class Stats_Bothacking_FabnetPeakEffectivePercent;
class Stats_Allies_TotalAllies;
class Stats_Allies_ZioniteDispatches;
class Stats_Allies_WarlordSquadRendezvous;
class Stats_Allies_TotalOrders;
class Stats_Allies_AllyAttacks;
class Stats_Allies_BorgCreated;
class Stats_Allies_XomAmusementGains;
class Stats_Intel_ActiveInfowar;
class Stats_Intel_DroneLaunches;
class Stats_Intel_Decoded0b10Intel;
class Stats_Intel_ZioniteIntelReceived;
class Stats_Exploration_SpacesMoved;
class Stats_Exploration_ExplorationRatePercent_RegionsVisited;
class Stats_Exploration_TerrainDestroyed;
class Stats_Exploration_TerrainRammed;
class Stats_Actions_Total;
class Stats_Rpglike_LevelsRaised;
class Stats_Rpglike_Upgrades;
class Stats_Rpglike_ProtomatterCreated_IntegrityRestored;
class Stats_Player2_SlotsEvolved;
class Stats_Player2_DamageTaken_CoreDamage;
class Stats_Player2_DamageInflicted;
class Stats_Player2_CombatHostilesDestroyed;
class Stats_Polymind_Hosts;
class Stats_Polymind_AverageSuspicion;
class Stats_Polymind_ProtomatterCreated;

class Stats
{
public:
	Stats_Build *mutable_build();
	Stats_Resources *mutable_resources();
	Stats_Kills *mutable_kills();
	Stats_Combat *mutable_combat();
	Stats_Alert *mutable_alert();
	Stats_Stealth *mutable_stealth();
	Stats_Traps *mutable_traps();
	Stats_Machines *mutable_machines();
	Stats_Hacking *mutable_hacking();
	Stats_Bothacking *mutable_bothacking();
	Stats_Allies *mutable_allies();
	Stats_Intel *mutable_intel();
	Stats_Exploration *mutable_exploration();
	Stats_Actions *mutable_actions();
	Stats_Rpglike *mutable_rpglike();
	Stats_Player2 *mutable_player2();
	Stats_Polymind *mutable_polymind();
};

class Stats_Build
{
public:
	Stats_Build_SlotsEvolved *mutable_slots_evolved();
	Stats_Build_PartsAttached *mutable_parts_attached();
	Stats_Build_PartsLost *mutable_parts_lost();
	Stats_Build_AverageSpares *mutable_average_spares();
	Stats_Build_UnusedSpares *mutable_unused_spares();
	Stats_Build_AverageSlotUsagePercent *mutable_average_slot_usage_percent();
	Stats_Build_PeakBuildRating *mutable_peak_build_rating();
	Stats_Build_HeaviestBuild *mutable_heaviest_build();
	Stats_Build_LargestInventoryCapacity *mutable_largest_inventory_capacity();
	Stats_Build_ScrapEngineConsumption *mutable_scrap_engine_consumption();
	Stats_Build_ScrapSuitUsage *mutable_scrap_suit_usage();
	Stats_Build_TransmogrifiedParts *mutable_transmogrified_parts();
	void set_avg_prop_armor_coverage(::google::protobuf::int32 value);
	void set_naked_turns(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached
{
public:
	Stats_Build_PartsAttached_Power *mutable_power();
	Stats_Build_PartsAttached_Propulsion *mutable_propulsion();
	Stats_Build_PartsAttached_Utility *mutable_utility();
	Stats_Build_PartsAttached_Weapon *mutable_weapon();
	Stats_Build_PartsAttached_CorruptedParts *mutable_corrupted_parts();
	void set_overall(::google::protobuf::int32 value);
	void set_unidentified_prototypes(::google::protobuf::int32 value);
};

class Stats_Resources
{
public:
	Stats_Resources_MatterCollected *mutable_matter_collected();
	Stats_Resources_SalvageCreated *mutable_salvage_created();
	Stats_Resources_PartsFieldRecycled *mutable_parts_field_recycled();
	Stats_Resources_PartsSelfDestructed *mutable_parts_self_destructed();
	Stats_Resources_PartsRestored *mutable_parts_restored();
	void set_haulers_intercepted(::google::protobuf::int32 value);
	void set_recyclers_shooed(::google::protobuf::int32 value);
};

class Stats_Kills
{
public:
	Stats_Kills_CombatHostilesDestroyed *mutable_combat_hostiles_destroyed();
	Stats_Kills_ClassesDestroyed *mutable_classes_destroyed();
	Stats_Kills_BestKillStreak *mutable_best_kill_streak();
	Stats_Kills_MaxKillsInSingleTurn *mutable_max_kills_in_single_turn();
	void set_uniques_npcs_destroyed(::google::protobuf::int32 value);
};

class Stats_Combat
{
public:
	Stats_Combat_HostileShotsFired *mutable_hostile_shots_fired();
	Stats_Combat_DamageTaken *mutable_damage_taken();
	Stats_Combat_VolleysFired *mutable_volleys_fired();
	Stats_Combat_ShotsFired *mutable_shots_fired();
	Stats_Combat_ShotsHitRobots *mutable_shots_hit_robots();
	Stats_Combat_MeleeAttacks *mutable_melee_attacks();
	Stats_Combat_DamageInflicted *mutable_damage_inflicted();
	Stats_Combat_HighestCorruption *mutable_highest_corruption();
	Stats_Combat_OverloadShots *mutable_overload_shots();
	Stats_Combat_OverflowDamage *mutable_overflow_damage();
	Stats_Combat_Knockbacks *mutable_knockbacks();
	Stats_Combat_SelfInflictedDamage *mutable_self_inflicted_damage();
	Stats_Combat_TargetsRammed *mutable_targets_rammed();
	Stats_Combat_HighestTemperature *mutable_highest_temperature();
	Stats_Combat_SiegeActivations *mutable_siege_activations();
	Stats_Combat_MartialActivations *mutable_martial_activations();
	Stats_Combat_ShieldingActivations *mutable_shielding_activations();
	Stats_Combat_RobotsDisrupted *mutable_robots_disrupted();
	Stats_Combat_RobotsCorrupted *mutable_robots_corrupted();
	Stats_Combat_RobotsMelted *mutable_robots_melted();
	Stats_Combat_LatentEnergyUsed *mutable_latent_energy_used();
	void set_core_remaining_percent(::google::protobuf::int32 value);
	void set_parts_sabotaged(::google::protobuf::int32 value);
	void set_parts_stolen(::google::protobuf::int32 value);
	void set_parts_stripped(::google::protobuf::int32 value);
	void set_power_chain_reactions(::google::protobuf::int32 value);
};

class Stats_Combat_HostileShotsFired
{
public:
	Stats_Combat_HostileShotsFired_Hits *mutable_hits();
	Stats_Combat_HostileShotsFired_CriticalStrikes *mutable_critical_strikes();
	Stats_Combat_HostileShotsFired_PartDisruptions *mutable_part_disruptions();
	void set_overall(::google::protobuf::int32 value);
	void set_missed(::google::protobuf::int32 value);
	void set_intercepted(::google::protobuf::int32 value);
	void set_deflected(::google::protobuf::int32 value);
};

class Stats_Combat_ShotsFired
{
public:
	Stats_Combat_ShotsFired_SecondaryTargets *mutable_secondary_targets();
	void set_overall(::google::protobuf::int32 value);
	void set_gun(::google::protobuf::int32 value);
	void set_cannon(::google::protobuf::int32 value);
	void set_launcher(::google::protobuf::int32 value);
	void set_special(::google::protobuf::int32 value);
	void set_kinetic(::google::protobuf::int32 value);
	void set_thermal(::google::protobuf::int32 value);
	void set_explosive(::google::protobuf::int32 value);
	void set_electromagnetic(::google::protobuf::int32 value);
	void set_impact(::google::protobuf::int32 value);
	void set_slashing(::google::protobuf::int32 value);
	void set_piercing(::google::protobuf::int32 value);
	void set_entropic(::google::protobuf::int32 value);
	void set_phasic(::google::protobuf::int32 value);
	void set_robot_hit_streak(::google::protobuf::int32 value);
	void set_robot_miss_streak(::google::protobuf::int32 value);
	void set_penetration_max(::google::protobuf::int32 value);
	void set_capacitor(::google::protobuf::int32 value);
	void set_autonomous(::google::protobuf::int32 value);
};

class Stats_Combat_ShotsHitRobots
{
public:
	Stats_Combat_ShotsHitRobots_CriticalStrikes *mutable_critical_strikes();
	void set_overall(::google::protobuf::int32 value);
	void set_core_hits(::google::protobuf::int32 value);
	void set_critical_kills(::google::protobuf::int32 value);
	void set_critical_parts_destroyed(::google::protobuf::int32 value);
};

class Stats_Combat_MeleeAttacks
{
public:
	Stats_Combat_MeleeAttacks_SneakAttacks *mutable_sneak_attacks();
	void set_overall(::google::protobuf::int32 value);
	void set_kinetic(::google::protobuf::int32 value);
	void set_thermal(::google::protobuf::int32 value);
	void set_explosive(::google::protobuf::int32 value);
	void set_electromagnetic(::google::protobuf::int32 value);
	void set_impact(::google::protobuf::int32 value);
	void set_slashing(::google::protobuf::int32 value);
	void set_piercing(::google::protobuf::int32 value);
	void set_entropic(::google::protobuf::int32 value);
	void set_phasic(::google::protobuf::int32 value);
	void set_follow_up_attacks(::google::protobuf::int32 value);
	void set_martial_strikes(::google::protobuf::int32 value);
};

class Stats_Combat_HighestCorruption
{
public:
	Stats_Combat_HighestCorruption_Effects *mutable_effects();
	void set_overall(::google::protobuf::int32 value);
	void set_average_corruption(::google::protobuf::int32 value);
	void set_corruption_purged(::google::protobuf::int32 value);
	void set_corruption_blocked(::google::protobuf::int32 value);
};

class Stats_Combat_OverloadShots
{
public:
	Stats_Combat_OverloadShots_Effects *mutable_effects();
	void set_overall(::google::protobuf::int32 value);
};

class Stats_Combat_HighestTemperature
{
public:
	Stats_Combat_HighestTemperature_Effects *mutable_effects();
	void set_overall(::google::protobuf::int32 value);
	void set_average_temperature(::google::protobuf::int32 value);
	void set_received_heat_transfer(::google::protobuf::int32 value);
	void set_thermoelectric_energy_gain(::google::protobuf::int32 value);
};

class Stats_Alert
{
public:
	Stats_Alert_MaximumAlertLevel *mutable_maximum_alert_level();
	Stats_Alert_PeakInfluence *mutable_peak_influence();
	Stats_Alert_InfluenceIncreases *mutable_influence_increases();
	Stats_Alert_InfluenceDecreases *mutable_influence_decreases();
	Stats_Alert_SquadsDispatched *mutable_squads_dispatched();
	void set_sterilizations(::google::protobuf::int32 value);
	void set_searches_triggered(::google::protobuf::int32 value);
	void set_unchained_authorized(::google::protobuf::int32 value);
	void set_data_miner_redirects(::google::protobuf::int32 value);
	void set_construction_impeded(::google::protobuf::int32 value);
	void set_haulers_reinforced(::google::protobuf::int32 value);
	void set_cargo_convoy_interrupts(::google::protobuf::int32 value);
	void set_alert_id_control_effect(::google::protobuf::int32 value);
};

class Stats_Stealth
{
public:
	Stats_Stealth_CommunicationsJammed *mutable_communications_jammed();
	Stats_Stealth_TimesSpotted *mutable_times_spotted();
	Stats_Stealth_IdMasksUsed *mutable_id_masks_used();
	void set_distress_signals(::google::protobuf::int32 value);
	void set_ecm_based_alert_blocks(::google::protobuf::int32 value);
};

class Stats_Traps
{
public:
	Stats_Traps_TrapsTriggered *mutable_traps_triggered();
	Stats_Traps_TrapHackAttempts *mutable_trap_hack_attempts();
	Stats_Traps_TrapsExtracted *mutable_traps_extracted();
	Stats_Traps_ObjectsRigged *mutable_objects_rigged();
	Stats_Traps_TimeBombsActivated *mutable_time_bombs_activated();
	void set_traps_reconfigurated(::google::protobuf::int32 value);
	void set_fabricated_traps(::google::protobuf::int32 value);
	void set_most_traps_carried(::google::protobuf::int32 value);
};

class Stats_Machines
{
public:
	Stats_Machines_MachinesDisabled *mutable_machines_disabled();
	void set_machines_repaired(::google::protobuf::int32 value);
	void set_machines_dismantled(::google::protobuf::int32 value);
	void set_machines_sabotaged(::google::protobuf::int32 value);
	void set_overloaded_fab_kills(::google::protobuf::int32 value);
};

class Stats_Hacking
{
public:
	Stats_Hacking_MachinesAccessed *mutable_machines_accessed();
	Stats_Hacking_TotalHacks *mutable_total_hacks();
	Stats_Hacking_TerminalHacks *mutable_terminal_hacks();
	Stats_Hacking_FabricatorHacks *mutable_fabricator_hacks();
	Stats_Hacking_RepairStationHacks *mutable_repair_station_hacks();
	Stats_Hacking_RecyclingUnitHacks *mutable_recycling_unit_hacks();
	Stats_Hacking_Scanalyzer *mutable_scanalyzer();
	Stats_Hacking_GarrisonAccessHacks *mutable_garrison_access_hacks();
	Stats_Hacking_UnauthorizedHacks *mutable_unauthorized_hacks();
	Stats_Hacking_DataCoresRecovered *mutable_data_cores_recovered();
	Stats_Hacking_HackingDetections *mutable_hacking_detections();
	Stats_Hacking_RobotSchematicsAcquired *mutable_robot_schematics_acquired();
	Stats_Hacking_PartSchematicsAcquired *mutable_part_schematics_acquired();
	Stats_Hacking_PartsRepaired *mutable_parts_repaired();
	Stats_Hacking_PartsRecycled *mutable_parts_recycled();
	Stats_Hacking_PartsScanalyzed *mutable_parts_scanalyzed();
	void set_part_studies_acquired(::google::protobuf::int32 value);
};

class Stats_Hacking_TotalHacks
{
public:
	Stats_Hacking_TotalHacks_Failed *mutable_failed();
	void set_overall(::google::protobuf::int32 value);
	void set_successful(::google::protobuf::int32 value);
	void set_database_lockouts(::google::protobuf::int32 value);
	void set_manual(::google::protobuf::int32 value);
	void set_terminals(::google::protobuf::int32 value);
	void set_fabricators(::google::protobuf::int32 value);
	void set_repair_stations(::google::protobuf::int32 value);
	void set_recycling_units(::google::protobuf::int32 value);
	void set_scanalyzers(::google::protobuf::int32 value);
	void set_garrison_access(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks
{
public:
	Stats_Hacking_UnauthorizedHacks_Terminals *mutable_terminals();
	Stats_Hacking_UnauthorizedHacks_Fabricators *mutable_fabricators();
	Stats_Hacking_UnauthorizedHacks_RepairStations *mutable_repair_stations();
	Stats_Hacking_UnauthorizedHacks_RecyclingUnits *mutable_recycling_units();
	Stats_Hacking_UnauthorizedHacks_Scanalyzers *mutable_scanalyzers();
	Stats_Hacking_UnauthorizedHacks_GarrisonAccess *mutable_garrison_access();
	void set_overall(::google::protobuf::int32 value);
};

class Stats_Hacking_HackingDetections
{
public:
	Stats_Hacking_HackingDetections_FeedbackEvents *mutable_feedback_events();
	void set_overall(::google::protobuf::int32 value);
	void set_full_trace_events(::google::protobuf::int32 value);
	void set_feedback_blocked(::google::protobuf::int32 value);
};

class Stats_Hacking_RobotSchematicsAcquired
{
public:
	Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt *mutable_robots_built();
	void set_overall(::google::protobuf::int32 value);
	void set_total_robot_build_rating(::google::protobuf::int32 value);
};

class Stats_Hacking_PartSchematicsAcquired
{
public:
	Stats_Hacking_PartSchematicsAcquired_PartsBuilt *mutable_parts_built();
	void set_overall(::google::protobuf::int32 value);
	void set_total_part_build_rating(::google::protobuf::int32 value);
};

class Stats_Bothacking
{
public:
	Stats_Bothacking_UsedRifInstaller *mutable_used_rif_installer();
	Stats_Bothacking_RobotsHacked *mutable_robots_hacked();
	Stats_Bothacking_RobotHacksApplied *mutable_robot_hacks_applied();
	Stats_Bothacking_RelayCouplersReleased *mutable_relay_couplers_released();
	Stats_Bothacking_FabnetPeakEffectivePercent *mutable_fabnet_peak_effective_percent();
	void set_robots_rewired(::google::protobuf::int32 value);
	void set_allies_hacked(::google::protobuf::int32 value);
	void set_hacks_repelled(::google::protobuf::int32 value);
};

class Stats_Allies
{
public:
	Stats_Allies_TotalAllies *mutable_total_allies();
	Stats_Allies_ZioniteDispatches *mutable_zionite_dispatches();
	Stats_Allies_WarlordSquadRendezvous *mutable_warlord_squad_rendezvous();
	Stats_Allies_TotalOrders *mutable_total_orders();
	Stats_Allies_AllyAttacks *mutable_ally_attacks();
	Stats_Allies_BorgCreated *mutable_borg_created();
	Stats_Allies_XomAmusementGains *mutable_xom_amusement_gains();
	void set_ufd_resources(::google::protobuf::int32 value);
	void set_warlord_eca_mod(::google::protobuf::int32 value);
	void set_allies_corrupted(::google::protobuf::int32 value);
	void set_allies_melted(::google::protobuf::int32 value);
	void set_turrets_deployed(::google::protobuf::int32 value);
	void set_fabricated_assembled(::google::protobuf::int32 value);
	void set_field_lobotomies(::google::protobuf::int32 value);
};

class Stats_Intel
{
public:
	Stats_Intel_ActiveInfowar *mutable_active_infowar();
	Stats_Intel_DroneLaunches *mutable_drone_launches();
	Stats_Intel_Decoded0b10Intel *mutable_decoded_0b10_intel();
	Stats_Intel_ZioniteIntelReceived *mutable_zionite_intel_received();
	void set_robot_analysis_total(::google::protobuf::int32 value);
	void set_derelict_logs_recovered(::google::protobuf::int32 value);
};

class Stats_Exploration
{
public:
	Stats_Exploration_SpacesMoved *mutable_spaces_moved();
	Stats_Exploration_ExplorationRatePercent *mutable_exploration_rate_percent();
	Stats_Exploration_TerrainDestroyed *mutable_terrain_destroyed();
	Stats_Exploration_TerrainRammed *mutable_terrain_rammed();
	void set_turns_passed(::google::protobuf::int32 value);
	void set_scrap_searched(::google::protobuf::int32 value);
	void set_spaces_dug(::google::protobuf::int32 value);
	void set_doors_sealed(::google::protobuf::int32 value);
};

class Stats_Exploration_ExplorationRatePercent
{
public:
	Stats_Exploration_ExplorationRatePercent_RegionsVisited *mutable_regions_visited();
	void set_overall(::google::protobuf::int32 value);
	void set_pre_discovered_areas(::google::protobuf::int32 value);
	void set_known_exits_taken(::google::protobuf::int32 value);
	void set_unknown_exits_taken(::google::protobuf::int32 value);
};

class Stats_Actions
{
public:
	Stats_Actions_Total *mutable_total();
};

class Stats_Rpglike
{
public:
	Stats_Rpglike_LevelsRaised *mutable_levels_raised();
	Stats_Rpglike_Upgrades *mutable_upgrades();
	Stats_Rpglike_ProtomatterCreated *mutable_protomatter_created();
	void set_protomatter_decayed(::google::protobuf::int32 value);
};

class Stats_Rpglike_ProtomatterCreated
{
public:
	Stats_Rpglike_ProtomatterCreated_IntegrityRestored *mutable_integrity_restored();
	void set_overall(::google::protobuf::int32 value);
};

class Stats_Player2
{
public:
	Stats_Player2_SlotsEvolved *mutable_slots_evolved();
	Stats_Player2_DamageTaken *mutable_damage_taken();
	Stats_Player2_DamageInflicted *mutable_damage_inflicted();
	Stats_Player2_CombatHostilesDestroyed *mutable_combat_hostiles_destroyed();
	void set_parts_attached(::google::protobuf::int32 value);
	void set_parts_lost(::google::protobuf::int32 value);
};

class Stats_Player2_DamageTaken
{
public:
	Stats_Player2_DamageTaken_CoreDamage *mutable_core();
	void set_overall(::google::protobuf::int32 value);
	void set_absorbed_by_shields(::google::protobuf::int32 value);
};

class Stats_Polymind
{
public:
	Stats_Polymind_Hosts *mutable_hosts();
	Stats_Polymind_AverageSuspicion *mutable_average_suspicion();
	Stats_Polymind_ProtomatterCreated *mutable_protomatter_created();
	void set_unique_host_classes(::google::protobuf::int32 value);
};

class Stats_Build_SlotsEvolved
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power(::google::protobuf::int32 value);
	void set_propulsion(::google::protobuf::int32 value);
	void set_utility(::google::protobuf::int32 value);
	void set_weapon(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached_Power
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_engine(::google::protobuf::int32 value);
	void set_core(::google::protobuf::int32 value);
	void set_reactor(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached_Propulsion
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_treads(::google::protobuf::int32 value);
	void set_leg(::google::protobuf::int32 value);
	void set_wheel(::google::protobuf::int32 value);
	void set_hover(::google::protobuf::int32 value);
	void set_flight(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached_Utility
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_device(::google::protobuf::int32 value);
	void set_storage(::google::protobuf::int32 value);
	void set_processor(::google::protobuf::int32 value);
	void set_hackware(::google::protobuf::int32 value);
	void set_protection(::google::protobuf::int32 value);
	void set_artifact(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached_Weapon
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_energy_gun(::google::protobuf::int32 value);
	void set_energy_cannon(::google::protobuf::int32 value);
	void set_ballistic_gun(::google::protobuf::int32 value);
	void set_ballistic_cannon(::google::protobuf::int32 value);
	void set_launcher(::google::protobuf::int32 value);
	void set_special_weapon(::google::protobuf::int32 value);
	void set_impact_weapon(::google::protobuf::int32 value);
	void set_slashing_weapon(::google::protobuf::int32 value);
	void set_piercing_weapon(::google::protobuf::int32 value);
	void set_special_melee_weapon(::google::protobuf::int32 value);
};

class Stats_Build_PartsAttached_CorruptedParts
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_system_corruption(::google::protobuf::int32 value);
};

class Stats_Build_PartsLost
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power(::google::protobuf::int32 value);
	void set_propulsion(::google::protobuf::int32 value);
	void set_utility(::google::protobuf::int32 value);
	void set_weapon(::google::protobuf::int32 value);
	void set_highest_loss_streak(::google::protobuf::int32 value);
	void set_to_critical_strikes(::google::protobuf::int32 value);
};

class Stats_Build_AverageSpares
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power(::google::protobuf::int32 value);
	void set_propulsion(::google::protobuf::int32 value);
	void set_utility(::google::protobuf::int32 value);
	void set_weapon(::google::protobuf::int32 value);
	void set_special(::google::protobuf::int32 value);
};

class Stats_Build_UnusedSpares
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power(::google::protobuf::int32 value);
	void set_propulsion(::google::protobuf::int32 value);
	void set_utility(::google::protobuf::int32 value);
	void set_weapon(::google::protobuf::int32 value);
	void set_special(::google::protobuf::int32 value);
};

class Stats_Build_AverageSlotUsagePercent
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_engine(::google::protobuf::int32 value);
	void set_core(::google::protobuf::int32 value);
	void set_reactor(::google::protobuf::int32 value);
	void set_treads(::google::protobuf::int32 value);
	void set_leg(::google::protobuf::int32 value);
	void set_wheel(::google::protobuf::int32 value);
	void set_hover(::google::protobuf::int32 value);
	void set_flight(::google::protobuf::int32 value);
	void set_device(::google::protobuf::int32 value);
	void set_storage(::google::protobuf::int32 value);
	void set_processor(::google::protobuf::int32 value);
	void set_hackware(::google::protobuf::int32 value);
	void set_protection(::google::protobuf::int32 value);
	void set_artifact(::google::protobuf::int32 value);
	void set_energy_gun(::google::protobuf::int32 value);
	void set_energy_cannon(::google::protobuf::int32 value);
	void set_ballistic_gun(::google::protobuf::int32 value);
	void set_ballistic_cannon(::google::protobuf::int32 value);
	void set_launcher(::google::protobuf::int32 value);
	void set_special_weapon(::google::protobuf::int32 value);
	void set_impact_weapon(::google::protobuf::int32 value);
	void set_slashing_weapon(::google::protobuf::int32 value);
	void set_piercing_weapon(::google::protobuf::int32 value);
	void set_special_melee_weapon(::google::protobuf::int32 value);
};

class Stats_Build_PeakBuildRating
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_average_rating(::google::protobuf::int32 value);
	void set_on_entrance(::google::protobuf::int32 value);
};

class Stats_Build_HeaviestBuild
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_greatest_support(::google::protobuf::int32 value);
	void set_greatest_overweight_times(::google::protobuf::int32 value);
	void set_average_overweight_times(::google::protobuf::int32 value);
};

class Stats_Build_LargestInventoryCapacity
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_average_capacity(::google::protobuf::int32 value);
	void set_most_carried(::google::protobuf::int32 value);
	void set_average_carried(::google::protobuf::int32 value);
	void set_final_capacity(::google::protobuf::int32 value);
	void set_final_carried(::google::protobuf::int32 value);
};

class Stats_Build_ScrapEngineConsumption
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_constructs_created(::google::protobuf::int32 value);
	void set_constructs_modified(::google::protobuf::int32 value);
};

class Stats_Build_ScrapSuitUsage
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_parts_cannibalized(::google::protobuf::int32 value);
};

class Stats_Build_TransmogrifiedParts
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_integrity_recovered(::google::protobuf::int32 value);
};

class Stats_Resources_MatterCollected
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_remotely(::google::protobuf::int32 value);
};

class Stats_Resources_SalvageCreated
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_parts(::google::protobuf::int32 value);
};

class Stats_Resources_PartsFieldRecycled
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_retrieved_matter(::google::protobuf::int32 value);
};

class Stats_Resources_PartsSelfDestructed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_prevented(::google::protobuf::int32 value);
};

class Stats_Resources_PartsRestored
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_broken(::google::protobuf::int32 value);
	void set_faulty(::google::protobuf::int32 value);
};

class Stats_Kills_CombatHostilesDestroyed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
	void set_guns(::google::protobuf::int32 value);
	void set_cannons(::google::protobuf::int32 value);
	void set_aoe(::google::protobuf::int32 value);
};

class Stats_Kills_ClassesDestroyed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_worker(::google::protobuf::int32 value);
	void set_builder(::google::protobuf::int32 value);
	void set_tunneler(::google::protobuf::int32 value);
	void set_hauler(::google::protobuf::int32 value);
	void set_recycler(::google::protobuf::int32 value);
	void set_carrier(::google::protobuf::int32 value);
	void set_minesweeper(::google::protobuf::int32 value);
	void set_mechanic(::google::protobuf::int32 value);
	void set_operator_(::google::protobuf::int32 value);
	void set_drone(::google::protobuf::int32 value);
	void set_turret(::google::protobuf::int32 value);
	void set_watcher(::google::protobuf::int32 value);
	void set_swarmer(::google::protobuf::int32 value);
	void set_cutter(::google::protobuf::int32 value);
	void set_saboteur(::google::protobuf::int32 value);
	void set_grunt(::google::protobuf::int32 value);
	void set_brawler(::google::protobuf::int32 value);
	void set_duelist(::google::protobuf::int32 value);
	void set_protector(::google::protobuf::int32 value);
	void set_researcher(::google::protobuf::int32 value);
	void set_sentry(::google::protobuf::int32 value);
	void set_demolisher(::google::protobuf::int32 value);
	void set_specialist(::google::protobuf::int32 value);
	void set_hunter(::google::protobuf::int32 value);
	void set_programmer(::google::protobuf::int32 value);
	void set_heavy(::google::protobuf::int32 value);
	void set_q_series(::google::protobuf::int32 value);
	void set_behemoth(::google::protobuf::int32 value);
	void set_compactor(::google::protobuf::int32 value);
	void set_armor_guard(::google::protobuf::int32 value);
	void set_cetus_guard(::google::protobuf::int32 value);
	void set_quarantine_guard(::google::protobuf::int32 value);
	void set_s7_guard(::google::protobuf::int32 value);
	void set_m_guard(::google::protobuf::int32 value);
	void set_m_shell_atk(::google::protobuf::int32 value);
	void set_m_shell_def(::google::protobuf::int32 value);
	void set_enhanced_grunt(::google::protobuf::int32 value);
	void set_enhanced_sentry(::google::protobuf::int32 value);
	void set_enhanced_demolisher(::google::protobuf::int32 value);
	void set_enhanced_hunter(::google::protobuf::int32 value);
	void set_enhanced_programmer(::google::protobuf::int32 value);
	void set_enhanced_qseries(::google::protobuf::int32 value);
	void set_lightning(::google::protobuf::int32 value);
	void set_clone_special(::google::protobuf::int32 value);
	void set_hotshot(::google::protobuf::int32 value);
	void set_decapitator(::google::protobuf::int32 value);
	void set_immortal(::google::protobuf::int32 value);
	void set_overlord(::google::protobuf::int32 value);
	void set_tracker(::google::protobuf::int32 value);
	void set_combat_programmer(::google::protobuf::int32 value);
	void set_investigator(::google::protobuf::int32 value);
	void set_striker(::google::protobuf::int32 value);
	void set_executioner(::google::protobuf::int32 value);
	void set_superbehemoth(::google::protobuf::int32 value);
	void set_alpha_7(::google::protobuf::int32 value);
	void set_fortress(::google::protobuf::int32 value);
	void set_vseries(::google::protobuf::int32 value);
	void set_protovariant_g(::google::protobuf::int32 value);
	void set_protovariant_l(::google::protobuf::int32 value);
	void set_protovariant_y(::google::protobuf::int32 value);
	void set_protovariant_d(::google::protobuf::int32 value);
	void set_protovariant_x(::google::protobuf::int32 value);
	void set_protovariant_h(::google::protobuf::int32 value);
	void set_protovariant_p(::google::protobuf::int32 value);
	void set_artisan(::google::protobuf::int32 value);
	void set_cobbler(::google::protobuf::int32 value);
	void set_subdweller(::google::protobuf::int32 value);
	void set_bolteater(::google::protobuf::int32 value);
	void set_federalist(::google::protobuf::int32 value);
	void set_explorer(::google::protobuf::int32 value);
	void set_ranger(::google::protobuf::int32 value);
	void set_guru(::google::protobuf::int32 value);
	void set_scientist(::google::protobuf::int32 value);
	void set_scrapper(::google::protobuf::int32 value);
	void set_elite(::google::protobuf::int32 value);
	void set_scrapoid(::google::protobuf::int32 value);
	void set_scraphulk(::google::protobuf::int32 value);
	void set_botcube(::google::protobuf::int32 value);
	void set_zionite(::google::protobuf::int32 value);
	void set_z_technician(::google::protobuf::int32 value);
	void set_z_courier(::google::protobuf::int32 value);
	void set_z_light(::google::protobuf::int32 value);
	void set_z_heavy(::google::protobuf::int32 value);
	void set_z_ex(::google::protobuf::int32 value);
	void set_decomposer(::google::protobuf::int32 value);
	void set_packrat(::google::protobuf::int32 value);
	void set_samaritan(::google::protobuf::int32 value);
	void set_tinkerer(::google::protobuf::int32 value);
	void set_demented(::google::protobuf::int32 value);
	void set_furnace(::google::protobuf::int32 value);
	void set_parasite(::google::protobuf::int32 value);
	void set_thief(::google::protobuf::int32 value);
	void set_master_thief(::google::protobuf::int32 value);
	void set_assembler(::google::protobuf::int32 value);
	void set_assembled(::google::protobuf::int32 value);
	void set_golem(::google::protobuf::int32 value);
	void set_surgeon(::google::protobuf::int32 value);
	void set_wasp(::google::protobuf::int32 value);
	void set_thug(::google::protobuf::int32 value);
	void set_savage(::google::protobuf::int32 value);
	void set_butcher(::google::protobuf::int32 value);
	void set_bouncer(::google::protobuf::int32 value);
	void set_martyr(::google::protobuf::int32 value);
	void set_guerrilla(::google::protobuf::int32 value);
	void set_wizard(::google::protobuf::int32 value);
	void set_marauder(::google::protobuf::int32 value);
	void set_fireman(::google::protobuf::int32 value);
	void set_mutant(::google::protobuf::int32 value);
	void set_infiltrator(::google::protobuf::int32 value);
	void set_sapper(::google::protobuf::int32 value);
	void set_commander(::google::protobuf::int32 value);
	void set_knight(::google::protobuf::int32 value);
	void set_troll(::google::protobuf::int32 value);
	void set_dragon(::google::protobuf::int32 value);
	void set_hydra(::google::protobuf::int32 value);
	void set_borebot(::google::protobuf::int32 value);
	void set_unchained(::google::protobuf::int32 value);
	void set_revision(::google::protobuf::int32 value);
	void set_abomination(::google::protobuf::int32 value);
	void set_anomaly(::google::protobuf::int32 value);
	void set_player(::google::protobuf::int32 value);
};

class Stats_Kills_BestKillStreak
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_bots_only(::google::protobuf::int32 value);
};

class Stats_Kills_MaxKillsInSingleTurn
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_gunslinging(::google::protobuf::int32 value);
	void set_exploded(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
};

class Stats_Combat_HostileShotsFired_Hits
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
	void set_projectile(::google::protobuf::int32 value);
	void set_aoe(::google::protobuf::int32 value);
};

class Stats_Combat_HostileShotsFired_CriticalStrikes
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_actively_blocked(::google::protobuf::int32 value);
};

class Stats_Combat_HostileShotsFired_PartDisruptions
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_actively_blocked(::google::protobuf::int32 value);
};

class Stats_Combat_DamageTaken
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_core(::google::protobuf::int32 value);
	void set_absorbed_by_shields(::google::protobuf::int32 value);
	void set_reduced_by_siege_mode(::google::protobuf::int32 value);
	void set_redirected_to_core(::google::protobuf::int32 value);
	void set_redirected_to_shielding(::google::protobuf::int32 value);
	void set_ignored_by_resistances(::google::protobuf::int32 value);
	void set_regen_repair_parts(::google::protobuf::int32 value);
};

class Stats_Combat_VolleysFired
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_largest(::google::protobuf::int32 value);
	void set_hottest(::google::protobuf::int32 value);
};

class Stats_Combat_ShotsFired_SecondaryTargets
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_max_gunslinging_chain(::google::protobuf::int32 value);
};

class Stats_Combat_ShotsHitRobots_CriticalStrikes
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_burn(::google::protobuf::int32 value);
	void set_meltdown(::google::protobuf::int32 value);
	void set_destroy(::google::protobuf::int32 value);
	void set_blast(::google::protobuf::int32 value);
	void set_corrupt(::google::protobuf::int32 value);
	void set_smash(::google::protobuf::int32 value);
	void set_sever(::google::protobuf::int32 value);
	void set_impale(::google::protobuf::int32 value);
	void set_detonate(::google::protobuf::int32 value);
	void set_sunder(::google::protobuf::int32 value);
	void set_intensify(::google::protobuf::int32 value);
	void set_phase(::google::protobuf::int32 value);
};

class Stats_Combat_MeleeAttacks_SneakAttacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_hostiles(::google::protobuf::int32 value);
};

class Stats_Combat_DamageInflicted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_guns(::google::protobuf::int32 value);
	void set_cannons(::google::protobuf::int32 value);
	void set_explosions(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
	void set_ramming(::google::protobuf::int32 value);
	void set_kinetic(::google::protobuf::int32 value);
	void set_thermal(::google::protobuf::int32 value);
	void set_explosive(::google::protobuf::int32 value);
	void set_electromagnetic(::google::protobuf::int32 value);
	void set_impact(::google::protobuf::int32 value);
	void set_slashing(::google::protobuf::int32 value);
	void set_piercing(::google::protobuf::int32 value);
	void set_entropic(::google::protobuf::int32 value);
	void set_phasic(::google::protobuf::int32 value);
};

class Stats_Combat_HighestCorruption_Effects
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_message_errors(::google::protobuf::int32 value);
	void set_matter_fused(::google::protobuf::int32 value);
	void set_heat_flow_errors(::google::protobuf::int32 value);
	void set_energy_discharges(::google::protobuf::int32 value);
	void set_parts_rejected(::google::protobuf::int32 value);
	void set_parts_fused(::google::protobuf::int32 value);
	void set_data_loss_minor_(::google::protobuf::int32 value);
	void set_data_loss_major_(::google::protobuf::int32 value);
	void set_misfires(::google::protobuf::int32 value);
	void set_alerts(::google::protobuf::int32 value);
	void set_misdirections(::google::protobuf::int32 value);
	void set_targeting_errors(::google::protobuf::int32 value);
	void set_weapon_failures(::google::protobuf::int32 value);
};

class Stats_Combat_OverloadShots_Effects
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_energy_bleed(::google::protobuf::int32 value);
	void set_heat_surge(::google::protobuf::int32 value);
	void set_short_circuit(::google::protobuf::int32 value);
	void set_meltdown(::google::protobuf::int32 value);
};

class Stats_Combat_OverflowDamage
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_projectiles(::google::protobuf::int32 value);
	void set_explosions(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
};

class Stats_Combat_Knockbacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_impact(::google::protobuf::int32 value);
	void set_kinetic(::google::protobuf::int32 value);
	void set_secondary(::google::protobuf::int32 value);
};

class Stats_Combat_SelfInflictedDamage
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_shots(::google::protobuf::int32 value);
	void set_rammed(::google::protobuf::int32 value);
};

class Stats_Combat_TargetsRammed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_kicked(::google::protobuf::int32 value);
	void set_crushed(::google::protobuf::int32 value);
};

class Stats_Combat_HighestTemperature_Effects
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_shutdowns(::google::protobuf::int32 value);
	void set_energy_bleed(::google::protobuf::int32 value);
	void set_interference(::google::protobuf::int32 value);
	void set_matter_decay(::google::protobuf::int32 value);
	void set_short_circuit(::google::protobuf::int32 value);
	void set_damage_minor_(::google::protobuf::int32 value);
	void set_damage_major_(::google::protobuf::int32 value);
	void set_damage_core_(::google::protobuf::int32 value);
};

class Stats_Combat_SiegeActivations
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_total_turns(::google::protobuf::int32 value);
	void set_longest_duration(::google::protobuf::int32 value);
};

class Stats_Combat_MartialActivations
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_total_turns(::google::protobuf::int32 value);
	void set_longest_duration(::google::protobuf::int32 value);
};

class Stats_Combat_ShieldingActivations
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_total_turns(::google::protobuf::int32 value);
	void set_longest_duration(::google::protobuf::int32 value);
};

class Stats_Combat_RobotsDisrupted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_hostiles(::google::protobuf::int32 value);
};

class Stats_Combat_RobotsCorrupted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_hostiles(::google::protobuf::int32 value);
	void set_parts_fried(::google::protobuf::int32 value);
	void set_impact_corruptions(::google::protobuf::int32 value);
};

class Stats_Combat_RobotsMelted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_hostiles(::google::protobuf::int32 value);
	void set_parts_melted(::google::protobuf::int32 value);
	void set_heat_transferred(::google::protobuf::int32 value);
};

class Stats_Combat_LatentEnergyUsed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_le_corruption(::google::protobuf::int32 value);
};

class Stats_Alert_MaximumAlertLevel
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_low_security_percent(::google::protobuf::int32 value);
	void set_level_1(::google::protobuf::int32 value);
	void set_level_2(::google::protobuf::int32 value);
	void set_level_3(::google::protobuf::int32 value);
	void set_level_4(::google::protobuf::int32 value);
	void set_level_5(::google::protobuf::int32 value);
	void set_high_security(::google::protobuf::int32 value);
	void set_max_security(::google::protobuf::int32 value);
};

class Stats_Alert_PeakInfluence
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_initial_influence(::google::protobuf::int32 value);
	void set_average_influence(::google::protobuf::int32 value);
};

class Stats_Alert_InfluenceIncreases
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_destroy_0b10_robot_c(::google::protobuf::int32 value);
	void set_destroy_0b10_robot_nc(::google::protobuf::int32 value);
	void set_destroy_leader(::google::protobuf::int32 value);
	void set_allied_during_kill(::google::protobuf::int32 value);
	void set_trap_triggered_on_0b10(::google::protobuf::int32 value);
	void set_successful_hack(::google::protobuf::int32 value);
	void set_select_force_hacks(::google::protobuf::int32 value);
	void set_disable_machine(::google::protobuf::int32 value);
	void set_anti_garrison_action(::google::protobuf::int32 value);
	void set_destroy_structure(::google::protobuf::int32 value);
	void set_advance_influence(::google::protobuf::int32 value);
	void set_partial_spotted(::google::protobuf::int32 value);
	void set_lose_combat_pursuer(::google::protobuf::int32 value);
	void set_active_sensor_use(::google::protobuf::int32 value);
	void set_miscellaneous(::google::protobuf::int32 value);
};

class Stats_Alert_InfluenceDecreases
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_entered_new_map(::google::protobuf::int32 value);
	void set_time_decay(::google::protobuf::int32 value);
	void set_search_patrol_dispatched(::google::protobuf::int32 value);
	void set_lost_part(::google::protobuf::int32 value);
	void set_lost_ally(::google::protobuf::int32 value);
	void set_purge_threat(::google::protobuf::int32 value);
	void set_miscellaneous(::google::protobuf::int32 value);
};

class Stats_Alert_SquadsDispatched
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_investigation(::google::protobuf::int32 value);
	void set_extermination(::google::protobuf::int32 value);
	void set_reinforcement(::google::protobuf::int32 value);
	void set_assault(::google::protobuf::int32 value);
	void set_garrison(::google::protobuf::int32 value);
	void set_intercept(::google::protobuf::int32 value);
};

class Stats_Stealth_CommunicationsJammed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_distress_signals(::google::protobuf::int32 value);
};

class Stats_Stealth_TimesSpotted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_peak_tracking_total(::google::protobuf::int32 value);
	void set_tactical_retreats(::google::protobuf::int32 value);
};

class Stats_Stealth_IdMasksUsed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_iff_responses(::google::protobuf::int32 value);
};

class Stats_Traps_TrapsTriggered
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_indirectly(::google::protobuf::int32 value);
};

class Stats_Traps_TrapHackAttempts
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_triggered(::google::protobuf::int32 value);
	void set_disarmed(::google::protobuf::int32 value);
	void set_reprogrammed(::google::protobuf::int32 value);
	void set_reused(::google::protobuf::int32 value);
};

class Stats_Traps_TrapsExtracted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_installed(::google::protobuf::int32 value);
	void set_triggered(::google::protobuf::int32 value);
};

class Stats_Traps_ObjectsRigged
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_exploded(::google::protobuf::int32 value);
};

class Stats_Traps_TimeBombsActivated
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_exploded(::google::protobuf::int32 value);
};

class Stats_Machines_MachinesDisabled
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_max_in_single_turn(::google::protobuf::int32 value);
	void set_garrison_access(::google::protobuf::int32 value);
	void set_garrison_relay(::google::protobuf::int32 value);
	void set_phase_generator(::google::protobuf::int32 value);
	void set_network_hub(::google::protobuf::int32 value);
	void set_energy_cycler(::google::protobuf::int32 value);
};

class Stats_Hacking_MachinesAccessed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_terminals(::google::protobuf::int32 value);
	void set_fabricators(::google::protobuf::int32 value);
	void set_repair_stations(::google::protobuf::int32 value);
	void set_recycling_units(::google::protobuf::int32 value);
	void set_scanalyzers(::google::protobuf::int32 value);
	void set_garrison_access(::google::protobuf::int32 value);
};

class Stats_Hacking_TotalHacks_Failed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_catastrophic(::google::protobuf::int32 value);
};

class Stats_Hacking_TerminalHacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_record(::google::protobuf::int32 value);
	void set_part_schematic(::google::protobuf::int32 value);
	void set_robot_schematic(::google::protobuf::int32 value);
	void set_robot_analysis(::google::protobuf::int32 value);
	void set_prototype_id_bank(::google::protobuf::int32 value);
	void set_open_door(::google::protobuf::int32 value);
	void set_open_dsf(::google::protobuf::int32 value);
	void set_level_access_points(::google::protobuf::int32 value);
	void set_branch_access_points(::google::protobuf::int32 value);
	void set_emergency_access_points(::google::protobuf::int32 value);
	void set_machine_index(::google::protobuf::int32 value);
	void set_terminal_index(::google::protobuf::int32 value);
	void set_fabricator_index(::google::protobuf::int32 value);
	void set_repair_station_index(::google::protobuf::int32 value);
	void set_recycling_unit_index(::google::protobuf::int32 value);
	void set_scanalyzer_index(::google::protobuf::int32 value);
	void set_garrison_index(::google::protobuf::int32 value);
	void set_alert_level(::google::protobuf::int32 value);
	void set_unreport_threat(::google::protobuf::int32 value);
	void set_locate_traps(::google::protobuf::int32 value);
	void set_disarm_traps(::google::protobuf::int32 value);
	void set_reprogram_traps(::google::protobuf::int32 value);
	void set_dispatch_records(::google::protobuf::int32 value);
	void set_maintenance_status(::google::protobuf::int32 value);
	void set_security_status(::google::protobuf::int32 value);
	void set_surveillance_status(::google::protobuf::int32 value);
	void set_patrol_status(::google::protobuf::int32 value);
	void set_transport_status(::google::protobuf::int32 value);
	void set_investigation_status(::google::protobuf::int32 value);
	void set_extermination_status(::google::protobuf::int32 value);
	void set_reinforcement_status(::google::protobuf::int32 value);
	void set_assault_status(::google::protobuf::int32 value);
	void set_garrison_status(::google::protobuf::int32 value);
	void set_intercept_status(::google::protobuf::int32 value);
	void set_coupling_status(::google::protobuf::int32 value);
	void set_recall_investigation(::google::protobuf::int32 value);
	void set_recall_extermination(::google::protobuf::int32 value);
	void set_recall_reinforcements(::google::protobuf::int32 value);
	void set_recall_assault(::google::protobuf::int32 value);
	void set_hauler_manifests(::google::protobuf::int32 value);
	void set_registered_components(::google::protobuf::int32 value);
	void set_registered_prototypes(::google::protobuf::int32 value);
	void set_zone_layout(::google::protobuf::int32 value);
	void set_download_registry(::google::protobuf::int32 value);
	void set_download_navigation(::google::protobuf::int32 value);
	void set_download_security(::google::protobuf::int32 value);
	void set_proto_id_catalog(::google::protobuf::int32 value);
	void set_protovariant_controls(::google::protobuf::int32 value);
	void set_activate_exoskeleton(::google::protobuf::int32 value);
	void set_disengage_seal(::google::protobuf::int32 value);
	void set_release_object(::google::protobuf::int32 value);
	void set_gate_test_138_a(::google::protobuf::int32 value);
	void set_gate_test_138_b(::google::protobuf::int32 value);
	void set_gate_test_138_c(::google::protobuf::int32 value);
	void set_gate_test_138_end(::google::protobuf::int32 value);
};

class Stats_Hacking_FabricatorHacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_network_status(::google::protobuf::int32 value);
	void set_load_schematic(::google::protobuf::int32 value);
	void set_build(::google::protobuf::int32 value);
};

class Stats_Hacking_RepairStationHacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_scan_component(::google::protobuf::int32 value);
	void set_repair(::google::protobuf::int32 value);
	void set_refit(::google::protobuf::int32 value);
};

class Stats_Hacking_RecyclingUnitHacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_recycle_component(::google::protobuf::int32 value);
	void set_process(::google::protobuf::int32 value);
	void set_report_inventory(::google::protobuf::int32 value);
	void set_retrieve_matter(::google::protobuf::int32 value);
	void set_retrieve_components(::google::protobuf::int32 value);
};

class Stats_Hacking_Scanalyzer
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_insert_component(::google::protobuf::int32 value);
	void set_analyze(::google::protobuf::int32 value);
	void set_retrieve_study(::google::protobuf::int32 value);
};

class Stats_Hacking_GarrisonAccessHacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_unlock_access(::google::protobuf::int32 value);
	void set_seal_access(::google::protobuf::int32 value);
	void set_coupler_status(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_Terminals
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_track(::google::protobuf::int32 value);
	void set_assimilate(::google::protobuf::int32 value);
	void set_botnet(::google::protobuf::int32 value);
	void set_detonate(::google::protobuf::int32 value);
	void set_disrupt(::google::protobuf::int32 value);
	void set_operators(::google::protobuf::int32 value);
	void set_skim(::google::protobuf::int32 value);
	void set_sabotage(::google::protobuf::int32 value);
	void set_search(::google::protobuf::int32 value);
	void set_override(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_Fabricators
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_report(::google::protobuf::int32 value);
	void set_prioritize(::google::protobuf::int32 value);
	void set_liberate(::google::protobuf::int32 value);
	void set_fabnet(::google::protobuf::int32 value);
	void set_haulers(::google::protobuf::int32 value);
	void set_overload(::google::protobuf::int32 value);
	void set_download(::google::protobuf::int32 value);
	void set_recompile(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_RepairStations
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_mechanics(::google::protobuf::int32 value);
	void set_patch(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_RecyclingUnits
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_monitor(::google::protobuf::int32 value);
	void set_reject(::google::protobuf::int32 value);
	void set_recyclers(::google::protobuf::int32 value);
	void set_mask(::google::protobuf::int32 value);
	void set_tunnel(::google::protobuf::int32 value);
	void set_fedlink(::google::protobuf::int32 value);
	void set_scrapoids(::google::protobuf::int32 value);
	void set_scraphulk(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_Scanalyzers
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_researchers(::google::protobuf::int32 value);
	void set_extract(::google::protobuf::int32 value);
};

class Stats_Hacking_UnauthorizedHacks_GarrisonAccess
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_broadcast(::google::protobuf::int32 value);
	void set_restock(::google::protobuf::int32 value);
	void set_decoy(::google::protobuf::int32 value);
	void set_redirect(::google::protobuf::int32 value);
	void set_reprogram(::google::protobuf::int32 value);
	void set_intercept(::google::protobuf::int32 value);
	void set_watchers(::google::protobuf::int32 value);
	void set_jam(::google::protobuf::int32 value);
	void set_eject(::google::protobuf::int32 value);
};

class Stats_Hacking_DataCoresRecovered
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_used(::google::protobuf::int32 value);
};

class Stats_Hacking_HackingDetections_FeedbackEvents
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_corruption(::google::protobuf::int32 value);
	void set_hackware_fried(::google::protobuf::int32 value);
};

class Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_authchips(::google::protobuf::int32 value);
	void set_time(::google::protobuf::int32 value);
};

class Stats_Hacking_PartSchematicsAcquired_PartsBuilt
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_authchips(::google::protobuf::int32 value);
	void set_time(::google::protobuf::int32 value);
};

class Stats_Hacking_PartsRepaired
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_time(::google::protobuf::int32 value);
};

class Stats_Hacking_PartsRecycled
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_recycled_matter(::google::protobuf::int32 value);
	void set_retrieved_matter(::google::protobuf::int32 value);
	void set_retrieved_components(::google::protobuf::int32 value);
};

class Stats_Hacking_PartsScanalyzed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_part_schematics_acquired(::google::protobuf::int32 value);
	void set_parts_damaged(::google::protobuf::int32 value);
};

class Stats_Bothacking_UsedRifInstaller
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_coupler_efficiency(::google::protobuf::int32 value);
	void set_hotswap(::google::protobuf::int32 value);
	void set_code_merge(::google::protobuf::int32 value);
	void set_command_fork(::google::protobuf::int32 value);
	void set_threat_obfuscation(::google::protobuf::int32 value);
	void set_signal_jamming(::google::protobuf::int32 value);
	void set_zone_cloak(::google::protobuf::int32 value);
	void set_robot_detection(::google::protobuf::int32 value);
	void set_watcher_feeds(::google::protobuf::int32 value);
	void set_patrol_navigation(::google::protobuf::int32 value);
	void set_alert_id_control(::google::protobuf::int32 value);
	void set_structural_interface(::google::protobuf::int32 value);
	void set_program_shield(::google::protobuf::int32 value);
	void set_autooverride(::google::protobuf::int32 value);
	void set_autoassimilate(::google::protobuf::int32 value);
	void set_crosswire(::google::protobuf::int32 value);
};

class Stats_Bothacking_RobotsHacked
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_non_combat(::google::protobuf::int32 value);
	void set_combat(::google::protobuf::int32 value);
	void set_autooverrided(::google::protobuf::int32 value);
	void set_autoassimilated(::google::protobuf::int32 value);
};

class Stats_Bothacking_RobotHacksApplied
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_parse_system(::google::protobuf::int32 value);
	void set_no_distress(::google::protobuf::int32 value);
	void set_generate_anomaly(::google::protobuf::int32 value);
	void set_generate_echo(::google::protobuf::int32 value);
	void set_start_evac(::google::protobuf::int32 value);
	void set_find_chute(::google::protobuf::int32 value);
	void set_deconstruct_machine(::google::protobuf::int32 value);
	void set_hold_bot(::google::protobuf::int32 value);
	void set_start_disposal(::google::protobuf::int32 value);
	void set_ignore_repairs(::google::protobuf::int32 value);
	void set_map_walls(::google::protobuf::int32 value);
	void set_randomize_corridors(::google::protobuf::int32 value);
	void set_map_earth(::google::protobuf::int32 value);
	void set_find_fabricator(::google::protobuf::int32 value);
	void set_find_dsf(::google::protobuf::int32 value);
	void set_drop_inventory(::google::protobuf::int32 value);
	void set_recall_reinforcements(::google::protobuf::int32 value);
	void set_locate_stockpiles(::google::protobuf::int32 value);
	void set_find_recycling(::google::protobuf::int32 value);
	void set_ignore_parts(::google::protobuf::int32 value);
	void set_find_station(::google::protobuf::int32 value);
	void set_release_backups(::google::protobuf::int32 value);
	void set_deconstruct_bot(::google::protobuf::int32 value);
	void set_check_alert(::google::protobuf::int32 value);
	void set_purge_threat(::google::protobuf::int32 value);
	void set_find_terminals(::google::protobuf::int32 value);
	void set_locate_traps(::google::protobuf::int32 value);
	void set_disarm_traps(::google::protobuf::int32 value);
	void set_reprogram_traps(::google::protobuf::int32 value);
	void set_block_reporting(::google::protobuf::int32 value);
	void set_summon_haulers(::google::protobuf::int32 value);
	void set_recall_investigation(::google::protobuf::int32 value);
	void set_clear_repairs(::google::protobuf::int32 value);
	void set_clear_recycling(::google::protobuf::int32 value);
	void set_map_route(::google::protobuf::int32 value);
	void set_mark_security(::google::protobuf::int32 value);
	void set_relay_feed(::google::protobuf::int32 value);
	void set_disable_shields(::google::protobuf::int32 value);
	void set_redirect_shields(::google::protobuf::int32 value);
	void set_find_scanalyzer(::google::protobuf::int32 value);
	void set_disable_scanner(::google::protobuf::int32 value);
	void set_locate_prototypes(::google::protobuf::int32 value);
	void set_report_prototypes(::google::protobuf::int32 value);
	void set_report_schematics(::google::protobuf::int32 value);
	void set_report_analyses(::google::protobuf::int32 value);
	void set_ignore_targets(::google::protobuf::int32 value);
	void set_emergency_deploy(::google::protobuf::int32 value);
	void set_find_shortcuts(::google::protobuf::int32 value);
	void set_find_garrison(::google::protobuf::int32 value);
	void set_show_paths(::google::protobuf::int32 value);
	void set_link_fov(::google::protobuf::int32 value);
	void set_focus_fire(::google::protobuf::int32 value);
	void set_reboot_propulsion(::google::protobuf::int32 value);
	void set_tweak_propulsion(::google::protobuf::int32 value);
	void set_scatter_targeting(::google::protobuf::int32 value);
	void set_mark_system(::google::protobuf::int32 value);
	void set_link_complan(::google::protobuf::int32 value);
	void set_broadcast_data(::google::protobuf::int32 value);
	void set_disrupt_area(::google::protobuf::int32 value);
	void set_spike_heat(::google::protobuf::int32 value);
	void set_overload_power(::google::protobuf::int32 value);
	void set_amplify_resonance(::google::protobuf::int32 value);
	void set_wipe_record(::google::protobuf::int32 value);
	void set_disable_weapons(::google::protobuf::int32 value);
	void set_reboot_system(::google::protobuf::int32 value);
	void set_go_dormant(::google::protobuf::int32 value);
	void set_overwrite_iff(::google::protobuf::int32 value);
	void set_streamctrl_low(::google::protobuf::int32 value);
	void set_streamctrl_high(::google::protobuf::int32 value);
	void set_formatsys_low(::google::protobuf::int32 value);
	void set_formatsys_high(::google::protobuf::int32 value);
	void set_formatsys_deep(::google::protobuf::int32 value);
	void set_retrieve_part(::google::protobuf::int32 value);
	void set_manual(::google::protobuf::int32 value);
};

class Stats_Bothacking_RelayCouplersReleased
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_ejected(::google::protobuf::int32 value);
	void set_machine_destruction(::google::protobuf::int32 value);
	void set_programmers(::google::protobuf::int32 value);
	void set_attached(::google::protobuf::int32 value);
	void set_crosswired(::google::protobuf::int32 value);
	void set_merged_code_value(::google::protobuf::int32 value);
};

class Stats_Bothacking_FabnetPeakEffectivePercent
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_autooverrided(::google::protobuf::int32 value);
};

class Stats_Allies_TotalAllies
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_largest_group(::google::protobuf::int32 value);
	void set_highest_rated_group(::google::protobuf::int32 value);
	void set_highest_rated_ally(::google::protobuf::int32 value);
};

class Stats_Allies_ZioniteDispatches
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_heavy(::google::protobuf::int32 value);
	void set_light(::google::protobuf::int32 value);
	void set_recon(::google::protobuf::int32 value);
	void set_fire(::google::protobuf::int32 value);
	void set_hacker(::google::protobuf::int32 value);
	void set_demo(::google::protobuf::int32 value);
	void set_experimental(::google::protobuf::int32 value);
	void set_hero(::google::protobuf::int32 value);
	void set_thermal_resupply(::google::protobuf::int32 value);
	void set_kinetic_resupply(::google::protobuf::int32 value);
	void set_explosive_resupply(::google::protobuf::int32 value);
	void set_melee_resupply(::google::protobuf::int32 value);
	void set_trap_resupply(::google::protobuf::int32 value);
	void set_resource_resupply(::google::protobuf::int32 value);
	void set_offense_resupply(::google::protobuf::int32 value);
	void set_defense_resupply(::google::protobuf::int32 value);
	void set_heavy_resupply(::google::protobuf::int32 value);
	void set_infowar_resupply(::google::protobuf::int32 value);
	void set_hacking_resupply(::google::protobuf::int32 value);
	void set_hover_resupply(::google::protobuf::int32 value);
	void set_zionite_resupply(::google::protobuf::int32 value);
};

class Stats_Allies_WarlordSquadRendezvous
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_dakka(::google::protobuf::int32 value);
	void set_infantry(::google::protobuf::int32 value);
	void set_muscle(::google::protobuf::int32 value);
	void set_geek(::google::protobuf::int32 value);
	void set_ranger(::google::protobuf::int32 value);
	void set_pyro(::google::protobuf::int32 value);
	void set_chimera(::google::protobuf::int32 value);
	void set_ghost(::google::protobuf::int32 value);
};

class Stats_Allies_TotalOrders
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_stay(::google::protobuf::int32 value);
	void set_roam(::google::protobuf::int32 value);
	void set_follow(::google::protobuf::int32 value);
	void set_guard(::google::protobuf::int32 value);
	void set_aid(::google::protobuf::int32 value);
	void set_tunnel(::google::protobuf::int32 value);
	void set_drop(::google::protobuf::int32 value);
	void set_pickup(::google::protobuf::int32 value);
	void set_collect(::google::protobuf::int32 value);
	void set_explore(::google::protobuf::int32 value);
	void set_return_(::google::protobuf::int32 value);
};

class Stats_Allies_AllyAttacks
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_total_damage(::google::protobuf::int32 value);
	void set_kills(::google::protobuf::int32 value);
};

class Stats_Allies_BorgCreated
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_largest_collective(::google::protobuf::int32 value);
};

class Stats_Allies_XomAmusementGains
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_average_entertainment(::google::protobuf::int32 value);
	void set_good_acts(::google::protobuf::int32 value);
	void set_bad_acts(::google::protobuf::int32 value);
};

class Stats_Intel_ActiveInfowar
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_optics(::google::protobuf::int32 value);
	void set_sensors(::google::protobuf::int32 value);
	void set_ass(::google::protobuf::int32 value);
	void set_iff(::google::protobuf::int32 value);
	void set_zeronet(::google::protobuf::int32 value);
	void set_terrain(::google::protobuf::int32 value);
	void set_structural(::google::protobuf::int32 value);
	void set_traps(::google::protobuf::int32 value);
	void set_seismic(::google::protobuf::int32 value);
	void set_decoding(::google::protobuf::int32 value);
	void set_tnc(::google::protobuf::int32 value);
	void set_machine_analysis(::google::protobuf::int32 value);
	void set_triangulation(::google::protobuf::int32 value);
	void set_cloaking(::google::protobuf::int32 value);
	void set_spoofing(::google::protobuf::int32 value);
	void set_jamming(::google::protobuf::int32 value);
	void set_ecm(::google::protobuf::int32 value);
	void set_id_mask(::google::protobuf::int32 value);
};

class Stats_Intel_DroneLaunches
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_drone_recoveries(::google::protobuf::int32 value);
};

class Stats_Intel_Decoded0b10Intel
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_traps(::google::protobuf::int32 value);
	void set_emergency_access(::google::protobuf::int32 value);
	void set_items(::google::protobuf::int32 value);
	void set_machines(::google::protobuf::int32 value);
	void set_garrisons(::google::protobuf::int32 value);
	void set_patrols(::google::protobuf::int32 value);
	void set_investigations(::google::protobuf::int32 value);
	void set_reinforcements(::google::protobuf::int32 value);
	void set_guards(::google::protobuf::int32 value);
	void set_exits(::google::protobuf::int32 value);
};

class Stats_Intel_ZioniteIntelReceived
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_main_access(::google::protobuf::int32 value);
	void set_branch_access(::google::protobuf::int32 value);
	void set_emergency_access(::google::protobuf::int32 value);
	void set_guard_positions(::google::protobuf::int32 value);
	void set_component_stockpiles(::google::protobuf::int32 value);
	void set_prototype_stockpiles(::google::protobuf::int32 value);
	void set_component_schematics(::google::protobuf::int32 value);
	void set_prototype_schematics(::google::protobuf::int32 value);
	void set_unaware_schematics(::google::protobuf::int32 value);
	void set_unaware_analyses(::google::protobuf::int32 value);
	void set_trap_installations(::google::protobuf::int32 value);
	void set_active_terminals(::google::protobuf::int32 value);
	void set_active_garrisons(::google::protobuf::int32 value);
	void set_depthwide_sectors_0(::google::protobuf::int32 value);
	void set_depthwide_sectors_1(::google::protobuf::int32 value);
};

class Stats_Exploration_SpacesMoved
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_core(::google::protobuf::int32 value);
	void set_treads(::google::protobuf::int32 value);
	void set_legs(::google::protobuf::int32 value);
	void set_wheels(::google::protobuf::int32 value);
	void set_hover(::google::protobuf::int32 value);
	void set_flight(::google::protobuf::int32 value);
	void set_fastest_speed(::google::protobuf::int32 value);
	void set_average_speed(::google::protobuf::int32 value);
	void set_slowest_speed(::google::protobuf::int32 value);
	void set_overloaded_moves(::google::protobuf::int32 value);
	void set_propulsion_burnouts(::google::protobuf::int32 value);
	void set_robots_hopped(::google::protobuf::int32 value);
	void set_potential_cave_ins(::google::protobuf::int32 value);
	void set_cave_ins_triggered(::google::protobuf::int32 value);
	void set_teleports(::google::protobuf::int32 value);
	void set_time_travels(::google::protobuf::int32 value);
};

class Stats_Exploration_ExplorationRatePercent_RegionsVisited
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_branch_regions(::google::protobuf::int32 value);
};

class Stats_Exploration_TerrainDestroyed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
	void set_projectile(::google::protobuf::int32 value);
	void set_aoe(::google::protobuf::int32 value);
};

class Stats_Exploration_TerrainRammed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_walls_destroyed(::google::protobuf::int32 value);
	void set_machines_disabled(::google::protobuf::int32 value);
};

class Stats_Actions_Total
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_wait(::google::protobuf::int32 value);
	void set_move(::google::protobuf::int32 value);
	void set_hop(::google::protobuf::int32 value);
	void set_pick_up(::google::protobuf::int32 value);
	void set_fast_attach(::google::protobuf::int32 value);
	void set_attach(::google::protobuf::int32 value);
	void set_detach(::google::protobuf::int32 value);
	void set_swap(::google::protobuf::int32 value);
	void set_drop(::google::protobuf::int32 value);
	void set_fire(::google::protobuf::int32 value);
	void set_melee(::google::protobuf::int32 value);
	void set_ram(::google::protobuf::int32 value);
	void set_kick(::google::protobuf::int32 value);
	void set_crush(::google::protobuf::int32 value);
	void set_escape_stasis(::google::protobuf::int32 value);
	void set_rewire(::google::protobuf::int32 value);
	void set_trap(::google::protobuf::int32 value);
	void set_miscellaneous(::google::protobuf::int32 value);
};

class Stats_Rpglike_LevelsRaised
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_xp_earned(::google::protobuf::int32 value);
	void set_xp_spent(::google::protobuf::int32 value);
};

class Stats_Rpglike_Upgrades
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power_slot(::google::protobuf::int32 value);
	void set_propulsion_slot(::google::protobuf::int32 value);
	void set_utility_slot(::google::protobuf::int32 value);
	void set_weapon_slot(::google::protobuf::int32 value);
	void set_core_integrity(::google::protobuf::int32 value);
	void set_heat_dissipation(::google::protobuf::int32 value);
	void set_energy_generation(::google::protobuf::int32 value);
	void set_energy_storage(::google::protobuf::int32 value);
	void set_matter_storage(::google::protobuf::int32 value);
	void set_mass_support(::google::protobuf::int32 value);
	void set_inventory_capacity(::google::protobuf::int32 value);
	void set_sight_range(::google::protobuf::int32 value);
	void set_sensor_range(::google::protobuf::int32 value);
	void set_terrain_scan_density(::google::protobuf::int32 value);
	void set_ranged_accuracy(::google::protobuf::int32 value);
	void set_melee_accuracy(::google::protobuf::int32 value);
	void set_hack_attack_percent(::google::protobuf::int32 value);
	void set_hack_defense_percent(::google::protobuf::int32 value);
	void set_ki_resistance_percent(::google::protobuf::int32 value);
	void set_th_resistance_percent(::google::protobuf::int32 value);
	void set_ex_resistance_percent(::google::protobuf::int32 value);
	void set_ki_damage_percent(::google::protobuf::int32 value);
	void set_th_damage_percent(::google::protobuf::int32 value);
	void set_ex_damage_percent(::google::protobuf::int32 value);
};

class Stats_Rpglike_ProtomatterCreated_IntegrityRestored
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_core(::google::protobuf::int32 value);
	void set_parts(::google::protobuf::int32 value);
};

class Stats_Player2_SlotsEvolved
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_power(::google::protobuf::int32 value);
	void set_propulsion(::google::protobuf::int32 value);
	void set_utility(::google::protobuf::int32 value);
	void set_weapon(::google::protobuf::int32 value);
};

class Stats_Player2_DamageTaken_CoreDamage
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_player2percentage(::google::protobuf::int32 value);
};

class Stats_Player2_DamageInflicted
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_player2percentage(::google::protobuf::int32 value);
};

class Stats_Player2_CombatHostilesDestroyed
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_player2percentage(::google::protobuf::int32 value);
};

class Stats_Polymind_Hosts
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_combat_hostiles(::google::protobuf::int32 value);
	void set_allies(::google::protobuf::int32 value);
};

class Stats_Polymind_AverageSuspicion
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_unsuspicious_activity(::google::protobuf::int32 value);
	void set_returns_to_shadow(::google::protobuf::int32 value);
	void set_fuzzy_dispatches(::google::protobuf::int32 value);
};

class Stats_Polymind_ProtomatterCreated
{
public:
	void set_overall(::google::protobuf::int32 value);
	void set_used(::google::protobuf::int32 value);
	void set_decayed(::google::protobuf::int32 value);
	void set_highest_spend(::google::protobuf::int32 value);
};

}


class OpR1h_StatSet	// NOTE: placeholder name
{
public:
	int get472440(unsigned int id);	// NOTE: placeholder name (0x472440)
};

class Scorekeeper
{
public:
	void opG1_fillStats(OpR1h_StatSet *stats, Protobuf::Stats *pbStats);	// NOTE: placeholder name (0x7a0e80)
};

void Scorekeeper::opG1_fillStats(OpR1h_StatSet *stats, Protobuf::Stats *pbStats)
{
	pbStats->mutable_build()->mutable_slots_evolved()->set_overall(stats->get472440(107));
	pbStats->mutable_build()->mutable_slots_evolved()->set_power(stats->get472440(108));
	pbStats->mutable_build()->mutable_slots_evolved()->set_propulsion(stats->get472440(109));
	pbStats->mutable_build()->mutable_slots_evolved()->set_utility(stats->get472440(110));
	pbStats->mutable_build()->mutable_slots_evolved()->set_weapon(stats->get472440(111));
	pbStats->mutable_build()->mutable_parts_attached()->set_overall(stats->get472440(112));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_power()->set_overall(stats->get472440(113));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_power()->set_engine(stats->get472440(114));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_power()->set_core(stats->get472440(115));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_power()->set_reactor(stats->get472440(116));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_overall(stats->get472440(117));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_treads(stats->get472440(118));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_leg(stats->get472440(119));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_wheel(stats->get472440(120));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_hover(stats->get472440(121));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_propulsion()->set_flight(stats->get472440(122));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_overall(stats->get472440(123));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_device(stats->get472440(124));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_storage(stats->get472440(125));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_processor(stats->get472440(126));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_hackware(stats->get472440(127));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_protection(stats->get472440(128));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_utility()->set_artifact(stats->get472440(129));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_overall(stats->get472440(130));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_energy_gun(stats->get472440(131));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_energy_cannon(stats->get472440(132));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_ballistic_gun(stats->get472440(133));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_ballistic_cannon(stats->get472440(134));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_launcher(stats->get472440(135));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_special_weapon(stats->get472440(136));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_impact_weapon(stats->get472440(137));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_slashing_weapon(stats->get472440(138));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_piercing_weapon(stats->get472440(139));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_weapon()->set_special_melee_weapon(stats->get472440(140));
	pbStats->mutable_build()->mutable_parts_attached()->set_unidentified_prototypes(stats->get472440(141));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_corrupted_parts()->set_overall(stats->get472440(142));
	pbStats->mutable_build()->mutable_parts_attached()->mutable_corrupted_parts()->set_system_corruption(stats->get472440(143));
	pbStats->mutable_build()->mutable_parts_lost()->set_overall(stats->get472440(144));
	pbStats->mutable_build()->mutable_parts_lost()->set_power(stats->get472440(145));
	pbStats->mutable_build()->mutable_parts_lost()->set_propulsion(stats->get472440(146));
	pbStats->mutable_build()->mutable_parts_lost()->set_utility(stats->get472440(147));
	pbStats->mutable_build()->mutable_parts_lost()->set_weapon(stats->get472440(148));
	pbStats->mutable_build()->mutable_parts_lost()->set_highest_loss_streak(stats->get472440(149));
	pbStats->mutable_build()->mutable_parts_lost()->set_to_critical_strikes(stats->get472440(150));
	pbStats->mutable_build()->mutable_average_spares()->set_overall(stats->get472440(151));
	pbStats->mutable_build()->mutable_average_spares()->set_power(stats->get472440(152));
	pbStats->mutable_build()->mutable_average_spares()->set_propulsion(stats->get472440(153));
	pbStats->mutable_build()->mutable_average_spares()->set_utility(stats->get472440(154));
	pbStats->mutable_build()->mutable_average_spares()->set_weapon(stats->get472440(155));
	pbStats->mutable_build()->mutable_average_spares()->set_special(stats->get472440(156));
	pbStats->mutable_build()->mutable_unused_spares()->set_overall(stats->get472440(157));
	pbStats->mutable_build()->mutable_unused_spares()->set_power(stats->get472440(158));
	pbStats->mutable_build()->mutable_unused_spares()->set_propulsion(stats->get472440(159));
	pbStats->mutable_build()->mutable_unused_spares()->set_utility(stats->get472440(160));
	pbStats->mutable_build()->mutable_unused_spares()->set_weapon(stats->get472440(161));
	pbStats->mutable_build()->mutable_unused_spares()->set_special(stats->get472440(162));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_overall(stats->get472440(163));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_engine(stats->get472440(164));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_core(stats->get472440(165));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_reactor(stats->get472440(166));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_treads(stats->get472440(167));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_leg(stats->get472440(168));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_wheel(stats->get472440(169));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_hover(stats->get472440(170));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_flight(stats->get472440(171));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_device(stats->get472440(172));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_storage(stats->get472440(173));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_processor(stats->get472440(174));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_hackware(stats->get472440(175));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_protection(stats->get472440(176));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_artifact(stats->get472440(177));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_energy_gun(stats->get472440(178));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_energy_cannon(stats->get472440(179));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_ballistic_gun(stats->get472440(180));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_ballistic_cannon(stats->get472440(181));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_launcher(stats->get472440(182));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_special_weapon(stats->get472440(183));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_impact_weapon(stats->get472440(184));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_slashing_weapon(stats->get472440(185));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_piercing_weapon(stats->get472440(186));
	pbStats->mutable_build()->mutable_average_slot_usage_percent()->set_special_melee_weapon(stats->get472440(187));
	pbStats->mutable_build()->mutable_peak_build_rating()->set_overall(stats->get472440(188));
	pbStats->mutable_build()->mutable_peak_build_rating()->set_average_rating(stats->get472440(189));
	pbStats->mutable_build()->mutable_peak_build_rating()->set_on_entrance(stats->get472440(190));
	pbStats->mutable_build()->set_avg_prop_armor_coverage(stats->get472440(191));
	pbStats->mutable_build()->set_naked_turns(stats->get472440(192));
	pbStats->mutable_build()->mutable_heaviest_build()->set_overall(stats->get472440(193));
	pbStats->mutable_build()->mutable_heaviest_build()->set_greatest_support(stats->get472440(194));
	pbStats->mutable_build()->mutable_heaviest_build()->set_greatest_overweight_times(stats->get472440(195));
	pbStats->mutable_build()->mutable_heaviest_build()->set_average_overweight_times(stats->get472440(196));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_overall(stats->get472440(197));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_average_capacity(stats->get472440(198));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_most_carried(stats->get472440(199));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_average_carried(stats->get472440(200));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_final_capacity(stats->get472440(201));
	pbStats->mutable_build()->mutable_largest_inventory_capacity()->set_final_carried(stats->get472440(202));
	pbStats->mutable_build()->mutable_scrap_engine_consumption()->set_overall(stats->get472440(203));
	pbStats->mutable_build()->mutable_scrap_engine_consumption()->set_constructs_created(stats->get472440(204));
	pbStats->mutable_build()->mutable_scrap_engine_consumption()->set_constructs_modified(stats->get472440(205));
	pbStats->mutable_build()->mutable_scrap_suit_usage()->set_overall(stats->get472440(206));
	pbStats->mutable_build()->mutable_scrap_suit_usage()->set_parts_cannibalized(stats->get472440(207));
	pbStats->mutable_build()->mutable_transmogrified_parts()->set_overall(stats->get472440(208));
	pbStats->mutable_build()->mutable_transmogrified_parts()->set_integrity_recovered(stats->get472440(209));
	pbStats->mutable_resources()->mutable_matter_collected()->set_overall(stats->get472440(210));
	pbStats->mutable_resources()->mutable_matter_collected()->set_remotely(stats->get472440(211));
	pbStats->mutable_resources()->mutable_salvage_created()->set_overall(stats->get472440(212));
	pbStats->mutable_resources()->mutable_salvage_created()->set_parts(stats->get472440(213));
	pbStats->mutable_resources()->set_haulers_intercepted(stats->get472440(214));
	pbStats->mutable_resources()->set_recyclers_shooed(stats->get472440(215));
	pbStats->mutable_resources()->mutable_parts_field_recycled()->set_overall(stats->get472440(216));
	pbStats->mutable_resources()->mutable_parts_field_recycled()->set_retrieved_matter(stats->get472440(217));
	pbStats->mutable_resources()->mutable_parts_self_destructed()->set_overall(stats->get472440(218));
	pbStats->mutable_resources()->mutable_parts_self_destructed()->set_prevented(stats->get472440(219));
	pbStats->mutable_resources()->mutable_parts_restored()->set_overall(stats->get472440(220));
	pbStats->mutable_resources()->mutable_parts_restored()->set_broken(stats->get472440(221));
	pbStats->mutable_resources()->mutable_parts_restored()->set_faulty(stats->get472440(222));
	pbStats->mutable_kills()->mutable_combat_hostiles_destroyed()->set_overall(stats->get472440(223));
	pbStats->mutable_kills()->mutable_combat_hostiles_destroyed()->set_melee(stats->get472440(224));
	pbStats->mutable_kills()->mutable_combat_hostiles_destroyed()->set_guns(stats->get472440(225));
	pbStats->mutable_kills()->mutable_combat_hostiles_destroyed()->set_cannons(stats->get472440(226));
	pbStats->mutable_kills()->mutable_combat_hostiles_destroyed()->set_aoe(stats->get472440(227));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_overall(stats->get472440(228));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_worker(stats->get472440(229));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_builder(stats->get472440(230));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_tunneler(stats->get472440(231));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_hauler(stats->get472440(232));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_recycler(stats->get472440(233));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_carrier(stats->get472440(234));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_minesweeper(stats->get472440(235));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_mechanic(stats->get472440(236));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_operator_(stats->get472440(237));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_drone(stats->get472440(238));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_turret(stats->get472440(239));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_watcher(stats->get472440(240));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_swarmer(stats->get472440(241));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_cutter(stats->get472440(242));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_saboteur(stats->get472440(243));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_grunt(stats->get472440(244));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_brawler(stats->get472440(245));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_duelist(stats->get472440(246));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protector(stats->get472440(247));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_researcher(stats->get472440(248));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_sentry(stats->get472440(249));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_demolisher(stats->get472440(250));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_specialist(stats->get472440(251));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_hunter(stats->get472440(252));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_programmer(stats->get472440(253));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_heavy(stats->get472440(254));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_q_series(stats->get472440(255));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_behemoth(stats->get472440(256));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_compactor(stats->get472440(257));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_armor_guard(stats->get472440(258));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_cetus_guard(stats->get472440(259));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_quarantine_guard(stats->get472440(260));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_s7_guard(stats->get472440(261));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_m_guard(stats->get472440(262));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_m_shell_atk(stats->get472440(263));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_m_shell_def(stats->get472440(264));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_grunt(stats->get472440(265));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_sentry(stats->get472440(266));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_demolisher(stats->get472440(267));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_hunter(stats->get472440(268));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_programmer(stats->get472440(269));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_enhanced_qseries(stats->get472440(270));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_lightning(stats->get472440(271));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_clone_special(stats->get472440(272));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_hotshot(stats->get472440(273));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_decapitator(stats->get472440(274));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_immortal(stats->get472440(275));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_overlord(stats->get472440(276));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_tracker(stats->get472440(277));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_combat_programmer(stats->get472440(278));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_investigator(stats->get472440(279));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_striker(stats->get472440(280));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_executioner(stats->get472440(281));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_superbehemoth(stats->get472440(282));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_alpha_7(stats->get472440(283));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_fortress(stats->get472440(284));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_vseries(stats->get472440(285));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_g(stats->get472440(286));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_l(stats->get472440(287));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_y(stats->get472440(288));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_d(stats->get472440(289));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_x(stats->get472440(290));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_h(stats->get472440(291));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_protovariant_p(stats->get472440(292));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_artisan(stats->get472440(293));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_cobbler(stats->get472440(294));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_subdweller(stats->get472440(295));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_bolteater(stats->get472440(296));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_federalist(stats->get472440(297));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_explorer(stats->get472440(298));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_ranger(stats->get472440(299));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_guru(stats->get472440(300));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_scientist(stats->get472440(301));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_scrapper(stats->get472440(302));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_elite(stats->get472440(303));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_scrapoid(stats->get472440(304));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_scraphulk(stats->get472440(305));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_botcube(stats->get472440(306));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_zionite(stats->get472440(307));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_z_technician(stats->get472440(308));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_z_courier(stats->get472440(309));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_z_light(stats->get472440(310));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_z_heavy(stats->get472440(311));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_z_ex(stats->get472440(312));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_decomposer(stats->get472440(313));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_packrat(stats->get472440(314));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_samaritan(stats->get472440(315));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_tinkerer(stats->get472440(316));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_demented(stats->get472440(317));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_furnace(stats->get472440(318));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_parasite(stats->get472440(319));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_thief(stats->get472440(320));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_master_thief(stats->get472440(321));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_assembler(stats->get472440(322));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_assembled(stats->get472440(323));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_golem(stats->get472440(324));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_surgeon(stats->get472440(325));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_wasp(stats->get472440(326));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_thug(stats->get472440(327));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_savage(stats->get472440(328));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_butcher(stats->get472440(329));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_bouncer(stats->get472440(330));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_martyr(stats->get472440(331));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_guerrilla(stats->get472440(332));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_wizard(stats->get472440(333));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_marauder(stats->get472440(334));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_fireman(stats->get472440(335));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_mutant(stats->get472440(336));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_infiltrator(stats->get472440(337));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_sapper(stats->get472440(338));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_commander(stats->get472440(339));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_knight(stats->get472440(340));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_troll(stats->get472440(341));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_dragon(stats->get472440(342));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_hydra(stats->get472440(343));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_borebot(stats->get472440(344));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_unchained(stats->get472440(345));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_revision(stats->get472440(346));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_abomination(stats->get472440(347));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_anomaly(stats->get472440(348));
	pbStats->mutable_kills()->mutable_classes_destroyed()->set_player(stats->get472440(349));
	pbStats->mutable_kills()->mutable_best_kill_streak()->set_overall(stats->get472440(350));
	pbStats->mutable_kills()->mutable_best_kill_streak()->set_combat_bots_only(stats->get472440(351));
	pbStats->mutable_kills()->mutable_max_kills_in_single_turn()->set_overall(stats->get472440(352));
	pbStats->mutable_kills()->mutable_max_kills_in_single_turn()->set_gunslinging(stats->get472440(353));
	pbStats->mutable_kills()->mutable_max_kills_in_single_turn()->set_exploded(stats->get472440(354));
	pbStats->mutable_kills()->mutable_max_kills_in_single_turn()->set_melee(stats->get472440(355));
	pbStats->mutable_kills()->set_uniques_npcs_destroyed(stats->get472440(356));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->set_overall(stats->get472440(357));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->set_missed(stats->get472440(358));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->set_intercepted(stats->get472440(359));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->set_deflected(stats->get472440(360));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_hits()->set_overall(stats->get472440(361));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_hits()->set_melee(stats->get472440(362));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_hits()->set_projectile(stats->get472440(363));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_hits()->set_aoe(stats->get472440(364));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_critical_strikes()->set_overall(stats->get472440(365));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_critical_strikes()->set_actively_blocked(stats->get472440(366));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_part_disruptions()->set_overall(stats->get472440(367));
	pbStats->mutable_combat()->mutable_hostile_shots_fired()->mutable_part_disruptions()->set_actively_blocked(stats->get472440(368));
	pbStats->mutable_combat()->mutable_damage_taken()->set_overall(stats->get472440(369));
	pbStats->mutable_combat()->mutable_damage_taken()->set_core(stats->get472440(370));
	pbStats->mutable_combat()->mutable_damage_taken()->set_absorbed_by_shields(stats->get472440(371));
	pbStats->mutable_combat()->mutable_damage_taken()->set_reduced_by_siege_mode(stats->get472440(372));
	pbStats->mutable_combat()->mutable_damage_taken()->set_redirected_to_core(stats->get472440(373));
	pbStats->mutable_combat()->mutable_damage_taken()->set_redirected_to_shielding(stats->get472440(374));
	pbStats->mutable_combat()->mutable_damage_taken()->set_ignored_by_resistances(stats->get472440(375));
	pbStats->mutable_combat()->mutable_damage_taken()->set_regen_repair_parts(stats->get472440(376));
	pbStats->mutable_combat()->set_core_remaining_percent(stats->get472440(377));
	pbStats->mutable_combat()->mutable_volleys_fired()->set_overall(stats->get472440(378));
	pbStats->mutable_combat()->mutable_volleys_fired()->set_largest(stats->get472440(379));
	pbStats->mutable_combat()->mutable_volleys_fired()->set_hottest(stats->get472440(380));
	pbStats->mutable_combat()->mutable_shots_fired()->set_overall(stats->get472440(381));
	pbStats->mutable_combat()->mutable_shots_fired()->set_gun(stats->get472440(382));
	pbStats->mutable_combat()->mutable_shots_fired()->set_cannon(stats->get472440(383));
	pbStats->mutable_combat()->mutable_shots_fired()->set_launcher(stats->get472440(384));
	pbStats->mutable_combat()->mutable_shots_fired()->set_special(stats->get472440(385));
	pbStats->mutable_combat()->mutable_shots_fired()->set_kinetic(stats->get472440(386));
	pbStats->mutable_combat()->mutable_shots_fired()->set_thermal(stats->get472440(387));
	pbStats->mutable_combat()->mutable_shots_fired()->set_explosive(stats->get472440(388));
	pbStats->mutable_combat()->mutable_shots_fired()->set_electromagnetic(stats->get472440(389));
	pbStats->mutable_combat()->mutable_shots_fired()->set_impact(stats->get472440(390));
	pbStats->mutable_combat()->mutable_shots_fired()->set_slashing(stats->get472440(391));
	pbStats->mutable_combat()->mutable_shots_fired()->set_piercing(stats->get472440(392));
	pbStats->mutable_combat()->mutable_shots_fired()->set_entropic(stats->get472440(393));
	pbStats->mutable_combat()->mutable_shots_fired()->set_phasic(stats->get472440(394));
	pbStats->mutable_combat()->mutable_shots_fired()->set_robot_hit_streak(stats->get472440(395));
	pbStats->mutable_combat()->mutable_shots_fired()->set_robot_miss_streak(stats->get472440(396));
	pbStats->mutable_combat()->mutable_shots_fired()->set_penetration_max(stats->get472440(397));
	pbStats->mutable_combat()->mutable_shots_fired()->mutable_secondary_targets()->set_overall(stats->get472440(398));
	pbStats->mutable_combat()->mutable_shots_fired()->mutable_secondary_targets()->set_max_gunslinging_chain(stats->get472440(399));
	pbStats->mutable_combat()->mutable_shots_fired()->set_capacitor(stats->get472440(400));
	pbStats->mutable_combat()->mutable_shots_fired()->set_autonomous(stats->get472440(401));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->set_overall(stats->get472440(402));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->set_core_hits(stats->get472440(403));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->set_critical_kills(stats->get472440(404));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->set_critical_parts_destroyed(stats->get472440(405));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_overall(stats->get472440(406));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_burn(stats->get472440(407));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_meltdown(stats->get472440(408));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_destroy(stats->get472440(409));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_blast(stats->get472440(410));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_corrupt(stats->get472440(411));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_smash(stats->get472440(412));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_sever(stats->get472440(413));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_impale(stats->get472440(414));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_detonate(stats->get472440(415));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_sunder(stats->get472440(416));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_intensify(stats->get472440(417));
	pbStats->mutable_combat()->mutable_shots_hit_robots()->mutable_critical_strikes()->set_phase(stats->get472440(418));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_overall(stats->get472440(419));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_kinetic(stats->get472440(420));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_thermal(stats->get472440(421));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_explosive(stats->get472440(422));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_electromagnetic(stats->get472440(423));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_impact(stats->get472440(424));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_slashing(stats->get472440(425));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_piercing(stats->get472440(426));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_entropic(stats->get472440(427));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_phasic(stats->get472440(428));
	pbStats->mutable_combat()->mutable_melee_attacks()->mutable_sneak_attacks()->set_overall(stats->get472440(429));
	pbStats->mutable_combat()->mutable_melee_attacks()->mutable_sneak_attacks()->set_combat_hostiles(stats->get472440(430));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_follow_up_attacks(stats->get472440(431));
	pbStats->mutable_combat()->mutable_melee_attacks()->set_martial_strikes(stats->get472440(432));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_overall(stats->get472440(433));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_guns(stats->get472440(434));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_cannons(stats->get472440(435));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_explosions(stats->get472440(436));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_melee(stats->get472440(437));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_ramming(stats->get472440(438));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_kinetic(stats->get472440(439));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_thermal(stats->get472440(440));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_explosive(stats->get472440(441));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_electromagnetic(stats->get472440(442));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_impact(stats->get472440(443));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_slashing(stats->get472440(444));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_piercing(stats->get472440(445));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_entropic(stats->get472440(446));
	pbStats->mutable_combat()->mutable_damage_inflicted()->set_phasic(stats->get472440(447));
	pbStats->mutable_combat()->mutable_highest_corruption()->set_overall(stats->get472440(448));
	pbStats->mutable_combat()->mutable_highest_corruption()->set_average_corruption(stats->get472440(449));
	pbStats->mutable_combat()->mutable_highest_corruption()->set_corruption_purged(stats->get472440(450));
	pbStats->mutable_combat()->mutable_highest_corruption()->set_corruption_blocked(stats->get472440(451));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_overall(stats->get472440(452));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_message_errors(stats->get472440(453));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_matter_fused(stats->get472440(454));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_heat_flow_errors(stats->get472440(455));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_energy_discharges(stats->get472440(456));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_parts_rejected(stats->get472440(457));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_parts_fused(stats->get472440(458));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_data_loss_minor_(stats->get472440(459));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_data_loss_major_(stats->get472440(460));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_misfires(stats->get472440(461));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_alerts(stats->get472440(462));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_misdirections(stats->get472440(463));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_targeting_errors(stats->get472440(464));
	pbStats->mutable_combat()->mutable_highest_corruption()->mutable_effects()->set_weapon_failures(stats->get472440(465));
	pbStats->mutable_combat()->mutable_overload_shots()->set_overall(stats->get472440(466));
	pbStats->mutable_combat()->mutable_overload_shots()->mutable_effects()->set_overall(stats->get472440(467));
	pbStats->mutable_combat()->mutable_overload_shots()->mutable_effects()->set_energy_bleed(stats->get472440(468));
	pbStats->mutable_combat()->mutable_overload_shots()->mutable_effects()->set_heat_surge(stats->get472440(469));
	pbStats->mutable_combat()->mutable_overload_shots()->mutable_effects()->set_short_circuit(stats->get472440(470));
	pbStats->mutable_combat()->mutable_overload_shots()->mutable_effects()->set_meltdown(stats->get472440(471));
	pbStats->mutable_combat()->mutable_overflow_damage()->set_overall(stats->get472440(472));
	pbStats->mutable_combat()->mutable_overflow_damage()->set_projectiles(stats->get472440(473));
	pbStats->mutable_combat()->mutable_overflow_damage()->set_explosions(stats->get472440(474));
	pbStats->mutable_combat()->mutable_overflow_damage()->set_melee(stats->get472440(475));
	pbStats->mutable_combat()->mutable_knockbacks()->set_overall(stats->get472440(476));
	pbStats->mutable_combat()->mutable_knockbacks()->set_impact(stats->get472440(477));
	pbStats->mutable_combat()->mutable_knockbacks()->set_kinetic(stats->get472440(478));
	pbStats->mutable_combat()->mutable_knockbacks()->set_secondary(stats->get472440(479));
	pbStats->mutable_combat()->mutable_self_inflicted_damage()->set_overall(stats->get472440(480));
	pbStats->mutable_combat()->mutable_self_inflicted_damage()->set_shots(stats->get472440(481));
	pbStats->mutable_combat()->mutable_self_inflicted_damage()->set_rammed(stats->get472440(482));
	pbStats->mutable_combat()->mutable_targets_rammed()->set_overall(stats->get472440(483));
	pbStats->mutable_combat()->mutable_targets_rammed()->set_kicked(stats->get472440(484));
	pbStats->mutable_combat()->mutable_targets_rammed()->set_crushed(stats->get472440(485));
	pbStats->mutable_combat()->mutable_highest_temperature()->set_overall(stats->get472440(486));
	pbStats->mutable_combat()->mutable_highest_temperature()->set_average_temperature(stats->get472440(487));
	pbStats->mutable_combat()->mutable_highest_temperature()->set_received_heat_transfer(stats->get472440(488));
	pbStats->mutable_combat()->mutable_highest_temperature()->set_thermoelectric_energy_gain(stats->get472440(489));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_overall(stats->get472440(490));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_shutdowns(stats->get472440(491));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_energy_bleed(stats->get472440(492));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_interference(stats->get472440(493));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_matter_decay(stats->get472440(494));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_short_circuit(stats->get472440(495));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_damage_minor_(stats->get472440(496));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_damage_major_(stats->get472440(497));
	pbStats->mutable_combat()->mutable_highest_temperature()->mutable_effects()->set_damage_core_(stats->get472440(498));
	pbStats->mutable_combat()->mutable_siege_activations()->set_overall(stats->get472440(499));
	pbStats->mutable_combat()->mutable_siege_activations()->set_total_turns(stats->get472440(500));
	pbStats->mutable_combat()->mutable_siege_activations()->set_longest_duration(stats->get472440(501));
	pbStats->mutable_combat()->mutable_martial_activations()->set_overall(stats->get472440(502));
	pbStats->mutable_combat()->mutable_martial_activations()->set_total_turns(stats->get472440(503));
	pbStats->mutable_combat()->mutable_martial_activations()->set_longest_duration(stats->get472440(504));
	pbStats->mutable_combat()->mutable_shielding_activations()->set_overall(stats->get472440(505));
	pbStats->mutable_combat()->mutable_shielding_activations()->set_total_turns(stats->get472440(506));
	pbStats->mutable_combat()->mutable_shielding_activations()->set_longest_duration(stats->get472440(507));
	pbStats->mutable_combat()->mutable_robots_disrupted()->set_overall(stats->get472440(508));
	pbStats->mutable_combat()->mutable_robots_disrupted()->set_combat_hostiles(stats->get472440(509));
	pbStats->mutable_combat()->mutable_robots_corrupted()->set_overall(stats->get472440(510));
	pbStats->mutable_combat()->mutable_robots_corrupted()->set_combat_hostiles(stats->get472440(511));
	pbStats->mutable_combat()->mutable_robots_corrupted()->set_parts_fried(stats->get472440(512));
	pbStats->mutable_combat()->mutable_robots_corrupted()->set_impact_corruptions(stats->get472440(513));
	pbStats->mutable_combat()->mutable_robots_melted()->set_overall(stats->get472440(514));
	pbStats->mutable_combat()->mutable_robots_melted()->set_combat_hostiles(stats->get472440(515));
	pbStats->mutable_combat()->mutable_robots_melted()->set_parts_melted(stats->get472440(516));
	pbStats->mutable_combat()->mutable_robots_melted()->set_heat_transferred(stats->get472440(517));
	pbStats->mutable_combat()->set_parts_sabotaged(stats->get472440(518));
	pbStats->mutable_combat()->set_parts_stolen(stats->get472440(519));
	pbStats->mutable_combat()->set_parts_stripped(stats->get472440(520));
	pbStats->mutable_combat()->set_power_chain_reactions(stats->get472440(521));
	pbStats->mutable_combat()->mutable_latent_energy_used()->set_overall(stats->get472440(522));
	pbStats->mutable_combat()->mutable_latent_energy_used()->set_le_corruption(stats->get472440(523));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_overall(stats->get472440(524));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_low_security_percent(stats->get472440(525));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_level_1(stats->get472440(526));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_level_2(stats->get472440(527));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_level_3(stats->get472440(528));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_level_4(stats->get472440(529));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_level_5(stats->get472440(530));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_high_security(stats->get472440(531));
	pbStats->mutable_alert()->mutable_maximum_alert_level()->set_max_security(stats->get472440(532));
	pbStats->mutable_alert()->set_sterilizations(stats->get472440(533));
	pbStats->mutable_alert()->mutable_peak_influence()->set_overall(stats->get472440(534));
	pbStats->mutable_alert()->mutable_peak_influence()->set_initial_influence(stats->get472440(535));
	pbStats->mutable_alert()->mutable_peak_influence()->set_average_influence(stats->get472440(536));
	pbStats->mutable_alert()->mutable_influence_increases()->set_overall(stats->get472440(537));
	pbStats->mutable_alert()->mutable_influence_increases()->set_destroy_0b10_robot_c(stats->get472440(538));
	pbStats->mutable_alert()->mutable_influence_increases()->set_destroy_0b10_robot_nc(stats->get472440(539));
	pbStats->mutable_alert()->mutable_influence_increases()->set_destroy_leader(stats->get472440(540));
	pbStats->mutable_alert()->mutable_influence_increases()->set_allied_during_kill(stats->get472440(541));
	pbStats->mutable_alert()->mutable_influence_increases()->set_trap_triggered_on_0b10(stats->get472440(542));
	pbStats->mutable_alert()->mutable_influence_increases()->set_successful_hack(stats->get472440(543));
	pbStats->mutable_alert()->mutable_influence_increases()->set_select_force_hacks(stats->get472440(544));
	pbStats->mutable_alert()->mutable_influence_increases()->set_disable_machine(stats->get472440(545));
	pbStats->mutable_alert()->mutable_influence_increases()->set_anti_garrison_action(stats->get472440(546));
	pbStats->mutable_alert()->mutable_influence_increases()->set_destroy_structure(stats->get472440(547));
	pbStats->mutable_alert()->mutable_influence_increases()->set_advance_influence(stats->get472440(548));
	pbStats->mutable_alert()->mutable_influence_increases()->set_partial_spotted(stats->get472440(549));
	pbStats->mutable_alert()->mutable_influence_increases()->set_lose_combat_pursuer(stats->get472440(550));
	pbStats->mutable_alert()->mutable_influence_increases()->set_active_sensor_use(stats->get472440(551));
	pbStats->mutable_alert()->mutable_influence_increases()->set_miscellaneous(stats->get472440(552));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_overall(stats->get472440(553));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_entered_new_map(stats->get472440(554));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_time_decay(stats->get472440(555));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_search_patrol_dispatched(stats->get472440(556));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_lost_part(stats->get472440(557));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_lost_ally(stats->get472440(558));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_purge_threat(stats->get472440(559));
	pbStats->mutable_alert()->mutable_influence_decreases()->set_miscellaneous(stats->get472440(560));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_overall(stats->get472440(561));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_investigation(stats->get472440(562));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_extermination(stats->get472440(563));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_reinforcement(stats->get472440(564));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_assault(stats->get472440(565));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_garrison(stats->get472440(566));
	pbStats->mutable_alert()->mutable_squads_dispatched()->set_intercept(stats->get472440(567));
	pbStats->mutable_alert()->set_searches_triggered(stats->get472440(568));
	pbStats->mutable_alert()->set_unchained_authorized(stats->get472440(569));
	pbStats->mutable_alert()->set_data_miner_redirects(stats->get472440(570));
	pbStats->mutable_alert()->set_construction_impeded(stats->get472440(571));
	pbStats->mutable_alert()->set_haulers_reinforced(stats->get472440(572));
	pbStats->mutable_alert()->set_cargo_convoy_interrupts(stats->get472440(574));
	pbStats->mutable_alert()->set_alert_id_control_effect(stats->get472440(575));
	pbStats->mutable_stealth()->set_distress_signals(stats->get472440(576));
	pbStats->mutable_stealth()->mutable_communications_jammed()->set_overall(stats->get472440(577));
	pbStats->mutable_stealth()->mutable_communications_jammed()->set_distress_signals(stats->get472440(578));
	pbStats->mutable_stealth()->mutable_times_spotted()->set_overall(stats->get472440(579));
	pbStats->mutable_stealth()->mutable_times_spotted()->set_peak_tracking_total(stats->get472440(580));
	pbStats->mutable_stealth()->mutable_times_spotted()->set_tactical_retreats(stats->get472440(581));
	pbStats->mutable_stealth()->set_ecm_based_alert_blocks(stats->get472440(582));
	pbStats->mutable_stealth()->mutable_id_masks_used()->set_overall(stats->get472440(583));
	pbStats->mutable_stealth()->mutable_id_masks_used()->set_iff_responses(stats->get472440(584));
	pbStats->mutable_traps()->mutable_traps_triggered()->set_overall(stats->get472440(585));
	pbStats->mutable_traps()->mutable_traps_triggered()->set_indirectly(stats->get472440(586));
	pbStats->mutable_traps()->mutable_trap_hack_attempts()->set_overall(stats->get472440(587));
	pbStats->mutable_traps()->mutable_trap_hack_attempts()->set_triggered(stats->get472440(588));
	pbStats->mutable_traps()->mutable_trap_hack_attempts()->set_disarmed(stats->get472440(589));
	pbStats->mutable_traps()->mutable_trap_hack_attempts()->set_reprogrammed(stats->get472440(590));
	pbStats->mutable_traps()->mutable_trap_hack_attempts()->set_reused(stats->get472440(591));
	pbStats->mutable_traps()->set_traps_reconfigurated(stats->get472440(592));
	pbStats->mutable_traps()->mutable_traps_extracted()->set_overall(stats->get472440(593));
	pbStats->mutable_traps()->mutable_traps_extracted()->set_installed(stats->get472440(594));
	pbStats->mutable_traps()->mutable_traps_extracted()->set_triggered(stats->get472440(595));
	pbStats->mutable_traps()->set_fabricated_traps(stats->get472440(596));
	pbStats->mutable_traps()->set_most_traps_carried(stats->get472440(597));
	pbStats->mutable_traps()->mutable_objects_rigged()->set_overall(stats->get472440(598));
	pbStats->mutable_traps()->mutable_objects_rigged()->set_exploded(stats->get472440(599));
	pbStats->mutable_traps()->mutable_time_bombs_activated()->set_overall(stats->get472440(600));
	pbStats->mutable_traps()->mutable_time_bombs_activated()->set_exploded(stats->get472440(601));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_overall(stats->get472440(602));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_max_in_single_turn(stats->get472440(603));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_garrison_access(stats->get472440(604));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_garrison_relay(stats->get472440(605));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_phase_generator(stats->get472440(606));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_network_hub(stats->get472440(607));
	pbStats->mutable_machines()->mutable_machines_disabled()->set_energy_cycler(stats->get472440(608));
	pbStats->mutable_machines()->set_machines_repaired(stats->get472440(609));
	pbStats->mutable_machines()->set_machines_dismantled(stats->get472440(610));
	pbStats->mutable_machines()->set_machines_sabotaged(stats->get472440(611));
	pbStats->mutable_machines()->set_overloaded_fab_kills(stats->get472440(612));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_overall(stats->get472440(613));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_terminals(stats->get472440(614));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_fabricators(stats->get472440(615));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_repair_stations(stats->get472440(616));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_recycling_units(stats->get472440(617));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_scanalyzers(stats->get472440(618));
	pbStats->mutable_hacking()->mutable_machines_accessed()->set_garrison_access(stats->get472440(619));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_overall(stats->get472440(620));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_successful(stats->get472440(621));
	pbStats->mutable_hacking()->mutable_total_hacks()->mutable_failed()->set_overall(stats->get472440(622));
	pbStats->mutable_hacking()->mutable_total_hacks()->mutable_failed()->set_catastrophic(stats->get472440(623));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_database_lockouts(stats->get472440(624));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_manual(stats->get472440(625));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_terminals(stats->get472440(626));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_fabricators(stats->get472440(627));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_repair_stations(stats->get472440(628));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_recycling_units(stats->get472440(629));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_scanalyzers(stats->get472440(630));
	pbStats->mutable_hacking()->mutable_total_hacks()->set_garrison_access(stats->get472440(631));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_overall(stats->get472440(632));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_record(stats->get472440(633));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_part_schematic(stats->get472440(634));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_robot_schematic(stats->get472440(635));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_robot_analysis(stats->get472440(636));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_prototype_id_bank(stats->get472440(637));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_open_door(stats->get472440(638));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_open_dsf(stats->get472440(639));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_level_access_points(stats->get472440(640));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_branch_access_points(stats->get472440(641));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_emergency_access_points(stats->get472440(642));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_machine_index(stats->get472440(643));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_terminal_index(stats->get472440(644));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_fabricator_index(stats->get472440(645));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_repair_station_index(stats->get472440(646));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_recycling_unit_index(stats->get472440(647));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_scanalyzer_index(stats->get472440(648));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_garrison_index(stats->get472440(649));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_alert_level(stats->get472440(650));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_unreport_threat(stats->get472440(651));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_locate_traps(stats->get472440(652));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_disarm_traps(stats->get472440(653));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_reprogram_traps(stats->get472440(654));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_dispatch_records(stats->get472440(655));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_maintenance_status(stats->get472440(656));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_security_status(stats->get472440(657));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_surveillance_status(stats->get472440(658));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_patrol_status(stats->get472440(659));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_transport_status(stats->get472440(660));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_investigation_status(stats->get472440(661));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_extermination_status(stats->get472440(662));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_reinforcement_status(stats->get472440(663));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_assault_status(stats->get472440(664));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_garrison_status(stats->get472440(665));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_intercept_status(stats->get472440(666));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_coupling_status(stats->get472440(667));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_recall_investigation(stats->get472440(668));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_recall_extermination(stats->get472440(669));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_recall_reinforcements(stats->get472440(670));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_recall_assault(stats->get472440(671));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_hauler_manifests(stats->get472440(672));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_registered_components(stats->get472440(673));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_registered_prototypes(stats->get472440(674));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_zone_layout(stats->get472440(675));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_download_registry(stats->get472440(676));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_download_navigation(stats->get472440(677));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_download_security(stats->get472440(678));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_proto_id_catalog(stats->get472440(679));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_protovariant_controls(stats->get472440(680));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_activate_exoskeleton(stats->get472440(681));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_disengage_seal(stats->get472440(682));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_release_object(stats->get472440(683));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_gate_test_138_a(stats->get472440(684));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_gate_test_138_b(stats->get472440(685));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_gate_test_138_c(stats->get472440(686));
	pbStats->mutable_hacking()->mutable_terminal_hacks()->set_gate_test_138_end(stats->get472440(687));
	pbStats->mutable_hacking()->mutable_fabricator_hacks()->set_overall(stats->get472440(688));
	pbStats->mutable_hacking()->mutable_fabricator_hacks()->set_network_status(stats->get472440(689));
	pbStats->mutable_hacking()->mutable_fabricator_hacks()->set_load_schematic(stats->get472440(690));
	pbStats->mutable_hacking()->mutable_fabricator_hacks()->set_build(stats->get472440(691));
	pbStats->mutable_hacking()->mutable_repair_station_hacks()->set_overall(stats->get472440(692));
	pbStats->mutable_hacking()->mutable_repair_station_hacks()->set_scan_component(stats->get472440(693));
	pbStats->mutable_hacking()->mutable_repair_station_hacks()->set_repair(stats->get472440(694));
	pbStats->mutable_hacking()->mutable_repair_station_hacks()->set_refit(stats->get472440(695));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_overall(stats->get472440(696));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_recycle_component(stats->get472440(697));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_process(stats->get472440(698));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_report_inventory(stats->get472440(699));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_retrieve_matter(stats->get472440(700));
	pbStats->mutable_hacking()->mutable_recycling_unit_hacks()->set_retrieve_components(stats->get472440(701));
	pbStats->mutable_hacking()->mutable_scanalyzer()->set_overall(stats->get472440(702));
	pbStats->mutable_hacking()->mutable_scanalyzer()->set_insert_component(stats->get472440(703));
	pbStats->mutable_hacking()->mutable_scanalyzer()->set_analyze(stats->get472440(704));
	pbStats->mutable_hacking()->mutable_scanalyzer()->set_retrieve_study(stats->get472440(705));
	pbStats->mutable_hacking()->mutable_garrison_access_hacks()->set_overall(stats->get472440(706));
	pbStats->mutable_hacking()->mutable_garrison_access_hacks()->set_unlock_access(stats->get472440(707));
	pbStats->mutable_hacking()->mutable_garrison_access_hacks()->set_seal_access(stats->get472440(708));
	pbStats->mutable_hacking()->mutable_garrison_access_hacks()->set_coupler_status(stats->get472440(709));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->set_overall(stats->get472440(710));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_overall(stats->get472440(711));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_track(stats->get472440(712));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_assimilate(stats->get472440(713));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_botnet(stats->get472440(714));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_detonate(stats->get472440(715));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_disrupt(stats->get472440(716));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_operators(stats->get472440(717));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_skim(stats->get472440(718));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_sabotage(stats->get472440(719));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_search(stats->get472440(720));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_terminals()->set_override(stats->get472440(721));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_overall(stats->get472440(722));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_report(stats->get472440(723));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_prioritize(stats->get472440(724));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_liberate(stats->get472440(725));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_fabnet(stats->get472440(726));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_haulers(stats->get472440(727));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_overload(stats->get472440(728));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_download(stats->get472440(729));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_fabricators()->set_recompile(stats->get472440(730));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_repair_stations()->set_overall(stats->get472440(731));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_repair_stations()->set_mechanics(stats->get472440(732));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_repair_stations()->set_patch(stats->get472440(733));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_overall(stats->get472440(734));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_monitor(stats->get472440(735));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_reject(stats->get472440(736));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_recyclers(stats->get472440(737));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_mask(stats->get472440(738));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_tunnel(stats->get472440(739));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_fedlink(stats->get472440(740));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_scrapoids(stats->get472440(741));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_recycling_units()->set_scraphulk(stats->get472440(742));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_scanalyzers()->set_overall(stats->get472440(743));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_scanalyzers()->set_researchers(stats->get472440(744));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_scanalyzers()->set_extract(stats->get472440(745));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_overall(stats->get472440(746));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_broadcast(stats->get472440(747));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_restock(stats->get472440(748));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_decoy(stats->get472440(749));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_redirect(stats->get472440(750));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_reprogram(stats->get472440(751));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_intercept(stats->get472440(752));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_watchers(stats->get472440(753));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_jam(stats->get472440(754));
	pbStats->mutable_hacking()->mutable_unauthorized_hacks()->mutable_garrison_access()->set_eject(stats->get472440(755));
	pbStats->mutable_hacking()->mutable_data_cores_recovered()->set_overall(stats->get472440(756));
	pbStats->mutable_hacking()->mutable_data_cores_recovered()->set_used(stats->get472440(757));
	pbStats->mutable_hacking()->mutable_hacking_detections()->set_overall(stats->get472440(758));
	pbStats->mutable_hacking()->mutable_hacking_detections()->set_full_trace_events(stats->get472440(759));
	pbStats->mutable_hacking()->mutable_hacking_detections()->mutable_feedback_events()->set_overall(stats->get472440(760));
	pbStats->mutable_hacking()->mutable_hacking_detections()->mutable_feedback_events()->set_corruption(stats->get472440(761));
	pbStats->mutable_hacking()->mutable_hacking_detections()->mutable_feedback_events()->set_hackware_fried(stats->get472440(762));
	pbStats->mutable_hacking()->mutable_hacking_detections()->set_feedback_blocked(stats->get472440(763));
	pbStats->mutable_hacking()->mutable_robot_schematics_acquired()->set_overall(stats->get472440(764));
	pbStats->mutable_hacking()->mutable_robot_schematics_acquired()->mutable_robots_built()->set_overall(stats->get472440(765));
	pbStats->mutable_hacking()->mutable_robot_schematics_acquired()->mutable_robots_built()->set_authchips(stats->get472440(766));
	pbStats->mutable_hacking()->mutable_robot_schematics_acquired()->mutable_robots_built()->set_time(stats->get472440(767));
	pbStats->mutable_hacking()->mutable_robot_schematics_acquired()->set_total_robot_build_rating(stats->get472440(768));
	pbStats->mutable_hacking()->mutable_part_schematics_acquired()->set_overall(stats->get472440(769));
	pbStats->mutable_hacking()->mutable_part_schematics_acquired()->mutable_parts_built()->set_overall(stats->get472440(770));
	pbStats->mutable_hacking()->mutable_part_schematics_acquired()->mutable_parts_built()->set_authchips(stats->get472440(771));
	pbStats->mutable_hacking()->mutable_part_schematics_acquired()->mutable_parts_built()->set_time(stats->get472440(772));
	pbStats->mutable_hacking()->mutable_part_schematics_acquired()->set_total_part_build_rating(stats->get472440(773));
	pbStats->mutable_hacking()->set_part_studies_acquired(stats->get472440(774));
	pbStats->mutable_hacking()->mutable_parts_repaired()->set_overall(stats->get472440(775));
	pbStats->mutable_hacking()->mutable_parts_repaired()->set_time(stats->get472440(776));
	pbStats->mutable_hacking()->mutable_parts_recycled()->set_overall(stats->get472440(777));
	pbStats->mutable_hacking()->mutable_parts_recycled()->set_recycled_matter(stats->get472440(778));
	pbStats->mutable_hacking()->mutable_parts_recycled()->set_retrieved_matter(stats->get472440(779));
	pbStats->mutable_hacking()->mutable_parts_recycled()->set_retrieved_components(stats->get472440(780));
	pbStats->mutable_hacking()->mutable_parts_scanalyzed()->set_overall(stats->get472440(781));
	pbStats->mutable_hacking()->mutable_parts_scanalyzed()->set_part_schematics_acquired(stats->get472440(782));
	pbStats->mutable_hacking()->mutable_parts_scanalyzed()->set_parts_damaged(stats->get472440(783));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_overall(stats->get472440(784));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_coupler_efficiency(stats->get472440(785));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_hotswap(stats->get472440(786));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_code_merge(stats->get472440(787));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_command_fork(stats->get472440(788));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_threat_obfuscation(stats->get472440(789));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_signal_jamming(stats->get472440(790));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_zone_cloak(stats->get472440(791));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_robot_detection(stats->get472440(792));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_watcher_feeds(stats->get472440(794));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_patrol_navigation(stats->get472440(793));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_alert_id_control(stats->get472440(795));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_structural_interface(stats->get472440(796));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_program_shield(stats->get472440(797));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_autooverride(stats->get472440(798));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_autoassimilate(stats->get472440(799));
	pbStats->mutable_bothacking()->mutable_used_rif_installer()->set_crosswire(stats->get472440(800));
	pbStats->mutable_bothacking()->mutable_robots_hacked()->set_overall(stats->get472440(801));
	pbStats->mutable_bothacking()->mutable_robots_hacked()->set_non_combat(stats->get472440(802));
	pbStats->mutable_bothacking()->mutable_robots_hacked()->set_combat(stats->get472440(803));
	pbStats->mutable_bothacking()->mutable_robots_hacked()->set_autooverrided(stats->get472440(804));
	pbStats->mutable_bothacking()->mutable_robots_hacked()->set_autoassimilated(stats->get472440(805));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_overall(stats->get472440(806));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_parse_system(stats->get472440(807));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_no_distress(stats->get472440(808));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_generate_anomaly(stats->get472440(809));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_generate_echo(stats->get472440(810));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_start_evac(stats->get472440(811));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_chute(stats->get472440(812));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_deconstruct_machine(stats->get472440(813));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_hold_bot(stats->get472440(814));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_start_disposal(stats->get472440(815));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_ignore_repairs(stats->get472440(816));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_map_walls(stats->get472440(817));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_randomize_corridors(stats->get472440(818));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_map_earth(stats->get472440(819));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_fabricator(stats->get472440(820));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_dsf(stats->get472440(821));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_drop_inventory(stats->get472440(822));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_recall_reinforcements(stats->get472440(823));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_locate_stockpiles(stats->get472440(824));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_recycling(stats->get472440(825));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_ignore_parts(stats->get472440(826));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_station(stats->get472440(827));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_release_backups(stats->get472440(828));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_deconstruct_bot(stats->get472440(829));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_check_alert(stats->get472440(830));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_purge_threat(stats->get472440(831));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_terminals(stats->get472440(832));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_locate_traps(stats->get472440(833));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_disarm_traps(stats->get472440(834));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_reprogram_traps(stats->get472440(835));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_block_reporting(stats->get472440(836));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_summon_haulers(stats->get472440(837));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_recall_investigation(stats->get472440(838));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_clear_repairs(stats->get472440(839));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_clear_recycling(stats->get472440(840));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_map_route(stats->get472440(841));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_mark_security(stats->get472440(842));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_relay_feed(stats->get472440(843));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_disable_shields(stats->get472440(844));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_redirect_shields(stats->get472440(845));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_scanalyzer(stats->get472440(846));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_disable_scanner(stats->get472440(847));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_locate_prototypes(stats->get472440(848));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_report_prototypes(stats->get472440(849));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_report_schematics(stats->get472440(850));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_report_analyses(stats->get472440(851));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_ignore_targets(stats->get472440(852));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_emergency_deploy(stats->get472440(853));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_shortcuts(stats->get472440(854));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_find_garrison(stats->get472440(855));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_show_paths(stats->get472440(856));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_link_fov(stats->get472440(857));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_focus_fire(stats->get472440(858));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_reboot_propulsion(stats->get472440(859));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_tweak_propulsion(stats->get472440(860));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_scatter_targeting(stats->get472440(861));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_mark_system(stats->get472440(862));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_link_complan(stats->get472440(863));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_broadcast_data(stats->get472440(864));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_disrupt_area(stats->get472440(865));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_spike_heat(stats->get472440(866));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_overload_power(stats->get472440(867));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_amplify_resonance(stats->get472440(868));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_wipe_record(stats->get472440(869));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_disable_weapons(stats->get472440(870));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_reboot_system(stats->get472440(871));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_go_dormant(stats->get472440(872));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_overwrite_iff(stats->get472440(873));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_streamctrl_low(stats->get472440(874));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_streamctrl_high(stats->get472440(875));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_formatsys_low(stats->get472440(876));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_formatsys_high(stats->get472440(877));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_formatsys_deep(stats->get472440(878));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_retrieve_part(stats->get472440(879));
	pbStats->mutable_bothacking()->mutable_robot_hacks_applied()->set_manual(stats->get472440(880));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_overall(stats->get472440(881));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_ejected(stats->get472440(882));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_machine_destruction(stats->get472440(883));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_programmers(stats->get472440(884));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_attached(stats->get472440(885));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_crosswired(stats->get472440(886));
	pbStats->mutable_bothacking()->mutable_relay_couplers_released()->set_merged_code_value(stats->get472440(887));
	pbStats->mutable_bothacking()->mutable_fabnet_peak_effective_percent()->set_overall(stats->get472440(888));
	pbStats->mutable_bothacking()->mutable_fabnet_peak_effective_percent()->set_autooverrided(stats->get472440(889));
	pbStats->mutable_bothacking()->set_robots_rewired(stats->get472440(890));
	pbStats->mutable_bothacking()->set_allies_hacked(stats->get472440(891));
	pbStats->mutable_bothacking()->set_hacks_repelled(stats->get472440(892));
	pbStats->mutable_allies()->mutable_total_allies()->set_overall(stats->get472440(893));
	pbStats->mutable_allies()->mutable_total_allies()->set_largest_group(stats->get472440(894));
	pbStats->mutable_allies()->mutable_total_allies()->set_highest_rated_group(stats->get472440(895));
	pbStats->mutable_allies()->mutable_total_allies()->set_highest_rated_ally(stats->get472440(896));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_overall(stats->get472440(897));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_heavy(stats->get472440(898));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_light(stats->get472440(899));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_recon(stats->get472440(900));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_fire(stats->get472440(901));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_hacker(stats->get472440(902));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_demo(stats->get472440(903));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_experimental(stats->get472440(904));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_hero(stats->get472440(905));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_thermal_resupply(stats->get472440(906));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_kinetic_resupply(stats->get472440(907));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_explosive_resupply(stats->get472440(908));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_melee_resupply(stats->get472440(909));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_trap_resupply(stats->get472440(910));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_resource_resupply(stats->get472440(911));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_offense_resupply(stats->get472440(912));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_defense_resupply(stats->get472440(913));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_heavy_resupply(stats->get472440(914));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_infowar_resupply(stats->get472440(915));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_hacking_resupply(stats->get472440(916));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_hover_resupply(stats->get472440(917));
	pbStats->mutable_allies()->mutable_zionite_dispatches()->set_zionite_resupply(stats->get472440(918));
	pbStats->mutable_allies()->set_ufd_resources(stats->get472440(919));
	pbStats->mutable_allies()->set_warlord_eca_mod(stats->get472440(920));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_overall(stats->get472440(921));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_dakka(stats->get472440(922));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_infantry(stats->get472440(923));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_muscle(stats->get472440(924));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_geek(stats->get472440(925));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_ranger(stats->get472440(926));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_pyro(stats->get472440(927));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_chimera(stats->get472440(928));
	pbStats->mutable_allies()->mutable_warlord_squad_rendezvous()->set_ghost(stats->get472440(929));
	pbStats->mutable_allies()->mutable_total_orders()->set_overall(stats->get472440(930));
	pbStats->mutable_allies()->mutable_total_orders()->set_stay(stats->get472440(931));
	pbStats->mutable_allies()->mutable_total_orders()->set_roam(stats->get472440(932));
	pbStats->mutable_allies()->mutable_total_orders()->set_follow(stats->get472440(933));
	pbStats->mutable_allies()->mutable_total_orders()->set_guard(stats->get472440(934));
	pbStats->mutable_allies()->mutable_total_orders()->set_aid(stats->get472440(935));
	pbStats->mutable_allies()->mutable_total_orders()->set_tunnel(stats->get472440(936));
	pbStats->mutable_allies()->mutable_total_orders()->set_drop(stats->get472440(937));
	pbStats->mutable_allies()->mutable_total_orders()->set_pickup(stats->get472440(938));
	pbStats->mutable_allies()->mutable_total_orders()->set_collect(stats->get472440(939));
	pbStats->mutable_allies()->mutable_total_orders()->set_explore(stats->get472440(940));
	pbStats->mutable_allies()->mutable_total_orders()->set_return_(stats->get472440(941));
	pbStats->mutable_allies()->mutable_ally_attacks()->set_overall(stats->get472440(942));
	pbStats->mutable_allies()->mutable_ally_attacks()->set_total_damage(stats->get472440(943));
	pbStats->mutable_allies()->mutable_ally_attacks()->set_kills(stats->get472440(944));
	pbStats->mutable_allies()->set_allies_corrupted(stats->get472440(945));
	pbStats->mutable_allies()->set_allies_melted(stats->get472440(946));
	pbStats->mutable_allies()->set_turrets_deployed(stats->get472440(947));
	pbStats->mutable_allies()->set_fabricated_assembled(stats->get472440(948));
	pbStats->mutable_allies()->set_field_lobotomies(stats->get472440(949));
	pbStats->mutable_allies()->mutable_borg_created()->set_overall(stats->get472440(950));
	pbStats->mutable_allies()->mutable_borg_created()->set_largest_collective(stats->get472440(951));
	pbStats->mutable_allies()->mutable_xom_amusement_gains()->set_overall(stats->get472440(952));
	pbStats->mutable_allies()->mutable_xom_amusement_gains()->set_average_entertainment(stats->get472440(953));
	pbStats->mutable_allies()->mutable_xom_amusement_gains()->set_good_acts(stats->get472440(954));
	pbStats->mutable_allies()->mutable_xom_amusement_gains()->set_bad_acts(stats->get472440(955));
	pbStats->mutable_intel()->mutable_active_infowar()->set_overall(stats->get472440(956));
	pbStats->mutable_intel()->mutable_active_infowar()->set_optics(stats->get472440(957));
	pbStats->mutable_intel()->mutable_active_infowar()->set_sensors(stats->get472440(958));
	pbStats->mutable_intel()->mutable_active_infowar()->set_ass(stats->get472440(959));
	pbStats->mutable_intel()->mutable_active_infowar()->set_iff(stats->get472440(960));
	pbStats->mutable_intel()->mutable_active_infowar()->set_zeronet(stats->get472440(961));
	pbStats->mutable_intel()->mutable_active_infowar()->set_terrain(stats->get472440(962));
	pbStats->mutable_intel()->mutable_active_infowar()->set_structural(stats->get472440(963));
	pbStats->mutable_intel()->mutable_active_infowar()->set_traps(stats->get472440(964));
	pbStats->mutable_intel()->mutable_active_infowar()->set_seismic(stats->get472440(965));
	pbStats->mutable_intel()->mutable_active_infowar()->set_decoding(stats->get472440(966));
	pbStats->mutable_intel()->mutable_active_infowar()->set_tnc(stats->get472440(967));
	pbStats->mutable_intel()->mutable_active_infowar()->set_machine_analysis(stats->get472440(968));
	pbStats->mutable_intel()->mutable_active_infowar()->set_triangulation(stats->get472440(969));
	pbStats->mutable_intel()->mutable_active_infowar()->set_cloaking(stats->get472440(970));
	pbStats->mutable_intel()->mutable_active_infowar()->set_spoofing(stats->get472440(971));
	pbStats->mutable_intel()->mutable_active_infowar()->set_jamming(stats->get472440(972));
	pbStats->mutable_intel()->mutable_active_infowar()->set_ecm(stats->get472440(973));
	pbStats->mutable_intel()->mutable_active_infowar()->set_id_mask(stats->get472440(974));
	pbStats->mutable_intel()->set_robot_analysis_total(stats->get472440(975));
	pbStats->mutable_intel()->set_derelict_logs_recovered(stats->get472440(976));
	pbStats->mutable_intel()->mutable_drone_launches()->set_overall(stats->get472440(977));
	pbStats->mutable_intel()->mutable_drone_launches()->set_drone_recoveries(stats->get472440(978));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_overall(stats->get472440(979));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_traps(stats->get472440(980));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_emergency_access(stats->get472440(981));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_items(stats->get472440(982));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_machines(stats->get472440(983));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_garrisons(stats->get472440(984));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_patrols(stats->get472440(985));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_investigations(stats->get472440(986));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_reinforcements(stats->get472440(987));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_guards(stats->get472440(988));
	pbStats->mutable_intel()->mutable_decoded_0b10_intel()->set_exits(stats->get472440(989));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_overall(stats->get472440(990));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_main_access(stats->get472440(991));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_branch_access(stats->get472440(992));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_emergency_access(stats->get472440(993));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_guard_positions(stats->get472440(994));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_component_stockpiles(stats->get472440(995));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_prototype_stockpiles(stats->get472440(996));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_component_schematics(stats->get472440(997));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_prototype_schematics(stats->get472440(998));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_unaware_schematics(stats->get472440(999));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_unaware_analyses(stats->get472440(1000));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_trap_installations(stats->get472440(1001));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_active_terminals(stats->get472440(1002));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_active_garrisons(stats->get472440(1003));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_depthwide_sectors_0(stats->get472440(1004));
	pbStats->mutable_intel()->mutable_zionite_intel_received()->set_depthwide_sectors_1(stats->get472440(1005));
	pbStats->mutable_exploration()->set_turns_passed(stats->get472440(1006));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_overall(stats->get472440(1007));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_core(stats->get472440(1008));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_treads(stats->get472440(1009));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_legs(stats->get472440(1010));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_wheels(stats->get472440(1011));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_hover(stats->get472440(1012));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_flight(stats->get472440(1013));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_fastest_speed(stats->get472440(1014));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_average_speed(stats->get472440(1015));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_slowest_speed(stats->get472440(1016));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_overloaded_moves(stats->get472440(1017));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_propulsion_burnouts(stats->get472440(1018));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_robots_hopped(stats->get472440(1019));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_potential_cave_ins(stats->get472440(1020));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_cave_ins_triggered(stats->get472440(1021));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_teleports(stats->get472440(1022));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_teleports(stats->get472440(1023));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_teleports(stats->get472440(1024));
	pbStats->mutable_exploration()->mutable_spaces_moved()->set_time_travels(stats->get472440(1025));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->set_overall(stats->get472440(1026));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->mutable_regions_visited()->set_overall(stats->get472440(1027));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->mutable_regions_visited()->set_branch_regions(stats->get472440(1028));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->set_pre_discovered_areas(stats->get472440(1029));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->set_known_exits_taken(stats->get472440(1030));
	pbStats->mutable_exploration()->mutable_exploration_rate_percent()->set_unknown_exits_taken(stats->get472440(1031));
	pbStats->mutable_exploration()->set_scrap_searched(stats->get472440(1032));
	pbStats->mutable_exploration()->set_spaces_dug(stats->get472440(1033));
	pbStats->mutable_exploration()->mutable_terrain_destroyed()->set_overall(stats->get472440(1034));
	pbStats->mutable_exploration()->mutable_terrain_destroyed()->set_melee(stats->get472440(1035));
	pbStats->mutable_exploration()->mutable_terrain_destroyed()->set_projectile(stats->get472440(1036));
	pbStats->mutable_exploration()->mutable_terrain_destroyed()->set_aoe(stats->get472440(1037));
	pbStats->mutable_exploration()->mutable_terrain_rammed()->set_overall(stats->get472440(1038));
	pbStats->mutable_exploration()->mutable_terrain_rammed()->set_walls_destroyed(stats->get472440(1039));
	pbStats->mutable_exploration()->mutable_terrain_rammed()->set_machines_disabled(stats->get472440(1040));
	pbStats->mutable_exploration()->set_doors_sealed(stats->get472440(1041));
	pbStats->mutable_actions()->mutable_total()->set_overall(stats->get472440(1042));
	pbStats->mutable_actions()->mutable_total()->set_wait(stats->get472440(1043));
	pbStats->mutable_actions()->mutable_total()->set_move(stats->get472440(1044));
	pbStats->mutable_actions()->mutable_total()->set_hop(stats->get472440(1045));
	pbStats->mutable_actions()->mutable_total()->set_pick_up(stats->get472440(1046));
	pbStats->mutable_actions()->mutable_total()->set_fast_attach(stats->get472440(1047));
	pbStats->mutable_actions()->mutable_total()->set_attach(stats->get472440(1048));
	pbStats->mutable_actions()->mutable_total()->set_detach(stats->get472440(1049));
	pbStats->mutable_actions()->mutable_total()->set_swap(stats->get472440(1050));
	pbStats->mutable_actions()->mutable_total()->set_drop(stats->get472440(1051));
	pbStats->mutable_actions()->mutable_total()->set_fire(stats->get472440(1052));
	pbStats->mutable_actions()->mutable_total()->set_melee(stats->get472440(1053));
	pbStats->mutable_actions()->mutable_total()->set_ram(stats->get472440(1054));
	pbStats->mutable_actions()->mutable_total()->set_kick(stats->get472440(1055));
	pbStats->mutable_actions()->mutable_total()->set_crush(stats->get472440(1056));
	pbStats->mutable_actions()->mutable_total()->set_escape_stasis(stats->get472440(1057));
	pbStats->mutable_actions()->mutable_total()->set_rewire(stats->get472440(1058));
	pbStats->mutable_actions()->mutable_total()->set_trap(stats->get472440(1059));
	pbStats->mutable_actions()->mutable_total()->set_miscellaneous(stats->get472440(1060));
	pbStats->mutable_rpglike()->mutable_levels_raised()->set_overall(stats->get472440(1061));
	pbStats->mutable_rpglike()->mutable_levels_raised()->set_xp_earned(stats->get472440(1062));
	pbStats->mutable_rpglike()->mutable_levels_raised()->set_xp_spent(stats->get472440(1063));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_overall(stats->get472440(1064));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_power_slot(stats->get472440(1065));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_propulsion_slot(stats->get472440(1066));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_utility_slot(stats->get472440(1067));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_weapon_slot(stats->get472440(1068));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_core_integrity(stats->get472440(1069));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_heat_dissipation(stats->get472440(1070));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_energy_generation(stats->get472440(1071));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_energy_storage(stats->get472440(1072));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_matter_storage(stats->get472440(1073));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_mass_support(stats->get472440(1074));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_inventory_capacity(stats->get472440(1075));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_sight_range(stats->get472440(1076));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_sensor_range(stats->get472440(1077));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_terrain_scan_density(stats->get472440(1078));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_ranged_accuracy(stats->get472440(1079));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_melee_accuracy(stats->get472440(1080));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_hack_attack_percent(stats->get472440(1081));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_hack_defense_percent(stats->get472440(1082));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_ki_resistance_percent(stats->get472440(1083));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_th_resistance_percent(stats->get472440(1084));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_ex_resistance_percent(stats->get472440(1085));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_ki_damage_percent(stats->get472440(1086));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_th_damage_percent(stats->get472440(1087));
	pbStats->mutable_rpglike()->mutable_upgrades()->set_ex_damage_percent(stats->get472440(1088));
	pbStats->mutable_rpglike()->mutable_protomatter_created()->set_overall(stats->get472440(1089));
	pbStats->mutable_rpglike()->mutable_protomatter_created()->mutable_integrity_restored()->set_overall(stats->get472440(1090));
	pbStats->mutable_rpglike()->mutable_protomatter_created()->mutable_integrity_restored()->set_core(stats->get472440(1091));
	pbStats->mutable_rpglike()->mutable_protomatter_created()->mutable_integrity_restored()->set_parts(stats->get472440(1092));
	pbStats->mutable_rpglike()->set_protomatter_decayed(stats->get472440(1093));
	pbStats->mutable_player2()->mutable_slots_evolved()->set_overall(stats->get472440(1094));
	pbStats->mutable_player2()->mutable_slots_evolved()->set_power(stats->get472440(1095));
	pbStats->mutable_player2()->mutable_slots_evolved()->set_propulsion(stats->get472440(1096));
	pbStats->mutable_player2()->mutable_slots_evolved()->set_utility(stats->get472440(1097));
	pbStats->mutable_player2()->mutable_slots_evolved()->set_weapon(stats->get472440(1098));
	pbStats->mutable_player2()->set_parts_attached(stats->get472440(1099));
	pbStats->mutable_player2()->set_parts_lost(stats->get472440(1100));
	pbStats->mutable_player2()->mutable_damage_taken()->set_overall(stats->get472440(1101));
	pbStats->mutable_player2()->mutable_damage_taken()->mutable_core()->set_overall(stats->get472440(1102));
	pbStats->mutable_player2()->mutable_damage_taken()->mutable_core()->set_player2percentage(stats->get472440(1103));
	pbStats->mutable_player2()->mutable_damage_taken()->set_absorbed_by_shields(stats->get472440(1104));
	pbStats->mutable_player2()->mutable_damage_inflicted()->set_overall(stats->get472440(1105));
	pbStats->mutable_player2()->mutable_damage_inflicted()->set_player2percentage(stats->get472440(1106));
	pbStats->mutable_player2()->mutable_combat_hostiles_destroyed()->set_overall(stats->get472440(1107));
	pbStats->mutable_player2()->mutable_combat_hostiles_destroyed()->set_player2percentage(stats->get472440(1108));
	pbStats->mutable_polymind()->mutable_hosts()->set_overall(stats->get472440(1109));
	pbStats->mutable_polymind()->mutable_hosts()->set_combat_hostiles(stats->get472440(1110));
	pbStats->mutable_polymind()->mutable_hosts()->set_allies(stats->get472440(1111));
	pbStats->mutable_polymind()->set_unique_host_classes(stats->get472440(1112));
	pbStats->mutable_polymind()->mutable_average_suspicion()->set_overall(stats->get472440(1113));
	pbStats->mutable_polymind()->mutable_average_suspicion()->set_unsuspicious_activity(stats->get472440(1114));
	pbStats->mutable_polymind()->mutable_average_suspicion()->set_returns_to_shadow(stats->get472440(1115));
	pbStats->mutable_polymind()->mutable_average_suspicion()->set_fuzzy_dispatches(stats->get472440(1116));
	pbStats->mutable_polymind()->mutable_protomatter_created()->set_overall(stats->get472440(1117));
	pbStats->mutable_polymind()->mutable_protomatter_created()->set_used(stats->get472440(1118));
	pbStats->mutable_polymind()->mutable_protomatter_created()->set_decayed(stats->get472440(1119));
	pbStats->mutable_polymind()->mutable_protomatter_created()->set_highest_spend(stats->get472440(1120));
}
