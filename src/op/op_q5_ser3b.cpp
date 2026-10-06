// op_q5: container/serialization helper template instances (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include "../util/rng.h"
#include "../util/stringutil.h"
using namespace std;

extern RNG rng;	// 0xd30908
void logError(string location, string message);	// NOTE: placeholder name


template <class T> bool OpQ5_findByName(vector<T*> &v, string &name, T *&result)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
		{
			result = v[i];
			return true;
		}
	}
	logError("object #" + intToString(rng.rangeInt(10000,99999)),name);
	result = NULL;
	return false;
}

struct OpQ5_U9d7a40
{
	char pad[8];
	string name;
};

template bool OpQ5_findByName<OpQ5_U9d7a40>(vector<OpQ5_U9d7a40*> &v, string &name, OpQ5_U9d7a40 *&result);
