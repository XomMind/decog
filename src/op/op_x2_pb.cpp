// op_x2_pb: protobuf 3.5.1 ArenaStringPtr::CreateInstanceNoArena (private inline, reached via the usual friend-access trick)
#define NDEBUG
#include "web/scoresheet.pb.h"
template<class Tag, typename Tag::type M> struct OpX2_Rob { friend typename Tag::type OpX2_get(Tag) { return M; } };
struct OpX2_A_CreateInstance { typedef void (::google::protobuf::internal::ArenaStringPtr::*type)(const ::std::string*); friend type OpX2_get(OpX2_A_CreateInstance); };
template struct OpX2_Rob<OpX2_A_CreateInstance, &::google::protobuf::internal::ArenaStringPtr::CreateInstanceNoArena>;
void op_x2_use_createInstanceNoArena()
{
	void (::google::protobuf::internal::ArenaStringPtr::*p)(const ::std::string*) = OpX2_get(OpX2_A_CreateInstance());
}
