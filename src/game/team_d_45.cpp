// team_d_45: EntityAI::AllyData::checkCapable (0x57f1b0).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
using namespace std;

class Entity;

class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};

class HItem
{
	int ID;
public:
	bool isValid() const;
};

struct AIState45	// NOTE: placeholder name and layout
{
	char	pad000[0xd0];
	int		unknownd0;	// NOTE: placeholder name
};

struct EntityData45	// NOTE: placeholder name and layout
{
	char	pad000[0x15c];
	bool	unknown15c;	// NOTE: placeholder name
};

class Entity
{
public:
	int getTarget();				// 0x45a760
	int getFaction();				// 0x45a2c0
	bool unknown5d5520(int a);		// NOTE: placeholder name
	bool unknown5d5460(int a);		// NOTE: placeholder name
	bool unknown5d55e0();			// NOTE: placeholder name
	AIState45 *getAI();				// 0x45b590
	int unknown5c8e20(int a);		// NOTE: placeholder name
	EntityData45 *getData();		// NOTE: placeholder name (folded getter 0x9b4350)
	bool isXomCandidate();			// 0x5d51a0
	HItem unknown5d2380(int slot);	// NOTE: placeholder name
};

extern string robotClassNames45_d2f798[];	// NOTE: placeholder name
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

class EntityAI
{
public:
	struct AllyData
	{
		bool capable;	// NOTE: placeholder name

		void checkCapable(HEntity ally);
	};
};

void EntityAI::AllyData::checkCapable(HEntity ally)
{
	if (ally->getTarget())
	{
		capable = false;
		return;
	}
	switch (ally->getFaction())
	{
	case 1:
		capable = true;
		break;
	case 2:
		capable = ally->unknown5d5520(0);
		break;
	case 3:
		capable = ally->unknown5d5460(0);
		break;
	case 4:
		capable = true;
		break;
	case 5:
		capable = true;
		break;
	case 6:
		capable = true;
		break;
	case 7:
		capable = ally->unknown5d55e0();
		break;
	case 8:
		capable = ally->getAI()->unknownd0 > 0 || ally->unknown5c8e20(0);
		break;
	case 9:
		capable = true;
		break;
	case 10:
		capable = ally->getData()->unknown15c ? ally->isXomCandidate() : true;
		break;
	case 11:
		capable = ally->isXomCandidate();
		break;
	case 12:
		capable = true;
		break;
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		capable = ally->isXomCandidate();
		break;
	case 19:
		capable = ally->unknown5d2380(0x46).isValid() || ally->unknown5d2380(0x47).isValid();
		break;
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
		capable = ally->isXomCandidate();
		break;
	case 35:
		capable = ally->unknown5d5520(0);
		break;
	case 37:
	case 38:
		capable = ally->isXomCandidate();
		break;
	case 39:
		capable = true;
		break;
	case 40:
	case 41:
	case 42:
		capable = ally->isXomCandidate();
		break;
	case 43:
		capable = true;
		break;
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
		capable = ally->isXomCandidate();
		break;
	case 49:
		capable = true;
		break;
	case 50:
	case 51:
	case 52:
		capable = ally->isXomCandidate();
		break;
	case 53:
		capable = true;
		break;
	case 54:
		capable = true;
		break;
	case 55:
		capable = true;
		break;
	case 56:
		capable = true;
		break;
	case 57:
		capable = true;
		break;
	case 59:
		capable = true;
		break;
	case 58:
	case 60:
	case 61:
	case 62:
	case 63:
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 69:
	case 70:
	case 71:
		capable = ally->isXomCandidate();
		break;
	case 72:
		capable = true;
		break;
	case 73:
		capable = ally->isXomCandidate();
		break;
	case 74:
	case 75:
	case 76:
	case 77:
	case 78:
	case 79:
	case 80:
	case 81:
	case 82:
	case 83:
	case 84:
	case 85:
	case 86:
	case 87:
	case 88:
	case 89:
	case 90:
	case 91:
	case 92:
	case 93:
	case 94:
	case 95:
	case 96:
		capable = ally->isXomCandidate();
		break;
	default:
		if (true)
		{
			logError("EntityAI::AllyData::checkCapable()","unknown class: " + robotClassNames45_d2f798[ally->getFaction()]);
			capable = true;
		}
		break;
	}
}
