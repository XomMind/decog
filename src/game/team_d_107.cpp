// team_d_107: experience gain 0x77e900 (callers OpR1h_Stats::add472b90, OpR3c_Overmind::unknown682420,
// BS::turnUpdate_74e750 and one more): scales the gain by the level difference to the current depth (unless
// raw), adds it, records stats and processes level-ups (sound, level-up display, messages) up to level 99.
// NOTE: class layouts are partial; all names are placeholders.
// NOTE: the depth scaling factors are extern const float globals because the exe multiplies by a float in
// .rdata (a float literal would be widened to a double constant).
#include <string>
using namespace std;

string intToString(int value);	// 0x4051f0
int tableEntry_434a80(int table, int level);	// NOTE: placeholder name
int triple_434aa0(int depth);	// NOTE: placeholder name
int triple_434ac0(int depth);	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

class HEntity
{
public:
	int ID;
	HEntity();
};

class HProp
{
public:
	int ID;
	HProp();
};

bool showMessage107(int id, const string *text, const void *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message107_5141b0(int id, const string *text, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

class GameData107	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name (current depth)
};
extern GameData107 gameData107_d1e860;	// NOTE: placeholder name

class Stats107	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats107 stats107_d2c658;	// NOTE: placeholder name

class BS
{
public:
	int unknown463e50();	// NOTE: placeholder name
};
extern BS *world107_cefc4c;	// NOTE: placeholder name

class RpgLevel107	// NOTE: placeholder name (TeamB_RpglikeLevel at 0xcec060)
{
public:
	void showLevelUp878b90();	// NOTE: placeholder name
};
extern RpgLevel107 *rpgLevel107_cec060;	// NOTE: placeholder name

class ConsoleA107	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA107 *consoleA107_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs107_cec0b4;	// NOTE: placeholder name

extern int level107_cf4690;		// NOTE: placeholder name
extern int table107_cf4718;		// NOTE: placeholder name
extern bool flag107_cf46a0;		// NOTE: placeholder name
extern const float xpAbove107_ba7ac0;	// NOTE: placeholder name (1.3)
extern const float xpBelow107_ba7ac4;	// NOTE: placeholder name (0.7)

class Experience107	// NOTE: placeholder name and layout
{
public:
	char	pad00[0xb8];
	int		levelUps;	// +0xb8
	int		total;		// +0xbc
	int		current;	// +0xc0
	int		spent;		// +0xc4

	void gain(int amount, bool raw);	// NOTE: placeholder name
};

void Experience107::gain(int amount, bool raw)
{
	if (amount <= 0 || level107_cf4690 == 99)
		return;
	if (!raw)
	{
		if (level107_cf4690 > triple_434ac0(gameData107_d1e860.getDepthIndex()))
		{
			int n = level107_cf4690 - triple_434ac0(gameData107_d1e860.getDepthIndex());
			while (n != 0)
			{
				amount = (int)(amount * xpBelow107_ba7ac4);
				n--;
			}
			if (amount == 0)
				return;
		}
		else if (table107_cf4718 && level107_cf4690 < triple_434aa0(gameData107_d1e860.getDepthIndex()))
		{
			int m = triple_434aa0(gameData107_d1e860.getDepthIndex()) - level107_cf4690;
			while (m != 0)
			{
				amount = (int)(amount * xpAbove107_ba7ac0);
				m--;
			}
		}
	}
	total += amount;
	current += amount;
	stats107_d2c658.add4729d0(0x426,amount,"",-1);
	while (total >= tableEntry_434a80(table107_cf4718,level107_cf4690 + 1))
	{
		int d = tableEntry_434a80(table107_cf4718,level107_cf4690 + 1) - tableEntry_434a80(table107_cf4718,level107_cf4690);
		spent += d;
		current -= d;
		levelUps++;
		if (world107_cefc4c && world107_cefc4c->unknown463e50())
		{
			rpgLevel107_cec060->showLevelUp878b90();
			opR1d_4541b0(0x138,0,0);
		}
		flag107_cf46a0 = false;
		do
		{
			if (showMessage107(0x2f9,&intToString(levelUps),0,0,HEntity(),HProp(),0,0))
				consoleA107_cec058->unknown8758d0(true);
			logMsgs107_cec0b4->scrollToEnd();
		} while (0);
		do
		{
			message107_5141b0(0x2c,&intToString(levelUps),0,0,HProp(),0);
		} while (0);
		stats107_d2c658.add4729d0(0x425,1,"",-1);
		if (level107_cf4690 == 99)
		{
			current = 0;
			break;
		}
	}
}
