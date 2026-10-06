// References std::string template members laid out in op_e's range (0x9af170-0x9aff60) so
//	LTCG emits them (they are only instantiated where used).
#include <string>
using namespace std;

void opE_useStringMembers(string &s, const string &t, string::const_iterator it)	// NOTE: placeholder name
{
	string a(3,'x');
	s = string("y");
	s = "z";
	s.assign(2,'c');
	s.insert(it,'c');
	s.erase(it);
	s.replace(0,1,t);
	s.replace(it,it,t);
	s.pop_back();
	s.back();
	s.swap(a);
	s.find(t,0);
	s.find("a",0);
	s.rfind(t,0);
	s.rfind("a",0);
	s.rfind('a',0);
	s.find_first_of('a',0);
	s.find_last_not_of('a',0);
	s.substr(0,1);
}
