// op_s3_e: Group / turn-queue / record functions (0x671000-0x682000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member/method names are placeholders unless named in config/.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <algorithm>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_) throw();
	Point(const Point &p);
	Point &operator=(const Point &p);
};

class Entity;
class Item;
class Group;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity() throw();
	bool isValid() const;
	bool operator==(HEntity other) const;
	Entity *operator->() const;
	void read(istream &stream);		// NOTE: placeholder name (0x9cfaf0)
	void write(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
};

class EntityAI
{
public:
	bool unknown5b3890(HEntity e, int maxValue);	// NOTE: placeholder name
	void adjustTargetForOrder3(HEntity source, HEntity target);
	void adjustTargetForOrder4(HEntity source, HEntity target);
};

class Entity
{
public:
	EntityAI *getAI();	// NOTE: placeholder name (0x45b590)
	int takeTurn();
};

class Group	// NOTE: placeholder name
{
public:
	int					unknown00;
	int					unknown04;
	int					unknown08;
	vector<HEntity>		members;

	void unknown671940(HEntity source, int value);	// NOTE: placeholder name
	void unknown671f00(HEntity source, HEntity target);	// NOTE: placeholder name
	void unknown671f80(HEntity source, HEntity target);	// NOTE: placeholder name
};

void Group::unknown671940(HEntity source, int value)
{
	unsigned int i;
	for (i = 0; i < members.size(); i++)
	{
		if (members[i]->getAI())
			members[i]->getAI()->unknown5b3890(source, value);
	}
}

void Group::unknown671f00(HEntity source, HEntity target)
{
	unsigned int i;
	for (i = 0; i < members.size(); i++)
	{
		if (members[i]->getAI())
			members[i]->getAI()->adjustTargetForOrder3(source, target);
	}
}

void Group::unknown671f80(HEntity source, HEntity target)
{
	unsigned int i;
	for (i = 0; i < members.size(); i++)
	{
		if (members[i]->getAI())
			members[i]->getAI()->adjustTargetForOrder4(source, target);
	}
}

//==================================================================
// turn queue
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480, NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
template <class T> void OpS3e_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9da940)
template <class T> void OpS3e_moveElement(vector<T> &v, int from, int to);	// NOTE: placeholder name (0x9da1f0)

class HItem
{
	int	ID;
public:
	HItem() throw();
	Item *operator->() const;	// 0x9b65b0
	bool operator==(HItem other) const;
	void read(istream &stream);		// NOTE: placeholder name (0x9cfaf0)
	void write(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
};

class Item
{
public:
	int unknown57cdd0();	// NOTE: placeholder name
};

class BS
{
public:
	void turnUpdate_74e750();
	void unknown464710(int value);	// NOTE: placeholder name
};

extern BS *world;	// NOTE: placeholder name (0xcefc4c)

struct OpS3e_Counter	// NOTE: placeholder name (ctor 0x45e510 sets the value to 1)
{
	int value;

	OpS3e_Counter() throw();
};

class OpS3e_TurnSlot;

class HTurnClock	// NOTE: placeholder name
{
	int	ID;
public:
	HTurnClock() throw();
	OpS3e_TurnSlot *operator->() const;	// 0x9b73b0
	void read(istream &stream);		// NOTE: placeholder name (0x9cfaf0)
	void write(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
};

class OpS3e_TurnSlot	// NOTE: placeholder name
{
public:
	HTurnClock	handle;
	int			time;
	int			type;
	void		*data;

	OpS3e_TurnSlot(istream &stream);
	void save(ostream &stream);
	bool takeTurn(int *delay);
	void setHandle(HTurnClock h);	// NOTE: placeholder name
};

bool OpS3e_isClockEarlier(const HTurnClock &a, const HTurnClock &b);	// NOTE: placeholder name (0x45e6c0)

struct OpS3e_ClockPool	// NOTE: placeholder name (pool object at 0xd208d4)
{
	HTurnClock add(OpS3e_TurnSlot *slot);
	void remove(HTurnClock h, bool deleteItem);
};

extern OpS3e_ClockPool opS3e_clockPool;	// NOTE: placeholder name (0xd208d4)

void OpS3e_TurnSlot::save(ostream &stream)
{
	handle.write(stream);
	writeBinary(stream,&time);
	writeBinary(stream,&type);
	switch (type)
	{
	case 0:
		writeBinary(stream,(int *)data);
		break;
	case 1:
		((HEntity *)data)->write(stream);
		break;
	case 2:
		((HItem *)data)->write(stream);
		break;
	}
}

OpS3e_TurnSlot::OpS3e_TurnSlot(istream &stream)
{
	handle.read(stream);
	readBinary(stream,&time);
	readBinary(stream,&type);
	switch (type)
	{
	case 0:
		{
			OpS3e_Counter *counter = new OpS3e_Counter();
			data = counter;
			readBinary(stream,(int *)data);
		}
		break;
	case 1:
		{
			HEntity *entity = new HEntity();
			data = entity;
			((HEntity *)data)->read(stream);
		}
		break;
	case 2:
		{
			HItem *item = new HItem();
			data = item;
			((HItem *)data)->read(stream);
		}
		break;
	}
}

bool OpS3e_TurnSlot::takeTurn(int *delay)
{
	switch (type)
	{
	case 0:
		((OpS3e_Counter *)data)->value++;
		*delay = 100;
		world->turnUpdate_74e750();
		return false;
	case 1:
		if (!(*(HEntity *)data).operator->())
			return true;
		*delay = (*(HEntity *)data)->takeTurn();
		return false;
	case 2:
		if (!(*(HItem *)data).operator->())
			return true;
		*delay = (*(HItem *)data)->unknown57cdd0();
		return false;
	}
	return true;
}

class OpS3e_TurnQueue	// NOTE: placeholder name
{
public:
	vector<HTurnClock>	clocks;

