#ifndef DUNGEON_DF_H
#define DUNGEON_DF_H

#include <istream>
#include <vector>
using namespace std;

//==================================================================
// Map position (reconstructed elsewhere; same declaration as src/consoles/xconsole.h)
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();								// (-1,-1)
	Pos(const Pos &pos);
	Pos& operator=(const Pos &pos);
	void move(int dx, int dy);			// NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();								// (0,0,0,0)
	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name
};

// binary save/load helper: in.read((char*)value,sizeof(int))
void readInt(istream &in, int *value);	// NOTE: placeholder name

//==================================================================
// DF: map generator builders (tunnelers dig corridors, roomies dig rooms)
//==================================================================
// Class names are real (RTTI); member and method names are placeholders.
// Directions: 0 = north, 1 = east, 2 = south, 3 = west.

namespace DF
{

// move pos by lateral/forward amounts relative to a facing direction
void shiftPos(Pos &pos, int dir, int lateral, int forward);	// NOTE: placeholder name

//==================================================================
// generator state (only what the builders touch)
//==================================================================

// cell grid the builders dig into, stored by column
class Grid	// NOTE: placeholder name
{
public:
	int		width;
	int		height;
	int*	cells;

	bool inBounds(const Pos &pos);	// NOTE: placeholder name
	int& at(int x, int y);			// NOTE: placeholder name
	int& at(const Pos &pos);		// NOTE: placeholder name
};

struct RoomSettings	// NOTE: placeholder name
{
	int		minArea;		// NOTE: placeholder name
	int		maxArea;		// NOTE: placeholder name
	int		maxCount;		// NOTE: placeholder name
	int		unknown0C[14];
};

struct Settings	// NOTE: placeholder name
{
	int				unknown00;
	int				roomMargin;		// NOTE: placeholder name
	float			maxRoomRatio;	// NOTE: placeholder name
	int				unknown0C[46];
	RoomSettings	rooms[1];		// NOTE: placeholder name, real count unknown
};

struct Room	// NOTE: placeholder name
{
	int				type;
	Rect			rect;
	vector<int>		unknown14;
	int				unknown24;
	vector<int>		unknown28;
	vector<Pos>		unknown38;
	vector<Pos>		unknown48;
	int				unknown58;
	vector<Pos>		unknown5C;
};

class Generator	// NOTE: placeholder name
{
public:
	int		unknown00[16];
	int		turn;			// NOTE: placeholder name
	int		unknown44[13];
	int		roomCount[1];	// NOTE: placeholder name, real count unknown

	int getTurn() { return turn; };	// NOTE: placeholder name
	int getRoomCount(int type) { return roomCount[type]; };	// NOTE: placeholder name
	void addRoomCount(int type) { roomCount[type]++; };	// NOTE: placeholder name
};

extern Generator generator;		// NOTE: placeholder name
extern Settings *settings;		// NOTE: placeholder name
extern Grid grid;				// NOTE: placeholder name
extern vector<Room> rooms;		// NOTE: placeholder name

class Builder
{
public:
	int		delay;		// generator turn on which the builder starts working	// NOTE: placeholder name
	int		age;		// turns worked so far	// NOTE: placeholder name
	int		dir;		// facing direction	// NOTE: placeholder name
	Pos		pos;		// NOTE: placeholder name

	Builder() {};
	Builder(int delay_, int dir_, const Pos &pos_)
		: delay	(delay_)
		, age	(0)
		, dir	(dir_)
		, pos	(pos_)
	{};
	virtual ~Builder() {};

	// returns non-zero once the builder is finished
	virtual int build() = 0;	// NOTE: placeholder name
};

class Tunneler : public Builder
{
public:
	int		startDir;		// NOTE: placeholder name
	int		param1C;		// NOTE: placeholder name
	int		width;			// NOTE: placeholder name
	int		param24;		// NOTE: placeholder name
	int		param28;		// NOTE: placeholder name
	int		param2C;		// NOTE: placeholder name
	int		param30;		// NOTE: placeholder name
	int		param34;		// NOTE: placeholder name
	int		param38;		// NOTE: placeholder name
	int		param3C;		// NOTE: placeholder name
	bool	param40;		// NOTE: placeholder name

	Tunneler() {};
	Tunneler(int delay_, int dir_, const Pos &pos_, int param1C_, int width_, int param24_, int param28_, int param2C_, int param30_, int param34_, int param38_, int param3C_, bool param40_)
		: Builder	(delay_,dir_,pos_)
		, startDir	(dir_)
		, param1C	(param1C_)
		, width		(width_)
		, param24	(param24_)
		, param28	(param28_)
		, param2C	(param2C_)
		, param30	(param30_)
		, param34	(param34_)
		, param38	(param38_)
		, param3C	(param3C_)
		, param40	(param40_)
	{};
	~Tunneler() {};

	void load(istream &in)	// NOTE: placeholder name
	{
		readInt(in,&width);
		readInt(in,&param24);
		readInt(in,&param28);
		readInt(in,&param2C);
		readInt(in,&param30);
		readInt(in,&param34);
		readInt(in,&param38);
	};
	void resetWidth()	// NOTE: placeholder name
	{
		width = 1;
		param24 = 3;
	};
	void setParam38(int param38_)	// NOTE: placeholder name
	{
		param38 = param38_;
	};

	int build();
};

class Roomie : public Builder
{
public:
	int		roomType;		// index into the generator's room settings	// NOTE: placeholder name
	int		param1C;		// NOTE: placeholder name

	Roomie(int delay_, int dir_, const Pos &pos_, int roomType_, int param1C_)
		: Builder	(delay_,dir_,pos_)
		, roomType	(roomType_)
		, param1C	(param1C_)
	{};
	~Roomie() {};

	int build();
	// distance the room can extend ahead of pos and the free space to its left/right
	int measure(const Pos &origin, int width, int *left, int *right, int margin);	// NOTE: placeholder name
};

}

#endif // DUNGEON_DF_H
