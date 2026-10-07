// team_b_23: terminal topic availability check (0x9004e0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names. Messages are passed as explicit string(...) temporaries, as in the exe.
#include <string>
using namespace std;
bool OpT8b_Fn9daf80(int lo, int v, int hi);
struct TeamB_MachineData { char pad[0x10]; bool limited; bool blocked; bool unknown45c160(int topic, int a); };	// NOTE: placeholder layout
struct TeamB_MachineInfo { char pad[0xf8]; int type; };	// NOTE: placeholder layout
class TeamB_MachineProp { public: TeamB_MachineData *getData_45cb30(); TeamB_MachineInfo *getInfo_9b8f00(); };
class HProp { public: int ID; TeamB_MachineProp *operator->() const; };
class TeamB_Hack { public: HProp get4b1460(); void unknown940ad0(int a, int b, int c); };
extern TeamB_Hack *teamb_cec0f8;	// NOTE: placeholder name
class CShell { public: void addNew(const string &text, const string &text2, int type, int a, bool b); };
extern CShell *teamb_shell_cec100;	// NOTE: placeholder name
struct TeamB_Topic6 { char pad[3]; bool f3; bool f4; char f5; };	// NOTE: placeholder layout
extern TeamB_Topic6 teamb_topics_b9b178[];	// NOTE: placeholder name
bool teamb_isAvailable9004e0(int topic, const string *text)	// NOTE: placeholder name (0x9004e0; OpW7_isAvailable_9004e0 in src/op/op_w7.cpp)
{
	if (teamb_cec0f8->get4b1460()->getData_45cb30()->blocked)
	{
		if (text)
			teamb_shell_cec100->addNew(*text,string("Connection blocked by override."),2,-1,false);
		return false;
	}
	bool allowed = teamb_cec0f8->get4b1460()->getData_45cb30()->unknown45c160(topic,-1);
	if (teamb_cec0f8->get4b1460()->getData_45cb30()->limited && !allowed)
	{
		if (text)
			teamb_shell_cec100->addNew(*text,string("Terminal is limited access only."),2,-1,false);
		return false;
	}
	if (!teamb_topics_b9b178[topic].f4 || allowed)
	{
		switch (teamb_cec0f8->get4b1460()->getInfo_9b8f00()->type)
		{
		case 0: if (OpT8b_Fn9daf80(0,topic,0x40)) return true; break;
		case 1: if (OpT8b_Fn9daf80(0x41,topic,0x4b)) return true; break;
		case 2: if (OpT8b_Fn9daf80(0x4c,topic,0x50)) return true; break;
		case 3: if (OpT8b_Fn9daf80(0x51,topic,0x5d)) return true; break;
		case 4: if (OpT8b_Fn9daf80(0x5e,topic,0x62)) return true; break;
		case 5: if (OpT8b_Fn9daf80(0x63,topic,0x6e)) return true; break;
		}
	}
	if (text)
	{
		string reply = teamb_topics_b9b178[topic].f3 || teamb_topics_b9b178[topic].f4 ? "Unknown command." : (teamb_cec0f8->get4b1460()->getInfo_9b8f00()->type >= 6 ? "Unknown command." : "Command unavailable on this system.");
		teamb_shell_cec100->addNew(*text,reply,2,-1,false);
		teamb_cec0f8->unknown940ad0(100,100,0);
	}
	return false;
}
