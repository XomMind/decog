// Not game code: odr-uses every inline function of the generated scoresheet.pb.h
// (protoc 3.5.1) so the out-of-line copies the game calls get emitted for matching.
#include "web/scoresheet.pb.h"

// private-member access via explicit instantiation (does not change mangling)
template<class Tag, typename Tag::type M> struct OpPb_Rob { friend typename Tag::type OpPb_get(Tag) { return M; } };
volatile int g_opPbNever;

#define C Protobuf::PingRequest
struct OpPb_A_PingRequest { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PingRequest); };
template struct OpPb_Rob<OpPb_A_PingRequest, &C::GetArenaNoVirtual>;
struct OpPb_M_PingRequest { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PingRequest); };
template struct OpPb_Rob<OpPb_M_PingRequest, &C::MaybeArenaPtr>;
void op_pb_use_PingRequest()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PingRequest()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PingRequest()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
}
#undef C

#define C Protobuf::PingResponse
struct OpPb_A_PingResponse { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PingResponse); };
template struct OpPb_Rob<OpPb_A_PingResponse, &C::GetArenaNoVirtual>;
struct OpPb_M_PingResponse { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PingResponse); };
template struct OpPb_Rob<OpPb_M_PingResponse, &C::MaybeArenaPtr>;
void op_pb_use_PingResponse()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PingResponse()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PingResponse()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_server_timestamp; }
	{ ::google::protobuf::uint64 (C::*p)() const = &C::server_timestamp; }
	{ void (C::*p)(::google::protobuf::uint64 value) = &C::set_server_timestamp; }
	{ void (C::*p)() = &C::clear_request_public_key; }
	{ const ::std::string& (C::*p)() const = &C::request_public_key; }
	{ void (C::*p)(const ::std::string& value) = &C::set_request_public_key; }
	{ void (C::*p)(const char* value) = &C::set_request_public_key; }
	{ void (C::*p)(const void* value, size_t size) = &C::set_request_public_key; }
	{ ::std::string* (C::*p)() = &C::mutable_request_public_key; }
	{ ::std::string* (C::*p)() = &C::release_request_public_key; }
	{ void (C::*p)(::std::string* request_public_key) = &C::set_allocated_request_public_key; }
}
#undef C

#define C Protobuf::PostScoresheetRequest
struct OpPb_A_PostScoresheetRequest { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PostScoresheetRequest); };
template struct OpPb_Rob<OpPb_A_PostScoresheetRequest, &C::GetArenaNoVirtual>;
struct OpPb_M_PostScoresheetRequest { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PostScoresheetRequest); };
template struct OpPb_Rob<OpPb_M_PostScoresheetRequest, &C::MaybeArenaPtr>;
void op_pb_use_PostScoresheetRequest()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PostScoresheetRequest()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PostScoresheetRequest()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_scoresheet; }
	{ void (C::*p)() = &C::clear_scoresheet; }
	{ const ::Protobuf::Scoresheet& (C::*p)() const = &C::scoresheet; }
	{ ::Protobuf::Scoresheet* (C::*p)() = &C::release_scoresheet; }
	{ ::Protobuf::Scoresheet* (C::*p)() = &C::mutable_scoresheet; }
	{ void (C::*p)(::Protobuf::Scoresheet* scoresheet) = &C::set_allocated_scoresheet; }
	{ void (C::*p)() = &C::clear_textual_scoresheet; }
	{ const ::std::string& (C::*p)() const = &C::textual_scoresheet; }
	{ void (C::*p)(const ::std::string& value) = &C::set_textual_scoresheet; }
	{ void (C::*p)(const char* value) = &C::set_textual_scoresheet; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_textual_scoresheet; }
	{ ::std::string* (C::*p)() = &C::mutable_textual_scoresheet; }
	{ ::std::string* (C::*p)() = &C::release_textual_scoresheet; }
	{ void (C::*p)(::std::string* textual_scoresheet) = &C::set_allocated_textual_scoresheet; }
}
#undef C

#define C Protobuf::PostScoresheetResponse
struct OpPb_A_PostScoresheetResponse { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PostScoresheetResponse); };
template struct OpPb_Rob<OpPb_A_PostScoresheetResponse, &C::GetArenaNoVirtual>;
struct OpPb_M_PostScoresheetResponse { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PostScoresheetResponse); };
template struct OpPb_Rob<OpPb_M_PostScoresheetResponse, &C::MaybeArenaPtr>;
void op_pb_use_PostScoresheetResponse()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PostScoresheetResponse()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PostScoresheetResponse()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_url; }
	{ const ::std::string& (C::*p)() const = &C::url; }
	{ void (C::*p)(const ::std::string& value) = &C::set_url; }
	{ void (C::*p)(const char* value) = &C::set_url; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_url; }
	{ ::std::string* (C::*p)() = &C::mutable_url; }
	{ ::std::string* (C::*p)() = &C::release_url; }
	{ void (C::*p)(::std::string* url) = &C::set_allocated_url; }
	{ void (C::*p)() = &C::clear_error_message; }
	{ const ::std::string& (C::*p)() const = &C::error_message; }
	{ void (C::*p)(const ::std::string& value) = &C::set_error_message; }
	{ void (C::*p)(const char* value) = &C::set_error_message; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_error_message; }
	{ ::std::string* (C::*p)() = &C::mutable_error_message; }
	{ ::std::string* (C::*p)() = &C::release_error_message; }
	{ void (C::*p)(::std::string* error_message) = &C::set_allocated_error_message; }
}
#undef C

#define C Protobuf::Submission_CreatedAt
struct OpPb_A_Submission_CreatedAt { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Submission_CreatedAt); };
template struct OpPb_Rob<OpPb_A_Submission_CreatedAt, &C::GetArenaNoVirtual>;
struct OpPb_M_Submission_CreatedAt { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Submission_CreatedAt); };
template struct OpPb_Rob<OpPb_M_Submission_CreatedAt, &C::MaybeArenaPtr>;
void op_pb_use_Submission_CreatedAt()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Submission_CreatedAt()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Submission_CreatedAt()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_unix; }
	{ ::google::protobuf::uint64 (C::*p)() const = &C::unix; }
	{ void (C::*p)(::google::protobuf::uint64 value) = &C::set_unix; }
}
#undef C

#define C Protobuf::Submission_Envelope
struct OpPb_A_Submission_Envelope { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Submission_Envelope); };
template struct OpPb_Rob<OpPb_A_Submission_Envelope, &C::GetArenaNoVirtual>;
struct OpPb_M_Submission_Envelope { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Submission_Envelope); };
template struct OpPb_Rob<OpPb_M_Submission_Envelope, &C::MaybeArenaPtr>;
void op_pb_use_Submission_Envelope()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Submission_Envelope()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Submission_Envelope()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_ip; }
	{ const ::std::string& (C::*p)() const = &C::ip; }
	{ void (C::*p)(const ::std::string& value) = &C::set_ip; }
	{ void (C::*p)(const char* value) = &C::set_ip; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_ip; }
	{ ::std::string* (C::*p)() = &C::mutable_ip; }
	{ ::std::string* (C::*p)() = &C::release_ip; }
	{ void (C::*p)(::std::string* ip) = &C::set_allocated_ip; }
	{ void (C::*p)() = &C::clear_address; }
	{ const ::std::string& (C::*p)() const = &C::address; }
	{ void (C::*p)(const ::std::string& value) = &C::set_address; }
	{ void (C::*p)(const char* value) = &C::set_address; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_address; }
	{ ::std::string* (C::*p)() = &C::mutable_address; }
	{ ::std::string* (C::*p)() = &C::release_address; }
	{ void (C::*p)(::std::string* address) = &C::set_allocated_address; }
	{ void (C::*p)() = &C::clear_useragent; }
	{ const ::std::string& (C::*p)() const = &C::useragent; }
	{ void (C::*p)(const ::std::string& value) = &C::set_useragent; }
	{ void (C::*p)(const char* value) = &C::set_useragent; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_useragent; }
	{ ::std::string* (C::*p)() = &C::mutable_useragent; }
	{ ::std::string* (C::*p)() = &C::release_useragent; }
	{ void (C::*p)(::std::string* useragent) = &C::set_allocated_useragent; }
}
#undef C

#define C Protobuf::Submission
struct OpPb_A_Submission { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Submission); };
template struct OpPb_Rob<OpPb_A_Submission, &C::GetArenaNoVirtual>;
struct OpPb_M_Submission { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Submission); };
template struct OpPb_Rob<OpPb_M_Submission, &C::MaybeArenaPtr>;
void op_pb_use_Submission()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Submission()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Submission()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_id; }
	{ const ::std::string& (C::*p)() const = &C::id; }
	{ void (C::*p)(const ::std::string& value) = &C::set_id; }
	{ void (C::*p)(const char* value) = &C::set_id; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_id; }
	{ ::std::string* (C::*p)() = &C::mutable_id; }
	{ ::std::string* (C::*p)() = &C::release_id; }
	{ void (C::*p)(::std::string* id) = &C::set_allocated_id; }
	{ bool (C::*p)() const = &C::has_createdat; }
	{ void (C::*p)() = &C::clear_createdat; }
	{ const ::Protobuf::Submission_CreatedAt& (C::*p)() const = &C::createdat; }
	{ ::Protobuf::Submission_CreatedAt* (C::*p)() = &C::release_createdat; }
	{ ::Protobuf::Submission_CreatedAt* (C::*p)() = &C::mutable_createdat; }
	{ void (C::*p)(::Protobuf::Submission_CreatedAt* createdat) = &C::set_allocated_createdat; }
	{ bool (C::*p)() const = &C::has_envelope; }
	{ void (C::*p)() = &C::clear_envelope; }
	{ const ::Protobuf::Submission_Envelope& (C::*p)() const = &C::envelope; }
	{ ::Protobuf::Submission_Envelope* (C::*p)() = &C::release_envelope; }
	{ ::Protobuf::Submission_Envelope* (C::*p)() = &C::mutable_envelope; }
	{ void (C::*p)(::Protobuf::Submission_Envelope* envelope) = &C::set_allocated_envelope; }
	{ bool (C::*p)() const = &C::has_scoresheet; }
	{ void (C::*p)() = &C::clear_scoresheet; }
	{ const ::Protobuf::Scoresheet& (C::*p)() const = &C::scoresheet; }
	{ ::Protobuf::Scoresheet* (C::*p)() = &C::release_scoresheet; }
	{ ::Protobuf::Scoresheet* (C::*p)() = &C::mutable_scoresheet; }
	{ void (C::*p)(::Protobuf::Scoresheet* scoresheet) = &C::set_allocated_scoresheet; }
}
#undef C

#define C Protobuf::Scoresheet
struct OpPb_A_Scoresheet { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Scoresheet); };
template struct OpPb_Rob<OpPb_A_Scoresheet, &C::GetArenaNoVirtual>;
struct OpPb_M_Scoresheet { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Scoresheet); };
template struct OpPb_Rob<OpPb_M_Scoresheet, &C::MaybeArenaPtr>;
void op_pb_use_Scoresheet()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Scoresheet()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Scoresheet()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_header; }
	{ void (C::*p)() = &C::clear_header; }
	{ const ::Protobuf::Header& (C::*p)() const = &C::header; }
	{ ::Protobuf::Header* (C::*p)() = &C::release_header; }
	{ ::Protobuf::Header* (C::*p)() = &C::mutable_header; }
	{ void (C::*p)(::Protobuf::Header* header) = &C::set_allocated_header; }
	{ bool (C::*p)() const = &C::has_performance; }
	{ void (C::*p)() = &C::clear_performance; }
	{ const ::Protobuf::Performance& (C::*p)() const = &C::performance; }
	{ ::Protobuf::Performance* (C::*p)() = &C::release_performance; }
	{ ::Protobuf::Performance* (C::*p)() = &C::mutable_performance; }
	{ void (C::*p)(::Protobuf::Performance* performance) = &C::set_allocated_performance; }
	{ bool (C::*p)() const = &C::has_bonus; }
	{ void (C::*p)() = &C::clear_bonus; }
	{ const ::Protobuf::Bonus& (C::*p)() const = &C::bonus; }
	{ ::Protobuf::Bonus* (C::*p)() = &C::release_bonus; }
	{ ::Protobuf::Bonus* (C::*p)() = &C::mutable_bonus; }
	{ void (C::*p)(::Protobuf::Bonus* bonus) = &C::set_allocated_bonus; }
	{ bool (C::*p)() const = &C::has_cogmind; }
	{ void (C::*p)() = &C::clear_cogmind; }
	{ const ::Protobuf::Cogmind& (C::*p)() const = &C::cogmind; }
	{ ::Protobuf::Cogmind* (C::*p)() = &C::release_cogmind; }
	{ ::Protobuf::Cogmind* (C::*p)() = &C::mutable_cogmind; }
	{ void (C::*p)(::Protobuf::Cogmind* cogmind) = &C::set_allocated_cogmind; }
	{ bool (C::*p)() const = &C::has_parts; }
	{ void (C::*p)() = &C::clear_parts; }
	{ const ::Protobuf::Parts& (C::*p)() const = &C::parts; }
	{ ::Protobuf::Parts* (C::*p)() = &C::release_parts; }
	{ ::Protobuf::Parts* (C::*p)() = &C::mutable_parts; }
	{ void (C::*p)(::Protobuf::Parts* parts) = &C::set_allocated_parts; }
	{ bool (C::*p)() const = &C::has_peak_state; }
	{ void (C::*p)() = &C::clear_peak_state; }
	{ const ::Protobuf::PeakState& (C::*p)() const = &C::peak_state; }
	{ ::Protobuf::PeakState* (C::*p)() = &C::release_peak_state; }
	{ ::Protobuf::PeakState* (C::*p)() = &C::mutable_peak_state; }
	{ void (C::*p)(::Protobuf::PeakState* peak_state) = &C::set_allocated_peak_state; }
	{ bool (C::*p)() const = &C::has_favorites; }
	{ void (C::*p)() = &C::clear_favorites; }
	{ const ::Protobuf::Favorites& (C::*p)() const = &C::favorites; }
	{ ::Protobuf::Favorites* (C::*p)() = &C::release_favorites; }
	{ ::Protobuf::Favorites* (C::*p)() = &C::mutable_favorites; }
	{ void (C::*p)(::Protobuf::Favorites* favorites) = &C::set_allocated_favorites; }
	{ bool (C::*p)() const = &C::has_class_distribution; }
	{ void (C::*p)() = &C::clear_class_distribution; }
	{ const ::Protobuf::ClassDistribution& (C::*p)() const = &C::class_distribution; }
	{ ::Protobuf::ClassDistribution* (C::*p)() = &C::release_class_distribution; }
	{ ::Protobuf::ClassDistribution* (C::*p)() = &C::mutable_class_distribution; }
	{ void (C::*p)(::Protobuf::ClassDistribution* class_distribution) = &C::set_allocated_class_distribution; }
	{ bool (C::*p)() const = &C::has_history_event_win; }
	{ void (C::*p)() = &C::clear_history_event_win; }
	{ const ::Protobuf::HistoryEventWin& (C::*p)() const = &C::history_event_win; }
	{ ::Protobuf::HistoryEventWin* (C::*p)() = &C::release_history_event_win; }
	{ ::Protobuf::HistoryEventWin* (C::*p)() = &C::mutable_history_event_win; }
	{ void (C::*p)(::Protobuf::HistoryEventWin* history_event_win) = &C::set_allocated_history_event_win; }
	{ bool (C::*p)() const = &C::has_last_messages; }
	{ void (C::*p)() = &C::clear_last_messages; }
	{ const ::Protobuf::LastMessages& (C::*p)() const = &C::last_messages; }
	{ ::Protobuf::LastMessages* (C::*p)() = &C::release_last_messages; }
	{ ::Protobuf::LastMessages* (C::*p)() = &C::mutable_last_messages; }
	{ void (C::*p)(::Protobuf::LastMessages* last_messages) = &C::set_allocated_last_messages; }
	{ bool (C::*p)() const = &C::has_map; }
	{ void (C::*p)() = &C::clear_map; }
	{ const ::Protobuf::Map& (C::*p)() const = &C::map; }
	{ ::Protobuf::Map* (C::*p)() = &C::release_map; }
	{ ::Protobuf::Map* (C::*p)() = &C::mutable_map; }
	{ void (C::*p)(::Protobuf::Map* map) = &C::set_allocated_map; }
	{ bool (C::*p)() const = &C::has_best_states; }
	{ void (C::*p)() = &C::clear_best_states; }
	{ const ::Protobuf::BestStates& (C::*p)() const = &C::best_states; }
	{ ::Protobuf::BestStates* (C::*p)() = &C::release_best_states; }
	{ ::Protobuf::BestStates* (C::*p)() = &C::mutable_best_states; }
	{ void (C::*p)(::Protobuf::BestStates* best_states) = &C::set_allocated_best_states; }
	{ bool (C::*p)() const = &C::has_alien_tech_used; }
	{ void (C::*p)() = &C::clear_alien_tech_used; }
	{ const ::Protobuf::AlienTechUsed& (C::*p)() const = &C::alien_tech_used; }
	{ ::Protobuf::AlienTechUsed* (C::*p)() = &C::release_alien_tech_used; }
	{ ::Protobuf::AlienTechUsed* (C::*p)() = &C::mutable_alien_tech_used; }
	{ void (C::*p)(::Protobuf::AlienTechUsed* alien_tech_used) = &C::set_allocated_alien_tech_used; }
	{ bool (C::*p)() const = &C::has_achievements; }
	{ void (C::*p)() = &C::clear_achievements; }
	{ const ::Protobuf::Achievements& (C::*p)() const = &C::achievements; }
	{ ::Protobuf::Achievements* (C::*p)() = &C::release_achievements; }
	{ ::Protobuf::Achievements* (C::*p)() = &C::mutable_achievements; }
	{ void (C::*p)(::Protobuf::Achievements* achievements) = &C::set_allocated_achievements; }
	{ bool (C::*p)() const = &C::has_challenges; }
	{ void (C::*p)() = &C::clear_challenges; }
	{ const ::Protobuf::Challenges& (C::*p)() const = &C::challenges; }
	{ ::Protobuf::Challenges* (C::*p)() = &C::release_challenges; }
	{ ::Protobuf::Challenges* (C::*p)() = &C::mutable_challenges; }
	{ void (C::*p)(::Protobuf::Challenges* challenges) = &C::set_allocated_challenges; }
	{ bool (C::*p)() const = &C::has_cogshop_purchases; }
	{ void (C::*p)() = &C::clear_cogshop_purchases; }
	{ const ::Protobuf::CogshopPurchases& (C::*p)() const = &C::cogshop_purchases; }
	{ ::Protobuf::CogshopPurchases* (C::*p)() = &C::release_cogshop_purchases; }
	{ ::Protobuf::CogshopPurchases* (C::*p)() = &C::mutable_cogshop_purchases; }
	{ void (C::*p)(::Protobuf::CogshopPurchases* cogshop_purchases) = &C::set_allocated_cogshop_purchases; }
	{ bool (C::*p)() const = &C::has_polymind_host_kill_leaderboard; }
	{ void (C::*p)() = &C::clear_polymind_host_kill_leaderboard; }
	{ const ::Protobuf::PolymindHostKillLeaderboard& (C::*p)() const = &C::polymind_host_kill_leaderboard; }
	{ ::Protobuf::PolymindHostKillLeaderboard* (C::*p)() = &C::release_polymind_host_kill_leaderboard; }
	{ ::Protobuf::PolymindHostKillLeaderboard* (C::*p)() = &C::mutable_polymind_host_kill_leaderboard; }
	{ void (C::*p)(::Protobuf::PolymindHostKillLeaderboard* polymind_host_kill_leaderboard) = &C::set_allocated_polymind_host_kill_leaderboard; }
	{ bool (C::*p)() const = &C::has_game; }
	{ void (C::*p)() = &C::clear_game; }
	{ const ::Protobuf::Game& (C::*p)() const = &C::game; }
	{ ::Protobuf::Game* (C::*p)() = &C::release_game; }
	{ ::Protobuf::Game* (C::*p)() = &C::mutable_game; }
	{ void (C::*p)(::Protobuf::Game* game) = &C::set_allocated_game; }
	{ bool (C::*p)() const = &C::has_options; }
	{ void (C::*p)() = &C::clear_options; }
	{ const ::Protobuf::Options& (C::*p)() const = &C::options; }
	{ ::Protobuf::Options* (C::*p)() = &C::release_options; }
	{ ::Protobuf::Options* (C::*p)() = &C::mutable_options; }
	{ void (C::*p)(::Protobuf::Options* options) = &C::set_allocated_options; }
	{ bool (C::*p)() const = &C::has_meta; }
	{ void (C::*p)() = &C::clear_meta; }
	{ const ::Protobuf::Meta& (C::*p)() const = &C::meta; }
	{ ::Protobuf::Meta* (C::*p)() = &C::release_meta; }
	{ ::Protobuf::Meta* (C::*p)() = &C::mutable_meta; }
	{ void (C::*p)(::Protobuf::Meta* meta) = &C::set_allocated_meta; }
	{ bool (C::*p)() const = &C::has_stats; }
	{ void (C::*p)() = &C::clear_stats; }
	{ const ::Protobuf::Stats& (C::*p)() const = &C::stats; }
	{ ::Protobuf::Stats* (C::*p)() = &C::release_stats; }
	{ ::Protobuf::Stats* (C::*p)() = &C::mutable_stats; }
	{ void (C::*p)(::Protobuf::Stats* stats) = &C::set_allocated_stats; }
	{ bool (C::*p)() const = &C::has_route; }
	{ void (C::*p)() = &C::clear_route; }
	{ const ::Protobuf::Route& (C::*p)() const = &C::route; }
	{ ::Protobuf::Route* (C::*p)() = &C::release_route; }
	{ ::Protobuf::Route* (C::*p)() = &C::mutable_route; }
	{ void (C::*p)(::Protobuf::Route* route) = &C::set_allocated_route; }
}
#undef C

#define C Protobuf::Header
struct OpPb_A_Header { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Header); };
template struct OpPb_Rob<OpPb_A_Header, &C::GetArenaNoVirtual>;
struct OpPb_M_Header { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Header); };
template struct OpPb_Rob<OpPb_M_Header, &C::MaybeArenaPtr>;
void op_pb_use_Header()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Header()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Header()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_filename; }
	{ const ::std::string& (C::*p)() const = &C::filename; }
	{ void (C::*p)(const ::std::string& value) = &C::set_filename; }
	{ void (C::*p)(const char* value) = &C::set_filename; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_filename; }
	{ ::std::string* (C::*p)() = &C::mutable_filename; }
	{ ::std::string* (C::*p)() = &C::release_filename; }
	{ void (C::*p)(::std::string* filename) = &C::set_allocated_filename; }
	{ void (C::*p)() = &C::clear_version; }
	{ const ::std::string& (C::*p)() const = &C::version; }
	{ void (C::*p)(const ::std::string& value) = &C::set_version; }
	{ void (C::*p)(const char* value) = &C::set_version; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_version; }
	{ ::std::string* (C::*p)() = &C::mutable_version; }
	{ ::std::string* (C::*p)() = &C::release_version; }
	{ void (C::*p)(::std::string* version) = &C::set_allocated_version; }
	{ void (C::*p)() = &C::clear_build; }
	{ const ::std::string& (C::*p)() const = &C::build; }
	{ void (C::*p)(const ::std::string& value) = &C::set_build; }
	{ void (C::*p)(const char* value) = &C::set_build; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_build; }
	{ ::std::string* (C::*p)() = &C::mutable_build; }
	{ ::std::string* (C::*p)() = &C::release_build; }
	{ void (C::*p)(::std::string* build) = &C::set_allocated_build; }
	{ void (C::*p)() = &C::clear_difficulty; }
	{ ::Protobuf::DifficultyType (C::*p)() const = &C::difficulty; }
	{ void (C::*p)(::Protobuf::DifficultyType value) = &C::set_difficulty; }
	{ void (C::*p)() = &C::clear_run_end_date; }
	{ const ::std::string& (C::*p)() const = &C::run_end_date; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_end_date; }
	{ void (C::*p)(const char* value) = &C::set_run_end_date; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_end_date; }
	{ ::std::string* (C::*p)() = &C::mutable_run_end_date; }
	{ ::std::string* (C::*p)() = &C::release_run_end_date; }
	{ void (C::*p)(::std::string* run_end_date) = &C::set_allocated_run_end_date; }
	{ void (C::*p)() = &C::clear_run_end_time; }
	{ const ::std::string& (C::*p)() const = &C::run_end_time; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_end_time; }
	{ void (C::*p)(const char* value) = &C::set_run_end_time; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_end_time; }
	{ ::std::string* (C::*p)() = &C::mutable_run_end_time; }
	{ ::std::string* (C::*p)() = &C::release_run_end_time; }
	{ void (C::*p)(::std::string* run_end_time) = &C::set_allocated_run_end_time; }
	{ void (C::*p)() = &C::clear_special_mode; }
	{ ::Protobuf::SpecialModeType (C::*p)() const = &C::special_mode; }
	{ void (C::*p)(::Protobuf::SpecialModeType value) = &C::set_special_mode; }
	{ void (C::*p)() = &C::clear_player_name; }
	{ const ::std::string& (C::*p)() const = &C::player_name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_player_name; }
	{ void (C::*p)(const char* value) = &C::set_player_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_player_name; }
	{ ::std::string* (C::*p)() = &C::mutable_player_name; }
	{ ::std::string* (C::*p)() = &C::release_player_name; }
	{ void (C::*p)(::std::string* player_name) = &C::set_allocated_player_name; }
	{ void (C::*p)() = &C::clear_run_result; }
	{ const ::std::string& (C::*p)() const = &C::run_result; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_result; }
	{ void (C::*p)(const char* value) = &C::set_run_result; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_result; }
	{ ::std::string* (C::*p)() = &C::mutable_run_result; }
	{ ::std::string* (C::*p)() = &C::release_run_result; }
	{ void (C::*p)(::std::string* run_result) = &C::set_allocated_run_result; }
	{ void (C::*p)() = &C::clear_win; }
	{ bool (C::*p)() const = &C::win; }
	{ void (C::*p)(bool value) = &C::set_win; }
}
#undef C

#define C Protobuf::Performance_Entry
struct OpPb_A_Performance_Entry { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Performance_Entry); };
template struct OpPb_Rob<OpPb_A_Performance_Entry, &C::GetArenaNoVirtual>;
struct OpPb_M_Performance_Entry { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Performance_Entry); };
template struct OpPb_Rob<OpPb_M_Performance_Entry, &C::MaybeArenaPtr>;
void op_pb_use_Performance_Entry()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Performance_Entry()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Performance_Entry()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_count; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::count; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_count; }
	{ void (C::*p)() = &C::clear_points; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::points; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_points; }
}
#undef C

#define C Protobuf::Performance
struct OpPb_A_Performance { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Performance); };
template struct OpPb_Rob<OpPb_A_Performance, &C::GetArenaNoVirtual>;
struct OpPb_M_Performance { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Performance); };
template struct OpPb_Rob<OpPb_M_Performance, &C::MaybeArenaPtr>;
void op_pb_use_Performance()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Performance()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Performance()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_total_score; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_score; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_score; }
	{ bool (C::*p)() const = &C::has_evolutions; }
	{ void (C::*p)() = &C::clear_evolutions; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::evolutions; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_evolutions; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_evolutions; }
	{ void (C::*p)(::Protobuf::Performance_Entry* evolutions) = &C::set_allocated_evolutions; }
	{ bool (C::*p)() const = &C::has_regions_visited; }
	{ void (C::*p)() = &C::clear_regions_visited; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::regions_visited; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_regions_visited; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_regions_visited; }
	{ void (C::*p)(::Protobuf::Performance_Entry* regions_visited) = &C::set_allocated_regions_visited; }
	{ bool (C::*p)() const = &C::has_robots_destroyed; }
	{ void (C::*p)() = &C::clear_robots_destroyed; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::robots_destroyed; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_robots_destroyed; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_robots_destroyed; }
	{ void (C::*p)(::Protobuf::Performance_Entry* robots_destroyed) = &C::set_allocated_robots_destroyed; }
	{ bool (C::*p)() const = &C::has_value_destroyed; }
	{ void (C::*p)() = &C::clear_value_destroyed; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::value_destroyed; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_value_destroyed; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_value_destroyed; }
	{ void (C::*p)(::Protobuf::Performance_Entry* value_destroyed) = &C::set_allocated_value_destroyed; }
	{ bool (C::*p)() const = &C::has_prototypes_identified; }
	{ void (C::*p)() = &C::clear_prototypes_identified; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::prototypes_identified; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_prototypes_identified; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_prototypes_identified; }
	{ void (C::*p)(::Protobuf::Performance_Entry* prototypes_identified) = &C::set_allocated_prototypes_identified; }
	{ bool (C::*p)() const = &C::has_alien_tech_used; }
	{ void (C::*p)() = &C::clear_alien_tech_used; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::alien_tech_used; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_alien_tech_used; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_alien_tech_used; }
	{ void (C::*p)(::Protobuf::Performance_Entry* alien_tech_used) = &C::set_allocated_alien_tech_used; }
	{ bool (C::*p)() const = &C::has_bonus; }
	{ void (C::*p)() = &C::clear_bonus; }
	{ const ::Protobuf::Performance_Entry& (C::*p)() const = &C::bonus; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::release_bonus; }
	{ ::Protobuf::Performance_Entry* (C::*p)() = &C::mutable_bonus; }
	{ void (C::*p)(::Protobuf::Performance_Entry* bonus) = &C::set_allocated_bonus; }
}
#undef C

#define C Protobuf::Bonus
struct OpPb_A_Bonus { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Bonus); };
template struct OpPb_Rob<OpPb_A_Bonus, &C::GetArenaNoVirtual>;
struct OpPb_M_Bonus { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Bonus); };
template struct OpPb_Rob<OpPb_M_Bonus, &C::MaybeArenaPtr>;
void op_pb_use_Bonus()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Bonus()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Bonus()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_devolution; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::devolution; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_devolution; }
	{ void (C::*p)() = &C::clear_fragile_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fragile_parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fragile_parts; }
	{ void (C::*p)() = &C::clear_gauntlet; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gauntlet; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gauntlet; }
	{ void (C::*p)() = &C::clear_inhibited_evolution; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::inhibited_evolution; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_inhibited_evolution; }
	{ void (C::*p)() = &C::clear_no_salvage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::no_salvage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_no_salvage; }
	{ void (C::*p)() = &C::clear_pure_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pure_core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pure_core; }
	{ void (C::*p)() = &C::clear_scavenger; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scavenger; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scavenger; }
	{ void (C::*p)() = &C::clear_simple_hacker; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::simple_hacker; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_simple_hacker; }
	{ void (C::*p)() = &C::clear_sticky_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sticky_parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sticky_parts; }
	{ void (C::*p)() = &C::clear_super_gauntlet; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::super_gauntlet; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_super_gauntlet; }
	{ void (C::*p)() = &C::clear_trapped; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trapped; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trapped; }
	{ void (C::*p)() = &C::clear_unstable_evolution; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unstable_evolution; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unstable_evolution; }
	{ void (C::*p)() = &C::clear_polymind_skill; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::polymind_skill; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_polymind_skill; }
	{ void (C::*p)() = &C::clear_pacifist; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pacifist; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pacifist; }
	{ void (C::*p)() = &C::clear_triggered_high_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triggered_high_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triggered_high_security; }
	{ void (C::*p)() = &C::clear_triggered_max_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triggered_max_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triggered_max_security; }
	{ void (C::*p)() = &C::clear_high_alert_combat_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::high_alert_combat_kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_high_alert_combat_kills; }
	{ void (C::*p)() = &C::clear_follower_combat_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::follower_combat_kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_follower_combat_kills; }
	{ void (C::*p)() = &C::clear_prayed_to_x01v1; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prayed_to_x01v1; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prayed_to_x01v1; }
	{ void (C::*p)() = &C::clear_major_x01v1_interference; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::major_x01v1_interference; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_major_x01v1_interference; }
	{ void (C::*p)() = &C::clear_hunted_by_unchained; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hunted_by_unchained; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hunted_by_unchained; }
	{ void (C::*p)() = &C::clear_destroyed_unchained; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_unchained; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_unchained; }
	{ void (C::*p)() = &C::clear_spooked_cyphr; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::spooked_cyphr; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_spooked_cyphr; }
	{ void (C::*p)() = &C::clear_forged_quantum_companion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::forged_quantum_companion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_forged_quantum_companion; }
	{ void (C::*p)() = &C::clear_awakened_behemoth_slayer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::awakened_behemoth_slayer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_awakened_behemoth_slayer; }
	{ void (C::*p)() = &C::clear_finished_modified_em_gauss; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::finished_modified_em_gauss; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_finished_modified_em_gauss; }
	{ void (C::*p)() = &C::clear_built_pl3xns_obliterator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::built_pl3xns_obliterator; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_built_pl3xns_obliterator; }
	{ void (C::*p)() = &C::clear_installed_lc_capacitor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::installed_lc_capacitor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_installed_lc_capacitor; }
	{ void (C::*p)() = &C::clear_subatomizer_sterilization; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::subatomizer_sterilization; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_subatomizer_sterilization; }
	{ void (C::*p)() = &C::clear_entered_garrisons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entered_garrisons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entered_garrisons; }
	{ void (C::*p)() = &C::clear_used_rif_installer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used_rif_installer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used_rif_installer; }
	{ void (C::*p)() = &C::clear_entered_dsfs; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entered_dsfs; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entered_dsfs; }
	{ void (C::*p)() = &C::clear_network_hubs_disabled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::network_hubs_disabled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_network_hubs_disabled; }
	{ void (C::*p)() = &C::clear_aligned_with_farcom; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::aligned_with_farcom; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_aligned_with_farcom; }
	{ void (C::*p)() = &C::clear_delivered_subcon_basin; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::delivered_subcon_basin; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_delivered_subcon_basin; }
	{ void (C::*p)() = &C::clear_registered_with_ufd; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::registered_with_ufd; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_registered_with_ufd; }
	{ void (C::*p)() = &C::clear_met_optimus_in_hq; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_optimus_in_hq; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_optimus_in_hq; }
	{ void (C::*p)() = &C::clear_met_data_miner; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_data_miner; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_data_miner; }
	{ void (C::*p)() = &C::clear_used_data_conduit; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used_data_conduit; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used_data_conduit; }
	{ void (C::*p)() = &C::clear_met_imprinter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_imprinter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_imprinter; }
	{ void (C::*p)() = &C::clear_was_imprinted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::was_imprinted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_was_imprinted; }
	{ void (C::*p)() = &C::clear_destroyed_zimprinter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_zimprinter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_zimprinter; }
	{ void (C::*p)() = &C::clear_triggered_deep_caves_wall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triggered_deep_caves_wall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triggered_deep_caves_wall; }
	{ void (C::*p)() = &C::clear_exposed_golem_chamber; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::exposed_golem_chamber; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_exposed_golem_chamber; }
	{ void (C::*p)() = &C::clear_acquired_eca; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::acquired_eca; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_acquired_eca; }
	{ void (C::*p)() = &C::clear_met_zhirov; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_zhirov; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_zhirov; }
	{ void (C::*p)() = &C::clear_met_warlord_at_base; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_warlord_at_base; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_warlord_at_base; }
	{ void (C::*p)() = &C::clear_mainc_attacked_warlord; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mainc_attacked_warlord; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mainc_attacked_warlord; }
	{ void (C::*p)() = &C::clear_warlord_defense_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::warlord_defense_kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_warlord_defense_kills; }
	{ void (C::*p)() = &C::clear_mainc_attacked_proxy_base; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mainc_attacked_proxy_base; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mainc_attacked_proxy_base; }
	{ void (C::*p)() = &C::clear_built_enhanced_grunts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::built_enhanced_grunts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_built_enhanced_grunts; }
	{ void (C::*p)() = &C::clear_a7_reached_mainframe; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::a7_reached_mainframe; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_a7_reached_mainframe; }
	{ void (C::*p)() = &C::clear_met_r17_at_cetus; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_r17_at_cetus; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_r17_at_cetus; }
	{ void (C::*p)() = &C::clear_read_decrypted_archives; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::read_decrypted_archives; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_read_decrypted_archives; }
	{ void (C::*p)() = &C::clear_bested_vlgr5; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::bested_vlgr5; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_bested_vlgr5; }
	{ void (C::*p)() = &C::clear_found_hidden_lab; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::found_hidden_lab; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_found_hidden_lab; }
	{ void (C::*p)() = &C::clear_decrypted_a0_command; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decrypted_a0_command; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_decrypted_a0_command; }
	{ void (C::*p)() = &C::clear_used_core_reset_matrix; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used_core_reset_matrix; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used_core_reset_matrix; }
	{ void (C::*p)() = &C::clear_hacked_protovariant; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacked_protovariant; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacked_protovariant; }
	{ void (C::*p)() = &C::clear_met_r17_at_research; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_r17_at_research; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_r17_at_research; }
	{ void (C::*p)() = &C::clear_met_warlord_at_research; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_warlord_at_research; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_warlord_at_research; }
	{ void (C::*p)() = &C::clear_invited_to_help_at_command; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::invited_to_help_at_command; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_invited_to_help_at_command; }
	{ void (C::*p)() = &C::clear_hacked_god_mode; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacked_god_mode; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacked_god_mode; }
	{ void (C::*p)() = &C::clear_scanned_by_researcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scanned_by_researcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scanned_by_researcher; }
	{ void (C::*p)() = &C::clear_pursued_by_intercept; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pursued_by_intercept; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pursued_by_intercept; }
	{ void (C::*p)() = &C::clear_acquired_sgemp; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::acquired_sgemp; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_acquired_sgemp; }
	{ void (C::*p)() = &C::clear_met_sigix; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_sigix; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_sigix; }
	{ void (C::*p)() = &C::clear_destroyed_superfortress; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_superfortress; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_superfortress; }
	{ void (C::*p)() = &C::clear_met_optimus_at_protoforge; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_optimus_at_protoforge; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_optimus_at_protoforge; }
	{ void (C::*p)() = &C::clear_executed_drillbomb_mission; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::executed_drillbomb_mission; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_executed_drillbomb_mission; }
	{ void (C::*p)() = &C::clear_optimus_survived_to_0b1; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::optimus_survived_to_0b1; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_optimus_survived_to_0b1; }
	{ void (C::*p)() = &C::clear_detonated_l2_power_cell; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::detonated_l2_power_cell; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_detonated_l2_power_cell; }
	{ void (C::*p)() = &C::clear_activated_exoskeleton; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::activated_exoskeleton; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_activated_exoskeleton; }
	{ void (C::*p)() = &C::clear_integrated_exoskeleton; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::integrated_exoskeleton; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_integrated_exoskeleton; }
	{ void (C::*p)() = &C::clear_delivered_sgemp; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::delivered_sgemp; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_delivered_sgemp; }
	{ void (C::*p)() = &C::clear_recovered_sigix_corpse; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recovered_sigix_corpse; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recovered_sigix_corpse; }
	{ void (C::*p)() = &C::clear_escaped_with_sigix; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::escaped_with_sigix; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_escaped_with_sigix; }
	{ void (C::*p)() = &C::clear_escaped_with_exosigix; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::escaped_with_exosigix; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_escaped_with_exosigix; }
	{ void (C::*p)() = &C::clear_destroyed_mainc_guards; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_mainc_guards; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_mainc_guards; }
	{ void (C::*p)() = &C::clear_met_mainc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_mainc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_mainc; }
	{ void (C::*p)() = &C::clear_hacked_mainc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacked_mainc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacked_mainc; }
	{ void (C::*p)() = &C::clear_destroyed_mainc_shell; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_mainc_shell; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_mainc_shell; }
	{ void (C::*p)() = &C::clear_destroyed_mainc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_mainc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_mainc; }
	{ void (C::*p)() = &C::clear_zhirov_destroyed_mainc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zhirov_destroyed_mainc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zhirov_destroyed_mainc; }
	{ void (C::*p)() = &C::clear_used_0b10_conduit; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used_0b10_conduit; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used_0b10_conduit; }
	{ void (C::*p)() = &C::clear_met_warlord_at_command; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_warlord_at_command; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_warlord_at_command; }
	{ void (C::*p)() = &C::clear_met_architect; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::met_architect; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_met_architect; }
	{ void (C::*p)() = &C::clear_started_test_138b; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::started_test_138b; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_started_test_138b; }
	{ void (C::*p)() = &C::clear_started_test_138c; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::started_test_138c; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_started_test_138c; }
	{ void (C::*p)() = &C::clear_destroyed_a8; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a8; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a8; }
	{ void (C::*p)() = &C::clear_destroyed_a6; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a6; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a6; }
	{ void (C::*p)() = &C::clear_destroyed_a5; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a5; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a5; }
	{ void (C::*p)() = &C::clear_destroyed_a4; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a4; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a4; }
	{ void (C::*p)() = &C::clear_destroyed_a3; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a3; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a3; }
	{ void (C::*p)() = &C::clear_destroyed_a2; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_a2; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_a2; }
	{ void (C::*p)() = &C::clear_destroyed_architect; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroyed_architect; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroyed_architect; }
	{ void (C::*p)() = &C::clear_win; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::win; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_win; }
	{ void (C::*p)() = &C::clear_win_speed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::win_speed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_win_speed; }
	{ void (C::*p)() = &C::clear_challenge_win; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::challenge_win; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_challenge_win; }
	{ void (C::*p)() = &C::clear_friendly_fire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::friendly_fire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_friendly_fire; }
}
#undef C

#define C Protobuf::Location
struct OpPb_A_Location { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Location); };
template struct OpPb_Rob<OpPb_A_Location, &C::GetArenaNoVirtual>;
struct OpPb_M_Location { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Location); };
template struct OpPb_Rob<OpPb_M_Location, &C::MaybeArenaPtr>;
void op_pb_use_Location()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Location()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Location()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_depth; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::depth; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_depth; }
	{ void (C::*p)() = &C::clear_map; }
	{ ::Protobuf::MapType (C::*p)() const = &C::map; }
	{ void (C::*p)(::Protobuf::MapType value) = &C::set_map; }
}
#undef C

#define C Protobuf::Cogmind_VariableValue
struct OpPb_A_Cogmind_VariableValue { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Cogmind_VariableValue); };
template struct OpPb_Rob<OpPb_A_Cogmind_VariableValue, &C::GetArenaNoVirtual>;
struct OpPb_M_Cogmind_VariableValue { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Cogmind_VariableValue); };
template struct OpPb_Rob<OpPb_M_Cogmind_VariableValue, &C::MaybeArenaPtr>;
void op_pb_use_Cogmind_VariableValue()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Cogmind_VariableValue()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Cogmind_VariableValue()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_current; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::current; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_current; }
	{ void (C::*p)() = &C::clear_maximum; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::maximum; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_maximum; }
}
#undef C

#define C Protobuf::Cogmind_Corruption
struct OpPb_A_Cogmind_Corruption { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Cogmind_Corruption); };
template struct OpPb_Rob<OpPb_A_Cogmind_Corruption, &C::GetArenaNoVirtual>;
struct OpPb_M_Cogmind_Corruption { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Cogmind_Corruption); };
template struct OpPb_Rob<OpPb_M_Cogmind_Corruption, &C::MaybeArenaPtr>;
void op_pb_use_Cogmind_Corruption()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Cogmind_Corruption()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Cogmind_Corruption()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_value; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::value; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_value; }
	{ void (C::*p)() = &C::clear_membrane; }
	{ bool (C::*p)() const = &C::membrane; }
	{ void (C::*p)(bool value) = &C::set_membrane; }
}
#undef C

#define C Protobuf::Cogmind_Temperature
struct OpPb_A_Cogmind_Temperature { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Cogmind_Temperature); };
template struct OpPb_Rob<OpPb_A_Cogmind_Temperature, &C::GetArenaNoVirtual>;
struct OpPb_M_Cogmind_Temperature { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Cogmind_Temperature); };
template struct OpPb_Rob<OpPb_M_Cogmind_Temperature, &C::MaybeArenaPtr>;
void op_pb_use_Cogmind_Temperature()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Cogmind_Temperature()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Cogmind_Temperature()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_heat; }
	{ ::Protobuf::HeatLevelType (C::*p)() const = &C::heat; }
	{ void (C::*p)(::Protobuf::HeatLevelType value) = &C::set_heat; }
	{ void (C::*p)() = &C::clear_value; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::value; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_value; }
	{ void (C::*p)() = &C::clear_thermoelectric_network; }
	{ bool (C::*p)() const = &C::thermoelectric_network; }
	{ void (C::*p)(bool value) = &C::set_thermoelectric_network; }
}
#undef C

#define C Protobuf::Cogmind_Movement
struct OpPb_A_Cogmind_Movement { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Cogmind_Movement); };
template struct OpPb_Rob<OpPb_A_Cogmind_Movement, &C::GetArenaNoVirtual>;
struct OpPb_M_Cogmind_Movement { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Cogmind_Movement); };
template struct OpPb_Rob<OpPb_M_Cogmind_Movement, &C::MaybeArenaPtr>;
void op_pb_use_Cogmind_Movement()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Cogmind_Movement()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Cogmind_Movement()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_mode; }
	{ ::Protobuf::MoveModeType (C::*p)() const = &C::mode; }
	{ void (C::*p)(::Protobuf::MoveModeType value) = &C::set_mode; }
	{ void (C::*p)() = &C::clear_speed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::speed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_speed; }
	{ void (C::*p)() = &C::clear_overweight_factor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overweight_factor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overweight_factor; }
	{ void (C::*p)() = &C::clear_teleportitis_level; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::teleportitis_level; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_teleportitis_level; }
}
#undef C

#define C Protobuf::Cogmind
struct OpPb_A_Cogmind { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Cogmind); };
template struct OpPb_Rob<OpPb_A_Cogmind, &C::GetArenaNoVirtual>;
struct OpPb_M_Cogmind { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Cogmind); };
template struct OpPb_Rob<OpPb_M_Cogmind, &C::MaybeArenaPtr>;
void op_pb_use_Cogmind()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Cogmind()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Cogmind()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_core_integrity; }
	{ void (C::*p)() = &C::clear_core_integrity; }
	{ const ::Protobuf::Cogmind_VariableValue& (C::*p)() const = &C::core_integrity; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::release_core_integrity; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::mutable_core_integrity; }
	{ void (C::*p)(::Protobuf::Cogmind_VariableValue* core_integrity) = &C::set_allocated_core_integrity; }
	{ bool (C::*p)() const = &C::has_matter; }
	{ void (C::*p)() = &C::clear_matter; }
	{ const ::Protobuf::Cogmind_VariableValue& (C::*p)() const = &C::matter; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::release_matter; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::mutable_matter; }
	{ void (C::*p)(::Protobuf::Cogmind_VariableValue* matter) = &C::set_allocated_matter; }
	{ bool (C::*p)() const = &C::has_energy; }
	{ void (C::*p)() = &C::clear_energy; }
	{ const ::Protobuf::Cogmind_VariableValue& (C::*p)() const = &C::energy; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::release_energy; }
	{ ::Protobuf::Cogmind_VariableValue* (C::*p)() = &C::mutable_energy; }
	{ void (C::*p)(::Protobuf::Cogmind_VariableValue* energy) = &C::set_allocated_energy; }
	{ void (C::*p)() = &C::clear_system_corruption; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::system_corruption; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_system_corruption; }
	{ bool (C::*p)() const = &C::has_corruption; }
	{ void (C::*p)() = &C::clear_corruption; }
	{ const ::Protobuf::Cogmind_Corruption& (C::*p)() const = &C::corruption; }
	{ ::Protobuf::Cogmind_Corruption* (C::*p)() = &C::release_corruption; }
	{ ::Protobuf::Cogmind_Corruption* (C::*p)() = &C::mutable_corruption; }
	{ void (C::*p)(::Protobuf::Cogmind_Corruption* corruption) = &C::set_allocated_corruption; }
	{ bool (C::*p)() const = &C::has_temperature; }
	{ void (C::*p)() = &C::clear_temperature; }
	{ const ::Protobuf::Cogmind_Temperature& (C::*p)() const = &C::temperature; }
	{ ::Protobuf::Cogmind_Temperature* (C::*p)() = &C::release_temperature; }
	{ ::Protobuf::Cogmind_Temperature* (C::*p)() = &C::mutable_temperature; }
	{ void (C::*p)(::Protobuf::Cogmind_Temperature* temperature) = &C::set_allocated_temperature; }
	{ bool (C::*p)() const = &C::has_movement; }
	{ void (C::*p)() = &C::clear_movement; }
	{ const ::Protobuf::Cogmind_Movement& (C::*p)() const = &C::movement; }
	{ ::Protobuf::Cogmind_Movement* (C::*p)() = &C::release_movement; }
	{ ::Protobuf::Cogmind_Movement* (C::*p)() = &C::mutable_movement; }
	{ void (C::*p)(::Protobuf::Cogmind_Movement* movement) = &C::set_allocated_movement; }
	{ bool (C::*p)() const = &C::has_location; }
	{ void (C::*p)() = &C::clear_location; }
	{ const ::Protobuf::Location& (C::*p)() const = &C::location; }
	{ ::Protobuf::Location* (C::*p)() = &C::release_location; }
	{ ::Protobuf::Location* (C::*p)() = &C::mutable_location; }
	{ void (C::*p)(::Protobuf::Location* location) = &C::set_allocated_location; }
}
#undef C

#define C Protobuf::PartSection
struct OpPb_A_PartSection { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PartSection); };
template struct OpPb_Rob<OpPb_A_PartSection, &C::GetArenaNoVirtual>;
struct OpPb_M_PartSection { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PartSection); };
template struct OpPb_Rob<OpPb_M_PartSection, &C::MaybeArenaPtr>;
void op_pb_use_PartSection()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PartSection()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PartSection()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_slots; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slots; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slots; }
	{ int (C::*p)() const = &C::parts_size; }
	{ void (C::*p)() = &C::clear_parts; }
	{ const ::std::string& (C::*p)(int index) const = &C::parts; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_parts; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_parts; }
	{ void (C::*p)(int index, const char* value) = &C::set_parts; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_parts; }
	{ ::std::string* (C::*p)() = &C::add_parts; }
	{ void (C::*p)(const ::std::string& value) = &C::add_parts; }
	{ void (C::*p)(const char* value) = &C::add_parts; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_parts; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::parts; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_parts; }
}
#undef C

#define C Protobuf::Parts
struct OpPb_A_Parts { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Parts); };
template struct OpPb_Rob<OpPb_A_Parts, &C::GetArenaNoVirtual>;
struct OpPb_M_Parts { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Parts); };
template struct OpPb_Rob<OpPb_M_Parts, &C::MaybeArenaPtr>;
void op_pb_use_Parts()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Parts()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Parts()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_power; }
	{ void (C::*p)() = &C::clear_power; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::power; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_power; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_power; }
	{ void (C::*p)(::Protobuf::PartSection* power) = &C::set_allocated_power; }
	{ bool (C::*p)() const = &C::has_propulsion; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::propulsion; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_propulsion; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_propulsion; }
	{ void (C::*p)(::Protobuf::PartSection* propulsion) = &C::set_allocated_propulsion; }
	{ bool (C::*p)() const = &C::has_utility; }
	{ void (C::*p)() = &C::clear_utility; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::utility; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_utility; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_utility; }
	{ void (C::*p)(::Protobuf::PartSection* utility) = &C::set_allocated_utility; }
	{ bool (C::*p)() const = &C::has_weapon; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::weapon; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_weapon; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_weapon; }
	{ void (C::*p)(::Protobuf::PartSection* weapon) = &C::set_allocated_weapon; }
	{ bool (C::*p)() const = &C::has_inventory; }
	{ void (C::*p)() = &C::clear_inventory; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::inventory; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_inventory; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_inventory; }
	{ void (C::*p)(::Protobuf::PartSection* inventory) = &C::set_allocated_inventory; }
}
#undef C

#define C Protobuf::PeakState
struct OpPb_A_PeakState { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PeakState); };
template struct OpPb_Rob<OpPb_A_PeakState, &C::GetArenaNoVirtual>;
struct OpPb_M_PeakState { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PeakState); };
template struct OpPb_Rob<OpPb_M_PeakState, &C::MaybeArenaPtr>;
void op_pb_use_PeakState()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PeakState()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PeakState()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_power; }
	{ void (C::*p)() = &C::clear_power; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::power; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_power; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_power; }
	{ void (C::*p)(::Protobuf::PartSection* power) = &C::set_allocated_power; }
	{ bool (C::*p)() const = &C::has_propulsion; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::propulsion; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_propulsion; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_propulsion; }
	{ void (C::*p)(::Protobuf::PartSection* propulsion) = &C::set_allocated_propulsion; }
	{ bool (C::*p)() const = &C::has_utility; }
	{ void (C::*p)() = &C::clear_utility; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::utility; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_utility; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_utility; }
	{ void (C::*p)(::Protobuf::PartSection* utility) = &C::set_allocated_utility; }
	{ bool (C::*p)() const = &C::has_weapon; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::weapon; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_weapon; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_weapon; }
	{ void (C::*p)(::Protobuf::PartSection* weapon) = &C::set_allocated_weapon; }
	{ bool (C::*p)() const = &C::has_inventory; }
	{ void (C::*p)() = &C::clear_inventory; }
	{ const ::Protobuf::PartSection& (C::*p)() const = &C::inventory; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::release_inventory; }
	{ ::Protobuf::PartSection* (C::*p)() = &C::mutable_inventory; }
	{ void (C::*p)(::Protobuf::PartSection* inventory) = &C::set_allocated_inventory; }
	{ void (C::*p)() = &C::clear_rating; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::rating; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_rating; }
}
#undef C

#define C Protobuf::Favorites_Power
struct OpPb_A_Favorites_Power { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Favorites_Power); };
template struct OpPb_Rob<OpPb_A_Favorites_Power, &C::GetArenaNoVirtual>;
struct OpPb_M_Favorites_Power { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Favorites_Power); };
template struct OpPb_Rob<OpPb_M_Favorites_Power, &C::MaybeArenaPtr>;
void op_pb_use_Favorites_Power()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Favorites_Power()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Favorites_Power()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ const ::std::string& (C::*p)() const = &C::overall; }
	{ void (C::*p)(const ::std::string& value) = &C::set_overall; }
	{ void (C::*p)(const char* value) = &C::set_overall; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_overall; }
	{ ::std::string* (C::*p)() = &C::mutable_overall; }
	{ ::std::string* (C::*p)() = &C::release_overall; }
	{ void (C::*p)(::std::string* overall) = &C::set_allocated_overall; }
	{ void (C::*p)() = &C::clear_engine; }
	{ const ::std::string& (C::*p)() const = &C::engine; }
	{ void (C::*p)(const ::std::string& value) = &C::set_engine; }
	{ void (C::*p)(const char* value) = &C::set_engine; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_engine; }
	{ ::std::string* (C::*p)() = &C::mutable_engine; }
	{ ::std::string* (C::*p)() = &C::release_engine; }
	{ void (C::*p)(::std::string* engine) = &C::set_allocated_engine; }
	{ void (C::*p)() = &C::clear_power_core; }
	{ const ::std::string& (C::*p)() const = &C::power_core; }
	{ void (C::*p)(const ::std::string& value) = &C::set_power_core; }
	{ void (C::*p)(const char* value) = &C::set_power_core; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_power_core; }
	{ ::std::string* (C::*p)() = &C::mutable_power_core; }
	{ ::std::string* (C::*p)() = &C::release_power_core; }
	{ void (C::*p)(::std::string* power_core) = &C::set_allocated_power_core; }
	{ void (C::*p)() = &C::clear_reactor; }
	{ const ::std::string& (C::*p)() const = &C::reactor; }
	{ void (C::*p)(const ::std::string& value) = &C::set_reactor; }
	{ void (C::*p)(const char* value) = &C::set_reactor; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_reactor; }
	{ ::std::string* (C::*p)() = &C::mutable_reactor; }
	{ ::std::string* (C::*p)() = &C::release_reactor; }
	{ void (C::*p)(::std::string* reactor) = &C::set_allocated_reactor; }
}
#undef C

#define C Protobuf::Favorites_Propulsion
struct OpPb_A_Favorites_Propulsion { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Favorites_Propulsion); };
template struct OpPb_Rob<OpPb_A_Favorites_Propulsion, &C::GetArenaNoVirtual>;
struct OpPb_M_Favorites_Propulsion { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Favorites_Propulsion); };
template struct OpPb_Rob<OpPb_M_Favorites_Propulsion, &C::MaybeArenaPtr>;
void op_pb_use_Favorites_Propulsion()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Favorites_Propulsion()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Favorites_Propulsion()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ const ::std::string& (C::*p)() const = &C::overall; }
	{ void (C::*p)(const ::std::string& value) = &C::set_overall; }
	{ void (C::*p)(const char* value) = &C::set_overall; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_overall; }
	{ ::std::string* (C::*p)() = &C::mutable_overall; }
	{ ::std::string* (C::*p)() = &C::release_overall; }
	{ void (C::*p)(::std::string* overall) = &C::set_allocated_overall; }
	{ void (C::*p)() = &C::clear_treads; }
	{ const ::std::string& (C::*p)() const = &C::treads; }
	{ void (C::*p)(const ::std::string& value) = &C::set_treads; }
	{ void (C::*p)(const char* value) = &C::set_treads; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_treads; }
	{ ::std::string* (C::*p)() = &C::mutable_treads; }
	{ ::std::string* (C::*p)() = &C::release_treads; }
	{ void (C::*p)(::std::string* treads) = &C::set_allocated_treads; }
	{ void (C::*p)() = &C::clear_leg; }
	{ const ::std::string& (C::*p)() const = &C::leg; }
	{ void (C::*p)(const ::std::string& value) = &C::set_leg; }
	{ void (C::*p)(const char* value) = &C::set_leg; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_leg; }
	{ ::std::string* (C::*p)() = &C::mutable_leg; }
	{ ::std::string* (C::*p)() = &C::release_leg; }
	{ void (C::*p)(::std::string* leg) = &C::set_allocated_leg; }
	{ void (C::*p)() = &C::clear_wheel; }
	{ const ::std::string& (C::*p)() const = &C::wheel; }
	{ void (C::*p)(const ::std::string& value) = &C::set_wheel; }
	{ void (C::*p)(const char* value) = &C::set_wheel; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_wheel; }
	{ ::std::string* (C::*p)() = &C::mutable_wheel; }
	{ ::std::string* (C::*p)() = &C::release_wheel; }
	{ void (C::*p)(::std::string* wheel) = &C::set_allocated_wheel; }
	{ void (C::*p)() = &C::clear_hover_unit; }
	{ const ::std::string& (C::*p)() const = &C::hover_unit; }
	{ void (C::*p)(const ::std::string& value) = &C::set_hover_unit; }
	{ void (C::*p)(const char* value) = &C::set_hover_unit; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_hover_unit; }
	{ ::std::string* (C::*p)() = &C::mutable_hover_unit; }
	{ ::std::string* (C::*p)() = &C::release_hover_unit; }
	{ void (C::*p)(::std::string* hover_unit) = &C::set_allocated_hover_unit; }
	{ void (C::*p)() = &C::clear_flight_unit; }
	{ const ::std::string& (C::*p)() const = &C::flight_unit; }
	{ void (C::*p)(const ::std::string& value) = &C::set_flight_unit; }
	{ void (C::*p)(const char* value) = &C::set_flight_unit; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_flight_unit; }
	{ ::std::string* (C::*p)() = &C::mutable_flight_unit; }
	{ ::std::string* (C::*p)() = &C::release_flight_unit; }
	{ void (C::*p)(::std::string* flight_unit) = &C::set_allocated_flight_unit; }
}
#undef C

#define C Protobuf::Favorites_Utility
struct OpPb_A_Favorites_Utility { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Favorites_Utility); };
template struct OpPb_Rob<OpPb_A_Favorites_Utility, &C::GetArenaNoVirtual>;
struct OpPb_M_Favorites_Utility { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Favorites_Utility); };
template struct OpPb_Rob<OpPb_M_Favorites_Utility, &C::MaybeArenaPtr>;
void op_pb_use_Favorites_Utility()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Favorites_Utility()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Favorites_Utility()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ const ::std::string& (C::*p)() const = &C::overall; }
	{ void (C::*p)(const ::std::string& value) = &C::set_overall; }
	{ void (C::*p)(const char* value) = &C::set_overall; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_overall; }
	{ ::std::string* (C::*p)() = &C::mutable_overall; }
	{ ::std::string* (C::*p)() = &C::release_overall; }
	{ void (C::*p)(::std::string* overall) = &C::set_allocated_overall; }
	{ void (C::*p)() = &C::clear_device; }
	{ const ::std::string& (C::*p)() const = &C::device; }
	{ void (C::*p)(const ::std::string& value) = &C::set_device; }
	{ void (C::*p)(const char* value) = &C::set_device; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_device; }
	{ ::std::string* (C::*p)() = &C::mutable_device; }
	{ ::std::string* (C::*p)() = &C::release_device; }
	{ void (C::*p)(::std::string* device) = &C::set_allocated_device; }
	{ void (C::*p)() = &C::clear_storage; }
	{ const ::std::string& (C::*p)() const = &C::storage; }
	{ void (C::*p)(const ::std::string& value) = &C::set_storage; }
	{ void (C::*p)(const char* value) = &C::set_storage; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_storage; }
	{ ::std::string* (C::*p)() = &C::mutable_storage; }
	{ ::std::string* (C::*p)() = &C::release_storage; }
	{ void (C::*p)(::std::string* storage) = &C::set_allocated_storage; }
	{ void (C::*p)() = &C::clear_processor; }
	{ const ::std::string& (C::*p)() const = &C::processor; }
	{ void (C::*p)(const ::std::string& value) = &C::set_processor; }
	{ void (C::*p)(const char* value) = &C::set_processor; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_processor; }
	{ ::std::string* (C::*p)() = &C::mutable_processor; }
	{ ::std::string* (C::*p)() = &C::release_processor; }
	{ void (C::*p)(::std::string* processor) = &C::set_allocated_processor; }
	{ void (C::*p)() = &C::clear_hackware; }
	{ const ::std::string& (C::*p)() const = &C::hackware; }
	{ void (C::*p)(const ::std::string& value) = &C::set_hackware; }
	{ void (C::*p)(const char* value) = &C::set_hackware; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_hackware; }
	{ ::std::string* (C::*p)() = &C::mutable_hackware; }
	{ ::std::string* (C::*p)() = &C::release_hackware; }
	{ void (C::*p)(::std::string* hackware) = &C::set_allocated_hackware; }
	{ void (C::*p)() = &C::clear_protection; }
	{ const ::std::string& (C::*p)() const = &C::protection; }
	{ void (C::*p)(const ::std::string& value) = &C::set_protection; }
	{ void (C::*p)(const char* value) = &C::set_protection; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_protection; }
	{ ::std::string* (C::*p)() = &C::mutable_protection; }
	{ ::std::string* (C::*p)() = &C::release_protection; }
	{ void (C::*p)(::std::string* protection) = &C::set_allocated_protection; }
	{ void (C::*p)() = &C::clear_artifact; }
	{ const ::std::string& (C::*p)() const = &C::artifact; }
	{ void (C::*p)(const ::std::string& value) = &C::set_artifact; }
	{ void (C::*p)(const char* value) = &C::set_artifact; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_artifact; }
	{ ::std::string* (C::*p)() = &C::mutable_artifact; }
	{ ::std::string* (C::*p)() = &C::release_artifact; }
	{ void (C::*p)(::std::string* artifact) = &C::set_allocated_artifact; }
}
#undef C

#define C Protobuf::Favorites_Weapon
struct OpPb_A_Favorites_Weapon { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Favorites_Weapon); };
template struct OpPb_Rob<OpPb_A_Favorites_Weapon, &C::GetArenaNoVirtual>;
struct OpPb_M_Favorites_Weapon { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Favorites_Weapon); };
template struct OpPb_Rob<OpPb_M_Favorites_Weapon, &C::MaybeArenaPtr>;
void op_pb_use_Favorites_Weapon()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Favorites_Weapon()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Favorites_Weapon()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ const ::std::string& (C::*p)() const = &C::overall; }
	{ void (C::*p)(const ::std::string& value) = &C::set_overall; }
	{ void (C::*p)(const char* value) = &C::set_overall; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_overall; }
	{ ::std::string* (C::*p)() = &C::mutable_overall; }
	{ ::std::string* (C::*p)() = &C::release_overall; }
	{ void (C::*p)(::std::string* overall) = &C::set_allocated_overall; }
	{ void (C::*p)() = &C::clear_energy_gun; }
	{ const ::std::string& (C::*p)() const = &C::energy_gun; }
	{ void (C::*p)(const ::std::string& value) = &C::set_energy_gun; }
	{ void (C::*p)(const char* value) = &C::set_energy_gun; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_energy_gun; }
	{ ::std::string* (C::*p)() = &C::mutable_energy_gun; }
	{ ::std::string* (C::*p)() = &C::release_energy_gun; }
	{ void (C::*p)(::std::string* energy_gun) = &C::set_allocated_energy_gun; }
	{ void (C::*p)() = &C::clear_energy_cannon; }
	{ const ::std::string& (C::*p)() const = &C::energy_cannon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_energy_cannon; }
	{ void (C::*p)(const char* value) = &C::set_energy_cannon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_energy_cannon; }
	{ ::std::string* (C::*p)() = &C::mutable_energy_cannon; }
	{ ::std::string* (C::*p)() = &C::release_energy_cannon; }
	{ void (C::*p)(::std::string* energy_cannon) = &C::set_allocated_energy_cannon; }
	{ void (C::*p)() = &C::clear_ballistic_gun; }
	{ const ::std::string& (C::*p)() const = &C::ballistic_gun; }
	{ void (C::*p)(const ::std::string& value) = &C::set_ballistic_gun; }
	{ void (C::*p)(const char* value) = &C::set_ballistic_gun; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_ballistic_gun; }
	{ ::std::string* (C::*p)() = &C::mutable_ballistic_gun; }
	{ ::std::string* (C::*p)() = &C::release_ballistic_gun; }
	{ void (C::*p)(::std::string* ballistic_gun) = &C::set_allocated_ballistic_gun; }
	{ void (C::*p)() = &C::clear_ballistic_cannon; }
	{ const ::std::string& (C::*p)() const = &C::ballistic_cannon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_ballistic_cannon; }
	{ void (C::*p)(const char* value) = &C::set_ballistic_cannon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_ballistic_cannon; }
	{ ::std::string* (C::*p)() = &C::mutable_ballistic_cannon; }
	{ ::std::string* (C::*p)() = &C::release_ballistic_cannon; }
	{ void (C::*p)(::std::string* ballistic_cannon) = &C::set_allocated_ballistic_cannon; }
	{ void (C::*p)() = &C::clear_launcher; }
	{ const ::std::string& (C::*p)() const = &C::launcher; }
	{ void (C::*p)(const ::std::string& value) = &C::set_launcher; }
	{ void (C::*p)(const char* value) = &C::set_launcher; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_launcher; }
	{ ::std::string* (C::*p)() = &C::mutable_launcher; }
	{ ::std::string* (C::*p)() = &C::release_launcher; }
	{ void (C::*p)(::std::string* launcher) = &C::set_allocated_launcher; }
	{ void (C::*p)() = &C::clear_special_weapon; }
	{ const ::std::string& (C::*p)() const = &C::special_weapon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_special_weapon; }
	{ void (C::*p)(const char* value) = &C::set_special_weapon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_special_weapon; }
	{ ::std::string* (C::*p)() = &C::mutable_special_weapon; }
	{ ::std::string* (C::*p)() = &C::release_special_weapon; }
	{ void (C::*p)(::std::string* special_weapon) = &C::set_allocated_special_weapon; }
	{ void (C::*p)() = &C::clear_impact_weapon; }
	{ const ::std::string& (C::*p)() const = &C::impact_weapon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_impact_weapon; }
	{ void (C::*p)(const char* value) = &C::set_impact_weapon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_impact_weapon; }
	{ ::std::string* (C::*p)() = &C::mutable_impact_weapon; }
	{ ::std::string* (C::*p)() = &C::release_impact_weapon; }
	{ void (C::*p)(::std::string* impact_weapon) = &C::set_allocated_impact_weapon; }
	{ void (C::*p)() = &C::clear_slashing_weapon; }
	{ const ::std::string& (C::*p)() const = &C::slashing_weapon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_slashing_weapon; }
	{ void (C::*p)(const char* value) = &C::set_slashing_weapon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_slashing_weapon; }
	{ ::std::string* (C::*p)() = &C::mutable_slashing_weapon; }
	{ ::std::string* (C::*p)() = &C::release_slashing_weapon; }
	{ void (C::*p)(::std::string* slashing_weapon) = &C::set_allocated_slashing_weapon; }
	{ void (C::*p)() = &C::clear_piercing_weapon; }
	{ const ::std::string& (C::*p)() const = &C::piercing_weapon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_piercing_weapon; }
	{ void (C::*p)(const char* value) = &C::set_piercing_weapon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_piercing_weapon; }
	{ ::std::string* (C::*p)() = &C::mutable_piercing_weapon; }
	{ ::std::string* (C::*p)() = &C::release_piercing_weapon; }
	{ void (C::*p)(::std::string* piercing_weapon) = &C::set_allocated_piercing_weapon; }
	{ void (C::*p)() = &C::clear_special_melee_weapon; }
	{ const ::std::string& (C::*p)() const = &C::special_melee_weapon; }
	{ void (C::*p)(const ::std::string& value) = &C::set_special_melee_weapon; }
	{ void (C::*p)(const char* value) = &C::set_special_melee_weapon; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_special_melee_weapon; }
	{ ::std::string* (C::*p)() = &C::mutable_special_melee_weapon; }
	{ ::std::string* (C::*p)() = &C::release_special_melee_weapon; }
	{ void (C::*p)(::std::string* special_melee_weapon) = &C::set_allocated_special_melee_weapon; }
}
#undef C

#define C Protobuf::Favorites
struct OpPb_A_Favorites { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Favorites); };
template struct OpPb_Rob<OpPb_A_Favorites, &C::GetArenaNoVirtual>;
struct OpPb_M_Favorites { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Favorites); };
template struct OpPb_Rob<OpPb_M_Favorites, &C::MaybeArenaPtr>;
void op_pb_use_Favorites()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Favorites()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Favorites()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_power; }
	{ void (C::*p)() = &C::clear_power; }
	{ const ::Protobuf::Favorites_Power& (C::*p)() const = &C::power; }
	{ ::Protobuf::Favorites_Power* (C::*p)() = &C::release_power; }
	{ ::Protobuf::Favorites_Power* (C::*p)() = &C::mutable_power; }
	{ void (C::*p)(::Protobuf::Favorites_Power* power) = &C::set_allocated_power; }
	{ bool (C::*p)() const = &C::has_propulsion; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ const ::Protobuf::Favorites_Propulsion& (C::*p)() const = &C::propulsion; }
	{ ::Protobuf::Favorites_Propulsion* (C::*p)() = &C::release_propulsion; }
	{ ::Protobuf::Favorites_Propulsion* (C::*p)() = &C::mutable_propulsion; }
	{ void (C::*p)(::Protobuf::Favorites_Propulsion* propulsion) = &C::set_allocated_propulsion; }
	{ bool (C::*p)() const = &C::has_utility; }
	{ void (C::*p)() = &C::clear_utility; }
	{ const ::Protobuf::Favorites_Utility& (C::*p)() const = &C::utility; }
	{ ::Protobuf::Favorites_Utility* (C::*p)() = &C::release_utility; }
	{ ::Protobuf::Favorites_Utility* (C::*p)() = &C::mutable_utility; }
	{ void (C::*p)(::Protobuf::Favorites_Utility* utility) = &C::set_allocated_utility; }
	{ bool (C::*p)() const = &C::has_weapon; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ const ::Protobuf::Favorites_Weapon& (C::*p)() const = &C::weapon; }
	{ ::Protobuf::Favorites_Weapon* (C::*p)() = &C::release_weapon; }
	{ ::Protobuf::Favorites_Weapon* (C::*p)() = &C::mutable_weapon; }
	{ void (C::*p)(::Protobuf::Favorites_Weapon* weapon) = &C::set_allocated_weapon; }
}
#undef C

#define C Protobuf::ClassDistribution_ClassEntry
struct OpPb_A_ClassDistribution_ClassEntry { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_ClassDistribution_ClassEntry); };
template struct OpPb_Rob<OpPb_A_ClassDistribution_ClassEntry, &C::GetArenaNoVirtual>;
struct OpPb_M_ClassDistribution_ClassEntry { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_ClassDistribution_ClassEntry); };
template struct OpPb_Rob<OpPb_M_ClassDistribution_ClassEntry, &C::MaybeArenaPtr>;
void op_pb_use_ClassDistribution_ClassEntry()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_ClassDistribution_ClassEntry()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_ClassDistribution_ClassEntry()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_percent; }
}
#undef C

#define C Protobuf::ClassDistribution
struct OpPb_A_ClassDistribution { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_ClassDistribution); };
template struct OpPb_Rob<OpPb_A_ClassDistribution, &C::GetArenaNoVirtual>;
struct OpPb_M_ClassDistribution { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_ClassDistribution); };
template struct OpPb_Rob<OpPb_M_ClassDistribution, &C::MaybeArenaPtr>;
void op_pb_use_ClassDistribution()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_ClassDistribution()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_ClassDistribution()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::classes_size; }
	{ void (C::*p)() = &C::clear_classes; }
	{ const ::Protobuf::ClassDistribution_ClassEntry& (C::*p)(int index) const = &C::classes; }
	{ ::Protobuf::ClassDistribution_ClassEntry* (C::*p)(int index) = &C::mutable_classes; }
	{ ::Protobuf::ClassDistribution_ClassEntry* (C::*p)() = &C::add_classes; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::ClassDistribution_ClassEntry >* (C::*p)() = &C::mutable_classes; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::ClassDistribution_ClassEntry >& (C::*p)() const = &C::classes; }
}
#undef C

#define C Protobuf::LastMessages
struct OpPb_A_LastMessages { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_LastMessages); };
template struct OpPb_Rob<OpPb_A_LastMessages, &C::GetArenaNoVirtual>;
struct OpPb_M_LastMessages { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_LastMessages); };
template struct OpPb_Rob<OpPb_M_LastMessages, &C::MaybeArenaPtr>;
void op_pb_use_LastMessages()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_LastMessages()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_LastMessages()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::messages_size; }
	{ void (C::*p)() = &C::clear_messages; }
	{ const ::std::string& (C::*p)(int index) const = &C::messages; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_messages; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_messages; }
	{ void (C::*p)(int index, const char* value) = &C::set_messages; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_messages; }
	{ ::std::string* (C::*p)() = &C::add_messages; }
	{ void (C::*p)(const ::std::string& value) = &C::add_messages; }
	{ void (C::*p)(const char* value) = &C::add_messages; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_messages; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::messages; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_messages; }
}
#undef C

#define C Protobuf::HistoryEventWin
struct OpPb_A_HistoryEventWin { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_HistoryEventWin); };
template struct OpPb_Rob<OpPb_A_HistoryEventWin, &C::GetArenaNoVirtual>;
struct OpPb_M_HistoryEventWin { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_HistoryEventWin); };
template struct OpPb_Rob<OpPb_M_HistoryEventWin, &C::MaybeArenaPtr>;
void op_pb_use_HistoryEventWin()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_HistoryEventWin()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_HistoryEventWin()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_turn; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::turn; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_turn; }
	{ void (C::*p)() = &C::clear_event; }
	{ const ::std::string& (C::*p)() const = &C::event; }
	{ void (C::*p)(const ::std::string& value) = &C::set_event; }
	{ void (C::*p)(const char* value) = &C::set_event; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_event; }
	{ ::std::string* (C::*p)() = &C::mutable_event; }
	{ ::std::string* (C::*p)() = &C::release_event; }
	{ void (C::*p)(::std::string* event) = &C::set_allocated_event; }
}
#undef C

#define C Protobuf::Map
struct OpPb_A_Map { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Map); };
template struct OpPb_Rob<OpPb_A_Map, &C::GetArenaNoVirtual>;
struct OpPb_M_Map { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Map); };
template struct OpPb_Rob<OpPb_M_Map, &C::MaybeArenaPtr>;
void op_pb_use_Map()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Map()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Map()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::lines_size; }
	{ void (C::*p)() = &C::clear_lines; }
	{ const ::std::string& (C::*p)(int index) const = &C::lines; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_lines; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_lines; }
	{ void (C::*p)(int index, const char* value) = &C::set_lines; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_lines; }
	{ ::std::string* (C::*p)() = &C::add_lines; }
	{ void (C::*p)(const ::std::string& value) = &C::add_lines; }
	{ void (C::*p)(const char* value) = &C::add_lines; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_lines; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::lines; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_lines; }
}
#undef C

#define C Protobuf::BestStates
struct OpPb_A_BestStates { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_BestStates); };
template struct OpPb_Rob<OpPb_A_BestStates, &C::GetArenaNoVirtual>;
struct OpPb_M_BestStates { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_BestStates); };
template struct OpPb_Rob<OpPb_M_BestStates, &C::MaybeArenaPtr>;
void op_pb_use_BestStates()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_BestStates()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_BestStates()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_heat_dissipation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_dissipation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_dissipation; }
	{ void (C::*p)() = &C::clear_coolant_potential; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::coolant_potential; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_coolant_potential; }
	{ void (C::*p)() = &C::clear_energy_generation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_generation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_generation; }
	{ void (C::*p)() = &C::clear_energy_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_capacity; }
	{ void (C::*p)() = &C::clear_matter_stores; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_stores; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_stores; }
	{ void (C::*p)() = &C::clear_matter_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_capacity; }
	{ void (C::*p)() = &C::clear_sight_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sight_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sight_range; }
	{ void (C::*p)() = &C::clear_robot_scan_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_scan_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_scan_range; }
	{ void (C::*p)() = &C::clear_terrain_scan_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terrain_scan_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terrain_scan_range; }
	{ void (C::*p)() = &C::clear_terrain_scan_density; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terrain_scan_density; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terrain_scan_density; }
	{ void (C::*p)() = &C::clear_ecm_strength; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ecm_strength; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ecm_strength; }
	{ void (C::*p)() = &C::clear_jamming_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::jamming_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_jamming_range; }
	{ void (C::*p)() = &C::clear_cloak_strength; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cloak_strength; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cloak_strength; }
	{ void (C::*p)() = &C::clear_power_amplification; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power_amplification; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power_amplification; }
	{ void (C::*p)() = &C::clear_additional_mass_support; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::additional_mass_support; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_additional_mass_support; }
	{ void (C::*p)() = &C::clear_base_temperature; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::base_temperature; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_base_temperature; }
	{ void (C::*p)() = &C::clear_em_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::em_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_em_shielding; }
	{ void (C::*p)() = &C::clear_corruption_containment; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corruption_containment; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corruption_containment; }
	{ void (C::*p)() = &C::clear_corruption_block; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corruption_block; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corruption_block; }
	{ void (C::*p)() = &C::clear_heat_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_shielding; }
	{ void (C::*p)() = &C::clear_armor_coverage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::armor_coverage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_armor_coverage; }
	{ void (C::*p)() = &C::clear_resistance_ki; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_ki; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_ki; }
	{ void (C::*p)() = &C::clear_resistance_th; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_th; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_th; }
	{ void (C::*p)() = &C::clear_resistance_ex; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_ex; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_ex; }
	{ void (C::*p)() = &C::clear_resistance_em; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_em; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_em; }
	{ void (C::*p)() = &C::clear_resistance_i; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_i; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_i; }
	{ void (C::*p)() = &C::clear_resistance_s; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_s; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_s; }
	{ void (C::*p)() = &C::clear_resistance_p; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resistance_p; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resistance_p; }
	{ void (C::*p)() = &C::clear_core_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core_shielding; }
	{ void (C::*p)() = &C::clear_power_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power_shielding; }
	{ void (C::*p)() = &C::clear_propulsion_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion_shielding; }
	{ void (C::*p)() = &C::clear_utility_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility_shielding; }
	{ void (C::*p)() = &C::clear_weapon_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon_shielding; }
	{ void (C::*p)() = &C::clear_point_defense_rating; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::point_defense_rating; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_point_defense_rating; }
	{ void (C::*p)() = &C::clear_projectile_deflection; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::projectile_deflection; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_projectile_deflection; }
	{ void (C::*p)() = &C::clear_thermal_conversion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermal_conversion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermal_conversion; }
	{ void (C::*p)() = &C::clear_reclamation_efficiency; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reclamation_efficiency; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reclamation_efficiency; }
	{ void (C::*p)() = &C::clear_weapon_cycling; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon_cycling; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon_cycling; }
	{ void (C::*p)() = &C::clear_melee_speed_boost; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee_speed_boost; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee_speed_boost; }
	{ void (C::*p)() = &C::clear_phase_shifting; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phase_shifting; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phase_shifting; }
	{ void (C::*p)() = &C::clear_evasion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::evasion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_evasion; }
	{ void (C::*p)() = &C::clear_targeting_accuracy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::targeting_accuracy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_targeting_accuracy; }
	{ void (C::*p)() = &C::clear_melee_accuracy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee_accuracy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee_accuracy; }
	{ void (C::*p)() = &C::clear_launcher_accuracy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::launcher_accuracy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_launcher_accuracy; }
	{ void (C::*p)() = &C::clear_target_analysis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::target_analysis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_target_analysis; }
	{ void (C::*p)() = &C::clear_core_analysis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core_analysis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core_analysis; }
	{ void (C::*p)() = &C::clear_armor_integrity_analysis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::armor_integrity_analysis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_armor_integrity_analysis; }
	{ void (C::*p)() = &C::clear_recoil_reduction; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recoil_reduction; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recoil_reduction; }
	{ void (C::*p)() = &C::clear_matter_filtering; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_filtering; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_filtering; }
	{ void (C::*p)() = &C::clear_energy_filtering; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_filtering; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_filtering; }
	{ void (C::*p)() = &C::clear_particle_charging; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::particle_charging; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_particle_charging; }
	{ void (C::*p)() = &C::clear_kinecelleration; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinecelleration; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinecelleration; }
	{ void (C::*p)() = &C::clear_force_boost; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::force_boost; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_force_boost; }
	{ void (C::*p)() = &C::clear_momentum_increase; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::momentum_increase; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_momentum_increase; }
	{ void (C::*p)() = &C::clear_overload_amplification; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overload_amplification; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overload_amplification; }
	{ void (C::*p)() = &C::clear_overload_regulation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overload_regulation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overload_regulation; }
	{ void (C::*p)() = &C::clear_salvage_targeting; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::salvage_targeting; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_salvage_targeting; }
	{ void (C::*p)() = &C::clear_stasis_canceling; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::stasis_canceling; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_stasis_canceling; }
	{ void (C::*p)() = &C::clear_offensive_hacking; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::offensive_hacking; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_offensive_hacking; }
	{ void (C::*p)() = &C::clear_defensive_hacking; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::defensive_hacking; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_defensive_hacking; }
	{ void (C::*p)() = &C::clear_relay_coupler_types; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::relay_coupler_types; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_relay_coupler_types; }
	{ void (C::*p)() = &C::clear_relay_coupler_value; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::relay_coupler_value; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_relay_coupler_value; }
	{ void (C::*p)() = &C::clear_authchip_count; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::authchip_count; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_authchip_count; }
	{ void (C::*p)() = &C::clear_trap_extractor_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trap_extractor_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trap_extractor_capacity; }
}
#undef C

#define C Protobuf::AlienTechUsed
struct OpPb_A_AlienTechUsed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_AlienTechUsed); };
template struct OpPb_Rob<OpPb_A_AlienTechUsed, &C::GetArenaNoVirtual>;
struct OpPb_M_AlienTechUsed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_AlienTechUsed); };
template struct OpPb_Rob<OpPb_M_AlienTechUsed, &C::MaybeArenaPtr>;
void op_pb_use_AlienTechUsed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_AlienTechUsed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_AlienTechUsed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::parts_size; }
	{ void (C::*p)() = &C::clear_parts; }
	{ const ::std::string& (C::*p)(int index) const = &C::parts; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_parts; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_parts; }
	{ void (C::*p)(int index, const char* value) = &C::set_parts; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_parts; }
	{ ::std::string* (C::*p)() = &C::add_parts; }
	{ void (C::*p)(const ::std::string& value) = &C::add_parts; }
	{ void (C::*p)(const char* value) = &C::add_parts; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_parts; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::parts; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_parts; }
}
#undef C

#define C Protobuf::Achievements
struct OpPb_A_Achievements { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Achievements); };
template struct OpPb_Rob<OpPb_A_Achievements, &C::GetArenaNoVirtual>;
struct OpPb_M_Achievements { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Achievements); };
template struct OpPb_Rob<OpPb_M_Achievements, &C::MaybeArenaPtr>;
void op_pb_use_Achievements()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Achievements()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Achievements()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::achievements_size; }
	{ void (C::*p)() = &C::clear_achievements; }
	{ const ::std::string& (C::*p)(int index) const = &C::achievements; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_achievements; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_achievements; }
	{ void (C::*p)(int index, const char* value) = &C::set_achievements; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_achievements; }
	{ ::std::string* (C::*p)() = &C::add_achievements; }
	{ void (C::*p)(const ::std::string& value) = &C::add_achievements; }
	{ void (C::*p)(const char* value) = &C::add_achievements; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_achievements; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::achievements; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_achievements; }
}
#undef C

#define C Protobuf::Challenges
struct OpPb_A_Challenges { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Challenges); };
template struct OpPb_Rob<OpPb_A_Challenges, &C::GetArenaNoVirtual>;
struct OpPb_M_Challenges { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Challenges); };
template struct OpPb_Rob<OpPb_M_Challenges, &C::MaybeArenaPtr>;
void op_pb_use_Challenges()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Challenges()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Challenges()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::challenges_size; }
	{ void (C::*p)() = &C::clear_challenges; }
	{ const ::std::string& (C::*p)(int index) const = &C::challenges; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_challenges; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_challenges; }
	{ void (C::*p)(int index, const char* value) = &C::set_challenges; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_challenges; }
	{ ::std::string* (C::*p)() = &C::add_challenges; }
	{ void (C::*p)(const ::std::string& value) = &C::add_challenges; }
	{ void (C::*p)(const char* value) = &C::add_challenges; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_challenges; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::challenges; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_challenges; }
}
#undef C

#define C Protobuf::CogshopPurchases_Purchase
struct OpPb_A_CogshopPurchases_Purchase { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_CogshopPurchases_Purchase); };
template struct OpPb_Rob<OpPb_A_CogshopPurchases_Purchase, &C::GetArenaNoVirtual>;
struct OpPb_M_CogshopPurchases_Purchase { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_CogshopPurchases_Purchase); };
template struct OpPb_Rob<OpPb_M_CogshopPurchases_Purchase, &C::MaybeArenaPtr>;
void op_pb_use_CogshopPurchases_Purchase()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_CogshopPurchases_Purchase()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_CogshopPurchases_Purchase()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_cost; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cost; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cost; }
}
#undef C

#define C Protobuf::CogshopPurchases
struct OpPb_A_CogshopPurchases { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_CogshopPurchases); };
template struct OpPb_Rob<OpPb_A_CogshopPurchases, &C::GetArenaNoVirtual>;
struct OpPb_M_CogshopPurchases { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_CogshopPurchases); };
template struct OpPb_Rob<OpPb_M_CogshopPurchases, &C::MaybeArenaPtr>;
void op_pb_use_CogshopPurchases()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_CogshopPurchases()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_CogshopPurchases()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::purchases_size; }
	{ void (C::*p)() = &C::clear_purchases; }
	{ const ::Protobuf::CogshopPurchases_Purchase& (C::*p)(int index) const = &C::purchases; }
	{ ::Protobuf::CogshopPurchases_Purchase* (C::*p)(int index) = &C::mutable_purchases; }
	{ ::Protobuf::CogshopPurchases_Purchase* (C::*p)() = &C::add_purchases; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::CogshopPurchases_Purchase >* (C::*p)() = &C::mutable_purchases; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::CogshopPurchases_Purchase >& (C::*p)() const = &C::purchases; }
}
#undef C

#define C Protobuf::PolymindHostKillLeaderboard_HostRecord
struct OpPb_A_PolymindHostKillLeaderboard_HostRecord { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PolymindHostKillLeaderboard_HostRecord); };
template struct OpPb_Rob<OpPb_A_PolymindHostKillLeaderboard_HostRecord, &C::GetArenaNoVirtual>;
struct OpPb_M_PolymindHostKillLeaderboard_HostRecord { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PolymindHostKillLeaderboard_HostRecord); };
template struct OpPb_Rob<OpPb_M_PolymindHostKillLeaderboard_HostRecord, &C::MaybeArenaPtr>;
void op_pb_use_PolymindHostKillLeaderboard_HostRecord()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PolymindHostKillLeaderboard_HostRecord()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PolymindHostKillLeaderboard_HostRecord()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ bool (C::*p)() const = &C::has_location; }
	{ void (C::*p)() = &C::clear_location; }
	{ const ::Protobuf::Location& (C::*p)() const = &C::location; }
	{ ::Protobuf::Location* (C::*p)() = &C::release_location; }
	{ ::Protobuf::Location* (C::*p)() = &C::mutable_location; }
	{ void (C::*p)(::Protobuf::Location* location) = &C::set_allocated_location; }
	{ void (C::*p)() = &C::clear_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kills; }
}
#undef C

#define C Protobuf::PolymindHostKillLeaderboard
struct OpPb_A_PolymindHostKillLeaderboard { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_PolymindHostKillLeaderboard); };
template struct OpPb_Rob<OpPb_A_PolymindHostKillLeaderboard, &C::GetArenaNoVirtual>;
struct OpPb_M_PolymindHostKillLeaderboard { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_PolymindHostKillLeaderboard); };
template struct OpPb_Rob<OpPb_M_PolymindHostKillLeaderboard, &C::MaybeArenaPtr>;
void op_pb_use_PolymindHostKillLeaderboard()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_PolymindHostKillLeaderboard()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_PolymindHostKillLeaderboard()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::host_records_size; }
	{ void (C::*p)() = &C::clear_host_records; }
	{ const ::Protobuf::PolymindHostKillLeaderboard_HostRecord& (C::*p)(int index) const = &C::host_records; }
	{ ::Protobuf::PolymindHostKillLeaderboard_HostRecord* (C::*p)(int index) = &C::mutable_host_records; }
	{ ::Protobuf::PolymindHostKillLeaderboard_HostRecord* (C::*p)() = &C::add_host_records; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::PolymindHostKillLeaderboard_HostRecord >* (C::*p)() = &C::mutable_host_records; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::PolymindHostKillLeaderboard_HostRecord >& (C::*p)() const = &C::host_records; }
}
#undef C

#define C Protobuf::Game
struct OpPb_A_Game { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Game); };
template struct OpPb_Rob<OpPb_A_Game, &C::GetArenaNoVirtual>;
struct OpPb_M_Game { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Game); };
template struct OpPb_Rob<OpPb_M_Game, &C::MaybeArenaPtr>;
void op_pb_use_Game()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Game()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Game()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_world_seed; }
	{ const ::std::string& (C::*p)() const = &C::world_seed; }
	{ void (C::*p)(const ::std::string& value) = &C::set_world_seed; }
	{ void (C::*p)(const char* value) = &C::set_world_seed; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_world_seed; }
	{ ::std::string* (C::*p)() = &C::mutable_world_seed; }
	{ ::std::string* (C::*p)() = &C::release_world_seed; }
	{ void (C::*p)(::std::string* world_seed) = &C::set_allocated_world_seed; }
	{ void (C::*p)() = &C::clear_world_seed_is_manual; }
	{ bool (C::*p)() const = &C::world_seed_is_manual; }
	{ void (C::*p)(bool value) = &C::set_world_seed_is_manual; }
	{ void (C::*p)() = &C::clear_run_time; }
	{ const ::std::string& (C::*p)() const = &C::run_time; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_time; }
	{ void (C::*p)(const char* value) = &C::set_run_time; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_time; }
	{ ::std::string* (C::*p)() = &C::mutable_run_time; }
	{ ::std::string* (C::*p)() = &C::release_run_time; }
	{ void (C::*p)(::std::string* run_time) = &C::set_allocated_run_time; }
	{ void (C::*p)() = &C::clear_cumulative_hours; }
	{ const ::std::string& (C::*p)() const = &C::cumulative_hours; }
	{ void (C::*p)(const ::std::string& value) = &C::set_cumulative_hours; }
	{ void (C::*p)(const char* value) = &C::set_cumulative_hours; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_cumulative_hours; }
	{ ::std::string* (C::*p)() = &C::mutable_cumulative_hours; }
	{ ::std::string* (C::*p)() = &C::release_cumulative_hours; }
	{ void (C::*p)(::std::string* cumulative_hours) = &C::set_allocated_cumulative_hours; }
	{ void (C::*p)() = &C::clear_run_start_date; }
	{ const ::std::string& (C::*p)() const = &C::run_start_date; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_start_date; }
	{ void (C::*p)(const char* value) = &C::set_run_start_date; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_start_date; }
	{ ::std::string* (C::*p)() = &C::mutable_run_start_date; }
	{ ::std::string* (C::*p)() = &C::release_run_start_date; }
	{ void (C::*p)(::std::string* run_start_date) = &C::set_allocated_run_start_date; }
	{ void (C::*p)() = &C::clear_run_end_date; }
	{ const ::std::string& (C::*p)() const = &C::run_end_date; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_end_date; }
	{ void (C::*p)(const char* value) = &C::set_run_end_date; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_end_date; }
	{ ::std::string* (C::*p)() = &C::mutable_run_end_date; }
	{ ::std::string* (C::*p)() = &C::release_run_end_date; }
	{ void (C::*p)(::std::string* run_end_date) = &C::set_allocated_run_end_date; }
	{ void (C::*p)() = &C::clear_run_sessions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::run_sessions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_run_sessions; }
	{ void (C::*p)() = &C::clear_run_loads; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::run_loads; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_run_loads; }
	{ void (C::*p)() = &C::clear_difficulty; }
	{ ::Protobuf::DifficultyType (C::*p)() const = &C::difficulty; }
	{ void (C::*p)(::Protobuf::DifficultyType value) = &C::set_difficulty; }
	{ void (C::*p)() = &C::clear_special_mode; }
	{ ::Protobuf::SpecialModeType (C::*p)() const = &C::special_mode; }
	{ void (C::*p)(::Protobuf::SpecialModeType value) = &C::set_special_mode; }
	{ void (C::*p)() = &C::clear_game_number; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::game_number; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_game_number; }
	{ int (C::*p)() const = &C::game_counts_size; }
	{ void (C::*p)() = &C::clear_game_counts; }
	{ ::google::protobuf::int32 (C::*p)(int index) const = &C::game_counts; }
	{ void (C::*p)(int index, ::google::protobuf::int32 value) = &C::set_game_counts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::add_game_counts; }
	{ const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >& (C::*p)() const = &C::game_counts; }
	{ ::google::protobuf::RepeatedField< ::google::protobuf::int32 >* (C::*p)() = &C::mutable_game_counts; }
	{ void (C::*p)() = &C::clear_win_type; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::win_type; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_win_type; }
	{ void (C::*p)() = &C::clear_win_total; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::win_total; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_win_total; }
	{ int (C::*p)() const = &C::win_type_history_size; }
	{ void (C::*p)() = &C::clear_win_type_history; }
	{ ::google::protobuf::int32 (C::*p)(int index) const = &C::win_type_history; }
	{ void (C::*p)(int index, ::google::protobuf::int32 value) = &C::set_win_type_history; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::add_win_type_history; }
	{ const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >& (C::*p)() const = &C::win_type_history; }
	{ ::google::protobuf::RepeatedField< ::google::protobuf::int32 >* (C::*p)() = &C::mutable_win_type_history; }
	{ void (C::*p)() = &C::clear_lore_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::lore_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_lore_percent; }
	{ void (C::*p)() = &C::clear_gallery_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gallery_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gallery_percent; }
	{ void (C::*p)() = &C::clear_achievement_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::achievement_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_achievement_percent; }
	{ void (C::*p)() = &C::clear_wizard_mode_run; }
	{ bool (C::*p)() const = &C::wizard_mode_run; }
	{ void (C::*p)(bool value) = &C::set_wizard_mode_run; }
}
#undef C

#define C Protobuf::Options
struct OpPb_A_Options { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Options); };
template struct OpPb_Rob<OpPb_A_Options, &C::GetArenaNoVirtual>;
struct OpPb_M_Options { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Options); };
template struct OpPb_Rob<OpPb_M_Options, &C::MaybeArenaPtr>;
void op_pb_use_Options()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Options()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Options()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_layout; }
	{ ::Protobuf::UiLayoutType (C::*p)() const = &C::layout; }
	{ void (C::*p)(::Protobuf::UiLayoutType value) = &C::set_layout; }
	{ void (C::*p)() = &C::clear_ascii; }
	{ bool (C::*p)() const = &C::ascii; }
	{ void (C::*p)(bool value) = &C::set_ascii; }
	{ void (C::*p)() = &C::clear_keyboard; }
	{ bool (C::*p)() const = &C::keyboard; }
	{ void (C::*p)(bool value) = &C::set_keyboard; }
	{ void (C::*p)() = &C::clear_movement; }
	{ ::Protobuf::MovementInputType (C::*p)() const = &C::movement; }
	{ void (C::*p)(::Protobuf::MovementInputType value) = &C::set_movement; }
	{ void (C::*p)() = &C::clear_keybinds; }
	{ bool (C::*p)() const = &C::keybinds; }
	{ void (C::*p)(bool value) = &C::set_keybinds; }
	{ void (C::*p)() = &C::clear_fullscreen; }
	{ ::Protobuf::FullscreenType (C::*p)() const = &C::fullscreen; }
	{ void (C::*p)(::Protobuf::FullscreenType value) = &C::set_fullscreen; }
	{ void (C::*p)() = &C::clear_font_set; }
	{ const ::std::string& (C::*p)() const = &C::font_set; }
	{ void (C::*p)(const ::std::string& value) = &C::set_font_set; }
	{ void (C::*p)(const char* value) = &C::set_font_set; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_font_set; }
	{ ::std::string* (C::*p)() = &C::mutable_font_set; }
	{ ::std::string* (C::*p)() = &C::release_font_set; }
	{ void (C::*p)(::std::string* font_set) = &C::set_allocated_font_set; }
	{ void (C::*p)() = &C::clear_map_width; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::map_width; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_map_width; }
	{ void (C::*p)() = &C::clear_map_height; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::map_height; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_map_height; }
	{ void (C::*p)() = &C::clear_zoom_use; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zoom_use; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zoom_use; }
	{ void (C::*p)() = &C::clear_tactical_hud; }
	{ bool (C::*p)() const = &C::tactical_hud; }
	{ void (C::*p)(bool value) = &C::set_tactical_hud; }
	{ void (C::*p)() = &C::clear_render_filters_map; }
	{ const ::std::string& (C::*p)() const = &C::render_filters_map; }
	{ void (C::*p)(const ::std::string& value) = &C::set_render_filters_map; }
	{ void (C::*p)(const char* value) = &C::set_render_filters_map; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_render_filters_map; }
	{ ::std::string* (C::*p)() = &C::mutable_render_filters_map; }
	{ ::std::string* (C::*p)() = &C::release_render_filters_map; }
	{ void (C::*p)(::std::string* render_filters_map) = &C::set_allocated_render_filters_map; }
	{ void (C::*p)() = &C::clear_render_filters; }
	{ const ::std::string& (C::*p)() const = &C::render_filters; }
	{ void (C::*p)(const ::std::string& value) = &C::set_render_filters; }
	{ void (C::*p)(const char* value) = &C::set_render_filters; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_render_filters; }
	{ ::std::string* (C::*p)() = &C::mutable_render_filters; }
	{ ::std::string* (C::*p)() = &C::release_render_filters; }
	{ void (C::*p)(::std::string* render_filters) = &C::set_allocated_render_filters; }
	{ void (C::*p)() = &C::clear_steam; }
	{ ::Protobuf::SteamType (C::*p)() const = &C::steam; }
	{ void (C::*p)(::Protobuf::SteamType value) = &C::set_steam; }
}
#undef C

#define C Protobuf::Meta
struct OpPb_A_Meta { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Meta); };
template struct OpPb_Rob<OpPb_A_Meta, &C::GetArenaNoVirtual>;
struct OpPb_M_Meta { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Meta); };
template struct OpPb_Rob<OpPb_M_Meta, &C::MaybeArenaPtr>;
void op_pb_use_Meta()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Meta()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Meta()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_run_guid; }
	{ const ::std::string& (C::*p)() const = &C::run_guid; }
	{ void (C::*p)(const ::std::string& value) = &C::set_run_guid; }
	{ void (C::*p)(const char* value) = &C::set_run_guid; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_run_guid; }
	{ ::std::string* (C::*p)() = &C::mutable_run_guid; }
	{ ::std::string* (C::*p)() = &C::release_run_guid; }
	{ void (C::*p)(::std::string* run_guid) = &C::set_allocated_run_guid; }
	{ void (C::*p)() = &C::clear_player_public_key; }
	{ const ::std::string& (C::*p)() const = &C::player_public_key; }
	{ void (C::*p)(const ::std::string& value) = &C::set_player_public_key; }
	{ void (C::*p)(const char* value) = &C::set_player_public_key; }
	{ void (C::*p)(const void* value, size_t size) = &C::set_player_public_key; }
	{ ::std::string* (C::*p)() = &C::mutable_player_public_key; }
	{ ::std::string* (C::*p)() = &C::release_player_public_key; }
	{ void (C::*p)(::std::string* player_public_key) = &C::set_allocated_player_public_key; }
	{ void (C::*p)() = &C::clear_player_guid; }
	{ const ::std::string& (C::*p)() const = &C::player_guid; }
	{ void (C::*p)(const ::std::string& value) = &C::set_player_guid; }
	{ void (C::*p)(const char* value) = &C::set_player_guid; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_player_guid; }
	{ ::std::string* (C::*p)() = &C::mutable_player_guid; }
	{ ::std::string* (C::*p)() = &C::release_player_guid; }
	{ void (C::*p)(::std::string* player_guid) = &C::set_allocated_player_guid; }
	{ void (C::*p)() = &C::clear_player_id; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::player_id; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_player_id; }
	{ void (C::*p)() = &C::clear_run_id; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::run_id; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_run_id; }
}
#undef C

#define C Protobuf::Route_Entry_DiscoveredExit
struct OpPb_A_Route_Entry_DiscoveredExit { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_DiscoveredExit); };
template struct OpPb_Rob<OpPb_A_Route_Entry_DiscoveredExit, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_DiscoveredExit { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_DiscoveredExit); };
template struct OpPb_Rob<OpPb_M_Route_Entry_DiscoveredExit, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_DiscoveredExit()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_DiscoveredExit()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_DiscoveredExit()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_destination; }
	{ ::Protobuf::MapType (C::*p)() const = &C::destination; }
	{ void (C::*p)(::Protobuf::MapType value) = &C::set_destination; }
	{ void (C::*p)() = &C::clear_destination_known; }
	{ bool (C::*p)() const = &C::destination_known; }
	{ void (C::*p)(bool value) = &C::set_destination_known; }
	{ void (C::*p)() = &C::clear_reached; }
	{ bool (C::*p)() const = &C::reached; }
	{ void (C::*p)(bool value) = &C::set_reached; }
	{ void (C::*p)() = &C::clear_count; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::count; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_count; }
}
#undef C

#define C Protobuf::Route_Entry_HistoryEvent
struct OpPb_A_Route_Entry_HistoryEvent { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_HistoryEvent); };
template struct OpPb_Rob<OpPb_A_Route_Entry_HistoryEvent, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_HistoryEvent { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_HistoryEvent); };
template struct OpPb_Rob<OpPb_M_Route_Entry_HistoryEvent, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_HistoryEvent()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_HistoryEvent()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_HistoryEvent()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_turn; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::turn; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_turn; }
	{ void (C::*p)() = &C::clear_event; }
	{ const ::std::string& (C::*p)() const = &C::event; }
	{ void (C::*p)(const ::std::string& value) = &C::set_event; }
	{ void (C::*p)(const char* value) = &C::set_event; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_event; }
	{ ::std::string* (C::*p)() = &C::mutable_event; }
	{ ::std::string* (C::*p)() = &C::release_event; }
	{ void (C::*p)(::std::string* event) = &C::set_allocated_event; }
}
#undef C

#define C Protobuf::Route_Entry_ObtainedSchematic
struct OpPb_A_Route_Entry_ObtainedSchematic { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_ObtainedSchematic); };
template struct OpPb_Rob<OpPb_A_Route_Entry_ObtainedSchematic, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_ObtainedSchematic { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_ObtainedSchematic); };
template struct OpPb_Rob<OpPb_M_Route_Entry_ObtainedSchematic, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_ObtainedSchematic()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_ObtainedSchematic()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_ObtainedSchematic()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_type; }
	{ ::Protobuf::SchematicType (C::*p)() const = &C::type; }
	{ void (C::*p)(::Protobuf::SchematicType value) = &C::set_type; }
	{ void (C::*p)() = &C::clear_method; }
	{ ::Protobuf::SchematicMethodType (C::*p)() const = &C::method; }
	{ void (C::*p)(::Protobuf::SchematicMethodType value) = &C::set_method; }
}
#undef C

#define C Protobuf::Route_Entry_FabricatedObject
struct OpPb_A_Route_Entry_FabricatedObject { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_FabricatedObject); };
template struct OpPb_Rob<OpPb_A_Route_Entry_FabricatedObject, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_FabricatedObject { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_FabricatedObject); };
template struct OpPb_Rob<OpPb_M_Route_Entry_FabricatedObject, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_FabricatedObject()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_FabricatedObject()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_FabricatedObject()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_count; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::count; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_count; }
	{ void (C::*p)() = &C::clear_preloaded; }
	{ bool (C::*p)() const = &C::preloaded; }
	{ void (C::*p)(bool value) = &C::set_preloaded; }
	{ void (C::*p)() = &C::clear_authchip; }
	{ bool (C::*p)() const = &C::authchip; }
	{ void (C::*p)(bool value) = &C::set_authchip; }
}
#undef C

#define C Protobuf::Route_Entry_RepairedObject
struct OpPb_A_Route_Entry_RepairedObject { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_RepairedObject); };
template struct OpPb_Rob<OpPb_A_Route_Entry_RepairedObject, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_RepairedObject { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_RepairedObject); };
template struct OpPb_Rob<OpPb_M_Route_Entry_RepairedObject, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_RepairedObject()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_RepairedObject()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_RepairedObject()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_integrity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::integrity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_integrity; }
	{ void (C::*p)() = &C::clear_broken; }
	{ bool (C::*p)() const = &C::broken; }
	{ void (C::*p)(bool value) = &C::set_broken; }
	{ void (C::*p)() = &C::clear_corrupted; }
	{ bool (C::*p)() const = &C::corrupted; }
	{ void (C::*p)(bool value) = &C::set_corrupted; }
}
#undef C

#define C Protobuf::Route_Entry_ObtainedStudy
struct OpPb_A_Route_Entry_ObtainedStudy { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_ObtainedStudy); };
template struct OpPb_Rob<OpPb_A_Route_Entry_ObtainedStudy, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_ObtainedStudy { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_ObtainedStudy); };
template struct OpPb_Rob<OpPb_M_Route_Entry_ObtainedStudy, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_ObtainedStudy()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_ObtainedStudy()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_ObtainedStudy()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_name; }
	{ const ::std::string& (C::*p)() const = &C::name; }
	{ void (C::*p)(const ::std::string& value) = &C::set_name; }
	{ void (C::*p)(const char* value) = &C::set_name; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_name; }
	{ ::std::string* (C::*p)() = &C::mutable_name; }
	{ ::std::string* (C::*p)() = &C::release_name; }
	{ void (C::*p)(::std::string* name) = &C::set_allocated_name; }
	{ void (C::*p)() = &C::clear_method; }
	{ ::Protobuf::StudyMethodType (C::*p)() const = &C::method; }
	{ void (C::*p)(::Protobuf::StudyMethodType value) = &C::set_method; }
}
#undef C

#define C Protobuf::Route_Entry_Factors
struct OpPb_A_Route_Entry_Factors { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry_Factors); };
template struct OpPb_Rob<OpPb_A_Route_Entry_Factors, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry_Factors { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry_Factors); };
template struct OpPb_Rob<OpPb_M_Route_Entry_Factors, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry_Factors()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry_Factors()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry_Factors()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::factor_one_size; }
	{ void (C::*p)() = &C::clear_factor_one; }
	{ ::google::protobuf::int32 (C::*p)(int index) const = &C::factor_one; }
	{ void (C::*p)(int index, ::google::protobuf::int32 value) = &C::set_factor_one; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::add_factor_one; }
	{ const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >& (C::*p)() const = &C::factor_one; }
	{ ::google::protobuf::RepeatedField< ::google::protobuf::int32 >* (C::*p)() = &C::mutable_factor_one; }
}
#undef C

#define C Protobuf::Route_Entry
struct OpPb_A_Route_Entry { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route_Entry); };
template struct OpPb_Rob<OpPb_A_Route_Entry, &C::GetArenaNoVirtual>;
struct OpPb_M_Route_Entry { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route_Entry); };
template struct OpPb_Rob<OpPb_M_Route_Entry, &C::MaybeArenaPtr>;
void op_pb_use_Route_Entry()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route_Entry()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route_Entry()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_location; }
	{ void (C::*p)() = &C::clear_location; }
	{ const ::Protobuf::Location& (C::*p)() const = &C::location; }
	{ ::Protobuf::Location* (C::*p)() = &C::release_location; }
	{ ::Protobuf::Location* (C::*p)() = &C::mutable_location; }
	{ void (C::*p)(::Protobuf::Location* location) = &C::set_allocated_location; }
	{ int (C::*p)() const = &C::discovered_exits_size; }
	{ void (C::*p)() = &C::clear_discovered_exits; }
	{ const ::Protobuf::Route_Entry_DiscoveredExit& (C::*p)(int index) const = &C::discovered_exits; }
	{ ::Protobuf::Route_Entry_DiscoveredExit* (C::*p)(int index) = &C::mutable_discovered_exits; }
	{ ::Protobuf::Route_Entry_DiscoveredExit* (C::*p)() = &C::add_discovered_exits; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_DiscoveredExit >* (C::*p)() = &C::mutable_discovered_exits; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_DiscoveredExit >& (C::*p)() const = &C::discovered_exits; }
	{ void (C::*p)() = &C::clear_dominant_class; }
	{ const ::std::string& (C::*p)() const = &C::dominant_class; }
	{ void (C::*p)(const ::std::string& value) = &C::set_dominant_class; }
	{ void (C::*p)(const char* value) = &C::set_dominant_class; }
	{ void (C::*p)(const char* value, size_t size) = &C::set_dominant_class; }
	{ ::std::string* (C::*p)() = &C::mutable_dominant_class; }
	{ ::std::string* (C::*p)() = &C::release_dominant_class; }
	{ void (C::*p)(::std::string* dominant_class) = &C::set_allocated_dominant_class; }
	{ int (C::*p)() const = &C::history_events_size; }
	{ void (C::*p)() = &C::clear_history_events; }
	{ const ::Protobuf::Route_Entry_HistoryEvent& (C::*p)(int index) const = &C::history_events; }
	{ ::Protobuf::Route_Entry_HistoryEvent* (C::*p)(int index) = &C::mutable_history_events; }
	{ ::Protobuf::Route_Entry_HistoryEvent* (C::*p)() = &C::add_history_events; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_HistoryEvent >* (C::*p)() = &C::mutable_history_events; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_HistoryEvent >& (C::*p)() const = &C::history_events; }
	{ int (C::*p)() const = &C::obtained_schematics_size; }
	{ void (C::*p)() = &C::clear_obtained_schematics; }
	{ const ::Protobuf::Route_Entry_ObtainedSchematic& (C::*p)(int index) const = &C::obtained_schematics; }
	{ ::Protobuf::Route_Entry_ObtainedSchematic* (C::*p)(int index) = &C::mutable_obtained_schematics; }
	{ ::Protobuf::Route_Entry_ObtainedSchematic* (C::*p)() = &C::add_obtained_schematics; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_ObtainedSchematic >* (C::*p)() = &C::mutable_obtained_schematics; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_ObtainedSchematic >& (C::*p)() const = &C::obtained_schematics; }
	{ int (C::*p)() const = &C::fabricated_objects_size; }
	{ void (C::*p)() = &C::clear_fabricated_objects; }
	{ const ::Protobuf::Route_Entry_FabricatedObject& (C::*p)(int index) const = &C::fabricated_objects; }
	{ ::Protobuf::Route_Entry_FabricatedObject* (C::*p)(int index) = &C::mutable_fabricated_objects; }
	{ ::Protobuf::Route_Entry_FabricatedObject* (C::*p)() = &C::add_fabricated_objects; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_FabricatedObject >* (C::*p)() = &C::mutable_fabricated_objects; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_FabricatedObject >& (C::*p)() const = &C::fabricated_objects; }
	{ int (C::*p)() const = &C::repaired_objects_size; }
	{ void (C::*p)() = &C::clear_repaired_objects; }
	{ const ::Protobuf::Route_Entry_RepairedObject& (C::*p)(int index) const = &C::repaired_objects; }
	{ ::Protobuf::Route_Entry_RepairedObject* (C::*p)(int index) = &C::mutable_repaired_objects; }
	{ ::Protobuf::Route_Entry_RepairedObject* (C::*p)() = &C::add_repaired_objects; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_RepairedObject >* (C::*p)() = &C::mutable_repaired_objects; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_RepairedObject >& (C::*p)() const = &C::repaired_objects; }
	{ int (C::*p)() const = &C::obtained_studies_size; }
	{ void (C::*p)() = &C::clear_obtained_studies; }
	{ const ::Protobuf::Route_Entry_ObtainedStudy& (C::*p)(int index) const = &C::obtained_studies; }
	{ ::Protobuf::Route_Entry_ObtainedStudy* (C::*p)(int index) = &C::mutable_obtained_studies; }
	{ ::Protobuf::Route_Entry_ObtainedStudy* (C::*p)() = &C::add_obtained_studies; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_ObtainedStudy >* (C::*p)() = &C::mutable_obtained_studies; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry_ObtainedStudy >& (C::*p)() const = &C::obtained_studies; }
	{ bool (C::*p)() const = &C::has_factors; }
	{ void (C::*p)() = &C::clear_factors; }
	{ const ::Protobuf::Route_Entry_Factors& (C::*p)() const = &C::factors; }
	{ ::Protobuf::Route_Entry_Factors* (C::*p)() = &C::release_factors; }
	{ ::Protobuf::Route_Entry_Factors* (C::*p)() = &C::mutable_factors; }
	{ void (C::*p)(::Protobuf::Route_Entry_Factors* factors) = &C::set_allocated_factors; }
	{ bool (C::*p)() const = &C::has_stats; }
	{ void (C::*p)() = &C::clear_stats; }
	{ const ::Protobuf::Stats& (C::*p)() const = &C::stats; }
	{ ::Protobuf::Stats* (C::*p)() = &C::release_stats; }
	{ ::Protobuf::Stats* (C::*p)() = &C::mutable_stats; }
	{ void (C::*p)(::Protobuf::Stats* stats) = &C::set_allocated_stats; }
}
#undef C

#define C Protobuf::Route
struct OpPb_A_Route { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Route); };
template struct OpPb_Rob<OpPb_A_Route, &C::GetArenaNoVirtual>;
struct OpPb_M_Route { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Route); };
template struct OpPb_Rob<OpPb_M_Route, &C::MaybeArenaPtr>;
void op_pb_use_Route()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Route()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Route()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ int (C::*p)() const = &C::entries_size; }
	{ void (C::*p)() = &C::clear_entries; }
	{ const ::Protobuf::Route_Entry& (C::*p)(int index) const = &C::entries; }
	{ ::Protobuf::Route_Entry* (C::*p)(int index) = &C::mutable_entries; }
	{ ::Protobuf::Route_Entry* (C::*p)() = &C::add_entries; }
	{ ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry >* (C::*p)() = &C::mutable_entries; }
	{ const ::google::protobuf::RepeatedPtrField< ::Protobuf::Route_Entry >& (C::*p)() const = &C::entries; }
}
#undef C

#define C Protobuf::Stats_Build_SlotsEvolved
struct OpPb_A_Stats_Build_SlotsEvolved { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_SlotsEvolved); };
template struct OpPb_Rob<OpPb_A_Stats_Build_SlotsEvolved, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_SlotsEvolved { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_SlotsEvolved); };
template struct OpPb_Rob<OpPb_M_Stats_Build_SlotsEvolved, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_SlotsEvolved()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_SlotsEvolved()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_SlotsEvolved()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion; }
	{ void (C::*p)() = &C::clear_utility; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached_Power
struct OpPb_A_Stats_Build_PartsAttached_Power { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached_Power); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached_Power, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached_Power { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached_Power); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached_Power, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached_Power()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached_Power()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached_Power()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_engine; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::engine; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_engine; }
	{ void (C::*p)() = &C::clear_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core; }
	{ void (C::*p)() = &C::clear_reactor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reactor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reactor; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached_Propulsion
struct OpPb_A_Stats_Build_PartsAttached_Propulsion { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached_Propulsion); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached_Propulsion, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached_Propulsion { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached_Propulsion); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached_Propulsion, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached_Propulsion()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached_Propulsion()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached_Propulsion()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_treads; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::treads; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_treads; }
	{ void (C::*p)() = &C::clear_leg; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::leg; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_leg; }
	{ void (C::*p)() = &C::clear_wheel; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wheel; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wheel; }
	{ void (C::*p)() = &C::clear_hover; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hover; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hover; }
	{ void (C::*p)() = &C::clear_flight; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::flight; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_flight; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached_Utility
struct OpPb_A_Stats_Build_PartsAttached_Utility { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached_Utility); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached_Utility, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached_Utility { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached_Utility); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached_Utility, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached_Utility()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached_Utility()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached_Utility()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_device; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::device; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_device; }
	{ void (C::*p)() = &C::clear_storage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::storage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_storage; }
	{ void (C::*p)() = &C::clear_processor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::processor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_processor; }
	{ void (C::*p)() = &C::clear_hackware; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hackware; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hackware; }
	{ void (C::*p)() = &C::clear_protection; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protection; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protection; }
	{ void (C::*p)() = &C::clear_artifact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::artifact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_artifact; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached_Weapon
struct OpPb_A_Stats_Build_PartsAttached_Weapon { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached_Weapon); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached_Weapon, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached_Weapon { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached_Weapon); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached_Weapon, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached_Weapon()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached_Weapon()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached_Weapon()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_energy_gun; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_gun; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_gun; }
	{ void (C::*p)() = &C::clear_energy_cannon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_cannon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_cannon; }
	{ void (C::*p)() = &C::clear_ballistic_gun; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ballistic_gun; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ballistic_gun; }
	{ void (C::*p)() = &C::clear_ballistic_cannon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ballistic_cannon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ballistic_cannon; }
	{ void (C::*p)() = &C::clear_launcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::launcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_launcher; }
	{ void (C::*p)() = &C::clear_special_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special_weapon; }
	{ void (C::*p)() = &C::clear_impact_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact_weapon; }
	{ void (C::*p)() = &C::clear_slashing_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slashing_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slashing_weapon; }
	{ void (C::*p)() = &C::clear_piercing_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::piercing_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_piercing_weapon; }
	{ void (C::*p)() = &C::clear_special_melee_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special_melee_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special_melee_weapon; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached_CorruptedParts
struct OpPb_A_Stats_Build_PartsAttached_CorruptedParts { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached_CorruptedParts); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached_CorruptedParts, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached_CorruptedParts { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached_CorruptedParts); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached_CorruptedParts, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached_CorruptedParts()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached_CorruptedParts()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached_CorruptedParts()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_system_corruption; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::system_corruption; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_system_corruption; }
}
#undef C

#define C Protobuf::Stats_Build_PartsAttached
struct OpPb_A_Stats_Build_PartsAttached { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsAttached); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsAttached, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsAttached { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsAttached); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsAttached, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsAttached()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsAttached()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsAttached()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_power; }
	{ void (C::*p)() = &C::clear_power; }
	{ const ::Protobuf::Stats_Build_PartsAttached_Power& (C::*p)() const = &C::power; }
	{ ::Protobuf::Stats_Build_PartsAttached_Power* (C::*p)() = &C::release_power; }
	{ ::Protobuf::Stats_Build_PartsAttached_Power* (C::*p)() = &C::mutable_power; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached_Power* power) = &C::set_allocated_power; }
	{ bool (C::*p)() const = &C::has_propulsion; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ const ::Protobuf::Stats_Build_PartsAttached_Propulsion& (C::*p)() const = &C::propulsion; }
	{ ::Protobuf::Stats_Build_PartsAttached_Propulsion* (C::*p)() = &C::release_propulsion; }
	{ ::Protobuf::Stats_Build_PartsAttached_Propulsion* (C::*p)() = &C::mutable_propulsion; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached_Propulsion* propulsion) = &C::set_allocated_propulsion; }
	{ bool (C::*p)() const = &C::has_utility; }
	{ void (C::*p)() = &C::clear_utility; }
	{ const ::Protobuf::Stats_Build_PartsAttached_Utility& (C::*p)() const = &C::utility; }
	{ ::Protobuf::Stats_Build_PartsAttached_Utility* (C::*p)() = &C::release_utility; }
	{ ::Protobuf::Stats_Build_PartsAttached_Utility* (C::*p)() = &C::mutable_utility; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached_Utility* utility) = &C::set_allocated_utility; }
	{ bool (C::*p)() const = &C::has_weapon; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ const ::Protobuf::Stats_Build_PartsAttached_Weapon& (C::*p)() const = &C::weapon; }
	{ ::Protobuf::Stats_Build_PartsAttached_Weapon* (C::*p)() = &C::release_weapon; }
	{ ::Protobuf::Stats_Build_PartsAttached_Weapon* (C::*p)() = &C::mutable_weapon; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached_Weapon* weapon) = &C::set_allocated_weapon; }
	{ void (C::*p)() = &C::clear_unidentified_prototypes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unidentified_prototypes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unidentified_prototypes; }
	{ bool (C::*p)() const = &C::has_corrupted_parts; }
	{ void (C::*p)() = &C::clear_corrupted_parts; }
	{ const ::Protobuf::Stats_Build_PartsAttached_CorruptedParts& (C::*p)() const = &C::corrupted_parts; }
	{ ::Protobuf::Stats_Build_PartsAttached_CorruptedParts* (C::*p)() = &C::release_corrupted_parts; }
	{ ::Protobuf::Stats_Build_PartsAttached_CorruptedParts* (C::*p)() = &C::mutable_corrupted_parts; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached_CorruptedParts* corrupted_parts) = &C::set_allocated_corrupted_parts; }
}
#undef C

#define C Protobuf::Stats_Build_PartsLost
struct OpPb_A_Stats_Build_PartsLost { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PartsLost); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PartsLost, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PartsLost { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PartsLost); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PartsLost, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PartsLost()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PartsLost()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PartsLost()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion; }
	{ void (C::*p)() = &C::clear_utility; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon; }
	{ void (C::*p)() = &C::clear_highest_loss_streak; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::highest_loss_streak; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_highest_loss_streak; }
	{ void (C::*p)() = &C::clear_to_critical_strikes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::to_critical_strikes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_to_critical_strikes; }
}
#undef C

#define C Protobuf::Stats_Build_AverageSpares
struct OpPb_A_Stats_Build_AverageSpares { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_AverageSpares); };
template struct OpPb_Rob<OpPb_A_Stats_Build_AverageSpares, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_AverageSpares { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_AverageSpares); };
template struct OpPb_Rob<OpPb_M_Stats_Build_AverageSpares, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_AverageSpares()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_AverageSpares()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_AverageSpares()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion; }
	{ void (C::*p)() = &C::clear_utility; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon; }
	{ void (C::*p)() = &C::clear_special; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special; }
}
#undef C

#define C Protobuf::Stats_Build_UnusedSpares
struct OpPb_A_Stats_Build_UnusedSpares { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_UnusedSpares); };
template struct OpPb_Rob<OpPb_A_Stats_Build_UnusedSpares, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_UnusedSpares { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_UnusedSpares); };
template struct OpPb_Rob<OpPb_M_Stats_Build_UnusedSpares, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_UnusedSpares()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_UnusedSpares()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_UnusedSpares()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion; }
	{ void (C::*p)() = &C::clear_utility; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon; }
	{ void (C::*p)() = &C::clear_special; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special; }
}
#undef C

#define C Protobuf::Stats_Build_AverageSlotUsagePercent
struct OpPb_A_Stats_Build_AverageSlotUsagePercent { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_AverageSlotUsagePercent); };
template struct OpPb_Rob<OpPb_A_Stats_Build_AverageSlotUsagePercent, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_AverageSlotUsagePercent { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_AverageSlotUsagePercent); };
template struct OpPb_Rob<OpPb_M_Stats_Build_AverageSlotUsagePercent, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_AverageSlotUsagePercent()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_AverageSlotUsagePercent()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_AverageSlotUsagePercent()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_engine; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::engine; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_engine; }
	{ void (C::*p)() = &C::clear_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core; }
	{ void (C::*p)() = &C::clear_reactor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reactor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reactor; }
	{ void (C::*p)() = &C::clear_treads; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::treads; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_treads; }
	{ void (C::*p)() = &C::clear_leg; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::leg; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_leg; }
	{ void (C::*p)() = &C::clear_wheel; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wheel; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wheel; }
	{ void (C::*p)() = &C::clear_hover; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hover; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hover; }
	{ void (C::*p)() = &C::clear_flight; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::flight; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_flight; }
	{ void (C::*p)() = &C::clear_device; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::device; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_device; }
	{ void (C::*p)() = &C::clear_storage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::storage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_storage; }
	{ void (C::*p)() = &C::clear_processor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::processor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_processor; }
	{ void (C::*p)() = &C::clear_hackware; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hackware; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hackware; }
	{ void (C::*p)() = &C::clear_protection; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protection; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protection; }
	{ void (C::*p)() = &C::clear_artifact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::artifact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_artifact; }
	{ void (C::*p)() = &C::clear_energy_gun; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_gun; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_gun; }
	{ void (C::*p)() = &C::clear_energy_cannon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_cannon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_cannon; }
	{ void (C::*p)() = &C::clear_ballistic_gun; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ballistic_gun; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ballistic_gun; }
	{ void (C::*p)() = &C::clear_ballistic_cannon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ballistic_cannon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ballistic_cannon; }
	{ void (C::*p)() = &C::clear_launcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::launcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_launcher; }
	{ void (C::*p)() = &C::clear_special_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special_weapon; }
	{ void (C::*p)() = &C::clear_impact_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact_weapon; }
	{ void (C::*p)() = &C::clear_slashing_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slashing_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slashing_weapon; }
	{ void (C::*p)() = &C::clear_piercing_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::piercing_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_piercing_weapon; }
	{ void (C::*p)() = &C::clear_special_melee_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special_melee_weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special_melee_weapon; }
}
#undef C

#define C Protobuf::Stats_Build_PeakBuildRating
struct OpPb_A_Stats_Build_PeakBuildRating { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_PeakBuildRating); };
template struct OpPb_Rob<OpPb_A_Stats_Build_PeakBuildRating, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_PeakBuildRating { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_PeakBuildRating); };
template struct OpPb_Rob<OpPb_M_Stats_Build_PeakBuildRating, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_PeakBuildRating()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_PeakBuildRating()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_PeakBuildRating()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_average_rating; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_rating; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_rating; }
	{ void (C::*p)() = &C::clear_on_entrance; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::on_entrance; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_on_entrance; }
}
#undef C

#define C Protobuf::Stats_Build_HeaviestBuild
struct OpPb_A_Stats_Build_HeaviestBuild { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_HeaviestBuild); };
template struct OpPb_Rob<OpPb_A_Stats_Build_HeaviestBuild, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_HeaviestBuild { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_HeaviestBuild); };
template struct OpPb_Rob<OpPb_M_Stats_Build_HeaviestBuild, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_HeaviestBuild()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_HeaviestBuild()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_HeaviestBuild()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_greatest_support; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::greatest_support; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_greatest_support; }
	{ void (C::*p)() = &C::clear_greatest_overweight_times; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::greatest_overweight_times; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_greatest_overweight_times; }
	{ void (C::*p)() = &C::clear_average_overweight_times; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_overweight_times; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_overweight_times; }
}
#undef C

#define C Protobuf::Stats_Build_LargestInventoryCapacity
struct OpPb_A_Stats_Build_LargestInventoryCapacity { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_LargestInventoryCapacity); };
template struct OpPb_Rob<OpPb_A_Stats_Build_LargestInventoryCapacity, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_LargestInventoryCapacity { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_LargestInventoryCapacity); };
template struct OpPb_Rob<OpPb_M_Stats_Build_LargestInventoryCapacity, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_LargestInventoryCapacity()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_LargestInventoryCapacity()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_LargestInventoryCapacity()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_average_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_capacity; }
	{ void (C::*p)() = &C::clear_most_carried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::most_carried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_most_carried; }
	{ void (C::*p)() = &C::clear_average_carried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_carried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_carried; }
	{ void (C::*p)() = &C::clear_final_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::final_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_final_capacity; }
	{ void (C::*p)() = &C::clear_final_carried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::final_carried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_final_carried; }
}
#undef C

#define C Protobuf::Stats_Build_ScrapEngineConsumption
struct OpPb_A_Stats_Build_ScrapEngineConsumption { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_ScrapEngineConsumption); };
template struct OpPb_Rob<OpPb_A_Stats_Build_ScrapEngineConsumption, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_ScrapEngineConsumption { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_ScrapEngineConsumption); };
template struct OpPb_Rob<OpPb_M_Stats_Build_ScrapEngineConsumption, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_ScrapEngineConsumption()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_ScrapEngineConsumption()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_ScrapEngineConsumption()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_constructs_created; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::constructs_created; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_constructs_created; }
	{ void (C::*p)() = &C::clear_constructs_modified; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::constructs_modified; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_constructs_modified; }
}
#undef C

#define C Protobuf::Stats_Build_ScrapSuitUsage
struct OpPb_A_Stats_Build_ScrapSuitUsage { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_ScrapSuitUsage); };
template struct OpPb_Rob<OpPb_A_Stats_Build_ScrapSuitUsage, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_ScrapSuitUsage { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_ScrapSuitUsage); };
template struct OpPb_Rob<OpPb_M_Stats_Build_ScrapSuitUsage, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_ScrapSuitUsage()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_ScrapSuitUsage()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_ScrapSuitUsage()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_parts_cannibalized; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_cannibalized; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_cannibalized; }
}
#undef C

#define C Protobuf::Stats_Build_TransmogrifiedParts
struct OpPb_A_Stats_Build_TransmogrifiedParts { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build_TransmogrifiedParts); };
template struct OpPb_Rob<OpPb_A_Stats_Build_TransmogrifiedParts, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build_TransmogrifiedParts { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build_TransmogrifiedParts); };
template struct OpPb_Rob<OpPb_M_Stats_Build_TransmogrifiedParts, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build_TransmogrifiedParts()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build_TransmogrifiedParts()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build_TransmogrifiedParts()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_integrity_recovered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::integrity_recovered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_integrity_recovered; }
}
#undef C

#define C Protobuf::Stats_Build
struct OpPb_A_Stats_Build { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Build); };
template struct OpPb_Rob<OpPb_A_Stats_Build, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Build { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Build); };
template struct OpPb_Rob<OpPb_M_Stats_Build, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Build()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Build()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Build()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_slots_evolved; }
	{ void (C::*p)() = &C::clear_slots_evolved; }
	{ const ::Protobuf::Stats_Build_SlotsEvolved& (C::*p)() const = &C::slots_evolved; }
	{ ::Protobuf::Stats_Build_SlotsEvolved* (C::*p)() = &C::release_slots_evolved; }
	{ ::Protobuf::Stats_Build_SlotsEvolved* (C::*p)() = &C::mutable_slots_evolved; }
	{ void (C::*p)(::Protobuf::Stats_Build_SlotsEvolved* slots_evolved) = &C::set_allocated_slots_evolved; }
	{ bool (C::*p)() const = &C::has_parts_attached; }
	{ void (C::*p)() = &C::clear_parts_attached; }
	{ const ::Protobuf::Stats_Build_PartsAttached& (C::*p)() const = &C::parts_attached; }
	{ ::Protobuf::Stats_Build_PartsAttached* (C::*p)() = &C::release_parts_attached; }
	{ ::Protobuf::Stats_Build_PartsAttached* (C::*p)() = &C::mutable_parts_attached; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsAttached* parts_attached) = &C::set_allocated_parts_attached; }
	{ bool (C::*p)() const = &C::has_parts_lost; }
	{ void (C::*p)() = &C::clear_parts_lost; }
	{ const ::Protobuf::Stats_Build_PartsLost& (C::*p)() const = &C::parts_lost; }
	{ ::Protobuf::Stats_Build_PartsLost* (C::*p)() = &C::release_parts_lost; }
	{ ::Protobuf::Stats_Build_PartsLost* (C::*p)() = &C::mutable_parts_lost; }
	{ void (C::*p)(::Protobuf::Stats_Build_PartsLost* parts_lost) = &C::set_allocated_parts_lost; }
	{ bool (C::*p)() const = &C::has_average_spares; }
	{ void (C::*p)() = &C::clear_average_spares; }
	{ const ::Protobuf::Stats_Build_AverageSpares& (C::*p)() const = &C::average_spares; }
	{ ::Protobuf::Stats_Build_AverageSpares* (C::*p)() = &C::release_average_spares; }
	{ ::Protobuf::Stats_Build_AverageSpares* (C::*p)() = &C::mutable_average_spares; }
	{ void (C::*p)(::Protobuf::Stats_Build_AverageSpares* average_spares) = &C::set_allocated_average_spares; }
	{ bool (C::*p)() const = &C::has_unused_spares; }
	{ void (C::*p)() = &C::clear_unused_spares; }
	{ const ::Protobuf::Stats_Build_UnusedSpares& (C::*p)() const = &C::unused_spares; }
	{ ::Protobuf::Stats_Build_UnusedSpares* (C::*p)() = &C::release_unused_spares; }
	{ ::Protobuf::Stats_Build_UnusedSpares* (C::*p)() = &C::mutable_unused_spares; }
	{ void (C::*p)(::Protobuf::Stats_Build_UnusedSpares* unused_spares) = &C::set_allocated_unused_spares; }
	{ bool (C::*p)() const = &C::has_average_slot_usage_percent; }
	{ void (C::*p)() = &C::clear_average_slot_usage_percent; }
	{ const ::Protobuf::Stats_Build_AverageSlotUsagePercent& (C::*p)() const = &C::average_slot_usage_percent; }
	{ ::Protobuf::Stats_Build_AverageSlotUsagePercent* (C::*p)() = &C::release_average_slot_usage_percent; }
	{ ::Protobuf::Stats_Build_AverageSlotUsagePercent* (C::*p)() = &C::mutable_average_slot_usage_percent; }
	{ void (C::*p)(::Protobuf::Stats_Build_AverageSlotUsagePercent* average_slot_usage_percent) = &C::set_allocated_average_slot_usage_percent; }
	{ bool (C::*p)() const = &C::has_peak_build_rating; }
	{ void (C::*p)() = &C::clear_peak_build_rating; }
	{ const ::Protobuf::Stats_Build_PeakBuildRating& (C::*p)() const = &C::peak_build_rating; }
	{ ::Protobuf::Stats_Build_PeakBuildRating* (C::*p)() = &C::release_peak_build_rating; }
	{ ::Protobuf::Stats_Build_PeakBuildRating* (C::*p)() = &C::mutable_peak_build_rating; }
	{ void (C::*p)(::Protobuf::Stats_Build_PeakBuildRating* peak_build_rating) = &C::set_allocated_peak_build_rating; }
	{ void (C::*p)() = &C::clear_avg_prop_armor_coverage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::avg_prop_armor_coverage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_avg_prop_armor_coverage; }
	{ void (C::*p)() = &C::clear_naked_turns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::naked_turns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_naked_turns; }
	{ bool (C::*p)() const = &C::has_heaviest_build; }
	{ void (C::*p)() = &C::clear_heaviest_build; }
	{ const ::Protobuf::Stats_Build_HeaviestBuild& (C::*p)() const = &C::heaviest_build; }
	{ ::Protobuf::Stats_Build_HeaviestBuild* (C::*p)() = &C::release_heaviest_build; }
	{ ::Protobuf::Stats_Build_HeaviestBuild* (C::*p)() = &C::mutable_heaviest_build; }
	{ void (C::*p)(::Protobuf::Stats_Build_HeaviestBuild* heaviest_build) = &C::set_allocated_heaviest_build; }
	{ bool (C::*p)() const = &C::has_largest_inventory_capacity; }
	{ void (C::*p)() = &C::clear_largest_inventory_capacity; }
	{ const ::Protobuf::Stats_Build_LargestInventoryCapacity& (C::*p)() const = &C::largest_inventory_capacity; }
	{ ::Protobuf::Stats_Build_LargestInventoryCapacity* (C::*p)() = &C::release_largest_inventory_capacity; }
	{ ::Protobuf::Stats_Build_LargestInventoryCapacity* (C::*p)() = &C::mutable_largest_inventory_capacity; }
	{ void (C::*p)(::Protobuf::Stats_Build_LargestInventoryCapacity* largest_inventory_capacity) = &C::set_allocated_largest_inventory_capacity; }
	{ bool (C::*p)() const = &C::has_scrap_engine_consumption; }
	{ void (C::*p)() = &C::clear_scrap_engine_consumption; }
	{ const ::Protobuf::Stats_Build_ScrapEngineConsumption& (C::*p)() const = &C::scrap_engine_consumption; }
	{ ::Protobuf::Stats_Build_ScrapEngineConsumption* (C::*p)() = &C::release_scrap_engine_consumption; }
	{ ::Protobuf::Stats_Build_ScrapEngineConsumption* (C::*p)() = &C::mutable_scrap_engine_consumption; }
	{ void (C::*p)(::Protobuf::Stats_Build_ScrapEngineConsumption* scrap_engine_consumption) = &C::set_allocated_scrap_engine_consumption; }
	{ bool (C::*p)() const = &C::has_scrap_suit_usage; }
	{ void (C::*p)() = &C::clear_scrap_suit_usage; }
	{ const ::Protobuf::Stats_Build_ScrapSuitUsage& (C::*p)() const = &C::scrap_suit_usage; }
	{ ::Protobuf::Stats_Build_ScrapSuitUsage* (C::*p)() = &C::release_scrap_suit_usage; }
	{ ::Protobuf::Stats_Build_ScrapSuitUsage* (C::*p)() = &C::mutable_scrap_suit_usage; }
	{ void (C::*p)(::Protobuf::Stats_Build_ScrapSuitUsage* scrap_suit_usage) = &C::set_allocated_scrap_suit_usage; }
	{ bool (C::*p)() const = &C::has_transmogrified_parts; }
	{ void (C::*p)() = &C::clear_transmogrified_parts; }
	{ const ::Protobuf::Stats_Build_TransmogrifiedParts& (C::*p)() const = &C::transmogrified_parts; }
	{ ::Protobuf::Stats_Build_TransmogrifiedParts* (C::*p)() = &C::release_transmogrified_parts; }
	{ ::Protobuf::Stats_Build_TransmogrifiedParts* (C::*p)() = &C::mutable_transmogrified_parts; }
	{ void (C::*p)(::Protobuf::Stats_Build_TransmogrifiedParts* transmogrified_parts) = &C::set_allocated_transmogrified_parts; }
}
#undef C

#define C Protobuf::Stats_Resources_MatterCollected
struct OpPb_A_Stats_Resources_MatterCollected { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources_MatterCollected); };
template struct OpPb_Rob<OpPb_A_Stats_Resources_MatterCollected, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources_MatterCollected { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources_MatterCollected); };
template struct OpPb_Rob<OpPb_M_Stats_Resources_MatterCollected, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources_MatterCollected()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources_MatterCollected()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources_MatterCollected()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_remotely; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::remotely; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_remotely; }
}
#undef C

#define C Protobuf::Stats_Resources_SalvageCreated
struct OpPb_A_Stats_Resources_SalvageCreated { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources_SalvageCreated); };
template struct OpPb_Rob<OpPb_A_Stats_Resources_SalvageCreated, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources_SalvageCreated { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources_SalvageCreated); };
template struct OpPb_Rob<OpPb_M_Stats_Resources_SalvageCreated, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources_SalvageCreated()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources_SalvageCreated()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources_SalvageCreated()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts; }
}
#undef C

#define C Protobuf::Stats_Resources_PartsFieldRecycled
struct OpPb_A_Stats_Resources_PartsFieldRecycled { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources_PartsFieldRecycled); };
template struct OpPb_Rob<OpPb_A_Stats_Resources_PartsFieldRecycled, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources_PartsFieldRecycled { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources_PartsFieldRecycled); };
template struct OpPb_Rob<OpPb_M_Stats_Resources_PartsFieldRecycled, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources_PartsFieldRecycled()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources_PartsFieldRecycled()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources_PartsFieldRecycled()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_retrieved_matter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieved_matter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieved_matter; }
}
#undef C

#define C Protobuf::Stats_Resources_PartsSelfDestructed
struct OpPb_A_Stats_Resources_PartsSelfDestructed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources_PartsSelfDestructed); };
template struct OpPb_Rob<OpPb_A_Stats_Resources_PartsSelfDestructed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources_PartsSelfDestructed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources_PartsSelfDestructed); };
template struct OpPb_Rob<OpPb_M_Stats_Resources_PartsSelfDestructed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources_PartsSelfDestructed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources_PartsSelfDestructed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources_PartsSelfDestructed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_prevented; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prevented; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prevented; }
}
#undef C

#define C Protobuf::Stats_Resources_PartsRestored
struct OpPb_A_Stats_Resources_PartsRestored { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources_PartsRestored); };
template struct OpPb_Rob<OpPb_A_Stats_Resources_PartsRestored, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources_PartsRestored { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources_PartsRestored); };
template struct OpPb_Rob<OpPb_M_Stats_Resources_PartsRestored, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources_PartsRestored()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources_PartsRestored()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources_PartsRestored()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_broken; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::broken; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_broken; }
	{ void (C::*p)() = &C::clear_faulty; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::faulty; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_faulty; }
}
#undef C

#define C Protobuf::Stats_Resources
struct OpPb_A_Stats_Resources { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Resources); };
template struct OpPb_Rob<OpPb_A_Stats_Resources, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Resources { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Resources); };
template struct OpPb_Rob<OpPb_M_Stats_Resources, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Resources()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Resources()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Resources()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_matter_collected; }
	{ void (C::*p)() = &C::clear_matter_collected; }
	{ const ::Protobuf::Stats_Resources_MatterCollected& (C::*p)() const = &C::matter_collected; }
	{ ::Protobuf::Stats_Resources_MatterCollected* (C::*p)() = &C::release_matter_collected; }
	{ ::Protobuf::Stats_Resources_MatterCollected* (C::*p)() = &C::mutable_matter_collected; }
	{ void (C::*p)(::Protobuf::Stats_Resources_MatterCollected* matter_collected) = &C::set_allocated_matter_collected; }
	{ bool (C::*p)() const = &C::has_salvage_created; }
	{ void (C::*p)() = &C::clear_salvage_created; }
	{ const ::Protobuf::Stats_Resources_SalvageCreated& (C::*p)() const = &C::salvage_created; }
	{ ::Protobuf::Stats_Resources_SalvageCreated* (C::*p)() = &C::release_salvage_created; }
	{ void (C::*p)(::Protobuf::Stats_Resources_SalvageCreated* salvage_created) = &C::set_allocated_salvage_created; }
	{ void (C::*p)() = &C::clear_haulers_intercepted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::haulers_intercepted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_haulers_intercepted; }
	{ void (C::*p)() = &C::clear_recyclers_shooed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recyclers_shooed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recyclers_shooed; }
	{ bool (C::*p)() const = &C::has_parts_field_recycled; }
	{ void (C::*p)() = &C::clear_parts_field_recycled; }
	{ const ::Protobuf::Stats_Resources_PartsFieldRecycled& (C::*p)() const = &C::parts_field_recycled; }
	{ ::Protobuf::Stats_Resources_PartsFieldRecycled* (C::*p)() = &C::release_parts_field_recycled; }
	{ void (C::*p)(::Protobuf::Stats_Resources_PartsFieldRecycled* parts_field_recycled) = &C::set_allocated_parts_field_recycled; }
	{ bool (C::*p)() const = &C::has_parts_self_destructed; }
	{ void (C::*p)() = &C::clear_parts_self_destructed; }
	{ const ::Protobuf::Stats_Resources_PartsSelfDestructed& (C::*p)() const = &C::parts_self_destructed; }
	{ ::Protobuf::Stats_Resources_PartsSelfDestructed* (C::*p)() = &C::release_parts_self_destructed; }
	{ void (C::*p)(::Protobuf::Stats_Resources_PartsSelfDestructed* parts_self_destructed) = &C::set_allocated_parts_self_destructed; }
	{ bool (C::*p)() const = &C::has_parts_restored; }
	{ void (C::*p)() = &C::clear_parts_restored; }
	{ const ::Protobuf::Stats_Resources_PartsRestored& (C::*p)() const = &C::parts_restored; }
	{ ::Protobuf::Stats_Resources_PartsRestored* (C::*p)() = &C::release_parts_restored; }
	{ void (C::*p)(::Protobuf::Stats_Resources_PartsRestored* parts_restored) = &C::set_allocated_parts_restored; }
}
#undef C

#define C Protobuf::Stats_Kills_CombatHostilesDestroyed
struct OpPb_A_Stats_Kills_CombatHostilesDestroyed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Kills_CombatHostilesDestroyed); };
template struct OpPb_Rob<OpPb_A_Stats_Kills_CombatHostilesDestroyed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Kills_CombatHostilesDestroyed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Kills_CombatHostilesDestroyed); };
template struct OpPb_Rob<OpPb_M_Stats_Kills_CombatHostilesDestroyed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Kills_CombatHostilesDestroyed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Kills_CombatHostilesDestroyed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Kills_CombatHostilesDestroyed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
	{ void (C::*p)() = &C::clear_guns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_guns; }
	{ void (C::*p)() = &C::clear_cannons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cannons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cannons; }
	{ void (C::*p)() = &C::clear_aoe; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::aoe; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_aoe; }
}
#undef C

#define C Protobuf::Stats_Kills_ClassesDestroyed
struct OpPb_A_Stats_Kills_ClassesDestroyed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Kills_ClassesDestroyed); };
template struct OpPb_Rob<OpPb_A_Stats_Kills_ClassesDestroyed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Kills_ClassesDestroyed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Kills_ClassesDestroyed); };
template struct OpPb_Rob<OpPb_M_Stats_Kills_ClassesDestroyed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Kills_ClassesDestroyed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Kills_ClassesDestroyed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Kills_ClassesDestroyed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_worker; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::worker; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_worker; }
	{ void (C::*p)() = &C::clear_builder; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::builder; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_builder; }
	{ void (C::*p)() = &C::clear_tunneler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tunneler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tunneler; }
	{ void (C::*p)() = &C::clear_hauler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hauler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hauler; }
	{ void (C::*p)() = &C::clear_recycler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycler; }
	{ void (C::*p)() = &C::clear_carrier; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::carrier; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_carrier; }
	{ void (C::*p)() = &C::clear_minesweeper; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::minesweeper; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_minesweeper; }
	{ void (C::*p)() = &C::clear_mechanic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mechanic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mechanic; }
	{ void (C::*p)() = &C::clear_operator_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::operator_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_operator_; }
	{ void (C::*p)() = &C::clear_drone; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::drone; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_drone; }
	{ void (C::*p)() = &C::clear_turret; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::turret; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_turret; }
	{ void (C::*p)() = &C::clear_watcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::watcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_watcher; }
	{ void (C::*p)() = &C::clear_swarmer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::swarmer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_swarmer; }
	{ void (C::*p)() = &C::clear_cutter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cutter; }
	{ void (C::*p)() = &C::clear_saboteur; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::saboteur; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_saboteur; }
	{ void (C::*p)() = &C::clear_grunt; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::grunt; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_grunt; }
	{ void (C::*p)() = &C::clear_brawler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::brawler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_brawler; }
	{ void (C::*p)() = &C::clear_duelist; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::duelist; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_duelist; }
	{ void (C::*p)() = &C::clear_protector; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protector; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protector; }
	{ void (C::*p)() = &C::clear_researcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::researcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_researcher; }
	{ void (C::*p)() = &C::clear_sentry; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sentry; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sentry; }
	{ void (C::*p)() = &C::clear_demolisher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::demolisher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_demolisher; }
	{ void (C::*p)() = &C::clear_specialist; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::specialist; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_specialist; }
	{ void (C::*p)() = &C::clear_hunter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hunter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hunter; }
	{ void (C::*p)() = &C::clear_programmer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::programmer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_programmer; }
	{ void (C::*p)() = &C::clear_heavy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heavy; }
	{ void (C::*p)() = &C::clear_q_series; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::q_series; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_q_series; }
	{ void (C::*p)() = &C::clear_behemoth; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::behemoth; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_behemoth; }
	{ void (C::*p)() = &C::clear_compactor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::compactor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_compactor; }
	{ void (C::*p)() = &C::clear_armor_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::armor_guard; }
	{ void (C::*p)() = &C::clear_cetus_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cetus_guard; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cetus_guard; }
	{ void (C::*p)() = &C::clear_quarantine_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::quarantine_guard; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_quarantine_guard; }
	{ void (C::*p)() = &C::clear_s7_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::s7_guard; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_s7_guard; }
	{ void (C::*p)() = &C::clear_m_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::m_guard; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_m_guard; }
	{ void (C::*p)() = &C::clear_m_shell_atk; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::m_shell_atk; }
	{ void (C::*p)() = &C::clear_m_shell_def; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::m_shell_def; }
	{ void (C::*p)() = &C::clear_enhanced_grunt; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_grunt; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_enhanced_grunt; }
	{ void (C::*p)() = &C::clear_enhanced_sentry; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_sentry; }
	{ void (C::*p)() = &C::clear_enhanced_demolisher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_demolisher; }
	{ void (C::*p)() = &C::clear_enhanced_hunter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_hunter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_enhanced_hunter; }
	{ void (C::*p)() = &C::clear_enhanced_programmer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_programmer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_enhanced_programmer; }
	{ void (C::*p)() = &C::clear_enhanced_qseries; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::enhanced_qseries; }
	{ void (C::*p)() = &C::clear_lightning; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::lightning; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_lightning; }
	{ void (C::*p)() = &C::clear_clone_special; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::clone_special; }
	{ void (C::*p)() = &C::clear_hotshot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hotshot; }
	{ void (C::*p)() = &C::clear_decapitator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decapitator; }
	{ void (C::*p)() = &C::clear_immortal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::immortal; }
	{ void (C::*p)() = &C::clear_overlord; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overlord; }
	{ void (C::*p)() = &C::clear_tracker; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tracker; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tracker; }
	{ void (C::*p)() = &C::clear_combat_programmer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_programmer; }
	{ void (C::*p)() = &C::clear_investigator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::investigator; }
	{ void (C::*p)() = &C::clear_striker; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::striker; }
	{ void (C::*p)() = &C::clear_executioner; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::executioner; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_executioner; }
	{ void (C::*p)() = &C::clear_superbehemoth; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::superbehemoth; }
	{ void (C::*p)() = &C::clear_alpha_7; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::alpha_7; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_alpha_7; }
	{ void (C::*p)() = &C::clear_fortress; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fortress; }
	{ void (C::*p)() = &C::clear_vseries; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::vseries; }
	{ void (C::*p)() = &C::clear_protovariant_g; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_g; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protovariant_g; }
	{ void (C::*p)() = &C::clear_protovariant_l; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_l; }
	{ void (C::*p)() = &C::clear_protovariant_y; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_y; }
	{ void (C::*p)() = &C::clear_protovariant_d; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_d; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protovariant_d; }
	{ void (C::*p)() = &C::clear_protovariant_x; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_x; }
	{ void (C::*p)() = &C::clear_protovariant_h; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_h; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protovariant_h; }
	{ void (C::*p)() = &C::clear_protovariant_p; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_p; }
	{ void (C::*p)() = &C::clear_artisan; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::artisan; }
	{ void (C::*p)() = &C::clear_cobbler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cobbler; }
	{ void (C::*p)() = &C::clear_subdweller; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::subdweller; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_subdweller; }
	{ void (C::*p)() = &C::clear_bolteater; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::bolteater; }
	{ void (C::*p)() = &C::clear_federalist; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::federalist; }
	{ void (C::*p)() = &C::clear_explorer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explorer; }
	{ void (C::*p)() = &C::clear_ranger; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ranger; }
	{ void (C::*p)() = &C::clear_guru; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guru; }
	{ void (C::*p)() = &C::clear_scientist; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scientist; }
	{ void (C::*p)() = &C::clear_scrapper; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scrapper; }
	{ void (C::*p)() = &C::clear_elite; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::elite; }
	{ void (C::*p)() = &C::clear_scrapoid; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scrapoid; }
	{ void (C::*p)() = &C::clear_scraphulk; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scraphulk; }
	{ void (C::*p)() = &C::clear_botcube; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::botcube; }
	{ void (C::*p)() = &C::clear_zionite; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zionite; }
	{ void (C::*p)() = &C::clear_z_technician; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::z_technician; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_z_technician; }
	{ void (C::*p)() = &C::clear_z_courier; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::z_courier; }
	{ void (C::*p)() = &C::clear_z_light; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::z_light; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_z_light; }
	{ void (C::*p)() = &C::clear_z_heavy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::z_heavy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_z_heavy; }
	{ void (C::*p)() = &C::clear_z_ex; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::z_ex; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_z_ex; }
	{ void (C::*p)() = &C::clear_decomposer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decomposer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_decomposer; }
	{ void (C::*p)() = &C::clear_packrat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::packrat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_packrat; }
	{ void (C::*p)() = &C::clear_samaritan; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::samaritan; }
	{ void (C::*p)() = &C::clear_tinkerer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tinkerer; }
	{ void (C::*p)() = &C::clear_demented; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::demented; }
	{ void (C::*p)() = &C::clear_furnace; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::furnace; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_furnace; }
	{ void (C::*p)() = &C::clear_parasite; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parasite; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parasite; }
	{ void (C::*p)() = &C::clear_thief; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thief; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thief; }
	{ void (C::*p)() = &C::clear_master_thief; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::master_thief; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_master_thief; }
	{ void (C::*p)() = &C::clear_assembler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::assembler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_assembler; }
	{ void (C::*p)() = &C::clear_assembled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::assembled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_assembled; }
	{ void (C::*p)() = &C::clear_golem; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::golem; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_golem; }
	{ void (C::*p)() = &C::clear_surgeon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::surgeon; }
	{ void (C::*p)() = &C::clear_wasp; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wasp; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wasp; }
	{ void (C::*p)() = &C::clear_thug; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thug; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thug; }
	{ void (C::*p)() = &C::clear_savage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::savage; }
	{ void (C::*p)() = &C::clear_butcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::butcher; }
	{ void (C::*p)() = &C::clear_bouncer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::bouncer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_bouncer; }
	{ void (C::*p)() = &C::clear_martyr; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::martyr; }
	{ void (C::*p)() = &C::clear_guerrilla; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guerrilla; }
	{ void (C::*p)() = &C::clear_wizard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wizard; }
	{ void (C::*p)() = &C::clear_marauder; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::marauder; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_marauder; }
	{ void (C::*p)() = &C::clear_fireman; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fireman; }
	{ void (C::*p)() = &C::clear_mutant; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mutant; }
	{ void (C::*p)() = &C::clear_infiltrator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::infiltrator; }
	{ void (C::*p)() = &C::clear_sapper; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sapper; }
	{ void (C::*p)() = &C::clear_commander; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::commander; }
	{ void (C::*p)() = &C::clear_knight; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::knight; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_knight; }
	{ void (C::*p)() = &C::clear_troll; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::troll; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_troll; }
	{ void (C::*p)() = &C::clear_dragon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::dragon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_dragon; }
	{ void (C::*p)() = &C::clear_hydra; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hydra; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hydra; }
	{ void (C::*p)() = &C::clear_borebot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::borebot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_borebot; }
	{ void (C::*p)() = &C::clear_unchained; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unchained; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unchained; }
	{ void (C::*p)() = &C::clear_revision; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::revision; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_revision; }
	{ void (C::*p)() = &C::clear_abomination; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::abomination; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_abomination; }
	{ void (C::*p)() = &C::clear_anomaly; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::anomaly; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_anomaly; }
	{ void (C::*p)() = &C::clear_player; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::player; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_player; }
}
#undef C

#define C Protobuf::Stats_Kills_BestKillStreak
struct OpPb_A_Stats_Kills_BestKillStreak { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Kills_BestKillStreak); };
template struct OpPb_Rob<OpPb_A_Stats_Kills_BestKillStreak, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Kills_BestKillStreak { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Kills_BestKillStreak); };
template struct OpPb_Rob<OpPb_M_Stats_Kills_BestKillStreak, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Kills_BestKillStreak()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Kills_BestKillStreak()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Kills_BestKillStreak()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_bots_only; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_bots_only; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_bots_only; }
}
#undef C

#define C Protobuf::Stats_Kills_MaxKillsInSingleTurn
struct OpPb_A_Stats_Kills_MaxKillsInSingleTurn { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Kills_MaxKillsInSingleTurn); };
template struct OpPb_Rob<OpPb_A_Stats_Kills_MaxKillsInSingleTurn, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Kills_MaxKillsInSingleTurn { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Kills_MaxKillsInSingleTurn); };
template struct OpPb_Rob<OpPb_M_Stats_Kills_MaxKillsInSingleTurn, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Kills_MaxKillsInSingleTurn()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Kills_MaxKillsInSingleTurn()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Kills_MaxKillsInSingleTurn()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_gunslinging; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gunslinging; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gunslinging; }
	{ void (C::*p)() = &C::clear_exploded; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::exploded; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_exploded; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
}
#undef C

#define C Protobuf::Stats_Kills
struct OpPb_A_Stats_Kills { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Kills); };
template struct OpPb_Rob<OpPb_A_Stats_Kills, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Kills { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Kills); };
template struct OpPb_Rob<OpPb_M_Stats_Kills, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Kills()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Kills()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Kills()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_combat_hostiles_destroyed; }
	{ void (C::*p)() = &C::clear_combat_hostiles_destroyed; }
	{ const ::Protobuf::Stats_Kills_CombatHostilesDestroyed& (C::*p)() const = &C::combat_hostiles_destroyed; }
	{ ::Protobuf::Stats_Kills_CombatHostilesDestroyed* (C::*p)() = &C::release_combat_hostiles_destroyed; }
	{ ::Protobuf::Stats_Kills_CombatHostilesDestroyed* (C::*p)() = &C::mutable_combat_hostiles_destroyed; }
	{ void (C::*p)(::Protobuf::Stats_Kills_CombatHostilesDestroyed* combat_hostiles_destroyed) = &C::set_allocated_combat_hostiles_destroyed; }
	{ bool (C::*p)() const = &C::has_classes_destroyed; }
	{ void (C::*p)() = &C::clear_classes_destroyed; }
	{ const ::Protobuf::Stats_Kills_ClassesDestroyed& (C::*p)() const = &C::classes_destroyed; }
	{ ::Protobuf::Stats_Kills_ClassesDestroyed* (C::*p)() = &C::release_classes_destroyed; }
	{ ::Protobuf::Stats_Kills_ClassesDestroyed* (C::*p)() = &C::mutable_classes_destroyed; }
	{ void (C::*p)(::Protobuf::Stats_Kills_ClassesDestroyed* classes_destroyed) = &C::set_allocated_classes_destroyed; }
	{ bool (C::*p)() const = &C::has_best_kill_streak; }
	{ void (C::*p)() = &C::clear_best_kill_streak; }
	{ const ::Protobuf::Stats_Kills_BestKillStreak& (C::*p)() const = &C::best_kill_streak; }
	{ ::Protobuf::Stats_Kills_BestKillStreak* (C::*p)() = &C::release_best_kill_streak; }
	{ ::Protobuf::Stats_Kills_BestKillStreak* (C::*p)() = &C::mutable_best_kill_streak; }
	{ void (C::*p)(::Protobuf::Stats_Kills_BestKillStreak* best_kill_streak) = &C::set_allocated_best_kill_streak; }
	{ bool (C::*p)() const = &C::has_max_kills_in_single_turn; }
	{ void (C::*p)() = &C::clear_max_kills_in_single_turn; }
	{ const ::Protobuf::Stats_Kills_MaxKillsInSingleTurn& (C::*p)() const = &C::max_kills_in_single_turn; }
	{ ::Protobuf::Stats_Kills_MaxKillsInSingleTurn* (C::*p)() = &C::release_max_kills_in_single_turn; }
	{ ::Protobuf::Stats_Kills_MaxKillsInSingleTurn* (C::*p)() = &C::mutable_max_kills_in_single_turn; }
	{ void (C::*p)(::Protobuf::Stats_Kills_MaxKillsInSingleTurn* max_kills_in_single_turn) = &C::set_allocated_max_kills_in_single_turn; }
	{ void (C::*p)() = &C::clear_uniques_npcs_destroyed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::uniques_npcs_destroyed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_uniques_npcs_destroyed; }
	{ int (C::*p)() const = &C::list_of_uniques_npcs_destroyed_size; }
	{ void (C::*p)() = &C::clear_list_of_uniques_npcs_destroyed; }
	{ const ::std::string& (C::*p)(int index) const = &C::list_of_uniques_npcs_destroyed; }
	{ ::std::string* (C::*p)(int index) = &C::mutable_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(int index, const ::std::string& value) = &C::set_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(int index, const char* value) = &C::set_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(int index, const char* value, size_t size) = &C::set_list_of_uniques_npcs_destroyed; }
	{ ::std::string* (C::*p)() = &C::add_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(const ::std::string& value) = &C::add_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(const char* value) = &C::add_list_of_uniques_npcs_destroyed; }
	{ void (C::*p)(const char* value, size_t size) = &C::add_list_of_uniques_npcs_destroyed; }
	{ const ::google::protobuf::RepeatedPtrField< ::std::string>& (C::*p)() const = &C::list_of_uniques_npcs_destroyed; }
	{ ::google::protobuf::RepeatedPtrField< ::std::string>* (C::*p)() = &C::mutable_list_of_uniques_npcs_destroyed; }
}
#undef C

#define C Protobuf::Stats_Combat_HostileShotsFired_Hits
struct OpPb_A_Stats_Combat_HostileShotsFired_Hits { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_Hits); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HostileShotsFired_Hits, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HostileShotsFired_Hits { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_Hits); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HostileShotsFired_Hits, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HostileShotsFired_Hits()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_Hits()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_Hits()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
	{ void (C::*p)() = &C::clear_projectile; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::projectile; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_projectile; }
	{ void (C::*p)() = &C::clear_aoe; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::aoe; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_aoe; }
}
#undef C

#define C Protobuf::Stats_Combat_HostileShotsFired_CriticalStrikes
struct OpPb_A_Stats_Combat_HostileShotsFired_CriticalStrikes { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_CriticalStrikes); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HostileShotsFired_CriticalStrikes, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HostileShotsFired_CriticalStrikes { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_CriticalStrikes); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HostileShotsFired_CriticalStrikes, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HostileShotsFired_CriticalStrikes()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_CriticalStrikes()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_CriticalStrikes()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_actively_blocked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::actively_blocked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_actively_blocked; }
}
#undef C

#define C Protobuf::Stats_Combat_HostileShotsFired_PartDisruptions
struct OpPb_A_Stats_Combat_HostileShotsFired_PartDisruptions { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_PartDisruptions); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HostileShotsFired_PartDisruptions, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HostileShotsFired_PartDisruptions { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_PartDisruptions); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HostileShotsFired_PartDisruptions, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HostileShotsFired_PartDisruptions()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired_PartDisruptions()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired_PartDisruptions()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_actively_blocked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::actively_blocked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_actively_blocked; }
}
#undef C

#define C Protobuf::Stats_Combat_HostileShotsFired
struct OpPb_A_Stats_Combat_HostileShotsFired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HostileShotsFired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HostileShotsFired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HostileShotsFired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HostileShotsFired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HostileShotsFired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HostileShotsFired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_missed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::missed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_missed; }
	{ void (C::*p)() = &C::clear_intercepted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::intercepted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_intercepted; }
	{ void (C::*p)() = &C::clear_deflected; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::deflected; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_deflected; }
	{ bool (C::*p)() const = &C::has_hits; }
	{ void (C::*p)() = &C::clear_hits; }
	{ const ::Protobuf::Stats_Combat_HostileShotsFired_Hits& (C::*p)() const = &C::hits; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_Hits* (C::*p)() = &C::release_hits; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_Hits* (C::*p)() = &C::mutable_hits; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HostileShotsFired_Hits* hits) = &C::set_allocated_hits; }
	{ bool (C::*p)() const = &C::has_critical_strikes; }
	{ void (C::*p)() = &C::clear_critical_strikes; }
	{ const ::Protobuf::Stats_Combat_HostileShotsFired_CriticalStrikes& (C::*p)() const = &C::critical_strikes; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_CriticalStrikes* (C::*p)() = &C::release_critical_strikes; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_CriticalStrikes* (C::*p)() = &C::mutable_critical_strikes; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HostileShotsFired_CriticalStrikes* critical_strikes) = &C::set_allocated_critical_strikes; }
	{ bool (C::*p)() const = &C::has_part_disruptions; }
	{ void (C::*p)() = &C::clear_part_disruptions; }
	{ const ::Protobuf::Stats_Combat_HostileShotsFired_PartDisruptions& (C::*p)() const = &C::part_disruptions; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_PartDisruptions* (C::*p)() = &C::release_part_disruptions; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired_PartDisruptions* (C::*p)() = &C::mutable_part_disruptions; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HostileShotsFired_PartDisruptions* part_disruptions) = &C::set_allocated_part_disruptions; }
}
#undef C

#define C Protobuf::Stats_Combat_DamageTaken
struct OpPb_A_Stats_Combat_DamageTaken { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_DamageTaken); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_DamageTaken, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_DamageTaken { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_DamageTaken); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_DamageTaken, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_DamageTaken()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_DamageTaken()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_DamageTaken()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core; }
	{ void (C::*p)() = &C::clear_absorbed_by_shields; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::absorbed_by_shields; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_absorbed_by_shields; }
	{ void (C::*p)() = &C::clear_reduced_by_siege_mode; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reduced_by_siege_mode; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reduced_by_siege_mode; }
	{ void (C::*p)() = &C::clear_redirected_to_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::redirected_to_core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_redirected_to_core; }
	{ void (C::*p)() = &C::clear_redirected_to_shielding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::redirected_to_shielding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_redirected_to_shielding; }
	{ void (C::*p)() = &C::clear_ignored_by_resistances; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ignored_by_resistances; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ignored_by_resistances; }
	{ void (C::*p)() = &C::clear_regen_repair_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::regen_repair_parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_regen_repair_parts; }
}
#undef C

#define C Protobuf::Stats_Combat_VolleysFired
struct OpPb_A_Stats_Combat_VolleysFired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_VolleysFired); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_VolleysFired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_VolleysFired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_VolleysFired); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_VolleysFired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_VolleysFired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_VolleysFired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_VolleysFired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_largest; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::largest; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_largest; }
	{ void (C::*p)() = &C::clear_hottest; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hottest; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hottest; }
}
#undef C

#define C Protobuf::Stats_Combat_ShotsFired_SecondaryTargets
struct OpPb_A_Stats_Combat_ShotsFired_SecondaryTargets { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_ShotsFired_SecondaryTargets); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_ShotsFired_SecondaryTargets, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_ShotsFired_SecondaryTargets { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_ShotsFired_SecondaryTargets); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_ShotsFired_SecondaryTargets, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_ShotsFired_SecondaryTargets()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_ShotsFired_SecondaryTargets()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_ShotsFired_SecondaryTargets()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_max_gunslinging_chain; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::max_gunslinging_chain; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_max_gunslinging_chain; }
}
#undef C

#define C Protobuf::Stats_Combat_ShotsFired
struct OpPb_A_Stats_Combat_ShotsFired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_ShotsFired); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_ShotsFired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_ShotsFired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_ShotsFired); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_ShotsFired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_ShotsFired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_ShotsFired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_ShotsFired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_gun; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gun; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gun; }
	{ void (C::*p)() = &C::clear_cannon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cannon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cannon; }
	{ void (C::*p)() = &C::clear_launcher; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::launcher; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_launcher; }
	{ void (C::*p)() = &C::clear_special; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::special; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_special; }
	{ void (C::*p)() = &C::clear_kinetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinetic; }
	{ void (C::*p)() = &C::clear_thermal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermal; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermal; }
	{ void (C::*p)() = &C::clear_explosive; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosive; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosive; }
	{ void (C::*p)() = &C::clear_electromagnetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::electromagnetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_electromagnetic; }
	{ void (C::*p)() = &C::clear_impact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact; }
	{ void (C::*p)() = &C::clear_slashing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slashing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slashing; }
	{ void (C::*p)() = &C::clear_piercing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::piercing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_piercing; }
	{ void (C::*p)() = &C::clear_entropic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entropic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entropic; }
	{ void (C::*p)() = &C::clear_phasic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phasic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phasic; }
	{ void (C::*p)() = &C::clear_robot_hit_streak; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_hit_streak; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_hit_streak; }
	{ void (C::*p)() = &C::clear_robot_miss_streak; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_miss_streak; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_miss_streak; }
	{ void (C::*p)() = &C::clear_penetration_max; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::penetration_max; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_penetration_max; }
	{ bool (C::*p)() const = &C::has_secondary_targets; }
	{ void (C::*p)() = &C::clear_secondary_targets; }
	{ const ::Protobuf::Stats_Combat_ShotsFired_SecondaryTargets& (C::*p)() const = &C::secondary_targets; }
	{ ::Protobuf::Stats_Combat_ShotsFired_SecondaryTargets* (C::*p)() = &C::release_secondary_targets; }
	{ ::Protobuf::Stats_Combat_ShotsFired_SecondaryTargets* (C::*p)() = &C::mutable_secondary_targets; }
	{ void (C::*p)(::Protobuf::Stats_Combat_ShotsFired_SecondaryTargets* secondary_targets) = &C::set_allocated_secondary_targets; }
	{ void (C::*p)() = &C::clear_capacitor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::capacitor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_capacitor; }
	{ void (C::*p)() = &C::clear_autonomous; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autonomous; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autonomous; }
}
#undef C

#define C Protobuf::Stats_Combat_ShotsHitRobots_CriticalStrikes
struct OpPb_A_Stats_Combat_ShotsHitRobots_CriticalStrikes { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_ShotsHitRobots_CriticalStrikes); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_ShotsHitRobots_CriticalStrikes, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_ShotsHitRobots_CriticalStrikes { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_ShotsHitRobots_CriticalStrikes); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_ShotsHitRobots_CriticalStrikes, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_ShotsHitRobots_CriticalStrikes()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_ShotsHitRobots_CriticalStrikes()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_ShotsHitRobots_CriticalStrikes()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_burn; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::burn; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_burn; }
	{ void (C::*p)() = &C::clear_meltdown; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::meltdown; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_meltdown; }
	{ void (C::*p)() = &C::clear_destroy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroy; }
	{ void (C::*p)() = &C::clear_blast; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::blast; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_blast; }
	{ void (C::*p)() = &C::clear_corrupt; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corrupt; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corrupt; }
	{ void (C::*p)() = &C::clear_smash; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::smash; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_smash; }
	{ void (C::*p)() = &C::clear_sever; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sever; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sever; }
	{ void (C::*p)() = &C::clear_impale; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impale; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impale; }
	{ void (C::*p)() = &C::clear_detonate; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::detonate; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_detonate; }
	{ void (C::*p)() = &C::clear_sunder; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sunder; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sunder; }
	{ void (C::*p)() = &C::clear_intensify; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::intensify; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_intensify; }
	{ void (C::*p)() = &C::clear_phase; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phase; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phase; }
}
#undef C

#define C Protobuf::Stats_Combat_ShotsHitRobots
struct OpPb_A_Stats_Combat_ShotsHitRobots { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_ShotsHitRobots); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_ShotsHitRobots, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_ShotsHitRobots { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_ShotsHitRobots); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_ShotsHitRobots, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_ShotsHitRobots()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_ShotsHitRobots()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_ShotsHitRobots()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_core_hits; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core_hits; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core_hits; }
	{ void (C::*p)() = &C::clear_critical_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::critical_kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_critical_kills; }
	{ void (C::*p)() = &C::clear_critical_parts_destroyed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::critical_parts_destroyed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_critical_parts_destroyed; }
	{ bool (C::*p)() const = &C::has_critical_strikes; }
	{ void (C::*p)() = &C::clear_critical_strikes; }
	{ const ::Protobuf::Stats_Combat_ShotsHitRobots_CriticalStrikes& (C::*p)() const = &C::critical_strikes; }
	{ ::Protobuf::Stats_Combat_ShotsHitRobots_CriticalStrikes* (C::*p)() = &C::release_critical_strikes; }
	{ ::Protobuf::Stats_Combat_ShotsHitRobots_CriticalStrikes* (C::*p)() = &C::mutable_critical_strikes; }
	{ void (C::*p)(::Protobuf::Stats_Combat_ShotsHitRobots_CriticalStrikes* critical_strikes) = &C::set_allocated_critical_strikes; }
}
#undef C

#define C Protobuf::Stats_Combat_MeleeAttacks_SneakAttacks
struct OpPb_A_Stats_Combat_MeleeAttacks_SneakAttacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_MeleeAttacks_SneakAttacks); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_MeleeAttacks_SneakAttacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_MeleeAttacks_SneakAttacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_MeleeAttacks_SneakAttacks); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_MeleeAttacks_SneakAttacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_MeleeAttacks_SneakAttacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_MeleeAttacks_SneakAttacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_MeleeAttacks_SneakAttacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_hostiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_hostiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_hostiles; }
}
#undef C

#define C Protobuf::Stats_Combat_MeleeAttacks
struct OpPb_A_Stats_Combat_MeleeAttacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_MeleeAttacks); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_MeleeAttacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_MeleeAttacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_MeleeAttacks); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_MeleeAttacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_MeleeAttacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_MeleeAttacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_MeleeAttacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_kinetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinetic; }
	{ void (C::*p)() = &C::clear_thermal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermal; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermal; }
	{ void (C::*p)() = &C::clear_explosive; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosive; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosive; }
	{ void (C::*p)() = &C::clear_electromagnetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::electromagnetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_electromagnetic; }
	{ void (C::*p)() = &C::clear_impact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact; }
	{ void (C::*p)() = &C::clear_slashing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slashing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slashing; }
	{ void (C::*p)() = &C::clear_piercing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::piercing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_piercing; }
	{ void (C::*p)() = &C::clear_entropic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entropic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entropic; }
	{ void (C::*p)() = &C::clear_phasic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phasic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phasic; }
	{ bool (C::*p)() const = &C::has_sneak_attacks; }
	{ void (C::*p)() = &C::clear_sneak_attacks; }
	{ const ::Protobuf::Stats_Combat_MeleeAttacks_SneakAttacks& (C::*p)() const = &C::sneak_attacks; }
	{ ::Protobuf::Stats_Combat_MeleeAttacks_SneakAttacks* (C::*p)() = &C::release_sneak_attacks; }
	{ ::Protobuf::Stats_Combat_MeleeAttacks_SneakAttacks* (C::*p)() = &C::mutable_sneak_attacks; }
	{ void (C::*p)(::Protobuf::Stats_Combat_MeleeAttacks_SneakAttacks* sneak_attacks) = &C::set_allocated_sneak_attacks; }
	{ void (C::*p)() = &C::clear_follow_up_attacks; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::follow_up_attacks; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_follow_up_attacks; }
	{ void (C::*p)() = &C::clear_martial_strikes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::martial_strikes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_martial_strikes; }
}
#undef C

#define C Protobuf::Stats_Combat_DamageInflicted
struct OpPb_A_Stats_Combat_DamageInflicted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_DamageInflicted); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_DamageInflicted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_DamageInflicted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_DamageInflicted); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_DamageInflicted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_DamageInflicted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_DamageInflicted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_DamageInflicted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_guns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_guns; }
	{ void (C::*p)() = &C::clear_cannons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cannons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cannons; }
	{ void (C::*p)() = &C::clear_explosions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosions; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
	{ void (C::*p)() = &C::clear_ramming; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ramming; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ramming; }
	{ void (C::*p)() = &C::clear_kinetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinetic; }
	{ void (C::*p)() = &C::clear_thermal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermal; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermal; }
	{ void (C::*p)() = &C::clear_explosive; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosive; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosive; }
	{ void (C::*p)() = &C::clear_electromagnetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::electromagnetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_electromagnetic; }
	{ void (C::*p)() = &C::clear_impact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact; }
	{ void (C::*p)() = &C::clear_slashing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slashing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slashing; }
	{ void (C::*p)() = &C::clear_piercing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::piercing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_piercing; }
	{ void (C::*p)() = &C::clear_entropic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entropic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entropic; }
	{ void (C::*p)() = &C::clear_phasic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phasic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phasic; }
}
#undef C

#define C Protobuf::Stats_Combat_HighestCorruption_Effects
struct OpPb_A_Stats_Combat_HighestCorruption_Effects { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HighestCorruption_Effects); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HighestCorruption_Effects, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HighestCorruption_Effects { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HighestCorruption_Effects); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HighestCorruption_Effects, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HighestCorruption_Effects()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HighestCorruption_Effects()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HighestCorruption_Effects()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_message_errors; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::message_errors; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_message_errors; }
	{ void (C::*p)() = &C::clear_matter_fused; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_fused; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_fused; }
	{ void (C::*p)() = &C::clear_heat_flow_errors; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_flow_errors; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_flow_errors; }
	{ void (C::*p)() = &C::clear_energy_discharges; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_discharges; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_discharges; }
	{ void (C::*p)() = &C::clear_parts_rejected; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_rejected; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_rejected; }
	{ void (C::*p)() = &C::clear_parts_fused; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_fused; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_fused; }
	{ void (C::*p)() = &C::clear_data_loss_minor_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::data_loss_minor_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_data_loss_minor_; }
	{ void (C::*p)() = &C::clear_data_loss_major_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::data_loss_major_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_data_loss_major_; }
	{ void (C::*p)() = &C::clear_misfires; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::misfires; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_misfires; }
	{ void (C::*p)() = &C::clear_alerts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::alerts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_alerts; }
	{ void (C::*p)() = &C::clear_misdirections; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::misdirections; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_misdirections; }
	{ void (C::*p)() = &C::clear_targeting_errors; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::targeting_errors; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_targeting_errors; }
	{ void (C::*p)() = &C::clear_weapon_failures; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon_failures; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon_failures; }
}
#undef C

#define C Protobuf::Stats_Combat_HighestCorruption
struct OpPb_A_Stats_Combat_HighestCorruption { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HighestCorruption); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HighestCorruption, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HighestCorruption { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HighestCorruption); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HighestCorruption, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HighestCorruption()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HighestCorruption()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HighestCorruption()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_average_corruption; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_corruption; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_corruption; }
	{ void (C::*p)() = &C::clear_corruption_purged; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corruption_purged; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corruption_purged; }
	{ void (C::*p)() = &C::clear_corruption_blocked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corruption_blocked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corruption_blocked; }
	{ bool (C::*p)() const = &C::has_effects; }
	{ void (C::*p)() = &C::clear_effects; }
	{ const ::Protobuf::Stats_Combat_HighestCorruption_Effects& (C::*p)() const = &C::effects; }
	{ ::Protobuf::Stats_Combat_HighestCorruption_Effects* (C::*p)() = &C::release_effects; }
	{ ::Protobuf::Stats_Combat_HighestCorruption_Effects* (C::*p)() = &C::mutable_effects; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HighestCorruption_Effects* effects) = &C::set_allocated_effects; }
}
#undef C

#define C Protobuf::Stats_Combat_OverloadShots_Effects
struct OpPb_A_Stats_Combat_OverloadShots_Effects { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_OverloadShots_Effects); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_OverloadShots_Effects, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_OverloadShots_Effects { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_OverloadShots_Effects); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_OverloadShots_Effects, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_OverloadShots_Effects()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_OverloadShots_Effects()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_OverloadShots_Effects()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_energy_bleed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_bleed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_bleed; }
	{ void (C::*p)() = &C::clear_heat_surge; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_surge; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_surge; }
	{ void (C::*p)() = &C::clear_short_circuit; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::short_circuit; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_short_circuit; }
	{ void (C::*p)() = &C::clear_meltdown; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::meltdown; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_meltdown; }
}
#undef C

#define C Protobuf::Stats_Combat_OverloadShots
struct OpPb_A_Stats_Combat_OverloadShots { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_OverloadShots); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_OverloadShots, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_OverloadShots { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_OverloadShots); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_OverloadShots, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_OverloadShots()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_OverloadShots()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_OverloadShots()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_effects; }
	{ void (C::*p)() = &C::clear_effects; }
	{ const ::Protobuf::Stats_Combat_OverloadShots_Effects& (C::*p)() const = &C::effects; }
	{ ::Protobuf::Stats_Combat_OverloadShots_Effects* (C::*p)() = &C::release_effects; }
	{ ::Protobuf::Stats_Combat_OverloadShots_Effects* (C::*p)() = &C::mutable_effects; }
	{ void (C::*p)(::Protobuf::Stats_Combat_OverloadShots_Effects* effects) = &C::set_allocated_effects; }
}
#undef C

#define C Protobuf::Stats_Combat_OverflowDamage
struct OpPb_A_Stats_Combat_OverflowDamage { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_OverflowDamage); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_OverflowDamage, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_OverflowDamage { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_OverflowDamage); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_OverflowDamage, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_OverflowDamage()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_OverflowDamage()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_OverflowDamage()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_projectiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::projectiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_projectiles; }
	{ void (C::*p)() = &C::clear_explosions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosions; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
}
#undef C

#define C Protobuf::Stats_Combat_Knockbacks
struct OpPb_A_Stats_Combat_Knockbacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_Knockbacks); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_Knockbacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_Knockbacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_Knockbacks); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_Knockbacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_Knockbacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_Knockbacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_Knockbacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_impact; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact; }
	{ void (C::*p)() = &C::clear_kinetic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinetic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinetic; }
	{ void (C::*p)() = &C::clear_secondary; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::secondary; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_secondary; }
}
#undef C

#define C Protobuf::Stats_Combat_SelfInflictedDamage
struct OpPb_A_Stats_Combat_SelfInflictedDamage { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_SelfInflictedDamage); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_SelfInflictedDamage, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_SelfInflictedDamage { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_SelfInflictedDamage); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_SelfInflictedDamage, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_SelfInflictedDamage()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_SelfInflictedDamage()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_SelfInflictedDamage()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_shots; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::shots; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_shots; }
	{ void (C::*p)() = &C::clear_rammed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::rammed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_rammed; }
}
#undef C

#define C Protobuf::Stats_Combat_TargetsRammed
struct OpPb_A_Stats_Combat_TargetsRammed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_TargetsRammed); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_TargetsRammed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_TargetsRammed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_TargetsRammed); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_TargetsRammed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_TargetsRammed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_TargetsRammed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_TargetsRammed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_kicked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kicked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kicked; }
	{ void (C::*p)() = &C::clear_crushed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::crushed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_crushed; }
}
#undef C

#define C Protobuf::Stats_Combat_HighestTemperature_Effects
struct OpPb_A_Stats_Combat_HighestTemperature_Effects { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HighestTemperature_Effects); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HighestTemperature_Effects, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HighestTemperature_Effects { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HighestTemperature_Effects); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HighestTemperature_Effects, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HighestTemperature_Effects()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HighestTemperature_Effects()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HighestTemperature_Effects()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_shutdowns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::shutdowns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_shutdowns; }
	{ void (C::*p)() = &C::clear_energy_bleed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_bleed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_bleed; }
	{ void (C::*p)() = &C::clear_interference; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::interference; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_interference; }
	{ void (C::*p)() = &C::clear_matter_decay; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_decay; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_decay; }
	{ void (C::*p)() = &C::clear_short_circuit; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::short_circuit; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_short_circuit; }
	{ void (C::*p)() = &C::clear_damage_minor_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::damage_minor_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_damage_minor_; }
	{ void (C::*p)() = &C::clear_damage_major_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::damage_major_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_damage_major_; }
	{ void (C::*p)() = &C::clear_damage_core_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::damage_core_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_damage_core_; }
}
#undef C

#define C Protobuf::Stats_Combat_HighestTemperature
struct OpPb_A_Stats_Combat_HighestTemperature { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_HighestTemperature); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_HighestTemperature, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_HighestTemperature { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_HighestTemperature); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_HighestTemperature, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_HighestTemperature()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_HighestTemperature()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_HighestTemperature()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_average_temperature; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_temperature; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_temperature; }
	{ void (C::*p)() = &C::clear_received_heat_transfer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::received_heat_transfer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_received_heat_transfer; }
	{ void (C::*p)() = &C::clear_thermoelectric_energy_gain; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermoelectric_energy_gain; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermoelectric_energy_gain; }
	{ bool (C::*p)() const = &C::has_effects; }
	{ void (C::*p)() = &C::clear_effects; }
	{ const ::Protobuf::Stats_Combat_HighestTemperature_Effects& (C::*p)() const = &C::effects; }
	{ ::Protobuf::Stats_Combat_HighestTemperature_Effects* (C::*p)() = &C::release_effects; }
	{ ::Protobuf::Stats_Combat_HighestTemperature_Effects* (C::*p)() = &C::mutable_effects; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HighestTemperature_Effects* effects) = &C::set_allocated_effects; }
}
#undef C

#define C Protobuf::Stats_Combat_SiegeActivations
struct OpPb_A_Stats_Combat_SiegeActivations { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_SiegeActivations); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_SiegeActivations, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_SiegeActivations { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_SiegeActivations); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_SiegeActivations, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_SiegeActivations()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_SiegeActivations()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_SiegeActivations()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_total_turns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_turns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_turns; }
	{ void (C::*p)() = &C::clear_longest_duration; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::longest_duration; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_longest_duration; }
}
#undef C

#define C Protobuf::Stats_Combat_MartialActivations
struct OpPb_A_Stats_Combat_MartialActivations { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_MartialActivations); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_MartialActivations, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_MartialActivations { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_MartialActivations); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_MartialActivations, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_MartialActivations()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_MartialActivations()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_MartialActivations()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_total_turns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_turns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_turns; }
	{ void (C::*p)() = &C::clear_longest_duration; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::longest_duration; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_longest_duration; }
}
#undef C

#define C Protobuf::Stats_Combat_ShieldingActivations
struct OpPb_A_Stats_Combat_ShieldingActivations { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_ShieldingActivations); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_ShieldingActivations, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_ShieldingActivations { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_ShieldingActivations); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_ShieldingActivations, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_ShieldingActivations()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_ShieldingActivations()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_ShieldingActivations()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_total_turns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_turns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_turns; }
	{ void (C::*p)() = &C::clear_longest_duration; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::longest_duration; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_longest_duration; }
}
#undef C

#define C Protobuf::Stats_Combat_RobotsDisrupted
struct OpPb_A_Stats_Combat_RobotsDisrupted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_RobotsDisrupted); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_RobotsDisrupted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_RobotsDisrupted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_RobotsDisrupted); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_RobotsDisrupted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_RobotsDisrupted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_RobotsDisrupted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_RobotsDisrupted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_hostiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_hostiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_hostiles; }
}
#undef C

#define C Protobuf::Stats_Combat_RobotsCorrupted
struct OpPb_A_Stats_Combat_RobotsCorrupted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_RobotsCorrupted); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_RobotsCorrupted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_RobotsCorrupted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_RobotsCorrupted); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_RobotsCorrupted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_RobotsCorrupted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_RobotsCorrupted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_RobotsCorrupted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_hostiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_hostiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_hostiles; }
	{ void (C::*p)() = &C::clear_parts_fried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_fried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_fried; }
	{ void (C::*p)() = &C::clear_impact_corruptions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::impact_corruptions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_impact_corruptions; }
}
#undef C

#define C Protobuf::Stats_Combat_RobotsMelted
struct OpPb_A_Stats_Combat_RobotsMelted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_RobotsMelted); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_RobotsMelted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_RobotsMelted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_RobotsMelted); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_RobotsMelted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_RobotsMelted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_RobotsMelted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_RobotsMelted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_hostiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_hostiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_hostiles; }
	{ void (C::*p)() = &C::clear_parts_melted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_melted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_melted; }
	{ void (C::*p)() = &C::clear_heat_transferred; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_transferred; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_transferred; }
}
#undef C

#define C Protobuf::Stats_Combat_LatentEnergyUsed
struct OpPb_A_Stats_Combat_LatentEnergyUsed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat_LatentEnergyUsed); };
template struct OpPb_Rob<OpPb_A_Stats_Combat_LatentEnergyUsed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat_LatentEnergyUsed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat_LatentEnergyUsed); };
template struct OpPb_Rob<OpPb_M_Stats_Combat_LatentEnergyUsed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat_LatentEnergyUsed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat_LatentEnergyUsed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat_LatentEnergyUsed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_le_corruption; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::le_corruption; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_le_corruption; }
}
#undef C

#define C Protobuf::Stats_Combat
struct OpPb_A_Stats_Combat { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Combat); };
template struct OpPb_Rob<OpPb_A_Stats_Combat, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Combat { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Combat); };
template struct OpPb_Rob<OpPb_M_Stats_Combat, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Combat()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Combat()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Combat()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_hostile_shots_fired; }
	{ void (C::*p)() = &C::clear_hostile_shots_fired; }
	{ const ::Protobuf::Stats_Combat_HostileShotsFired& (C::*p)() const = &C::hostile_shots_fired; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired* (C::*p)() = &C::release_hostile_shots_fired; }
	{ ::Protobuf::Stats_Combat_HostileShotsFired* (C::*p)() = &C::mutable_hostile_shots_fired; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HostileShotsFired* hostile_shots_fired) = &C::set_allocated_hostile_shots_fired; }
	{ bool (C::*p)() const = &C::has_damage_taken; }
	{ void (C::*p)() = &C::clear_damage_taken; }
	{ const ::Protobuf::Stats_Combat_DamageTaken& (C::*p)() const = &C::damage_taken; }
	{ ::Protobuf::Stats_Combat_DamageTaken* (C::*p)() = &C::release_damage_taken; }
	{ ::Protobuf::Stats_Combat_DamageTaken* (C::*p)() = &C::mutable_damage_taken; }
	{ void (C::*p)(::Protobuf::Stats_Combat_DamageTaken* damage_taken) = &C::set_allocated_damage_taken; }
	{ void (C::*p)() = &C::clear_core_remaining_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core_remaining_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core_remaining_percent; }
	{ bool (C::*p)() const = &C::has_volleys_fired; }
	{ void (C::*p)() = &C::clear_volleys_fired; }
	{ const ::Protobuf::Stats_Combat_VolleysFired& (C::*p)() const = &C::volleys_fired; }
	{ ::Protobuf::Stats_Combat_VolleysFired* (C::*p)() = &C::release_volleys_fired; }
	{ ::Protobuf::Stats_Combat_VolleysFired* (C::*p)() = &C::mutable_volleys_fired; }
	{ void (C::*p)(::Protobuf::Stats_Combat_VolleysFired* volleys_fired) = &C::set_allocated_volleys_fired; }
	{ bool (C::*p)() const = &C::has_shots_fired; }
	{ void (C::*p)() = &C::clear_shots_fired; }
	{ const ::Protobuf::Stats_Combat_ShotsFired& (C::*p)() const = &C::shots_fired; }
	{ ::Protobuf::Stats_Combat_ShotsFired* (C::*p)() = &C::release_shots_fired; }
	{ ::Protobuf::Stats_Combat_ShotsFired* (C::*p)() = &C::mutable_shots_fired; }
	{ void (C::*p)(::Protobuf::Stats_Combat_ShotsFired* shots_fired) = &C::set_allocated_shots_fired; }
	{ bool (C::*p)() const = &C::has_shots_hit_robots; }
	{ void (C::*p)() = &C::clear_shots_hit_robots; }
	{ const ::Protobuf::Stats_Combat_ShotsHitRobots& (C::*p)() const = &C::shots_hit_robots; }
	{ ::Protobuf::Stats_Combat_ShotsHitRobots* (C::*p)() = &C::release_shots_hit_robots; }
	{ ::Protobuf::Stats_Combat_ShotsHitRobots* (C::*p)() = &C::mutable_shots_hit_robots; }
	{ void (C::*p)(::Protobuf::Stats_Combat_ShotsHitRobots* shots_hit_robots) = &C::set_allocated_shots_hit_robots; }
	{ bool (C::*p)() const = &C::has_melee_attacks; }
	{ void (C::*p)() = &C::clear_melee_attacks; }
	{ const ::Protobuf::Stats_Combat_MeleeAttacks& (C::*p)() const = &C::melee_attacks; }
	{ ::Protobuf::Stats_Combat_MeleeAttacks* (C::*p)() = &C::release_melee_attacks; }
	{ ::Protobuf::Stats_Combat_MeleeAttacks* (C::*p)() = &C::mutable_melee_attacks; }
	{ void (C::*p)(::Protobuf::Stats_Combat_MeleeAttacks* melee_attacks) = &C::set_allocated_melee_attacks; }
	{ bool (C::*p)() const = &C::has_damage_inflicted; }
	{ void (C::*p)() = &C::clear_damage_inflicted; }
	{ const ::Protobuf::Stats_Combat_DamageInflicted& (C::*p)() const = &C::damage_inflicted; }
	{ ::Protobuf::Stats_Combat_DamageInflicted* (C::*p)() = &C::release_damage_inflicted; }
	{ ::Protobuf::Stats_Combat_DamageInflicted* (C::*p)() = &C::mutable_damage_inflicted; }
	{ void (C::*p)(::Protobuf::Stats_Combat_DamageInflicted* damage_inflicted) = &C::set_allocated_damage_inflicted; }
	{ bool (C::*p)() const = &C::has_highest_corruption; }
	{ void (C::*p)() = &C::clear_highest_corruption; }
	{ const ::Protobuf::Stats_Combat_HighestCorruption& (C::*p)() const = &C::highest_corruption; }
	{ ::Protobuf::Stats_Combat_HighestCorruption* (C::*p)() = &C::release_highest_corruption; }
	{ ::Protobuf::Stats_Combat_HighestCorruption* (C::*p)() = &C::mutable_highest_corruption; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HighestCorruption* highest_corruption) = &C::set_allocated_highest_corruption; }
	{ bool (C::*p)() const = &C::has_overload_shots; }
	{ void (C::*p)() = &C::clear_overload_shots; }
	{ const ::Protobuf::Stats_Combat_OverloadShots& (C::*p)() const = &C::overload_shots; }
	{ ::Protobuf::Stats_Combat_OverloadShots* (C::*p)() = &C::release_overload_shots; }
	{ ::Protobuf::Stats_Combat_OverloadShots* (C::*p)() = &C::mutable_overload_shots; }
	{ void (C::*p)(::Protobuf::Stats_Combat_OverloadShots* overload_shots) = &C::set_allocated_overload_shots; }
	{ bool (C::*p)() const = &C::has_overflow_damage; }
	{ void (C::*p)() = &C::clear_overflow_damage; }
	{ const ::Protobuf::Stats_Combat_OverflowDamage& (C::*p)() const = &C::overflow_damage; }
	{ ::Protobuf::Stats_Combat_OverflowDamage* (C::*p)() = &C::release_overflow_damage; }
	{ ::Protobuf::Stats_Combat_OverflowDamage* (C::*p)() = &C::mutable_overflow_damage; }
	{ void (C::*p)(::Protobuf::Stats_Combat_OverflowDamage* overflow_damage) = &C::set_allocated_overflow_damage; }
	{ bool (C::*p)() const = &C::has_knockbacks; }
	{ void (C::*p)() = &C::clear_knockbacks; }
	{ const ::Protobuf::Stats_Combat_Knockbacks& (C::*p)() const = &C::knockbacks; }
	{ ::Protobuf::Stats_Combat_Knockbacks* (C::*p)() = &C::release_knockbacks; }
	{ ::Protobuf::Stats_Combat_Knockbacks* (C::*p)() = &C::mutable_knockbacks; }
	{ void (C::*p)(::Protobuf::Stats_Combat_Knockbacks* knockbacks) = &C::set_allocated_knockbacks; }
	{ bool (C::*p)() const = &C::has_self_inflicted_damage; }
	{ void (C::*p)() = &C::clear_self_inflicted_damage; }
	{ const ::Protobuf::Stats_Combat_SelfInflictedDamage& (C::*p)() const = &C::self_inflicted_damage; }
	{ ::Protobuf::Stats_Combat_SelfInflictedDamage* (C::*p)() = &C::release_self_inflicted_damage; }
	{ ::Protobuf::Stats_Combat_SelfInflictedDamage* (C::*p)() = &C::mutable_self_inflicted_damage; }
	{ void (C::*p)(::Protobuf::Stats_Combat_SelfInflictedDamage* self_inflicted_damage) = &C::set_allocated_self_inflicted_damage; }
	{ bool (C::*p)() const = &C::has_targets_rammed; }
	{ void (C::*p)() = &C::clear_targets_rammed; }
	{ const ::Protobuf::Stats_Combat_TargetsRammed& (C::*p)() const = &C::targets_rammed; }
	{ ::Protobuf::Stats_Combat_TargetsRammed* (C::*p)() = &C::release_targets_rammed; }
	{ ::Protobuf::Stats_Combat_TargetsRammed* (C::*p)() = &C::mutable_targets_rammed; }
	{ void (C::*p)(::Protobuf::Stats_Combat_TargetsRammed* targets_rammed) = &C::set_allocated_targets_rammed; }
	{ bool (C::*p)() const = &C::has_highest_temperature; }
	{ void (C::*p)() = &C::clear_highest_temperature; }
	{ const ::Protobuf::Stats_Combat_HighestTemperature& (C::*p)() const = &C::highest_temperature; }
	{ ::Protobuf::Stats_Combat_HighestTemperature* (C::*p)() = &C::release_highest_temperature; }
	{ ::Protobuf::Stats_Combat_HighestTemperature* (C::*p)() = &C::mutable_highest_temperature; }
	{ void (C::*p)(::Protobuf::Stats_Combat_HighestTemperature* highest_temperature) = &C::set_allocated_highest_temperature; }
	{ bool (C::*p)() const = &C::has_siege_activations; }
	{ void (C::*p)() = &C::clear_siege_activations; }
	{ const ::Protobuf::Stats_Combat_SiegeActivations& (C::*p)() const = &C::siege_activations; }
	{ ::Protobuf::Stats_Combat_SiegeActivations* (C::*p)() = &C::release_siege_activations; }
	{ ::Protobuf::Stats_Combat_SiegeActivations* (C::*p)() = &C::mutable_siege_activations; }
	{ void (C::*p)(::Protobuf::Stats_Combat_SiegeActivations* siege_activations) = &C::set_allocated_siege_activations; }
	{ bool (C::*p)() const = &C::has_martial_activations; }
	{ void (C::*p)() = &C::clear_martial_activations; }
	{ const ::Protobuf::Stats_Combat_MartialActivations& (C::*p)() const = &C::martial_activations; }
	{ ::Protobuf::Stats_Combat_MartialActivations* (C::*p)() = &C::release_martial_activations; }
	{ ::Protobuf::Stats_Combat_MartialActivations* (C::*p)() = &C::mutable_martial_activations; }
	{ void (C::*p)(::Protobuf::Stats_Combat_MartialActivations* martial_activations) = &C::set_allocated_martial_activations; }
	{ bool (C::*p)() const = &C::has_shielding_activations; }
	{ void (C::*p)() = &C::clear_shielding_activations; }
	{ const ::Protobuf::Stats_Combat_ShieldingActivations& (C::*p)() const = &C::shielding_activations; }
	{ ::Protobuf::Stats_Combat_ShieldingActivations* (C::*p)() = &C::release_shielding_activations; }
	{ ::Protobuf::Stats_Combat_ShieldingActivations* (C::*p)() = &C::mutable_shielding_activations; }
	{ void (C::*p)(::Protobuf::Stats_Combat_ShieldingActivations* shielding_activations) = &C::set_allocated_shielding_activations; }
	{ bool (C::*p)() const = &C::has_robots_disrupted; }
	{ void (C::*p)() = &C::clear_robots_disrupted; }
	{ const ::Protobuf::Stats_Combat_RobotsDisrupted& (C::*p)() const = &C::robots_disrupted; }
	{ ::Protobuf::Stats_Combat_RobotsDisrupted* (C::*p)() = &C::release_robots_disrupted; }
	{ ::Protobuf::Stats_Combat_RobotsDisrupted* (C::*p)() = &C::mutable_robots_disrupted; }
	{ void (C::*p)(::Protobuf::Stats_Combat_RobotsDisrupted* robots_disrupted) = &C::set_allocated_robots_disrupted; }
	{ bool (C::*p)() const = &C::has_robots_corrupted; }
	{ void (C::*p)() = &C::clear_robots_corrupted; }
	{ const ::Protobuf::Stats_Combat_RobotsCorrupted& (C::*p)() const = &C::robots_corrupted; }
	{ ::Protobuf::Stats_Combat_RobotsCorrupted* (C::*p)() = &C::release_robots_corrupted; }
	{ ::Protobuf::Stats_Combat_RobotsCorrupted* (C::*p)() = &C::mutable_robots_corrupted; }
	{ void (C::*p)(::Protobuf::Stats_Combat_RobotsCorrupted* robots_corrupted) = &C::set_allocated_robots_corrupted; }
	{ bool (C::*p)() const = &C::has_robots_melted; }
	{ void (C::*p)() = &C::clear_robots_melted; }
	{ const ::Protobuf::Stats_Combat_RobotsMelted& (C::*p)() const = &C::robots_melted; }
	{ ::Protobuf::Stats_Combat_RobotsMelted* (C::*p)() = &C::release_robots_melted; }
	{ ::Protobuf::Stats_Combat_RobotsMelted* (C::*p)() = &C::mutable_robots_melted; }
	{ void (C::*p)(::Protobuf::Stats_Combat_RobotsMelted* robots_melted) = &C::set_allocated_robots_melted; }
	{ void (C::*p)() = &C::clear_parts_sabotaged; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_sabotaged; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_sabotaged; }
	{ void (C::*p)() = &C::clear_parts_stolen; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_stolen; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_stolen; }
	{ void (C::*p)() = &C::clear_parts_stripped; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_stripped; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_stripped; }
	{ void (C::*p)() = &C::clear_power_chain_reactions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power_chain_reactions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power_chain_reactions; }
	{ void (C::*p)() = &C::clear_missiles_intercepted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::missiles_intercepted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_missiles_intercepted; }
	{ bool (C::*p)() const = &C::has_latent_energy_used; }
	{ void (C::*p)() = &C::clear_latent_energy_used; }
	{ const ::Protobuf::Stats_Combat_LatentEnergyUsed& (C::*p)() const = &C::latent_energy_used; }
	{ ::Protobuf::Stats_Combat_LatentEnergyUsed* (C::*p)() = &C::release_latent_energy_used; }
	{ ::Protobuf::Stats_Combat_LatentEnergyUsed* (C::*p)() = &C::mutable_latent_energy_used; }
	{ void (C::*p)(::Protobuf::Stats_Combat_LatentEnergyUsed* latent_energy_used) = &C::set_allocated_latent_energy_used; }
}
#undef C

#define C Protobuf::Stats_Alert_MaximumAlertLevel
struct OpPb_A_Stats_Alert_MaximumAlertLevel { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert_MaximumAlertLevel); };
template struct OpPb_Rob<OpPb_A_Stats_Alert_MaximumAlertLevel, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert_MaximumAlertLevel { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert_MaximumAlertLevel); };
template struct OpPb_Rob<OpPb_M_Stats_Alert_MaximumAlertLevel, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert_MaximumAlertLevel()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert_MaximumAlertLevel()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert_MaximumAlertLevel()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_low_security_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::low_security_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_low_security_percent; }
	{ void (C::*p)() = &C::clear_level_1; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_1; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_1; }
	{ void (C::*p)() = &C::clear_level_2; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_2; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_2; }
	{ void (C::*p)() = &C::clear_level_3; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_3; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_3; }
	{ void (C::*p)() = &C::clear_level_4; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_4; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_4; }
	{ void (C::*p)() = &C::clear_level_5; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_5; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_5; }
	{ void (C::*p)() = &C::clear_high_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::high_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_high_security; }
	{ void (C::*p)() = &C::clear_max_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::max_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_max_security; }
}
#undef C

#define C Protobuf::Stats_Alert_PeakInfluence
struct OpPb_A_Stats_Alert_PeakInfluence { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert_PeakInfluence); };
template struct OpPb_Rob<OpPb_A_Stats_Alert_PeakInfluence, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert_PeakInfluence { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert_PeakInfluence); };
template struct OpPb_Rob<OpPb_M_Stats_Alert_PeakInfluence, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert_PeakInfluence()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert_PeakInfluence()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert_PeakInfluence()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_initial_influence; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::initial_influence; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_initial_influence; }
	{ void (C::*p)() = &C::clear_average_influence; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_influence; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_influence; }
}
#undef C

#define C Protobuf::Stats_Alert_InfluenceIncreases
struct OpPb_A_Stats_Alert_InfluenceIncreases { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert_InfluenceIncreases); };
template struct OpPb_Rob<OpPb_A_Stats_Alert_InfluenceIncreases, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert_InfluenceIncreases { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert_InfluenceIncreases); };
template struct OpPb_Rob<OpPb_M_Stats_Alert_InfluenceIncreases, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert_InfluenceIncreases()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert_InfluenceIncreases()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert_InfluenceIncreases()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_destroy_0b10_robot_c; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroy_0b10_robot_c; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroy_0b10_robot_c; }
	{ void (C::*p)() = &C::clear_destroy_0b10_robot_nc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroy_0b10_robot_nc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroy_0b10_robot_nc; }
	{ void (C::*p)() = &C::clear_destroy_leader; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroy_leader; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroy_leader; }
	{ void (C::*p)() = &C::clear_allied_during_kill; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::allied_during_kill; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_allied_during_kill; }
	{ void (C::*p)() = &C::clear_trap_triggered_on_0b10; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trap_triggered_on_0b10; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trap_triggered_on_0b10; }
	{ void (C::*p)() = &C::clear_successful_hack; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::successful_hack; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_successful_hack; }
	{ void (C::*p)() = &C::clear_select_force_hacks; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::select_force_hacks; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_select_force_hacks; }
	{ void (C::*p)() = &C::clear_disable_machine; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disable_machine; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disable_machine; }
	{ void (C::*p)() = &C::clear_anti_garrison_action; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::anti_garrison_action; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_anti_garrison_action; }
	{ void (C::*p)() = &C::clear_destroy_structure; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::destroy_structure; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_destroy_structure; }
	{ void (C::*p)() = &C::clear_advance_influence; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::advance_influence; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_advance_influence; }
	{ void (C::*p)() = &C::clear_partial_spotted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::partial_spotted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_partial_spotted; }
	{ void (C::*p)() = &C::clear_lose_combat_pursuer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::lose_combat_pursuer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_lose_combat_pursuer; }
	{ void (C::*p)() = &C::clear_active_sensor_use; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::active_sensor_use; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_active_sensor_use; }
	{ void (C::*p)() = &C::clear_miscellaneous; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::miscellaneous; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_miscellaneous; }
}
#undef C

#define C Protobuf::Stats_Alert_InfluenceDecreases
struct OpPb_A_Stats_Alert_InfluenceDecreases { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert_InfluenceDecreases); };
template struct OpPb_Rob<OpPb_A_Stats_Alert_InfluenceDecreases, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert_InfluenceDecreases { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert_InfluenceDecreases); };
template struct OpPb_Rob<OpPb_M_Stats_Alert_InfluenceDecreases, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert_InfluenceDecreases()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert_InfluenceDecreases()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert_InfluenceDecreases()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_entered_new_map; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::entered_new_map; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_entered_new_map; }
	{ void (C::*p)() = &C::clear_time_decay; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::time_decay; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_time_decay; }
	{ void (C::*p)() = &C::clear_search_patrol_dispatched; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::search_patrol_dispatched; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_search_patrol_dispatched; }
	{ void (C::*p)() = &C::clear_lost_part; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::lost_part; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_lost_part; }
	{ void (C::*p)() = &C::clear_lost_ally; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::lost_ally; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_lost_ally; }
	{ void (C::*p)() = &C::clear_purge_threat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::purge_threat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_purge_threat; }
	{ void (C::*p)() = &C::clear_miscellaneous; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::miscellaneous; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_miscellaneous; }
}
#undef C

#define C Protobuf::Stats_Alert_SquadsDispatched
struct OpPb_A_Stats_Alert_SquadsDispatched { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert_SquadsDispatched); };
template struct OpPb_Rob<OpPb_A_Stats_Alert_SquadsDispatched, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert_SquadsDispatched { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert_SquadsDispatched); };
template struct OpPb_Rob<OpPb_M_Stats_Alert_SquadsDispatched, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert_SquadsDispatched()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert_SquadsDispatched()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert_SquadsDispatched()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_investigation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::investigation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_investigation; }
	{ void (C::*p)() = &C::clear_extermination; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::extermination; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_extermination; }
	{ void (C::*p)() = &C::clear_reinforcement; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reinforcement; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reinforcement; }
	{ void (C::*p)() = &C::clear_assault; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::assault; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_assault; }
	{ void (C::*p)() = &C::clear_garrison; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison; }
	{ void (C::*p)() = &C::clear_intercept; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::intercept; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_intercept; }
}
#undef C

#define C Protobuf::Stats_Alert
struct OpPb_A_Stats_Alert { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Alert); };
template struct OpPb_Rob<OpPb_A_Stats_Alert, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Alert { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Alert); };
template struct OpPb_Rob<OpPb_M_Stats_Alert, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Alert()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Alert()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Alert()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_maximum_alert_level; }
	{ void (C::*p)() = &C::clear_maximum_alert_level; }
	{ const ::Protobuf::Stats_Alert_MaximumAlertLevel& (C::*p)() const = &C::maximum_alert_level; }
	{ ::Protobuf::Stats_Alert_MaximumAlertLevel* (C::*p)() = &C::release_maximum_alert_level; }
	{ ::Protobuf::Stats_Alert_MaximumAlertLevel* (C::*p)() = &C::mutable_maximum_alert_level; }
	{ void (C::*p)(::Protobuf::Stats_Alert_MaximumAlertLevel* maximum_alert_level) = &C::set_allocated_maximum_alert_level; }
	{ void (C::*p)() = &C::clear_sterilizations; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sterilizations; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sterilizations; }
	{ bool (C::*p)() const = &C::has_peak_influence; }
	{ void (C::*p)() = &C::clear_peak_influence; }
	{ const ::Protobuf::Stats_Alert_PeakInfluence& (C::*p)() const = &C::peak_influence; }
	{ ::Protobuf::Stats_Alert_PeakInfluence* (C::*p)() = &C::release_peak_influence; }
	{ ::Protobuf::Stats_Alert_PeakInfluence* (C::*p)() = &C::mutable_peak_influence; }
	{ void (C::*p)(::Protobuf::Stats_Alert_PeakInfluence* peak_influence) = &C::set_allocated_peak_influence; }
	{ bool (C::*p)() const = &C::has_influence_increases; }
	{ void (C::*p)() = &C::clear_influence_increases; }
	{ const ::Protobuf::Stats_Alert_InfluenceIncreases& (C::*p)() const = &C::influence_increases; }
	{ ::Protobuf::Stats_Alert_InfluenceIncreases* (C::*p)() = &C::release_influence_increases; }
	{ ::Protobuf::Stats_Alert_InfluenceIncreases* (C::*p)() = &C::mutable_influence_increases; }
	{ void (C::*p)(::Protobuf::Stats_Alert_InfluenceIncreases* influence_increases) = &C::set_allocated_influence_increases; }
	{ bool (C::*p)() const = &C::has_influence_decreases; }
	{ void (C::*p)() = &C::clear_influence_decreases; }
	{ const ::Protobuf::Stats_Alert_InfluenceDecreases& (C::*p)() const = &C::influence_decreases; }
	{ ::Protobuf::Stats_Alert_InfluenceDecreases* (C::*p)() = &C::release_influence_decreases; }
	{ ::Protobuf::Stats_Alert_InfluenceDecreases* (C::*p)() = &C::mutable_influence_decreases; }
	{ void (C::*p)(::Protobuf::Stats_Alert_InfluenceDecreases* influence_decreases) = &C::set_allocated_influence_decreases; }
	{ bool (C::*p)() const = &C::has_squads_dispatched; }
	{ void (C::*p)() = &C::clear_squads_dispatched; }
	{ const ::Protobuf::Stats_Alert_SquadsDispatched& (C::*p)() const = &C::squads_dispatched; }
	{ ::Protobuf::Stats_Alert_SquadsDispatched* (C::*p)() = &C::release_squads_dispatched; }
	{ ::Protobuf::Stats_Alert_SquadsDispatched* (C::*p)() = &C::mutable_squads_dispatched; }
	{ void (C::*p)(::Protobuf::Stats_Alert_SquadsDispatched* squads_dispatched) = &C::set_allocated_squads_dispatched; }
	{ void (C::*p)() = &C::clear_searches_triggered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::searches_triggered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_searches_triggered; }
	{ void (C::*p)() = &C::clear_unchained_authorized; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unchained_authorized; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unchained_authorized; }
	{ void (C::*p)() = &C::clear_data_miner_redirects; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::data_miner_redirects; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_data_miner_redirects; }
	{ void (C::*p)() = &C::clear_construction_impeded; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::construction_impeded; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_construction_impeded; }
	{ void (C::*p)() = &C::clear_haulers_reinforced; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::haulers_reinforced; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_haulers_reinforced; }
	{ void (C::*p)() = &C::clear_active_scanning_responses; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::active_scanning_responses; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_active_scanning_responses; }
	{ void (C::*p)() = &C::clear_cargo_convoy_interrupts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cargo_convoy_interrupts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cargo_convoy_interrupts; }
	{ void (C::*p)() = &C::clear_alert_id_control_effect; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::alert_id_control_effect; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_alert_id_control_effect; }
}
#undef C

#define C Protobuf::Stats_Stealth_CommunicationsJammed
struct OpPb_A_Stats_Stealth_CommunicationsJammed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Stealth_CommunicationsJammed); };
template struct OpPb_Rob<OpPb_A_Stats_Stealth_CommunicationsJammed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Stealth_CommunicationsJammed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Stealth_CommunicationsJammed); };
template struct OpPb_Rob<OpPb_M_Stats_Stealth_CommunicationsJammed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Stealth_CommunicationsJammed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Stealth_CommunicationsJammed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Stealth_CommunicationsJammed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_distress_signals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::distress_signals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_distress_signals; }
}
#undef C

#define C Protobuf::Stats_Stealth_TimesSpotted
struct OpPb_A_Stats_Stealth_TimesSpotted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Stealth_TimesSpotted); };
template struct OpPb_Rob<OpPb_A_Stats_Stealth_TimesSpotted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Stealth_TimesSpotted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Stealth_TimesSpotted); };
template struct OpPb_Rob<OpPb_M_Stats_Stealth_TimesSpotted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Stealth_TimesSpotted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Stealth_TimesSpotted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Stealth_TimesSpotted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_peak_tracking_total; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::peak_tracking_total; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_peak_tracking_total; }
	{ void (C::*p)() = &C::clear_tactical_retreats; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tactical_retreats; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tactical_retreats; }
}
#undef C

#define C Protobuf::Stats_Stealth_IdMasksUsed
struct OpPb_A_Stats_Stealth_IdMasksUsed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Stealth_IdMasksUsed); };
template struct OpPb_Rob<OpPb_A_Stats_Stealth_IdMasksUsed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Stealth_IdMasksUsed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Stealth_IdMasksUsed); };
template struct OpPb_Rob<OpPb_M_Stats_Stealth_IdMasksUsed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Stealth_IdMasksUsed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Stealth_IdMasksUsed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Stealth_IdMasksUsed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_iff_responses; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::iff_responses; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_iff_responses; }
}
#undef C

#define C Protobuf::Stats_Stealth
struct OpPb_A_Stats_Stealth { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Stealth); };
template struct OpPb_Rob<OpPb_A_Stats_Stealth, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Stealth { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Stealth); };
template struct OpPb_Rob<OpPb_M_Stats_Stealth, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Stealth()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Stealth()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Stealth()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_distress_signals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::distress_signals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_distress_signals; }
	{ bool (C::*p)() const = &C::has_communications_jammed; }
	{ void (C::*p)() = &C::clear_communications_jammed; }
	{ const ::Protobuf::Stats_Stealth_CommunicationsJammed& (C::*p)() const = &C::communications_jammed; }
	{ ::Protobuf::Stats_Stealth_CommunicationsJammed* (C::*p)() = &C::release_communications_jammed; }
	{ ::Protobuf::Stats_Stealth_CommunicationsJammed* (C::*p)() = &C::mutable_communications_jammed; }
	{ void (C::*p)(::Protobuf::Stats_Stealth_CommunicationsJammed* communications_jammed) = &C::set_allocated_communications_jammed; }
	{ bool (C::*p)() const = &C::has_times_spotted; }
	{ void (C::*p)() = &C::clear_times_spotted; }
	{ const ::Protobuf::Stats_Stealth_TimesSpotted& (C::*p)() const = &C::times_spotted; }
	{ ::Protobuf::Stats_Stealth_TimesSpotted* (C::*p)() = &C::release_times_spotted; }
	{ ::Protobuf::Stats_Stealth_TimesSpotted* (C::*p)() = &C::mutable_times_spotted; }
	{ void (C::*p)(::Protobuf::Stats_Stealth_TimesSpotted* times_spotted) = &C::set_allocated_times_spotted; }
	{ void (C::*p)() = &C::clear_ecm_based_alert_blocks; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ecm_based_alert_blocks; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ecm_based_alert_blocks; }
	{ bool (C::*p)() const = &C::has_id_masks_used; }
	{ void (C::*p)() = &C::clear_id_masks_used; }
	{ const ::Protobuf::Stats_Stealth_IdMasksUsed& (C::*p)() const = &C::id_masks_used; }
	{ ::Protobuf::Stats_Stealth_IdMasksUsed* (C::*p)() = &C::release_id_masks_used; }
	{ ::Protobuf::Stats_Stealth_IdMasksUsed* (C::*p)() = &C::mutable_id_masks_used; }
	{ void (C::*p)(::Protobuf::Stats_Stealth_IdMasksUsed* id_masks_used) = &C::set_allocated_id_masks_used; }
}
#undef C

#define C Protobuf::Stats_Traps_TrapsTriggered
struct OpPb_A_Stats_Traps_TrapsTriggered { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps_TrapsTriggered); };
template struct OpPb_Rob<OpPb_A_Stats_Traps_TrapsTriggered, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps_TrapsTriggered { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps_TrapsTriggered); };
template struct OpPb_Rob<OpPb_M_Stats_Traps_TrapsTriggered, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps_TrapsTriggered()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps_TrapsTriggered()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps_TrapsTriggered()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_indirectly; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::indirectly; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_indirectly; }
}
#undef C

#define C Protobuf::Stats_Traps_TrapHackAttempts
struct OpPb_A_Stats_Traps_TrapHackAttempts { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps_TrapHackAttempts); };
template struct OpPb_Rob<OpPb_A_Stats_Traps_TrapHackAttempts, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps_TrapHackAttempts { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps_TrapHackAttempts); };
template struct OpPb_Rob<OpPb_M_Stats_Traps_TrapHackAttempts, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps_TrapHackAttempts()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps_TrapHackAttempts()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps_TrapHackAttempts()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_triggered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triggered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triggered; }
	{ void (C::*p)() = &C::clear_disarmed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disarmed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disarmed; }
	{ void (C::*p)() = &C::clear_reprogrammed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reprogrammed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reprogrammed; }
	{ void (C::*p)() = &C::clear_reused; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reused; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reused; }
}
#undef C

#define C Protobuf::Stats_Traps_TrapsExtracted
struct OpPb_A_Stats_Traps_TrapsExtracted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps_TrapsExtracted); };
template struct OpPb_Rob<OpPb_A_Stats_Traps_TrapsExtracted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps_TrapsExtracted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps_TrapsExtracted); };
template struct OpPb_Rob<OpPb_M_Stats_Traps_TrapsExtracted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps_TrapsExtracted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps_TrapsExtracted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps_TrapsExtracted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_installed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::installed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_installed; }
	{ void (C::*p)() = &C::clear_triggered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triggered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triggered; }
}
#undef C

#define C Protobuf::Stats_Traps_ObjectsRigged
struct OpPb_A_Stats_Traps_ObjectsRigged { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps_ObjectsRigged); };
template struct OpPb_Rob<OpPb_A_Stats_Traps_ObjectsRigged, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps_ObjectsRigged { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps_ObjectsRigged); };
template struct OpPb_Rob<OpPb_M_Stats_Traps_ObjectsRigged, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps_ObjectsRigged()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps_ObjectsRigged()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps_ObjectsRigged()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_exploded; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::exploded; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_exploded; }
}
#undef C

#define C Protobuf::Stats_Traps_TimeBombsActivated
struct OpPb_A_Stats_Traps_TimeBombsActivated { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps_TimeBombsActivated); };
template struct OpPb_Rob<OpPb_A_Stats_Traps_TimeBombsActivated, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps_TimeBombsActivated { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps_TimeBombsActivated); };
template struct OpPb_Rob<OpPb_M_Stats_Traps_TimeBombsActivated, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps_TimeBombsActivated()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps_TimeBombsActivated()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps_TimeBombsActivated()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_exploded; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::exploded; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_exploded; }
}
#undef C

#define C Protobuf::Stats_Traps
struct OpPb_A_Stats_Traps { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Traps); };
template struct OpPb_Rob<OpPb_A_Stats_Traps, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Traps { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Traps); };
template struct OpPb_Rob<OpPb_M_Stats_Traps, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Traps()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Traps()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Traps()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_traps_triggered; }
	{ void (C::*p)() = &C::clear_traps_triggered; }
	{ const ::Protobuf::Stats_Traps_TrapsTriggered& (C::*p)() const = &C::traps_triggered; }
	{ ::Protobuf::Stats_Traps_TrapsTriggered* (C::*p)() = &C::release_traps_triggered; }
	{ ::Protobuf::Stats_Traps_TrapsTriggered* (C::*p)() = &C::mutable_traps_triggered; }
	{ void (C::*p)(::Protobuf::Stats_Traps_TrapsTriggered* traps_triggered) = &C::set_allocated_traps_triggered; }
	{ bool (C::*p)() const = &C::has_trap_hack_attempts; }
	{ void (C::*p)() = &C::clear_trap_hack_attempts; }
	{ const ::Protobuf::Stats_Traps_TrapHackAttempts& (C::*p)() const = &C::trap_hack_attempts; }
	{ ::Protobuf::Stats_Traps_TrapHackAttempts* (C::*p)() = &C::release_trap_hack_attempts; }
	{ ::Protobuf::Stats_Traps_TrapHackAttempts* (C::*p)() = &C::mutable_trap_hack_attempts; }
	{ void (C::*p)(::Protobuf::Stats_Traps_TrapHackAttempts* trap_hack_attempts) = &C::set_allocated_trap_hack_attempts; }
	{ void (C::*p)() = &C::clear_traps_reconfigurated; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::traps_reconfigurated; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_traps_reconfigurated; }
	{ bool (C::*p)() const = &C::has_traps_extracted; }
	{ void (C::*p)() = &C::clear_traps_extracted; }
	{ const ::Protobuf::Stats_Traps_TrapsExtracted& (C::*p)() const = &C::traps_extracted; }
	{ ::Protobuf::Stats_Traps_TrapsExtracted* (C::*p)() = &C::release_traps_extracted; }
	{ ::Protobuf::Stats_Traps_TrapsExtracted* (C::*p)() = &C::mutable_traps_extracted; }
	{ void (C::*p)(::Protobuf::Stats_Traps_TrapsExtracted* traps_extracted) = &C::set_allocated_traps_extracted; }
	{ void (C::*p)() = &C::clear_fabricated_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabricated_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabricated_traps; }
	{ void (C::*p)() = &C::clear_most_traps_carried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::most_traps_carried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_most_traps_carried; }
	{ bool (C::*p)() const = &C::has_objects_rigged; }
	{ void (C::*p)() = &C::clear_objects_rigged; }
	{ const ::Protobuf::Stats_Traps_ObjectsRigged& (C::*p)() const = &C::objects_rigged; }
	{ ::Protobuf::Stats_Traps_ObjectsRigged* (C::*p)() = &C::release_objects_rigged; }
	{ ::Protobuf::Stats_Traps_ObjectsRigged* (C::*p)() = &C::mutable_objects_rigged; }
	{ void (C::*p)(::Protobuf::Stats_Traps_ObjectsRigged* objects_rigged) = &C::set_allocated_objects_rigged; }
	{ bool (C::*p)() const = &C::has_time_bombs_activated; }
	{ void (C::*p)() = &C::clear_time_bombs_activated; }
	{ const ::Protobuf::Stats_Traps_TimeBombsActivated& (C::*p)() const = &C::time_bombs_activated; }
	{ ::Protobuf::Stats_Traps_TimeBombsActivated* (C::*p)() = &C::release_time_bombs_activated; }
	{ ::Protobuf::Stats_Traps_TimeBombsActivated* (C::*p)() = &C::mutable_time_bombs_activated; }
	{ void (C::*p)(::Protobuf::Stats_Traps_TimeBombsActivated* time_bombs_activated) = &C::set_allocated_time_bombs_activated; }
}
#undef C

#define C Protobuf::Stats_Machines_MachinesDisabled
struct OpPb_A_Stats_Machines_MachinesDisabled { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Machines_MachinesDisabled); };
template struct OpPb_Rob<OpPb_A_Stats_Machines_MachinesDisabled, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Machines_MachinesDisabled { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Machines_MachinesDisabled); };
template struct OpPb_Rob<OpPb_M_Stats_Machines_MachinesDisabled, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Machines_MachinesDisabled()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Machines_MachinesDisabled()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Machines_MachinesDisabled()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_max_in_single_turn; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::max_in_single_turn; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_max_in_single_turn; }
	{ void (C::*p)() = &C::clear_garrison_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_access; }
	{ void (C::*p)() = &C::clear_garrison_relay; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_relay; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_relay; }
	{ void (C::*p)() = &C::clear_phase_generator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::phase_generator; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_phase_generator; }
	{ void (C::*p)() = &C::clear_network_hub; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::network_hub; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_network_hub; }
	{ void (C::*p)() = &C::clear_energy_cycler; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_cycler; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_cycler; }
}
#undef C

#define C Protobuf::Stats_Machines
struct OpPb_A_Stats_Machines { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Machines); };
template struct OpPb_Rob<OpPb_A_Stats_Machines, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Machines { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Machines); };
template struct OpPb_Rob<OpPb_M_Stats_Machines, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Machines()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Machines()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Machines()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_machines_disabled; }
	{ void (C::*p)() = &C::clear_machines_disabled; }
	{ const ::Protobuf::Stats_Machines_MachinesDisabled& (C::*p)() const = &C::machines_disabled; }
	{ ::Protobuf::Stats_Machines_MachinesDisabled* (C::*p)() = &C::release_machines_disabled; }
	{ ::Protobuf::Stats_Machines_MachinesDisabled* (C::*p)() = &C::mutable_machines_disabled; }
	{ void (C::*p)(::Protobuf::Stats_Machines_MachinesDisabled* machines_disabled) = &C::set_allocated_machines_disabled; }
	{ void (C::*p)() = &C::clear_machines_repaired; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machines_repaired; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machines_repaired; }
	{ void (C::*p)() = &C::clear_machines_dismantled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machines_dismantled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machines_dismantled; }
	{ void (C::*p)() = &C::clear_machines_sabotaged; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machines_sabotaged; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machines_sabotaged; }
	{ void (C::*p)() = &C::clear_garrisons_compromised; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrisons_compromised; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrisons_compromised; }
	{ void (C::*p)() = &C::clear_overloaded_fab_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overloaded_fab_kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overloaded_fab_kills; }
	{ void (C::*p)() = &C::clear_fab_network_shutdowns; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fab_network_shutdowns; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fab_network_shutdowns; }
}
#undef C

#define C Protobuf::Stats_Hacking_MachinesAccessed
struct OpPb_A_Stats_Hacking_MachinesAccessed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_MachinesAccessed); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_MachinesAccessed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_MachinesAccessed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_MachinesAccessed); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_MachinesAccessed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_MachinesAccessed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_MachinesAccessed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_MachinesAccessed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_terminals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terminals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terminals; }
	{ void (C::*p)() = &C::clear_fabricators; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabricators; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabricators; }
	{ void (C::*p)() = &C::clear_repair_stations; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::repair_stations; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_repair_stations; }
	{ void (C::*p)() = &C::clear_recycling_units; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycling_units; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycling_units; }
	{ void (C::*p)() = &C::clear_scanalyzers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scanalyzers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scanalyzers; }
	{ void (C::*p)() = &C::clear_garrison_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_access; }
}
#undef C

#define C Protobuf::Stats_Hacking_TotalHacks_Failed
struct OpPb_A_Stats_Hacking_TotalHacks_Failed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_TotalHacks_Failed); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_TotalHacks_Failed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_TotalHacks_Failed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_TotalHacks_Failed); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_TotalHacks_Failed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_TotalHacks_Failed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_TotalHacks_Failed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_TotalHacks_Failed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_catastrophic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::catastrophic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_catastrophic; }
}
#undef C

#define C Protobuf::Stats_Hacking_TotalHacks
struct OpPb_A_Stats_Hacking_TotalHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_TotalHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_TotalHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_TotalHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_TotalHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_TotalHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_TotalHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_TotalHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_TotalHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_successful; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::successful; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_successful; }
	{ bool (C::*p)() const = &C::has_failed; }
	{ void (C::*p)() = &C::clear_failed; }
	{ const ::Protobuf::Stats_Hacking_TotalHacks_Failed& (C::*p)() const = &C::failed; }
	{ ::Protobuf::Stats_Hacking_TotalHacks_Failed* (C::*p)() = &C::release_failed; }
	{ ::Protobuf::Stats_Hacking_TotalHacks_Failed* (C::*p)() = &C::mutable_failed; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_TotalHacks_Failed* failed) = &C::set_allocated_failed; }
	{ void (C::*p)() = &C::clear_database_lockouts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::database_lockouts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_database_lockouts; }
	{ void (C::*p)() = &C::clear_manual; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::manual; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_manual; }
	{ void (C::*p)() = &C::clear_terminals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terminals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terminals; }
	{ void (C::*p)() = &C::clear_fabricators; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabricators; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabricators; }
	{ void (C::*p)() = &C::clear_repair_stations; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::repair_stations; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_repair_stations; }
	{ void (C::*p)() = &C::clear_recycling_units; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycling_units; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycling_units; }
	{ void (C::*p)() = &C::clear_scanalyzers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scanalyzers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scanalyzers; }
	{ void (C::*p)() = &C::clear_garrison_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_access; }
}
#undef C

#define C Protobuf::Stats_Hacking_TerminalHacks
struct OpPb_A_Stats_Hacking_TerminalHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_TerminalHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_TerminalHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_TerminalHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_TerminalHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_TerminalHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_TerminalHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_TerminalHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_TerminalHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_record; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::record; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_record; }
	{ void (C::*p)() = &C::clear_part_schematic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::part_schematic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_part_schematic; }
	{ void (C::*p)() = &C::clear_robot_schematic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_schematic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_schematic; }
	{ void (C::*p)() = &C::clear_robot_analysis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_analysis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_analysis; }
	{ void (C::*p)() = &C::clear_prototype_id_bank; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prototype_id_bank; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prototype_id_bank; }
	{ void (C::*p)() = &C::clear_open_door; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::open_door; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_open_door; }
	{ void (C::*p)() = &C::clear_open_dsf; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::open_dsf; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_open_dsf; }
	{ void (C::*p)() = &C::clear_level_access_points; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::level_access_points; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_level_access_points; }
	{ void (C::*p)() = &C::clear_branch_access_points; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::branch_access_points; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_branch_access_points; }
	{ void (C::*p)() = &C::clear_emergency_access_points; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::emergency_access_points; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_emergency_access_points; }
	{ void (C::*p)() = &C::clear_machine_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machine_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machine_index; }
	{ void (C::*p)() = &C::clear_terminal_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terminal_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terminal_index; }
	{ void (C::*p)() = &C::clear_fabricator_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabricator_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabricator_index; }
	{ void (C::*p)() = &C::clear_repair_station_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::repair_station_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_repair_station_index; }
	{ void (C::*p)() = &C::clear_recycling_unit_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycling_unit_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycling_unit_index; }
	{ void (C::*p)() = &C::clear_scanalyzer_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scanalyzer_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scanalyzer_index; }
	{ void (C::*p)() = &C::clear_garrison_index; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_index; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_index; }
	{ void (C::*p)() = &C::clear_alert_level; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::alert_level; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_alert_level; }
	{ void (C::*p)() = &C::clear_unreport_threat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unreport_threat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unreport_threat; }
	{ void (C::*p)() = &C::clear_locate_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::locate_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_locate_traps; }
	{ void (C::*p)() = &C::clear_disarm_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disarm_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disarm_traps; }
	{ void (C::*p)() = &C::clear_reprogram_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reprogram_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reprogram_traps; }
	{ void (C::*p)() = &C::clear_dispatch_records; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::dispatch_records; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_dispatch_records; }
	{ void (C::*p)() = &C::clear_maintenance_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::maintenance_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_maintenance_status; }
	{ void (C::*p)() = &C::clear_security_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::security_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_security_status; }
	{ void (C::*p)() = &C::clear_surveillance_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::surveillance_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_surveillance_status; }
	{ void (C::*p)() = &C::clear_patrol_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::patrol_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_patrol_status; }
	{ void (C::*p)() = &C::clear_transport_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::transport_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_transport_status; }
	{ void (C::*p)() = &C::clear_investigation_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::investigation_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_investigation_status; }
	{ void (C::*p)() = &C::clear_extermination_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::extermination_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_extermination_status; }
	{ void (C::*p)() = &C::clear_reinforcement_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reinforcement_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reinforcement_status; }
	{ void (C::*p)() = &C::clear_assault_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::assault_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_assault_status; }
	{ void (C::*p)() = &C::clear_garrison_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrison_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrison_status; }
	{ void (C::*p)() = &C::clear_intercept_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::intercept_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_intercept_status; }
	{ void (C::*p)() = &C::clear_coupling_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::coupling_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_coupling_status; }
	{ void (C::*p)() = &C::clear_recall_investigation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_investigation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_investigation; }
	{ void (C::*p)() = &C::clear_recall_extermination; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_extermination; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_extermination; }
	{ void (C::*p)() = &C::clear_recall_reinforcements; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_reinforcements; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_reinforcements; }
	{ void (C::*p)() = &C::clear_recall_assault; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_assault; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_assault; }
	{ void (C::*p)() = &C::clear_hauler_manifests; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hauler_manifests; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hauler_manifests; }
	{ void (C::*p)() = &C::clear_registered_components; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::registered_components; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_registered_components; }
	{ void (C::*p)() = &C::clear_registered_prototypes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::registered_prototypes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_registered_prototypes; }
	{ void (C::*p)() = &C::clear_zone_layout; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zone_layout; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zone_layout; }
	{ void (C::*p)() = &C::clear_download_registry; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::download_registry; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_download_registry; }
	{ void (C::*p)() = &C::clear_download_navigation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::download_navigation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_download_navigation; }
	{ void (C::*p)() = &C::clear_download_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::download_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_download_security; }
	{ void (C::*p)() = &C::clear_proto_id_catalog; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::proto_id_catalog; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_proto_id_catalog; }
	{ void (C::*p)() = &C::clear_protovariant_controls; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protovariant_controls; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protovariant_controls; }
	{ void (C::*p)() = &C::clear_activate_exoskeleton; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::activate_exoskeleton; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_activate_exoskeleton; }
	{ void (C::*p)() = &C::clear_disengage_seal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disengage_seal; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disengage_seal; }
	{ void (C::*p)() = &C::clear_release_object; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::release_object; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_release_object; }
	{ void (C::*p)() = &C::clear_gate_test_138_a; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gate_test_138_a; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gate_test_138_a; }
	{ void (C::*p)() = &C::clear_gate_test_138_b; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gate_test_138_b; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gate_test_138_b; }
	{ void (C::*p)() = &C::clear_gate_test_138_c; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gate_test_138_c; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gate_test_138_c; }
	{ void (C::*p)() = &C::clear_gate_test_138_end; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::gate_test_138_end; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_gate_test_138_end; }
}
#undef C

#define C Protobuf::Stats_Hacking_FabricatorHacks
struct OpPb_A_Stats_Hacking_FabricatorHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_FabricatorHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_FabricatorHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_FabricatorHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_FabricatorHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_FabricatorHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_FabricatorHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_FabricatorHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_FabricatorHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_network_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::network_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_network_status; }
	{ void (C::*p)() = &C::clear_load_schematic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::load_schematic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_load_schematic; }
	{ void (C::*p)() = &C::clear_build; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::build; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_build; }
}
#undef C

#define C Protobuf::Stats_Hacking_RepairStationHacks
struct OpPb_A_Stats_Hacking_RepairStationHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_RepairStationHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_RepairStationHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_RepairStationHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_RepairStationHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_RepairStationHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_RepairStationHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_RepairStationHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_RepairStationHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_scan_component; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scan_component; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scan_component; }
	{ void (C::*p)() = &C::clear_repair; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::repair; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_repair; }
	{ void (C::*p)() = &C::clear_refit; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::refit; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_refit; }
}
#undef C

#define C Protobuf::Stats_Hacking_RecyclingUnitHacks
struct OpPb_A_Stats_Hacking_RecyclingUnitHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_RecyclingUnitHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_RecyclingUnitHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_RecyclingUnitHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_RecyclingUnitHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_RecyclingUnitHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_RecyclingUnitHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_RecyclingUnitHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_RecyclingUnitHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_recycle_component; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycle_component; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycle_component; }
	{ void (C::*p)() = &C::clear_process; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::process; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_process; }
	{ void (C::*p)() = &C::clear_report_inventory; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::report_inventory; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_report_inventory; }
	{ void (C::*p)() = &C::clear_retrieve_matter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieve_matter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieve_matter; }
	{ void (C::*p)() = &C::clear_retrieve_components; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieve_components; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieve_components; }
}
#undef C

#define C Protobuf::Stats_Hacking_Scanalyzer
struct OpPb_A_Stats_Hacking_Scanalyzer { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_Scanalyzer); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_Scanalyzer, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_Scanalyzer { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_Scanalyzer); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_Scanalyzer, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_Scanalyzer()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_Scanalyzer()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_Scanalyzer()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_insert_component; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::insert_component; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_insert_component; }
	{ void (C::*p)() = &C::clear_analyze; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::analyze; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_analyze; }
	{ void (C::*p)() = &C::clear_retrieve_study; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieve_study; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieve_study; }
}
#undef C

#define C Protobuf::Stats_Hacking_GarrisonAccessHacks
struct OpPb_A_Stats_Hacking_GarrisonAccessHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_GarrisonAccessHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_GarrisonAccessHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_GarrisonAccessHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_GarrisonAccessHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_GarrisonAccessHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_GarrisonAccessHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_GarrisonAccessHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_GarrisonAccessHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_unlock_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unlock_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unlock_access; }
	{ void (C::*p)() = &C::clear_seal_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::seal_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_seal_access; }
	{ void (C::*p)() = &C::clear_coupler_status; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::coupler_status; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_coupler_status; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_Terminals
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_Terminals { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Terminals); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_Terminals, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_Terminals { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Terminals); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_Terminals, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_Terminals()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Terminals()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Terminals()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_track; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::track; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_track; }
	{ void (C::*p)() = &C::clear_assimilate; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::assimilate; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_assimilate; }
	{ void (C::*p)() = &C::clear_botnet; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::botnet; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_botnet; }
	{ void (C::*p)() = &C::clear_detonate; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::detonate; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_detonate; }
	{ void (C::*p)() = &C::clear_disrupt; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disrupt; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disrupt; }
	{ void (C::*p)() = &C::clear_operators; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::operators; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_operators; }
	{ void (C::*p)() = &C::clear_skim; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::skim; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_skim; }
	{ void (C::*p)() = &C::clear_sabotage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sabotage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sabotage; }
	{ void (C::*p)() = &C::clear_search; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::search; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_search; }
	{ void (C::*p)() = &C::clear_override; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::override; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_override; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_Fabricators
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_Fabricators { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Fabricators); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_Fabricators, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_Fabricators { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Fabricators); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_Fabricators, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_Fabricators()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Fabricators()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Fabricators()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_report; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::report; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_report; }
	{ void (C::*p)() = &C::clear_prioritize; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prioritize; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prioritize; }
	{ void (C::*p)() = &C::clear_liberate; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::liberate; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_liberate; }
	{ void (C::*p)() = &C::clear_fabnet; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabnet; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabnet; }
	{ void (C::*p)() = &C::clear_haulers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::haulers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_haulers; }
	{ void (C::*p)() = &C::clear_overload; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overload; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overload; }
	{ void (C::*p)() = &C::clear_download; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::download; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_download; }
	{ void (C::*p)() = &C::clear_recompile; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recompile; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recompile; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_RepairStations
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_RepairStations { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_RepairStations); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_RepairStations, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_RepairStations { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_RepairStations); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_RepairStations, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_RepairStations()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_RepairStations()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_RepairStations()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_mechanics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mechanics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mechanics; }
	{ void (C::*p)() = &C::clear_patch; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::patch; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_patch; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_RecyclingUnits
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_RecyclingUnits { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_RecyclingUnits); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_RecyclingUnits, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_RecyclingUnits { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_RecyclingUnits); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_RecyclingUnits, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_RecyclingUnits()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_RecyclingUnits()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_RecyclingUnits()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_monitor; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::monitor; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_monitor; }
	{ void (C::*p)() = &C::clear_reject; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reject; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reject; }
	{ void (C::*p)() = &C::clear_recyclers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recyclers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recyclers; }
	{ void (C::*p)() = &C::clear_mask; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mask; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mask; }
	{ void (C::*p)() = &C::clear_tunnel; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tunnel; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tunnel; }
	{ void (C::*p)() = &C::clear_fedlink; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fedlink; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fedlink; }
	{ void (C::*p)() = &C::clear_scrapoids; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scrapoids; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scrapoids; }
	{ void (C::*p)() = &C::clear_scraphulk; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scraphulk; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scraphulk; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_Scanalyzers
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_Scanalyzers { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Scanalyzers); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_Scanalyzers, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_Scanalyzers { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Scanalyzers); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_Scanalyzers, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_Scanalyzers()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_Scanalyzers()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_Scanalyzers()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_researchers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::researchers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_researchers; }
	{ void (C::*p)() = &C::clear_extract; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::extract; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_extract; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks_GarrisonAccess
struct OpPb_A_Stats_Hacking_UnauthorizedHacks_GarrisonAccess { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_GarrisonAccess); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks_GarrisonAccess, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks_GarrisonAccess { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_GarrisonAccess); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks_GarrisonAccess, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks_GarrisonAccess()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks_GarrisonAccess()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks_GarrisonAccess()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_broadcast; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::broadcast; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_broadcast; }
	{ void (C::*p)() = &C::clear_restock; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::restock; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_restock; }
	{ void (C::*p)() = &C::clear_decoy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decoy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_decoy; }
	{ void (C::*p)() = &C::clear_redirect; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::redirect; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_redirect; }
	{ void (C::*p)() = &C::clear_reprogram; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reprogram; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reprogram; }
	{ void (C::*p)() = &C::clear_intercept; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::intercept; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_intercept; }
	{ void (C::*p)() = &C::clear_watchers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::watchers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_watchers; }
	{ void (C::*p)() = &C::clear_jam; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::jam; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_jam; }
	{ void (C::*p)() = &C::clear_eject; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::eject; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_eject; }
}
#undef C

#define C Protobuf::Stats_Hacking_UnauthorizedHacks
struct OpPb_A_Stats_Hacking_UnauthorizedHacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_UnauthorizedHacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_UnauthorizedHacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_UnauthorizedHacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_UnauthorizedHacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_UnauthorizedHacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_UnauthorizedHacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_terminals; }
	{ void (C::*p)() = &C::clear_terminals; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_Terminals& (C::*p)() const = &C::terminals; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Terminals* (C::*p)() = &C::release_terminals; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Terminals* (C::*p)() = &C::mutable_terminals; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_Terminals* terminals) = &C::set_allocated_terminals; }
	{ bool (C::*p)() const = &C::has_fabricators; }
	{ void (C::*p)() = &C::clear_fabricators; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_Fabricators& (C::*p)() const = &C::fabricators; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Fabricators* (C::*p)() = &C::release_fabricators; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Fabricators* (C::*p)() = &C::mutable_fabricators; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_Fabricators* fabricators) = &C::set_allocated_fabricators; }
	{ bool (C::*p)() const = &C::has_repair_stations; }
	{ void (C::*p)() = &C::clear_repair_stations; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_RepairStations& (C::*p)() const = &C::repair_stations; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_RepairStations* (C::*p)() = &C::release_repair_stations; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_RepairStations* (C::*p)() = &C::mutable_repair_stations; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_RepairStations* repair_stations) = &C::set_allocated_repair_stations; }
	{ bool (C::*p)() const = &C::has_recycling_units; }
	{ void (C::*p)() = &C::clear_recycling_units; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_RecyclingUnits& (C::*p)() const = &C::recycling_units; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_RecyclingUnits* (C::*p)() = &C::release_recycling_units; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_RecyclingUnits* (C::*p)() = &C::mutable_recycling_units; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_RecyclingUnits* recycling_units) = &C::set_allocated_recycling_units; }
	{ bool (C::*p)() const = &C::has_scanalyzers; }
	{ void (C::*p)() = &C::clear_scanalyzers; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_Scanalyzers& (C::*p)() const = &C::scanalyzers; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Scanalyzers* (C::*p)() = &C::release_scanalyzers; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_Scanalyzers* (C::*p)() = &C::mutable_scanalyzers; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_Scanalyzers* scanalyzers) = &C::set_allocated_scanalyzers; }
	{ bool (C::*p)() const = &C::has_garrison_access; }
	{ void (C::*p)() = &C::clear_garrison_access; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks_GarrisonAccess& (C::*p)() const = &C::garrison_access; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_GarrisonAccess* (C::*p)() = &C::release_garrison_access; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks_GarrisonAccess* (C::*p)() = &C::mutable_garrison_access; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks_GarrisonAccess* garrison_access) = &C::set_allocated_garrison_access; }
}
#undef C

#define C Protobuf::Stats_Hacking_DataCoresRecovered
struct OpPb_A_Stats_Hacking_DataCoresRecovered { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_DataCoresRecovered); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_DataCoresRecovered, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_DataCoresRecovered { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_DataCoresRecovered); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_DataCoresRecovered, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_DataCoresRecovered()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_DataCoresRecovered()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_DataCoresRecovered()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_used; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used; }
}
#undef C

#define C Protobuf::Stats_Hacking_HackingDetections_FeedbackEvents
struct OpPb_A_Stats_Hacking_HackingDetections_FeedbackEvents { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_HackingDetections_FeedbackEvents); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_HackingDetections_FeedbackEvents, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_HackingDetections_FeedbackEvents { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_HackingDetections_FeedbackEvents); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_HackingDetections_FeedbackEvents, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_HackingDetections_FeedbackEvents()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_HackingDetections_FeedbackEvents()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_HackingDetections_FeedbackEvents()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_corruption; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::corruption; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_corruption; }
	{ void (C::*p)() = &C::clear_hackware_fried; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hackware_fried; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hackware_fried; }
}
#undef C

#define C Protobuf::Stats_Hacking_HackingDetections
struct OpPb_A_Stats_Hacking_HackingDetections { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_HackingDetections); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_HackingDetections, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_HackingDetections { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_HackingDetections); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_HackingDetections, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_HackingDetections()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_HackingDetections()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_HackingDetections()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_full_trace_events; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::full_trace_events; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_full_trace_events; }
	{ bool (C::*p)() const = &C::has_feedback_events; }
	{ void (C::*p)() = &C::clear_feedback_events; }
	{ const ::Protobuf::Stats_Hacking_HackingDetections_FeedbackEvents& (C::*p)() const = &C::feedback_events; }
	{ ::Protobuf::Stats_Hacking_HackingDetections_FeedbackEvents* (C::*p)() = &C::release_feedback_events; }
	{ ::Protobuf::Stats_Hacking_HackingDetections_FeedbackEvents* (C::*p)() = &C::mutable_feedback_events; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_HackingDetections_FeedbackEvents* feedback_events) = &C::set_allocated_feedback_events; }
	{ void (C::*p)() = &C::clear_feedback_blocked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::feedback_blocked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_feedback_blocked; }
}
#undef C

#define C Protobuf::Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt
struct OpPb_A_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_authchips; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::authchips; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_authchips; }
	{ void (C::*p)() = &C::clear_time; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::time; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_time; }
}
#undef C

#define C Protobuf::Stats_Hacking_RobotSchematicsAcquired
struct OpPb_A_Stats_Hacking_RobotSchematicsAcquired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_RobotSchematicsAcquired); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_RobotSchematicsAcquired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_RobotSchematicsAcquired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_RobotSchematicsAcquired); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_RobotSchematicsAcquired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_RobotSchematicsAcquired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_RobotSchematicsAcquired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_RobotSchematicsAcquired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_robots_built; }
	{ void (C::*p)() = &C::clear_robots_built; }
	{ const ::Protobuf::Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt& (C::*p)() const = &C::robots_built; }
	{ ::Protobuf::Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt* (C::*p)() = &C::release_robots_built; }
	{ ::Protobuf::Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt* (C::*p)() = &C::mutable_robots_built; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_RobotSchematicsAcquired_RobotsBuilt* robots_built) = &C::set_allocated_robots_built; }
	{ void (C::*p)() = &C::clear_total_robot_build_rating; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_robot_build_rating; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_robot_build_rating; }
}
#undef C

#define C Protobuf::Stats_Hacking_PartSchematicsAcquired_PartsBuilt
struct OpPb_A_Stats_Hacking_PartSchematicsAcquired_PartsBuilt { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_PartSchematicsAcquired_PartsBuilt); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_PartSchematicsAcquired_PartsBuilt, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_PartSchematicsAcquired_PartsBuilt { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_PartSchematicsAcquired_PartsBuilt); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_PartSchematicsAcquired_PartsBuilt, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_PartSchematicsAcquired_PartsBuilt()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_PartSchematicsAcquired_PartsBuilt()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_PartSchematicsAcquired_PartsBuilt()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_authchips; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::authchips; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_authchips; }
	{ void (C::*p)() = &C::clear_time; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::time; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_time; }
}
#undef C

#define C Protobuf::Stats_Hacking_PartSchematicsAcquired
struct OpPb_A_Stats_Hacking_PartSchematicsAcquired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_PartSchematicsAcquired); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_PartSchematicsAcquired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_PartSchematicsAcquired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_PartSchematicsAcquired); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_PartSchematicsAcquired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_PartSchematicsAcquired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_PartSchematicsAcquired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_PartSchematicsAcquired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_parts_built; }
	{ void (C::*p)() = &C::clear_parts_built; }
	{ const ::Protobuf::Stats_Hacking_PartSchematicsAcquired_PartsBuilt& (C::*p)() const = &C::parts_built; }
	{ ::Protobuf::Stats_Hacking_PartSchematicsAcquired_PartsBuilt* (C::*p)() = &C::release_parts_built; }
	{ ::Protobuf::Stats_Hacking_PartSchematicsAcquired_PartsBuilt* (C::*p)() = &C::mutable_parts_built; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_PartSchematicsAcquired_PartsBuilt* parts_built) = &C::set_allocated_parts_built; }
	{ void (C::*p)() = &C::clear_total_part_build_rating; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_part_build_rating; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_part_build_rating; }
}
#undef C

#define C Protobuf::Stats_Hacking_PartsRepaired
struct OpPb_A_Stats_Hacking_PartsRepaired { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_PartsRepaired); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_PartsRepaired, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_PartsRepaired { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_PartsRepaired); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_PartsRepaired, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_PartsRepaired()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_PartsRepaired()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_PartsRepaired()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_time; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::time; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_time; }
}
#undef C

#define C Protobuf::Stats_Hacking_PartsRecycled
struct OpPb_A_Stats_Hacking_PartsRecycled { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_PartsRecycled); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_PartsRecycled, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_PartsRecycled { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_PartsRecycled); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_PartsRecycled, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_PartsRecycled()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_PartsRecycled()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_PartsRecycled()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_recycled_matter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recycled_matter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recycled_matter; }
	{ void (C::*p)() = &C::clear_retrieved_matter; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieved_matter; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieved_matter; }
	{ void (C::*p)() = &C::clear_retrieved_components; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieved_components; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieved_components; }
}
#undef C

#define C Protobuf::Stats_Hacking_PartsScanalyzed
struct OpPb_A_Stats_Hacking_PartsScanalyzed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking_PartsScanalyzed); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking_PartsScanalyzed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking_PartsScanalyzed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking_PartsScanalyzed); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking_PartsScanalyzed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking_PartsScanalyzed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking_PartsScanalyzed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking_PartsScanalyzed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_part_schematics_acquired; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::part_schematics_acquired; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_part_schematics_acquired; }
	{ void (C::*p)() = &C::clear_parts_damaged; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_damaged; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_damaged; }
}
#undef C

#define C Protobuf::Stats_Hacking
struct OpPb_A_Stats_Hacking { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Hacking); };
template struct OpPb_Rob<OpPb_A_Stats_Hacking, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Hacking { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Hacking); };
template struct OpPb_Rob<OpPb_M_Stats_Hacking, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Hacking()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Hacking()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Hacking()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_machines_accessed; }
	{ void (C::*p)() = &C::clear_machines_accessed; }
	{ const ::Protobuf::Stats_Hacking_MachinesAccessed& (C::*p)() const = &C::machines_accessed; }
	{ ::Protobuf::Stats_Hacking_MachinesAccessed* (C::*p)() = &C::release_machines_accessed; }
	{ ::Protobuf::Stats_Hacking_MachinesAccessed* (C::*p)() = &C::mutable_machines_accessed; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_MachinesAccessed* machines_accessed) = &C::set_allocated_machines_accessed; }
	{ bool (C::*p)() const = &C::has_total_hacks; }
	{ void (C::*p)() = &C::clear_total_hacks; }
	{ const ::Protobuf::Stats_Hacking_TotalHacks& (C::*p)() const = &C::total_hacks; }
	{ ::Protobuf::Stats_Hacking_TotalHacks* (C::*p)() = &C::release_total_hacks; }
	{ ::Protobuf::Stats_Hacking_TotalHacks* (C::*p)() = &C::mutable_total_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_TotalHacks* total_hacks) = &C::set_allocated_total_hacks; }
	{ bool (C::*p)() const = &C::has_terminal_hacks; }
	{ void (C::*p)() = &C::clear_terminal_hacks; }
	{ const ::Protobuf::Stats_Hacking_TerminalHacks& (C::*p)() const = &C::terminal_hacks; }
	{ ::Protobuf::Stats_Hacking_TerminalHacks* (C::*p)() = &C::release_terminal_hacks; }
	{ ::Protobuf::Stats_Hacking_TerminalHacks* (C::*p)() = &C::mutable_terminal_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_TerminalHacks* terminal_hacks) = &C::set_allocated_terminal_hacks; }
	{ bool (C::*p)() const = &C::has_fabricator_hacks; }
	{ void (C::*p)() = &C::clear_fabricator_hacks; }
	{ const ::Protobuf::Stats_Hacking_FabricatorHacks& (C::*p)() const = &C::fabricator_hacks; }
	{ ::Protobuf::Stats_Hacking_FabricatorHacks* (C::*p)() = &C::release_fabricator_hacks; }
	{ ::Protobuf::Stats_Hacking_FabricatorHacks* (C::*p)() = &C::mutable_fabricator_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_FabricatorHacks* fabricator_hacks) = &C::set_allocated_fabricator_hacks; }
	{ bool (C::*p)() const = &C::has_repair_station_hacks; }
	{ void (C::*p)() = &C::clear_repair_station_hacks; }
	{ const ::Protobuf::Stats_Hacking_RepairStationHacks& (C::*p)() const = &C::repair_station_hacks; }
	{ ::Protobuf::Stats_Hacking_RepairStationHacks* (C::*p)() = &C::release_repair_station_hacks; }
	{ ::Protobuf::Stats_Hacking_RepairStationHacks* (C::*p)() = &C::mutable_repair_station_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_RepairStationHacks* repair_station_hacks) = &C::set_allocated_repair_station_hacks; }
	{ bool (C::*p)() const = &C::has_recycling_unit_hacks; }
	{ void (C::*p)() = &C::clear_recycling_unit_hacks; }
	{ const ::Protobuf::Stats_Hacking_RecyclingUnitHacks& (C::*p)() const = &C::recycling_unit_hacks; }
	{ ::Protobuf::Stats_Hacking_RecyclingUnitHacks* (C::*p)() = &C::release_recycling_unit_hacks; }
	{ ::Protobuf::Stats_Hacking_RecyclingUnitHacks* (C::*p)() = &C::mutable_recycling_unit_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_RecyclingUnitHacks* recycling_unit_hacks) = &C::set_allocated_recycling_unit_hacks; }
	{ bool (C::*p)() const = &C::has_scanalyzer; }
	{ void (C::*p)() = &C::clear_scanalyzer; }
	{ const ::Protobuf::Stats_Hacking_Scanalyzer& (C::*p)() const = &C::scanalyzer; }
	{ ::Protobuf::Stats_Hacking_Scanalyzer* (C::*p)() = &C::release_scanalyzer; }
	{ ::Protobuf::Stats_Hacking_Scanalyzer* (C::*p)() = &C::mutable_scanalyzer; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_Scanalyzer* scanalyzer) = &C::set_allocated_scanalyzer; }
	{ bool (C::*p)() const = &C::has_garrison_access_hacks; }
	{ void (C::*p)() = &C::clear_garrison_access_hacks; }
	{ const ::Protobuf::Stats_Hacking_GarrisonAccessHacks& (C::*p)() const = &C::garrison_access_hacks; }
	{ ::Protobuf::Stats_Hacking_GarrisonAccessHacks* (C::*p)() = &C::release_garrison_access_hacks; }
	{ ::Protobuf::Stats_Hacking_GarrisonAccessHacks* (C::*p)() = &C::mutable_garrison_access_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_GarrisonAccessHacks* garrison_access_hacks) = &C::set_allocated_garrison_access_hacks; }
	{ bool (C::*p)() const = &C::has_unauthorized_hacks; }
	{ void (C::*p)() = &C::clear_unauthorized_hacks; }
	{ const ::Protobuf::Stats_Hacking_UnauthorizedHacks& (C::*p)() const = &C::unauthorized_hacks; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks* (C::*p)() = &C::release_unauthorized_hacks; }
	{ ::Protobuf::Stats_Hacking_UnauthorizedHacks* (C::*p)() = &C::mutable_unauthorized_hacks; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_UnauthorizedHacks* unauthorized_hacks) = &C::set_allocated_unauthorized_hacks; }
	{ bool (C::*p)() const = &C::has_data_cores_recovered; }
	{ void (C::*p)() = &C::clear_data_cores_recovered; }
	{ const ::Protobuf::Stats_Hacking_DataCoresRecovered& (C::*p)() const = &C::data_cores_recovered; }
	{ ::Protobuf::Stats_Hacking_DataCoresRecovered* (C::*p)() = &C::release_data_cores_recovered; }
	{ ::Protobuf::Stats_Hacking_DataCoresRecovered* (C::*p)() = &C::mutable_data_cores_recovered; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_DataCoresRecovered* data_cores_recovered) = &C::set_allocated_data_cores_recovered; }
	{ bool (C::*p)() const = &C::has_hacking_detections; }
	{ void (C::*p)() = &C::clear_hacking_detections; }
	{ const ::Protobuf::Stats_Hacking_HackingDetections& (C::*p)() const = &C::hacking_detections; }
	{ ::Protobuf::Stats_Hacking_HackingDetections* (C::*p)() = &C::release_hacking_detections; }
	{ ::Protobuf::Stats_Hacking_HackingDetections* (C::*p)() = &C::mutable_hacking_detections; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_HackingDetections* hacking_detections) = &C::set_allocated_hacking_detections; }
	{ bool (C::*p)() const = &C::has_robot_schematics_acquired; }
	{ void (C::*p)() = &C::clear_robot_schematics_acquired; }
	{ const ::Protobuf::Stats_Hacking_RobotSchematicsAcquired& (C::*p)() const = &C::robot_schematics_acquired; }
	{ ::Protobuf::Stats_Hacking_RobotSchematicsAcquired* (C::*p)() = &C::release_robot_schematics_acquired; }
	{ ::Protobuf::Stats_Hacking_RobotSchematicsAcquired* (C::*p)() = &C::mutable_robot_schematics_acquired; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_RobotSchematicsAcquired* robot_schematics_acquired) = &C::set_allocated_robot_schematics_acquired; }
	{ bool (C::*p)() const = &C::has_part_schematics_acquired; }
	{ void (C::*p)() = &C::clear_part_schematics_acquired; }
	{ const ::Protobuf::Stats_Hacking_PartSchematicsAcquired& (C::*p)() const = &C::part_schematics_acquired; }
	{ ::Protobuf::Stats_Hacking_PartSchematicsAcquired* (C::*p)() = &C::release_part_schematics_acquired; }
	{ ::Protobuf::Stats_Hacking_PartSchematicsAcquired* (C::*p)() = &C::mutable_part_schematics_acquired; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_PartSchematicsAcquired* part_schematics_acquired) = &C::set_allocated_part_schematics_acquired; }
	{ void (C::*p)() = &C::clear_part_studies_acquired; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::part_studies_acquired; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_part_studies_acquired; }
	{ bool (C::*p)() const = &C::has_parts_repaired; }
	{ void (C::*p)() = &C::clear_parts_repaired; }
	{ const ::Protobuf::Stats_Hacking_PartsRepaired& (C::*p)() const = &C::parts_repaired; }
	{ ::Protobuf::Stats_Hacking_PartsRepaired* (C::*p)() = &C::release_parts_repaired; }
	{ ::Protobuf::Stats_Hacking_PartsRepaired* (C::*p)() = &C::mutable_parts_repaired; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_PartsRepaired* parts_repaired) = &C::set_allocated_parts_repaired; }
	{ bool (C::*p)() const = &C::has_parts_recycled; }
	{ void (C::*p)() = &C::clear_parts_recycled; }
	{ const ::Protobuf::Stats_Hacking_PartsRecycled& (C::*p)() const = &C::parts_recycled; }
	{ ::Protobuf::Stats_Hacking_PartsRecycled* (C::*p)() = &C::release_parts_recycled; }
	{ ::Protobuf::Stats_Hacking_PartsRecycled* (C::*p)() = &C::mutable_parts_recycled; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_PartsRecycled* parts_recycled) = &C::set_allocated_parts_recycled; }
	{ bool (C::*p)() const = &C::has_parts_scanalyzed; }
	{ void (C::*p)() = &C::clear_parts_scanalyzed; }
	{ const ::Protobuf::Stats_Hacking_PartsScanalyzed& (C::*p)() const = &C::parts_scanalyzed; }
	{ ::Protobuf::Stats_Hacking_PartsScanalyzed* (C::*p)() = &C::release_parts_scanalyzed; }
	{ ::Protobuf::Stats_Hacking_PartsScanalyzed* (C::*p)() = &C::mutable_parts_scanalyzed; }
	{ void (C::*p)(::Protobuf::Stats_Hacking_PartsScanalyzed* parts_scanalyzed) = &C::set_allocated_parts_scanalyzed; }
}
#undef C

#define C Protobuf::Stats_Bothacking_UsedRifInstaller
struct OpPb_A_Stats_Bothacking_UsedRifInstaller { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking_UsedRifInstaller); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking_UsedRifInstaller, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking_UsedRifInstaller { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking_UsedRifInstaller); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking_UsedRifInstaller, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking_UsedRifInstaller()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking_UsedRifInstaller()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking_UsedRifInstaller()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_coupler_efficiency; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::coupler_efficiency; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_coupler_efficiency; }
	{ void (C::*p)() = &C::clear_hotswap; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hotswap; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hotswap; }
	{ void (C::*p)() = &C::clear_code_merge; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::code_merge; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_code_merge; }
	{ void (C::*p)() = &C::clear_command_fork; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::command_fork; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_command_fork; }
	{ void (C::*p)() = &C::clear_threat_obfuscation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::threat_obfuscation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_threat_obfuscation; }
	{ void (C::*p)() = &C::clear_signal_jamming; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::signal_jamming; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_signal_jamming; }
	{ void (C::*p)() = &C::clear_zone_cloak; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zone_cloak; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zone_cloak; }
	{ void (C::*p)() = &C::clear_robot_detection; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_detection; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_detection; }
	{ void (C::*p)() = &C::clear_watcher_feeds; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::watcher_feeds; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_watcher_feeds; }
	{ void (C::*p)() = &C::clear_patrol_navigation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::patrol_navigation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_patrol_navigation; }
	{ void (C::*p)() = &C::clear_alert_id_control; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::alert_id_control; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_alert_id_control; }
	{ void (C::*p)() = &C::clear_structural_interface; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::structural_interface; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_structural_interface; }
	{ void (C::*p)() = &C::clear_program_shield; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::program_shield; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_program_shield; }
	{ void (C::*p)() = &C::clear_autooverride; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autooverride; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autooverride; }
	{ void (C::*p)() = &C::clear_autoassimilate; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autoassimilate; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autoassimilate; }
	{ void (C::*p)() = &C::clear_crosswire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::crosswire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_crosswire; }
}
#undef C

#define C Protobuf::Stats_Bothacking_RobotsHacked
struct OpPb_A_Stats_Bothacking_RobotsHacked { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking_RobotsHacked); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking_RobotsHacked, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking_RobotsHacked { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking_RobotsHacked); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking_RobotsHacked, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking_RobotsHacked()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking_RobotsHacked()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking_RobotsHacked()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_non_combat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::non_combat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_non_combat; }
	{ void (C::*p)() = &C::clear_combat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat; }
	{ void (C::*p)() = &C::clear_autooverrided; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autooverrided; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autooverrided; }
	{ void (C::*p)() = &C::clear_autoassimilated; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autoassimilated; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autoassimilated; }
}
#undef C

#define C Protobuf::Stats_Bothacking_RobotHacksApplied
struct OpPb_A_Stats_Bothacking_RobotHacksApplied { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking_RobotHacksApplied); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking_RobotHacksApplied, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking_RobotHacksApplied { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking_RobotHacksApplied); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking_RobotHacksApplied, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking_RobotHacksApplied()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking_RobotHacksApplied()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking_RobotHacksApplied()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_parse_system; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parse_system; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parse_system; }
	{ void (C::*p)() = &C::clear_no_distress; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::no_distress; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_no_distress; }
	{ void (C::*p)() = &C::clear_generate_anomaly; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::generate_anomaly; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_generate_anomaly; }
	{ void (C::*p)() = &C::clear_generate_echo; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::generate_echo; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_generate_echo; }
	{ void (C::*p)() = &C::clear_start_evac; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::start_evac; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_start_evac; }
	{ void (C::*p)() = &C::clear_find_chute; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_chute; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_chute; }
	{ void (C::*p)() = &C::clear_deconstruct_machine; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::deconstruct_machine; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_deconstruct_machine; }
	{ void (C::*p)() = &C::clear_hold_bot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hold_bot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hold_bot; }
	{ void (C::*p)() = &C::clear_start_disposal; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::start_disposal; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_start_disposal; }
	{ void (C::*p)() = &C::clear_ignore_repairs; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ignore_repairs; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ignore_repairs; }
	{ void (C::*p)() = &C::clear_map_walls; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::map_walls; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_map_walls; }
	{ void (C::*p)() = &C::clear_randomize_corridors; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::randomize_corridors; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_randomize_corridors; }
	{ void (C::*p)() = &C::clear_map_earth; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::map_earth; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_map_earth; }
	{ void (C::*p)() = &C::clear_find_fabricator; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_fabricator; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_fabricator; }
	{ void (C::*p)() = &C::clear_find_dsf; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_dsf; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_dsf; }
	{ void (C::*p)() = &C::clear_drop_inventory; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::drop_inventory; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_drop_inventory; }
	{ void (C::*p)() = &C::clear_recall_reinforcements; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_reinforcements; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_reinforcements; }
	{ void (C::*p)() = &C::clear_locate_stockpiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::locate_stockpiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_locate_stockpiles; }
	{ void (C::*p)() = &C::clear_find_recycling; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_recycling; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_recycling; }
	{ void (C::*p)() = &C::clear_ignore_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ignore_parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ignore_parts; }
	{ void (C::*p)() = &C::clear_find_station; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_station; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_station; }
	{ void (C::*p)() = &C::clear_release_backups; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::release_backups; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_release_backups; }
	{ void (C::*p)() = &C::clear_deconstruct_bot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::deconstruct_bot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_deconstruct_bot; }
	{ void (C::*p)() = &C::clear_check_alert; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::check_alert; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_check_alert; }
	{ void (C::*p)() = &C::clear_purge_threat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::purge_threat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_purge_threat; }
	{ void (C::*p)() = &C::clear_find_terminals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_terminals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_terminals; }
	{ void (C::*p)() = &C::clear_locate_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::locate_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_locate_traps; }
	{ void (C::*p)() = &C::clear_disarm_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disarm_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disarm_traps; }
	{ void (C::*p)() = &C::clear_reprogram_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reprogram_traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reprogram_traps; }
	{ void (C::*p)() = &C::clear_block_reporting; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::block_reporting; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_block_reporting; }
	{ void (C::*p)() = &C::clear_summon_haulers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::summon_haulers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_summon_haulers; }
	{ void (C::*p)() = &C::clear_recall_investigation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recall_investigation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recall_investigation; }
	{ void (C::*p)() = &C::clear_clear_repairs; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::clear_repairs; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_clear_repairs; }
	{ void (C::*p)() = &C::clear_clear_recycling; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::clear_recycling; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_clear_recycling; }
	{ void (C::*p)() = &C::clear_map_route; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::map_route; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_map_route; }
	{ void (C::*p)() = &C::clear_mark_security; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mark_security; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mark_security; }
	{ void (C::*p)() = &C::clear_relay_feed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::relay_feed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_relay_feed; }
	{ void (C::*p)() = &C::clear_disable_shields; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disable_shields; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disable_shields; }
	{ void (C::*p)() = &C::clear_redirect_shields; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::redirect_shields; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_redirect_shields; }
	{ void (C::*p)() = &C::clear_find_scanalyzer; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_scanalyzer; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_scanalyzer; }
	{ void (C::*p)() = &C::clear_disable_scanner; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disable_scanner; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disable_scanner; }
	{ void (C::*p)() = &C::clear_locate_prototypes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::locate_prototypes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_locate_prototypes; }
	{ void (C::*p)() = &C::clear_report_prototypes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::report_prototypes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_report_prototypes; }
	{ void (C::*p)() = &C::clear_report_schematics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::report_schematics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_report_schematics; }
	{ void (C::*p)() = &C::clear_report_analyses; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::report_analyses; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_report_analyses; }
	{ void (C::*p)() = &C::clear_ignore_targets; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ignore_targets; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ignore_targets; }
	{ void (C::*p)() = &C::clear_emergency_deploy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::emergency_deploy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_emergency_deploy; }
	{ void (C::*p)() = &C::clear_find_shortcuts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_shortcuts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_shortcuts; }
	{ void (C::*p)() = &C::clear_find_garrison; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::find_garrison; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_find_garrison; }
	{ void (C::*p)() = &C::clear_show_paths; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::show_paths; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_show_paths; }
	{ void (C::*p)() = &C::clear_link_fov; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::link_fov; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_link_fov; }
	{ void (C::*p)() = &C::clear_focus_fire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::focus_fire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_focus_fire; }
	{ void (C::*p)() = &C::clear_reboot_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reboot_propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reboot_propulsion; }
	{ void (C::*p)() = &C::clear_tweak_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tweak_propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tweak_propulsion; }
	{ void (C::*p)() = &C::clear_scatter_targeting; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scatter_targeting; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scatter_targeting; }
	{ void (C::*p)() = &C::clear_mark_system; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mark_system; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mark_system; }
	{ void (C::*p)() = &C::clear_link_complan; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::link_complan; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_link_complan; }
	{ void (C::*p)() = &C::clear_broadcast_data; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::broadcast_data; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_broadcast_data; }
	{ void (C::*p)() = &C::clear_disrupt_area; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disrupt_area; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disrupt_area; }
	{ void (C::*p)() = &C::clear_spike_heat; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::spike_heat; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_spike_heat; }
	{ void (C::*p)() = &C::clear_overload_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overload_power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overload_power; }
	{ void (C::*p)() = &C::clear_amplify_resonance; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::amplify_resonance; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_amplify_resonance; }
	{ void (C::*p)() = &C::clear_wipe_record; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wipe_record; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wipe_record; }
	{ void (C::*p)() = &C::clear_disable_weapons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::disable_weapons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_disable_weapons; }
	{ void (C::*p)() = &C::clear_reboot_system; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reboot_system; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reboot_system; }
	{ void (C::*p)() = &C::clear_go_dormant; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::go_dormant; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_go_dormant; }
	{ void (C::*p)() = &C::clear_overwrite_iff; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overwrite_iff; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overwrite_iff; }
	{ void (C::*p)() = &C::clear_streamctrl_low; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::streamctrl_low; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_streamctrl_low; }
	{ void (C::*p)() = &C::clear_streamctrl_high; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::streamctrl_high; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_streamctrl_high; }
	{ void (C::*p)() = &C::clear_formatsys_low; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::formatsys_low; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_formatsys_low; }
	{ void (C::*p)() = &C::clear_formatsys_high; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::formatsys_high; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_formatsys_high; }
	{ void (C::*p)() = &C::clear_formatsys_deep; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::formatsys_deep; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_formatsys_deep; }
	{ void (C::*p)() = &C::clear_retrieve_part; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::retrieve_part; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_retrieve_part; }
	{ void (C::*p)() = &C::clear_manual; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::manual; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_manual; }
}
#undef C

#define C Protobuf::Stats_Bothacking_RelayCouplersReleased
struct OpPb_A_Stats_Bothacking_RelayCouplersReleased { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking_RelayCouplersReleased); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking_RelayCouplersReleased, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking_RelayCouplersReleased { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking_RelayCouplersReleased); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking_RelayCouplersReleased, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking_RelayCouplersReleased()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking_RelayCouplersReleased()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking_RelayCouplersReleased()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_ejected; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ejected; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ejected; }
	{ void (C::*p)() = &C::clear_machine_destruction; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machine_destruction; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machine_destruction; }
	{ void (C::*p)() = &C::clear_programmers; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::programmers; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_programmers; }
	{ void (C::*p)() = &C::clear_attached; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::attached; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_attached; }
	{ void (C::*p)() = &C::clear_crosswired; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::crosswired; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_crosswired; }
	{ void (C::*p)() = &C::clear_merged_code_value; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::merged_code_value; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_merged_code_value; }
}
#undef C

#define C Protobuf::Stats_Bothacking_FabnetPeakEffectivePercent
struct OpPb_A_Stats_Bothacking_FabnetPeakEffectivePercent { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking_FabnetPeakEffectivePercent); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking_FabnetPeakEffectivePercent, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking_FabnetPeakEffectivePercent { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking_FabnetPeakEffectivePercent); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking_FabnetPeakEffectivePercent, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking_FabnetPeakEffectivePercent()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking_FabnetPeakEffectivePercent()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking_FabnetPeakEffectivePercent()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_autooverrided; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::autooverrided; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_autooverrided; }
}
#undef C

#define C Protobuf::Stats_Bothacking
struct OpPb_A_Stats_Bothacking { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Bothacking); };
template struct OpPb_Rob<OpPb_A_Stats_Bothacking, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Bothacking { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Bothacking); };
template struct OpPb_Rob<OpPb_M_Stats_Bothacking, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Bothacking()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Bothacking()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Bothacking()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_used_rif_installer; }
	{ void (C::*p)() = &C::clear_used_rif_installer; }
	{ const ::Protobuf::Stats_Bothacking_UsedRifInstaller& (C::*p)() const = &C::used_rif_installer; }
	{ ::Protobuf::Stats_Bothacking_UsedRifInstaller* (C::*p)() = &C::release_used_rif_installer; }
	{ ::Protobuf::Stats_Bothacking_UsedRifInstaller* (C::*p)() = &C::mutable_used_rif_installer; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking_UsedRifInstaller* used_rif_installer) = &C::set_allocated_used_rif_installer; }
	{ bool (C::*p)() const = &C::has_robots_hacked; }
	{ void (C::*p)() = &C::clear_robots_hacked; }
	{ const ::Protobuf::Stats_Bothacking_RobotsHacked& (C::*p)() const = &C::robots_hacked; }
	{ ::Protobuf::Stats_Bothacking_RobotsHacked* (C::*p)() = &C::release_robots_hacked; }
	{ ::Protobuf::Stats_Bothacking_RobotsHacked* (C::*p)() = &C::mutable_robots_hacked; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking_RobotsHacked* robots_hacked) = &C::set_allocated_robots_hacked; }
	{ bool (C::*p)() const = &C::has_robot_hacks_applied; }
	{ void (C::*p)() = &C::clear_robot_hacks_applied; }
	{ const ::Protobuf::Stats_Bothacking_RobotHacksApplied& (C::*p)() const = &C::robot_hacks_applied; }
	{ ::Protobuf::Stats_Bothacking_RobotHacksApplied* (C::*p)() = &C::release_robot_hacks_applied; }
	{ ::Protobuf::Stats_Bothacking_RobotHacksApplied* (C::*p)() = &C::mutable_robot_hacks_applied; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking_RobotHacksApplied* robot_hacks_applied) = &C::set_allocated_robot_hacks_applied; }
	{ bool (C::*p)() const = &C::has_relay_couplers_released; }
	{ void (C::*p)() = &C::clear_relay_couplers_released; }
	{ const ::Protobuf::Stats_Bothacking_RelayCouplersReleased& (C::*p)() const = &C::relay_couplers_released; }
	{ ::Protobuf::Stats_Bothacking_RelayCouplersReleased* (C::*p)() = &C::release_relay_couplers_released; }
	{ ::Protobuf::Stats_Bothacking_RelayCouplersReleased* (C::*p)() = &C::mutable_relay_couplers_released; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking_RelayCouplersReleased* relay_couplers_released) = &C::set_allocated_relay_couplers_released; }
	{ bool (C::*p)() const = &C::has_fabnet_peak_effective_percent; }
	{ void (C::*p)() = &C::clear_fabnet_peak_effective_percent; }
	{ const ::Protobuf::Stats_Bothacking_FabnetPeakEffectivePercent& (C::*p)() const = &C::fabnet_peak_effective_percent; }
	{ ::Protobuf::Stats_Bothacking_FabnetPeakEffectivePercent* (C::*p)() = &C::release_fabnet_peak_effective_percent; }
	{ ::Protobuf::Stats_Bothacking_FabnetPeakEffectivePercent* (C::*p)() = &C::mutable_fabnet_peak_effective_percent; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking_FabnetPeakEffectivePercent* fabnet_peak_effective_percent) = &C::set_allocated_fabnet_peak_effective_percent; }
	{ void (C::*p)() = &C::clear_robots_rewired; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robots_rewired; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robots_rewired; }
	{ void (C::*p)() = &C::clear_allies_hacked; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::allies_hacked; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_allies_hacked; }
	{ void (C::*p)() = &C::clear_hacks_repelled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacks_repelled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacks_repelled; }
}
#undef C

#define C Protobuf::Stats_Allies_TotalAllies
struct OpPb_A_Stats_Allies_TotalAllies { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_TotalAllies); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_TotalAllies, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_TotalAllies { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_TotalAllies); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_TotalAllies, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_TotalAllies()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_TotalAllies()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_TotalAllies()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_largest_group; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::largest_group; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_largest_group; }
	{ void (C::*p)() = &C::clear_highest_rated_group; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::highest_rated_group; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_highest_rated_group; }
	{ void (C::*p)() = &C::clear_highest_rated_ally; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::highest_rated_ally; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_highest_rated_ally; }
}
#undef C

#define C Protobuf::Stats_Allies_ZioniteDispatches
struct OpPb_A_Stats_Allies_ZioniteDispatches { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_ZioniteDispatches); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_ZioniteDispatches, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_ZioniteDispatches { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_ZioniteDispatches); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_ZioniteDispatches, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_ZioniteDispatches()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_ZioniteDispatches()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_ZioniteDispatches()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_heavy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heavy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heavy; }
	{ void (C::*p)() = &C::clear_light; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::light; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_light; }
	{ void (C::*p)() = &C::clear_recon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::recon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_recon; }
	{ void (C::*p)() = &C::clear_fire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fire; }
	{ void (C::*p)() = &C::clear_hacker; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacker; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacker; }
	{ void (C::*p)() = &C::clear_demo; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::demo; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_demo; }
	{ void (C::*p)() = &C::clear_experimental; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::experimental; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_experimental; }
	{ void (C::*p)() = &C::clear_hero; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hero; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hero; }
	{ void (C::*p)() = &C::clear_thermal_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::thermal_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_thermal_resupply; }
	{ void (C::*p)() = &C::clear_kinetic_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kinetic_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kinetic_resupply; }
	{ void (C::*p)() = &C::clear_explosive_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explosive_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explosive_resupply; }
	{ void (C::*p)() = &C::clear_melee_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee_resupply; }
	{ void (C::*p)() = &C::clear_trap_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trap_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trap_resupply; }
	{ void (C::*p)() = &C::clear_resource_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::resource_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_resource_resupply; }
	{ void (C::*p)() = &C::clear_offense_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::offense_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_offense_resupply; }
	{ void (C::*p)() = &C::clear_defense_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::defense_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_defense_resupply; }
	{ void (C::*p)() = &C::clear_heavy_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heavy_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heavy_resupply; }
	{ void (C::*p)() = &C::clear_infowar_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::infowar_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_infowar_resupply; }
	{ void (C::*p)() = &C::clear_hacking_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hacking_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hacking_resupply; }
	{ void (C::*p)() = &C::clear_hover_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hover_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hover_resupply; }
	{ void (C::*p)() = &C::clear_zionite_resupply; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zionite_resupply; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zionite_resupply; }
}
#undef C

#define C Protobuf::Stats_Allies_WarlordSquadRendezvous
struct OpPb_A_Stats_Allies_WarlordSquadRendezvous { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_WarlordSquadRendezvous); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_WarlordSquadRendezvous, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_WarlordSquadRendezvous { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_WarlordSquadRendezvous); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_WarlordSquadRendezvous, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_WarlordSquadRendezvous()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_WarlordSquadRendezvous()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_WarlordSquadRendezvous()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_dakka; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::dakka; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_dakka; }
	{ void (C::*p)() = &C::clear_infantry; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::infantry; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_infantry; }
	{ void (C::*p)() = &C::clear_muscle; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::muscle; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_muscle; }
	{ void (C::*p)() = &C::clear_geek; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::geek; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_geek; }
	{ void (C::*p)() = &C::clear_ranger; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ranger; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ranger; }
	{ void (C::*p)() = &C::clear_pyro; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pyro; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pyro; }
	{ void (C::*p)() = &C::clear_chimera; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::chimera; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_chimera; }
	{ void (C::*p)() = &C::clear_ghost; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ghost; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ghost; }
}
#undef C

#define C Protobuf::Stats_Allies_TotalOrders
struct OpPb_A_Stats_Allies_TotalOrders { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_TotalOrders); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_TotalOrders, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_TotalOrders { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_TotalOrders); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_TotalOrders, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_TotalOrders()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_TotalOrders()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_TotalOrders()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_stay; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::stay; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_stay; }
	{ void (C::*p)() = &C::clear_goto_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::goto_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_goto_; }
	{ void (C::*p)() = &C::clear_roam; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::roam; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_roam; }
	{ void (C::*p)() = &C::clear_follow; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::follow; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_follow; }
	{ void (C::*p)() = &C::clear_guard; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guard; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_guard; }
	{ void (C::*p)() = &C::clear_aid; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::aid; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_aid; }
	{ void (C::*p)() = &C::clear_tunnel; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tunnel; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tunnel; }
	{ void (C::*p)() = &C::clear_drop; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::drop; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_drop; }
	{ void (C::*p)() = &C::clear_pickup; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pickup; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pickup; }
	{ void (C::*p)() = &C::clear_collect; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::collect; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_collect; }
	{ void (C::*p)() = &C::clear_explore; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::explore; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_explore; }
	{ void (C::*p)() = &C::clear_return_; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::return_; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_return_; }
}
#undef C

#define C Protobuf::Stats_Allies_AllyAttacks
struct OpPb_A_Stats_Allies_AllyAttacks { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_AllyAttacks); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_AllyAttacks, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_AllyAttacks { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_AllyAttacks); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_AllyAttacks, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_AllyAttacks()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_AllyAttacks()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_AllyAttacks()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_total_damage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::total_damage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_total_damage; }
	{ void (C::*p)() = &C::clear_kills; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kills; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kills; }
}
#undef C

#define C Protobuf::Stats_Allies_BorgCreated
struct OpPb_A_Stats_Allies_BorgCreated { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_BorgCreated); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_BorgCreated, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_BorgCreated { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_BorgCreated); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_BorgCreated, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_BorgCreated()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_BorgCreated()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_BorgCreated()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_largest_collective; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::largest_collective; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_largest_collective; }
}
#undef C

#define C Protobuf::Stats_Allies_XomAmusementGains
struct OpPb_A_Stats_Allies_XomAmusementGains { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies_XomAmusementGains); };
template struct OpPb_Rob<OpPb_A_Stats_Allies_XomAmusementGains, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies_XomAmusementGains { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies_XomAmusementGains); };
template struct OpPb_Rob<OpPb_M_Stats_Allies_XomAmusementGains, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies_XomAmusementGains()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies_XomAmusementGains()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies_XomAmusementGains()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_average_entertainment; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_entertainment; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_entertainment; }
	{ void (C::*p)() = &C::clear_good_acts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::good_acts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_good_acts; }
	{ void (C::*p)() = &C::clear_bad_acts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::bad_acts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_bad_acts; }
}
#undef C

#define C Protobuf::Stats_Allies
struct OpPb_A_Stats_Allies { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Allies); };
template struct OpPb_Rob<OpPb_A_Stats_Allies, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Allies { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Allies); };
template struct OpPb_Rob<OpPb_M_Stats_Allies, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Allies()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Allies()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Allies()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_total_allies; }
	{ void (C::*p)() = &C::clear_total_allies; }
	{ const ::Protobuf::Stats_Allies_TotalAllies& (C::*p)() const = &C::total_allies; }
	{ ::Protobuf::Stats_Allies_TotalAllies* (C::*p)() = &C::release_total_allies; }
	{ ::Protobuf::Stats_Allies_TotalAllies* (C::*p)() = &C::mutable_total_allies; }
	{ void (C::*p)(::Protobuf::Stats_Allies_TotalAllies* total_allies) = &C::set_allocated_total_allies; }
	{ bool (C::*p)() const = &C::has_zionite_dispatches; }
	{ void (C::*p)() = &C::clear_zionite_dispatches; }
	{ const ::Protobuf::Stats_Allies_ZioniteDispatches& (C::*p)() const = &C::zionite_dispatches; }
	{ ::Protobuf::Stats_Allies_ZioniteDispatches* (C::*p)() = &C::release_zionite_dispatches; }
	{ ::Protobuf::Stats_Allies_ZioniteDispatches* (C::*p)() = &C::mutable_zionite_dispatches; }
	{ void (C::*p)(::Protobuf::Stats_Allies_ZioniteDispatches* zionite_dispatches) = &C::set_allocated_zionite_dispatches; }
	{ void (C::*p)() = &C::clear_ufd_resources; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ufd_resources; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ufd_resources; }
	{ void (C::*p)() = &C::clear_warlord_eca_mod; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::warlord_eca_mod; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_warlord_eca_mod; }
	{ bool (C::*p)() const = &C::has_warlord_squad_rendezvous; }
	{ void (C::*p)() = &C::clear_warlord_squad_rendezvous; }
	{ const ::Protobuf::Stats_Allies_WarlordSquadRendezvous& (C::*p)() const = &C::warlord_squad_rendezvous; }
	{ ::Protobuf::Stats_Allies_WarlordSquadRendezvous* (C::*p)() = &C::release_warlord_squad_rendezvous; }
	{ ::Protobuf::Stats_Allies_WarlordSquadRendezvous* (C::*p)() = &C::mutable_warlord_squad_rendezvous; }
	{ void (C::*p)(::Protobuf::Stats_Allies_WarlordSquadRendezvous* warlord_squad_rendezvous) = &C::set_allocated_warlord_squad_rendezvous; }
	{ bool (C::*p)() const = &C::has_total_orders; }
	{ void (C::*p)() = &C::clear_total_orders; }
	{ const ::Protobuf::Stats_Allies_TotalOrders& (C::*p)() const = &C::total_orders; }
	{ ::Protobuf::Stats_Allies_TotalOrders* (C::*p)() = &C::release_total_orders; }
	{ ::Protobuf::Stats_Allies_TotalOrders* (C::*p)() = &C::mutable_total_orders; }
	{ void (C::*p)(::Protobuf::Stats_Allies_TotalOrders* total_orders) = &C::set_allocated_total_orders; }
	{ bool (C::*p)() const = &C::has_ally_attacks; }
	{ void (C::*p)() = &C::clear_ally_attacks; }
	{ const ::Protobuf::Stats_Allies_AllyAttacks& (C::*p)() const = &C::ally_attacks; }
	{ ::Protobuf::Stats_Allies_AllyAttacks* (C::*p)() = &C::release_ally_attacks; }
	{ ::Protobuf::Stats_Allies_AllyAttacks* (C::*p)() = &C::mutable_ally_attacks; }
	{ void (C::*p)(::Protobuf::Stats_Allies_AllyAttacks* ally_attacks) = &C::set_allocated_ally_attacks; }
	{ void (C::*p)() = &C::clear_allies_corrupted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::allies_corrupted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_allies_corrupted; }
	{ void (C::*p)() = &C::clear_allies_melted; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::allies_melted; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_allies_melted; }
	{ void (C::*p)() = &C::clear_turrets_deployed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::turrets_deployed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_turrets_deployed; }
	{ void (C::*p)() = &C::clear_fabricated_assembled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fabricated_assembled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fabricated_assembled; }
	{ void (C::*p)() = &C::clear_field_lobotomies; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::field_lobotomies; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_field_lobotomies; }
	{ bool (C::*p)() const = &C::has_borg_created; }
	{ void (C::*p)() = &C::clear_borg_created; }
	{ const ::Protobuf::Stats_Allies_BorgCreated& (C::*p)() const = &C::borg_created; }
	{ ::Protobuf::Stats_Allies_BorgCreated* (C::*p)() = &C::release_borg_created; }
	{ ::Protobuf::Stats_Allies_BorgCreated* (C::*p)() = &C::mutable_borg_created; }
	{ void (C::*p)(::Protobuf::Stats_Allies_BorgCreated* borg_created) = &C::set_allocated_borg_created; }
	{ bool (C::*p)() const = &C::has_xom_amusement_gains; }
	{ void (C::*p)() = &C::clear_xom_amusement_gains; }
	{ const ::Protobuf::Stats_Allies_XomAmusementGains& (C::*p)() const = &C::xom_amusement_gains; }
	{ ::Protobuf::Stats_Allies_XomAmusementGains* (C::*p)() = &C::release_xom_amusement_gains; }
	{ ::Protobuf::Stats_Allies_XomAmusementGains* (C::*p)() = &C::mutable_xom_amusement_gains; }
	{ void (C::*p)(::Protobuf::Stats_Allies_XomAmusementGains* xom_amusement_gains) = &C::set_allocated_xom_amusement_gains; }
}
#undef C

#define C Protobuf::Stats_Intel_ActiveInfowar
struct OpPb_A_Stats_Intel_ActiveInfowar { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Intel_ActiveInfowar); };
template struct OpPb_Rob<OpPb_A_Stats_Intel_ActiveInfowar, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Intel_ActiveInfowar { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Intel_ActiveInfowar); };
template struct OpPb_Rob<OpPb_M_Stats_Intel_ActiveInfowar, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Intel_ActiveInfowar()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Intel_ActiveInfowar()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Intel_ActiveInfowar()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_optics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::optics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_optics; }
	{ void (C::*p)() = &C::clear_sensors; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sensors; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sensors; }
	{ void (C::*p)() = &C::clear_ass; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ass; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ass; }
	{ void (C::*p)() = &C::clear_iff; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::iff; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_iff; }
	{ void (C::*p)() = &C::clear_zeronet; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::zeronet; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_zeronet; }
	{ void (C::*p)() = &C::clear_terrain; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terrain; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terrain; }
	{ void (C::*p)() = &C::clear_structural; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::structural; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_structural; }
	{ void (C::*p)() = &C::clear_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_traps; }
	{ void (C::*p)() = &C::clear_seismic; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::seismic; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_seismic; }
	{ void (C::*p)() = &C::clear_decoding; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decoding; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_decoding; }
	{ void (C::*p)() = &C::clear_tnc; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::tnc; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_tnc; }
	{ void (C::*p)() = &C::clear_machine_analysis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machine_analysis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machine_analysis; }
	{ void (C::*p)() = &C::clear_triangulation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::triangulation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_triangulation; }
	{ void (C::*p)() = &C::clear_cloaking; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cloaking; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cloaking; }
	{ void (C::*p)() = &C::clear_spoofing; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::spoofing; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_spoofing; }
	{ void (C::*p)() = &C::clear_jamming; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::jamming; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_jamming; }
	{ void (C::*p)() = &C::clear_ecm; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ecm; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ecm; }
	{ void (C::*p)() = &C::clear_id_mask; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::id_mask; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_id_mask; }
}
#undef C

#define C Protobuf::Stats_Intel_DroneLaunches
struct OpPb_A_Stats_Intel_DroneLaunches { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Intel_DroneLaunches); };
template struct OpPb_Rob<OpPb_A_Stats_Intel_DroneLaunches, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Intel_DroneLaunches { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Intel_DroneLaunches); };
template struct OpPb_Rob<OpPb_M_Stats_Intel_DroneLaunches, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Intel_DroneLaunches()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Intel_DroneLaunches()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Intel_DroneLaunches()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_drone_recoveries; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::drone_recoveries; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_drone_recoveries; }
}
#undef C

#define C Protobuf::Stats_Intel_Decoded0b10Intel
struct OpPb_A_Stats_Intel_Decoded0b10Intel { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Intel_Decoded0b10Intel); };
template struct OpPb_Rob<OpPb_A_Stats_Intel_Decoded0b10Intel, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Intel_Decoded0b10Intel { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Intel_Decoded0b10Intel); };
template struct OpPb_Rob<OpPb_M_Stats_Intel_Decoded0b10Intel, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Intel_Decoded0b10Intel()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Intel_Decoded0b10Intel()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Intel_Decoded0b10Intel()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_traps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::traps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_traps; }
	{ void (C::*p)() = &C::clear_emergency_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::emergency_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_emergency_access; }
	{ void (C::*p)() = &C::clear_items; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::items; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_items; }
	{ void (C::*p)() = &C::clear_machines; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machines; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machines; }
	{ void (C::*p)() = &C::clear_garrisons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::garrisons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_garrisons; }
	{ void (C::*p)() = &C::clear_patrols; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::patrols; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_patrols; }
	{ void (C::*p)() = &C::clear_investigations; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::investigations; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_investigations; }
	{ void (C::*p)() = &C::clear_reinforcements; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::reinforcements; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_reinforcements; }
	{ void (C::*p)() = &C::clear_guards; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guards; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_guards; }
	{ void (C::*p)() = &C::clear_exits; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::exits; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_exits; }
}
#undef C

#define C Protobuf::Stats_Intel_ZioniteIntelReceived
struct OpPb_A_Stats_Intel_ZioniteIntelReceived { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Intel_ZioniteIntelReceived); };
template struct OpPb_Rob<OpPb_A_Stats_Intel_ZioniteIntelReceived, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Intel_ZioniteIntelReceived { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Intel_ZioniteIntelReceived); };
template struct OpPb_Rob<OpPb_M_Stats_Intel_ZioniteIntelReceived, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Intel_ZioniteIntelReceived()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Intel_ZioniteIntelReceived()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Intel_ZioniteIntelReceived()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_main_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::main_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_main_access; }
	{ void (C::*p)() = &C::clear_branch_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::branch_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_branch_access; }
	{ void (C::*p)() = &C::clear_emergency_access; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::emergency_access; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_emergency_access; }
	{ void (C::*p)() = &C::clear_guard_positions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::guard_positions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_guard_positions; }
	{ void (C::*p)() = &C::clear_component_stockpiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::component_stockpiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_component_stockpiles; }
	{ void (C::*p)() = &C::clear_prototype_stockpiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prototype_stockpiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prototype_stockpiles; }
	{ void (C::*p)() = &C::clear_component_schematics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::component_schematics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_component_schematics; }
	{ void (C::*p)() = &C::clear_prototype_schematics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::prototype_schematics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_prototype_schematics; }
	{ void (C::*p)() = &C::clear_unaware_schematics; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unaware_schematics; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unaware_schematics; }
	{ void (C::*p)() = &C::clear_unaware_analyses; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unaware_analyses; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unaware_analyses; }
	{ void (C::*p)() = &C::clear_trap_installations; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trap_installations; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trap_installations; }
	{ void (C::*p)() = &C::clear_active_terminals; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::active_terminals; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_active_terminals; }
	{ void (C::*p)() = &C::clear_active_garrisons; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::active_garrisons; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_active_garrisons; }
	{ void (C::*p)() = &C::clear_depthwide_sectors_0; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::depthwide_sectors_0; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_depthwide_sectors_0; }
	{ void (C::*p)() = &C::clear_depthwide_sectors_1; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::depthwide_sectors_1; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_depthwide_sectors_1; }
}
#undef C

#define C Protobuf::Stats_Intel
struct OpPb_A_Stats_Intel { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Intel); };
template struct OpPb_Rob<OpPb_A_Stats_Intel, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Intel { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Intel); };
template struct OpPb_Rob<OpPb_M_Stats_Intel, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Intel()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Intel()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Intel()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_active_infowar; }
	{ void (C::*p)() = &C::clear_active_infowar; }
	{ const ::Protobuf::Stats_Intel_ActiveInfowar& (C::*p)() const = &C::active_infowar; }
	{ ::Protobuf::Stats_Intel_ActiveInfowar* (C::*p)() = &C::release_active_infowar; }
	{ ::Protobuf::Stats_Intel_ActiveInfowar* (C::*p)() = &C::mutable_active_infowar; }
	{ void (C::*p)(::Protobuf::Stats_Intel_ActiveInfowar* active_infowar) = &C::set_allocated_active_infowar; }
	{ void (C::*p)() = &C::clear_robot_analysis_total; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robot_analysis_total; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robot_analysis_total; }
	{ void (C::*p)() = &C::clear_derelict_logs_recovered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::derelict_logs_recovered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_derelict_logs_recovered; }
	{ bool (C::*p)() const = &C::has_drone_launches; }
	{ void (C::*p)() = &C::clear_drone_launches; }
	{ const ::Protobuf::Stats_Intel_DroneLaunches& (C::*p)() const = &C::drone_launches; }
	{ ::Protobuf::Stats_Intel_DroneLaunches* (C::*p)() = &C::release_drone_launches; }
	{ ::Protobuf::Stats_Intel_DroneLaunches* (C::*p)() = &C::mutable_drone_launches; }
	{ void (C::*p)(::Protobuf::Stats_Intel_DroneLaunches* drone_launches) = &C::set_allocated_drone_launches; }
	{ bool (C::*p)() const = &C::has_decoded_0b10_intel; }
	{ void (C::*p)() = &C::clear_decoded_0b10_intel; }
	{ const ::Protobuf::Stats_Intel_Decoded0b10Intel& (C::*p)() const = &C::decoded_0b10_intel; }
	{ ::Protobuf::Stats_Intel_Decoded0b10Intel* (C::*p)() = &C::release_decoded_0b10_intel; }
	{ ::Protobuf::Stats_Intel_Decoded0b10Intel* (C::*p)() = &C::mutable_decoded_0b10_intel; }
	{ void (C::*p)(::Protobuf::Stats_Intel_Decoded0b10Intel* decoded_0b10_intel) = &C::set_allocated_decoded_0b10_intel; }
	{ bool (C::*p)() const = &C::has_zionite_intel_received; }
	{ void (C::*p)() = &C::clear_zionite_intel_received; }
	{ const ::Protobuf::Stats_Intel_ZioniteIntelReceived& (C::*p)() const = &C::zionite_intel_received; }
	{ ::Protobuf::Stats_Intel_ZioniteIntelReceived* (C::*p)() = &C::release_zionite_intel_received; }
	{ ::Protobuf::Stats_Intel_ZioniteIntelReceived* (C::*p)() = &C::mutable_zionite_intel_received; }
	{ void (C::*p)(::Protobuf::Stats_Intel_ZioniteIntelReceived* zionite_intel_received) = &C::set_allocated_zionite_intel_received; }
}
#undef C

#define C Protobuf::Stats_Exploration_SpacesMoved
struct OpPb_A_Stats_Exploration_SpacesMoved { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration_SpacesMoved); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration_SpacesMoved, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration_SpacesMoved { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration_SpacesMoved); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration_SpacesMoved, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration_SpacesMoved()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration_SpacesMoved()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration_SpacesMoved()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core; }
	{ void (C::*p)() = &C::clear_treads; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::treads; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_treads; }
	{ void (C::*p)() = &C::clear_legs; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::legs; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_legs; }
	{ void (C::*p)() = &C::clear_wheels; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wheels; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wheels; }
	{ void (C::*p)() = &C::clear_hover; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hover; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hover; }
	{ void (C::*p)() = &C::clear_flight; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::flight; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_flight; }
	{ void (C::*p)() = &C::clear_fastest_speed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fastest_speed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fastest_speed; }
	{ void (C::*p)() = &C::clear_average_speed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::average_speed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_average_speed; }
	{ void (C::*p)() = &C::clear_slowest_speed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::slowest_speed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_slowest_speed; }
	{ void (C::*p)() = &C::clear_overloaded_moves; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overloaded_moves; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overloaded_moves; }
	{ void (C::*p)() = &C::clear_propulsion_burnouts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion_burnouts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion_burnouts; }
	{ void (C::*p)() = &C::clear_robots_hopped; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::robots_hopped; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_robots_hopped; }
	{ void (C::*p)() = &C::clear_potential_cave_ins; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::potential_cave_ins; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_potential_cave_ins; }
	{ void (C::*p)() = &C::clear_cave_ins_triggered; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::cave_ins_triggered; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_cave_ins_triggered; }
	{ void (C::*p)() = &C::clear_teleports; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::teleports; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_teleports; }
	{ void (C::*p)() = &C::clear_spacefolds; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::spacefolds; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_spacefolds; }
	{ void (C::*p)() = &C::clear_microwarps; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::microwarps; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_microwarps; }
	{ void (C::*p)() = &C::clear_time_travels; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::time_travels; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_time_travels; }
}
#undef C

#define C Protobuf::Stats_Exploration_ExplorationRatePercent_RegionsVisited
struct OpPb_A_Stats_Exploration_ExplorationRatePercent_RegionsVisited { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration_ExplorationRatePercent_RegionsVisited); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration_ExplorationRatePercent_RegionsVisited, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration_ExplorationRatePercent_RegionsVisited { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration_ExplorationRatePercent_RegionsVisited); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration_ExplorationRatePercent_RegionsVisited, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration_ExplorationRatePercent_RegionsVisited()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration_ExplorationRatePercent_RegionsVisited()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration_ExplorationRatePercent_RegionsVisited()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_branch_regions; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::branch_regions; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_branch_regions; }
}
#undef C

#define C Protobuf::Stats_Exploration_ExplorationRatePercent
struct OpPb_A_Stats_Exploration_ExplorationRatePercent { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration_ExplorationRatePercent); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration_ExplorationRatePercent, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration_ExplorationRatePercent { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration_ExplorationRatePercent); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration_ExplorationRatePercent, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration_ExplorationRatePercent()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration_ExplorationRatePercent()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration_ExplorationRatePercent()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_regions_visited; }
	{ void (C::*p)() = &C::clear_regions_visited; }
	{ const ::Protobuf::Stats_Exploration_ExplorationRatePercent_RegionsVisited& (C::*p)() const = &C::regions_visited; }
	{ ::Protobuf::Stats_Exploration_ExplorationRatePercent_RegionsVisited* (C::*p)() = &C::release_regions_visited; }
	{ ::Protobuf::Stats_Exploration_ExplorationRatePercent_RegionsVisited* (C::*p)() = &C::mutable_regions_visited; }
	{ void (C::*p)(::Protobuf::Stats_Exploration_ExplorationRatePercent_RegionsVisited* regions_visited) = &C::set_allocated_regions_visited; }
	{ void (C::*p)() = &C::clear_pre_discovered_areas; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pre_discovered_areas; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pre_discovered_areas; }
	{ void (C::*p)() = &C::clear_known_exits_taken; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::known_exits_taken; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_known_exits_taken; }
	{ void (C::*p)() = &C::clear_unknown_exits_taken; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unknown_exits_taken; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unknown_exits_taken; }
}
#undef C

#define C Protobuf::Stats_Exploration_TerrainDestroyed
struct OpPb_A_Stats_Exploration_TerrainDestroyed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration_TerrainDestroyed); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration_TerrainDestroyed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration_TerrainDestroyed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration_TerrainDestroyed); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration_TerrainDestroyed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration_TerrainDestroyed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration_TerrainDestroyed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration_TerrainDestroyed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
	{ void (C::*p)() = &C::clear_projectile; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::projectile; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_projectile; }
	{ void (C::*p)() = &C::clear_aoe; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::aoe; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_aoe; }
}
#undef C

#define C Protobuf::Stats_Exploration_TerrainRammed
struct OpPb_A_Stats_Exploration_TerrainRammed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration_TerrainRammed); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration_TerrainRammed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration_TerrainRammed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration_TerrainRammed); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration_TerrainRammed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration_TerrainRammed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration_TerrainRammed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration_TerrainRammed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_walls_destroyed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::walls_destroyed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_walls_destroyed; }
	{ void (C::*p)() = &C::clear_machines_disabled; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::machines_disabled; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_machines_disabled; }
}
#undef C

#define C Protobuf::Stats_Exploration
struct OpPb_A_Stats_Exploration { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Exploration); };
template struct OpPb_Rob<OpPb_A_Stats_Exploration, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Exploration { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Exploration); };
template struct OpPb_Rob<OpPb_M_Stats_Exploration, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Exploration()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Exploration()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Exploration()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_turns_passed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::turns_passed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_turns_passed; }
	{ bool (C::*p)() const = &C::has_spaces_moved; }
	{ void (C::*p)() = &C::clear_spaces_moved; }
	{ const ::Protobuf::Stats_Exploration_SpacesMoved& (C::*p)() const = &C::spaces_moved; }
	{ ::Protobuf::Stats_Exploration_SpacesMoved* (C::*p)() = &C::release_spaces_moved; }
	{ ::Protobuf::Stats_Exploration_SpacesMoved* (C::*p)() = &C::mutable_spaces_moved; }
	{ void (C::*p)(::Protobuf::Stats_Exploration_SpacesMoved* spaces_moved) = &C::set_allocated_spaces_moved; }
	{ bool (C::*p)() const = &C::has_exploration_rate_percent; }
	{ void (C::*p)() = &C::clear_exploration_rate_percent; }
	{ const ::Protobuf::Stats_Exploration_ExplorationRatePercent& (C::*p)() const = &C::exploration_rate_percent; }
	{ ::Protobuf::Stats_Exploration_ExplorationRatePercent* (C::*p)() = &C::release_exploration_rate_percent; }
	{ ::Protobuf::Stats_Exploration_ExplorationRatePercent* (C::*p)() = &C::mutable_exploration_rate_percent; }
	{ void (C::*p)(::Protobuf::Stats_Exploration_ExplorationRatePercent* exploration_rate_percent) = &C::set_allocated_exploration_rate_percent; }
	{ void (C::*p)() = &C::clear_scrap_searched; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::scrap_searched; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_scrap_searched; }
	{ void (C::*p)() = &C::clear_spaces_dug; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::spaces_dug; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_spaces_dug; }
	{ bool (C::*p)() const = &C::has_terrain_destroyed; }
	{ void (C::*p)() = &C::clear_terrain_destroyed; }
	{ const ::Protobuf::Stats_Exploration_TerrainDestroyed& (C::*p)() const = &C::terrain_destroyed; }
	{ ::Protobuf::Stats_Exploration_TerrainDestroyed* (C::*p)() = &C::release_terrain_destroyed; }
	{ ::Protobuf::Stats_Exploration_TerrainDestroyed* (C::*p)() = &C::mutable_terrain_destroyed; }
	{ void (C::*p)(::Protobuf::Stats_Exploration_TerrainDestroyed* terrain_destroyed) = &C::set_allocated_terrain_destroyed; }
	{ bool (C::*p)() const = &C::has_terrain_rammed; }
	{ void (C::*p)() = &C::clear_terrain_rammed; }
	{ const ::Protobuf::Stats_Exploration_TerrainRammed& (C::*p)() const = &C::terrain_rammed; }
	{ ::Protobuf::Stats_Exploration_TerrainRammed* (C::*p)() = &C::release_terrain_rammed; }
	{ ::Protobuf::Stats_Exploration_TerrainRammed* (C::*p)() = &C::mutable_terrain_rammed; }
	{ void (C::*p)(::Protobuf::Stats_Exploration_TerrainRammed* terrain_rammed) = &C::set_allocated_terrain_rammed; }
	{ void (C::*p)() = &C::clear_doors_sealed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::doors_sealed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_doors_sealed; }
}
#undef C

#define C Protobuf::Stats_Actions_Total
struct OpPb_A_Stats_Actions_Total { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Actions_Total); };
template struct OpPb_Rob<OpPb_A_Stats_Actions_Total, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Actions_Total { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Actions_Total); };
template struct OpPb_Rob<OpPb_M_Stats_Actions_Total, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Actions_Total()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Actions_Total()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Actions_Total()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_wait; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::wait; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_wait; }
	{ void (C::*p)() = &C::clear_move; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::move; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_move; }
	{ void (C::*p)() = &C::clear_hop; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hop; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hop; }
	{ void (C::*p)() = &C::clear_pick_up; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::pick_up; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_pick_up; }
	{ void (C::*p)() = &C::clear_fast_attach; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fast_attach; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fast_attach; }
	{ void (C::*p)() = &C::clear_attach; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::attach; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_attach; }
	{ void (C::*p)() = &C::clear_detach; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::detach; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_detach; }
	{ void (C::*p)() = &C::clear_swap; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::swap; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_swap; }
	{ void (C::*p)() = &C::clear_drop; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::drop; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_drop; }
	{ void (C::*p)() = &C::clear_fire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fire; }
	{ void (C::*p)() = &C::clear_melee; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee; }
	{ void (C::*p)() = &C::clear_ram; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ram; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ram; }
	{ void (C::*p)() = &C::clear_kick; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::kick; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_kick; }
	{ void (C::*p)() = &C::clear_crush; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::crush; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_crush; }
	{ void (C::*p)() = &C::clear_escape_stasis; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::escape_stasis; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_escape_stasis; }
	{ void (C::*p)() = &C::clear_rewire; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::rewire; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_rewire; }
	{ void (C::*p)() = &C::clear_trap; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::trap; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_trap; }
	{ void (C::*p)() = &C::clear_miscellaneous; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::miscellaneous; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_miscellaneous; }
}
#undef C

#define C Protobuf::Stats_Actions
struct OpPb_A_Stats_Actions { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Actions); };
template struct OpPb_Rob<OpPb_A_Stats_Actions, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Actions { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Actions); };
template struct OpPb_Rob<OpPb_M_Stats_Actions, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Actions()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Actions()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Actions()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_total; }
	{ void (C::*p)() = &C::clear_total; }
	{ const ::Protobuf::Stats_Actions_Total& (C::*p)() const = &C::total; }
	{ ::Protobuf::Stats_Actions_Total* (C::*p)() = &C::release_total; }
	{ ::Protobuf::Stats_Actions_Total* (C::*p)() = &C::mutable_total; }
	{ void (C::*p)(::Protobuf::Stats_Actions_Total* total) = &C::set_allocated_total; }
}
#undef C

#define C Protobuf::Stats_Rpglike_LevelsRaised
struct OpPb_A_Stats_Rpglike_LevelsRaised { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Rpglike_LevelsRaised); };
template struct OpPb_Rob<OpPb_A_Stats_Rpglike_LevelsRaised, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Rpglike_LevelsRaised { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Rpglike_LevelsRaised); };
template struct OpPb_Rob<OpPb_M_Stats_Rpglike_LevelsRaised, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Rpglike_LevelsRaised()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Rpglike_LevelsRaised()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Rpglike_LevelsRaised()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_xp_earned; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::xp_earned; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_xp_earned; }
	{ void (C::*p)() = &C::clear_xp_spent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::xp_spent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_xp_spent; }
}
#undef C

#define C Protobuf::Stats_Rpglike_Upgrades
struct OpPb_A_Stats_Rpglike_Upgrades { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Rpglike_Upgrades); };
template struct OpPb_Rob<OpPb_A_Stats_Rpglike_Upgrades, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Rpglike_Upgrades { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Rpglike_Upgrades); };
template struct OpPb_Rob<OpPb_M_Stats_Rpglike_Upgrades, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Rpglike_Upgrades()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Rpglike_Upgrades()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Rpglike_Upgrades()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power_slot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power_slot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power_slot; }
	{ void (C::*p)() = &C::clear_propulsion_slot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion_slot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion_slot; }
	{ void (C::*p)() = &C::clear_utility_slot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility_slot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility_slot; }
	{ void (C::*p)() = &C::clear_weapon_slot; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon_slot; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon_slot; }
	{ void (C::*p)() = &C::clear_core_integrity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core_integrity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core_integrity; }
	{ void (C::*p)() = &C::clear_heat_dissipation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::heat_dissipation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_heat_dissipation; }
	{ void (C::*p)() = &C::clear_energy_generation; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_generation; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_generation; }
	{ void (C::*p)() = &C::clear_energy_storage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::energy_storage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_energy_storage; }
	{ void (C::*p)() = &C::clear_matter_storage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::matter_storage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_matter_storage; }
	{ void (C::*p)() = &C::clear_mass_support; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::mass_support; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_mass_support; }
	{ void (C::*p)() = &C::clear_inventory_capacity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::inventory_capacity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_inventory_capacity; }
	{ void (C::*p)() = &C::clear_sight_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sight_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sight_range; }
	{ void (C::*p)() = &C::clear_sensor_range; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::sensor_range; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_sensor_range; }
	{ void (C::*p)() = &C::clear_terrain_scan_density; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::terrain_scan_density; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_terrain_scan_density; }
	{ void (C::*p)() = &C::clear_ranged_accuracy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ranged_accuracy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ranged_accuracy; }
	{ void (C::*p)() = &C::clear_melee_accuracy; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::melee_accuracy; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_melee_accuracy; }
	{ void (C::*p)() = &C::clear_hack_attack_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hack_attack_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hack_attack_percent; }
	{ void (C::*p)() = &C::clear_hack_defense_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::hack_defense_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_hack_defense_percent; }
	{ void (C::*p)() = &C::clear_ki_resistance_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ki_resistance_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ki_resistance_percent; }
	{ void (C::*p)() = &C::clear_th_resistance_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::th_resistance_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_th_resistance_percent; }
	{ void (C::*p)() = &C::clear_ex_resistance_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ex_resistance_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ex_resistance_percent; }
	{ void (C::*p)() = &C::clear_ki_damage_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ki_damage_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ki_damage_percent; }
	{ void (C::*p)() = &C::clear_th_damage_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::th_damage_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_th_damage_percent; }
	{ void (C::*p)() = &C::clear_ex_damage_percent; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::ex_damage_percent; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_ex_damage_percent; }
}
#undef C

#define C Protobuf::Stats_Rpglike_ProtomatterCreated_IntegrityRestored
struct OpPb_A_Stats_Rpglike_ProtomatterCreated_IntegrityRestored { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Rpglike_ProtomatterCreated_IntegrityRestored); };
template struct OpPb_Rob<OpPb_A_Stats_Rpglike_ProtomatterCreated_IntegrityRestored, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Rpglike_ProtomatterCreated_IntegrityRestored { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Rpglike_ProtomatterCreated_IntegrityRestored); };
template struct OpPb_Rob<OpPb_M_Stats_Rpglike_ProtomatterCreated_IntegrityRestored, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Rpglike_ProtomatterCreated_IntegrityRestored()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Rpglike_ProtomatterCreated_IntegrityRestored()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Rpglike_ProtomatterCreated_IntegrityRestored()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_core; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::core; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_core; }
	{ void (C::*p)() = &C::clear_parts; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts; }
}
#undef C

#define C Protobuf::Stats_Rpglike_ProtomatterCreated
struct OpPb_A_Stats_Rpglike_ProtomatterCreated { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Rpglike_ProtomatterCreated); };
template struct OpPb_Rob<OpPb_A_Stats_Rpglike_ProtomatterCreated, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Rpglike_ProtomatterCreated { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Rpglike_ProtomatterCreated); };
template struct OpPb_Rob<OpPb_M_Stats_Rpglike_ProtomatterCreated, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Rpglike_ProtomatterCreated()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Rpglike_ProtomatterCreated()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Rpglike_ProtomatterCreated()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_integrity_restored; }
	{ void (C::*p)() = &C::clear_integrity_restored; }
	{ const ::Protobuf::Stats_Rpglike_ProtomatterCreated_IntegrityRestored& (C::*p)() const = &C::integrity_restored; }
	{ ::Protobuf::Stats_Rpglike_ProtomatterCreated_IntegrityRestored* (C::*p)() = &C::release_integrity_restored; }
	{ ::Protobuf::Stats_Rpglike_ProtomatterCreated_IntegrityRestored* (C::*p)() = &C::mutable_integrity_restored; }
	{ void (C::*p)(::Protobuf::Stats_Rpglike_ProtomatterCreated_IntegrityRestored* integrity_restored) = &C::set_allocated_integrity_restored; }
}
#undef C

#define C Protobuf::Stats_Rpglike
struct OpPb_A_Stats_Rpglike { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Rpglike); };
template struct OpPb_Rob<OpPb_A_Stats_Rpglike, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Rpglike { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Rpglike); };
template struct OpPb_Rob<OpPb_M_Stats_Rpglike, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Rpglike()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Rpglike()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Rpglike()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_levels_raised; }
	{ void (C::*p)() = &C::clear_levels_raised; }
	{ const ::Protobuf::Stats_Rpglike_LevelsRaised& (C::*p)() const = &C::levels_raised; }
	{ ::Protobuf::Stats_Rpglike_LevelsRaised* (C::*p)() = &C::release_levels_raised; }
	{ ::Protobuf::Stats_Rpglike_LevelsRaised* (C::*p)() = &C::mutable_levels_raised; }
	{ void (C::*p)(::Protobuf::Stats_Rpglike_LevelsRaised* levels_raised) = &C::set_allocated_levels_raised; }
	{ bool (C::*p)() const = &C::has_upgrades; }
	{ void (C::*p)() = &C::clear_upgrades; }
	{ const ::Protobuf::Stats_Rpglike_Upgrades& (C::*p)() const = &C::upgrades; }
	{ ::Protobuf::Stats_Rpglike_Upgrades* (C::*p)() = &C::release_upgrades; }
	{ ::Protobuf::Stats_Rpglike_Upgrades* (C::*p)() = &C::mutable_upgrades; }
	{ void (C::*p)(::Protobuf::Stats_Rpglike_Upgrades* upgrades) = &C::set_allocated_upgrades; }
	{ bool (C::*p)() const = &C::has_protomatter_created; }
	{ void (C::*p)() = &C::clear_protomatter_created; }
	{ const ::Protobuf::Stats_Rpglike_ProtomatterCreated& (C::*p)() const = &C::protomatter_created; }
	{ ::Protobuf::Stats_Rpglike_ProtomatterCreated* (C::*p)() = &C::release_protomatter_created; }
	{ ::Protobuf::Stats_Rpglike_ProtomatterCreated* (C::*p)() = &C::mutable_protomatter_created; }
	{ void (C::*p)(::Protobuf::Stats_Rpglike_ProtomatterCreated* protomatter_created) = &C::set_allocated_protomatter_created; }
	{ void (C::*p)() = &C::clear_protomatter_decayed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::protomatter_decayed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_protomatter_decayed; }
}
#undef C

#define C Protobuf::Stats_Player2_SlotsEvolved
struct OpPb_A_Stats_Player2_SlotsEvolved { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2_SlotsEvolved); };
template struct OpPb_Rob<OpPb_A_Stats_Player2_SlotsEvolved, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2_SlotsEvolved { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2_SlotsEvolved); };
template struct OpPb_Rob<OpPb_M_Stats_Player2_SlotsEvolved, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2_SlotsEvolved()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2_SlotsEvolved()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2_SlotsEvolved()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_power; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::power; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_power; }
	{ void (C::*p)() = &C::clear_propulsion; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::propulsion; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_propulsion; }
	{ void (C::*p)() = &C::clear_utility; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::utility; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_utility; }
	{ void (C::*p)() = &C::clear_weapon; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::weapon; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_weapon; }
}
#undef C

#define C Protobuf::Stats_Player2_DamageTaken_CoreDamage
struct OpPb_A_Stats_Player2_DamageTaken_CoreDamage { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2_DamageTaken_CoreDamage); };
template struct OpPb_Rob<OpPb_A_Stats_Player2_DamageTaken_CoreDamage, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2_DamageTaken_CoreDamage { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2_DamageTaken_CoreDamage); };
template struct OpPb_Rob<OpPb_M_Stats_Player2_DamageTaken_CoreDamage, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2_DamageTaken_CoreDamage()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2_DamageTaken_CoreDamage()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2_DamageTaken_CoreDamage()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_player2percentage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::player2percentage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_player2percentage; }
}
#undef C

#define C Protobuf::Stats_Player2_DamageTaken
struct OpPb_A_Stats_Player2_DamageTaken { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2_DamageTaken); };
template struct OpPb_Rob<OpPb_A_Stats_Player2_DamageTaken, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2_DamageTaken { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2_DamageTaken); };
template struct OpPb_Rob<OpPb_M_Stats_Player2_DamageTaken, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2_DamageTaken()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2_DamageTaken()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2_DamageTaken()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ bool (C::*p)() const = &C::has_core; }
	{ void (C::*p)() = &C::clear_core; }
	{ const ::Protobuf::Stats_Player2_DamageTaken_CoreDamage& (C::*p)() const = &C::core; }
	{ ::Protobuf::Stats_Player2_DamageTaken_CoreDamage* (C::*p)() = &C::release_core; }
	{ ::Protobuf::Stats_Player2_DamageTaken_CoreDamage* (C::*p)() = &C::mutable_core; }
	{ void (C::*p)(::Protobuf::Stats_Player2_DamageTaken_CoreDamage* core) = &C::set_allocated_core; }
	{ void (C::*p)() = &C::clear_absorbed_by_shields; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::absorbed_by_shields; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_absorbed_by_shields; }
}
#undef C

#define C Protobuf::Stats_Player2_DamageInflicted
struct OpPb_A_Stats_Player2_DamageInflicted { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2_DamageInflicted); };
template struct OpPb_Rob<OpPb_A_Stats_Player2_DamageInflicted, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2_DamageInflicted { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2_DamageInflicted); };
template struct OpPb_Rob<OpPb_M_Stats_Player2_DamageInflicted, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2_DamageInflicted()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2_DamageInflicted()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2_DamageInflicted()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_player2percentage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::player2percentage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_player2percentage; }
}
#undef C

#define C Protobuf::Stats_Player2_CombatHostilesDestroyed
struct OpPb_A_Stats_Player2_CombatHostilesDestroyed { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2_CombatHostilesDestroyed); };
template struct OpPb_Rob<OpPb_A_Stats_Player2_CombatHostilesDestroyed, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2_CombatHostilesDestroyed { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2_CombatHostilesDestroyed); };
template struct OpPb_Rob<OpPb_M_Stats_Player2_CombatHostilesDestroyed, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2_CombatHostilesDestroyed()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2_CombatHostilesDestroyed()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2_CombatHostilesDestroyed()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_player2percentage; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::player2percentage; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_player2percentage; }
}
#undef C

#define C Protobuf::Stats_Player2
struct OpPb_A_Stats_Player2 { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Player2); };
template struct OpPb_Rob<OpPb_A_Stats_Player2, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Player2 { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Player2); };
template struct OpPb_Rob<OpPb_M_Stats_Player2, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Player2()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Player2()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Player2()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_slots_evolved; }
	{ void (C::*p)() = &C::clear_slots_evolved; }
	{ const ::Protobuf::Stats_Player2_SlotsEvolved& (C::*p)() const = &C::slots_evolved; }
	{ ::Protobuf::Stats_Player2_SlotsEvolved* (C::*p)() = &C::release_slots_evolved; }
	{ ::Protobuf::Stats_Player2_SlotsEvolved* (C::*p)() = &C::mutable_slots_evolved; }
	{ void (C::*p)(::Protobuf::Stats_Player2_SlotsEvolved* slots_evolved) = &C::set_allocated_slots_evolved; }
	{ void (C::*p)() = &C::clear_parts_attached; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_attached; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_attached; }
	{ void (C::*p)() = &C::clear_parts_lost; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::parts_lost; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_parts_lost; }
	{ bool (C::*p)() const = &C::has_damage_taken; }
	{ void (C::*p)() = &C::clear_damage_taken; }
	{ const ::Protobuf::Stats_Player2_DamageTaken& (C::*p)() const = &C::damage_taken; }
	{ ::Protobuf::Stats_Player2_DamageTaken* (C::*p)() = &C::release_damage_taken; }
	{ ::Protobuf::Stats_Player2_DamageTaken* (C::*p)() = &C::mutable_damage_taken; }
	{ void (C::*p)(::Protobuf::Stats_Player2_DamageTaken* damage_taken) = &C::set_allocated_damage_taken; }
	{ bool (C::*p)() const = &C::has_damage_inflicted; }
	{ void (C::*p)() = &C::clear_damage_inflicted; }
	{ const ::Protobuf::Stats_Player2_DamageInflicted& (C::*p)() const = &C::damage_inflicted; }
	{ ::Protobuf::Stats_Player2_DamageInflicted* (C::*p)() = &C::release_damage_inflicted; }
	{ ::Protobuf::Stats_Player2_DamageInflicted* (C::*p)() = &C::mutable_damage_inflicted; }
	{ void (C::*p)(::Protobuf::Stats_Player2_DamageInflicted* damage_inflicted) = &C::set_allocated_damage_inflicted; }
	{ bool (C::*p)() const = &C::has_combat_hostiles_destroyed; }
	{ void (C::*p)() = &C::clear_combat_hostiles_destroyed; }
	{ const ::Protobuf::Stats_Player2_CombatHostilesDestroyed& (C::*p)() const = &C::combat_hostiles_destroyed; }
	{ ::Protobuf::Stats_Player2_CombatHostilesDestroyed* (C::*p)() = &C::release_combat_hostiles_destroyed; }
	{ ::Protobuf::Stats_Player2_CombatHostilesDestroyed* (C::*p)() = &C::mutable_combat_hostiles_destroyed; }
	{ void (C::*p)(::Protobuf::Stats_Player2_CombatHostilesDestroyed* combat_hostiles_destroyed) = &C::set_allocated_combat_hostiles_destroyed; }
}
#undef C

#define C Protobuf::Stats_Polymind_Hosts
struct OpPb_A_Stats_Polymind_Hosts { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Polymind_Hosts); };
template struct OpPb_Rob<OpPb_A_Stats_Polymind_Hosts, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Polymind_Hosts { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Polymind_Hosts); };
template struct OpPb_Rob<OpPb_M_Stats_Polymind_Hosts, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Polymind_Hosts()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Polymind_Hosts()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Polymind_Hosts()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_combat_hostiles; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::combat_hostiles; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_combat_hostiles; }
	{ void (C::*p)() = &C::clear_allies; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::allies; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_allies; }
}
#undef C

#define C Protobuf::Stats_Polymind_AverageSuspicion
struct OpPb_A_Stats_Polymind_AverageSuspicion { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Polymind_AverageSuspicion); };
template struct OpPb_Rob<OpPb_A_Stats_Polymind_AverageSuspicion, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Polymind_AverageSuspicion { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Polymind_AverageSuspicion); };
template struct OpPb_Rob<OpPb_M_Stats_Polymind_AverageSuspicion, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Polymind_AverageSuspicion()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Polymind_AverageSuspicion()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Polymind_AverageSuspicion()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_unsuspicious_activity; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unsuspicious_activity; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unsuspicious_activity; }
	{ void (C::*p)() = &C::clear_returns_to_shadow; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::returns_to_shadow; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_returns_to_shadow; }
	{ void (C::*p)() = &C::clear_fuzzy_dispatches; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::fuzzy_dispatches; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_fuzzy_dispatches; }
}
#undef C

#define C Protobuf::Stats_Polymind_ProtomatterCreated
struct OpPb_A_Stats_Polymind_ProtomatterCreated { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Polymind_ProtomatterCreated); };
template struct OpPb_Rob<OpPb_A_Stats_Polymind_ProtomatterCreated, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Polymind_ProtomatterCreated { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Polymind_ProtomatterCreated); };
template struct OpPb_Rob<OpPb_M_Stats_Polymind_ProtomatterCreated, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Polymind_ProtomatterCreated()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Polymind_ProtomatterCreated()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Polymind_ProtomatterCreated()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ void (C::*p)() = &C::clear_overall; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::overall; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_overall; }
	{ void (C::*p)() = &C::clear_used; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::used; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_used; }
	{ void (C::*p)() = &C::clear_decayed; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::decayed; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_decayed; }
	{ void (C::*p)() = &C::clear_highest_spend; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::highest_spend; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_highest_spend; }
}
#undef C

#define C Protobuf::Stats_Polymind
struct OpPb_A_Stats_Polymind { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats_Polymind); };
template struct OpPb_Rob<OpPb_A_Stats_Polymind, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats_Polymind { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats_Polymind); };
template struct OpPb_Rob<OpPb_M_Stats_Polymind, &C::MaybeArenaPtr>;
void op_pb_use_Stats_Polymind()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats_Polymind()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats_Polymind()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_hosts; }
	{ void (C::*p)() = &C::clear_hosts; }
	{ const ::Protobuf::Stats_Polymind_Hosts& (C::*p)() const = &C::hosts; }
	{ ::Protobuf::Stats_Polymind_Hosts* (C::*p)() = &C::release_hosts; }
	{ ::Protobuf::Stats_Polymind_Hosts* (C::*p)() = &C::mutable_hosts; }
	{ void (C::*p)(::Protobuf::Stats_Polymind_Hosts* hosts) = &C::set_allocated_hosts; }
	{ void (C::*p)() = &C::clear_unique_host_classes; }
	{ ::google::protobuf::int32 (C::*p)() const = &C::unique_host_classes; }
	{ void (C::*p)(::google::protobuf::int32 value) = &C::set_unique_host_classes; }
	{ bool (C::*p)() const = &C::has_average_suspicion; }
	{ void (C::*p)() = &C::clear_average_suspicion; }
	{ const ::Protobuf::Stats_Polymind_AverageSuspicion& (C::*p)() const = &C::average_suspicion; }
	{ ::Protobuf::Stats_Polymind_AverageSuspicion* (C::*p)() = &C::release_average_suspicion; }
	{ ::Protobuf::Stats_Polymind_AverageSuspicion* (C::*p)() = &C::mutable_average_suspicion; }
	{ void (C::*p)(::Protobuf::Stats_Polymind_AverageSuspicion* average_suspicion) = &C::set_allocated_average_suspicion; }
	{ bool (C::*p)() const = &C::has_protomatter_created; }
	{ void (C::*p)() = &C::clear_protomatter_created; }
	{ const ::Protobuf::Stats_Polymind_ProtomatterCreated& (C::*p)() const = &C::protomatter_created; }
	{ ::Protobuf::Stats_Polymind_ProtomatterCreated* (C::*p)() = &C::release_protomatter_created; }
	{ ::Protobuf::Stats_Polymind_ProtomatterCreated* (C::*p)() = &C::mutable_protomatter_created; }
	{ void (C::*p)(::Protobuf::Stats_Polymind_ProtomatterCreated* protomatter_created) = &C::set_allocated_protomatter_created; }
}
#undef C

#define C Protobuf::Stats
struct OpPb_A_Stats { typedef ::google::protobuf::Arena* (C::*type)() const; friend type OpPb_get(OpPb_A_Stats); };
template struct OpPb_Rob<OpPb_A_Stats, &C::GetArenaNoVirtual>;
struct OpPb_M_Stats { typedef void* (C::*type)() const; friend type OpPb_get(OpPb_M_Stats); };
template struct OpPb_Rob<OpPb_M_Stats, &C::MaybeArenaPtr>;
void op_pb_use_Stats()
{
	{ C& (C::*p)(const C&) = &C::operator=; }
	{ const C* (*p)() = &C::internal_default_instance; }
	{ ::google::protobuf::Arena* (C::*p)() const = OpPb_get(OpPb_A_Stats()); }
	{ void* (C::*p)() const = OpPb_get(OpPb_M_Stats()); }
	if (g_opPbNever) { C* a = 0; swap(*a, *a); }
	{ bool (C::*p)() const = &C::has_build; }
	{ void (C::*p)() = &C::clear_build; }
	{ const ::Protobuf::Stats_Build& (C::*p)() const = &C::build; }
	{ ::Protobuf::Stats_Build* (C::*p)() = &C::release_build; }
	{ ::Protobuf::Stats_Build* (C::*p)() = &C::mutable_build; }
	{ void (C::*p)(::Protobuf::Stats_Build* build) = &C::set_allocated_build; }
	{ bool (C::*p)() const = &C::has_resources; }
	{ void (C::*p)() = &C::clear_resources; }
	{ const ::Protobuf::Stats_Resources& (C::*p)() const = &C::resources; }
	{ ::Protobuf::Stats_Resources* (C::*p)() = &C::release_resources; }
	{ ::Protobuf::Stats_Resources* (C::*p)() = &C::mutable_resources; }
	{ void (C::*p)(::Protobuf::Stats_Resources* resources) = &C::set_allocated_resources; }
	{ bool (C::*p)() const = &C::has_kills; }
	{ void (C::*p)() = &C::clear_kills; }
	{ const ::Protobuf::Stats_Kills& (C::*p)() const = &C::kills; }
	{ ::Protobuf::Stats_Kills* (C::*p)() = &C::release_kills; }
	{ ::Protobuf::Stats_Kills* (C::*p)() = &C::mutable_kills; }
	{ void (C::*p)(::Protobuf::Stats_Kills* kills) = &C::set_allocated_kills; }
	{ bool (C::*p)() const = &C::has_combat; }
	{ void (C::*p)() = &C::clear_combat; }
	{ const ::Protobuf::Stats_Combat& (C::*p)() const = &C::combat; }
	{ ::Protobuf::Stats_Combat* (C::*p)() = &C::release_combat; }
	{ ::Protobuf::Stats_Combat* (C::*p)() = &C::mutable_combat; }
	{ void (C::*p)(::Protobuf::Stats_Combat* combat) = &C::set_allocated_combat; }
	{ bool (C::*p)() const = &C::has_alert; }
	{ void (C::*p)() = &C::clear_alert; }
	{ const ::Protobuf::Stats_Alert& (C::*p)() const = &C::alert; }
	{ ::Protobuf::Stats_Alert* (C::*p)() = &C::release_alert; }
	{ ::Protobuf::Stats_Alert* (C::*p)() = &C::mutable_alert; }
	{ void (C::*p)(::Protobuf::Stats_Alert* alert) = &C::set_allocated_alert; }
	{ bool (C::*p)() const = &C::has_stealth; }
	{ void (C::*p)() = &C::clear_stealth; }
	{ const ::Protobuf::Stats_Stealth& (C::*p)() const = &C::stealth; }
	{ ::Protobuf::Stats_Stealth* (C::*p)() = &C::release_stealth; }
	{ ::Protobuf::Stats_Stealth* (C::*p)() = &C::mutable_stealth; }
	{ void (C::*p)(::Protobuf::Stats_Stealth* stealth) = &C::set_allocated_stealth; }
	{ bool (C::*p)() const = &C::has_traps; }
	{ void (C::*p)() = &C::clear_traps; }
	{ const ::Protobuf::Stats_Traps& (C::*p)() const = &C::traps; }
	{ ::Protobuf::Stats_Traps* (C::*p)() = &C::release_traps; }
	{ ::Protobuf::Stats_Traps* (C::*p)() = &C::mutable_traps; }
	{ void (C::*p)(::Protobuf::Stats_Traps* traps) = &C::set_allocated_traps; }
	{ bool (C::*p)() const = &C::has_machines; }
	{ void (C::*p)() = &C::clear_machines; }
	{ const ::Protobuf::Stats_Machines& (C::*p)() const = &C::machines; }
	{ ::Protobuf::Stats_Machines* (C::*p)() = &C::release_machines; }
	{ ::Protobuf::Stats_Machines* (C::*p)() = &C::mutable_machines; }
	{ void (C::*p)(::Protobuf::Stats_Machines* machines) = &C::set_allocated_machines; }
	{ bool (C::*p)() const = &C::has_hacking; }
	{ void (C::*p)() = &C::clear_hacking; }
	{ const ::Protobuf::Stats_Hacking& (C::*p)() const = &C::hacking; }
	{ ::Protobuf::Stats_Hacking* (C::*p)() = &C::release_hacking; }
	{ ::Protobuf::Stats_Hacking* (C::*p)() = &C::mutable_hacking; }
	{ void (C::*p)(::Protobuf::Stats_Hacking* hacking) = &C::set_allocated_hacking; }
	{ bool (C::*p)() const = &C::has_bothacking; }
	{ void (C::*p)() = &C::clear_bothacking; }
	{ const ::Protobuf::Stats_Bothacking& (C::*p)() const = &C::bothacking; }
	{ ::Protobuf::Stats_Bothacking* (C::*p)() = &C::release_bothacking; }
	{ ::Protobuf::Stats_Bothacking* (C::*p)() = &C::mutable_bothacking; }
	{ void (C::*p)(::Protobuf::Stats_Bothacking* bothacking) = &C::set_allocated_bothacking; }
	{ bool (C::*p)() const = &C::has_allies; }
	{ void (C::*p)() = &C::clear_allies; }
	{ const ::Protobuf::Stats_Allies& (C::*p)() const = &C::allies; }
	{ ::Protobuf::Stats_Allies* (C::*p)() = &C::release_allies; }
	{ ::Protobuf::Stats_Allies* (C::*p)() = &C::mutable_allies; }
	{ void (C::*p)(::Protobuf::Stats_Allies* allies) = &C::set_allocated_allies; }
	{ bool (C::*p)() const = &C::has_intel; }
	{ void (C::*p)() = &C::clear_intel; }
	{ const ::Protobuf::Stats_Intel& (C::*p)() const = &C::intel; }
	{ ::Protobuf::Stats_Intel* (C::*p)() = &C::release_intel; }
	{ ::Protobuf::Stats_Intel* (C::*p)() = &C::mutable_intel; }
	{ void (C::*p)(::Protobuf::Stats_Intel* intel) = &C::set_allocated_intel; }
	{ bool (C::*p)() const = &C::has_exploration; }
	{ void (C::*p)() = &C::clear_exploration; }
	{ const ::Protobuf::Stats_Exploration& (C::*p)() const = &C::exploration; }
	{ ::Protobuf::Stats_Exploration* (C::*p)() = &C::release_exploration; }
	{ ::Protobuf::Stats_Exploration* (C::*p)() = &C::mutable_exploration; }
	{ void (C::*p)(::Protobuf::Stats_Exploration* exploration) = &C::set_allocated_exploration; }
	{ bool (C::*p)() const = &C::has_actions; }
	{ void (C::*p)() = &C::clear_actions; }
	{ const ::Protobuf::Stats_Actions& (C::*p)() const = &C::actions; }
	{ ::Protobuf::Stats_Actions* (C::*p)() = &C::release_actions; }
	{ ::Protobuf::Stats_Actions* (C::*p)() = &C::mutable_actions; }
	{ void (C::*p)(::Protobuf::Stats_Actions* actions) = &C::set_allocated_actions; }
	{ bool (C::*p)() const = &C::has_rpglike; }
	{ void (C::*p)() = &C::clear_rpglike; }
	{ const ::Protobuf::Stats_Rpglike& (C::*p)() const = &C::rpglike; }
	{ ::Protobuf::Stats_Rpglike* (C::*p)() = &C::release_rpglike; }
	{ ::Protobuf::Stats_Rpglike* (C::*p)() = &C::mutable_rpglike; }
	{ void (C::*p)(::Protobuf::Stats_Rpglike* rpglike) = &C::set_allocated_rpglike; }
	{ bool (C::*p)() const = &C::has_player2; }
	{ void (C::*p)() = &C::clear_player2; }
	{ const ::Protobuf::Stats_Player2& (C::*p)() const = &C::player2; }
	{ ::Protobuf::Stats_Player2* (C::*p)() = &C::release_player2; }
	{ ::Protobuf::Stats_Player2* (C::*p)() = &C::mutable_player2; }
	{ void (C::*p)(::Protobuf::Stats_Player2* player2) = &C::set_allocated_player2; }
	{ bool (C::*p)() const = &C::has_polymind; }
	{ void (C::*p)() = &C::clear_polymind; }
	{ const ::Protobuf::Stats_Polymind& (C::*p)() const = &C::polymind; }
	{ ::Protobuf::Stats_Polymind* (C::*p)() = &C::release_polymind; }
	{ ::Protobuf::Stats_Polymind* (C::*p)() = &C::mutable_polymind; }
	{ void (C::*p)(::Protobuf::Stats_Polymind* polymind) = &C::set_allocated_polymind; }
}
#undef C

void op_pb_use_free()
{
	using namespace Protobuf;
	{ void (*p)() = &protobuf_scoresheet_2eproto::InitDefaults; }
	{ const ::std::string& (*p)(DifficultyType value) = &Protobuf::DifficultyType_Name; }
	{ bool (*p)( const ::std::string& name, DifficultyType* value) = &Protobuf::DifficultyType_Parse; }
	{ const ::std::string& (*p)(SpecialModeType value) = &Protobuf::SpecialModeType_Name; }
	{ bool (*p)( const ::std::string& name, SpecialModeType* value) = &Protobuf::SpecialModeType_Parse; }
	{ const ::std::string& (*p)(MapType value) = &Protobuf::MapType_Name; }
	{ bool (*p)( const ::std::string& name, MapType* value) = &Protobuf::MapType_Parse; }
	{ const ::std::string& (*p)(HeatLevelType value) = &Protobuf::HeatLevelType_Name; }
	{ bool (*p)( const ::std::string& name, HeatLevelType* value) = &Protobuf::HeatLevelType_Parse; }
	{ const ::std::string& (*p)(MoveModeType value) = &Protobuf::MoveModeType_Name; }
	{ bool (*p)( const ::std::string& name, MoveModeType* value) = &Protobuf::MoveModeType_Parse; }
	{ const ::std::string& (*p)(UiLayoutType value) = &Protobuf::UiLayoutType_Name; }
	{ bool (*p)( const ::std::string& name, UiLayoutType* value) = &Protobuf::UiLayoutType_Parse; }
	{ const ::std::string& (*p)(MovementInputType value) = &Protobuf::MovementInputType_Name; }
	{ bool (*p)( const ::std::string& name, MovementInputType* value) = &Protobuf::MovementInputType_Parse; }
	{ const ::std::string& (*p)(FullscreenType value) = &Protobuf::FullscreenType_Name; }
	{ bool (*p)( const ::std::string& name, FullscreenType* value) = &Protobuf::FullscreenType_Parse; }
	{ const ::std::string& (*p)(SteamType value) = &Protobuf::SteamType_Name; }
	{ bool (*p)( const ::std::string& name, SteamType* value) = &Protobuf::SteamType_Parse; }
	{ const ::std::string& (*p)(SchematicType value) = &Protobuf::SchematicType_Name; }
	{ bool (*p)( const ::std::string& name, SchematicType* value) = &Protobuf::SchematicType_Parse; }
	{ const ::std::string& (*p)(SchematicMethodType value) = &Protobuf::SchematicMethodType_Name; }
	{ bool (*p)( const ::std::string& name, SchematicMethodType* value) = &Protobuf::SchematicMethodType_Parse; }
	{ const ::std::string& (*p)(StudyMethodType value) = &Protobuf::StudyMethodType_Name; }
	{ bool (*p)( const ::std::string& name, StudyMethodType* value) = &Protobuf::StudyMethodType_Parse; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::DifficultyType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::SpecialModeType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::MapType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::HeatLevelType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::MoveModeType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::UiLayoutType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::MovementInputType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::FullscreenType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::SteamType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::SchematicType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::SchematicMethodType>; }
	{ const ::google::protobuf::EnumDescriptor* (*p)() = &::google::protobuf::GetEnumDescriptor< ::Protobuf::StudyMethodType>; }
}
