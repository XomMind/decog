// Private alias of actual Sound destructor layout: chunk0, flags4, string8.
#include <string>
struct LMSound {void *chunk;int flags;std::string name;~LMSound();};
void lmDeleteSound(LMSound *sound) {delete sound;}
