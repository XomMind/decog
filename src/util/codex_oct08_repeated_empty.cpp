// Retail 0xA04D10: shared IsEmpty slot of protobuf repeated-pointer accessors.
// NOTE: placeholder names and partial layout; current_size is at +4.
struct RepeatedField_a04d10 {
    void *arena;
    int current_size;
};
struct RepeatedFieldAccessor_a04d10 {
    __declspec(dllexport) bool isEmpty(const void *field) const;
};

#pragma optimize("gt", on)
#pragma optimize("y", off)
bool RepeatedFieldAccessor_a04d10::isEmpty(const void *field) const {
    return static_cast<const RepeatedField_a04d10 *>(field)->current_size == 0;
}
#pragma optimize("", off)
