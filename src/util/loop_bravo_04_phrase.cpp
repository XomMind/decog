// NOTE: private aliases and placeholder layouts for phrase routing at 0x5141b0.
#include <string>
typedef std::string LB4Text;
LB4Text lb4_intToString(int);
extern const LB4Text lb4_empty_d21b9c;
extern const char lb4_sep_bd5dd0[],lb4_colon_bd5dc8[];
struct LB4Entity { int id; LB4Entity(); bool operator!=(LB4Entity) const; };
struct LB4Map {
 LB4Entity player_4630f0(); bool visibleEntity_4631f0(LB4Entity); bool visible_4631c0(int);
 int turn_464270();
};
extern LB4Map *lb4_map_cefc4c;
struct LB4Type { char pad[0x20];int visibility,limit; char pad28; bool webhook; };
struct LB4Types { LB4Type *&at_9b81f0(unsigned); };
struct LB4Counts { int &at_9b81f0(unsigned); };
extern LB4Types lb4_types_cf08c4;
extern LB4Counts lb4_counts_cf4800;
struct LB4GameData { int unknown46f530(); };
extern LB4GameData lb4_gamedata_d1e860;
struct LB4Phrase {
 int type,turn,label; char pad0c[0x10];
 LB4Phrase(int,int,int,const LB4Text *,const LB4Text *,const LB4Text *);
 LB4Text text_514060();
};
struct LB4Phrases { void push_9b9280(LB4Phrase *&&); LB4Phrase *const &back_9b6540() const; };
extern LB4Phrases lb4_phrases_cf4d00;
struct LB4Label { LB4Text text_46ed40(); };
struct LB4Handle { int id; LB4Label *get_9b7910(); };
struct LB4Labels { LB4Handle &at_9b81f0(unsigned); };
extern LB4Labels lb4_labels_d1e88c;
struct LB4Webhook { char pad[0x34]; bool enabled; void comment_4f9f50(LB4Text); };
extern LB4Webhook *lb4_webhook_cefb5c;
extern int lb4_special_cf47b8,lb4_special_cf47bc;
bool lb4_phrase_5141b0(int id,const LB4Text *a,const LB4Text *b,const LB4Text *c,LB4Entity entity,int visible) {
 if(lb4_types_cf08c4.at_9b81f0(id)->limit && (lb4_counts_cf4800.at_9b81f0(id)>=lb4_types_cf08c4.at_9b81f0(id)->limit || lb4_types_cf08c4.at_9b81f0(id)->limit==-1)) return false;
 switch(lb4_types_cf08c4.at_9b81f0(id)->visibility) {
 break;
 case 1: if(entity!=lb4_map_cefc4c->player_4630f0()) { return false; } else break;
 case 2: if(!lb4_map_cefc4c->visibleEntity_4631f0(entity)) { return false; } else break;
 case 3: if(!lb4_map_cefc4c->visible_4631c0(visible)) return false;
 }
 lb4_phrases_cf4d00.push_9b9280(new LB4Phrase(id,lb4_map_cefc4c->turn_464270(),lb4_gamedata_d1e860.unknown46f530(),a,b,c));
 ++lb4_counts_cf4800.at_9b81f0(id);
 if(lb4_webhook_cefb5c && !lb4_types_cf08c4.at_9b81f0(id)->webhook && lb4_webhook_cefb5c->enabled) {
  LB4Phrase *phrase=lb4_phrases_cf4d00.back_9b6540();
  if(id==9 && lb4_special_cf47b8==15 && lb4_special_cf47bc==20) return true;
  lb4_webhook_cefb5c->comment_4f9f50(lb4_intToString(phrase->turn)+lb4_sep_bd5dd0+(phrase->label!=-1 ? lb4_labels_d1e88c.at_9b81f0(phrase->label).get_9b7910()->text_46ed40() : LB4Text(lb4_empty_d21b9c))+lb4_colon_bd5dc8+phrase->text_514060());
 }
 return true;
}
