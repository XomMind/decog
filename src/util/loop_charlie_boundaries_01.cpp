// NOTE: explicit original protobuf12-byte closure layout; retail flags/callback addresses retained.
extern void* closure_vtable_b62adc[];
struct OnceClosure_b5 { void** vtable; void(*function)(); bool self_deleting; ~OnceClosure_b5(); };
void unknowna09180(int*,OnceClosure_b5*);
extern int once_ceb338,once_ceb528;
void unknowna3d580(); void unknowna83860();
#pragma optimize("gt",on)
void singleton_b5c6a0() { if(once_ceb338!=2) { OnceClosure_b5 func={closure_vtable_b62adc,&unknowna3d580,false}; unknowna09180(&once_ceb338,&func); } }
void singleton_b5c850() { if(once_ceb528!=2) { OnceClosure_b5 func={closure_vtable_b62adc,&unknowna83860,false}; unknowna09180(&once_ceb528,&func); } }
#pragma optimize("",off)
