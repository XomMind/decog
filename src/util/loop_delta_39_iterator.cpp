#include <vector>
// Actual release-native iterator forwarding helper, insensitive to record contents.
// Original pooled iterator element semantics remain unknown; known native Area is a borrowed arithmetic alias witness only.
struct D39Point{int x,y;};
struct D39Area{D39Point first,last;D39Area(const D39Area&)throw();};
template class std::_Vector_iterator<std::_Vector_val<D39Area,std::allocator<D39Area> > >;
