// protobuf 3.5.1 ArenaStringPtr::CreateInstanceNoArena, emitted with NDEBUG.
// NOTE: private wrapper name, real one-pointer ArenaStringPtr layout.
#define NDEBUG
#include <string>
#include "google/protobuf/stubs/logging.h"
struct LA2ArenaString {
 std::string *ptr_;
 __declspec(noinline) void create449ac0(const std::string *initial_value);
};
void LA2ArenaString::create449ac0(const std::string *initial_value) {
#line 311 "C:\\_\\_RL\\Protobuffer\\protobuf-3.5.1\\src\\google/protobuf/arenastring.h"
 GOOGLE_DCHECK(initial_value != 0);
 ptr_=new std::string(*initial_value);
}
