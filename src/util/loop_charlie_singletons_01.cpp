#pragma optimize("gt",on)
// NOTE: explicit retail closure layout, including its vtable, callback, and false self-deletion flag.
extern void* closure_vtable_b62adc[];
struct OnceClosure_b5 { void** vtable; void(*function)(); bool self_deleting; ~OnceClosure_b5(); };
void unknowna09180(int*,OnceClosure_b5*);
extern int once_ceb578,once_ceb5a0,once_ceb6c8;
void unknowna90530(); void unknowna90ef0(); void unknowna9ecd0();
void singleton_b5c8e0() { if(once_ceb578!=2) { OnceClosure_b5 func = {closure_vtable_b62adc,&unknowna90530,false}; unknowna09180(&once_ceb578,&func); } }
void singleton_b5c960() { if(once_ceb5a0!=2) { OnceClosure_b5 func = {closure_vtable_b62adc,&unknowna90ef0,false}; unknowna09180(&once_ceb5a0,&func); } }
void singleton_b5c9e0() { if(once_ceb6c8!=2) { OnceClosure_b5 func = {closure_vtable_b62adc,&unknowna9ecd0,false}; unknowna09180(&once_ceb6c8,&func); } }

#pragma optimize("",off)
