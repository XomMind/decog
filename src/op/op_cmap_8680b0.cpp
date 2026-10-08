// op_cmap_8680b0: draws the intel markers on the map view, then edge indicators for off-screen ones (COGMIND.exe Beta 17.1).
// NOTE: placeholder names/layouts throughout; the edge placement mirrors op_d40_86f9c0.cpp.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor() throw();
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	XColor &operator*=(float value);
	void setHSV(float h, float s, float v);
};

struct Pos	// NOTE: placeholder layout
{
	int x;
	int y;
	Pos(int x_, int y_);
};

struct CM86_Point	// NOTE: placeholder name (map point)
{
	int x;
	int y;
	CM86_Point();	// 0x453b40
	CM86_Point &operator=(const CM86_Point &p);	// 0x46ca50
	CM86_Point operator+(const CM86_Point &p) const;	// 0x409b60
	CM86_Point &operator+=(const CM86_Point &p);	// 0x409a30
};

struct CM86_Area	// NOTE: placeholder name
{
	CM86_Point min;
	CM86_Point max;
	CM86_Area();	// 0x40b100
	bool contains(const CM86_Point &p);	// 0x40b750
};

struct CM86_Marker	// NOTE: placeholder layout
{
	int pad00;
	int type;
	CM86_Point pos;
	int turn;
	int sub;
};

struct CM86_HMarker	// NOTE: placeholder name
{
	unsigned int id;
	CM86_HMarker() throw();
	CM86_Marker *operator->() const;	// 0x9b7cd0
};

struct CM86_HEntity	// NOTE: placeholder name
{
	unsigned int id;
	CM86_HEntity() throw();
	bool isValid() const;	// 0x9b7230
};

class CM86_Cell	// NOTE: placeholder name
{
public:
	CM86_HEntity getEntity();	// 0x45d250
};

template <class T> struct CM86_Grid	// NOTE: placeholder name
{
	int width;
	int height;
	T *data;
	T *at(int x, int y);
	T *atPoint(CM86_Point &p);
};

struct CM86_Track	// NOTE: placeholder layout
{
	int type;
	char pad04[0x14 - 0x04];
};

class CM86_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	char pad000[0x69c];
	CM86_Grid<int> grid;
	char pad6a8[0x740 - 0x6a8];
	CM86_Grid<CM86_Track> tracks;
	int trackType;
	vector<vector<CM86_HMarker> > *unknown463ec0();
	bool unknown463160(const CM86_Point &p);
	bool unknown4648d0(const CM86_Point &p);
	bool isVisible(const CM86_Point &p);	// 0x4631c0
	int getTurn();	// 0x464270
};

class CM86_Intel	// NOTE: placeholder name (object at 0xcec0cc)
{
public:
	bool isSet(int index);	// 0x48f8d0
	bool *getFieldAddress();	// 0x48f900
};

struct CM86_ItemType	// NOTE: placeholder layout
{
	char pad00[0x44];
	int slot;
	char pad48[0x50 - 0x48];
	int colorIndex;
	char pad54[0x78 - 0x54];
	int ascii;
};

struct CM86_Slot	// NOTE: placeholder layout
{
	int ascii;
	XColor color;
};

struct CM86_SlotColor	// NOTE: placeholder layout (CM86_Slot viewed from +4)
{
	XColor color;
	char pad03[5];
};

class CM86_Effect	// NOTE: placeholder name
{
public:
	void init_50de10();
};

class CM86_Engine	// NOTE: placeholder name (object at 0xcefc64)
{
public:
	CM86_Effect *unknown50fb50(CM86_Engine *engine, int id, const Pos &pos, const CM86_Point *a, const Pos *b, const CM86_Point *c, int layer);
};

class XConsole
{
public:
	bool isHidden();
	int getHeight();
	Pos getPos();
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, int flag);
};

class CMap : public XConsole	// NOTE: placeholder layout
{
public:
	char base[0x6c];
	CM86_Point offset;
	char pad74[0x36c - 0x74];
	XConsole *sub36c;
	char pad370[0x7a8 - 0x370];
	int field7a8;
	int width_44b0d0();
	void unknown8051f0(CM86_Point *min, CM86_Point *max);
	void unknown8680b0();
};

