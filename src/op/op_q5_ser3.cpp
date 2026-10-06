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

struct OpQ5_U9d7390
{
	int pad;
	string name;
};

struct OpQ5_U9d7530
{
	int pad;
	string name;
};

struct OpQ5_U9d7710
{
	int pad;
	string name;
};

struct OpQ5_U9d7be0
{
	int pad;
	string name;
};

struct OpQ5_U9d7de0
{
	int pad;
	string name;
};

struct OpQ5_U9db510
{
	int pad;
	string name;
};

struct OpQ5_U9db6a0
{
	int pad;
	string name;
};

struct OpQ5_U9dba30
{
	int pad;
	string name;
};

template bool OpQ5_findByName<OpQ5_U9d7390>(vector<OpQ5_U9d7390*> &v, string &name, OpQ5_U9d7390 *&result);
template bool OpQ5_findByName<OpQ5_U9d7530>(vector<OpQ5_U9d7530*> &v, string &name, OpQ5_U9d7530 *&result);
template bool OpQ5_findByName<OpQ5_U9d7710>(vector<OpQ5_U9d7710*> &v, string &name, OpQ5_U9d7710 *&result);
template bool OpQ5_findByName<OpQ5_U9d7be0>(vector<OpQ5_U9d7be0*> &v, string &name, OpQ5_U9d7be0 *&result);
template bool OpQ5_findByName<OpQ5_U9d7de0>(vector<OpQ5_U9d7de0*> &v, string &name, OpQ5_U9d7de0 *&result);
template bool OpQ5_findByName<OpQ5_U9db510>(vector<OpQ5_U9db510*> &v, string &name, OpQ5_U9db510 *&result);
template bool OpQ5_findByName<OpQ5_U9db6a0>(vector<OpQ5_U9db6a0*> &v, string &name, OpQ5_U9db6a0 *&result);
template bool OpQ5_findByName<OpQ5_U9dba30>(vector<OpQ5_U9dba30*> &v, string &name, OpQ5_U9dba30 *&result);
