#include <string>
#include <vector>
#include <algorithm>

typedef bool (*OpS8g_Pred)(const std::string&, const std::string&);	// NOTE: placeholder name

bool OpS8g_Less(const std::string& a, const std::string& b);	// NOTE: placeholder name

void OpS8g_sortStrings(std::vector<std::string>& v)	// NOTE: placeholder name
{
	std::sort(v.begin(), v.end(), OpS8g_Less);
}

void OpS8g_use(std::string* a, std::string* b, OpS8g_Pred p)	// NOTE: placeholder name
{
	std::make_heap(a, b, p);
	std::sort_heap(a, b, p);
	std::pop_heap(a, b, p);
	std::push_heap(a, b, p);
	std::_Insertion_sort(a, b, p);
	std::_Med3(a, a, b, p);
	std::stable_sort(a, b, p);
	std::sort(a, b);
	std::stable_sort(a, b);
	std::partial_sort(a, a, b, p);
	std::partial_sort(a, a, b);
}