bool OpU8a_lookup1(const string &name, int *index);
float opR1d_4371a0(float a, float b, int period, int offset);
bool blink_437320(unsigned int period);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
int opR5a_findFree(int start, int end, vector<int> &used, bool forward);
void cm86_eraseStep(vector<CM86_HMarker> &v, int &index);	// NOTE: placeholder name (0x9d6440)
void OpX5_fillChars(bool *p, unsigned int count, char value);

extern CM86_World *cm86_world;	// NOTE: placeholder name (0xcefc4c)
extern CM86_Intel *cm86_intel;	// NOTE: placeholder name (0xcec0cc)
extern CM86_Engine *cm86_engine;	// NOTE: placeholder name (0xcefc64)
extern XConsole *cm86_msgLog;	// NOTE: placeholder name (0xcec0f4)
extern CM86_Grid<CM86_Cell *> cm86_cells;	// NOTE: placeholder name (0xcfd44c)
extern vector<CM86_ItemType *> cm86_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern CM86_Slot cm86_slots[];	// NOTE: placeholder name (0xd01618)
extern CM86_SlotColor cm86_slotColors[];	// NOTE: placeholder name (0xd0161c)
extern XColor cm86_itemColors[];	// NOTE: placeholder name (0xd216f8)
extern XColor cm86_intelColors[];	// NOTE: placeholder name (0xcfe5a8)
extern const char cm86_intelChars[];	// NOTE: placeholder name (0xb9e258)
extern const char cm86_subChars[];	// NOTE: placeholder name (0xb99c08)
extern float cm86_subHues[][3];	// NOTE: placeholder name (0xb9e678)
extern int cm86_fadeTurns[];	// NOTE: placeholder name (0xcaf250)
extern XColor *cm86_white;	// NOTE: placeholder name (0xcfabbc)
extern CM86_Point cm86_none;	// NOTE: placeholder name (0xcfbec0)
extern bool cm86_asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern bool cm86_flagD28def;	// NOTE: placeholder name (0xd28def)
extern bool cm86_bigFont;	// NOTE: placeholder name (0xd28d15)
extern int cm86_mapWidth;	// NOTE: placeholder name (0xcf27f4)
extern int cm86_mapHeight;	// NOTE: placeholder name (0xcf27f8)
extern const float cm86_pulseLow;	// NOTE: placeholder name (0xba6be8)
extern const float cm86_pulseHigh;	// NOTE: placeholder name (0xba6bec)
extern const float cm86_fadeScale;	// NOTE: placeholder name (0xb9e478)

#define CM86_STYLE(TYPE, REC) \
	switch (TYPE) \
	{ \
	case 0: \
		subtype = REC->sub; \
		ch = cm86_subChars[subtype]; \
		bgColor.setHSV(cm86_subHues[subtype][0],cm86_subHues[subtype][1],cm86_subHues[subtype][2]); \
		break; \
	case 14: \
	case 15: \
		ch = cm86_asciiEnabled ? cm86_itemTypes[REC->sub]->ascii : cm86_slots[cm86_itemTypes[REC->sub]->slot].ascii; \
		bgColor = cm86_asciiEnabled && cm86_flagD28def ? cm86_itemColors[cm86_itemTypes[REC->sub]->colorIndex] : cm86_slotColors[cm86_itemTypes[REC->sub]->slot].color; \
		break; \
	default: \
		ch = cm86_intelChars[TYPE]; \
		bgColor = cm86_intelColors[TYPE]; \
		break; \
	}

#define CM86_EFFECT(DX, DY) \
	cm86_engine->unknown50fb50(cm86_engine,effect,Pos(px + DX,py + DY),&cm86_none,&Pos(px,py),&cm86_none,9)->init_50de10();

