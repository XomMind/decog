#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	bool contains_40c190(int value);	// NOTE: placeholder name (0x40c190)
	void set_409ff0(int value);	// NOTE: placeholder name (0x409ff0)
};

struct OpT3d_MapRecord	// NOTE: placeholder name
{
	char pad00[0x44];
	int ID;
	char pad48[8];
	int depth;
	char pad54[0xd4];
	int unknown128;
	char pad12c[0x10c];
	bool unknown238;
};
extern vector<OpT3d_MapRecord*> opT3d_records;	// NOTE: placeholder name (0xd2d1c4)

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	void add(T value, int weight);	// 0x9ba310
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
};

void OpT3d_unknown684d00(OpR5h_WL<int> *list, int id, Point range, bool flag)	// NOTE: placeholder name
{
	do
	{
		for (unsigned int i = 0; i < opT3d_records.size(); i++)
		{
			if (opT3d_records[i]->ID == id && range.contains_40c190(opT3d_records[i]->depth) && opT3d_records[i]->unknown238 && (!flag || opT3d_records[i]->unknown128 == 3))
				list->add(i,1);
		}
		range.set_409ff0(range.x - 1);
	} while (!list->size() && range.x > 0);
}
