#include "penetrationrollpool.h"
#include "../util/rng.h"
#include "../util/stringutil.h"

extern RNG rng;
void logError(std::string location, std::string message);
template <typename T>
void removeVectorElement(std::vector<T> &values, int index)
{
	values.erase(values.begin()+index);
}

void PenetrationRollPool::initialize()
{
	values.clear();
	while (values.size() < 25)
	{
		int value = rng.rangeInt(1,100);
		values.push_back(value);
	}
}

int PenetrationRollPool::peekValue(unsigned int index)
{
	if (index >= values.size())
	{
		logError("PenetrationRollPool::peekValue()", "Peeking too far ahead (" + intToString(index) + "), PENETRATION_ROLL_POOL_SIZE too small?");
		return 0;
	}
	return values[index];
}

int PenetrationRollPool::nextValue()
{
	int value = values[0];
	removeVectorElement(values,0);
	int roll = rng.rangeInt(1,100);
	values.push_back(roll);
	return value;
}
