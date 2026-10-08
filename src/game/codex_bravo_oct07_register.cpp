// Protobuf enum-value string registration forwarding function. NOTE: placeholder name.
namespace google { namespace protobuf {
class EnumValueOptions;
namespace internal {
struct StringTypeTraits { template<class T> static void Register(int,unsigned char,bool); };
}
} }
void cb_register_9bf9a0(int field) {
 google::protobuf::internal::StringTypeTraits::Register<google::protobuf::EnumValueOptions>(field,9,false);
}