#define CM86_PUT(X, Y, TYPE, REC, DIR) \
	{ \
		int px = X; \
		if (sub36c && !sub36c->isHidden() && X == width_44b0d0() - 1 && OpT8b_Fn9daf80(1,Y,sub36c->getHeight())) \
			px = sub36c->getPos().x - 1; \
		int py = Y; \
		if (Y == 0) \
		{ \
			if (field7a8) \
				py++; \
			if (!cm86_msgLog->isHidden()) \
				py++; \
		} \
		charColor = *cm86_white; \
		if (cm86_fadeTurns[TYPE] && cm86_world->getTurn() - REC->turn > cm86_fadeTurns[TYPE]) \
		{ \
			charColor *= cm86_fadeScale; \
			bgColor *= cm86_fadeScale; \
		} \
		if (TYPE == 15) \
			charColor *= fgAlpha; \
		bgColor *= dim; \
		putChar_418150(px,py,ch,charColor,bgColor,1); \
		if (newMarkers[TYPE] && effect) \
		{ \
			switch (DIR) \
			{ \
				break; \
			case 0: \
				CM86_EFFECT(0, -3) \
				break; \
			case 1: \
				CM86_EFFECT(3, 0) \
				break; \
			case 2: \
				CM86_EFFECT(0, 3) \
				break; \
			case 3: \
				CM86_EFFECT(-3, 0) \
				break; \
			} \
		} \
	}

#define REC hidden[i]
#define TYPE hidden[i]->type

#define CM86_CORNER(FROM, TO, LIST, FWD, X, Y, DIR) \
	slot = opR5a_findFree(FROM,TO,LIST,FWD); \
	if (slot != -1) \
	{ \
		CM86_STYLE(TYPE, REC) \
		CM86_PUT(X, Y, TYPE, REC, DIR) \
		LIST.push_back(slot); \
	} \
	cm86_eraseStep(hidden,i);

#define CM86_EDGE(X, Y, DIR) \
	{ \
		CM86_STYLE(TYPE, REC) \
		CM86_PUT(X, Y, TYPE, REC, DIR) \
		list.push_back(slot); \
	}

