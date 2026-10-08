// team_c_46: Cogmind layout injection for REX_Init (0x446390, passed as its layout callback): picks the largest font
//	size that fits the desktop, derives the map view and root console dimensions from system.cfg
// NOTE: names are placeholders; the Config fields are declared as separate globals (Config object at 0xd28c68)
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
void logInfo(string message);
void logMessage(string message);
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void OpB_updateFontScale_446320();	// NOTE: placeholder name
extern string gameStrings_d2a530[];	// global_string_arrays.cpp

struct C46_Rex { int getDesktopWidth(); int getDesktopHeight(); };	// NOTE: placeholder names (REX at 0xd223f0)
struct C46_JLog { void end(int level); };

extern C46_Rex c46_d223f0;	// NOTE: placeholder names below
extern int c46_d28c68, c46_cebd5c, c46_d28cc0, c46_d28cc4, c46_d28cc8, c46_d28ca4, c46_d28ca8;
extern string c46_d28c6c, c46_d2a504;
extern bool c46_d28c88;
extern int c46_cefab0, c46_cefaac, c46_cefab4, c46_cefab8, c46_caf128, c46_caf12c;
extern int c46_ba6aa4[], c46_ba6ab0[], c46_ba6ac8[];
extern C46_JLog *c46_cefa64;

void c46_injectLayout_446390(int *rootWidth, int *rootHeight, int *fontHeight, int *fontWidth)	// NOTE: placeholder name
{
	logInfo("Cogmind injection");
	c46_cebd5c = c46_d28c68;
	logMessage("Target layout: " + gameStrings_d2a530[c46_cebd5c]);
	if (c46_d28cc0 != c46_d223f0.getDesktopWidth() || c46_d28cc4 != c46_d223f0.getDesktopHeight() || c46_d28cc8 != c46_d28c68)
	{
		logMessage("Resetting core system.cfg values to AUTO/0/0");
		c46_d28c6c = c46_d2a504;
		c46_d28ca4 = 0;
		c46_d28ca8 = 0;
		c46_d28cc0 = c46_d223f0.getDesktopWidth();
		c46_d28cc4 = c46_d223f0.getDesktopHeight();
		c46_d28cc8 = c46_d28c68;
	}
	vector<int> center;
	for (int cols = c46_cebd5c != 0 ? 14 : 10; cols <= 20; cols += 2)
		center.push_back(cols);
	for (int cols = 24; cols <= 40; cols += 4)
		center.push_back(cols);
	center.push_back(42);
	center.push_back(48);
	center.push_back(54);
	center.push_back(56);
	center.push_back(60);
	center.push_back(64);
	int col = c46_d223f0.getDesktopWidth();
	int adj = c46_d223f0.getDesktopHeight();
	*fontWidth = 0;
	*fontHeight = 0;
	if (c46_d28c88)
	{
		for (int current = center.size() - 1; current >= 0; current--)
		{
			if (center[current] * c46_ba6aa4[c46_cebd5c] <= adj && center[current] / 2 * c46_ba6ab0[c46_cebd5c] <= col)
			{
				*fontWidth = center[current];
				break;
			}
		}
	}
	else
	{
		for (int cols = center.size() - 1; cols >= 0; cols--)
		{
			if (center[cols] * c46_ba6aa4[c46_cebd5c] < adj && center[cols] / 2 * c46_ba6ab0[c46_cebd5c] < col)
			{
				*fontWidth = center[cols];
				break;
			}
		}
	}
	if (*fontWidth == 0)
		logFatal("rexFastResize()","No fonts fit in desktop");
	*fontHeight = *fontWidth / 2;
	if (c46_d28ca4 == 0 || c46_d28ca8 == 0)
	{
		c46_d28ca8 = adj / *fontWidth - c46_ba6aa4[c46_cebd5c] + c46_ba6ac8[c46_cebd5c];
		c46_cefab0 = c46_d28ca8;
		c46_d28ca4 = (col / *fontHeight - c46_ba6ab0[c46_cebd5c]) / 2 + 50;
		c46_cefaac = c46_d28ca4;
		logMessage("Setting map dimensions (AUTO): " + intToString(c46_cefaac) + "x" + intToString(c46_cefab0));
		if (!c46_d28c88)
		{
			c46_cefab0 -= 2;
			c46_d28ca8 -= 2;
			c46_cefaac -= 2;
			c46_d28ca4 -= 2;
			logMessage("Reducing AUTO map dimensions for windowed mode: " + intToString(c46_cefaac) + "x" + intToString(c46_cefab0));
		}
	}
	else
	{
		c46_cefab0 = c46_d28ca8;
		c46_cefaac = c46_d28ca4;
		logMessage("Setting map dimensions: " + intToString(c46_cefaac) + "x" + intToString(c46_cefab0));
	}
	OpB_updateFontScale_446320();
	*rootWidth = c46_cefab4 * c46_caf128 + 60;
	*rootHeight = (c46_cebd5c == 2 ? 1 : 10) + c46_cefab8 * c46_caf12c;
	logMessage("Setting root dimensions: " + intToString(*rootWidth) + "x" + intToString(*rootHeight));
	c46_cefa64->end(2);
}
