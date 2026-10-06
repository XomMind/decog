#include "stringutil.h"
#include <sstream>

std::string intToString(int value)
{
	std::ostringstream stream;
	stream << value;
	return stream.str();
}
