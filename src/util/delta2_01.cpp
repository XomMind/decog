// std::swap<int> (exe 0xa04380, ICF-folded with other swap<T*> instances). Its real extent is 0x3f bytes:
// fn_size merges the following thunks/import jumps, so the mapping row uses the exact size (cf. boundary_audit).
#include <utility>
void delta2_use_swap_int(int& a, int& b) { std::swap(a, b); }