void CMap::unknown8680b0()
{
	vector<vector<CM86_HMarker> > *markerArrays = cm86_world->unknown463ec0();
	CM86_Area view;
	unknown8051f0(&view.min,&view.max);
	CM86_Grid<int> *fovGrid = &cm86_world->grid;
	CM86_Grid<CM86_Track> *trackMap = &cm86_world->tracks;
	int trackType = cm86_world->trackType;
	CM86_Point xy;
	XColor charColor;
	int ch;
	XColor bgColor;
	float dim = opR1d_4371a0(cm86_pulseLow,cm86_pulseHigh,2000,0);
	float fgAlpha = opR1d_4371a0(cm86_pulseLow,cm86_pulseHigh,2000,1000);
	bool *newMarkers = cm86_intel->getFieldAddress();
	int effect;
	OpU8a_lookup1("CMap_Intel_Marker_New_E",&effect);
	vector<CM86_HMarker> hidden;
	int subtype;
	int slot;
	for (int i = 0; i < markerArrays->size(); i++)
	{
		if (!cm86_intel->isSet(i))
			continue;
		vector<CM86_HMarker> &layer = (*markerArrays)[i];
		for (int j = 0; j < layer.size(); j++)
		{
			xy = layer[j]->pos;
			if (view.contains(xy))
			{
				if (i == 18)
				{
				}
				else
				{
					if (i == 0 && cm86_world->unknown463160(xy))
					{
						if (cm86_world->unknown4648d0(xy))
							cm86_eraseStep(layer,j);
						continue;
					}
					if (cm86_world->isVisible(xy))
					{
						cm86_eraseStep(layer,j);
						continue;
					}
				}
				if (((*fovGrid->atPoint(xy) && (*cm86_cells.atPoint(xy))->getEntity().isValid()) || trackMap->atPoint(xy)->type == trackType) && blink_437320(1000))
					continue;
				xy += offset;
				CM86_STYLE(i, layer[j])
				CM86_PUT(xy.x, xy.y, i, layer[j], -1)
			}
			else
				hidden.push_back(layer[j]);
		}
	}
	CM86_Point screenPos;
	vector<int> usedTop;
	usedTop.push_back(0);
	usedTop.push_back(width_44b0d0() - 1);
	vector<int> bottom;
	bottom.push_back(0);
	bottom.push_back(width_44b0d0() - 1);
	vector<int> left;
	left.push_back(0);
	left.push_back(getHeight() - 1);
	vector<int> rights;
	rights.push_back(0);
	bottom.push_back(getHeight() - 1);
	if (cm86_bigFont)
	{
		CM86_Grid<int> *fovGrid = &cm86_world->grid;
		CM86_Grid<CM86_Track> *trackMap = &cm86_world->tracks;
		for (int x = view.min.x, scrX = view.min.x + offset.x; x <= view.max.x; x++, scrX++)
		{
			if ((*fovGrid->at(x,view.min.y) && (*cm86_cells.at(x,view.min.y))->getEntity().isValid()) || trackMap->at(x,view.min.y)->type == trackType)
				usedTop.push_back(scrX);
			if ((*fovGrid->at(x,view.max.y) && (*cm86_cells.at(x,view.max.y))->getEntity().isValid()) || trackMap->at(x,view.max.y)->type == trackType)
				bottom.push_back(scrX);
		}
		for (int y = view.min.y, scrY = view.min.y + offset.y; y <= view.max.y; y++, scrY++)
		{
			if ((*fovGrid->at(view.min.x,y) && (*cm86_cells.at(view.min.x,y))->getEntity().isValid()) || trackMap->at(view.min.x,y)->type == trackType)
				left.push_back(scrY);
			if ((*fovGrid->at(view.max.x,y) && (*cm86_cells.at(view.max.x,y))->getEntity().isValid()) || trackMap->at(view.max.x,y)->type == trackType)
				rights.push_back(scrY);
		}
	}
	for (int i = 0; i < hidden.size(); i++)
	{
		screenPos = hidden[i]->pos + offset;
		if (screenPos.x < 0)
		{
			if (screenPos.y < 0)
			{
				if (screenPos.x < screenPos.y)
				{
					CM86_CORNER(1, cm86_mapHeight - 2, left, true, 0, slot, 1)
				}
				else
				{
					CM86_CORNER(1, cm86_mapWidth - 2, usedTop, true, slot, 0, 2)
				}
			}
			else if (screenPos.y >= cm86_mapHeight)
			{
				if (-screenPos.x > screenPos.y - cm86_mapHeight)
				{
					CM86_CORNER(cm86_mapHeight - 2, 1, left, false, 0, slot, 1)
				}
				else
				{
					CM86_CORNER(1, cm86_mapWidth - 2, bottom, true, slot, cm86_mapHeight - 1, 0)
				}
			}
		}
		else if (screenPos.x >= cm86_mapWidth)
		{
			if (screenPos.y < 0)
			{
				if (-(screenPos.x - cm86_mapWidth) < screenPos.y)
				{
					CM86_CORNER(1, cm86_mapHeight - 2, rights, true, cm86_mapWidth - 1, slot, 3)
				}
				else
				{
					CM86_CORNER(cm86_mapWidth - 2, 1, usedTop, false, slot, 0, 2)
				}
			}
			else if (screenPos.y >= cm86_mapHeight)
			{
				if (screenPos.x - cm86_mapWidth > screenPos.y - cm86_mapHeight)
				{
					CM86_CORNER(cm86_mapHeight - 2, 1, rights, false, cm86_mapWidth - 1, slot, 3)
				}
				else
				{
					CM86_CORNER(cm86_mapWidth - 2, 1, bottom, false, slot, cm86_mapHeight - 1, 0)
				}
			}
		}
	}
	for (int i = 0; i < hidden.size(); i++)
	{
		screenPos = hidden[i]->pos + offset;
		if (screenPos.x < 0 || screenPos.x >= cm86_mapWidth)
		{
			bool isLeft = screenPos.x < 0;
			vector<int> &list = isLeft ? left : rights;
			int col = isLeft ? 0 : cm86_mapWidth - 1;
			slot = opR5a_findFree(screenPos.y,cm86_mapHeight - 2,list,true);
			if (slot != -1)
				CM86_EDGE(col, slot, isLeft ? 1 : 3)
			else
			{
				slot = opR5a_findFree(screenPos.y,1,list,false);
				if (slot != -1)
					CM86_EDGE(col, slot, isLeft ? 1 : 3)
			}
		}
		else
		{
			bool upper = screenPos.y < 0;
			vector<int> &list = upper ? usedTop : bottom;
			int row = upper ? 0 : cm86_mapHeight - 1;
			slot = opR5a_findFree(screenPos.x,cm86_mapWidth - 2,list,true);
			if (slot != -1)
				CM86_EDGE(slot, row, upper ? 2 : 0)
			else
			{
				slot = opR5a_findFree(screenPos.x,1,list,false);
				if (slot != -1)
					CM86_EDGE(slot, row, upper ? 2 : 0)
			}
		}
	}
	OpX5_fillChars(newMarkers,20,0);
}
