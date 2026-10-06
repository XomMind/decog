// op_v3d_gallery: CGallery* consoles (0x7d5cf0-0x7d7200), Beta 17.1.
#include "op_v3d.h"

extern unsigned int tickCount;	// 0xcaed20

struct OpV3d_ItemObj	// NOTE: placeholder name
{
	int getType_457820();	// NOTE: placeholder name (folded getter)
};
struct OpV3d_ItemHandle	// NOTE: placeholder name
{
	int ID;
	OpV3d_ItemObj *operator->() const;	// 0x9b65b0
};

class OpV3d_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	OpV3d_ItemHandle createD(int *data);	// 0x7932b0
};
extern OpV3d_Factory *opv3d_factory;	// NOTE: placeholder name (0xcefaa8)

class CInfo : public Console
{
public:
	CInfo(XConsole *parent, bool flag, int layer);
	OpV3d_ItemHandle getUnknown9c();	// NOTE: placeholder name
	void unknown8b4500(HEntity a, OpV3d_ItemHandle b, HEntity c, const Pos &pos, int mode, bool e);	// NOTE: placeholder name

	char pad6c[0xfc - 0x6c];
};
extern CInfo *opv3d_cec124;	// NOTE: placeholder name
extern XConsole *opv3d_cec034;	// NOTE: placeholder name

class CGallery : public Console
{
public:
	char getKey(int index);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name (folded getter 0x45a760)
	int getTick_45a760();	// NOTE: placeholder name (folded getter)
};
extern CGallery *opv3d_cec040;	// NOTE: placeholder name
extern vector<int*> opv3d_d25790;	// NOTE: placeholder name
extern vector<int*> opv3d_d2d1c4;	// NOTE: placeholder name

class CGalleryInfoButton : public Console
{
public:
	virtual bool input(XEvent *event);

	CGallery *getParentGallery();	// NOTE: placeholder name (folded +4 getter, 0x9b8f00)
};

bool CGalleryInfoButton::input(XEvent *event)
{
	switch (event->type)
	{
		case 0x26:
		{
			if (tickCount >= opv3d_cec040->getTick_45a760() + 1000)
			{
				if (opv3d_d25790[getParentGallery()->unknown6c])
				{
					if (!opv3d_cec124)
					{
						opv3d_cec124 = new CInfo(opv3d_cec034,false,20);
					}
					else
					{
						if (!opv3d_cec124->getUnknown9c().operator->() || opv3d_cec124->getUnknown9c()->getType_457820() == getParentGallery()->unknown6c)
							return false;
					}
					opv3d_cec124->unknown8b4500(HEntity(),opv3d_factory->createD(opv3d_d2d1c4[getParentGallery()->unknown6c]),HEntity(),Pos(-1),6,true);
				}
			}
			return true;
		}
	}
	return false;
}
