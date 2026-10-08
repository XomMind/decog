// Protobuf arena allocation wrappers. NOTE: placeholder names and layout.
extern unsigned cb_align_432450(unsigned);
extern char cb_rtti_cea98c[],cb_rtti_ceaa00[],cb_rtti_ceaa34[],cb_rtti_ceaa64[],cb_rtti_ceaa9c[],cb_rtti_ceaad0[],cb_rtti_ceab04[];
namespace Protobuf { class Route_Entry; }
namespace google { namespace protobuf { namespace internal { template<class T> void arena_destruct_object(void*); } } }
struct CodexBravoArenaOct07 {
 void hook_432460(const void*,unsigned);
 void* allocate_a5a340(unsigned);
 void* cleanup_a5a3e0(unsigned,void(*)(void*));
 void* f_a03e90(bool skip);
 void* f_a03f50(bool skip);
 void* f_a03fb0(bool skip);
 void* f_a04010(bool skip);
 void* f_a04070(bool skip);
 void* f_a040d0(bool skip);
 void* f_a04130(bool skip);
};
void* CodexBravoArenaOct07::f_a03e90(bool skip) {
 const unsigned n=cb_align_432450(20);
 hook_432460(cb_rtti_cea98c,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a03f50(bool skip) {
 const unsigned n=cb_align_432450(24);
 hook_432460(cb_rtti_ceaa00,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a03fb0(bool skip) {
 const unsigned n=cb_align_432450(20);
 hook_432460(cb_rtti_ceaa34,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a04010(bool skip) {
 const unsigned n=cb_align_432450(24);
 hook_432460(cb_rtti_ceaa64,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a04070(bool skip) {
 const unsigned n=cb_align_432450(24);
 hook_432460(cb_rtti_ceaa9c,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a040d0(bool skip) {
 const unsigned n=cb_align_432450(24);
 hook_432460(cb_rtti_ceaad0,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
void* CodexBravoArenaOct07::f_a04130(bool skip) {
 const unsigned n=cb_align_432450(20);
 hook_432460(cb_rtti_ceab04,n);
 if(skip) { return allocate_a5a340(n); }
 else { return cleanup_a5a3e0(n,&google::protobuf::internal::arena_destruct_object<Protobuf::Route_Entry>); }
}
