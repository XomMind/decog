// NOTE: placeholder partial layout; standalone TU sorts late to avoid EH inference changes.
extern "C" void * __cdecl memset(void *, int, unsigned int);
struct TeamOct08CharlieGrid { int width, height; void *data; void clear9cf020(int byte); };
void TeamOct08CharlieGrid::clear9cf020(int byte) { memset(data, byte, width * 4 * height); }
