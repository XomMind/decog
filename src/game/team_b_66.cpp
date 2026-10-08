// team_b_66: RepeatedField<int>::Reserve as the exe has it (0x9ecac0): protobuf 3.5.1 built with NDEBUG, so the
// GOOGLE_DCHECK_LE is `while (false) GOOGLE_CHECK...`. web.cpp instantiates the real template without NDEBUG
// first, so this is a private copy of the template under a placeholder name.
#define NDEBUG
#include <limits>
#include <algorithm>
#include "google/protobuf/repeated_field.h"

extern const int teamb_kMinRepeatedFieldAllocationSize_bb88ac;	// NOTE: placeholder name (internal::kMinRepeatedFieldAllocationSize, 4)

template <typename Element> class TeamB_RepeatedField	// NOTE: placeholder name (copy of RepeatedField<Element>)
{
public:
	void Reserve(int new_size);

private:
	struct Rep
	{
		::google::protobuf::Arena *arena;
		Element elements[1];
	};
	static const size_t kRepHeaderSize;

	int current_size_;
	int total_size_;
	Rep *rep_;

	::google::protobuf::Arena *GetArenaNoVirtual() const;
	void MoveArray(Element *to, Element *from, int size);
	void InternalDeallocate(Rep *rep, int size);
};

template <typename Element> const size_t TeamB_RepeatedField<Element>::kRepHeaderSize =
	reinterpret_cast<size_t>(&reinterpret_cast<Rep*>(16)->elements[0]) - 16;

template <typename Element> void TeamB_RepeatedField<Element>::Reserve(int new_size) {
  if (total_size_ >= new_size) return;
  Rep* old_rep = rep_;
  ::google::protobuf::Arena* arena = GetArenaNoVirtual();
  new_size = std::max(teamb_kMinRepeatedFieldAllocationSize_bb88ac,
                      std::max(total_size_ * 2, new_size));
#line 1374 "C:\\_\\_RL\\Protobuffer\\protobuf-3.5.1\\src\\google/protobuf/repeated_field.h"
  GOOGLE_DCHECK_LE(
      static_cast<size_t>(new_size),
      (std::numeric_limits<size_t>::max() - kRepHeaderSize) / sizeof(Element))
      << "Requested size is too large to fit into size_t.";
  size_t bytes = kRepHeaderSize + sizeof(Element) * static_cast<size_t>(new_size);
  if (arena == NULL) {
    rep_ = static_cast<Rep*>(::operator new(bytes));
  } else {
    rep_ = reinterpret_cast<Rep*>(
            ::google::protobuf::Arena::CreateArray<char>(arena, bytes));
  }
  rep_->arena = arena;
  int old_total_size = total_size_;
  total_size_ = new_size;
  Element* e = &rep_->elements[0];
  Element* limit = &rep_->elements[total_size_];
  for (; e < limit; e++) {
    new (e) Element;
  }
  if (current_size_ > 0) {
    MoveArray(rep_->elements, old_rep->elements, current_size_);
  }
  InternalDeallocate(old_rep, old_total_size);
}

template void TeamB_RepeatedField<int>::Reserve(int new_size);
