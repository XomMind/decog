// Not game code: odr-uses generated scoresheet.pb.h inlines so the out-of-line copies the game calls get emitted.
#include "web/scoresheet.pb.h"

void op_x2_use_setErrorMessageSize(Protobuf::PostScoresheetResponse *response, const char *text)
{
	response->set_error_message(text,1);
}
