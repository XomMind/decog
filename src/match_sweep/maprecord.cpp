// Partial MapRecord layout recovered from Beta 17.1, 0x6c1a90.
// NOTE: field and unknown method names below are placeholders.
#include <string>
#include "../engine/xcolor.h"
using namespace std;
void logError(string location, string message);
class Item
{
public:
	int sweepAscii();
	int unknown457a70();
	XColor *sweepColor(bool known);
	int sweepType();
	int sweepCachedValue();
	int unknown457ca0();
	int sweepCategory();
	int sweepStatus();
};
class HItem
{
	int ID;
public:
	Item *operator->() const;
};
class Cell
{
public:
	bool isDoor();
	bool unknown45d700();
	HItem getItem();
};
extern XColor sweepItemBackground;
extern int sweepCurrentTurn;
struct MapRecord
{
	int ascii;
	int alternateAscii;
	XColor foreground;
	XColor background;
	int type;
	int cachedValue;
	int quantity;
	int category;
	int status;
	int turn;
	void updateItem(Cell *cell);
};
void MapRecord::updateItem(Cell *cell)
{
	if (cell->isDoor())
	{
		logError("MapRecord::updateItem()","found trap!");
		return;
	}
	if (!cell->unknown45d700())
	{
		logError("MapRecord::updateItem()","no item");
		return;
	}
	HItem item = cell->getItem();
	ascii = item->sweepAscii();
	alternateAscii = item->unknown457a70();
	foreground = *item->sweepColor(false);
	background = sweepItemBackground;
	type = item->sweepType();
	cachedValue = item->sweepCachedValue();
	quantity = item->unknown457ca0();
	category = item->sweepCategory();
	status = item->sweepStatus();
	turn = sweepCurrentTurn;
}
