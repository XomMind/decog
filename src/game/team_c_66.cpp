// team_c_66: RIF ability description (0x781a10): concatenates the description of each installed RIF ability
//	(with its current level and level-dependent values) into one help text
// NOTE: names are placeholders; layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder signature

extern string rifAbilityNames_d2a2e0[];	// global_string_arrays.cpp
extern int c66_couplerEfficiency_b988f0[], c66_commandFork_b98948[], c66_codeMerge_b989a0[], c66_threatObfuscation_b989a8[], c66_zoneCloakDelay_b989b4[], c66_b989bc[], c66_b989c8[];	// NOTE: placeholder names (per-level value tables)

class C66_PlayerData	// NOTE: placeholder layout
{
public:
	char pad0[0x42c];
	vector<int> f42c;
	vector<int> f43c;

	string describeRIF_781a10();
};

string C66_PlayerData::describeRIF_781a10()
{
	string center;
	vector<int> col;
	for (unsigned int cols = 0; cols < f43c.size(); cols++)
	{
		if (!OpX5_containsRecord(col,f43c[cols]))
		{
			col.push_back(f43c[cols]);
			switch (f43c[cols])
			{
				case 0:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[0];
					center += ": Know the ambient influence level while in 0b10-controlled areas.";
					break;
				case 1:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[1];
					center += ": Gain control over Garrison Access machines, making it easier to hack them, and also easier to escape once inside. Also automatically detects Garrisons and RIF Installers up to a range of " + intToString(15) + ".";
					break;
				case 2:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[2];
					center += ": Use Relay Couplers to interface with their respective robots.";
					break;
				case 3:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[3];
					center += " (" + intToString(f42c[3]) + "): +" + intToString(c66_couplerEfficiency_b988f0[f42c[3]]) + " effective code value to all Relay Couplers.";
					break;
				case 4:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[4];
					center += ": Automatically swap in additional matching Couplers in sequence from inventory when effective code value of current attached Couplers insufficient for desired hack.";
					break;
				case 5:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[5];
					center += " (" + intToString(f42c[5]) + "): Stand on a Coupler and use > or right-click on self to add " + intToString(c66_codeMerge_b989a0[f42c[5]]) + "% of its code value to a matching attached Coupler. Cannot increase value beyond " + intToString(99) + ".";
					break;
					break;
				case 6:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[6];
					center += " (" + intToString(f42c[6]) + "): " + intToString(c66_commandFork_b98948[f42c[6]]) + "% chance to duplicate each hack, also applying it to the visible applicable target nearest to the initial target, at no extra cost. Must have a matching Coupler attached for the fork target. Compatible with most hacks, excluding generate_echo, map_walls, map_earth, map_route, or those that would have no meaningful effect.";
					break;
				case 7:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[7];
					center += " (" + intToString(f42c[7]) + "): All influence increases reduced by " + intToString(c66_threatObfuscation_b989a8[f42c[7]]) + "%.";
					break;
				case 8:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[8];
					center += ": Blocks local transmissions from visible hostiles while matching Coupler attached, making it impossible for them to share information about your current position. Also prevents calls for reinforcements, and suppresses alarm traps.";
					break;
				case 9:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[9];
					center += " (" + intToString(f42c[9]) + "): Extermination squads require an average " + intToString(c66_zoneCloakDelay_b989b4[f42c[9]]) + " more turns before they can pinpoint your position for dispatching.";
					break;
				case 10:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[10];
					center += ": Know positions of combat bots within a range of " + intToString(24) + " while matching Coupler attached. Also distinguishes squad leaders (L).";
					break;
				case 11:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[11];
					center += ": Tap into visual feed data of all 0b10 Watchers within a range of " + intToString(22) + " while at least one Relay Coupler [NC] attached.";
					break;
				case 12:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[12];
					center += ": Know routes of patrol squads within a range of " + intToString(24) + " while matching Coupler attached.";
					break;
				case 13:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[13];
					center += ": Block the influence of kills by allied former 0b10 combat bots while matching Coupler attached.";
					break;
				case 14:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[14];
					center += ": Reveal any hidden door or phasewall on sight, and pass through phasewalls normally.";
					break;
				case 15:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[15];
					center += ": Fully prevent Programmers from hacking allied former 0b10 combat bots while matching Coupler attached (no range or sight limitations).";
					break;
				case 16:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[16];
					center += " (" + intToString(f42c[16]) + "): " + intToString(c66_b989bc[f42c[16]]) + "% chance to automatically trick target system into believing it is allied with Cogmind. After 10 turns the network will perform an automated quickboot to restore it to normal, a process which takes anywhere from 5 to 10 turns. Checked once per visible combat bot while matching Coupler attached, separately for each Coupler.";
					break;
				case 17:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[17];
					center += " (" + intToString(f42c[17]) + "): " + intToString(c66_b989c8[f42c[17]]) + "% chance to automatically rewrite all target system data, permanently converting it into a fully controllable ally. Requires 6 turns to complete the process. Checked once per visible combat bot while matching Coupler attached, separately for each Coupler.";
					break;
				case 18:
					if (!center.empty())
						center += "\n\n";
					center += rifAbilityNames_d2a2e0[18];
					center += ": Convert Swarmer, Grunt, Brawler, and Duelist Couplers to Relay Coupler [C], usable on any common 0b10 bots of these types.";
					break;
			}
		}
	}
	center += "\n\n";
	center += "Seek out additional RIF Installers to gain new capabilities.";
	return center;
}
