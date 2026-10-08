// team_b_63: std::string member bodies and an iterator deref at exe addresses whose natural names are already
// mapped to other (ICF-folded) addresses; distinct placeholder names give each exe copy its own symbol.
#include <string>
using namespace std;

// 0x9c7ed0: const iterator operator* (the exe's copy has an empty do/while from an assertion macro)
struct TeamB_It9c7ed0	// NOTE: placeholder name
{
	const char *ptr;
	const char &operator*() const;
};
const char &TeamB_It9c7ed0::operator*() const
{
	do {} while (0);
	return *this->ptr;
}

struct TeamB_Str : string	// NOTE: placeholder name (copies of basic_string<char> members)
{
	TeamB_Str &assign_9af390(const char *ptr);	// operator=(const char *)
	TeamB_Str &append_9af3d0(const string &right);	// operator+=(const string &)
	TeamB_Str &append_9af410(char ch);	// operator+=(char)
	TeamB_Str &append_9af460(const char *ptr);	// append(const char *)
};

TeamB_Str &TeamB_Str::assign_9af390(const char *ptr)
{
	return (TeamB_Str &)assign(ptr);
}

TeamB_Str &TeamB_Str::append_9af3d0(const string &right)
{
	return (TeamB_Str &)append(right);
}

TeamB_Str &TeamB_Str::append_9af410(char ch)
{
	return (TeamB_Str &)append((size_type)1,ch);
}

TeamB_Str &TeamB_Str::append_9af460(const char *ptr)
{
	return (TeamB_Str &)append(ptr,char_traits<char>::length(ptr));
}
