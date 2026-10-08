// NOTE: placeholder wrapper names; retail string operators omit the unused reference return.
#include <string>
struct TeamOct08CharlieString {
 void append9af410(char c);
 void assign9af390(const char *s);
 void append9af3d0(const std::string &s);
};
void TeamOct08CharlieString::append9af410(char c) { reinterpret_cast<std::string *>(this)->append(1u,c); }
void TeamOct08CharlieString::assign9af390(const char *s) { reinterpret_cast<std::string *>(this)->assign(s); }
void TeamOct08CharlieString::append9af3d0(const std::string &s) { reinterpret_cast<std::string *>(this)->append(s); }
