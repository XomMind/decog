#ifndef PENETRATIONROLLPOOL_H
#define PENETRATIONROLLPOOL_H

#include <vector>
#include <string>

// Recovered from 0x460510-0x4606c6. Member names other than peekValue
// are placeholders; this pool queues 25 future penetration percentile rolls.
class PenetrationRollPool
{
	std::vector<int> values;

public:
	void initialize();
	int peekValue(unsigned int index);
	int nextValue();
};

#endif