	HTurnClock add(OpS3e_TurnSlot *slot, int delay);
	void unknown672450();
	void unknown672580(int index);
	void unknown672700();
	void unknown6727c0(int delta);
	void unknown672800(HEntity entity);
	void unknown6728c0(HEntity entity);
	void unknown672980(HItem item);
	int unknown672a20(HItem item);
	int unknown672ad0(HEntity entity);
	void unknown672b80(HEntity entity, int delta);
};

HTurnClock OpS3e_TurnQueue::add(OpS3e_TurnSlot *slot, int delay)
{
	HTurnClock clock = opS3e_clockPool.add(slot);
	clock->setHandle(clock);
	clock->time = clocks.empty() ? 0 : clocks.front()->time + delay;
	if (clocks.empty() || clock->time >= clocks.back()->time)
	{
		clocks.push_back(clock);
	}
	else
	{
		vector<HTurnClock>::iterator it = lower_bound(clocks.begin(),clocks.end(),clock,OpS3e_isClockEarlier);
		while ((*it)->time == clock->time)
			it++;
		clocks.insert(it,clock);
	}
	return clock;
}

void OpS3e_TurnQueue::unknown672450()
{
	if (clocks.size() > 1 && clocks[0]->time > clocks[1]->time)
	{
		if (clocks[0]->time >= clocks.back()->time)
		{
			OpS3e_moveElement(clocks,0,clocks.size() - 1);
		}
		else
		{
			HTurnClock clock = clocks[0];
			OpS3e_eraseAt(clocks,0);
			vector<HTurnClock>::iterator it = lower_bound(clocks.begin(),clocks.end(),clock,OpS3e_isClockEarlier);
			while ((*it)->time == clock->time)
				it++;
			clocks.insert(it,clock);
		}
	}
}

void OpS3e_TurnQueue::unknown672580(int index)
{
	if ((index > 1 && clocks[index]->time < clocks[index - 1]->time) || (index < clocks.size() - 1 && clocks[index]->time > clocks[index + 1]->time))
	{
		if (clocks[index]->time >= clocks.back()->time)
		{
			OpS3e_moveElement(clocks,index,clocks.size() - 1);
		}
		else
		{
			HTurnClock clock = clocks[index];
			OpS3e_eraseAt(clocks,index);
			vector<HTurnClock>::iterator it = lower_bound(clocks.begin(),clocks.end(),clock,OpS3e_isClockEarlier);
			while ((*it)->time == clock->time)
				it++;
			clocks.insert(it,clock);
		}
	}
}

void OpS3e_TurnQueue::unknown672700()
{
	if (clocks.empty())
	{
		world->unknown464710(3);
		return;
	}
	int delay = 100;
	if (clocks[0]->takeTurn(&delay))
	{
		opS3e_clockPool.remove(clocks[0],true);
		OpS3e_eraseAt(clocks,0);
		return;
	}
	if (delay == -1)
		return;
	clocks[0]->time += delay;
	unknown672450();
}

void OpS3e_TurnQueue::unknown6727c0(int delta)
{
	clocks[0]->time += delta;
	unknown672450();
}

void OpS3e_TurnQueue::unknown672800(HEntity entity)
{
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 1 && *(HEntity *)clocks[i]->data == entity)
		{
			if (i != 0)
			{
				OpS3e_moveElement(clocks,i,0);
				clocks[0]->time = clocks[1]->time;
			}
			return;
		}
	}
}

void OpS3e_TurnQueue::unknown6728c0(HEntity entity)
{
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 1 && *(HEntity *)clocks[i]->data == entity)
		{
			if (i > 1)
			{
				OpS3e_moveElement(clocks,i,1);
				clocks[1]->time = clocks[2]->time;
			}
			return;
		}
	}
}

void OpS3e_TurnQueue::unknown672980(HItem item)
{
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 2 && *(HItem *)clocks[i]->data == item)
		{
			opS3e_clockPool.remove(clocks[i],true);
			OpS3e_eraseAt(clocks,i);
		}
	}
}

int OpS3e_TurnQueue::unknown672a20(HItem item)
{
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 2 && *(HItem *)clocks[i]->data == item)
			return clocks[0]->time - clocks[i]->time;
	}
	return 0;
}

int OpS3e_TurnQueue::unknown672ad0(HEntity entity)
{
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 1 && *(HEntity *)clocks[i]->data == entity)
			return clocks[0]->time - clocks[i]->time;
	}
	return 0;
}

void OpS3e_TurnQueue::unknown672b80(HEntity entity, int delta)
{
	if (clocks.size() < 2)
		return;
	for (unsigned int i = 0; i < clocks.size(); i++)
	{
		if (clocks[i]->type == 1 && *(HEntity *)clocks[i]->data == entity)
		{
			clocks[i]->time += delta;
			unknown672580(i);
			return;
		}
	}
}
