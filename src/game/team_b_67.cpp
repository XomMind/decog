// team_b_67: RepeatedPtrFieldBase::MergeFrom<RepeatedPtrField<Route_Entry>::TypeHandler> as the exe has it (0x9f67d0,
// NDEBUG DCHECK); minimal redeclaration of the protobuf classes so the copy can call the private members by name.
#define NDEBUG
#include "google/protobuf/stubs/logging.h"

namespace Protobuf { class Route_Entry; }

namespace google {
namespace protobuf {
template <typename Element> class RepeatedPtrField
{
public:
	class TypeHandler;
};
namespace internal {
class RepeatedPtrFieldBase	// NOTE: partial redeclaration (protobuf 3.5.1 layout)
{
public:
	template <typename TypeHandler> void TeamB_MergeFrom_9f67d0(const RepeatedPtrFieldBase &other);	// NOTE: placeholder name

private:
	void MergeFromInternal(const RepeatedPtrFieldBase &other, void (RepeatedPtrFieldBase::*inner_loop)(void **, void **, int, int));
	template <typename TypeHandler> void MergeFromInnerLoop(void **our_elems, void **other_elems, int length, int already_allocated);

	void *arena_;
	int current_size_;
	int total_size_;
	void *rep_;
};

template <typename TypeHandler> void RepeatedPtrFieldBase::TeamB_MergeFrom_9f67d0(const RepeatedPtrFieldBase &other) {
#line 1605 "C:\\_\\_RL\\Protobuffer\\protobuf-3.5.1\\src\\google/protobuf/repeated_field.h"
  GOOGLE_DCHECK_NE(&other, this);
  if (other.current_size_ == 0) return;
  MergeFromInternal(
      other, &RepeatedPtrFieldBase::MergeFromInnerLoop<TypeHandler>);
}

template void RepeatedPtrFieldBase::TeamB_MergeFrom_9f67d0<RepeatedPtrField<Protobuf::Route_Entry>::TypeHandler>(const RepeatedPtrFieldBase &other);
}  // namespace internal
}  // namespace protobuf
}  // namespace google
