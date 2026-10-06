// op_r6: explicit std instantiations over real element types (string, int, Point, ...) in 0x9bb000-0xa044d0
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p);
	Point &operator=(const Point &p);
};

template class std::basic_string<char>;
template class std::vector<string>;
template class std::vector<int>;
template class std::vector<unsigned int>;
template class std::vector<char>;
template class std::vector<Point>;
template class std::vector<vector<int> >;
template class std::vector<bool>;
