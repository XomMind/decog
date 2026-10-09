// BS::turnUpdate_51da30 (0x51da30, 258 KB): runs the map-script triggers of the given event type (records ->
//	effects -> condition chains -> effect switch, effect 0x33 = numbered special scripts).
// NOTE: placeholder names/layouts throughout: Uf*/uf_* are private, callees carry their exe address in the name.
// Lives in src/util/ (sorts last in the link) because it declares many private throw() aliases.
#include <string>
using std::string;

struct UfHRec{int id;};struct UfEntity;struct UfProp;struct UfItem;struct UfCell;
struct UfPoint{bool ne_409cf0(int,int);bool is_409cb0(int,int);int distanceTo_409fb0(const UfPoint&);void set_40a060(const UfPoint&,int,int);void shift_40bf50(int);UfPoint(const UfPoint&,int,int)throw();int x,y;UfPoint(const UfPoint&,const UfPoint&)throw();bool test_409b90(const UfPoint&);void scale_40a300(int);UfPoint()throw();UfPoint(int,int)throw();UfPoint&operator=(const UfPoint&)throw();UfPoint(int)throw();UfPoint(const UfPoint&)throw();};
typedef UfPoint UfPos;
struct UfHE{int id;UfHE()throw();bool isNull_9b65d0()const throw();bool ne_9b6510(UfHE)const;bool eq_9b78e0(UfHE)const;UfEntity*get_9b6570()const throw();bool isValid_9b7230()const throw();};
struct UfHP{bool isNull_9b65d0()const throw();int id;UfHP()throw();UfProp*get_9b64f0()const throw();bool isValid_9b7230()const throw();};
struct UfHI{int id;UfHI()throw();bool isNull_9b65d0()const throw();UfItem*get_9b65b0()const throw();bool isValid_9b7230()const throw();};
template<class T>struct UfVP{int p0,p1,p2,p3;unsigned size_9b9260()const throw();T&at_9b81f0(unsigned)throw();bool empty_9b86e0()const throw();void clear_9bac80()throw();void push_back_9b9d30(const T&);};
struct UfVecU{UfVecU(unsigned,unsigned);UfVecU(unsigned,const int&);int&back_9b6540()throw();int p0,p1,p2,p3;UfVecU(const UfVecU&);int&front_9b7060()throw();void push_back_9b9280(int&&);UfVecU()throw();~UfVecU()throw();unsigned size_9b9260()const throw();int&at_9b81f0(unsigned)throw();bool empty_9b86e0()const throw();void clear_9bac80()throw();void push_back_9b9d30(const int&);};
struct UfVPt{void pop_back_9b33e0();UfPoint&back_9e8c10()throw();UfVPt(const UfVPt&);int p0,p1,p2,p3;void push_back_9b32e0(const UfPoint&);void clear_9b3560();void push_back_9b3020(UfPoint&&);UfVPt();UfVPt(unsigned,const UfPoint&);~UfVPt();unsigned size_9b9a50()const throw();UfPoint&at_9e7c10(unsigned)throw();UfPoint&front_9b7060()throw();bool empty_9b86e0()const throw();};
struct UfVecU2{int p0,p1,p2,p3;UfVecU2();void push_back_9b9d30(const int&);UfVecU2(unsigned,unsigned);~UfVecU2()throw();UfVecU2(const UfVecU2&);};
struct UfVHE2{UfVHE2(const struct UfVHE&);void push_back_9b80b0(const UfHE&);int p0,p1,p2,p3;UfVHE2();~UfVHE2();void push_back_9b7cf0(const UfHE&);UfHE&front_9b7060()throw();UfHE&at_9b81f0(unsigned)throw();unsigned size_9b9260()const throw();bool empty_9b86e0()const throw();};
struct UfVHE{int p0,p1,p2,p3;bool empty_9b86e0()const throw();unsigned size_9b9260()const throw();UfHE&at_9b81f0(unsigned)throw();};
struct UfColor{int c;UfColor(const UfColor&);};extern UfColor*uf_cfe674;
struct UfGroup{int type_9b4350()throw();void resetField_45e460();void unknown458460();UfHE unknown45e1c0(const string&);UfHE unknown45e2d0(const string&);void setField_45e4a0(int);UfVHE&members_416f40()throw();int count_44afb0()throw();int id_9b8f00()throw();};
struct UfHG{int id;UfHG()throw();bool eq_9b78e0(UfHG)const;UfGroup*get_9b7250()const throw();};
struct UfVHG{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfHG&at_9b81f0(unsigned)throw();};
struct UfVLnk{int p0,p1,p2,p3;UfVLnk&operator=(const UfVLnk&);};
struct UfLoc{int unknown46ed20();UfHE find_46ee80(int);bool inRange_46ecb0();int pad0;int type;int depth;UfVLnk v0c;char pad1c[0x25-0x1c];bool b25;char pad26[0x2f-0x26];bool b2f;void init_46eb70(int,int,int,int);};
struct UfHL{int id;UfLoc*get_9b7910()const throw();};
struct UfBox{int x1,y1,x2,y2;UfBox(int,int,int,int)throw();};struct UfSize{int w,h;};
struct UfZone{UfZone(const UfPoint&,UfHL,int,UfHE,UfHE){}~UfZone();UfPoint pt;UfHL loc;char bc;bool bd;char pade[2];int x10;UfHP h14;char pad18[4];int kind;int pad20[16];void unknown6c16d0(string);};	// NOTE: placeholder layout (0x60 bytes per operator new)
struct UfVZone{bool empty_9b86e0()const throw();void push_back_9b9d30(UfZone*const&);int p0,p1,p2,p3;UfVZone(const UfVZone&);~UfVZone();unsigned size_9b9260()const throw();UfZone*&at_9b81f0(unsigned)throw();};
struct UfAI{void unknown4593d0(UfVPt&);void set_44bef0(int);void unknown5b5380(struct UfJob2*);bool unknown458fb0(UfHE);void unknown459470(const UfBox&);void chase_5b4710(UfHE,int,int,int,int);void unknown459380(const UfPoint&);void unknown459520(const UfPoint&);struct UfJob*&unknown459070();bool getFollowers_580a90(UfVHE2*,int);int unknown4592e0();void unknown4593b0(const UfPoint&);void setField_4505b0(int);struct UfVPt*unknown458ef0();void set_44e540(int);void unknown459470(const struct UfRect&);void unknown5b2d10();void setPatrolRandom_5b3430(UfPoint);void setFollowEntity_5b2f80(UfHE,int);void unknown4582d0(int);void setField_4593f0(int);void unknown459540(const UfPoint&);void unknown459440(const UfPoint&,const UfSize&);void unknown459410(const UfBox&);void set_451930(int);UfHE getFollowEntity_458ed0();int id_9b8f00b()throw();UfHE*getEntity_459570(UfHE);int unknown458f30()throw();int id_9b8f00()throw();};
struct UfVHI{UfHI&back_9b6540()throw();void pop_back_9e8cd0();int p0,p1,p2,p3;void push_back_9b7cf0(const UfHI&);void push_back_9b80b0(const UfHI&);UfHI&front_9b7060()throw();UfVHI();~UfVHI();UfVHI&operator=(const UfVHI&);unsigned size_9b9260()const throw();UfHI&at_9b81f0(unsigned)throw();void clear_9b73d0()throw();bool empty_9b86e0()const throw();};
struct UfEntityDef{int x0;string name4;char pad20[4];int x24;int x28;char pad2c[0x48-0x2c];int x48;string s4c;int x68;char pad6c[0x9c-0x6c];int x9c;char pada0[0x138-0xa0];bool b138;char pad139[0x160-0x139];struct UfVRcp{int p0,p1,p2,p3;unsigned size_9b5100()const throw();struct UfVRcpE&at_9b8070(unsigned)throw();}v160;char pad170[0x1ac-0x170];string name1ac;};
struct UfEntity{int unknown5c8e20(int);int unknown5ca210();void unknown5cb830(UfVHI*);UfHI unknown5d2380(int);bool teleport_63b5a0(int,int);void unknown5c93d0(UfVecU*);int unknown5d1440();void unknown45b100(int*);int unknown5ccb50(UfHI);UfHE unknown5cc8e0();bool unknown45a780();int unknown5cc190(int);bool isXomCandidate_5d51a0();int unknown5cba50();int getRoomCount_448fe0(int);void unknown639470(int,int);void unknown5c8880(UfVHE2*);void unknown5c89d0(struct UfVPt*);void unknown45b360(int);bool unknown45aaa0(UfHE);void unknown5d6c30(UfVHE2*);void unknown5d7700(UfVHE2*,UfVecU*);int get_45a6e0()throw();void set_45b090(int);void unknown45b0b0();int getAiType_45a2a0();void removeByName_45b440(const string&);void unknown5de480(struct UfItemDef*);void unknown6396a0(const string&,int);bool unknown5c98c0(int,int,int);bool unknown45ad20(const string&);UfHE unknown5d2a90(int);void changePos_5dccb0(const UfPoint&,int);int unknown5cb8b0(UfVHI*);void unknown639530(int,int);int unknown45aa30();void unknown5dcc70(int,int);int unknown5c92e0(int);UfHI unknown5d5c30();UfHI unknown5d5b20();bool unknown45ab20(const string&);bool unknown5d7d60(int);bool unknown5d26e0(int);int unknown5c7d30();UfHE unknown45af90();void unknown639730(bool);int getFaction_45a2c0();const string&getName_45a280();const string&getName_416f40()throw();UfEntityDef*def_9b4350()throw();UfPoint&getPosition_45a4a0()throw();UfPoint pos_45a4c0();int getTarget_45a760()throw();UfHG getGroup_45a3f0();UfVHI*getInventoryList_45ab00()throw();UfAI*ai_45b590()throw();struct UfFx*unknown45ac40(int);int unknown45acb0(int);int unknown45adb0(int);int unknown45a920()throw();int unknown45a940()throw();int unknown45a8d0()throw();int unknown45a8f0()throw();int unknown45a880()throw();int getField_490840()throw();int unknown5c7fa0();int unknown5c8cb0();bool unknown5c9b10();int unknown5ca260();int unknown5ca400();int unknown5ca670();int unknown5cab90();bool unknown5cb680(UfHG);int unknown5cbb10();bool unknown5cbdf0(int,bool,bool);
	struct UfVPt&path_45d1a0()throw();void removeEffects_45b4c0(void*,bool);void unknown637bb0();bool unknown5d5250();void unknown6399e0(int,int);bool isHostileTo_45aa70(UfHE);struct UfSlots{int x0,x4,x8,xc;}*unknown45a840();void unknown6396f0(const string&,int);bool unknown5d1280(int);void unknown5fd900(int,int);void unknown5fdab0();void setAI_64ecf0(struct UfEntityAI*);void unknown5deb40(int);void unknown45b240(int);void unknown5ded70(int);void unknown45b270(int);void unknown637d10(struct UfEff*,int);void unknown5dea60(int,int);void setField_4514c0(int);int unknown45a990();int unknown5cab30();void unknown5defa0(int,int);void set_44e2c0(int);int unknown45a9d0();void setField_4514e0(int);int unknown45a9f0();void unknown45b340(struct UfFx*);void unknown45b3d0(struct UfFx*);void unknown45b070(const string&);void unknown5ddac0(const UfPoint&,int);void changeFaction_5dc780(UfHG,int);void unknown6395d0(void*,bool);bool isPlayer_5c7600();int getSize_45a360();void*unknown45b540();void unknown45b2a0();int unknown45a810();void*unknown5db5f0(UfHI,int,int,int);void unknown639800(void*);void die_633790(int,int,UfHE,int,int,int,int,int);};
struct UfInfo{int pad0;string name;int x20[10];};
struct UfPropDef{char pad0[0x20];string name20;char pad3c[0x60-0x3c];UfInfo*info;char pad64[0x8c-0x64];struct UfPD8c*x8c;char pad90[0xa8-0x90];int xa8[10];char padd0[0xf4-0xd0];int xf4;};
struct UfProp{void unknown665be0(int);bool isPassableFor_65e1d0(UfHE);bool unknown45cb10();int unknown44a630();bool isTrap_45cb70();struct UfPLink*unknown44b020()throw();void unknown665b90(const string&,int);void*unknown45c8e0(string);void unknown452270(int);struct UfMach*unknown45cb30()throw();int unknown457b10();UfPoint&pos_4184d0()throw();const string&location_45c590();const string&getName_45c5b0();int getNestedField_45c630()throw();int unknown45c870(int);int unknown45ca00(int);UfPropDef*def_9b8f00()throw();void unknown45ce10(bool,int,bool,UfHE);int unknown44ab40();void unknown45cc50(const UfPoint&);void unknown665b10(void*,bool);void unknown65f270(const UfPoint&);void unknown65d9d0(int);int getNestedField_45c570()throw();void disableMachine_65ed00();bool unknown45cad0();void setSoundMute_65f320(bool);struct UfFx*unknown45c800(int);void unknown45cee0(struct UfFx*);void unknown45cf00(struct UfFx*);void unknown665860(struct UfEff*);};
struct UfItemDef;struct UfItem{int unknown457cd0();void unknown458360(int);int unknown457fd0();int unknown457fb0();void unknown458310(int);void setBroken_5795b0(int,int);void unknown458690(void*,int);struct UfRL*unknown44a7d0();bool unknown457db0();int unknown44ab90();int unknown4578a0();int unknown4578c0();int unknown457880();int unknown457920();int unknown457a30();void unknown57a190(UfHE,int,int,int);int unknown457f90();string unknown573860(int,int);bool unknown457cf0();bool unknown457ad0();int unknown577fb0();bool unknown57a620();int id_9fcd80()throw();int unknown577600(int);void unknown458390(int);bool getField_415ee0();bool unknown5773d0(int,int);bool unknown457d10();bool unknown577530();void unknown5797c0();void unknown4585c0(int);string unknown457990();UfItemDef*def_9b4350()throw();string getName_571db0(int,int);int getType_44aec0()throw();int getNestedField_457820()throw();const string&name_457860();const string&name_457970();UfHE unknown457b50();int getEffectValue_457be0(int)throw();int unknown457c50(int)throw();int unknown457ca0()throw();bool unknown457d70()throw();UfPoint&pos_575920()throw();int trap_9b6bf0()throw();bool isPlayer_5758f0();void remove_57dbe0(bool,int,int,int);void unknown57a0f0(const UfPoint&,int,int);void unknown57c090(void*,bool);void set_44fc60(int);int getNestedField_4578a0()throw();void unknown579c80();int getNestedField_4578c0();void unknown57beb0(struct UfEff*,int);void set_450460(int);int unknown457c80()throw();struct UfFx*getEffect_457b70(int);void addEffect_4585a0(struct UfFx*);void unknown458630(struct UfFx*);};
struct UfCellDef{int x0;char pad4[0x50-4];UfInfo*info;};
struct UfCell{bool unknown45dc70();bool unknown45de40();bool unknown45d990();bool unknown45da50();bool unknown45d230();void unknown66b740(UfCell*);void unknown66ce10(int,int,int,int);UfHP getPropNT_45d550()throw();void unknown66b700(int,int);bool isMachinePart_45dcd0();void unknown66d580(int);bool unknown45db70();bool canPlaceEntity_66ad20(int);bool fitsProp_45d570(int);bool hasBlockingObject_45d7b0();bool unknown45df50(UfHP);int unknown45d0e0();void unknown66a050(int,int,int);void unknown670150(struct UfEff*);void trigger_45e110(bool,int,UfHE);const string&unknown45d140();UfPoint&pos_45d1a0();struct UfFx*getEffect_45d350(int);void unknown45df90(struct UfFx*);void remove_45e020(struct UfFx*);bool getField_4550b0()throw();const string&unknown45d100();const string&unknown45d120();UfHE getEntity_45d250();int getEffectValue_45d3c0(int);UfHP getProp_45d550();UfHI getItem_45d8f0();bool isPassableFor_66ab30(UfHE);int getArmor_66ae70();UfCellDef*def_9fcd80()throw();};
struct UfRect{UfRect(const UfPoint&,int,int)throw();UfRect(const UfPoint&,const UfPoint&)throw();bool contains_40b750(const UfPoint&);UfPoint center_40b620();UfRect(int,int,int,int)throw();UfRect(const UfPoint&,int)throw();void set_40b300(int,int,int,int);int x1,y1,x2,y2;UfRect()throw();UfPoint randomPoint_40be90();void randomPoint_40be30(UfPoint*);};
struct UfGrid{void getNeighbors_9ce500(const UfPoint&,struct UfVPt*);UfCell**at_9ceda0(int,int)throw();UfBox getArea_9b4400();bool contains_9b43b0(const UfPoint&);void getRect_9b4430(const UfPoint&,int,UfRect&);UfSize size_9b7930();int getWidth_9fcd80()throw();int getHeight_9b8f00()throw();UfCell**atPoint_9ced70(const UfPos&)throw();};
struct UfMap{void unknown74cb00();void addListB24_465540(UfHI);UfHE unknown71e7c0(const UfPoint&,int,int);void unknown7456a0();struct UfVMsg*unknown464570();UfPoint&unknown7141a0();UfVHI*getItems_4655e0();UfVPt*getItemPositions_465600();void unknown728fa0(UfHI);void unknown465030(UfHI);bool unknown7178d0(UfHE,const UfPoint&,const UfPoint*,const UfPoint&,const UfPoint*,int);void unknown731960();void unknown748a00(int,int);void unknown749240();bool unknown6f0f80(UfHE*,UfHE*,UfHE*);struct UfArr2*unknown4638c0();struct UfVVPt*unknown459070m();void unknown464710(int);void unknown747860(int,int);void unknown7457f0();bool unknown72a850(int,UfHE,UfHE);void unknown6c6600(UfHE,const string&);int spawnSquads_73e5c0(const UfPoint&,struct UfVStr2*);void unknown74bb90(UfHP,UfHE*,UfPoint*,bool*);UfBox&unknown464670();void escort_743350(int,int,int);void unknown742c80();void unknown7430a0(int,int);void unknown7243c0(int,int,int);void announceMachine_71dd30(UfHL);UfPoint&unknown464610();void unknown747060(const UfPoint&,int,int);void unknown7480e0(int);void unknown7409f0(int);void unknown740300(int);struct UfVRoute*unknown4645f0();string unknown463060(const UfPoint&);bool unknown7170a0(UfHE,const UfPoint&,UfVPt&,UfVecU&,UfVecU&,UfPoint&,int,int,int,int);void unknown73a490();void unknown73c750();bool unknown464450();void unknown465890(UfHP);void unknown7149a0(UfHE);void zionAttacked_731b10(int);int unknown4642b0();UfPoint unknown714120(int);void unknown465950(int,int,int);void unknown736510(int,const UfPoint&,struct UfRect&,int,int);bool isVisible_463190(int,int);void unknown72ffe0(int);void removeEntity_465750(UfHE);UfHI placeItem_6c5480(const string&,const UfPoint&);UfHE unknown715230(int,int);UfItemDef*selectRandomItemOfRating_6c40e0(int,int,int,int,int,int,int);void unknown6c3a50(struct UfWL&,int,int);int countPassableAdjacent_71c850(const UfPoint&);UfPoint unknown71d000(int);int unknown4642f0();void unknown738310();bool unknown6c6700(UfHP,const string&,int);UfHE getEntity671_463110();UfHI unknown6c5400(void*,const UfPoint&);UfPoint&unknown4184d0()throw();UfHE unknown6c5e20(struct UfBP*,const UfPoint&,int,int,int,int);UfPoint*unknown6f0ca0();void setUnknownA18_4653e0(bool);void unknown6c6b90(const UfPoint&,const string&,int,int);UfHE unknown6c5dc0(const string&,const UfPoint&,int,int,int,int,int);UfHE getPlayer_4630f0();bool isVisible_4631c0(const UfPoint&);bool unknown4631f0(UfHE);bool unknown4633c0(const UfPoint&);bool unknown463400(UfHE);int unknown463710();UfHG group_463890(int);void*unknown4638e0(int,int);UfVHG*groups_463950();int getTurn_464270()throw();int unknown4642d0()throw();void unknown4647a0(const UfPoint&,int);struct UfEntityDef*unknown6c5600(int,int,bool,int);UfHE placeEntity_6c58c0(struct UfEntityDef*,const UfPoint&,int,int,int,int,int);bool unknown71bc10(const UfPoint&,UfPoint*);UfItemDef*selectRandomItem_6c3bc0(int,int,int);struct UfVZone*zones_462e10();bool findPlaceableNear_71c150(UfPoint&,UfPoint&,int);bool unknown7168e0(const UfPoint&,const UfPoint&,UfEntity*,struct UfVPt*);bool findPropSpotNear_71c3c0(UfPoint&,UfPoint&,struct UfFaction*);void unknown464e60(UfHP);void unknown464f60(UfHI);UfHE getEntity_45d250();void unknown74d560(int,int,int,UfColor);void unknown6c65a0(UfHE,const string&,int);bool unknown716940(const UfPoint&,const UfPoint&,int,int);UfHI unknown6c51d0(struct UfItemDef*,UfHE,int,int);UfHI giveItem_6c52b0(const string&,UfHE,bool,int);void unknown714000(struct UfVPt*);bool unknown465200(UfPoint&,UfPoint&);bool isReachable_465230(int,UfPoint&,UfPoint&);int unknown715b10();UfHRec addRecord_777a20(UfHRec);};
struct UfParty{int x0;UfHE leader;int x8;};
struct UfOvermind{void spawnWarlordRaid_68e1f0(int);void resetField_9b7270();void spawnResponseParty_68c2f0(int,UfHE,const UfPoint&,int);bool unknown68d980(int,int,int);void wake_68d480();void unknown68c6d0(UfHE);void unknown6901e0(UfHE,int,int,int,const UfPoint&,int,int);void unknown68b9a0(UfVPt&,bool);int unknown45edd0(int);UfParty*unknown68cf70(UfVecU2,const UfPoint&);bool redirectParty_68d1f0(UfParty*,const UfPoint&,UfHE);bool dispatch_689100(const UfPoint&);void*unknown6892c0(int,UfPoint*,int);void*spawnPatrolParty_6896d0(UfHE,int,int,struct UfVPt*,int,int,int,int,int);void*unknown68a500(int,UfPoint*,bool);void*unknown684250(const UfPoint&,int);void*unknown685a10(UfHE,UfPoint*);void*unknown686c60(const UfPoint&,int,int,int);bool spawnAntiInfestationCarrier_688e80(const UfPoint&,const string&);void*unknown687520(UfHE,UfPoint*,int);UfParty*unknown45ed10();};
struct UfEntry{string key;string value;};struct UfEntryIt{UfEntry*p;UfEntry&deref_9b8da0()throw();};
struct UfGameData{int unknown789250(int);bool unknown46f4b0(int);int unknown46f530();int unknown46f4e0();bool hasObjectID_46fa40(int);void setEntryText_46f700(const string&,const string&);void addExit_7892d0(UfHE,const UfPoint&,const string&);UfEntryIt getEntryIterator_46f5b0(const string&);const string&getEntryText_46f6d0(const string&);};
struct UfXom{void pokeWall_6bdf10();void showXomAct_6bdb50(int,UfHE,int);bool b0;void unknown69e700(int,int,float);};extern UfXom uf_d25450;
struct UfPlayerData{void unknown46df70();void unknown77ffb0(int,int);void unknown783020();void unknown783060();void unlock_77fbc0(int);};extern UfPlayerData uf_cf45d8;
struct UfRng{float rangeFloat_406e20(float,float);bool chance_406c90(int);int rangeInt_406d70(float,float);};
extern UfRng rng;
struct UfRange{UfRange(int,int)throw();int x,y;int randomInRange_40c130()throw();};
struct UfFx{void*type;int value;UfFx(void*,int);};
UfFx::UfFx(void*type_,int value_){type=type_;value=value_;}
struct UfEntityAI{int d[0x4c];UfEntityAI(UfHE,int,int);};
struct UfCond{int type;string key;int op;string operand;bool compareInt_455e00(int);bool compareString_455f40(const string&);};
struct UfVCond{int p0,p1,p2,p3;unsigned size_9b7020()const throw();UfCond&at_9b7040(unsigned)throw();};
struct UfEff{int type;UfVCond conds;UfVecU jumps;int mode;int x28;int weight;bool once;char pad31[3];int x34;int x38;int x3c;int x40;UfRange range44;bool b4c;char pad4d[3];int x50;int x54;int x58;UfRange range5c;int x64;int x68;int x6c;int x70;int x74;int x78;int x7c;int x80;int x84;bool b88;char pad89[0x8c-0x89];int x8c;int x90;int x94;UfRange range98;int xa0;int xa4;bool bA8;char pada9[0xb0-0xa9];int xb0;char padb4[0xb8-0xb4];int xb8;int xbc;int xc0;char padc4[0xcc-0xc4];int xcc;int xd0;int xd4;int xd8;int xdc;int xe0;int xe4;bool bE8;bool bE9;bool bEA;char padEB[0xec-0xeb];UfRange rangeEC;char padF4[0x118-0xf4];int x118;int x11c;int x120;int x124;UfVecU v128;bool b138;bool b139;bool b13a;char pad13b;int x13c;int x140;string s144;string s160;int x17c;int x180;string s184;string s1a0;string s1bc;};
struct UfVEff{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfEff*&at_9b81f0(unsigned)throw();};
struct UfDef{int id;string name4;char pad20[0x3c-0x20];int type;char pad40[0x60-0x40];bool b60;bool b61;char pad62[2];int x64;int x68;char pad6c[0xc0-0x6c];UfVEff effects;};
struct UfRec{UfDef*def;UfHE e;const string*g;UfHE other;};
struct UfVRec{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfRec*&at_9b81f0(unsigned)throw();};
struct UfVVI{int p0,p1,p2,p3;UfVecU&at_9b8070(unsigned)throw();};
struct UfExpl{int d[16];UfExpl(UfHE,void*,const UfPoint&,UfHE,const UfPoint&,const UfPoint&);};
struct UfFactory{void unknown792890();UfHL createB_793120();void unknown793690();void showOnce_793450(int,int,int,int,int);UfHP createE_793360(void*);UfHI createD_7932b0(UfItemDef*);UfHRec createA_7930e0(void*);};
struct UfVoidVec{int p0,p1,p2,p3;void*&at_9b81f0(unsigned)throw();};
struct UfMapView{void unknown8195a0(const UfPoint&,int,int);void labelAccess_80e3a0(int,struct UfZone*);void unknown49ada0(int);void unknown819d50(int,bool);void unknown49adc0(int);};

extern UfMap*uf_cefc4c;extern UfGrid uf_cfd44c;extern UfOvermind uf_cf6428;extern UfGameData uf_d1e860;extern UfHL uf_d1e888;
extern string uf_cfe140[];extern int uf_b90000[];extern string uf_d312f0[];extern string uf_d25664;
extern string uf_cfd458[];extern string uf_d2f798[];extern bool uf_caf1f8[];extern string uf_d01860[];extern string uf_d31db8[];
extern UfVecU uf_d2ac98;extern bool uf_cebc50;extern bool uf_ba634c[];extern UfVVI uf_d1e8f0;extern int uf_ba5f40[];extern bool uf_ba6288[];
extern UfMapView*uf_cec054;extern UfFactory*uf_cefaa8;struct UfWL{UfWL(UfVecU&);void reset_9c07a0();UfVecU*keys_9c0790();int d0,d1,d2,d3,d4,d5,d6,d7,d8;UfWL();~UfWL();void add_9ba310(int,int);int&pick_9ba470();};
struct UfWLI{int d0,d1,d2,d3,d4,d5,d6,d7,d8;bool empty_9b81b0();void add_9ba310(struct UfItemDef*,int);struct UfItemDef*&pick_9ba470();};extern UfWLI uf_d29d44;extern int uf_ba3acc[];extern struct UfItemDef*uf_cefbec;extern bool uf_d257e4;extern int uf_d25740;extern int uf_cf645c,uf_cf6474;struct UfVParty{int p0,p1,p2,p3;unsigned size_9b9260()const throw();struct UfParty*&at_9b81f0(unsigned)throw();struct UfParty*&back_9b6540()throw();};extern UfVParty uf_cf6478;struct UfFlags{int push_5121f0(struct UfPhrase2*);void set_451400(int);};extern UfFlags uf_cf1080;extern bool uf_d28fb0;extern int uf_d1eab0,uf_d1eab4;struct UfFov{bool findPath_40c9a0(const UfPoint&,const UfPoint&,void*,void*,struct UfVPt&);void unknown40ca20(const UfPoint&,int,void*,int);};extern UfFov uf_cfe568;extern void*uf_cefc30;extern UfVPt uf_d15e58;extern int uf_d25624;extern int uf_d1e884;extern const char uf_b91cab[];struct UfFxObj{void init_503b20(int,const UfPoint&,const UfPoint*,int,int,int,int,int);};struct UfFxPool{UfFxObj*new_508610(UfFxPool*);};extern UfFxPool*uf_cefc50;extern UfPoint uf_d2e20c;
extern const float uf_c37190;extern const double uf_c37188,uf_c36de8;struct UfPhrase{char pad[0x20];int x20;};struct UfVPhrase{int p0,p1,p2,p3;UfPhrase*&at_9b81f0(unsigned)throw();};extern UfVPhrase uf_cf08c4;
struct UfStatDef{int x0;};struct UfVStatDef{int p0,p1,p2,p3;};extern UfVStatDef uf_d389c4;
struct UfStats{void add_472b90(unsigned,int);bool add_4729d0(unsigned,int,string,int);};extern UfStats uf_d2c658;extern const char uf_b91caa[];extern UfPoint uf_d20cf4;extern UfVHI uf_d33d74;extern int uf_caf160;extern int uf_caf144;extern int uf_caf150;extern int uf_caf164;
struct UfItemDef{int getValue_457330(int);bool unknown56fae0(UfVecU*);struct UfEntityDef*getRecord_56f3c0();int x0;char pad4[0x24-4];string name24;int x40;int x44;char pad48[4];int x4c;int x50;int x54;char pad58[4];int x5c;char pad60[4];int x64;char pad68[0x94-0x68];int x94;char pad98[0xf0-0x98];int xf0;int xf4;char padf8[0x128-0xf8];int x128;char pad12c[0x13c-0x12c];UfVecU v13c;char pad14c[0x190-0x14c];int x190;char pad194[0x1a0-0x194];struct UfBlastDef*x1a0;char pad1a4[0x23a-0x1a4];bool b23a;char pad23b[0x275-0x23b];bool b275;};struct UfVIDef{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfItemDef*&at_9b81f0(unsigned)throw();};extern UfVIDef uf_d2d1c4;
struct UfTerr{int x0;string name;};struct UfVTerr{int p0,p1,p2,p3;UfTerr*&at_9b81f0(unsigned)throw();};extern UfVTerr uf_cfb844;struct UfFaction{char pad[0x20];string name20;};struct UfVFac{int p0,p1,p2,p3;UfFaction*&at_9b81f0(unsigned)throw();};extern UfVFac uf_cf35b0;extern string uf_cf25d8[];struct UfAbil{char pad[0x20];string name20;};struct UfVAbil{int p0,p1,p2,p3;UfAbil*&at_9b81f0(unsigned)throw();};extern UfVAbil uf_d2c408;
struct UfBubble{void bubble_8758d0(bool);};extern UfBubble*uf_cec058;struct UfLogMsgs{void scrollToEnd_7b4f10();};extern UfLogMsgs*uf_cec0b4;struct UfVEDef{unsigned size_9b9260()const throw();int p0,p1,p2,p3;struct UfEntityDef*&at_9b81f0(unsigned)throw();};extern UfVEDef uf_d25de0;extern UfVoidVec uf_d2f0f8;extern UfVoidVec uf_cfd2cc;extern UfVHI uf_d32edc;

struct UfBlastDef{int pad[12];int x30;int pad34[2];int x3c;};struct UfArrI{int&at_9cfe20(int,int);};struct UfBlast{int pad[8];UfArrI a20;int pad24[11];UfBlast();~UfBlast();void init_455880(UfBlastDef*,int,UfPoint*,UfPoint*,UfPoint*);};
struct UfStrCIt{string*p;};struct UfStrIt:UfStrCIt{};
// ---- whiskey additions ----
struct UfSay{void say_49e250(int,int,string);};extern UfSay*uf_cefb48;extern const char uf_b91cb6[];
extern int uf_d1eac0;extern bool uf_d1eabc,uf_d1e880,uf_d257e5;
struct UfVbRef{int p,o;UfVbRef()throw();UfVbRef&set_9b3a70(bool)throw();bool get_9b3ad0()const throw();};
struct UfVBool{int p0,p1,p2,p3,p4;UfVBool();~UfVBool();void push_back_9b3920(bool);UfVbRef back_9b38e0()throw();UfVbRef at_9b38a0(unsigned)throw();};
void uf_eraseAt_9ce6d0(UfVZone&,unsigned&);
int uf_fn9d4500(UfVecU&);
bool uf_fn9d7670(const UfVBool&,bool);
int uf_fn9d76c0(const UfVBool&,bool);
UfZone*uf_randomRec_9d5d00(UfVZone&);
string uf_pointToString_40a4a0(const UfPoint&);
extern int uf_cfe5e8;extern bool uf_b95150[];
bool uf_findByName_9d7710(UfVFac&,const string&,UfFaction**);
struct UfVStr{int p0,p1,p2,p3;string&back_9b06c0()throw();};extern UfVStr uf_d1ea8c;
struct UfBP{int x0;char pad4[0x34-4];bool b34;};
struct UfVBP{int p0,p1,p2,p3;UfVBP();~UfVBP();unsigned size_9b9260()const throw();UfBP*&at_9b81f0(unsigned)throw();bool empty_9b86e0()const throw();void push_back_9b9d30(UfBP*const&);};
extern UfVBP uf_d1e97c[];extern UfVecU uf_d1ea6c;
int uf_randomIndex_9d9b20(UfVBP&);
int uf_fn9d4660(UfVBP&,UfBP*);
void uf_deleteObject_9d7850(UfVBP&,int);
struct UfObj969{void unknown965c10(int,int,int);void unknown96ada0(int);void start_969b60();void unknown967c90();void unknown966ed0();void unknown966dc0();void unknown969300();};extern UfObj969*uf_cec138;extern bool uf_d1eacc;extern int uf_d1eac4;
extern UfPropDef*uf_cefbd8;extern void*uf_cefc40;extern UfCellDef*uf_cefb84;extern int*uf_cefb9c;
void*uf_unknown777cf0();
extern int uf_d395f0;extern UfCellDef*uf_cefb80;
void uf_eraseAt_9d5190(UfVPt&,int);
void uf_opR1d_4542a0(const UfPoint*,int,int);
struct UfVStr2{struct UfStrIt end_9e9b30()throw();void insert_9b0860(struct UfStrCIt,unsigned,const string&);unsigned size_9b0650()const throw();string&at_9b06a0(unsigned)throw();int p0,p1,p2,p3;void push_back_9b0340(string&&);UfVStr2();~UfVStr2();void push_back_9b06f0(const string&);};
void uf_fn9d78c0(UfVStr2&,string);
string uf_randomString_9d3280(UfVStr2&);
struct UfVIDef2{int p0,p1,p2,p3;UfVIDef2();~UfVIDef2();void push_back_9b9d30(UfItemDef*const&);UfItemDef*&at_9b81f0(unsigned)throw();unsigned size_9b9260()const throw();bool empty_9b86e0()const throw();void clear_9bac80()throw();};
UfItemDef*uf_randomRec_9d5d00(UfVIDef2&);
extern const char uf_b91cb7[];extern string uf_d30268[];
int uf_pointsFn_4374c0(const UfPoint&,const UfPoint&);
bool uf_lookup2_9d7980(const string&,int**);
struct UfSlot{int x0;int x4;bool b8;};struct UfVSlot{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfSlot*&at_9b81f0(unsigned)throw();};
struct UfMach{int pad0[6];UfVSlot v18;int x28;};
struct UfProj{int x0;string name4;};struct UfVProj{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfProj*&at_9b81f0(unsigned)throw();};extern UfVProj uf_d35b58;
bool uf_strNe_9ceb30(const string&,const char*);
extern int uf_d1eb08,uf_d1eb0c;extern bool uf_d257e7;
void uf_unknown789ac0();
extern UfItemDef*uf_cefbe8;struct UfParts{void unknown8987b0(UfHI,UfVHE2*);void unknown89d610(UfHI,int);void unknown898860(UfHI,UfVHE2*);bool findParts_4a9a40(UfHI,struct UfVPartP*);struct UfPart*unknown894e70(UfHI);void toggle_8993e0(struct UfPart*,int);void unknown896820(UfHI);bool isLinked_4a9b10(UfHI);};extern UfParts*uf_cec088;
extern string uf_cf4acc,uf_cf4b04;
string uf_countString_407a80(int,const string&);
bool uf_findByName_9d7a40(UfVIDef&,const string&,UfItemDef**);
bool uf_contains_9db330(UfVecU&,int);
extern UfWL uf_d358c0;
extern int uf_d1eb10,uf_d25618;
extern "C" __declspec(dllimport) int __cdecl isalpha(int);extern "C" __declspec(dllimport) int __cdecl isdigit(int);extern "C" __declspec(dllimport) int __cdecl toupper(int);
struct UfVName{int p0,p1,p2,p3;};extern UfVName uf_cf3a20;extern int uf_caf168;
int uf_indexOfName4_9d7b80(UfVName&,const string&);
struct UfPart{void putChar_4180b0(int,int,int);void unknown890710(int);void unknown4a9120();void drawStatus_4a8e70(int);};extern const char uf_b91cbf[];
extern UfPropDef*uf_cefbd0;struct UfVMark{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfHP&at_9b81f0(unsigned)throw();};struct UfVVMark{int p0,p1,p2,p3;UfVMark&at_9b8070(unsigned)throw();};extern UfVVMark uf_d31640;
void uf_removeEntity_9d2f00(UfVMark&,UfHP);
extern int*uf_cefb88;void uf_fn510360(string&);
extern UfRange uf_d30348,uf_d21760;extern UfEntityDef*uf_cefc08;extern int uf_d2c46c;
bool uf_findByName_9d7be0(UfVoidVec&,const string&,void**);extern int uf_d1eaf8,uf_d1eafc,uf_d1eb00,uf_d1eb04;
extern UfVBP uf_d1ea0c;extern bool uf_cf6470,uf_cf6472;
extern int uf_d1ebac;extern UfPoint uf_d1ebb0;
void uf_getAdjacentCells_4fab80(const UfPoint&,UfVPt*);extern int uf_cf4740;extern string uf_d20c94;
struct UfPhrase2{int d[10];UfPhrase2(int,const string*,const string*,const string*,UfHE,UfHE);};
extern int uf_cf462c;
extern int uf_caed20;extern UfVecU uf_d1dd58;
struct UfRectP{UfPoint a;UfPoint b;UfRectP()throw();void set_40b300(int,int,int,int);};
bool uf_containsEntity_9d31e0(UfVHE2&,UfHE);extern const char uf_b91ccd[];extern bool uf_d257e9;
struct UfVPartP{int p0,p1,p2,p3;UfVPartP();~UfVPartP();unsigned size_9b9260()const throw();UfPart*&at_9b81f0(unsigned)throw();};
extern const char uf_b91cce[],uf_b91ccf[];
extern int uf_cf6514;extern UfHP uf_cf6510;
struct UfPD8c{int pad[15];int x3c;};
struct UfVMarkH{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfHP&at_9b81f0(unsigned)throw();};
void uf_fn9db000(UfVecU&,int);int uf_randomRec_9d5d00(UfVecU&);
struct UfVShot{int p0,p1,p2,p3;UfVShot();~UfVShot();};
struct UfShoot{int d[31];UfShoot(UfHE,int,const UfPoint&,const UfPoint&,int*,UfVShot&,int,UfHE);};
struct UfVRoute{int p0,p1,p2,p3;UfRect&front_9b7060()throw();UfRect&at_9b8070(unsigned)throw();unsigned size_9b5100()const throw();};
struct UfJob{int type;int pad[5];UfJob(int,int,UfHE,UfHI,const UfPoint&){}};UfRect uf_randomArea_9d7d20(UfVRoute*);
extern bool uf_cf4a00;struct UfPLink{bool unknown65cf80();};
struct UfSndMgr{void unknown454540();void unknown500010();};extern UfSndMgr uf_d2d2a0;extern UfVecU uf_cf46e4;
struct UfVHP{UfVHP(const UfVMark&);int p0,p1,p2,p3;UfVHP();~UfVHP();void push_back_9b7cf0(const UfHP&);UfHP&at_9b81f0(unsigned)throw();unsigned size_9b9260()const throw();bool empty_9b86e0()const throw();};
bool uf_nextLineStep_40ff60(const UfPoint&,const UfPoint&,UfPoint*);int uf_commonNeighbors_4fac50(const UfPoint&,const UfPoint&,UfVPt*);
float uf_distance_40a450(const UfPoint&,const UfPoint&);
struct UfVFloat{int p0,p1,p2,p3;UfVFloat();~UfVFloat();void push_back_9b84b0(float&&);float&at_9b81f0(unsigned)throw();bool empty_9b86e0()const throw();};
int uf_minIndex_9d7d70(UfVFloat&);
extern UfVStr2 uf_cf4bc0;extern UfVecU uf_cf4bd0;struct UfTally{void unknown6998a0(int,int,int);};extern UfTally uf_cf6888;
void uf_reveal_794da0(int,int,int,int);extern bool uf_b90480[];struct UfFW{void wake_68d480();};
struct UfRF{void resetField_9b7270();};extern UfRF uf_cf6454;
struct UfRcp{int x0;int x4;};struct UfVRcpE{int p0,p1,p2,p3;UfRcp*&front_9b7060()throw();};
struct UfVEDef2{int p0,p1,p2,p3;UfVEDef2();~UfVEDef2();void push_back_9b9d30(UfEntityDef*const&);bool empty_9b86e0()const throw();};
UfEntityDef*uf_randomRec_9d5d00(UfVEDef2&);void uf_shuffle_9d9fc0(UfVHE2&);
extern int uf_cf6464;
extern UfVStr2 uf_d1e900;extern bool uf_cefc88;struct UfShell{void addNew_90d550(const string&,const string&,int,int,int);};extern UfShell*uf_cec100;
bool uf_findByName_9d7de0(UfVAbil&,const string&,UfAbil**);extern UfVPt uf_d1ec20;extern UfVecU uf_d1ec30,uf_d1ec40;extern int uf_d1ec50;
struct UfVVStr{int p0,p1,p2,p3;UfVVStr();~UfVVStr();void push_back_9b2d50(const UfVStr2&);UfVStr2&back_9b5ac0()throw();UfVStr2&at_9b8070(unsigned)throw();};
struct UfWLS{int d0,d1,d2,d3,d4,d5,d6,d7,d8;UfWLS();~UfWLS();void add_9b9f50(string,int);string&pick_9b9fd0();};
int uf_indexOfPoint_9d53a0(UfVPt&,UfPoint);extern int uf_d1eb68;extern const unsigned uf_c2ea48;
void uf_appendVector_9d7f20(UfVPt&,UfVPt&);
void uf_appendVector_9d49c0(UfVHE2&,UfVHE&);struct UfArr2{int*at_9ceda0(int,int)throw();};
struct UfVVPt{int p0,p1,p2,p3;UfVPt&at_9b8070(unsigned)throw();};
extern UfVHE2 uf_d1ec00;extern UfVPt uf_d1ec10;extern int uf_d1ec54,uf_d1ec58;
bool uf_eraseZone_9d51d0(UfVZone&,UfZone*);
extern int uf_d1ec68;
extern UfPoint uf_d1ec6c;
extern UfVecU uf_cf47cc;
struct UfGM{void addItemAttachCount_778560(int,int,int);};extern UfGM uf_d25628;
void uf_shuffle_9d9fc0(UfVHI&);
struct UfJob2{int a[7];UfJob2(int,UfHE,const UfPoint&);};
void uf_fillInts_9e2be0(int*,int,int);
bool uf_anyNonZero_9d7f70(UfVecU&);
void uf_insert_9d8fc0(UfVHI&,unsigned,UfHI);
void uf_replaceAll_407f00(string&,string,string);
struct UfDiscord{void addComment_4f9f50(string);};extern UfDiscord*uf_cefb5c;
struct UfInvItem{void drawBar_4aa310();};struct UfInventory{void unknown8a54c0(UfHI,int);UfInvItem*unknown8a1fd0(UfHI,bool);};extern UfInventory*uf_cec08c;
extern UfItemDef*uf_cefbf0;
struct UfDial{int x0;int x4;bool b8;int xc;UfVPt v10;int x20;int x24;};extern UfDial uf_cf4a70;
extern UfRange uf_d386b8;extern UfRange uf_d30550;extern UfRange uf_d35b7c;extern UfRange uf_cf39cc;
float uf_angleBetween_40a680(const UfPoint&,const UfPoint&);
void uf_fn9d06d0(int*,int,int);
bool uf_angleInArc_4065d0(int,int,int);
struct UfRL{bool hasTypeFlagB_4565a0();};
extern const char uf_b91cd9[];extern const char uf_b91cda[];
int uf_indexOfEntity_9d3110(UfVHI&,UfHI);
struct UfVVecU{int p0,p1,p2,p3;void push_back_9e8d90(UfVecU&&);UfVecU&back_9b5ac0()throw();void pop_back_9b7610();};extern UfVVecU uf_cf6570;
struct UfVVPt2{int p0,p1,p2,p3;void push_back_9b5610(UfVPt&&);UfVPt&back_9b5ac0()throw();void pop_back_9b5880();};extern UfVVPt2 uf_cf6580;
extern UfWLI uf_d2ae08;extern UfRange uf_d2f130;extern int uf_cf4718;extern float uf_ba65d8[];
struct UfVHL{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfHL&at_9b81f0(unsigned)throw();};extern UfVHL uf_d1e88c;
int uf_indexOfName4_9d7b80(UfVTerr&,const string&);
extern string uf_cfaca0[];
struct UfQS{int turn;UfPoint p;int xc;int x10;};extern UfQS uf_cf65a8;
struct UfMsg{UfHE e;int x4;string s8;};struct UfVMsg{int p0,p1,p2,p3;unsigned size_9b9260()const throw();UfMsg*&at_9b81f0(unsigned)throw();};
void uf_deleteObjectAndStep_9d7fb0(UfVMsg&,unsigned&);
struct UfConvoy{int a;int b;int pad[8];};extern UfConvoy uf_b939c0[];extern int uf_ba6608[];
UfHI uf_popRandom_9d8030(UfVHI&);
extern UfWLI uf_d31700;
void uf_logWarning_404e50(string,string);
struct UfVIDefP{int p0,p1,p2,p3;UfVIDefP();~UfVIDefP();void push_back_9b9d30(UfItemDef*const&);unsigned size_9b9260()const throw();UfItemDef*&at_9b81f0(unsigned)throw();};
void uf_appendUnique_9d80a0(UfVPt&,UfVPt&);
extern UfVecU uf_d1eb9c;
extern int uf_caf43c;
struct UfItemRec{int d[13];UfItemRec(UfHI);};extern UfItemRec*uf_cf4ac8;extern UfVHI uf_d25860;
extern const float uf_ba780c;

int uf_stringToInt_405610(const string&);
int uf_distanceCeil_40a3f0(const UfPoint&,const UfPoint&);
void uf_message_49c610(int,UfHE,const string*,const UfPoint*);
void uf_playEffectPath_55ca70(int,struct UfVPt&,const UfPoint*);
bool uf_between_9daf80(int,int,int);
void uf_dummy(int)throw();
bool uf_show_5111e0b(int,const string*,const string*,const string*,UfHE,UfHE,const UfPoint*,int);
void uf_sound_4541b0(int,int,int);
bool uf_findByName_9d7530(struct UfVEDef&,const string&,struct UfEntityDef**);
void uf_clearDijkstra_4faf40();
bool uf_findNode_470180(int,int,int,UfHE*);
void uf_rotatePoint_501fc0(const UfPoint&,const UfPoint&,float,UfPoint*);
bool uf_fn9d3020(struct UfVPt&,UfPoint);
void uf_bresenham_40ff30(const UfPoint&,const UfPoint&,struct UfVPt&);
int uf_indexOfName_9d74d0(struct UfVIDef&,const string&);
bool uf_teambCheck_69d230();
void uf_prelearnData_797e60(const string&,int);
void uf_logPhrase_5141b0(int,const string*,const string*,int,UfHE,const UfPoint*);
bool uf_findByName_9d7390(struct UfVStatDef&,const string&,struct UfStatDef**);
void uf_showTransmission_8f58f0(UfHE,int);
void uf_openDecide_8f8680(UfHE,const string&);
string uf_intToString_4051f0(int);
void uf_surrounding_4faaf0(const UfPoint&,struct UfVPt*);
int uf_indexOfEntity_9d3110(struct UfVHE2&,UfHE);
void uf_moveElement_9da1f0b(struct UfVHE2&,int,int);
void uf_eraseStep_9d7300(struct UfVPt&,unsigned&);
bool uf_fn9d0ce0(struct UfVPt&,UfPoint);
UfPoint uf_randomPoint_9d5350(struct UfVPt&);
void uf_shuffle_9d7350(struct UfVPt&);
void uf_fn9d5460(struct UfVPt&,int,UfPoint);
bool uf_strEq_9ccb50(const string&,const char*);
void uf_logError_404f10(string,string);
void uf_shuffle_9d8f80(struct UfVZone&);
int uf_minInt_9cdb30(int,int)throw();
int uf_maxInt_9cdb60(int,int)throw();
void uf_playSoundNearest_55cc00(struct UfEff*,struct UfVPt&);
bool uf_collectProps_517ae0(int,struct UfVPt*,int,int,UfPoint*);
void uf_opR1d_454260(const UfPoint*,int);
bool uf_show_5111e0(int,const string*,const string*,const string*,UfHE,UfHE,const UfPoint&,int);
void uf_playMapEffect_55cb10(int,const UfPoint&);
bool uf_placeFootprint_51cd40(struct UfEff*,struct UfEntityDef*,UfHE,UfPoint*);
void uf_assignFollow_51caa0(struct UfEff*,UfHE,UfHE,UfHE);
void uf_moveElement_9da1f0(UfVHI&,int,int);
void uf_eraseStep_9d6440(UfVHI&,unsigned&);
void uf_playSound_55cb90(struct UfEff*,const UfPoint&);
void uf_playEffect_55ca10(int,const UfPoint&,const UfPoint*);
int uf_applyOperation_456a50(int,int,float,int,int);
void uf_fn51d880(UfHE,UfHP,UfHI,const UfPoint*,UfVHI*);
void uf_eraseAt_9da940(UfVHI&,int);
void uf_fn51d5e0(UfHP,UfVecU2,bool);
void uf_fn51d730(UfHI,UfVecU2,bool);
void uf_fn51d5e0(UfHP,UfVecU,bool);
void uf_fn51d730(UfHI,UfVecU,bool);

#define CELLAT(P) (*uf_cfd44c.atPoint_9ced70(P))
#define ENTX (entity.isValid_9b7230() ? entity : prop.isValid_9b7230() ? CELLAT(prop.get_9b64f0()->pos_4184d0())->getEntity_45d250() : item.isValid_9b7230() ? CELLAT(item.get_9b65b0()->pos_575920())->getEntity_45d250() : pos ? CELLAT(*pos)->getEntity_45d250() : CELLAT(UfPoint(0))->getEntity_45d250())
#define PROPX (prop.isValid_9b7230() ? prop : entity.isValid_9b7230() ? CELLAT(entity.get_9b6570()->pos_45a4c0())->getProp_45d550() : item.isValid_9b7230() ? CELLAT(item.get_9b65b0()->pos_575920())->getProp_45d550() : pos ? CELLAT(*pos)->getProp_45d550() : CELLAT(UfPoint(0))->getProp_45d550())
#define PTX (entity.isValid_9b7230() ? entity.get_9b6570()->pos_45a4c0() : prop.isValid_9b7230() ? prop.get_9b64f0()->pos_4184d0() : item.isValid_9b7230() ? item.get_9b65b0()->pos_575920() : pos ? *pos : UfPoint(0))
#define POSX (pos ? *pos : entity.isValid_9b7230() ? entity.get_9b6570()->pos_45a4c0() : prop.isValid_9b7230() ? prop.get_9b64f0()->pos_4184d0() : item.isValid_9b7230() ? item.get_9b65b0()->pos_575920() : UfPoint(0))

#define FXCELL(c) UfCell *c = CELLAT(POSX); uf_message_49c610(eff->x28,UfHE(),&c->unknown45d140(),&c->pos_45d1a0()); uf_playEffect_55ca10(eff->x34,c->pos_45d1a0(),0); uf_playSound_55cb90(eff,c->pos_45d1a0());
#define FXPROP(p) UfHP p = PROPX; if (!p.get_9b64f0()) goto nextEff; uf_message_49c610(eff->x28,UfHE(),&p.get_9b64f0()->getName_45c5b0(),&p.get_9b64f0()->pos_4184d0()); uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0); uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
#define FXENT(e) UfHE e = ENTX; if (!e.get_9b6570()) goto nextEff; uf_message_49c610(eff->x28,e,0,0); uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0); uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
#define FXITEMS(l) UfVHI l; if (uf_cebc50) l = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&l); if (l.empty_9b86e0()) goto nextEff; }
#define FXITEM(l,m) uf_message_49c610(eff->x28,UfHE(),&l.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),&l.at_9b81f0(m).get_9b65b0()->pos_575920()); uf_playEffect_55ca10(eff->x34,l.at_9b81f0(m).get_9b65b0()->pos_575920(),0); uf_playSound_55cb90(eff,l.at_9b81f0(m).get_9b65b0()->pos_575920());

#define UF_ALERT(text) do { uf_cf1080.set_451400(true); if (true && !(uf_d28fb0 && true && true)) uf_sound_4541b0(0x127,0,0); do { if (uf_show_5111e0b(0x324,&string(text),0,0,UfHE(),UfHE(),0,0)) uf_cec058->bubble_8758d0(true); uf_cec0b4->scrollToEnd_7b4f10(); } while (false); uf_cec0b4->scrollToEnd_7b4f10(); } while (false);
#define UF_ALERTP(p) do { uf_cf1080.set_451400(true); if (true && !(uf_d28fb0 && true && true)) uf_sound_4541b0(0x127,0,0); do { if (uf_show_5111e0b(0x324,p,0,0,UfHE(),UfHE(),0,0)) uf_cec058->bubble_8758d0(true); uf_cec0b4->scrollToEnd_7b4f10(); } while (false); uf_cec0b4->scrollToEnd_7b4f10(); } while (false);

struct UfBS
{
	static bool turnUpdate_51da30(UfVRec *records, int type, UfHE entity, UfHP prop, UfHI item, const UfPoint *pos, int flag);
};

bool UfBS::turnUpdate_51da30(UfVRec *records, int type, UfHE entity, UfHP prop, UfHI item, const UfPoint *pos, int flag)
{
	if (entity.isValid_9b7230() && !entity.get_9b6570())
		return false;
	if (prop.isValid_9b7230() && !prop.get_9b64f0())
		return false;
	if (item.isValid_9b7230() && !item.get_9b65b0())
		return false;
	uf_d2ac98.clear_9bac80();
	for (unsigned i = 0; i < records->size_9b9260(); i++)
	{
		if (records->at_9b81f0(i)->def->type == type)
		{
			UfDef *defVal = records->at_9b81f0(i)->def;
			if (flag == 0 && records->at_9b81f0(i)->e.get_9b6570())
			{
				uf_message_49c610(defVal->x64,records->at_9b81f0(i)->e,records->at_9b81f0(i)->g,0);
				uf_playEffectPath_55ca70(defVal->x68,records->at_9b81f0(i)->e.get_9b6570()->path_45d1a0(),0);
			}
			int k = 0;
			int first7 = -1;
			int last = -1;
			UfVecU a8;
			bool aC = false;
			int nPass = 0;
			int a1 = 0;
			int aI = 0;
			int prev = 0;
			for (; k < defVal->effects.size_9b9260(); k++)
			{
				if (aC)
				{
					k = last + 1;
					aC = false;
					if (k >= defVal->effects.size_9b9260())
						break;
				}
				UfEff *eff = defVal->effects.at_9b81f0(k);
				if (entity.isValid_9b7230() && !entity.get_9b6570() || prop.isValid_9b7230() && !prop.get_9b64f0() || item.isValid_9b7230() && !item.get_9b65b0())
					return !uf_d2ac98.empty_9b86e0();
				if (eff->weight && k > last)
				{
					if (first7 != -1)
					{
						a8.clear_9bac80();
						aC = false;
					}
					first7 = last = k;
					while (last + 1 < defVal->effects.size_9b9260() && defVal->effects.at_9b81f0(last + 1)->weight)
						last++;
				}
				bool aa = false;
				if (uf_ba634c[eff->type] && !records->at_9b81f0(i)->e.get_9b6570())
					aa = true;
				else
				{
					switch (eff->mode)
					{
						break;
						case 1:
							if (nPass == 0) { aa = true; goto done; }
							else break;
						case 2:
							if (nPass != aI) { aa = true; goto done; }
							else break;
						case 3:
							if (prev == 0) { aa = true; goto done; }
							else break;
						case 4:
							if (a1 == 0) { aa = true; goto done; }
							else break;
						case 5:
							if (a1 != aI) { aa = true; goto done; }
							else break;
						case 6:
							if (prev != 0) { aa = true; goto done; }
					}
					UfVCond &conds = eff->conds;
					uf_cebc50 = false;
					for (int j = 0; j < conds.size_9b7020(); j++)
					{
						switch (conds.at_9b7040(j).type)
						{
					case 0:
						if (conds.at_9b7040(j).compareInt_455e00(rng.rangeInt_406d70(1,100))) goto pass;
						break;
					case 1:
						if (conds.at_9b7040(j).compareString_455f40(uf_d1e860.getEntryText_46f6d0(conds.at_9b7040(j).key))) goto pass;
						break;
					case 2:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->getTurn_464270())) goto pass;
						break;
					case 3:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->unknown4642d0())) goto pass;
						break;
					case 4:
						if (conds.at_9b7040(j).compareString_455f40(uf_cfe140[uf_d1e888.get_9b7910()->type])) goto pass;
						break;
					case 5:
						if (conds.at_9b7040(j).compareString_455f40(uf_d312f0[uf_b90000[uf_d1e888.get_9b7910()->type]])) goto pass;
						break;
					case 6:
						if (conds.at_9b7040(j).compareInt_455e00(uf_d1e888.get_9b7910()->depth)) goto pass;
						break;
					case 7:
					{
						bool flag = false;
						if (entity.isValid_9b7230())
							flag = uf_stringToInt_405610(conds.at_9b7040(j).key) <= 1 ? uf_cefc4c->unknown463400(entity) && (uf_stringToInt_405610(conds.at_9b7040(j).key) == 0 || entity.get_9b6570()->ai_45b590()->getEntity_459570(uf_cefc4c->getPlayer_4630f0())) : uf_cefc4c->unknown4631f0(entity);
						else if (prop.isValid_9b7230())
							flag = uf_stringToInt_405610(conds.at_9b7040(j).key) <= 1 ? uf_cefc4c->unknown4633c0(prop.get_9b64f0()->pos_4184d0()) : uf_cefc4c->isVisible_4631c0(prop.get_9b64f0()->pos_4184d0());
						else if (item.isValid_9b7230())
							flag = uf_stringToInt_405610(conds.at_9b7040(j).key) <= 1 ? uf_cefc4c->unknown4633c0(item.get_9b65b0()->pos_575920()) : uf_cefc4c->isVisible_4631c0(item.get_9b65b0()->pos_575920());
						else if (pos)
							flag = uf_stringToInt_405610(conds.at_9b7040(j).key) <= 1 ? uf_cefc4c->unknown4633c0(*pos) : uf_cefc4c->isVisible_4631c0(*pos);
						if (conds.at_9b7040(j).compareInt_455e00(flag != 0)) goto pass;
						break;
					}
					case 8:
					{
						bool found = false;
						int data = uf_stringToInt_405610(conds.at_9b7040(j).key);
						int group = data / 50000;
						int range = data % 50000 / 1000;
						int event = data % 1000;
						UfPoint v(entity.isValid_9b7230() ? entity.get_9b6570()->getPosition_45a4a0() : prop.isValid_9b7230() ? prop.get_9b64f0()->pos_4184d0() : item.isValid_9b7230() ? item.get_9b65b0()->pos_575920() : *pos);
						UfVHE &members = uf_cefc4c->group_463890(group).get_9b7250()->members_416f40();
						for (unsigned m = 0; m < members.size_9b9260(); m++)
						{
							if (members.at_9b81f0(m).get_9b6570()->unknown45ac40(event) && uf_distanceCeil_40a3f0(v,members.at_9b81f0(m).get_9b6570()->getPosition_45a4a0()) <= range && uf_cefc4c->isReachable_465230(range,v,members.at_9b81f0(m).get_9b6570()->getPosition_45a4a0()))
							{
								found = true;
								break;
							}
						}
						if (conds.at_9b7040(j).compareInt_455e00(found != 0)) goto pass;
						break;
					}
					case 9:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cf6428.unknown45edd0(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
						break;
					case 10:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->unknown715b10())) goto pass;
						break;
					case 11:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cbdf0(uf_stringToInt_405610(conds.at_9b7040(j).key),false,false) != 0)) goto pass;
						break;
					case 12:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cbdf0(uf_stringToInt_405610(conds.at_9b7040(j).key),true,true) != 0)) goto pass;
						break;
					case 13:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->group_463890(uf_stringToInt_405610(conds.at_9b7040(j).key)).get_9b7250()->count_44afb0())) goto pass;
						break;
					case 14:
						if (conds.at_9b7040(j).compareInt_455e00(uf_cefc4c->unknown463710())) goto pass;
						break;
					case 15:
						if (conds.at_9b7040(j).compareInt_455e00((uf_d25664 == conds.at_9b7040(j).key) != 0)) goto pass;
						break;
					case 25:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(ent.get_9b6570()->getName_45a280())) goto pass;
							break;
						}
					case 26:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(ent.get_9b6570()->def_9b4350()->name1ac)) goto pass;
							break;
						}
					case 27:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(ent.get_9b6570()->getName_416f40())) goto pass;
							break;
						}
					case 28:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(uf_cfd458[ent.get_9b6570()->def_9b4350()->x24])) goto pass;
							break;
						}
					case 29:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(uf_d2f798[ent.get_9b6570()->def_9b4350()->x28])) goto pass;
							break;
						}
					case 30:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->def_9b4350()->x9c)) goto pass;
							break;
						}
					case 31:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5c8cb0())) goto pass;
							break;
						}
					case 32:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->getTarget_45a760() == 0)) goto pass;
							break;
						}
					case 33:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(uf_caf1f8[ent.get_9b6570()->getTarget_45a760()])) goto pass;
							break;
						}
					case 34:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareString_455f40(uf_d01860[ent.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350()])) goto pass;
							break;
						}
					case 35:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5c7fa0())) goto pass;
							break;
						}
					case 36:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5cb680(uf_cefc4c->group_463890(uf_stringToInt_405610(conds.at_9b7040(j).key))))) goto pass;
							break;
						}
					case 37:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
														if (ent.get_9b6570()->ai_45b590() && conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->ai_45b590()->unknown458f30())) goto pass;
							break;
						}
					case 38:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
														if (ent.get_9b6570()->ai_45b590() && conds.at_9b7040(j).compareString_455f40(uf_d31db8[ent.get_9b6570()->ai_45b590()->id_9b8f00()])) goto pass;
							break;
						}
					case 39:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5c9b10())) goto pass;
							break;
						}
					case 40:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5cbb10())) goto pass;
							break;
						}
					case 41:
					case 42:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							UfVHI &list3 = *ent.get_9b6570()->getInventoryList_45ab00();
							for (unsigned m = 0; m < list3.size_9b9260(); m++)
							{
								if (list3.at_9b81f0(m).get_9b65b0()->getType_44aec0() <= 3 && list3.at_9b81f0(m).get_9b65b0()->unknown457d70() && conds.at_9b7040(j).compareString_455f40(list3.at_9b81f0(m).get_9b65b0()->name_457970()))
								{
									if (conds.at_9b7040(j).type == 0x2a)
										list3.at_9b81f0(m).get_9b65b0()->remove_57dbe0(ent.eq_9b78e0(uf_cefc4c->getPlayer_4630f0()),0,1,1);
									goto pass;
								}
							}
							break;
						}
					case 43:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							UfVHI &list5 = *ent.get_9b6570()->getInventoryList_45ab00();
							for (unsigned m = 0; m < list5.size_9b9260(); m++)
							{
								if (conds.at_9b7040(j).compareString_455f40(list5.at_9b81f0(m).get_9b65b0()->name_457970())) goto pass;
							}
							break;
						}
					case 44:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45a920())) goto pass;
							break;
						}
					case 45:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5ca670())) goto pass;
							break;
						}
					case 46:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45a940())) goto pass;
							break;
						}
					case 47:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45a8d0())) goto pass;
							break;
						}
					case 48:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5ca400())) goto pass;
							break;
						}
					case 49:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45a8f0())) goto pass;
							break;
						}
					case 50:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->getField_490840())) goto pass;
							break;
						}
					case 51:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5ca260())) goto pass;
							break;
						}
					case 52:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45a880())) goto pass;
							break;
						}
					case 53:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5ca260() - ent.get_9b6570()->getField_490840())) goto pass;
							break;
						}
					case 54:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown5cab90())) goto pass;
							break;
						}
					case 55:
						{
							UfHE a5 = ENTX;
							if (!a5.get_9b6570())
								break;
							UfVHI &list = *a5.get_9b6570()->getInventoryList_45ab00();
							int val = uf_stringToInt_405610(conds.at_9b7040(j).key);
							for (unsigned m = 0; m < list.size_9b9260(); m++)
							{
								if (list.at_9b81f0(m).get_9b65b0()->getType_44aec0() <= 3 && list.at_9b81f0(m).get_9b65b0()->getNestedField_457820() == val && conds.at_9b7040(j).compareInt_455e00(list.at_9b81f0(m).get_9b65b0()->unknown457ca0())) goto pass;
							}
							break;
						}
					case 56:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45acb0(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
							break;
						}
					case 57:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							if (conds.at_9b7040(j).compareInt_455e00(ent.get_9b6570()->unknown45adb0(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
							break;
						}
					case 58:
						{
							UfHE aE = ENTX;
							if (!aE.get_9b6570())
								break;
							UfVHE &list = uf_cefc4c->group_463890(uf_stringToInt_405610(conds.at_9b7040(j).key)).get_9b7250()->members_416f40();
							int best = 9999;
							int dist;
							for (unsigned m = 0; m < list.size_9b9260(); m++)
							{
								if (!list.at_9b81f0(m).get_9b6570()->getTarget_45a760())
								{
									dist = uf_distanceCeil_40a3f0(aE.get_9b6570()->pos_45a4c0(),list.at_9b81f0(m).get_9b6570()->pos_45a4c0());
									if (dist < best)
										best = dist;
								}
							}
							if (conds.at_9b7040(j).compareInt_455e00(best)) goto pass;
							break;
						}
					case 59:
						{
							UfHE ent = ENTX;
							if (!ent.get_9b6570())
								break;
							int mode = uf_stringToInt_405610(conds.at_9b7040(j).key);
							if (mode == 0 || mode == 1 && uf_cefc4c->isVisible_4631c0(ent.get_9b6570()->getPosition_45a4a0()) || mode == 2 && !uf_cefc4c->isVisible_4631c0(ent.get_9b6570()->getPosition_45a4a0()))
							{
								if (conds.at_9b7040(j).compareInt_455e00(uf_distanceCeil_40a3f0(ent.get_9b6570()->getPosition_45a4a0(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->pos_45a4c0()))) goto pass;
							}
							break;
						}
					case 60:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareString_455f40(p.get_9b64f0()->location_45c590())) goto pass;
						break;
					}
					case 61:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareString_455f40(p.get_9b64f0()->getName_45c5b0())) goto pass;
						break;
					}
					case 62:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareInt_455e00(p.get_9b64f0()->getNestedField_45c630())) goto pass;
						break;
					}
					case 63:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareString_455f40(p.get_9b64f0()->def_9b8f00()->info->name)) goto pass;
						break;
					}
					case 64:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareInt_455e00(p.get_9b64f0()->unknown45c870(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
						break;
					}
					case 65:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (conds.at_9b7040(j).compareInt_455e00(p.get_9b64f0()->unknown45ca00(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
						break;
					}
					case 66:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						UfVHE &list = uf_cefc4c->group_463890(uf_stringToInt_405610(conds.at_9b7040(j).key)).get_9b7250()->members_416f40();
						int best = 9999;
						int dist;
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							if (!list.at_9b81f0(m).get_9b6570()->getTarget_45a760())
							{
								dist = uf_distanceCeil_40a3f0(p.get_9b64f0()->pos_4184d0(),list.at_9b81f0(m).get_9b6570()->pos_45a4c0());
								if (dist < best)
									best = dist;
							}
						}
						if (conds.at_9b7040(j).compareInt_455e00(best)) goto pass;
						break;
					}
					case 67:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						UfVHE &list = uf_cefc4c->group_463890(uf_stringToInt_405610(conds.at_9b7040(j).key)).get_9b7250()->members_416f40();
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							if (!list.at_9b81f0(m).get_9b6570()->getTarget_45a760() && conds.at_9b7040(j).compareInt_455e00(uf_distanceCeil_40a3f0(p.get_9b64f0()->pos_4184d0(),list.at_9b81f0(m).get_9b6570()->pos_45a4c0())) && uf_cefc4c->unknown465200(p.get_9b64f0()->pos_4184d0(),list.at_9b81f0(m).get_9b6570()->pos_45a4c0())) goto pass;
						}
						break;
					}
					case 68:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						UfVHG &groups = *uf_cefc4c->groups_463950();
						int faction = uf_cefc4c->group_463890(3).get_9b7250()->id_9b8f00();
						for (unsigned m = 0; m < groups.size_9b9260(); m++)
						{
							if (!uf_cefc4c->unknown4638e0(groups.at_9b81f0(m).get_9b7250()->id_9b8f00(),faction))
							{
								UfVHE &list = groups.at_9b81f0(m).get_9b7250()->members_416f40();
								for (unsigned n = 0; n < list.size_9b9260(); n++)
								{
									if (!list.at_9b81f0(n).get_9b6570()->getTarget_45a760() && conds.at_9b7040(j).compareInt_455e00(uf_distanceCeil_40a3f0(p.get_9b64f0()->pos_4184d0(),list.at_9b81f0(n).get_9b6570()->pos_45a4c0())) && (uf_stringToInt_405610(conds.at_9b7040(j).key) == 0 || uf_stringToInt_405610(conds.at_9b7040(j).key) && uf_cefc4c->unknown465200(p.get_9b64f0()->pos_4184d0(),list.at_9b81f0(n).get_9b6570()->pos_45a4c0()))) goto pass;
								}
							}
						}
						break;
					}
					case 69:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							break;
						if (p.isValid_9b7230() && (uf_stringToInt_405610(conds.at_9b7040(j).key) == 0 || uf_stringToInt_405610(conds.at_9b7040(j).key) && uf_cefc4c->isVisible_4631c0(p.get_9b64f0()->pos_4184d0())) && conds.at_9b7040(j).compareInt_455e00(uf_distanceCeil_40a3f0(p.get_9b64f0()->pos_4184d0(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->pos_45a4c0()))) goto pass;
						break;
					}
					case 70:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (!conds.at_9b7040(j).compareString_455f40(uf_d32edc.at_9b81f0(m).get_9b65b0()->name_457860()))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 71:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (!conds.at_9b7040(j).compareString_455f40(uf_d32edc.at_9b81f0(m).get_9b65b0()->name_457970()))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 72:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (!conds.at_9b7040(j).compareInt_455e00(uf_d32edc.at_9b81f0(m).get_9b65b0()->trap_9b6bf0()))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 73:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (!conds.at_9b7040(j).compareInt_455e00(uf_d32edc.at_9b81f0(m).get_9b65b0()->getEffectValue_457be0(uf_stringToInt_405610(conds.at_9b7040(j).key))))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 74:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (!conds.at_9b7040(j).compareInt_455e00(uf_d32edc.at_9b81f0(m).get_9b65b0()->unknown457c50(uf_stringToInt_405610(conds.at_9b7040(j).key))))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 75:
						if (!uf_cebc50)
						{
							uf_d32edc.clear_9b73d0();
							uf_fn51d880(entity,prop,item,pos,&uf_d32edc);
							uf_cebc50 = true;
							if (uf_d32edc.empty_9b86e0())
								break;
						}
						for (int m = uf_d32edc.size_9b9260() - 1; m >= 0; m--)
						{
							if (uf_d32edc.at_9b81f0(m).get_9b65b0()->unknown457b50().isNull_9b65d0() || !conds.at_9b7040(j).compareString_455f40(uf_d32edc.at_9b81f0(m).get_9b65b0()->unknown457b50().get_9b6570()->getName_45a280()))
								uf_eraseAt_9da940(uf_d32edc,m);
						}
						if (uf_d32edc.empty_9b86e0())
							break;
						goto pass;
					case 76:
						if (false) {} if (false) {} if (false) {}	// NOTE: zero-code idiom: keeps this case's jump-table entry on its own break jmp (exe +67fe); three keep the eax/ecx/edx rotation unchanged
						break;
					case 77:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareString_455f40(cell->unknown45d100())) goto pass;
						break;
					}
					case 78:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareString_455f40(cell->unknown45d120())) goto pass;
						break;
					}
					case 79:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->getArmor_66ae70())) goto pass;
						break;
					}
					case 80:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareString_455f40(cell->def_9fcd80()->info->name)) goto pass;
						break;
					}
					case 81:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->getItem_45d8f0().isValid_9b7230() != 0)) goto pass;
						break;
					}
					case 82:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->getField_4550b0() != 0)) goto pass;
						break;
					}
					case 83:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->isPassableFor_66ab30(UfHE()) != 0)) goto pass;
						break;
					}
					case 84:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->getEntity_45d250().isValid_9b7230() != 0)) goto pass;
						break;
					}
					case 85:
					{
						UfCell *cell = CELLAT(POSX);
						if (conds.at_9b7040(j).compareInt_455e00(cell->getEffectValue_45d3c0(uf_stringToInt_405610(conds.at_9b7040(j).key)))) goto pass;
						break;
					}

						}
						if (eff->jumps.at_9b81f0(j) != j + 1)
							continue;
						else
						{
							aa = true;
							break;
						}
					pass:
						j = eff->jumps.at_9b81f0(j) - 1;
					}
				}
			done:
				if (uf_between_9daf80(first7,k,last))
				{
					if (!aa && uf_d1e8f0.at_9b8070(defVal->id).at_9b81f0(k) == 0)
						a8.push_back_9b9d30(k);
					if (k == last)
					{
						aI++;
						if (a8.empty_9b86e0())
						{
							a1++;
							prev = 0;
							continue;
						}
						else
						{
							nPass++;
							prev = 1;
							int b5 = 0;
							for (unsigned m = 0; m < a8.size_9b9260(); m++)
								b5 += defVal->effects.at_9b81f0(a8.at_9b81f0(m))->weight;
							int roll = rng.rangeInt_406d70(1,b5);
							for (unsigned n = 0; n < a8.size_9b9260(); n++)
							{
								roll -= defVal->effects.at_9b81f0(a8.at_9b81f0(n))->weight;
								if (roll <= 0)
								{
									k = a8.at_9b81f0(n);
									eff = defVal->effects.at_9b81f0(k);
									if (eff->once)
										uf_d1e8f0.at_9b8070(defVal->id).at_9b81f0(k) = 1;
									aC = true;
									break;
								}
							}
						}
					}
					else
						continue;
				}
				else if (aa)
				{
					a1++;
					aI++;
					prev = 0;
					continue;
				}
				else
				{
					nPass++;
					aI++;
					prev = 1;
				}
				switch (eff->type)
				{
					case 0:
						if (entity.isValid_9b7230())
						{
							UfPoint p = entity.get_9b6570()->pos_45a4c0();
							uf_message_49c610(eff->x28,UfHE(),&entity.get_9b6570()->getName_416f40(),&p);
							uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),uf_cfd2cc.at_9b81f0(eff->x50),p,UfHE(),UfPoint(-1),UfPoint(-1))));
						}
						else if (prop.isValid_9b7230())
						{
							uf_message_49c610(eff->x28,UfHE(),&prop.get_9b64f0()->getName_45c5b0(),&prop.get_9b64f0()->pos_4184d0());
							uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),uf_cfd2cc.at_9b81f0(eff->x50),prop.get_9b64f0()->pos_4184d0(),UfHE(),UfPoint(-1),UfPoint(-1))));
						}
						else if (item.isValid_9b7230())
						{
							uf_message_49c610(eff->x28,UfHE(),&item.get_9b65b0()->getName_571db0(0,0),&item.get_9b65b0()->pos_575920());
							uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),uf_cfd2cc.at_9b81f0(eff->x50),item.get_9b65b0()->pos_575920(),UfHE(),UfPoint(-1),UfPoint(-1))));
						}
						else
						{
							uf_message_49c610(eff->x28,UfHE(),&CELLAT(*pos)->unknown45d140(),pos);
							uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),uf_cfd2cc.at_9b81f0(eff->x50),*pos,UfHE(),UfPoint(-1),UfPoint(-1))));
						}
						break;
					case 1:
					case 2:
					case 3:
					case 4:
					{
						UfCell *ct;
						UfHE ent;
						UfHP a3;
						UfVHI items;
						switch (eff->type)
						{
							case 1:
								ent = ENTX;
								if (!ent.get_9b6570())
									goto nextEff;
								uf_message_49c610(eff->x28,ent,0,0);
								uf_playEffectPath_55ca70(eff->x34,ent.get_9b6570()->path_45d1a0(),0);
								uf_playSound_55cb90(eff,ent.get_9b6570()->pos_45a4c0());
								goto ops;
							case 2:
								a3 = PROPX;
								if (!a3.get_9b64f0())
									goto nextEff;
								uf_message_49c610(eff->x28,UfHE(),&a3.get_9b64f0()->getName_45c5b0(),&a3.get_9b64f0()->pos_4184d0());
								uf_playEffect_55ca10(eff->x34,a3.get_9b64f0()->pos_4184d0(),0);
								uf_playSound_55cb90(eff,a3.get_9b64f0()->pos_4184d0());
								goto ops;
							case 3:
							{
								UfVHI list;
								if (uf_cebc50)
									list = uf_d32edc;
								else
								{
									uf_fn51d880(entity,prop,item,pos,&list);
									if (list.empty_9b86e0())
										goto nextEff;
								}
								for (unsigned m = 0; m < list.size_9b9260(); m++)
								{
									uf_playEffect_55ca10(eff->x34,list.at_9b81f0(m).get_9b65b0()->pos_575920(),0);
									uf_message_49c610(eff->x28,UfHE(),&list.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),&list.at_9b81f0(m).get_9b65b0()->pos_575920());
									uf_playSound_55cb90(eff,list.at_9b81f0(m).get_9b65b0()->pos_575920());
								}
								items = list;
								goto ops;
							}
							case 4:
								ct = CELLAT(POSX);
								uf_message_49c610(eff->x28,UfHE(),&ct->unknown45d140(),&ct->pos_45d1a0());
								uf_playEffect_55ca10(eff->x34,ct->pos_45d1a0(),0);
								uf_playSound_55cb90(eff,ct->pos_45d1a0());
							ops:
								switch (eff->x54)
						{
							case 0:
								if (ent.isValid_9b7230())
								{
									switch (eff->range5c.y)
									{
										case 0:
											ent.get_9b6570()->unknown5fd900(8,0);
											break;
										case 1:
											ent.get_9b6570()->unknown5fdab0();
											if (ent.get_9b6570()->ai_45b590() && !ent.get_9b6570()->ai_45b590()->id_9b8f00())
												ent.get_9b6570()->setAI_64ecf0(new UfEntityAI(ent,0x22,0xe));
											break;
										case 2:
											ent.get_9b6570()->unknown5fd900(6,0);
											break;
										case 3:
											ent.get_9b6570()->unknown5fd900(2,0);
											break;
										case 4:
											ent.get_9b6570()->unknown5fd900(4,9999999);
											break;
										default:
											ent.get_9b6570()->unknown5fd900(4,eff->range5c.randomInRange_40c130());
									}
								}
								else
								{
									switch (eff->range5c.y)
									{
										case 0:
											a3.get_9b64f0()->disableMachine_65ed00();
									}
								}
								break;
							case 1:
								if (eff->x58 == 0)
									ent.get_9b6570()->unknown5deb40(eff->range5c.randomInRange_40c130());
								else
									ent.get_9b6570()->unknown45b240(uf_applyOperation_456a50(ent.get_9b6570()->unknown45a920(),eff->x58,eff->range5c.randomInRange_40c130(),0,-1));
								break;
							case 2:
								if (eff->x58 == 0)
									ent.get_9b6570()->unknown5ded70(eff->range5c.randomInRange_40c130());
								else
									ent.get_9b6570()->unknown45b270(uf_applyOperation_456a50(ent.get_9b6570()->unknown45a8d0(),eff->x58,eff->range5c.randomInRange_40c130(),0,-1));
								break;
							case 3:
							{
								int m = 0;
								do
								{
									int op = eff->x58;
									float amt = eff->range5c.randomInRange_40c130();
									int newCur = ent.isValid_9b7230() ? ent.get_9b6570()->getField_490840() : items.at_9b81f0(m).get_9b65b0() ? items.at_9b81f0(m).get_9b65b0()->trap_9b6bf0() : 1;
									if (op == 3)
									{
										op = 1;
										amt = newCur - newCur / amt;
									}
									else if (op == 2)
									{
										op = 0;
										amt = newCur * amt - newCur;
									}
									if (op == 1)
									{
										if (ent.isValid_9b7230())
											ent.get_9b6570()->unknown637d10(eff,amt);
										else if (items.at_9b81f0(m).get_9b65b0())
											items.at_9b81f0(m).get_9b65b0()->unknown57beb0(eff,amt);
									}
									else
									{
										if (ent.isValid_9b7230())
											ent.get_9b6570()->unknown5dea60(uf_applyOperation_456a50(newCur,op,amt,0,-1),0);
										else if (items.at_9b81f0(m).get_9b65b0())
											items.at_9b81f0(m).get_9b65b0()->set_450460(uf_applyOperation_456a50(newCur,op,amt,0,items.at_9b81f0(m).get_9b65b0()->unknown457c80()));
									}
								}
								while (++m < items.size_9b9260());
								break;
							}
							case 4:
								ent.get_9b6570()->setField_4514c0(uf_applyOperation_456a50(ent.get_9b6570()->unknown45a990(),eff->x58,eff->range5c.randomInRange_40c130(),ent.get_9b6570()->unknown5cab30(),-1));
								break;
							case 5:
								if (eff->x58 == 0)
									ent.get_9b6570()->unknown5defa0(eff->range5c.randomInRange_40c130(),1);
								else
									ent.get_9b6570()->set_44e2c0(uf_applyOperation_456a50(ent.get_9b6570()->unknown45a9d0(),eff->x58,eff->range5c.randomInRange_40c130(),0,-1));
								break;
							case 6:
								ent.get_9b6570()->setField_4514e0(uf_applyOperation_456a50(ent.get_9b6570()->unknown45a9f0(),eff->x58,eff->range5c.randomInRange_40c130(),-1,-1));
								break;
							case 7:
								if (a3.get_9b64f0()->unknown45cad0())
									a3.get_9b64f0()->setSoundMute_65f320(eff->range5c.randomInRange_40c130() != 0);
								break;
							case 8:
							{
								int n = 0;
								do
								{
									UfFx *fx = ent.isValid_9b7230() ? ent.get_9b6570()->unknown45ac40(eff->x118) : a3.isValid_9b7230() ? a3.get_9b64f0()->unknown45c800(eff->x118) : !items.empty_9b86e0() ? items.at_9b81f0(n).get_9b65b0()->getEffect_457b70(eff->x118) : ct->getEffect_45d350(eff->x118);
									switch (eff->x58)
									{
										case 0:
											if (fx)
												fx->value += eff->range5c.randomInRange_40c130();
											else
											{
											addNew:
												if (ent.isValid_9b7230())
													ent.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(eff->x118),eff->range5c.randomInRange_40c130()));
												else if (a3.isValid_9b7230())
													a3.get_9b64f0()->unknown45cee0(new UfFx(uf_d2f0f8.at_9b81f0(eff->x118),eff->range5c.randomInRange_40c130()));
												else if (!items.empty_9b86e0())
												{
													if (items.at_9b81f0(n).get_9b65b0())
														items.at_9b81f0(n).get_9b65b0()->addEffect_4585a0(new UfFx(uf_d2f0f8.at_9b81f0(eff->x118),eff->range5c.randomInRange_40c130()));
												}
												else
													ct->unknown45df90(new UfFx(uf_d2f0f8.at_9b81f0(eff->x118),eff->range5c.randomInRange_40c130()));
											}
											break;
										case 1:
										case 3:
											if (fx)
											{
												int amt = eff->x58 == 1 ? eff->range5c.randomInRange_40c130() : fx->value == 1 ? 1 : fx->value / 2;
												fx->value -= amt;
												if (fx->value <= 0)
												{
												remove:
													if (ent.isValid_9b7230())
														ent.get_9b6570()->unknown45b3d0(fx);
													else if (a3.isValid_9b7230())
														a3.get_9b64f0()->unknown45cf00(fx);
													else if (!items.empty_9b86e0())
													{
														if (items.at_9b81f0(n).get_9b65b0())
															items.at_9b81f0(n).get_9b65b0()->unknown458630(fx);
													}
													else
														ct->remove_45e020(fx);
												}
											}
											break;
										case 2:
											if (fx)
												fx->value *= eff->range5c.randomInRange_40c130();
											break;
										case 4:
											if (eff->range5c.x || eff->range5c.y)
											{
												if (fx)
													fx->value = eff->range5c.randomInRange_40c130();
												else
													goto addNew;
											}
											else if (fx)
												goto remove;
									}
								}
								while (++n < items.size_9b9260());
								break;
							}
						}
						}
						break;
					}
					case 5:
					{
						UfCell *cell = CELLAT(POSX); uf_message_49c610(eff->x28,UfHE(),&cell->unknown45d140(),&cell->pos_45d1a0()); uf_playEffect_55ca10(eff->x34,cell->pos_45d1a0(),0); uf_playSound_55cb90(eff,cell->pos_45d1a0());
						cell->unknown670150(eff);
						break;
					}
					case 6:
					{
						UfHP p = PROPX; if (!p.get_9b64f0()) goto nextEff; uf_message_49c610(eff->x28,UfHE(),&p.get_9b64f0()->getName_45c5b0(),&p.get_9b64f0()->pos_4184d0()); uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0); uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
						p.get_9b64f0()->unknown665860(eff);
						break;
					}
					case 7:
					{
						UfHE e = ENTX; if (!e.get_9b6570()) goto nextEff; uf_message_49c610(eff->x28,e,0,0); uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0); uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						e.get_9b6570()->die_633790(0,eff->x6c,UfHE(),1,0,0,0,0);
						break;
					}
					case 8:
					{
						UfHE e = ENTX; if (!e.get_9b6570()) goto nextEff; uf_message_49c610(eff->x28,e,0,0); uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0); uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						e.get_9b6570()->unknown637bb0();
						break;
					}
					case 9:
					{
						UfHP p = PROPX; if (!p.get_9b64f0()) goto nextEff; uf_message_49c610(eff->x28,UfHE(),&p.get_9b64f0()->getName_45c5b0(),&p.get_9b64f0()->pos_4184d0()); uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0); uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
						p.get_9b64f0()->unknown45ce10(eff->bE9,0,eff->bEA,UfHE());
						break;
					}
					case 10:
					{
						UfVHI list; if (uf_cebc50) list = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list); if (list.empty_9b86e0()) goto nextEff; }
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							FXITEM(list,m)
							list.at_9b81f0(m).get_9b65b0()->remove_57dbe0(list.at_9b81f0(m).get_9b65b0()->isPlayer_5758f0(),1,1,1);
						}
						break;
					}
					case 11:
					{
						UfCell *e5 = CELLAT(POSX);
						UfPoint cp(e5->pos_45d1a0());
						uf_message_49c610(eff->x28,UfHE(),&e5->unknown45d140(),&cp);
						uf_playEffect_55ca10(eff->x34,e5->pos_45d1a0(),0);
						uf_playSound_55cb90(eff,e5->pos_45d1a0());
						e5->trigger_45e110(eff->bE9,0,UfHE());
						break;
					}
					case 12:
					{
						UfCell *en = CELLAT(POSX);
						uf_message_49c610(eff->x28,records->at_9b81f0(i)->e,&en->unknown45d140(),&en->pos_45d1a0());
						uf_playEffect_55ca10(eff->x34,en->pos_45d1a0(),0);
						uf_playMapEffect_55cb10(eff->x13c,en->pos_45d1a0());
						uf_playSound_55cb90(eff,en->pos_45d1a0());
						UfHG g = records->at_9b81f0(i)->e.get_9b6570()->getGroup_45a3f0();
						if (!g.get_9b7250()->type_9b4350())
							uf_cefc4c->unknown4647a0(en->pos_45d1a0(),1);
						break;
					}
					case 13:
					{
						UfHE gN = ENTX;
						if (!gN.get_9b6570())
							goto nextEff;
						UfEntityDef *def2 = eff->x7c != uf_caf160 ? uf_d25de0.at_9b81f0(eff->x7c) : uf_cefc4c->unknown6c5600(eff->x80,eff->x84,eff->xa0 != 0,0);
						if (gN.get_9b6570()->def_9b4350() == def2 || gN.get_9b6570()->isPlayer_5c7600() || eff->xc0 == 1 && !records->at_9b81f0(i)->e.get_9b6570())
							goto nextEff;
						else
						{
							UfPoint vP(gN.get_9b6570()->getPosition_45a4a0());
							if (def2->x9c > gN.get_9b6570()->getSize_45a360() && !uf_placeFootprint_51cd40(eff,def2,gN,&vP))
								goto nextEff;
							uf_message_49c610(eff->x28,gN,&def2->name1ac,0);
							UfHG grp0;
							switch (eff->xc0)
							{
								case 0:
									grp0 = gN.get_9b6570()->getGroup_45a3f0();
									break;
								case 1:
									grp0 = records->at_9b81f0(i)->e.get_9b6570()->getGroup_45a3f0();
									break;
								default:
									grp0 = uf_cefc4c->group_463890(eff->xc0 - 2);
							}
							int a7 = gN.get_9b6570()->unknown45a920();
							int aA = gN.get_9b6570()->unknown45a940();
							int i8 = gN.get_9b6570()->unknown45a8d0();
							int s44fc = gN.get_9b6570()->unknown45a8f0();
							int cd = gN.get_9b6570()->getField_490840();
							int aG = gN.get_9b6570()->unknown45a880();
							UfVHI *inv3 = gN.get_9b6570()->getInventoryList_45ab00();
							UfVHI itemsD;
							UfVecU types;
							UfPoint a9 = gN.get_9b6570()->pos_45a4c0();
							if (eff->xb8 != 3)
							{
								while (!inv3->empty_9b86e0())
								{
									itemsD.push_back_9b80b0(inv3->front_9b7060());
									types.push_back_9b9280(inv3->front_9b7060().get_9b65b0()->getType_44aec0());
									inv3->front_9b7060().get_9b65b0()->unknown57a0f0(a9,0,0);
								}
							}
							void *ai2 = 0;
							if (eff->xbc != 1)
								ai2 = gN.get_9b6570()->unknown45b540();
							UfHE follow;
							if (gN.get_9b6570()->ai_45b590())
								follow = gN.get_9b6570()->ai_45b590()->getFollowEntity_458ed0();
							gN.get_9b6570()->unknown637bb0();
							UfHE ne = uf_cefc4c->placeEntity_6c58c0(def2,vP,grp0.get_9b7250()->type_9b4350(),0,0x22,0xe,0);
							uf_assignFollow_51caa0(eff,ne,records->at_9b81f0(i)->e,follow);
							if (eff->b88)
								ne.get_9b6570()->unknown45b2a0();
							switch (eff->xd8)
							{
								case 0:
									ne.get_9b6570()->unknown45b240(ne.get_9b6570()->unknown5ca670());
									break;
								case 1:
									if (aG < 100)
										ne.get_9b6570()->unknown45b240(ne.get_9b6570()->unknown5ca670() * aA / 100);
									break;
								case 2:
									ne.get_9b6570()->unknown45b240(a7);
							}
							switch (eff->xdc)
							{
								case 0:
									ne.get_9b6570()->unknown45b270(ne.get_9b6570()->unknown5ca400());
									break;
								case 1:
									if (aG < 100)
										ne.get_9b6570()->unknown45b270(ne.get_9b6570()->unknown5ca400() * s44fc / 100);
									break;
								case 2:
									ne.get_9b6570()->unknown45b270(i8);
							}
							switch (eff->xe0)
							{
								break;
								case 1:
									if (aG < 100)
										ne.get_9b6570()->unknown5dea60(ne.get_9b6570()->unknown5ca260() * aG / 100,0);
									break;
								case 2:
									ne.get_9b6570()->unknown5dea60(cd,0);
							}
							switch (eff->xb8)
							{
								case 0:
								case 1:
									for (unsigned n = 0; n < itemsD.size_9b9260(); n++)
									{
										if (itemsD.at_9b81f0(n).get_9b65b0()->unknown457f90() == 7)
											uf_moveElement_9da1f0(itemsD,n,0);
									}
									for (unsigned n2 = 0; n2 < itemsD.size_9b9260(); n2++)
									{
										if (types.at_9b81f0(n2) == 4)
										{
											if (ne.get_9b6570()->unknown45a810() >= itemsD.at_9b81f0(n2).get_9b65b0()->getNestedField_4578c0())
											{
												itemsD.at_9b81f0(n2).get_9b65b0()->unknown57a190(ne,types.at_9b81f0(n2),0,0);
												uf_eraseStep_9d6440(itemsD,n2);
											}
										}
										else if (ne.get_9b6570()->unknown5db5f0(itemsD.at_9b81f0(n2),0,1,0))
										{
											itemsD.at_9b81f0(n2).get_9b65b0()->unknown57a190(ne,types.at_9b81f0(n2),0,0);
											uf_eraseStep_9d6440(itemsD,n2);
										}
									}
									if (eff->xb8 == 1)
									{
										while (!itemsD.empty_9b86e0())
											itemsD.front_9b7060().get_9b65b0()->remove_57dbe0(false,0,1,1);
										break;
									}
								case 2:
									for (unsigned n3 = 0; n3 < itemsD.size_9b9260(); n3++)
									{
										UfPoint q;
										if (uf_cefc4c->unknown71bc10(a9,&q))
										{
											itemsD.at_9b81f0(n3).get_9b65b0()->unknown57a0f0(q,0,0);
											uf_eraseStep_9d6440(itemsD,n3);
										}
									}
									while (!itemsD.empty_9b86e0())
										itemsD.front_9b7060().get_9b65b0()->remove_57dbe0(false,0,1,1);
							}
							switch (eff->xbc)
							{
								case 0:
									if (ai2)
										ne.get_9b6570()->unknown639800(ai2);
							}
							uf_playEffectPath_55ca70(eff->x34,ne.get_9b6570()->path_45d1a0(),0);
							uf_playSound_55cb90(eff,ne.get_9b6570()->pos_45a4c0());
						}
						break;
					}
					case 14:
					{
						UfPoint p(PTX);
						UfVPt pts2;
						int j4 = CELLAT(p)->getProp_45d550().isValid_9b7230() ? CELLAT(p)->getProp_45d550().get_9b64f0()->unknown44ab40() : -1;
						uf_collectProps_517ae0(j4,&pts2,0,eff->rangeEC.randomInRange_40c130(),j4 != -1 ? 0 : &p);
						if (!pts2.empty_9b86e0())
						{
							string name = CELLAT(pts2.front_9b7060())->getProp_45d550().get_9b64f0()->getName_45c5b0();
							uf_message_49c610(eff->x28,UfHE(),&name,&p);
							for (unsigned m = 0; m < pts2.size_9b9a50(); m++)
								CELLAT(pts2.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
							uf_playEffectPath_55ca70(eff->x34,pts2,0);
							if (eff->x38 != uf_caf144)
								uf_playSound_55cb90(eff,p);
							else
								uf_opR1d_454260(&p,0x7e);
						}
						break;
					}
					case 15:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							goto nextEff;
						if (p.get_9b64f0()->getNestedField_45c570() == eff->x8c)
							break;
						else
						{
							if (eff->x28 != uf_caf150)
							{
								do
								{
									if (uf_show_5111e0(eff->x28,&p.get_9b64f0()->getName_45c5b0(),&uf_cf35b0.at_9b81f0(eff->x8c)->name20,0,UfHE(),UfHE(),p.get_9b64f0()->pos_4184d0(),0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (0);
							}
							uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0);
							uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
							p.get_9b64f0()->unknown65d9d0(eff->x8c);
						}
						break;
					}
					case 16:
					{
						UfVHI list0; if (uf_cebc50) list0 = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list0); if (list0.empty_9b86e0()) goto nextEff; }
						UfItemDef *idef = eff->x90 != uf_caf164 ? uf_d2d1c4.at_9b81f0(eff->x90) : uf_cefc4c->selectRandomItem_6c3bc0(eff->xa0,eff->x94,0x12);
						for (unsigned m = 0; m < list0.size_9b9260(); m++)
						{
							if (list0.at_9b81f0(m).get_9b65b0()->def_9b4350() == idef)
								break;
							else
							{
								if (eff->x28 != uf_caf150)
								{
									do
									{
										if (uf_show_5111e0(eff->x28,&list0.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),&idef->name24,0,UfHE(),UfHE(),list0.at_9b81f0(m).get_9b65b0()->pos_575920(),0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (0);
								}
								uf_playEffect_55ca10(eff->x34,list0.at_9b81f0(m).get_9b65b0()->pos_575920(),0);
								uf_playSound_55cb90(eff,list0.at_9b81f0(m).get_9b65b0()->pos_575920());
								int itype = list0.at_9b81f0(m).get_9b65b0()->getType_44aec0();
								UfPoint aD(list0.at_9b81f0(m).get_9b65b0()->pos_575920());
								UfHE owner = list0.at_9b81f0(m).get_9b65b0()->unknown457b50();
								list0.at_9b81f0(m).get_9b65b0()->remove_57dbe0(list0.at_9b81f0(m).get_9b65b0()->isPlayer_5758f0(),0,1,1);
								UfHI aP = uf_cefaa8->createD_7932b0(idef);
								if (itype <= 3 && !owner.get_9b6570()->unknown5db5f0(aP,0,1,0))
									aP.get_9b65b0()->unknown57a190(owner,itype,0,1);
								else if (itype != 5 && owner.get_9b6570()->unknown45a810() >= aP.get_9b65b0()->getNestedField_4578c0())
									aP.get_9b65b0()->unknown57a190(owner,itype,0,1);
								else
								{
									UfPoint q;
									if (uf_cefc4c->unknown71bc10(aD,&q))
										aP.get_9b65b0()->unknown57a0f0(q,0,0);
									else
										aP.get_9b65b0()->remove_57dbe0(false,0,1,1);
								}
							}
						}
						break;
					}
					case 17:
					{
						UfCell *cell = CELLAT(POSX);
						if (cell->unknown45d0e0() == eff->xa4)
							break;
						else
						{
							if (eff->x28 != uf_caf150)
							{
								do
								{
									if (uf_show_5111e0(eff->x28,&cell->unknown45d140(),&uf_cfb844.at_9b81f0(eff->xa4)->name,0,UfHE(),UfHE(),cell->pos_45d1a0(),0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (0);
							}
							uf_playEffect_55ca10(eff->x34,cell->pos_45d1a0(),0);
							uf_playSound_55cb90(eff,cell->pos_45d1a0());
							cell->unknown66a050(eff->xa4,2,0);
						}
						break;
					}
					case 18:
					case 19:
					{
						UfPoint p(-1);
						UfHE tgt;
						switch (eff->x74)
						{
							break;
							case 1:
								tgt = ENTX;
								p = PTX;
								break;
							case 2:
								tgt = uf_cefc4c->getPlayer_4630f0();
								p = tgt.get_9b6570()->getPosition_45a4a0();
						}
						int k5 = eff->range44.randomInRange_40c130();
						bool lo = false;
						for (int n = 0; n < k5; n++)
						{
							bool ok = false;
							UfParty *party = 0;
							if (eff->type == 0x13)
							{
								UfVecU2 v;
								v.push_back_9b9d30(eff->x70);
								party = uf_cf6428.unknown68cf70(v,p);
								if (party)
								{
									switch (eff->x70)
									{
										case 0:
										case 1:
										case 2:
										case 3:
										case 4:
										case 6:
											ok = uf_cf6428.redirectParty_68d1f0(party,p,UfHE());
											break;
										case 5:
										case 7:
											if (eff->xa0 == 0 && tgt.get_9b6570())
												ok = uf_cf6428.redirectParty_68d1f0(party,p,tgt);
											else
												ok = uf_cf6428.redirectParty_68d1f0(party,p,UfHE());
											break;
									}
								}
							}
							else
							{
								switch (eff->x70)
								{
									case 0:
										ok = uf_cf6428.dispatch_689100(p);
										break;
									case 1:
										ok = uf_cf6428.unknown6892c0(0,p.x != -1 ? &p : 0,0);
										break;
									case 2:
									{
										UfVPt v(1,p);
										ok = uf_cf6428.spawnPatrolParty_6896d0(UfHE(),0,0,p.x != -1 ? &v : 0,0,0,0,10,0);
										break;
									}
									case 3:
										ok = uf_cf6428.unknown68a500(0,p.x != -1 ? &p : 0,eff->xa0 != 0);
										break;
									case 4:
										ok = uf_cf6428.unknown684250(p,0);
										break;
									case 5:
										if (eff->xa0)
											ok = uf_cf6428.unknown685a10(UfHE(),&p);
										else
										{
											if (!tgt.get_9b6570())
												goto nextEff;
											ok = uf_cf6428.unknown685a10(tgt,0);
										}
										break;
									case 6:
										ok = uf_cf6428.unknown686c60(p,-1,0x61,0x7a);
										break;
									case 7:
										if (eff->xa0 == 2)
										{
											string where = uf_d1e888.get_9b7910()->type == 1 ? "scrapyard" : "mines";
											string text = "ALERT: Infestation in the " + where + ", dispatching Demolisher response squad.";
											ok = uf_cf6428.spawnAntiInfestationCarrier_688e80(p,text);
											if (uf_d25450.b0 && uf_d1e888.get_9b7910()->type == 7)
												uf_d25450.unknown69e700(0x46,uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown45a880() <= 0x32,0);
										}
										else if (eff->xa0 == 0 && tgt.get_9b6570())
											ok = uf_cf6428.unknown687520(tgt,0,0);
										else
											ok = uf_cf6428.unknown687520(UfHE(),&p,0);
										break;
								}
							}
							if (ok)
							{
								UfParty *pp = eff->type == 0x12 ? uf_cf6428.unknown45ed10() : party;
								if (eff->x78)
									pp->x8 = uf_cefc4c->getTurn_464270() + eff->x78;
								if (eff->x118 != -1 && !pp->leader.get_9b6570()->unknown45ac40(eff->x118))
									pp->leader.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(eff->x118),1));
								if (!eff->v128.empty_9b86e0())
								{
									UfHE leader = pp->leader;
									for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
										leader.get_9b6570()->unknown6395d0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b138);
								}
								lo = true;
							}
						}
						if (!lo)
							goto nextEff;
						uf_message_49c610(eff->x28,UfHE(),&string(uf_cf25d8[eff->x70]),&p);
						break;
					}
					case 20:
					{
						int nG = eff->range44.randomInRange_40c130();
						UfEntityDef *nW = eff->x7c != uf_caf160 ? uf_d25de0.at_9b81f0(eff->x7c) : uf_cefc4c->unknown6c5600(eff->x80,eff->x84,eff->xa0 != 0,0);
						if (!nW)
							break;
						UfPoint p(PTX);
						UfVPt spots;
						for (int n = 0; n < nG; n++)
						{
							UfPoint q3(p);
							if (!uf_cefc4c->findPlaceableNear_71c150(q3,q3,nW->x9c) && !uf_placeFootprint_51cd40(eff,nW,UfHE(),&q3))
								goto nextEff;
							UfHG grp;
							switch (eff->xc0)
							{
								case 0:
									goto nextEff;
								case 1:
									grp = records->at_9b81f0(i)->e.get_9b6570()->getGroup_45a3f0();
									break;
								default:
									grp = uf_cefc4c->group_463890(eff->xc0 - 2);
							}
							UfHE ne = uf_cefc4c->placeEntity_6c58c0(nW,q3,grp.get_9b7250()->type_9b4350(),0,eff->xcc,eff->xd0,0);
							if (ne.isNull_9b65d0())
								uf_logError_404f10("checkTriggers()",defVal->name4 + " SE fail");
							else
							{
								if (!eff->s1bc.empty())
									ne.get_9b6570()->unknown45b070(eff->s1bc);
								uf_assignFollow_51caa0(eff,ne,records->at_9b81f0(i)->e,UfHE());
								if (eff->b88)
									ne.get_9b6570()->unknown45b2a0();
								if (eff->xcc == 0x19)
								{
									UfPoint best(-1);
									UfVZone cands(*uf_cefc4c->zones_462e10());
									uf_shuffle_9d8f80(cands);
									for (unsigned m = 0; m < cands.size_9b9260(); m++)
									{
										if (uf_d1e888.get_9b7910()->type == 0xd && (cands.at_9b81f0(m)->kind == 2 || cands.at_9b81f0(m)->kind == 3 || cands.at_9b81f0(m)->kind == 4))
											continue;
										UfVPt path;
										if (uf_cefc4c->unknown7168e0(ne.get_9b6570()->getPosition_45a4a0(),cands.at_9b81f0(m)->pt,ne.get_9b6570(),&path))
										{
											best = cands.at_9b81f0(m)->pt;
											if (uf_d1e888.get_9b7910()->type == 0xd)
												cands.at_9b81f0(m)->kind = 0;
											break;
										}
									}
									if (best.x != -1)
										ne.get_9b6570()->ai_45b590()->unknown459540(best);
									else
										ne.get_9b6570()->setAI_64ecf0(new UfEntityAI(ne,0x22,0xe));
								}
								switch (eff->xd8)
								{
									case 0:
										ne.get_9b6570()->unknown45b240(ne.get_9b6570()->unknown5ca670());
								}
								switch (eff->xdc)
								{
									case 0:
										ne.get_9b6570()->unknown45b270(ne.get_9b6570()->unknown5ca400());
								}
								if (eff->x28 != uf_caf150 && (eff->b4c || n == 0))
									uf_message_49c610(eff->x28,ne,0,0);
								uf_playEffectPath_55ca70(eff->x34,ne.get_9b6570()->path_45d1a0(),0);
								spots.push_back_9b3020(ne.get_9b6570()->pos_45a4c0());
								for (unsigned m2 = 0; m2 < eff->v128.size_9b9260(); m2++)
									ne.get_9b6570()->unknown6395d0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m2)),eff->b138);
								if (eff->rangeEC.y != 1 && ne.get_9b6570()->ai_45b590()->id_9b8f00() == 3)
								{
									if (eff->rangeEC.y == 0)
										ne.get_9b6570()->ai_45b590()->unknown459440(UfPoint(0,0),uf_cfd44c.size_9b7930());
									else
									{
										int r = eff->rangeEC.randomInRange_40c130();
										UfPoint np(ne.get_9b6570()->getPosition_45a4a0());
										UfBox at(uf_maxInt_9cdb60(0,np.x - r),uf_maxInt_9cdb60(0,np.y - r),uf_minInt_9cdb30(uf_cfd44c.getWidth_9fcd80() - 1,np.x + r),uf_minInt_9cdb30(uf_cfd44c.getHeight_9b8f00() - 1,np.y + r));
										ne.get_9b6570()->ai_45b590()->unknown459410(at);
									}
								}
								if (eff->xd4 != -1)
									ne.get_9b6570()->ai_45b590()->set_451930(eff->xd4);
							}
						}
						uf_playSoundNearest_55cc00(eff,spots);
						break;
					}
					case 21:
					{
						int count = eff->range44.randomInRange_40c130();
						for (int n = 0; n < count; n++)
						{
							UfPoint p(PTX);
							if (!uf_cefc4c->findPropSpotNear_71c3c0(p,p,eff->b139 ? uf_cf35b0.at_9b81f0(eff->x8c) : 0))
								goto nextEff;
							UfHP np = uf_cefaa8->createE_793360(uf_cf35b0.at_9b81f0(eff->x8c));
							CELLAT(p)->unknown45df50(np);
							np.get_9b64f0()->unknown45cc50(p);
							if (eff->x28 != uf_caf150 && (eff->b4c || n == 0))
								uf_message_49c610(eff->x28,UfHE(),&np.get_9b64f0()->getName_45c5b0(),&p);
							uf_playEffect_55ca10(eff->x34,p,0);
							uf_playSound_55cb90(eff,p);
							for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
								np.get_9b64f0()->unknown665b10(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b138);
							uf_cefc4c->unknown464e60(np);
							if (eff->x11c != -1 && !np.get_9b64f0()->unknown45c870(eff->x11c))
								np.get_9b64f0()->unknown45cee0(new UfFx(uf_d2f0f8.at_9b81f0(eff->x11c),1));
						}
						break;
					}
					case 22:
					{
						int count = eff->range44.randomInRange_40c130();
						UfItemDef *idef = eff->x90 != uf_caf164 ? uf_d2d1c4.at_9b81f0(eff->x90) : uf_cefc4c->selectRandomItem_6c3bc0(eff->xa0,eff->x94,0x12);
						for (int n = 0; n < count; n++)
						{
							UfPoint p(PTX);
							UfPoint p0(p);
							if (!uf_cefc4c->unknown71bc10(p,&p))
								goto nextEff;
							UfHI aK = uf_cefaa8->createD_7932b0(idef);
							if (eff->x28 != uf_caf150 && (eff->b4c || n == 0))
								uf_message_49c610(eff->x28,UfHE(),&aK.get_9b65b0()->getName_571db0(0,0),&p);
							uf_playEffect_55ca10(eff->x34,p,0);
							uf_playSound_55cb90(eff,p);
							for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
								aK.get_9b65b0()->unknown57c090(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b138);
							if (eff->range98.x < 100)
							{
								if (aK.get_9b65b0()->unknown457f90() == 0x7c)
									aK.get_9b65b0()->set_44fc60(eff->range98.randomInRange_40c130());
								else
									aK.get_9b65b0()->set_450460(uf_maxInt_9cdb60(1,eff->range98.randomInRange_40c130() * aK.get_9b65b0()->trap_9b6bf0() / 100));
							}
							if (eff->x11c != -1 && !aK.get_9b65b0()->getEffectValue_457be0(eff->x11c))
								aK.get_9b65b0()->addEffect_4585a0(new UfFx(uf_d2f0f8.at_9b81f0(eff->x11c),1));
							switch (eff->xe4)
							{
								case 3:
								case 4:
								{
									UfVHE2 holders;
									if (CELLAT(p0)->getEntity_45d250().isValid_9b7230())
										holders.push_back_9b7cf0(CELLAT(p0)->getEntity_45d250());
									else
									{
										UfVPt around;
										uf_surrounding_4faaf0(p0,&around);
										for (unsigned m = 0; m < around.size_9b9a50(); m++)
										{
											if (CELLAT(around.at_9e7c10(m))->getEntity_45d250().isValid_9b7230() && CELLAT(around.at_9e7c10(m))->getEntity_45d250().get_9b6570()->getGroup_45a3f0().eq_9b78e0(uf_cefc4c->getEntity_45d250().get_9b6570()->getGroup_45a3f0()))
												holders.push_back_9b7cf0(CELLAT(around.at_9e7c10(m))->getEntity_45d250());
										}
										if (records->at_9b81f0(i)->e.get_9b6570())
										{
											int idx = uf_indexOfEntity_9d3110(holders,records->at_9b81f0(i)->e);
											if (idx != -1)
												uf_moveElement_9da1f0b(holders,idx,0);
										}
									}
									if (eff->xe4 == 4)
									{
										for (unsigned m2 = 0; m2 < holders.size_9b9260(); m2++)
										{
											if (!holders.at_9b81f0(m2).get_9b6570()->unknown5db5f0(aK,0,1,0))
											{
												aK.get_9b65b0()->unknown57a190(holders.at_9b81f0(m2),aK.get_9b65b0()->getNestedField_4578a0(),holders.at_9b81f0(m2).get_9b6570()->isPlayer_5c7600(),1);
												goto next22;
											}
										}
									}
									for (unsigned m3 = 0; m3 < holders.size_9b9260(); m3++)
									{
										if (holders.at_9b81f0(m3).get_9b6570()->unknown45a810() >= aK.get_9b65b0()->getNestedField_4578c0())
										{
											aK.get_9b65b0()->unknown57a190(holders.at_9b81f0(m3),4,holders.at_9b81f0(m3).get_9b6570()->isPlayer_5c7600(),1);
											goto next22;
										}
									}
									if (!holders.empty_9b86e0() && CELLAT(holders.front_9b7060().get_9b6570()->getPosition_45a4a0())->hasBlockingObject_45d7b0())
										p = holders.front_9b7060().get_9b6570()->getPosition_45a4a0();
									break;
								}
								case 2:
									break;
								case 0:
								{
									UfVPt around;
									uf_surrounding_4faaf0(p0,&around);
									for (unsigned m = 0; m < around.size_9b9a50(); m++)
									{
										if (!CELLAT(around.at_9e7c10(m))->hasBlockingObject_45d7b0())
											uf_eraseStep_9d7300(around,m);
									}
									if (!around.empty_9b86e0())
									{
										if (uf_fn9d0ce0(around,uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0()))
											p = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0();
										else
											p = uf_randomPoint_9d5350(around);
									}
									break;
								}
								case 1:
								{
									UfVPt around;
									uf_surrounding_4faaf0(p0,&around);
									uf_shuffle_9d7350(around);
									uf_fn9d5460(around,0,p);
									for (unsigned m = 0; m < around.size_9b9a50(); m++)
									{
										if (!CELLAT(around.at_9e7c10(m))->hasBlockingObject_45d7b0() || !uf_cefc4c->isVisible_4631c0(around.at_9e7c10(m)) || CELLAT(around.at_9e7c10(m))->getEntity_45d250().isValid_9b7230())
											uf_eraseStep_9d7300(around,m);
									}
									if (!around.empty_9b86e0())
										p = around.at_9e7c10(0);
									break;
								}
								default:
									goto next22;
							}
							aK.get_9b65b0()->unknown57a0f0(p,0,aK.get_9b65b0()->isPlayer_5758f0());
							if (uf_d1e888.get_9b7910()->type == 0x21 && uf_strEq_9ccb50(aK.get_9b65b0()->name_457860(),"Plexus Tether"))
								uf_d33d74.push_back_9b80b0(aK);
							if (eff->bE8)
								aK.get_9b65b0()->unknown579c80();
						next22:
							;
						}
						break;
					}
					case 23:
					{
						UfHE ns = ENTX;
						if (!ns.get_9b6570())
							goto nextEff;
						UfVHI *inv = ns.get_9b6570()->getInventoryList_45ab00();
						for (unsigned m = 0; m < inv->size_9b9260(); m++)
						{
							if (inv->at_9b81f0(m).get_9b65b0()->getNestedField_457820() == eff->x90)
							{
								uf_message_49c610(eff->x28,ns,&inv->at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),&ns.get_9b6570()->getPosition_45a4a0());
								uf_playEffectPath_55ca70(eff->x34,ns.get_9b6570()->path_45d1a0(),0);
								uf_playSound_55cb90(eff,ns.get_9b6570()->pos_45a4c0());
								UfPoint q;
								if (uf_cefc4c->unknown71bc10(ns.get_9b6570()->pos_45a4c0(),&q))
									inv->at_9b81f0(m).get_9b65b0()->unknown57a0f0(q,1,1);
								break;
							}
						}
						break;
					}
					case 24:
					{
						UfHE pK = ENTX;
						if (!pK.get_9b6570())
							goto nextEff;
						UfPoint q;
						const UfPoint &aN = pK.get_9b6570()->getPosition_45a4a0();
						bool foundVal = false;
						if (eff->bA8)
						{
							q = uf_d20cf4;
							foundVal = true;
							if (!CELLAT(q)->canPlaceEntity_66ad20(pK.get_9b6570()->getSize_45a360()) && !uf_cefc4c->findPlaceableNear_71c150(q,q,pK.get_9b6570()->getSize_45a360()))
								foundVal = false;
						}
						else
						{
							UfRect r;
							uf_cfd44c.getRect_9b4430(aN,eff->rangeEC.y,r);
							for (int t = 0; t < 100; t++)
							{
								r.randomPoint_40be30(&q);
								if (uf_between_9daf80(eff->rangeEC.x,uf_distanceCeil_40a3f0(aN,q),eff->rangeEC.y) && CELLAT(q)->canPlaceEntity_66ad20(pK.get_9b6570()->getSize_45a360()))
								{
									foundVal = true;
									break;
								}
							}
						}
						if (foundVal)
						{
							uf_message_49c610(eff->x28,pK,0,&aN);
							uf_playEffectPath_55ca70(eff->x34,pK.get_9b6570()->path_45d1a0(),&q);
							uf_playSound_55cb90(eff,pK.get_9b6570()->pos_45a4c0());
							pK.get_9b6570()->unknown5ddac0(q,1);
							uf_playEffectPath_55ca70(eff->xb0,pK.get_9b6570()->path_45d1a0(),0);
						}
						else
							goto nextEff;
						break;
					}
					case 25:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							goto nextEff;
						UfPoint q;
						const UfPoint &pp = p.get_9b64f0()->pos_4184d0();
						bool found = false;
						if (eff->bA8)
						{
							q = uf_d20cf4;
							found = true;
							if (!CELLAT(q)->fitsProp_45d570(0) && !uf_cefc4c->findPropSpotNear_71c3c0(q,q,0))
								found = false;
						}
						else
						{
							UfRect r;
							uf_cfd44c.getRect_9b4430(pp,eff->rangeEC.y,r);
							for (int t = 0; t < 50; t++)
							{
								r.randomPoint_40be30(&q);
								if (uf_between_9daf80(eff->rangeEC.x,uf_distanceCeil_40a3f0(pp,q),eff->rangeEC.y) && CELLAT(q)->fitsProp_45d570(0))
								{
									found = true;
									break;
								}
							}
						}
						if (found)
						{
							uf_message_49c610(eff->x28,UfHE(),&p.get_9b64f0()->def_9b8f00()->name20,&pp);
							uf_playEffect_55ca10(eff->x34,pp,&q);
							uf_playSound_55cb90(eff,pp);
							p.get_9b64f0()->unknown65f270(q);
							uf_playEffect_55ca10(eff->xb0,q,0);
						}
						else
							goto nextEff;
						break;
					}
					case 26:
					{
						UfVHI list; if (uf_cebc50) list = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list); if (list.empty_9b86e0()) goto nextEff; }
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							UfPoint q;
							const UfPoint &sy = list.at_9b81f0(m).get_9b65b0()->pos_575920();
							bool found = false;
							if (eff->bA8)
							{
								q = uf_d20cf4;
								found = true;
								if (!CELLAT(q)->hasBlockingObject_45d7b0() && !uf_cefc4c->unknown71bc10(q,&q))
									found = false;
							}
							else
							{
								UfRect r;
								uf_cfd44c.getRect_9b4430(sy,eff->rangeEC.y,r);
								for (int t = 0; t < 50; t++)
								{
									r.randomPoint_40be30(&q);
									if (uf_between_9daf80(eff->rangeEC.x,uf_distanceCeil_40a3f0(sy,q),eff->rangeEC.y) && CELLAT(q)->hasBlockingObject_45d7b0())
									{
										found = true;
										break;
									}
								}
							}
							if (found)
							{
								uf_message_49c610(eff->x28,UfHE(),&list.at_9b81f0(m).get_9b65b0()->def_9b4350()->name24,&sy);
								uf_playEffect_55ca10(eff->x34,sy,&q);
								uf_playSound_55cb90(eff,sy);
								uf_playEffect_55ca10(eff->xb0,q,0);
								if (eff->bA8 && CELLAT(q)->getEntity_45d250().isValid_9b7230())
								{
									UfHE occ = CELLAT(q)->getEntity_45d250();
									if (occ.get_9b6570()->unknown45a810() >= list.at_9b81f0(m).get_9b65b0()->getNestedField_4578c0())
									{
										list.at_9b81f0(m).get_9b65b0()->unknown57a190(occ,4,occ.get_9b6570()->isPlayer_5c7600(),1);
										goto moved26;
									}
								}
								list.at_9b81f0(m).get_9b65b0()->unknown57a0f0(q,0,0);
							moved26:
								;
							}
							else
								goto nextEff;
						}
						break;
					}
					case 27:
					{
						UfCell *cell = CELLAT(POSX);
						uf_message_49c610(eff->x28,UfHE(),0,&cell->pos_45d1a0());
						uf_playEffect_55ca10(eff->x34,cell->pos_45d1a0(),0);
						uf_playSound_55cb90(eff,cell->pos_45d1a0());
						break;
					}
					case 28:
					{
						UfHE e = ENTX; if (!e.get_9b6570()) goto nextEff; uf_message_49c610(eff->x28,e,0,0); uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0); uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						break;
					}
					case 29:
					{
						UfHE t_ = ENTX;
						if (!t_.get_9b6570())
							goto nextEff;
						UfHG g;
						switch (eff->xc0)
						{
							case 0:
								goto nextEff;
							case 1:
								if (records->at_9b81f0(i)->e.get_9b6570())
								{
									g = records->at_9b81f0(i)->e.get_9b6570()->getGroup_45a3f0();
									break;
								}
								else
									goto nextEff;
							default:
								g = uf_cefc4c->group_463890(eff->xc0 - 2);
						}
						if (t_.get_9b6570()->getGroup_45a3f0().eq_9b78e0(g) || t_.get_9b6570()->isPlayer_5c7600())
						{
							if (eff->x120 == 100 && t_.get_9b6570()->ai_45b590())
								uf_assignFollow_51caa0(eff,t_,records->at_9b81f0(i)->e,t_.get_9b6570()->ai_45b590()->getFollowEntity_458ed0());
							goto nextEff;
						}
						if (!rng.chance_406c90(eff->x120))
						{
							uf_message_49c610(eff->x124,t_,&uf_d01860[g.get_9b7250()->type_9b4350()],0);
							uf_playEffectPath_55ca70(eff->xb0,t_.get_9b6570()->path_45d1a0(),0);
							uf_playSound_55cb90(eff,t_.get_9b6570()->pos_45a4c0());
							goto nextEff;
						}
						else
						{
							UfHE follow;
							if (t_.get_9b6570()->ai_45b590())
								follow = t_.get_9b6570()->ai_45b590()->getFollowEntity_458ed0();
							t_.get_9b6570()->changeFaction_5dc780(g,1);
							uf_assignFollow_51caa0(eff,t_,records->at_9b81f0(i)->e,follow);
							uf_message_49c610(eff->x28,t_,&uf_d01860[g.get_9b7250()->type_9b4350()],0);
							uf_playEffectPath_55ca70(eff->x34,t_.get_9b6570()->path_45d1a0(),0);
							uf_playSound_55cb90(eff,t_.get_9b6570()->pos_45a4c0());
						}
						break;
					}
					case 30:
					{
						UfHE vC = ENTX;
						if (!vC.get_9b6570())
							goto nextEff;
						UfHE follow;
						if (vC.get_9b6570()->ai_45b590())
							follow = vC.get_9b6570()->ai_45b590()->getFollowEntity_458ed0();
						vC.get_9b6570()->setAI_64ecf0(new UfEntityAI(vC,eff->xcc,eff->xd0));
						uf_assignFollow_51caa0(eff,vC,records->at_9b81f0(i)->e,follow);
						if (eff->xcc == 3 && eff->rangeEC.y != 1)
						{
							if (eff->rangeEC.y == 0)
								vC.get_9b6570()->ai_45b590()->unknown459440(UfPoint(0,0),uf_cfd44c.size_9b7930());
							else
							{
								int r = eff->rangeEC.randomInRange_40c130();
								UfPoint np(vC.get_9b6570()->getPosition_45a4a0());
								UfBox bN(uf_maxInt_9cdb60(0,np.x - r),uf_maxInt_9cdb60(0,np.y - r),uf_minInt_9cdb30(uf_cfd44c.getWidth_9fcd80() - 1,np.x + r),uf_minInt_9cdb30(uf_cfd44c.getHeight_9b8f00() - 1,np.y + r));
								vC.get_9b6570()->ai_45b590()->unknown459410(bN);
							}
						}
						if (eff->xd4 != -1)
							vC.get_9b6570()->ai_45b590()->set_451930(eff->xd4);
						uf_message_49c610(eff->x28,vC,0,0);
						uf_playEffectPath_55ca70(eff->x34,vC.get_9b6570()->path_45d1a0(),0);
						uf_playSound_55cb90(eff,vC.get_9b6570()->pos_45a4c0());
						break;
					}
					case 31:
					{
						UfHE e = ENTX;
						if (!e.get_9b6570())
							goto nextEff;
						uf_message_49c610(eff->x28,e,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,0);
						uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0);
						uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
							e.get_9b6570()->unknown6395d0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b138);
						break;
					}
					case 32:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							goto nextEff;
						if (eff->x28 != uf_caf150)
						{
							do
							{
								if (uf_show_5111e0(eff->x28,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,&p.get_9b64f0()->getName_45c5b0(),0,UfHE(),UfHE(),p.get_9b64f0()->pos_4184d0(),0))
									uf_cec058->bubble_8758d0(true);
								uf_cec0b4->scrollToEnd_7b4f10();
							}
							while (0);
						}
						uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0);
						uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
						for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
							p.get_9b64f0()->unknown665b10(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b138);
						uf_cefc4c->unknown464e60(p);
						break;
					}
					case 33:
					{
						UfVHI list; if (uf_cebc50) list = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list); if (list.empty_9b86e0()) goto nextEff; }
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							if (eff->x28 != uf_caf150)
							{
								do
								{
									if (uf_show_5111e0(eff->x28,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,&list.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),0,UfHE(),UfHE(),list.at_9b81f0(m).get_9b65b0()->pos_575920(),0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (0);
							}
							uf_playEffect_55ca10(eff->x34,list.at_9b81f0(m).get_9b65b0()->pos_575920(),0);
							uf_playSound_55cb90(eff,list.at_9b81f0(m).get_9b65b0()->pos_575920());
							for (unsigned m2 = 0; m2 < eff->v128.size_9b9260(); m2++)
								list.at_9b81f0(m).get_9b65b0()->unknown57c090(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m2)),eff->b138);
							uf_cefc4c->unknown464f60(list.at_9b81f0(m));
						}
						break;
					}
					case 34:
					{
						UfHE e = ENTX;
						if (!e.get_9b6570())
							goto nextEff;
						uf_message_49c610(eff->x28,e,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,0);
						uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0);
						uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						for (unsigned m = 0; m < eff->v128.size_9b9260(); m++)
							e.get_9b6570()->removeEffects_45b4c0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m)),eff->b13a);
						break;
					}
					case 35:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							goto nextEff;
						if (eff->x28 != uf_caf150)
						{
							do
							{
								if (uf_show_5111e0(eff->x28,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,&p.get_9b64f0()->getName_45c5b0(),0,UfHE(),UfHE(),p.get_9b64f0()->pos_4184d0(),0))
									uf_cec058->bubble_8758d0(true);
								uf_cec0b4->scrollToEnd_7b4f10();
							}
							while (0);
						}
						uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0);
						uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
						uf_fn51d5e0(p,eff->v128,eff->b13a);
						break;
					}
					case 36:
					{
						UfVHI list; if (uf_cebc50) list = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list); if (list.empty_9b86e0()) goto nextEff; }
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							if (eff->x28 != uf_caf150)
							{
								do
								{
									if (uf_show_5111e0(eff->x28,&uf_d2c408.at_9b81f0(eff->v128.front_9b7060())->name20,&list.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),0,UfHE(),UfHE(),list.at_9b81f0(m).get_9b65b0()->pos_575920(),0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (0);
							}
							uf_playEffect_55ca10(eff->x34,list.at_9b81f0(m).get_9b65b0()->pos_575920(),0);
							uf_playSound_55cb90(eff,list.at_9b81f0(m).get_9b65b0()->pos_575920());
							uf_fn51d730(list.at_9b81f0(m),eff->v128,eff->b13a);
						}
						break;
					}
					case 37:
					case 38:
					{
						UfHG g;
						switch (eff->xc0)
						{
							case 0:
								goto nextEff;
							case 1:
								if (records->at_9b81f0(i)->e.get_9b6570())
								{
									g = records->at_9b81f0(i)->e.get_9b6570()->getGroup_45a3f0();
									break;
								}
								else
									goto nextEff;
							default:
								g = uf_cefc4c->group_463890(eff->xc0 - 2);
						}
						UfVHE &members = g.get_9b7250()->members_416f40();
						for (unsigned m = 0; m < members.size_9b9260(); m++)
						{
							if (members.at_9b81f0(m).get_9b6570()->unknown45ac40(eff->x11c))
							{
								for (unsigned m2 = 0; m2 < eff->v128.size_9b9260(); m2++)
								{
									if (eff->type == 0x25)
										members.at_9b81f0(m).get_9b6570()->unknown6395d0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m2)),eff->b138);
									else
										members.at_9b81f0(m).get_9b6570()->removeEffects_45b4c0(uf_d2c408.at_9b81f0(eff->v128.at_9b81f0(m2)),eff->b13a);
								}
							}
						}
						break;
					}
					case 39:
						if (entity.isValid_9b7230())
						{
							uf_playEffectPath_55ca70(eff->x34,entity.get_9b6570()->path_45d1a0(),0);
							uf_playMapEffect_55cb10(eff->x13c,entity.get_9b6570()->pos_45a4c0());
							uf_playSound_55cb90(eff,entity.get_9b6570()->pos_45a4c0());
						}
						else
						{
							uf_playEffect_55ca10(eff->x34,PTX,0);
							uf_playMapEffect_55cb10(eff->x13c,PTX);
							uf_playSound_55cb90(eff,PTX);
						}
						uf_message_49c610(eff->x28,UfHE(),entity.isValid_9b7230() ? &entity.get_9b6570()->getName_416f40() : prop.isValid_9b7230() ? &prop.get_9b64f0()->getName_45c5b0() : item.isValid_9b7230() ? &item.get_9b65b0()->getName_571db0(0,0) : &CELLAT(*pos)->unknown45d140(),&PTX);
						break;
					case 40:
					{
						UfHE e = ENTX;
						if (!e.get_9b6570())
							goto nextEff;
						uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0);
						uf_playMapEffect_55cb10(eff->x13c,e.get_9b6570()->pos_45a4c0());
						uf_message_49c610(eff->x28,e,0,0);
						uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						break;
					}
					case 41:
						if (records->at_9b81f0(i)->e.get_9b6570())
						{
							UfHE e = records->at_9b81f0(i)->e;
							uf_playEffectPath_55ca70(eff->x34,e.get_9b6570()->path_45d1a0(),0);
							uf_playMapEffect_55cb10(eff->x13c,e.get_9b6570()->pos_45a4c0());
							uf_message_49c610(eff->x28,e,0,0);
							uf_playSound_55cb90(eff,e.get_9b6570()->pos_45a4c0());
						}
						break;
					case 42:
					{
						UfHP p = PROPX;
						if (!p.get_9b64f0())
							goto nextEff;
						uf_playEffect_55ca10(eff->x34,p.get_9b64f0()->pos_4184d0(),0);
						uf_message_49c610(eff->x28,UfHE(),&p.get_9b64f0()->getName_45c5b0(),&p.get_9b64f0()->pos_4184d0());
						uf_playSound_55cb90(eff,p.get_9b64f0()->pos_4184d0());
						break;
					}
					case 43:
					{
						UfVHI list; if (uf_cebc50) list = uf_d32edc; else { uf_fn51d880(entity,prop,item,pos,&list); if (list.empty_9b86e0()) goto nextEff; }
						for (unsigned m = 0; m < list.size_9b9260(); m++)
						{
							uf_playEffect_55ca10(eff->x34,list.at_9b81f0(m).get_9b65b0()->pos_575920(),0);
							uf_message_49c610(eff->x28,UfHE(),&list.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),&list.at_9b81f0(m).get_9b65b0()->pos_575920());
							uf_playSound_55cb90(eff,list.at_9b81f0(m).get_9b65b0()->pos_575920());
						}
						break;
					}
					case 44:
					{
						UfCell *cell = CELLAT(POSX);
						uf_playEffect_55ca10(eff->x34,cell->pos_45d1a0(),0);
						uf_message_49c610(eff->x28,UfHE(),&CELLAT(*pos)->unknown45d140(),&cell->pos_45d1a0());
						uf_playSound_55cb90(eff,cell->pos_45d1a0());
						break;
					}
					case 45:
					{
						UfHE e = ENTX;
						if (!e.get_9b6570())
							goto nextEff;
						uf_showTransmission_8f58f0(e,eff->x140);
						break;
					}
					case 46:
					{
						UfHE e = ENTX;
						if (!e.get_9b6570())
							goto nextEff;
						uf_openDecide_8f8680(e,eff->s1bc);
						break;
					}
					case 47:
					{
						UfEntryIt it = uf_d1e860.getEntryIterator_46f5b0(eff->s144);
						if (eff->x58 == 4)
							it.deref_9b8da0().value = eff->s160;
						else
							it.deref_9b8da0().value = uf_intToString_4051f0(uf_applyOperation_456a50(uf_stringToInt_405610(it.deref_9b8da0().value),eff->x58,uf_stringToInt_405610(eff->s160),-1,-1));
						uf_message_49c610(eff->x28,uf_cefc4c->getPlayer_4630f0(),0,0);
						break;
					}
					case 48:
						uf_cec054->unknown819d50(eff->x17c,eff->s1bc == "FORCE_ASCII");
						uf_message_49c610(eff->x28,uf_cefc4c->getPlayer_4630f0(),0,0);
						break;
					case 49:
					{
						string name;
						if (!eff->s184.empty())
						{
							if (eff->s184 == "[name]" && records->at_9b81f0(i)->e.get_9b6570())
								name = records->at_9b81f0(i)->e.get_9b6570()->getName_416f40();
							else
								name = eff->s184;
						}
						switch (uf_cf08c4.at_9b81f0(eff->x180)->x20)
						{
							case 0:
								do
								{
									uf_logPhrase_5141b0(eff->x180,name.empty() ? 0 : &name,0,0,UfHE(),0);
								}
								while (0);
								break;
							case 1:
								do
								{
									uf_logPhrase_5141b0(eff->x180,name.empty() ? 0 : &name,0,0,uf_cefc4c->getPlayer_4630f0(),0);
								}
								while (0);
								break;
							case 2:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								do
								{
									uf_logPhrase_5141b0(eff->x180,name.empty() ? 0 : &name,0,0,e,0);
								}
								while (0);
								break;
							}
							case 3:
							{
								UfCell *cell = CELLAT(POSX);
								do
								{
									uf_logPhrase_5141b0(eff->x180,name.empty() ? 0 : &name,0,0,UfHE(),&cell->pos_45d1a0());
								}
								while (0);
								break;
							}
						}
						break;
					}
					case 50:
					{
						UfStatDef *sd;
						uf_findByName_9d7390(uf_d389c4,eff->s1a0,&sd);
						if (sd)
						{
							if (uf_between_9daf80(7,sd->x0,0x6a))
								uf_d2c658.add_472b90(sd->x0,-999999);
							else
								uf_d2c658.add_4729d0(sd->x0,1,uf_b91caa,-1);
						}
						break;
					}
					case 51:
					{
						UfCell *w3 = CELLAT(POSX);
						uf_message_49c610(eff->x28,UfHE(),0,&w3->pos_45d1a0());
						if (eff->s1bc.find("PRELEARN_",0) != string::npos)
						{
							uf_prelearnData_797e60(eff->s1bc,0);
							break;
						}
						if (false) {}
						if (eff->s1bc[0] == '$')
						{
							uf_cf45d8.unlock_77fbc0(uf_stringToInt_405610(string(eff->s1bc.begin() + 1,eff->s1bc.end())));
							break;
						}
						else if (eff->s1bc[0] == '@')
						{
							if (uf_d25450.b0)
								uf_d25450.unknown69e700(uf_stringToInt_405610(string(eff->s1bc.begin() + 1,eff->s1bc.end())),0,0);
							break;
						}
						if (eff->s1bc[0] != '#')
							break;
						int bX = uf_stringToInt_405610(string(eff->s1bc.begin() + 1,eff->s1bc.end()));
						switch (bX)
						{
							case 0:
								uf_cefc4c->unknown74d560(0xd,2,2,*uf_cfe674);
								uf_cefc4c->group_463890(0xd).get_9b7250()->setField_45e4a0(1);
								break;
							case 1:
								if (entity.get_9b6570()->unknown5d5250())
								{
									if (uf_cefc4c->unknown4631f0(entity))
									{
										string s = entity.get_9b6570()->getName_416f40() + " disintegrates.";
										uf_message_49c610(0x320,UfHE(),&s,0);
										uf_opR1d_454260(&entity.get_9b6570()->getPosition_45a4a0(),0xc0);
									}
									entity.get_9b6570()->unknown637bb0();
								}
								break;
							case 2:
								if (uf_d25450.b0 && !uf_teambCheck_69d230())
									uf_d25450.unknown69e700(0x60,0,0);
								break;
							case 3:
								switch (rng.rangeInt_406d70(0,1))
								{
									case 0:
									{
										entity.get_9b6570()->unknown6399e0(0xf,0);
										string s = entity.get_9b6570()->getName_416f40() + " emits IFF burst signal.";
										uf_message_49c610(0x320,UfHE(),&s,0);
										break;
									}
									case 1:
									{
										UfPoint c = uf_randomPoint_9d5350(entity.get_9b6570()->path_45d1a0());
										UfRect w9;
										uf_cfd44c.getRect_9b4430(c,0xf,w9);
										UfPoint fp;
										do
											fp = w9.randomPoint_40be90();
										while (fp.test_409b90(c));
										int i49a8 = 0x1e;
										int wC = 0x14;
										UfVPt hits;
										UfVPt xC;
										int spread0;
										switch (uf_distanceCeil_40a3f0(c,fp))
										{
											case 1:
												spread0 = 20;
												break;
											case 2:
												spread0 = 10;
												break;
											case 3:
												spread0 = 7;
												break;
											default:
												spread0 = 5;
										}
										UfPoint z6(fp.x - c.x,fp.y - c.y);
										z6.scale_40a300(spread0);
										UfPoint far(c,z6);
										UfPoint z7;
										for (float a = uf_c37190; a <= uf_c37188; a += uf_c36de8)
										{
											int ang = a;
											if (ang < 0)
												ang += 360;
											uf_rotatePoint_501fc0(c,far,ang,&z7);
											uf_fn9d3020(xC,z7);
										}
										UfVPt line;
										for (unsigned m = 0; m < xC.size_9b9a50(); m++)
										{
											line.clear_9b3560();
											uf_bresenham_40ff30(c,xC.at_9e7c10(m),line);
											for (unsigned n = 0; n < line.size_9b9a50(); n++)
											{
												if (uf_cfd44c.contains_9b43b0(line.at_9e7c10(n)) && uf_distanceCeil_40a3f0(c,line.at_9e7c10(n)) <= 20)
													uf_fn9d3020(hits,line.at_9e7c10(n));
												else
													break;
											}
										}
										if (!hits.empty_9b86e0())
										{
											int terr = uf_d2d1c4.at_9b81f0(uf_indexOfName_9d74d0(uf_d2d1c4,"Terrabomb"))->x190;
											int count = 0;
											int aFp = 0;
											for (unsigned m2 = 0; m2 < hits.size_9b9a50(); m2++)
											{
												if (!CELLAT(hits.at_9e7c10(m2))->getField_4550b0() && !CELLAT(hits.at_9e7c10(m2))->unknown45db70())
												{
													uf_cefc50->new_508610(uf_cefc50)->init_503b20(terr,hits.at_9e7c10(m2),&uf_d2e20c,0,0,0,9,0);
													CELLAT(hits.at_9e7c10(m2))->trigger_45e110(0,1,UfHE());
													count++;
													if (uf_cefc4c->isVisible_4631c0(hits.at_9e7c10(m2)))
														aFp++;
												}
											}
											if (count)
											{
												uf_opR1d_454260(&c,0xcd);
												if (aFp)
												{
													string s = entity.get_9b6570()->getName_416f40() + " projects a cone of terrain-disintegrating energy.";
													uf_message_49c610(0x320,UfHE(),&s,0);
												}
											}
										}
										break;
									}
								}
								break;
							case 4:
							{
								if ((uf_d1e888.get_9b7910()->type != 2 || uf_d1e888.get_9b7910()->depth != 10) && uf_d1e888.get_9b7910()->type != 0xf)
								{
									entity.get_9b6570()->removeEffects_45b4c0(defVal,true);
									break;
								}
								UfVHE &grp13 = uf_cefc4c->group_463890(0xd).get_9b7250()->members_416f40();
								if (grp13.empty_9b86e0())
									break;
								UfHE art;
								for (unsigned m = 0; m < grp13.size_9b9260(); m++)
								{
									if (grp13.at_9b81f0(m).get_9b6570()->ai_45b590()->getFollowEntity_458ed0().get_9b6570() && !grp13.at_9b81f0(m).get_9b6570()->getTarget_45a760() && !grp13.at_9b81f0(m).get_9b6570()->unknown5d1280(0))
									{
										art = grp13.at_9b81f0(m);
										break;
									}
								}
								if (art.isNull_9b65d0())
								{
									for (unsigned m2 = 0; m2 < grp13.size_9b9260(); m2++)
									{
										if (!grp13.at_9b81f0(m2).get_9b6570()->getTarget_45a760() && !grp13.at_9b81f0(m2).get_9b6570()->unknown5d1280(0))
										{
											art = grp13.at_9b81f0(m2);
											break;
										}
									}
									if (art.isValid_9b7230())
									{
										for (unsigned m3 = 0; m3 < grp13.size_9b9260(); m3++)
										{
											if (grp13.at_9b81f0(m3).ne_9b6510(art))
												grp13.at_9b81f0(m3).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(art,0);
										}
									}
								}
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("matSpawnedFedparty_g")))
								{
									uf_d1e860.setEntryText_46f700("matSpawnedFedparty_g","1");
									uf_d257e4 = true;
									if (art.isValid_9b7230())
										uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Greet",0);
								}
								if (art.isValid_9b7230() && uf_d1e888.get_9b7910()->type == 0xf)
								{
									if (uf_cefc4c->unknown4642d0() == 1)
									{
										do
										{
											uf_logPhrase_5141b0(0xc9,&uf_intToString_4051f0(uf_cefc4c->group_463890(0xd).get_9b7250()->members_416f40().size_9b9260()),0,0,UfHE(),0);
										}
										while (0);
										uf_cf45d8.unlock_77fbc0(0x173);
										for (unsigned m4 = 0; m4 < grp13.size_9b9260(); m4++)
										{
											grp13.at_9b81f0(m4).get_9b6570()->ai_45b590()->unknown459410(uf_cfd44c.getArea_9b4400());
											grp13.at_9b81f0(m4).get_9b6570()->ai_45b590()->set_451930(0x21);
										}
										uf_d1eab0 = 1;
										uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(15,30);
									}
									else if (uf_d1eab4 == uf_cefc4c->getTurn_464270())
									{
										switch (uf_d1eab0)
										{
											case 1:
												uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Talk1",0);
												uf_d1eab0++;
												uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(10,20);
												break;
											case 2:
												uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Talk2",0);
												uf_d1eab0++;
												uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(70,130);
												break;
											case 3:
											{
												UfEntityDef *fed;
												if (uf_findByName_9d7530(uf_d25de0,"Federalist",&fed))
												{
													int n = rng.rangeInt_406d70(2,3);
													for (int k2 = 0; k2 < n; k2++)
													{
														UfPoint sp(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
														uf_clearDijkstra_4faf40();
														uf_cfe568.unknown40ca20(sp,999,&uf_d25624,0);
														if (!uf_d15e58.empty_9b86e0())
															sp = uf_randomPoint_9d5350(uf_d15e58);
														if (uf_cefc4c->findPlaceableNear_71c150(sp,sp,1))
														{
															UfHE fe = uf_cefc4c->placeEntity_6c58c0(fed,sp,0xd,0,0x22,0xe,0);
															fe.get_9b6570()->ai_45b590()->unknown459410(uf_cfd44c.getArea_9b4400());
															fe.get_9b6570()->ai_45b590()->set_451930(0x21);
															fe.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(art,0);
															if (k2 == 0)
																uf_cefc4c->unknown6c65a0(fe,"MAT_Fedparty_Talk_Join",0);
														}
													}
												}
												uf_d1eab0++;
												uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(25,50);
												break;
											}
											case 4:
												uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Talk3",0);
												uf_d1eab0++;
												uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(25,50);
												break;
											case 5:
												uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Talk4",0);
												uf_d1eab0++;
												uf_d1eab4 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(15,30);
												break;
											case 6:
											{
												uf_cefc4c->unknown6c65a0(art,"MAT_Fedparty_Talk5",0);
												uf_d1eab0++;
												UfHE node;
												if (!uf_findNode_470180(0xb,-1,uf_d1e884,&node))
													break;
												uf_d1e860.addExit_7892d0(node,art.get_9b6570()->getPosition_45a4a0(),uf_b91cab);
												for (unsigned m5 = 0; m5 < grp13.size_9b9260(); m5++)
												{
													grp13.at_9b81f0(m5).get_9b6570()->ai_45b590()->unknown4582d0(0x19);
													grp13.at_9b81f0(m5).get_9b6570()->ai_45b590()->unknown459540(art.get_9b6570()->getPosition_45a4a0());
													grp13.at_9b81f0(m5).get_9b6570()->ai_45b590()->setField_4593f0(0);
												}
												break;
											}
										}
									}
								}
								break;
							}
							case 5:
								if (uf_d25740 >= 10 && rng.chance_406c90(0x21) && uf_cefc4c->unknown716940(w3->pos_45d1a0(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0,0) && !uf_cf645c && !uf_cf6474)
								{
									UfEntityDef *sub;
									if (uf_findByName_9d7530(uf_d25de0,"Subdweller",&sub))
									{
										int n4a2c = 3;
										UfHE first;
										int spawned = 0;
										for (int k = 0; k < 3; k++)
										{
											UfHE se = uf_cefc4c->placeEntity_6c58c0(sub,w3->pos_45d1a0(),5,0,0x22,0xe,0);
											if (se.isValid_9b7230())
											{
												spawned++;
												if (first.isNull_9b65d0())
													first = se;
												else
													se.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(first,0);
												uf_cefc4c->unknown6c65a0(se,"MAT_Subdweller_Retreat",0);
											}
										}
										bool found5 = false;
										for (unsigned m = 0; m < uf_cf6478.size_9b9260(); m++)
										{
											if (uf_cf6478.at_9b81f0(m)->x0 == 2)
											{
												uf_cf6478.at_9b81f0(m)->leader.get_9b6570()->ai_45b590()->setPatrolRandom_5b3430(w3->pos_45d1a0());
												if (!found5)
												{
													UF_ALERT("ALERT: Derelict incursion detected, rerouting patrols to target area.")
													do
													{
														uf_logPhrase_5141b0(0xcc,0,0,0,UfHE(),0);
													}
													while (0);
													found5 = true;
												}
											}
										}
										if (!found5)
										{
											for (int k2 = 0; k2 < 2; k2++)
											{
												if (uf_cf6428.spawnPatrolParty_6896d0(UfHE(),0,0,0,0,0,0,10,0))
												{
													uf_cf6478.back_9b6540()->leader.get_9b6570()->ai_45b590()->setPatrolRandom_5b3430(w3->pos_45d1a0());
													if (k2 == 0)
													{
														UF_ALERT("ALERT: Derelict incursion detected, dispatching patrols to target area.")
														do
														{
															uf_logPhrase_5141b0(0xcc,0,0,0,UfHE(),0);
														}
														while (0);
													}
												}
											}
										}
									}
								}
								break;
							case 6:
							{
								UfVZone at5(*uf_cefc4c->zones_462e10());
								uf_shuffle_9d8f80(at5);
								UfPoint dest(-1);
								for (unsigned m = 0; m < at5.size_9b9260(); m++)
								{
									if (at5.at_9b81f0(m)->loc.get_9b7910()->type == 7 || at5.at_9b81f0(m)->loc.get_9b7910()->type == 0xf)
									{
										dest = at5.at_9b81f0(m)->pt;
										break;
									}
								}
								if (dest.x == -1)
									dest = at5.at_9b81f0(0)->pt;
								entity.get_9b6570()->setAI_64ecf0(new UfEntityAI(entity,0x19,0xe));
								entity.get_9b6570()->ai_45b590()->unknown459540(dest);
								break;
							}
							case 7:
							{
								UfWL wl;
								wl.add_9ba310(0,0x19);
								wl.add_9ba310(1,0x28);
								wl.add_9ba310(2,0x14);
								wl.add_9ba310(3,0xa);
								wl.add_9ba310(4,5);
								int kind = wl.pick_9ba470();
								UfVHI got3;
								switch (kind)
								{
									break;
									case 1:
									case 2:
									{
										int n = (kind != 1) + 1;
										for (int k = 0; k < n; k++)
											got3.push_back_9b7cf0(uf_cefc4c->unknown6c51d0(uf_cefbec,entity,0,0));
										break;
									}
									case 3:
									case 4:
									{
										int n2 = (kind != 3) + 1;
										if (rng.chance_406c90(0x32))
										{
											for (int k = 0; k < n2; k++)
											{
												UfItemDef *d = uf_cefc4c->selectRandomItem_6c3bc0(2,0x1f,0x12);
												uf_cefc4c->unknown6c51d0(d,entity,0,1);
											}
											break;
										}
										if (uf_d29d44.empty_9b81b0())
										{
											for (unsigned m = 0; m < uf_d2d1c4.size_9b9260(); m++)
											{
												if (uf_d2d1c4.at_9b81f0(m)->x54 == 3 && uf_d2d1c4.at_9b81f0(m)->x50 <= 2)
													uf_d29d44.add_9ba310(uf_d2d1c4.at_9b81f0(m),uf_ba3acc[uf_d2d1c4.at_9b81f0(m)->x5c]);
											}
											uf_d29d44.add_9ba310(uf_d2d1c4.at_9b81f0(uf_indexOfName_9d74d0(uf_d2d1c4,"Dirty Datajack")),uf_ba3acc[2]);
											uf_d29d44.add_9ba310(uf_d2d1c4.at_9b81f0(uf_indexOfName_9d74d0(uf_d2d1c4,"Shrapnel Trap")),uf_ba3acc[1]);
											uf_d29d44.add_9ba310(uf_d2d1c4.at_9b81f0(uf_indexOfName_9d74d0(uf_d2d1c4,"Piercing Trap")),uf_ba3acc[1]);
										}
										if (!uf_d29d44.empty_9b81b0())
										{
											for (int k3 = 0; k3 < n2; k3++)
												uf_cefc4c->unknown6c51d0(uf_d29d44.pick_9ba470(),entity,0,1);
										}
										break;
									}
								}
								for (unsigned m = 0; m < got3.size_9b9260(); m++)
									got3.at_9b81f0(m).get_9b65b0()->set_450460(got3.at_9b81f0(m).get_9b65b0()->trap_9b6bf0() * rng.rangeFloat_406e20(0.9f,1.0f));
								break;
							}
							case 8:
							{
								int roll = rng.rangeInt_406d70(1,100);
								if (roll <= 0x21)
								{
									bool small = roll <= 0x10;
									UfHI aH = uf_cefc4c->giveItem_6c52b0("CPS Tube",entity,small,0);
									if (small)
									{
										UfFx *fx = aH.get_9b65b0()->getEffect_457b70(0x44);
										if (fx && fx->value > 1)
											fx->value = 1;
										entity.get_9b6570()->ai_45b590()->unknown5b2d10();
									}
								}
								break;
							}
							case 9:
							{
								UfHE ats = ENTX;
								if (!ats.get_9b6570())
									goto nextEff;
								bool a_ = false;
								UfVPt exits;
								if (uf_d1e888.get_9b7910()->depth == 4)
								{
									UfVZone *zs = uf_cefc4c->zones_462e10();
									for (unsigned m = 0; m < zs->size_9b9260(); m++)
									{
										if (zs->at_9b81f0(m)->loc.get_9b7910()->type == 0x11)
											exits.push_back_9b32e0(zs->at_9b81f0(m)->pt);
									}
									a_ = true;
								}
								else
									uf_cefc4c->unknown714000(&exits);
								int best = -1;
								UfPoint dst(-1);
								for (unsigned m2 = 0; m2 < exits.size_9b9a50(); m2++)
								{
									UfVPt path;
									if (uf_cfe568.findPath_40c9a0(entity.get_9b6570()->getPosition_45a4a0(),exits.at_9e7c10(m2),uf_cefc30,0,path) && (best == -1 || path.size_9b9a50() < best))
									{
										best = path.size_9b9a50();
										dst = exits.at_9e7c10(m2);
									}
								}
								if (dst.x == -1)
								{
									uf_logError_404f10("checkTriggers()::Terminus Leave Map","no exitLoc");
									dst = uf_randomPoint_9d5350(exits);
								}
								else
								{
									entity.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
									entity.get_9b6570()->ai_45b590()->unknown459540(dst);
									if (!entity.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()))
									{
										if (!a_)
											entity.get_9b6570()->ai_45b590()->setField_4593f0(1);
										uf_cefc4c->unknown6c65a0(entity,a_ ? "MAT_Term_Talk_Exit_Cave" : "MAT_Term_Talk_Exit_0b10",0);
									}
								}
								break;
							}
							case 10:
								if (uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown45a840()->xc >= 5)
								{
									uf_message_49c610(0x322,entity,&string("[name]: \"That's a lot of weapons. I approve.\""),&entity.get_9b6570()->getPosition_45a4a0());
									entity.get_9b6570()->unknown6396f0("MAT_Term_Talk_Wep_Slots",1);
								}
								break;
							case 11:
								if (entity.get_9b6570()->unknown5d1280(1))
								{
									uf_message_49c610(0x322,entity,&string("[name]: \"Go on without me. I'll, uh, be fine.\""),&entity.get_9b6570()->getPosition_45a4a0());
									entity.get_9b6570()->unknown639730(1);
								}
								break;
							case 12:
								if (entity.get_9b6570()->unknown5d5250())
								{
									uf_message_49c610(0x322,entity,&string("[name]: \"It looks like the shooting part is up to you now.\""),&entity.get_9b6570()->getPosition_45a4a0());
									entity.get_9b6570()->unknown639730(1);
									entity.get_9b6570()->ai_45b590()->set_451930(0);
									UfPoint dst(-1);
									if (uf_d1e888.get_9b7910()->type == 2)
									{
										for (unsigned m = 0; m < uf_cefc4c->zones_462e10()->size_9b9260(); m++)
										{
											if (uf_cefc4c->zones_462e10()->at_9b81f0(m)->loc.get_9b7910()->type == 3)
											{
												dst = uf_cefc4c->zones_462e10()->at_9b81f0(m)->pt;
												break;
											}
										}
									}
									else
									{
										for (unsigned m2 = 0; m2 < uf_cefc4c->zones_462e10()->size_9b9260(); m2++)
										{
											if (uf_cefc4c->zones_462e10()->at_9b81f0(m2)->loc.get_9b7910()->type == 0x10 || uf_cefc4c->zones_462e10()->at_9b81f0(m2)->loc.get_9b7910()->type == 0x11)
											{
												dst = uf_cefc4c->zones_462e10()->at_9b81f0(m2)->pt;
												break;
											}
										}
									}
									if (dst.x == -1)
										uf_logError_404f10("checkTriggers()::Terminus disarmed","no exitLoc");
									else
									{
										entity.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
										entity.get_9b6570()->ai_45b590()->unknown459540(dst);
										entity.get_9b6570()->ai_45b590()->setField_4593f0(0);
										entity.get_9b6570()->unknown6396f0("MAT_Term_Check_Kills",0);
									}
								}
								break;
							case 13:
								uf_cefc4c->setUnknownA18_4653e0(1);
								if (uf_cefb48)
									uf_cefb48->say_49e250(0x69,0,uf_b91cb6);
								break;
							case 14:
								if (uf_d1e888.get_9b7910()->find_46ee80(8).isValid_9b7230() && !uf_d1eac0 && !uf_d1eabc && (uf_d1e880 && !uf_d257e5 || rng.chance_406c90(0x32)))
								{
									UfPoint sp;
									if (!uf_cefc4c->findPropSpotNear_71c3c0(w3->pos_45d1a0(),sp,0))
										goto rescue14;
									uf_cefc4c->unknown6c6b90(sp,"MIN_Infest_Rescue_Brawn",0,-1);
								}
								else
								{
								rescue14:
									UfVecU dists4;
									UfVBool aJ;
									UfParty *party = uf_cf6428.unknown45ed10();
									UfVZone zones(*uf_cefc4c->zones_462e10());
									for (unsigned m = 0; m < zones.size_9b9260(); m++)
									{
										if (!zones.at_9b81f0(m)->loc.get_9b7910()->inRange_46ecb0())
											uf_eraseAt_9ce6d0(zones,m);
									}
									UfVPt path4;
									for (unsigned m2 = 0; m2 < zones.size_9b9260(); m2++)
									{
										dists4.push_back_9b9280(99999);
										if (party)
										{
											path4.clear_9b3560();
											if (uf_cefc4c->unknown7168e0(party->leader.get_9b6570()->getPosition_45a4a0(),zones.at_9b81f0(m2)->pt,party->leader.get_9b6570(),&path4))
												dists4.back_9b6540() = path4.size_9b9a50();
										}
										aJ.push_back_9b3920(false);
										path4.clear_9b3560();
										UfVPt around;
										if (uf_cfe568.findPath_40c9a0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),zones.at_9b81f0(m2)->pt,uf_cefc30,0,path4))
										{
											for (unsigned m3 = 1; m3 < path4.size_9b9a50(); m3 += 3)
											{
												around.clear_9b3560();
												uf_surrounding_4faaf0(path4.at_9e7c10(m3),&around);
												around.push_back_9b32e0(path4.at_9e7c10(m3));
												for (unsigned m4 = 0; m4 < around.size_9b9a50(); m4++)
												{
													if (CELLAT(around.at_9e7c10(m4))->getEntity_45d250().isValid_9b7230() && CELLAT(around.at_9e7c10(m4))->getEntity_45d250().get_9b6570()->getFaction_45a2c0() == 0x3c)
													{
														aJ.back_9b38e0().set_9b3a70(true);
														goto found14;
													}
												}
											}
										}
									found14:
										;
									}
									UfPoint dest;
									int bestA = uf_fn9d4500(dists4);
									if (!aJ.at_9b38a0(bestA).get_9b3ad0())
										dest = zones.at_9b81f0(bestA)->pt;
									else if (uf_fn9d7670(aJ,false))
										dest = zones.at_9b81f0(uf_fn9d76c0(aJ,false))->pt;
									else
										dest = uf_randomRec_9d5d00(zones)->pt;
									UfHE g = uf_cefc4c->unknown6c5dc0("Guerilla_5",uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),8,0,0x19,0xe,0);
									if (g.isValid_9b7230())
									{
										g.get_9b6570()->ai_45b590()->unknown459540(dest);
										uf_cefc4c->unknown6c65a0(g,"MIN_Infest_Rescue_Talk",0);
										uf_cefc4c->unknown6c65a0(g,"MIN_Infest_Rescue_Fight",0);
									}
								}
								break;
							case 15:
							{
								UfPoint *home = uf_cefc4c->unknown6f0ca0();
								UfHE brawn = uf_cefc4c->unknown6c5dc0("8R-AWN",w3->pos_45d1a0(),9,1,0x19,0xe,0);
								if (brawn.isNull_9b65d0())
									uf_logError_404f10("checkTriggers()","failed to spawn 8R-AWN to " + uf_pointToString_40a4a0(w3->pos_45d1a0()));
								else
								{
									brawn.get_9b6570()->ai_45b590()->unknown459540(*home);
									uf_cefc4c->unknown6c65a0(brawn,"EXI_Brawn_Dialogue_MIN",0);
									uf_cefc4c->unknown6c65a0(brawn,"EXI_Brawn_Score_MIN",0);
									uf_cefc4c->unknown6c65a0(brawn,"EXI_Brawn_Death",0);
								}
								break;
							}
							case 16:
							{
								UfEntityDef *ad;
								if (!uf_findByName_9d7530(uf_d25de0,"Assembled_4",&ad))
									;
								int n = rng.rangeInt_406d70(2,4);
								int radius6 = 10;
								uf_clearDijkstra_4faf40();
								uf_cfe568.unknown40ca20(w3->pos_45d1a0(),0x16,&uf_cfe5e8,0);
								if (uf_d15e58.empty_9b86e0())
									uf_logError_404f10("checkTrigger()::SA_EFFECT_SPECIAL","Cave-in area search failed");
								else
								{
									UfVPt cells7(uf_d15e58);
									uf_shuffle_9d7350(cells7);
									UfPoint c;
									for (unsigned m = 0; m < cells7.size_9b9a50(); m++)
									{
										c = cells7.at_9e7c10(m);
										if (CELLAT(c)->isMachinePart_45dcd0())
											continue;
										if (rng.chance_406c90(10) || CELLAT(c)->getEntity_45d250().isValid_9b7230() && !uf_b95150[CELLAT(c)->getEntity_45d250().get_9b6570()->def_9b4350()->x28])
										{
											if (CELLAT(c)->getProp_45d550().isNull_9b65d0())
											{
												UfFaction *rub;
												if (uf_findByName_9d7710(uf_cf35b0,"Concrete Rubble",&rub))
												{
													UfHP np = uf_cefaa8->createE_793360(rub);
													CELLAT(c)->unknown45df50(np);
													np.get_9b64f0()->unknown45cc50(c);
												}
											}
											if (n && ad && rng.chance_406c90(0x32))
											{
												if (CELLAT(c)->canPlaceEntity_66ad20(1))
												{
													n--;
													UfHE se = uf_cefc4c->placeEntity_6c58c0(ad,c,5,0,0x22,0xe,0);
												}
												uf_opR1d_454260(&c,0x102);
											}
										}
										else
											CELLAT(c)->unknown66d580(1);
									}
									uf_cf6428.unknown68b9a0(cells7,0);
									uf_cefaa8->showOnce_793450(0x43,1,0,0,0);
								}
								break;
							}
							case 17:
							{
								bool found = false;
								UfVZone *zs = uf_cefc4c->zones_462e10();
								UfVPt path;
								for (unsigned m = 0; m < zs->size_9b9260(); m++)
								{
									if (uf_cfe568.findPath_40c9a0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),zs->at_9b81f0(m)->pt,uf_cefc30,0,path))
									{
										found = true;
										break;
									}
								}
								if (!found)
								{
									path.clear_9b3560();
									path.push_back_9b32e0(w3->pos_45d1a0());
									uf_cf6428.unknown68b9a0(path,1);
								}
								break;
							}
							case 18:
							case 19:
							case 20:
							{
								UfHE col = w3->getEntity_45d250();
								int kindD;
								switch (uf_stringToInt_405610(string(eff->s1bc.begin() + 1,eff->s1bc.end())))
								{
									case 18:
										kindD = 0x14;
										break;
									case 19:
										kindD = 0x15;
										break;
									default:
										kindD = 0x17;
								}
								UfHE node;
								if (!uf_findNode_470180(kindD,-1,uf_d1e884,&node))
									goto tunnel18;
								uf_d1e860.addExit_7892d0(node,w3->pos_45d1a0(),col.get_9b6570()->getName_416f40());
							tunnel18:
								col.get_9b6570()->unknown637bb0();
								string msg = uf_d1ea8c.back_9b06c0() + " disappears into a concealed tunnel.";
								uf_message_49c610(0x320,UfHE(),&msg,0);
								break;
							}
							case 21:
								if (uf_d1e860.hasObjectID_46fa40(1))
								{
									UfVBP cands;
									UfVecU lists8;
									for (int i = 0; i < 15; i++)
									{
										for (unsigned j = 0; j < uf_d1e97c[i].size_9b9260(); j++)
										{
											if (uf_d1e97c[i].at_9b81f0(j)->x0 == 1)
											{
												cands.push_back_9b9d30(uf_d1e97c[i].at_9b81f0(j));
												lists8.push_back_9b9280(+i);
											}
										}
									}
									int r7 = uf_randomIndex_9d9b20(cands);
									UfBP *bp = cands.at_9b81f0(r7);
									UfPoint aT(uf_cefc4c->unknown4184d0());
									if (uf_cefc4c->findPlaceableNear_71c150(aT,aT,1))
									{
										UfHE ne = uf_cefc4c->unknown6c5e20(bp,aT,lists8.at_9b81f0(r7),0,1,1);
										if (uf_d1e888.get_9b7910()->type == 0xc)
										{
											do
											{
												if (uf_show_5111e0b(0x229,0,0,0,ne,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											uf_opR1d_454260(&ne.get_9b6570()->getPosition_45a4a0(),0xa0);
										}
										else
										{
											do
											{
												if (uf_show_5111e0b(0x244,0,0,0,ne,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
										}
										bp->b34 = false;
										uf_deleteObject_9d7850(uf_d1e97c[lists8.at_9b81f0(r7)],uf_fn9d4660(uf_d1e97c[lists8.at_9b81f0(r7)],bp));
										if (uf_d1e97c[lists8.at_9b81f0(r7)].empty_9b86e0())
										{
											do
											{
												uf_logPhrase_5141b0(0x18a,&uf_intToString_4051f0(uf_d1ea6c.at_9b81f0(lists8.at_9b81f0(r7))),0,0,UfHE(),0);
											}
											while (0);
										}
									}
								}
								break;
							case 22:
								w3->getEntity_45d250().get_9b6570()->ai_45b590()->setField_4593f0(1);
								uf_cefc4c->unknown6c65a0(w3->getEntity_45d250(),"EXI_Brawn_Enters_MIN",0);
								break;
							case 23:
							{
								UfPoint *home = uf_cefc4c->unknown6f0ca0();
								w3->getEntity_45d250().get_9b6570()->setAI_64ecf0(new UfEntityAI(w3->getEntity_45d250(),0x19,0xe));
								w3->getEntity_45d250().get_9b6570()->ai_45b590()->unknown459540(*home);
								break;
							}
							case 24:
								uf_d2c658.add_472b90(0x28,-999999);
								do
								{
									uf_logPhrase_5141b0(0x12e,0,0,0,UfHE(),0);
								}
								while (0);
								uf_cec138->unknown969300();
								uf_d1e860.setEntryText_46f700("exiFarcomEnabled_g","1");
								uf_d1eacc = true;
								break;
							case 25:
								if (uf_d1eac0 == 1 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("exiMaincAttacked_g")))
								{
									if (uf_d1eac4 == -1)
										uf_d1eac4 = uf_cefc4c->unknown4642f0();
									else if (uf_cefc4c->unknown4642f0() - uf_d1eac4 >= 0x28)
										uf_cefc4c->unknown738310();
								}
								break;
							case 26:
							{
								UfRect r;
								UfPoint p;
								uf_cfd44c.getRect_9b4430(w3->pos_45d1a0(),0xf,r);
								for (int i = 0; i < 500; i++)
								{
									r.randomPoint_40be30(&p);
									if (CELLAT(p)->getProp_45d550().isValid_9b7230() && CELLAT(p)->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd8)
									{
										uf_cefc4c->unknown6c6700(CELLAT(p)->getProp_45d550(),"SUB_Revenge_Delayed",0);
										break;
									}
								}
								if (w3->getEntity_45d250().isValid_9b7230() && w3->getEntity_45d250().get_9b6570()->unknown45af90().get_9b6570() && w3->getEntity_45d250().get_9b6570()->unknown45af90().get_9b6570()->isPlayer_5c7600())
									uf_cf45d8.unlock_77fbc0(0x1a);
								break;
							}
							case 27:
							{
								UfVZone zones(*uf_cefc4c->zones_462e10());
								uf_shuffle_9d8f80(zones);
								UfVPt path2;
								for (unsigned m = 0; m < zones.size_9b9260(); m++)
								{
									if (!uf_cfe568.findPath_40c9a0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),zones.at_9b81f0(m)->pt,uf_cefc40,0,path2))
										path2.clear_9b3560();
									else
										break;
								}
								int radius9 = 10;
								uf_clearDijkstra_4faf40();
								uf_cfe568.unknown40ca20(w3->pos_45d1a0(),0x16,&uf_cfe5e8,0);
								if (uf_d15e58.empty_9b86e0())
									goto end27;
								{
									bool vis = false;
									UfVPt cells0(uf_d15e58);
									uf_shuffle_9d7350(cells0);
									UfPoint c0;
									for (unsigned m2 = 0; m2 < cells0.size_9b9a50(); m2++)
									{
										c0 = cells0.at_9e7c10(m2);
										if (CELLAT(c0)->isMachinePart_45dcd0())
											continue;
										if (rng.chance_406c90(0x32) || CELLAT(c0)->getEntity_45d250().isValid_9b7230() && uf_b95150[CELLAT(c0)->getEntity_45d250().get_9b6570()->def_9b4350()->x28] && !CELLAT(c0)->getEntity_45d250().get_9b6570()->isPlayer_5c7600() && CELLAT(c0)->getEntity_45d250().ne_9b6510(uf_cefc4c->getEntity671_463110()))
											CELLAT(c0)->unknown66d580(1);
										else if (CELLAT(c0)->getProp_45d550().isNull_9b65d0())
										{
											UfFaction *rub;
											if (uf_findByName_9d7710(uf_cf35b0,"Concrete Rubble",&rub))
											{
												UfHP np = uf_cefaa8->createE_793360(rub);
												CELLAT(c0)->unknown45df50(np);
												np.get_9b64f0()->unknown45cc50(c0);
											}
										}
										if (uf_cefc4c->isVisible_4631c0(c0))
											vis = true;
									}
									if (vis)
									{
										string msg = "A swath of the cavern ceiling suddenly collapses.";
										uf_message_49c610(0x320,UfHE(),&msg,0);
										do
										{
											uf_logPhrase_5141b0(0x11f,0,0,0,UfHE(),0);
										}
										while (0);
									}
									UfVZone *bC = uf_cefc4c->zones_462e10();
									for (unsigned m3 = 0; m3 < bC->size_9b9260(); m3++)
									{
										UfVPt p2;
										if (uf_cfe568.findPath_40c9a0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),bC->at_9b81f0(m3)->pt,uf_cefc30,0,p2))
											goto skip27;
									}
									for (unsigned m4 = 0; m4 < path2.size_9b9a50(); m4++)
									{
										if (CELLAT(path2.at_9e7c10(m4))->def_9fcd80() == uf_cefb84)
											CELLAT(path2.at_9e7c10(m4))->unknown66a050(*uf_cefb9c,2,0);
									}
								skip27:
									;
								}
							end27:
								break;
							}
							case 28:
							{
								void *src = uf_unknown777cf0();
								UfHI it = uf_cefc4c->unknown6c5400(src,w3->pos_45d1a0());
								if (it.isValid_9b7230())
								{
									string msg = it.get_9b65b0()->getName_571db0(0,0) + " falls loose from the Twisted Machinery.";
									uf_message_49c610(0x320,UfHE(),&msg,0);
									do
									{
										uf_logPhrase_5141b0(0x11b,&it.get_9b65b0()->getName_571db0(0,0),0,0,UfHE(),0);
									}
									while (0);
									uf_opR1d_454260(&uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0xb1);
								}
								break;
							}
							case 29:
								if (!uf_cefc4c->isVisible_4631c0(uf_cefc4c->unknown4184d0()) && uf_distanceCeil_40a3f0(uf_cefc4c->unknown4184d0(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0()) >= uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5c7d30() + 10)
								{
									int radius = 12;
									uf_clearDijkstra_4faf40();
									uf_cfe568.unknown40ca20(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0x1a,&uf_d395f0,0);
									if (uf_d15e58.empty_9b86e0())
										goto end29;
									{
										UfVPt cells(uf_d15e58);
										UfPoint c6(-1);
										for (unsigned m = 0; m < cells.size_9b9a50(); m++)
										{
											if (CELLAT(cells.at_9e7c10(m))->def_9fcd80() == uf_cefb80)
											{
												c6 = cells.at_9e7c10(m);
												break;
											}
										}
										if (c6.x == -1)
										{
											uf_shuffle_9d7350(cells);
											for (unsigned m2 = 0; m2 < cells.size_9b9a50(); m2++)
											{
												if (CELLAT(cells.at_9e7c10(m2))->getProp_45d550().isNull_9b65d0())
												{
													c6 = cells.at_9e7c10(m2);
													break;
												}
											}
										}
										if (c6.x == -1)
											goto skip29;
										{
											UfVPt den;
											uf_surrounding_4faaf0(c6,&den);
											for (int m3 = den.size_9b9a50() - 1; m3 >= 0; m3--)
											{
												if (!CELLAT(den.at_9e7c10(m3))->fitsProp_45d570(0))
													uf_eraseAt_9d5190(den,m3);
											}
											den.push_back_9b32e0(c6);
											bool shown = false;
											for (unsigned m4 = 0; m4 < den.size_9b9a50(); m4++)
											{
												CELLAT(den.at_9e7c10(m4))->unknown66a050(*uf_cefb9c,2,0);
												UfHP np = uf_cefaa8->createE_793360(uf_cefbd8);
												CELLAT(den.at_9e7c10(m4))->unknown45df50(np);
												np.get_9b64f0()->unknown45cc50(den.at_9e7c10(m4));
												if (!shown && uf_cefc4c->isVisible_4631c0(den.at_9e7c10(m4)))
												{
													uf_message_49c610(0x320,UfHE(),&string("A mess of Twisted Machinery falls from the cavern ceiling."),0);
													shown = true;
												}
											}
											do
											{
												uf_logPhrase_5141b0(0x119,0,0,0,UfHE(),0);
											}
											while (0);
											uf_opR1d_4542a0(&c6,0xab,0x14);
											uf_opR1d_454260(&c6,0xb2);
											for (int k = 0; k < 6; k++)
											{
												UfPoint rp = uf_randomPoint_9d5350(den);
												uf_cefc4c->unknown6c6700(CELLAT(rp)->getProp_45d550(),"SUB_TMachinery_Sub_Time",1);
												uf_cefc4c->unknown6c6700(CELLAT(rp)->getProp_45d550(),"SUB_TMachinery_Subs_Dst",1);
											}
											UfVPt open;
											for (unsigned m5 = 0; m5 < den.size_9b9a50(); m5++)
											{
												if (uf_cefc4c->countPassableAdjacent_71c850(den.at_9e7c10(m5)))
													open.push_back_9b32e0(den.at_9e7c10(m5));
											}
											if (open.empty_9b86e0())
												goto subs29;
											{
												c6 = uf_randomPoint_9d5350(open);
												UfHE sd = uf_cefc4c->unknown6c5dc0("Subdweller",c6,6,0,0x22,0xe,0);
												if (sd.isValid_9b7230())
												{
													UfRect r;
													uf_cfd44c.getRect_9b4430(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),10,r);
													sd.get_9b6570()->ai_45b590()->unknown459470(r);
													if (uf_cefc4c->unknown4631f0(sd))
														uf_message_49c610(0x320,sd,&string("[name] comes tumbling into view."),0);
												}
											}
										subs29:
											UfVHE &g9 = uf_cefc4c->group_463890(9).get_9b7250()->members_416f40();
											for (unsigned m6 = 0; m6 < g9.size_9b9260(); m6++)
											{
												if (uf_strEq_9ccb50(g9.at_9b81f0(m6).get_9b6570()->getName_45a280(),"Guerilla_7") && g9.at_9b81f0(m6).get_9b6570()->ai_45b590()->getFollowEntity_458ed0().eq_9b78e0(uf_cefc4c->getPlayer_4630f0()))
												{
													entity = g9.at_9b81f0(m6);
													break;
												}
											}
											if (entity.isValid_9b7230())
											{
												uf_cefc4c->unknown6c65a0(entity,"SUB_Entrance_Dialogue3",0);
												c6 = uf_cefc4c->unknown71d000(3);
												if (c6.x != -1)
												{
													for (int k2 = 0; k2 < 3; k2++)
													{
														entity = uf_cefc4c->unknown6c5dc0("Thug_5",c6,9,0,0x22,0xe,0);
														if (entity.isValid_9b7230())
														{
															entity.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
															if (k2 == 0)
																uf_cefc4c->unknown6c65a0(entity,"SUB_Entrance_Dialogue4",0);
														}
													}
												}
											}
										}
									skip29:
										;
									}
								end29:
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								}
								break;
							case 30:
							{
								UfVPt exitsTmp;
								uf_cefc4c->unknown714000(&exitsTmp);
								UfPoint dst = uf_randomPoint_9d5350(exitsTmp);
								UfVHE &g9 = uf_cefc4c->group_463890(9).get_9b7250()->members_416f40();
								for (unsigned m = 0; m < g9.size_9b9260(); m++)
								{
									g9.at_9b81f0(m).get_9b6570()->ai_45b590()->unknown4582d0(0x19);
									g9.at_9b81f0(m).get_9b6570()->ai_45b590()->unknown459540(dst);
									g9.at_9b81f0(m).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
								}
								break;
							}
							case 31:
							{
								UfVStr2 names;
								names.push_back_9b06f0("Powered Cannon");
								names.push_back_9b06f0("Meta Core");
								names.push_back_9b06f0("Rainbow Chip");
								names.push_back_9b06f0("Power Bank");
								names.push_back_9b06f0("Cargo Legs");
								names.push_back_9b06f0("Gun Armor");
								names.push_back_9b06f0("Flightbrick");
								names.push_back_9b06f0("Arachnoskeleton");
								names.push_back_9b06f0("Maxwheels");
								for (int x = 0; x < uf_cfd44c.getWidth_9fcd80(); x++)
								{
									for (int y = 0; y < uf_cfd44c.getHeight_9b8f00(); y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->unknown457f90() == 0xd4)
										{
											uf_fn9d78c0(names,(*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->name_457860());
											break;
										}
									}
								}
								UfHE e19 = ENTX;
								if (!e19.get_9b6570())
									goto nextEff;
								UfHI aS = uf_cefc4c->giveItem_6c52b0(uf_randomString_9d3280(names),e19,0,0);
								aS.get_9b65b0()->set_450460(aS.get_9b65b0()->unknown457c80() - rng.rangeInt_406d70(1,10));
								break;
							}
							case 32:
							{
								UfHE el4 = ENTX;
								if (!el4.get_9b6570())
	goto nextEff;
								uf_cefc4c->unknown74d560(0xe,5,0,*uf_cfe674);
								el4.get_9b6570()->unknown5dcc70(0xe,0);
								UfVHE2 dB;
								UfRect r;
								uf_cfd44c.getRect_9b4430(el4.get_9b6570()->getPosition_45a4a0(),5,r);
								for (int x = r.x1; x <= r.x2; x++)
								{
	for (int y = r.y1; y <= r.y2; y++)
	{
		if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->getFaction_45a2c0() == 0x30)
			dB.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250());
	}
								}
								for (unsigned m = 0; m < dB.size_9b9260(); m++)
								{
	dB.at_9b81f0(m).get_9b6570()->unknown5dcc70(0xe,0);
	dB.at_9b81f0(m).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(el4,0);
	UfItemDef *d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,0x1f,0,0x2a,0);
	if (d)
		uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
	UfWL wl;
	wl.add_9ba310(9,1);
	wl.add_9ba310(10,1);
	wl.add_9ba310(11,1);
	int kindA = wl.pick_9ba470();
	for (int k = 0; k < 2; k++)
	{
		do
		{
			d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,kindA,0x12,0x2a,0);
			if (!d)
				break;
		}
		while (d->x4c != 1);
		if (d)
			uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
	}
	UfWL wl2;
	uf_cefc4c->unknown6c3a50(wl2,0,3);
	UfVecU *a0 = wl2.keys_9c0790();
	UfVIDef2 defs3;
	for (unsigned m2 = 0; m2 < a0->size_9b9260(); m2++)
		defs3.push_back_9b9d30(uf_d2d1c4.at_9b81f0(a0->at_9b81f0(m2)));
	int bA = dB.at_9b81f0(m).get_9b6570()->unknown5c92e0(2);
	UfVIDef2 cand;
									for (unsigned m3 = 0; m3 < defs3.size_9b9260(); m3++)
									{
										if (defs3.at_9b81f0(m3)->xf0 == 1 || defs3.at_9b81f0(m3)->xf0 == 2)
											cand.push_back_9b9d30(defs3.at_9b81f0(m3));
									}
									if (!cand.empty_9b86e0())
									{
										d = uf_randomRec_9d5d00(cand);
										uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
										bA -= d->x4c;
									}
									cand.clear_9bac80();
									for (unsigned m4 = 0; m4 < defs3.size_9b9260(); m4++)
									{
										if (defs3.at_9b81f0(m4)->xf0 == 8 || defs3.at_9b81f0(m4)->xf0 == 9)
											cand.push_back_9b9d30(defs3.at_9b81f0(m4));
									}
									if (!cand.empty_9b86e0())
									{
										d = uf_randomRec_9d5d00(cand);
										uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
										bA -= d->x4c;
									}
									cand.clear_9bac80();
									for (unsigned m5 = 0; m5 < defs3.size_9b9260(); m5++)
									{
										if ((defs3.at_9b81f0(m5)->xf0 == 0x2e || defs3.at_9b81f0(m5)->xf0 == 0x2f || defs3.at_9b81f0(m5)->xf0 == 0x30 || defs3.at_9b81f0(m5)->xf0 == 0x42 || defs3.at_9b81f0(m5)->xf0 == 0x43) && defs3.at_9b81f0(m5)->x4c <= bA)
											cand.push_back_9b9d30(defs3.at_9b81f0(m5));
									}
									if (!cand.empty_9b86e0())
									{
										d = uf_randomRec_9d5d00(cand);
										uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
										bA -= d->x4c;
									}
									if (rng.chance_406c90(0x32))
									{
										bool has = dB.at_9b81f0(m).get_9b6570()->unknown5d5c30().isValid_9b7230();
										cand.clear_9bac80();
										for (unsigned m6 = 0; m6 < defs3.size_9b9260(); m6++)
										{
											if (defs3.at_9b81f0(m6)->xf0 == (has ? 0x5a : 0x55) && defs3.at_9b81f0(m6)->x4c <= bA)
												cand.push_back_9b9d30(defs3.at_9b81f0(m6));
										}
										if (!cand.empty_9b86e0())
										{
											d = uf_randomRec_9d5d00(cand);
											uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											bA -= d->x4c;
										}
									}
									if (rng.chance_406c90(0x32))
									{
										cand.clear_9bac80();
										for (unsigned m7 = 0; m7 < defs3.size_9b9260(); m7++)
										{
											if ((defs3.at_9b81f0(m7)->xf0 == 0xa || defs3.at_9b81f0(m7)->xf0 == 0xb || defs3.at_9b81f0(m7)->xf0 == 0x12 || defs3.at_9b81f0(m7)->xf0 == 0x18) && defs3.at_9b81f0(m7)->x4c <= bA)
												cand.push_back_9b9d30(defs3.at_9b81f0(m7));
										}
										if (!cand.empty_9b86e0())
										{
											d = uf_randomRec_9d5d00(cand);
											uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											bA -= d->x4c;
										}
									}
									UfWL wl3;
									wl3.add_9ba310(0,100);
									wl3.add_9ba310(1,100);
									wl3.add_9ba310(2,25);
									wl3.add_9ba310(3,50);
									wl3.add_9ba310(4,25);
									wl.reset_9c07a0();
									int pick5 = wl3.pick_9ba470();
									switch (pick5)
									{
										case 0:
											for (int k2 = 0; k2 < 2; k2++)
											{
												d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,rng.chance_406c90(0x32) ? 0x14 : 0x16,0x12,0x2a,0);
												if (d)
													uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											}
											break;
										case 1:
											d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,rng.chance_406c90(0x32) ? 0x15 : 0x17,0x12,0x2a,0);
											if (d)
												uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											break;
										case 2:
											for (int k3 = 0; k3 < 2; k3++)
											{
												do
												{
													d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,rng.chance_406c90(0x32) ? 0x15 : 0x17,0x12,0x2a,0);
													if (!d)
														break;
												}
												while (d->x4c != 1);
												if (d)
													uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											}
											break;
										case 3:
											d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,rng.chance_406c90(0x32) ? 0x1a : 0x1b,0x12,0x2a,0);
											if (d)
												uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											break;
										case 4:
											for (int k4 = 0; k4 < 2; k4++)
											{
												d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,3),0,0,rng.chance_406c90(0x32) ? 0x1a : 0x1b,0x12,0x2a,0);
												if (d)
													uf_cefc4c->unknown6c51d0(d,dB.at_9b81f0(m),1,0);
											}
											break;
									}
									UfVStr2 names5;
									if (dB.at_9b81f0(m).get_9b6570()->unknown45ab20("Mining Claw"))
									{
										names5.push_back_9b06f0("Botminer");
										names5.push_back_9b06f0("All I Could Find");
									}
									else if (dB.at_9b81f0(m).get_9b6570()->unknown45ab20("Hvy. Armor Plating") && kindA == 10)
										names5.push_back_9b06f0("Shellwalker");
									else if (dB.at_9b81f0(m).get_9b6570()->unknown45ab20("Shield Generator") && kindA == 9)
										names5.push_back_9b06f0("Bubbletank");
									else if (pick5 == 3 && kindA == 9)
									{
										names5.push_back_9b06f0("Patient One");
										names5.push_back_9b06f0("Please Let Me Get Close");
										names5.push_back_9b06f0("Be With You Shortly");
									}
									else if (pick5 == 3)
									{
										names5.push_back_9b06f0("Chopster");
										names5.push_back_9b06f0("Facepuncher");
										if (dB.at_9b81f0(m).get_9b6570()->unknown5d7d60(4))
											names5.push_back_9b06f0("Hermelin Impact");
										if (dB.at_9b81f0(m).get_9b6570()->unknown5d7d60(5))
											names5.push_back_9b06f0("Slice 'n Dice");
										names5.push_back_9b06f0("Slash Mode");
									}
									else if (pick5 == 4)
									{
										names5.push_back_9b06f0("Gladiator");
										names5.push_back_9b06f0("Hackmaster 2000");
										names5.push_back_9b06f0("No Trespassing x2");
									}
									else if (pick5 == 0 && dB.at_9b81f0(m).get_9b6570()->unknown5d7d60(0))
									{
										names5.push_back_9b06f0("Dakkacube");
										if (kindA == 10)
											names5.push_back_9b06f0("Run 'n Gun");
									}
									else if (pick5 == 0 && dB.at_9b81f0(m).get_9b6570()->unknown5d7d60(1))
									{
										names5.push_back_9b06f0("Meltycube");
										names5.push_back_9b06f0("Warm Welcome");
										if (kindA == 0xb)
											names5.push_back_9b06f0("Hotrod");
									}
									else if (pick5 == 0 && dB.at_9b81f0(m).get_9b6570()->unknown5d7d60(3))
									{
										names5.push_back_9b06f0("Zapcube");
										if (kindA == 0xb)
										{
											names5.push_back_9b06f0("Shockroller");
											names5.push_back_9b06f0("Rolling Thunder");
										}
									}
									else if (pick5 == 0)
									{
										names5.push_back_9b06f0("Guncrazy");
										names5.push_back_9b06f0("Double Barrel");
										names5.push_back_9b06f0("Gunmaster");
									}
									else if (pick5 == 1)
									{
										names5.push_back_9b06f0("Budget Cyclops");
										names5.push_back_9b0340(dB.at_9b81f0(m).get_9b6570()->unknown5d5b20().get_9b65b0()->unknown457990() + " Carrier");
									}
									else if (pick5 == 1 && dB.at_9b81f0(m).get_9b6570()->unknown5d26e0(0x55))
										names5.push_back_9b06f0("Snipey");
									else if (pick5 == 3 && dB.at_9b81f0(m).get_9b6570()->unknown5d26e0(0x5a))
									{
										names5.push_back_9b0340(dB.at_9b81f0(m).get_9b6570()->unknown5d5c30().get_9b65b0()->unknown457990() + " Pro");
										names5.push_back_9b0340(dB.at_9b81f0(m).get_9b6570()->unknown5d5c30().get_9b65b0()->unknown457990() + "master");
									}
									else if (pick5 == 2)
									{
										names5.push_back_9b06f0("Overkill");
										names5.push_back_9b06f0("Flee or Die");
										names5.push_back_9b06f0("OP.CUBE");
										names5.push_back_9b06f0("Face Your Regrets");
										names5.push_back_9b06f0("Angry About Something");
									}
									else if (kindA == 0xb)
									{
										names5.push_back_9b06f0("Wheely Good");
										names5.push_back_9b06f0("Wheeled Menace");
										if (dB.at_9b81f0(m).get_9b6570()->unknown5d5b20().isValid_9b7230())
											names5.push_back_9b06f0("Walkie-shootie");
									}
									else if (kindA == 0xa)
									{
										names5.push_back_9b06f0("Leggy");
										names5.push_back_9b06f0("Legster");
									}
									else
									{
										names5.push_back_9b06f0("Treadmonster");
										names5.push_back_9b06f0("Tready Thing");
									}
									dB.at_9b81f0(m).get_9b6570()->unknown45b070(uf_randomString_9d3280(names5));
								}
								break;
							}
							case 33:
								if (uf_cefc4c->unknown4642d0() == 1)
								{
									UfEntityDef *sci;
									if (uf_findByName_9d7530(uf_d25de0,"Scientist",&sci))
									{
										UfPoint sp(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
										uf_clearDijkstra_4faf40();
										uf_cfe568.unknown40ca20(sp,999,&uf_d25624,0);
										if (!uf_d15e58.empty_9b86e0())
											sp = uf_randomPoint_9d5350(uf_d15e58);
										UfHE g22 = uf_cefc4c->placeEntity_6c58c0(sci,sp,0xa,0,0x22,0xe,0);
										if (g22.isValid_9b7230())
										{
											g22.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
											uf_cefc4c->unknown6c65a0(g22,"SUB_Scientist_Escort_T",0);
											g22.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(0x96),1));
										}
									}
								}
								else
								{
									UfHE sci;
									UfVHE &g10 = uf_cefc4c->group_463890(10).get_9b7250()->members_416f40();
									for (unsigned m = 0; m < g10.size_9b9260(); m++)
									{
										if (g10.at_9b81f0(m).get_9b6570()->unknown45acb0(0x96))
										{
											sci = g10.at_9b81f0(m);
											break;
										}
									}
									if (sci.isNull_9b65d0())
										prop.get_9b64f0()->unknown45ce10(1,0,1,UfHE());
									else if (uf_cefc4c->isReachable_465230(0x10,sci.get_9b6570()->getPosition_45a4a0(),prop.get_9b64f0()->pos_4184d0()))
									{
										UfPoint pp(prop.get_9b64f0()->pos_4184d0());
										sci.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
										sci.get_9b6570()->ai_45b590()->unknown459540(pp);
										sci.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
										uf_cefc4c->unknown6c65a0(sci,"SUB_Scientist_Escort_T3",0);
										prop.get_9b64f0()->unknown45ce10(1,0,1,UfHE());
										UfHE g31;
										if (!uf_findNode_470180(0xb,-1,uf_d1e884,&g31))
											goto exit33;
										uf_d1e860.addExit_7892d0(g31,pp,uf_b91cb7);
									exit33:
										;
									}
									else if (uf_cefc4c->unknown4642d0() % 0x33 == 0 && uf_distanceCeil_40a3f0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),sci.get_9b6570()->getPosition_45a4a0()) <= 0xf)
									{
										string s("[name]: \"");
										if (uf_distanceCeil_40a3f0(sci.get_9b6570()->getPosition_45a4a0(),prop.get_9b64f0()->pos_4184d0()) <= 0x14)
											s += "We're getting close, I can feel it.";
										else
										{
											int dir = uf_pointsFn_4374c0(sci.get_9b6570()->getPosition_45a4a0(),prop.get_9b64f0()->pos_4184d0());
											s += "I think it's somewhere " + uf_d30268[dir] + " of here";
										}
										s += "\"";
										uf_message_49c610(0x322,sci,&s,0);
									}
								}
								break;
							case 34:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (e.get_9b6570()->unknown45a9d0())
								{
									UfVPt around;
									uf_surrounding_4faaf0(w3->pos_45d1a0(),&around);
									for (unsigned m = 0; m < around.size_9b9a50(); m++)
									{
										if (CELLAT(around.at_9e7c10(m))->getProp_45d550().isValid_9b7230() && !CELLAT(around.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown457b10())
										{
											e.get_9b6570()->set_44e2c0(0);
											do
											{
												uf_logPhrase_5141b0(0xf5,0,0,0,UfHE(),0);
											}
											while (0);
											do
											{
												if (uf_show_5111e0b(0x320,&string("LOCAL NARROWCAST: Corruption nullified, you may proceed."),0,0,UfHE(),UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											int *fx;
											if (uf_lookup2_9d7980("P_SCR_Corruption_Clear",&fx))
												uf_playEffect_55ca10(*fx,w3->pos_45d1a0(),0);
											uf_sound_4541b0(0x88,0,0);
											break;
										}
									}
								}
								break;
							}
							case 35:
								uf_cf45d8.unknown783020();
								break;
							case 36:
								uf_cf45d8.unknown783060();
								break;
							case 37:
							{
								UfHP p = (*uf_cfd44c.at_9ceda0(0x62,0x35))->getProp_45d550();
								if (p.isNull_9b65d0())
									goto follow37;
								{
									UfMach *mc = p.get_9b64f0()->unknown45cb30();
									if (!mc)
										goto follow37;
									for (unsigned m = 0; m < mc->v18.size_9b9260(); m++)
									{
										if (mc->v18.at_9b81f0(m)->x0 == 0 && uf_strEq_9ccb50(uf_d35b58.at_9b81f0(mc->v18.at_9b81f0(m)->x4)->name4,"0bP002 Project Fedlink"))
										{
											int next = mc->v18.at_9b81f0(m)->x4 + 1;
											if (uf_strNe_9ceb30(uf_d35b58.at_9b81f0(next)->name4,"0bP002 Fedlink Acceleration"))
											{
												next = -1;
												for (unsigned k = 0; k < uf_d35b58.size_9b9260(); k++)
												{
													if (uf_strEq_9ccb50(uf_d35b58.at_9b81f0(k)->name4,"0bP002 Fedlink Acceleration"))
													{
														next = k;
														break;
													}
												}
											}
											if (next == -1)
												goto brk37;
											mc->v18.at_9b81f0(m)->x4 = next;
											mc->v18.at_9b81f0(m)->b8 = false;
										brk37:
											break;
										}
									}
								}
							follow37:
								UfHE g45 = ENTX;
								if (!g45.get_9b6570())
									goto nextEff;
								g45.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
								uf_d1eb08 = uf_cefc4c->unknown4642d0();
								UfVPt path;
								uf_cfe568.findPath_40c9a0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),UfPoint(0x7a,0xe),uf_cefc30,0,path);
								int len = path.size_9b9a50();
								len += 10;
								if (uf_d1eb0c < len)
									uf_d1eb0c = len;
								uf_d1eb0c += uf_cefc4c->unknown4642f0();
								uf_d257e7 = true;
								break;
							}
							case 38:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (e.get_9b6570()->unknown45aa30() >= 0x14)
								{
									UfPoint dst(0x7a,0xe);
									e.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
									e.get_9b6570()->ai_45b590()->unknown459540(dst);
									e.get_9b6570()->ai_45b590()->set_44e540(10);
									e.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
									uf_cefc4c->unknown6c65a0(e,"SCR_Optimus_CW_Retreat2",0);
									e.get_9b6570()->removeEffects_45b4c0(defVal,true);
									UfEntityDef *el;
									if (uf_findByName_9d7530(uf_d25de0,"Elite_4",&el))
									{
										for (int k = 0; k < 3; k++)
										{
											UfHE ne = uf_cefc4c->placeEntity_6c58c0(el,dst,0xa,0,0x19,0xe,0);
											if (ne.isValid_9b7230())
											{
												ne.get_9b6570()->ai_45b590()->unknown459540(dst);
												ne.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(e,0);
												ne.get_9b6570()->ai_45b590()->set_44e540(10);
											}
										}
									}
								}
								break;
							}
							case 39:
							{
								UfHE g49 = ENTX;
								if (!g49.get_9b6570())
									goto nextEff;
								UfHE t = uf_cefc4c->unknown715230(0xe,0x4d);
								if (t.isValid_9b7230() && uf_cefc4c->isReachable_465230(g49.get_9b6570()->unknown5c7d30(),g49.get_9b6570()->getPosition_45a4a0(),t.get_9b6570()->getPosition_45a4a0()))
								{
									if (uf_cefc4c->unknown4631f0(g49))
										uf_message_49c610(0x322,entity,&string("[name]: \"Someone shut down Triborg? Who would do that? How?!\""),&entity.get_9b6570()->getPosition_45a4a0());
									g49.get_9b6570()->removeEffects_45b4c0(defVal,true);
								}
								break;
							}
							case 40:
								uf_cefaa8->unknown793690();
								uf_unknown789ac0();
								break;
							case 41:
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrEnhScrapShieldGave_g")))
								{
									UfHI best;
									UfVHI *inv = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getInventoryList_45ab00();
									for (int pass = 0; pass < 2; pass++)
									{
										for (unsigned m = 0; m < inv->size_9b9260(); m++)
										{
											if (inv->at_9b81f0(m).get_9b65b0()->def_9b4350() == uf_cefbe8 && (pass == 1 || !uf_cec088->isLinked_4a9b10(inv->at_9b81f0(m))) && (best.isNull_9b65d0() || inv->at_9b81f0(m).get_9b65b0()->unknown457ca0() < best.get_9b65b0()->unknown457ca0()))
												best = inv->at_9b81f0(m);
										}
										if (best.isValid_9b7230())
											break;
									}
									if (best.isValid_9b7230())
									{
										best.get_9b65b0()->remove_57dbe0(1,0,0,1);
										uf_d1e860.setEntryText_46f700("scrEnhScrapShieldGave_g","1");
										do
										{
											uf_logPhrase_5141b0(0xfc,0,0,0,UfHE(),0);
										}
										while (0);
										break;
									}
								}
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrEnhScrapShieldGave_g")) == 1)
								{
									uf_d1e860.setEntryText_46f700("scrEnhScrapShieldGave_g","2");
									break;
								}
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrEnhScrapShieldNone_g")))
								{
									uf_d1e860.setEntryText_46f700("scrEnhScrapShieldNone_g","1");
									break;
								}
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrEnhScrapShieldNone_g")) == 1)
								{
									uf_d1e860.setEntryText_46f700("scrEnhScrapShieldNone_g","2");
									break;
								}
								break;
							case 42:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrNameChangerChanged_g")))
								{
									UfHI best;
									UfVHI *inv = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getInventoryList_45ab00();
									for (unsigned m = 0; m < inv->size_9b9260(); m++)
									{
										if (inv->at_9b81f0(m).get_9b65b0()->def_9b4350()->x40 == 0x1d && (best.isNull_9b65d0() || inv->at_9b81f0(m).get_9b65b0()->unknown457ca0() > best.get_9b65b0()->unknown457ca0()))
											best = inv->at_9b81f0(m);
									}
									if (best.isValid_9b7230())
									{
										uf_cf4acc = uf_cf4b04;
										best.get_9b65b0()->unknown57a190(e,4,1,0);
										uf_d1e860.setEntryText_46f700("scrNameChangerChanged_g","1");
										do
										{
											uf_logPhrase_5141b0(0xfd,&uf_cf4acc,0,0,UfHE(),0);
										}
										while (0);
										uf_cf45d8.unlock_77fbc0(0x124);
										break;
									}
								}
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrNameChangerChanged_g")) == 1)
								{
									uf_d1e860.setEntryText_46f700("scrNameChangerChanged_g","2");
									break;
								}
								break;
							}
							case 43:
							{
								UfHE g51 = ENTX;
								if (!g51.get_9b6570())
									goto nextEff;
								UfHI pend;
								UfVHI *inv = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getInventoryList_45ab00();
								for (unsigned m = 0; m < inv->size_9b9260(); m++)
								{
									if (uf_strEq_9ccb50(inv->at_9b81f0(m).get_9b65b0()->name_457860(),"V3-11A's Pendant"))
									{
										pend = inv->at_9b81f0(m);
										break;
									}
								}
								if (pend.isValid_9b7230())
								{
									pend.get_9b65b0()->unknown57a190(g51,4,1,0);
									uf_d1e860.setEntryText_46f700("scrTriangleResearchDelivered_g","1");
									do
									{
										uf_logPhrase_5141b0(0xfe,&pend.get_9b65b0()->getName_571db0(0,0),0,0,UfHE(),0);
									}
									while (0);
								}
								break;
							}
							case 44:
							{
								UfRect h49;
								uf_cfd44c.getRect_9b4430(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0xf,h49);
								UfPoint dst(-1);
								UfPoint p9;
								for (int i = 0; i < 300; i++)
								{
									h49.randomPoint_40be30(&p9);
									if (uf_cefc4c->isVisible_4631c0(p9) && CELLAT(p9)->getEntity_45d250().isNull_9b65d0() && CELLAT(p9)->hasBlockingObject_45d7b0())
									{
										dst = p9;
										break;
									}
								}
								if (dst.x == -1)
									uf_cefc4c->unknown6c65a0(uf_cefc4c->getPlayer_4630f0(),"Yendor_Amulet_Trigger2",1);
								else
								{
									UfHI am = uf_cefc4c->placeItem_6c5480("Amulet of Y3-NDR",dst);
									if (am.isValid_9b7230())
									{
										string msg5 = am.get_9b65b0()->getName_571db0(0,0) + " suddenly appears amidst a halo of triangles.";
										uf_message_49c610(0x320,UfHE(),&msg5,0);
										do
										{
											uf_logPhrase_5141b0(0x103,&am.get_9b65b0()->getName_571db0(0,0),0,0,UfHE(),0);
										}
										while (0);
										uf_cf45d8.unlock_77fbc0(0x127);
										int *fx;
										if (uf_lookup2_9d7980("Amulet_Of_Yendor",&fx))
											uf_playEffect_55ca10(*fx,am.get_9b65b0()->pos_575920(),0);
										uf_cec054->unknown49adc0(1000);
									}
								}
								break;
							}
							case 45:
							{
								int *fx;
								if (uf_lookup2_9d7980("SCR_Sub_Part_Scan",&fx))
									uf_playEffect_55ca10(*fx,w3->pos_45d1a0(),0);
								UfHE h59 = w3->getEntity_45d250();
								int count8 = 0;
								UfVHI *oldInv = h59.get_9b6570()->getInventoryList_45ab00();
								for (unsigned m = 0; m < oldInv->size_9b9260(); m++)
								{
									if (oldInv->at_9b81f0(m).get_9b65b0()->def_9b4350() == uf_cefbe8 || oldInv->at_9b81f0(m).get_9b65b0()->def_9b4350()->x40 == 0x1d)
										count8++;
								}
								if (count8 == 0)
								{
									do
									{
										if (uf_show_5111e0b(0x320,&string("QUICKSCAN^tm: Scanning found no target technology."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
								}
								else
								{
									int five = 5;
									int n_ = uf_minInt_9cdb30(count8 / 2 + 1,5);
									string msg = "QUICKSCAN^tm: Scanned " + uf_intToString_4051f0(count8) + " Subdweller components. Printing " + uf_countString_407a80(n_,"log") + ".";
									do
									{
										if (uf_show_5111e0b(0x320,&msg,0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									if (n_ == 5)
										uf_cf45d8.unlock_77fbc0(0x123);
									UfItemDef *hiD;
									if (uf_findByName_9d7a40(uf_d2d1c4,"Derelict Log",&hiD))
									{
										UfVecU used;
										for (int k = 0; k < n_; k++)
										{
											UfHI it = uf_cefc4c->unknown6c5400(hiD,UfPoint(0x2e,0x14));
											if (it.isValid_9b7230())
											{
												int pick;
												do
													pick = uf_d358c0.pick_9ba470();
												while (uf_contains_9db330(used,pick));
												used.push_back_9b9d30(pick);
												it.get_9b65b0()->addEffect_4585a0(new UfFx(uf_d2f0f8.at_9b81f0(0x4e),pick));
											}
										}
									}
									UfHE dy = (*uf_cfd44c.at_9ceda0(0x2e,0x12))->getEntity_45d250();
									if (dy.isValid_9b7230() && dy.get_9b6570()->getFaction_45a2c0() == 0x2b)
									{
										dy.get_9b6570()->unknown6396f0("AUTO_SCR_SUB_PART_SCAN",1);
										uf_cefc4c->removeEntity_465750(dy);
										uf_cefc4c->unknown6c65a0(dy,h59.get_9b6570()->isPlayer_5c7600() ? "SCR_Sub_Part_Scan_TalkC" : "SCR_Sub_Part_Scan_TalkS",0);
									}
									do
									{
										uf_logPhrase_5141b0(0x105,0,0,0,UfHE(),0);
									}
									while (0);
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								}
								break;
							}
							case 46:
								if (uf_d25450.b0 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrAttackedLocals_g")) && !uf_d1eb10)
								{
									UfHE his = ENTX;
									if (!his.get_9b6570())
										goto nextEff;
									UfPoint e4(his.get_9b6570()->getPosition_45a4a0());
									his.get_9b6570()->unknown637bb0();
									UfHE c7 = uf_cefc4c->unknown6c5dc0("Chaos Wyrm",e4,2,0,0x22,0xe,0);
									c7.get_9b6570()->unknown639530(0x3a,1);
									c7.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
									uf_d25450.showXomAct_6bdb50(0,c7,0);
									uf_d25618 = uf_cefc4c->zones_462e10()->at_9b81f0(0)->loc.get_9b7910()->depth - 3;
									string msg("X0-1V1 animates Wyrm Statue.");
									do
									{
										if (uf_show_5111e0(0x2b9,&msg,0,0,UfHE(),UfHE(),c7.get_9b6570()->getPosition_45a4a0(),0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									do
									{
										uf_logPhrase_5141b0(0xc1,0,0,0,UfHE(),0);
									}
									while (0);
									uf_cefc4c->unknown72ffe0(1);
									UfRect r;
									uf_cfd44c.getRect_9b4430(e4,8,r);
									for (int x = r.x1; x <= r.x2; x++)
									{
										for (int y = r.y1; y <= r.y2; y++)
										{
											if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->getFaction_45a2c0() == 0x28 && (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->unknown45ac40(0))
											{
												uf_cefc4c->unknown6c65a0((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250(),"SCR_SOTW_Wyrm_Xom_Talk",0);
												goto out46;
											}
										}
									}
								out46:
									;
								}
								break;
							case 47:
							{
								UfHE hub = ENTX;
								if (!hub.get_9b6570())
									goto nextEff;
								UfHI e7;
								UfPoint pp(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
								UfVPt spots;
								spots.push_back_9b3020(UfPoint(pp,0,-2));
								spots.push_back_9b3020(UfPoint(pp,0,2));
								spots.push_back_9b3020(UfPoint(pp,-2,0));
								spots.push_back_9b3020(UfPoint(pp,2,0));
								for (unsigned m = 0; m < spots.size_9b9a50(); m++)
								{
									if (CELLAT(spots.at_9e7c10(m))->getItem_45d8f0().isValid_9b7230() && CELLAT(spots.at_9e7c10(m))->getItem_45d8f0().get_9b65b0()->getEffectValue_457be0(0))
									{
										e7 = CELLAT(spots.at_9e7c10(m))->getItem_45d8f0();
										e7.get_9b65b0()->unknown4585c0(0);
									}
								}
								if (e7.isValid_9b7230())
								{
									string name(e7.get_9b65b0()->name_457860());
									string key("AUTO_SCR_CURATORS_");
									for (unsigned m2 = 0; m2 < name.size(); m2++)
									{
										if (isalpha(name[m2]) || isdigit(name[m2]))
											key += toupper(name[m2]);
										else if (name[m2] == ' ')
											key += '_';
									}
									int b7 = uf_indexOfName4_9d7b80(uf_cf3a20,key);
									if (b7 == uf_caf168)
										goto skip47;
									uf_cf45d8.unknown77ffb0(e7.get_9b65b0()->getNestedField_457820(),0);
									uf_showTransmission_8f58f0(entity,b7);
								skip47:
									;
								}
								break;
							}
							case 48:
							{
								UfVPt cands;
								UfVZone *zs = uf_cefc4c->zones_462e10();
								for (unsigned m = 0; m < zs->size_9b9260(); m++)
								{
									if (uf_cefc4c->unknown716940(w3->pos_45d1a0(),zs->at_9b81f0(m)->pt,0,0))
										cands.push_back_9b32e0(zs->at_9b81f0(m)->pt);
								}
								if (cands.empty_9b86e0())
									goto end48;
								{
									UfPoint sp = uf_randomPoint_9d5350(cands);
									UfEntityDef *pr;
									if (uf_findByName_9d7530(uf_d25de0,"Packrat",&pr))
									{
										UfHE rat = uf_cefc4c->placeEntity_6c58c0(pr,sp,8,0,0x15,0xe,0);
										if (rat.isValid_9b7230())
										{
											int n = rat.get_9b6570()->unknown45a810();
											n = rng.rangeInt_406d70(66,100) * n / 100;
											for (int k = 0; k < n; k++)
											{
												UfItemDef *d = uf_cefc4c->selectRandomItemOfRating_6c40e0(rng.rangeInt_406d70(1,5),0,0,0x1f,0x12,1,0);
												if (d)
												{
													UfHI it = uf_cefc4c->unknown6c51d0(d,rat,0,1);
													it.get_9b65b0()->set_450460(uf_maxInt_9cdb60(1,it.get_9b65b0()->unknown457c80() * rng.rangeInt_406d70(35,75) / 100));
												}
											}
											rat.get_9b6570()->ai_45b590()->unknown458ef0()->push_back_9b32e0(w3->pos_45d1a0());
										}
									}
								}
							end48:
								break;
							}
							case 49:
							{
								UfVHI parts;
								if (uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb8b0(&parts))
								{
									int n = 0;
									for (unsigned m = 0; m < parts.size_9b9260(); m++)
									{
										if (parts.at_9b81f0(m).get_9b65b0()->def_9b4350()->x94 == 0 && !parts.at_9b81f0(m).get_9b65b0()->getField_415ee0() && parts.at_9b81f0(m).get_9b65b0()->unknown5773d0(0,0))
										{
											bool changed = false;
											if (parts.at_9b81f0(m).get_9b65b0()->unknown457d10() && parts.at_9b81f0(m).get_9b65b0()->unknown577530())
											{
												parts.at_9b81f0(m).get_9b65b0()->unknown5797c0();
												UfPart *pt = uf_cec088->unknown894e70(parts.at_9b81f0(m));
												if (pt)
												{
													uf_cec088->toggle_8993e0(pt,0);
													pt->unknown4a9120();
													if (parts.at_9b81f0(m).get_9b65b0()->getNestedField_4578c0() > 1)
														uf_cec088->unknown896820(parts.at_9b81f0(m));
												}
												changed = true;
											}
											if (parts.at_9b81f0(m).get_9b65b0()->trap_9b6bf0() < parts.at_9b81f0(m).get_9b65b0()->unknown457c80())
											{
												uf_d2c658.add_4729d0(0x178,parts.at_9b81f0(m).get_9b65b0()->unknown457c80() - parts.at_9b81f0(m).get_9b65b0()->trap_9b6bf0(),uf_b91cbf,-1);
												parts.at_9b81f0(m).get_9b65b0()->set_450460(parts.at_9b81f0(m).get_9b65b0()->unknown457c80());
												UfPart *pt2 = uf_cec088->unknown894e70(parts.at_9b81f0(m));
												if (pt2)
													pt2->drawStatus_4a8e70(0);
												changed = true;
											}
											if (changed)
												n++;
										}
									}
									if (n)
									{
										do
										{
											uf_logPhrase_5141b0(0xff,&uf_countString_407a80(n,"part"),0,0,UfHE(),0);
										}
										while (0);
									}
								}
								break;
							}
							case 50:
							{
								UfRect r;
								uf_cfd44c.getRect_9b4430(prop.get_9b64f0()->pos_4184d0(),5,r);
								for (int x = r.x1; x <= r.x2; x++)
								{
									for (int y = r.y1; y <= r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230() && uf_strEq_9ccb50((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->name_457860(),"Schematic Archive"))
										{
											(*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->remove_57dbe0(0,0,1,1);
											uf_cefc4c->unknown6c6b90(UfPoint(x,y),"SCR_Pitchfork_CW_Ash",0,-1);
											if (uf_cefc4c->isVisible_463190(x,y) || uf_distanceCeil_40a3f0(UfPoint(x,y),uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0()) <= 0xc)
											{
												string msg("A message is being transmitted: \"Emergency incinerator activated, please stay clear of the safe.\"");
												uf_message_49c610(0x320,UfHE(),&msg,0);
											}
											goto end50;
										}
									}
								}
							end50:
								break;
							}
							case 51:
							{
								UfVStr2 names;
								names.push_back_9b06f0("Adv. Trap Scanner");
								names.push_back_9b06f0("Machine Analyzer");
								names.push_back_9b06f0("Triangulator");
								names.push_back_9b06f0("Spectral Analyzer");
								names.push_back_9b06f0("Exp. Sensor Array");
								names.push_back_9b06f0("Exp. Signal Interpreter");
								names.push_back_9b06f0("0b10 Decoder Chip [Scout]");
								names.push_back_9b06f0("0b10 Decoder Chip [Skirmisher]");
								names.push_back_9b06f0("Active Sensor Suite");
								names.push_back_9b06f0("Exp. Terrain Scanner");
								names.push_back_9b06f0("Exp. Terrain Scan Processor");
								names.push_back_9b06f0("Seismic Detector");
								names.push_back_9b06f0("Transport Network Coupler");
								names.push_back_9b06f0("0b10 Decoder Chip [Generic]");
								names.push_back_9b06f0("0b10 Decoder Chip [Looter]");
								for (unsigned m = 0; m < names.size_9b0650(); m++)
								{
									int idx = uf_indexOfName_9d74d0(uf_d2d1c4,names.at_9b06a0(m));
									if (idx == uf_caf164)
										goto next51;
									uf_cf45d8.unknown77ffb0(idx,0);
								 next51:
									;
								}
								break;
							}
							case 52:
							{
								UfHE k24 = ENTX;
								if (!k24.get_9b6570())
									goto nextEff;
								UfRect r;
								uf_cfd44c.getRect_9b4430(entity.get_9b6570()->getPosition_45a4a0(),4,r);
								for (int x = r.x1; x < r.x2; x++)
								{
									for (int y = r.y1; y < r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->unknown457f90() == 0x68)
										{
											{
												UfVPt pts;
												pts.push_back_9b3020(UfPoint(x + 2,y));
												pts.push_back_9b3020(UfPoint(x - 2,y));
												pts.push_back_9b3020(UfPoint(x,y + 2));
												pts.push_back_9b3020(UfPoint(x,y - 2));
												for (unsigned m = 0; m < pts.size_9b9a50(); m++)
												{
													if (CELLAT(pts.at_9e7c10(m))->getProp_45d550().isValid_9b7230() && CELLAT(pts.at_9e7c10(m))->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd0)
													{
														pts.at_9e7c10(m).x += (x - pts.at_9e7c10(m).x) / 2;
														pts.at_9e7c10(m).y += (y - pts.at_9e7c10(m).y) / 2;
														UfHP pr = CELLAT(pts.at_9e7c10(m))->getProp_45d550();
														pr.get_9b64f0()->unknown452270(1);
														uf_removeEntity_9d2f00(uf_d31640.at_9b8070(pr.get_9b64f0()->unknown44ab40()),pr);
														pr.get_9b64f0()->unknown45ce10(1,0,1,UfHE());
														break;
													}
												}
											}
											goto end52;
										}
									}
								}
							end52:
								break;
							}
							case 53:
							{
								UfRect r;
								uf_cfd44c.getRect_9b4430(w3->pos_45d1a0(),0xf,r);
								uf_cefc4c->unknown736510(rng.rangeInt_406d70(2,3),w3->pos_45d1a0(),r,1,0);
								uf_cfd44c.getRect_9b4430(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0xf,r);
								uf_cefc4c->unknown736510(rng.rangeInt_406d70(1,2),UfPoint(-1),r,1,1);
								break;
							}
							case 54:
							{
								bool vanish = entity.get_9b6570()->getField_490840() < entity.get_9b6570()->unknown5ca260();
								if (!vanish)
								{
									UfVHI *inv = entity.get_9b6570()->getInventoryList_45ab00();
									for (unsigned m = 0; m < inv->size_9b9260(); m++)
									{
										if (inv->at_9b81f0(m).get_9b65b0()->trap_9b6bf0() < inv->at_9b81f0(m).get_9b65b0()->unknown457c80())
											vanish = true;
									}
								}
								if (vanish)
								{
								vanish54:
									if (uf_cefc4c->unknown4631f0(entity))
									{
										string msg = entity.get_9b6570()->getName_416f40() + " vanishes into the earth.";
										uf_message_49c610(0x320,UfHE(),&msg,0);
									}
									entity.get_9b6570()->unknown637bb0();
									break;
								}
								switch (entity.get_9b6570()->unknown45acb0(0))
								{
									case 0:
										if (uf_cefc4c->unknown4631f0(entity))
										{
											string s("^10_[sfrj]: \"Wzrtwx tk rd ijfym fwj lwjfyqd jcflljwfyji!\"");
											uf_fn510360(s);
											uf_message_49c610(0x322,entity,&s,0);
											entity.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(0),1));
										}
										break;
									case 1:
									{
										UfPoint p(entity.get_9b6570()->getPosition_45a4a0());
										int k27 = p.y >= uf_cfd44c.getHeight_9b8f00() - p.y ? 1 : -1;
										for (;;)
										{
											p.y += k27;
											if (!uf_cfd44c.contains_9b43b0(p))
												goto vanish54;
											if (CELLAT(p)->def_9fcd80() == uf_cefb80)
											{
												CELLAT(p)->unknown66a050(*uf_cefb88,2,0);
												entity.get_9b6570()->changePos_5dccb0(p,1);
												break;
											}
										}
										entity.get_9b6570()->unknown45ac40(0)->value = 2;
										break;
									}
									case 2:
										UfPoint p2(entity.get_9b6570()->getPosition_45a4a0());
										int k30 = p2.y >= uf_cfd44c.getHeight_9b8f00() - p2.y ? 1 : -1;
										bool theFirst = false;
										for (;;)
										{
											p2.y += k30;
											if (!uf_cfd44c.contains_9b43b0(p2))
												goto vanish54;
											if (CELLAT(p2)->def_9fcd80() == uf_cefb80)
											{
												if (!theFirst)
													theFirst = true;
												else
												{
													CELLAT(p2)->unknown66a050(*uf_cefb88,2,0);
													string nm("^6_Pdn. Odvhu Vkryho");
													uf_fn510360(nm);
													uf_cefc4c->placeItem_6c5480(nm,p2);
													if (uf_cefc4c->unknown4631f0(entity))
													{
														string msg = "The earth collapses behind " + entity.get_9b6570()->getName_416f40() + ": \"They'll never stop me! The dig must go on!\"";
														uf_message_49c610(0x320,UfHE(),&msg,0);
													}
													entity.get_9b6570()->unknown637bb0();
													break;
												}
											}
										}
										break;
								}
								break;
							}
							case 55:
							{
								UfHE k50 = ENTX;
								if (!k50.get_9b6570())
									goto nextEff;
								UfHE t = k50.get_9b6570()->unknown5d2a90(7);
								if (t.isValid_9b7230())
								{
									int oldD = uf_d1e860.unknown46f4e0() + 1;
									UfPoint r(oldD,oldD + 2);
									if (r.y > 9)
										r.shift_40bf50(9 - r.y);
									uf_cf6428.unknown6901e0(k50,1,uf_d30348.randomInRange_40c130(),uf_d21760.randomInRange_40c130(),r,1,2);
								}
								break;
							}
							case 56:
							{
								UfHE k51 = ENTX;
								if (!k51.get_9b6570())
									goto nextEff;
								UfVPt exits;
								uf_cefc4c->unknown714000(&exits);
								if (!exits.empty_9b86e0())
								{
									UfPoint p(exits.at_9e7c10(0));
									UfHE f = uf_cefc4c->unknown6c5dc0("A-27 Freighter",p,3,0,0x12,0xe,0);
									if (f.isValid_9b7230())
									{
										f.get_9b6570()->ai_45b590()->unknown4593b0(k51.get_9b6570()->getPosition_45a4a0());
										UfHE esc;
										UfEntityDef *d = uf_cefc08;
										esc = uf_cefc4c->placeEntity_6c58c0(d,p,3,0,0x22,0xe,0);
										esc.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(f,0);
										esc.get_9b6570()->ai_45b590()->setField_4505b0(4);
										d = uf_cefc4c->unknown6c5600(1,0x13,0,1);
										if (d)
										{
											esc = uf_cefc4c->placeEntity_6c58c0(d,p,3,0,0x22,0xe,0);
											esc.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(f,0);
										}
									}
								}
								break;
							}
							case 57:
								w3->unknown66b700(-1,uf_d2c46c);
								break;
							case 58:
							{
								UfHE mt = uf_cefc4c->group_463890(0xd).get_9b7250()->unknown45e1c0("01-MTF");
								if (mt.isValid_9b7230())
								{
									UfHE k = uf_cefc4c->unknown6c5dc0("KN-7UR",w3->pos_45d1a0(),10,0,1,0xe,0);
									if (k.isValid_9b7230())
									{
										UfVHE &g = uf_cefc4c->group_463890(10).get_9b7250()->members_416f40();
										for (unsigned m = 0; m < g.size_9b9260(); m++)
										{
											if (g.at_9b81f0(m).get_9b6570()->unknown45ad20("REC_Scraplab_Outer_Guard"))
											{
												g.at_9b81f0(m).get_9b6570()->unknown6396f0("REC_Scraplab_Guard_Talk",1);
												g.at_9b81f0(m).get_9b6570()->unknown6396f0("REC_Scraplab_Guard_Sub",1);
												uf_cefc4c->removeEntity_465750(g.at_9b81f0(m));
												break;
											}
										}
									}
								}
								break;
							}
							case 59:
							{
								UfHE ce = w3->getEntity_45d250();
								UfHE mt = uf_cefc4c->group_463890(0xd).get_9b7250()->unknown45e1c0("01-MTF");
								if (ce.isValid_9b7230() && mt.isValid_9b7230())
								{
									ce.get_9b6570()->unknown5dcc70(0xe,0);
									uf_cefc4c->unknown74d560(0xe,2,2,*uf_cfe674);
									uf_cefc4c->unknown465950(0xd,0xe,0);
									ce.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(mt,0);
									uf_cefc4c->group_463890(0xd).get_9b7250()->setField_45e4a0(0);
									mt.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
									UfHE g = uf_cefc4c->group_463890(10).get_9b7250()->unknown45e2d0("REC_Scraplab_Outer_Guard");
									uf_cefc4c->unknown6c65a0(g,"REC_SCR_Guard_Yell",0);
								}
								break;
							}
							case 60:
							{
								UfHE k = uf_cefc4c->group_463890(0xe).get_9b7250()->unknown45e1c0("KN-7UR");
								UfHE mt = uf_cefc4c->group_463890(0xd).get_9b7250()->unknown45e1c0("01-MTF");
								UfHE k54 = uf_cefc4c->group_463890(0xd).get_9b7250()->unknown45e1c0("KN-7UR");
								if (k54.isNull_9b65d0())
									k54 = uf_cefc4c->group_463890(1).get_9b7250()->unknown45e1c0("KN-7UR");
								UfHE b4 = uf_cefc4c->group_463890(1).get_9b7250()->unknown45e1c0("01-MTF");
								UfVHE2 list;
								if (mt.isValid_9b7230() && (k.isNull_9b65d0() || k54.isValid_9b7230()))
								{
									if (uf_cefc4c->group_463890(0xe).get_9b7250()->count_44afb0() >= 2 && !mt.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()))
										uf_cefc4c->unknown6c65a0(mt,"REC_Mtf_Reward_1",0);
									list.push_back_9b80b0(mt);
									if (k54.isValid_9b7230())
										list.push_back_9b80b0(k54);
								}
								if (k.isValid_9b7230() && (mt.isNull_9b65d0() || b4.isValid_9b7230()))
								{
									if (uf_cefc4c->group_463890(0xd).get_9b7250()->count_44afb0() >= 2 && !k.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()))
										uf_cefc4c->unknown6c65a0(k,"REC_Ktur_Reward_1",0);
									list.push_back_9b80b0(k);
									if (b4.isValid_9b7230())
										list.push_back_9b80b0(b4);
								}
								if (!list.empty_9b86e0())
								{
									for (unsigned m = 0; m < list.size_9b9260(); m++)
									{
										list.at_9b81f0(m).get_9b6570()->unknown5dcc70(10,0);
										list.at_9b81f0(m).get_9b6570()->ai_45b590()->unknown4582d0(0x19);
										list.at_9b81f0(m).get_9b6570()->ai_45b590()->unknown459540(uf_cefc4c->unknown714120(0xb));
										list.at_9b81f0(m).get_9b6570()->ai_45b590()->set_451930(0x4b);
										list.at_9b81f0(m).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
									}
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
									if (uf_d25450.b0 && (k.isValid_9b7230() && k.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()) || mt.isValid_9b7230() && mt.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0())))
										uf_d25450.unknown69e700(0x47,0,0);
								}
								break;
							}
							case 61:
							{
								UfPoint k57(prop.get_9b64f0()->pos_4184d0());
								UfPoint lo4;
								UfRect r;
								if (k57.x < 0x46)
								{
									bool a = (*uf_cfd44c.at_9ceda0(k57.x - 2,k57.y))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(k57.x - 2,k57.y))->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd0;
									bool b = (*uf_cfd44c.at_9ceda0(k57.x + 2,k57.y))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(k57.x + 2,k57.y))->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd0;
									if (a && b)
										lo4 = k57;
									else if (a)
										lo4.set_40a060(k57,-2,0);
									else
										lo4.set_40a060(k57,2,0);
									r.set_40b300(lo4.x - 3,lo4.y - 1,lo4.x + 3,lo4.y + 2);
								}
								else
								{
									bool a2 = (*uf_cfd44c.at_9ceda0(k57.x,k57.y - 2))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(k57.x,k57.y - 2))->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd0;
									bool b2 = (*uf_cfd44c.at_9ceda0(k57.x,k57.y + 2))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(k57.x,k57.y + 2))->getProp_45d550().get_9b64f0()->def_9b8f00() == uf_cefbd0;
									if (a2 && b2)
										lo4 = k57;
									else if (a2)
										lo4.set_40a060(k57,0,-2);
									else
										lo4.set_40a060(k57,0,2);
									r.set_40b300(lo4.x - 2,lo4.y - 3,lo4.x + 1,lo4.y + 3);
								}
								int *fx;
								if (uf_lookup2_9d7980("P_REC_Scraplab_Scan",&fx))
								{
									UfPoint pl(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
									for (int y = r.y1; y <= r.y2; y++)
										uf_playEffect_55ca10(*fx,UfPoint(pl.x,y),0);
									for (int x = r.x1; x <= r.x2; x++)
										uf_playEffect_55ca10(*fx,UfPoint(x,pl.y),0);
								}
								uf_sound_4541b0(0x87,0,0);
								break;
							}
							case 62:
							{
								UfHE loA = ENTX;
								if (!loA.get_9b6570())
									goto nextEff;
								UfVHE &g = uf_cefc4c->group_463890(2).get_9b7250()->members_416f40();
								for (unsigned m = 0; m < g.size_9b9260(); m++)
								{
									if (g.at_9b81f0(m).get_9b6570()->getFaction_45a2c0() == 0x25 && uf_distanceCeil_40a3f0(g.at_9b81f0(m).get_9b6570()->getPosition_45a4a0(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0()) <= 10)
									{
										uf_cefc4c->unknown6c65a0(loA,"REC_Scraplab_Guard_Sub2",0);
										break;
									}
								}
								break;
							}
							case 63:
							{
								bool m14 = false;
								UfVHI *inv = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getInventoryList_45ab00();
								for (unsigned m = 0; m < inv->size_9b9260(); m++)
								{
									if (uf_strEq_9ccb50(inv->at_9b81f0(m).get_9b65b0()->name_457860(),"SUBCON Basin") && inv->at_9b81f0(m).get_9b65b0()->getEffectValue_457be0(0x7c))
									{
										m14 = true;
										break;
									}
								}
								if (m14)
								{
									void *xd;
									if (uf_findByName_9d7be0(uf_cfd2cc,"REC_Scraplab_Basin_Chk",&xd))
										uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),xd,w3->pos_45d1a0(),UfHE(),UfPoint(-1),UfPoint(-1))));
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								}
								break;
							}
							case 64:
							{
								bool done = false;
								for (int x = uf_d1eaf8; x <= uf_d1eb00; x++)
								{
									for (int y = uf_d1eafc; y <= uf_d1eb04; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230() && uf_strEq_9ccb50((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->name_457860(),"SUBCON Basin") && (*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->getEffectValue_457be0(0x7c))
										{
											for (int x2 = uf_d1eaf8; x2 <= uf_d1eb00; x2++)
											{
												for (int y2 = uf_d1eafc; y2 <= uf_d1eb04; y2++)
												{
													if ((*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250().get_9b6570()->unknown45ad20("REC_Scraplab_Warning"))
													{
														uf_cefc4c->unknown6c65a0((*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250(),"REC_Scraplab_Basin_Rwrd",0);
														UfHE e = ENTX;
														if (!e.get_9b6570())
															goto nextEff;
														e.get_9b6570()->unknown6396f0("REC_Scraplab_Basin_Find",1);
														goto end64;
													}
												}
											}
											goto end64;
										}
									}
								}
							end64:
								break;
							}
								case 65:
									if (uf_d1e860.hasObjectID_46fa40(2))
									{
										UfVBP cands;
										UfVecU listsX;
										for (unsigned i = 0; i < uf_d1ea0c.size_9b9260(); i++)
										{
											if (uf_d1ea0c.at_9b81f0(i)->x0 == 2)
											{
												cands.push_back_9b9d30(uf_d1ea0c.at_9b81f0(i));
												listsX.push_back_9b9280(9);
											}
										}
										int r = uf_randomIndex_9d9b20(cands);
										UfBP *g_ = cands.at_9b81f0(r);
										UfPoint theP(uf_cefc4c->unknown4184d0());
										if (uf_cefc4c->findPlaceableNear_71c150(theP,theP,1))
										{
											UfHE ne = uf_cefc4c->unknown6c5e20(g_,theP,listsX.at_9b81f0(r),0,1,0);
											do
											{
												if (uf_show_5111e0b(0x244,0,0,0,ne,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											g_->b34 = false;
											uf_deleteObject_9d7850(uf_d1e97c[listsX.at_9b81f0(r)],uf_fn9d4660(uf_d1e97c[listsX.at_9b81f0(r)],g_));
											if (uf_d1e97c[listsX.at_9b81f0(r)].empty_9b86e0())
											{
												do
												{
													uf_logPhrase_5141b0(0xf4,&uf_intToString_4051f0(uf_d1ea6c.at_9b81f0(listsX.at_9b81f0(r))),0,0,UfHE(),0);
												}
												while (0);
											}
										}
									}
									break;
								case 66:
									if (uf_d1e860.hasObjectID_46fa40(3))
									{
										UfVBP cands;
										UfVecU lists;
										for (unsigned i = 0; i < uf_d1ea0c.size_9b9260(); i++)
										{
											if (uf_d1ea0c.at_9b81f0(i)->x0 == 3)
											{
												cands.push_back_9b9d30(uf_d1ea0c.at_9b81f0(i));
												lists.push_back_9b9280(9);
											}
										}
										int m27 = uf_randomIndex_9d9b20(cands);
										UfBP *bp = cands.at_9b81f0(m27);
										UfPoint p5(uf_cefc4c->unknown4184d0());
										if (uf_cefc4c->findPlaceableNear_71c150(p5,p5,1))
										{
											UfHE ne = uf_cefc4c->unknown6c5e20(bp,p5,lists.at_9b81f0(m27),0,1,0);
											if (rng.chance_406c90(0x32) && uf_cefc4c->unknown4642d0() <= 0xb)
												uf_cefc4c->unknown6c65a0(ne,"DSF_Warlord_Follow_Talk",0);
											do
											{
												if (uf_show_5111e0b(0x244,0,0,0,ne,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											bp->b34 = false;
											uf_deleteObject_9d7850(uf_d1e97c[lists.at_9b81f0(m27)],uf_fn9d4660(uf_d1e97c[lists.at_9b81f0(m27)],bp));
											if (uf_d1e97c[lists.at_9b81f0(m27)].empty_9b86e0())
											{
												do
												{
													uf_logPhrase_5141b0(0x114,&uf_intToString_4051f0(uf_d1ea6c.at_9b81f0(lists.at_9b81f0(m27))),0,0,UfHE(),0);
												}
												while (0);
											}
										}
									}
									break;
								case 67:
									if (uf_cefc4c->group_463890(3).get_9b7250()->members_416f40().empty_9b86e0() || uf_cefc4c->unknown4642d0() >= 0x1e)
									{
										int n = uf_cefc4c->group_463890(3).get_9b7250()->members_416f40().size_9b9260();
										int pct = n == 0 ? 0x32 : 8 - n;
										if (pct > 0 && rng.chance_406c90(pct))
										{
											uf_cf6470 = false;
											uf_cf6472 = true;
											w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
										}
									}
									break;
							case 68:
							{
								if (!uf_d1ebac && (uf_cefc4c->unknown4642b0() >= 0x3c || uf_distanceCeil_40a3f0(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),uf_cefc4c->zones_462e10()->at_9b81f0(0)->pt) <= 0x14))
									uf_d1ebac = uf_cefc4c->getTurn_464270();
								if (uf_d1ebac)
								{
									int dt;
									if ((dt = uf_cefc4c->getTurn_464270() - uf_d1ebac) == 0 || dt % 10 == 0)
									{
										int wave = dt == 0 ? 1 : dt / 10 + 1;
										if (wave <= 3)
										{
											UfWL wl;
											wl.add_9ba310(0x10,0x1e);
											wl.add_9ba310(0x11,10);
											wl.add_9ba310(0x12,10);
											wl.add_9ba310(0x18,10);
											wl.add_9ba310(0x3e,10);
											wl.add_9ba310(0x3f,0x1e);
											UfEntityDef *d;
											for (int k = 0; k < 4; k++)
											{
												d = uf_cefc4c->unknown6c5600(3,wl.pick_9ba470(),0,1);
												if (d)
												{
													UfHE ne = uf_cefc4c->placeEntity_6c58c0(d,uf_cefc4c->zones_462e10()->at_9b81f0(0)->pt,5,0,0x22,0xe,0);
													if (k == 0 && wave == 1 && ne.isValid_9b7230())
														uf_cefc4c->unknown6c65a0(ne,"DSF_Wild_Derelicts_Talk",0);
												}
											}
											if (wave == 1)
											{
												do
												{
													uf_logPhrase_5141b0(0x117,0,0,0,UfHE(),0);
												}
												while (0);
											}
										}
									}
									if (dt == 0x96)
									{
										uf_cf6470 = false;
										uf_cf6472 = true;
										w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
									}
									if (uf_d25450.b0 && dt == 0)
										uf_d25450.unknown69e700(0x4d,uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5c98c0(0,0x32,0) ? 1 : 0,0);
								}
								break;
							}
							case 69:
								if (!uf_cf6474)
								{
									int t = uf_cefc4c->unknown4642d0();
									if (t <= 0x12c && (t == 10 || t > 10 && (t - 10) % 0x28 == 0))
									{
										int n = rng.rangeInt_406d70(6,10);
										if (t > 10)
											n += (t - 10) / 0x28 * 2;
										if (n)
										{
											UfEntityDef *d = uf_cefc4c->unknown6c5600(3,0x3c,0,1);
											if (d)
											{
												int fac = uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")) ? 2 : 5;
												while (n)
												{
													UfPoint p;
													if (!uf_cefc4c->findPlaceableNear_71c150(uf_d1ebb0,p,d->x9c))
														break;
													uf_cefc4c->placeEntity_6c58c0(d,p,fac,0,0x22,0xe,0);
													n--;
												}
												uf_opR1d_454260(&uf_d1ebb0,0x102);
												if (uf_cefc4c->isVisible_4631c0(uf_d1ebb0))
													uf_message_49c610(0x320,UfHE(),&string("Assembled squeeze their way out of the twisted tunnel."),0);
												if (t == 10)
												{
													do
													{
														uf_logPhrase_5141b0(0x118,0,0,0,UfHE(),0);
													}
													while (0);
												}
											}
										}
									}
									if (!uf_cf6474)
									{
										switch (t)
										{
											case 2:
												if (uf_d25450.b0)
													uf_d25450.unknown69e700(0x4c,uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5c98c0(0,0x32,0) ? 1 : 0,0);
												break;
											case 0x3c:
											case 0x96:
												uf_cf6428.spawnAntiInfestationCarrier_688e80(uf_d1ebb0,string("ALERT: Infestation has breached DSF, dispatching Demolisher response squad."));
												break;
										}
									}
									else if (t == 0x12c)
										uf_cf6472 = true;
								}
								break;
							case 70:
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("datHostileToDataMiner_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("datDataConduitDisabled_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("datDataConduitDownloaded_g")) && !uf_cefc4c->isVisible_4631c0(uf_cefc4c->unknown4184d0()) && uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5c98c0(1,0x21,1))
								{
									UfPoint p = uf_cefc4c->unknown71d000(0);
									if (p.x != -1)
									{
										UfHE g = uf_cefc4c->unknown6c5dc0("Enhanced Grunt",p,2,0,0x22,0xe,0);
										g.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
										uf_cefc4c->unknown6c65a0(g,"DAT_Miner_Escort_Talk",0);
									}
									uf_d1e860.setEntryText_46f700("datDataMinerEscorted_g","1");
								}
								break;
							case 71:
								uf_d2c658.add_472b90(0x2d,-999999);
								do
								{
									uf_logPhrase_5141b0(0x160,0,0,0,UfHE(),0);
								}
								while (0);
								uf_cec138->unknown966dc0();
								break;
							case 72:
							{
								bool ok = false;
								UfVPt adj;
								uf_getAdjacentCells_4fab80(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),&adj);
								for (unsigned m = 0; m < adj.size_9b9a50(); m++)
								{
									if (CELLAT(adj.at_9e7c10(m))->getProp_45d550().isValid_9b7230() && uf_strEq_9ccb50(CELLAT(adj.at_9e7c10(m))->getProp_45d550().get_9b64f0()->location_45c590(),"GAR_RIF_Installer"))
									{
										if (CELLAT(adj.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown457b10() != 1)
											ok = true;
										break;
									}
								}
								if (ok)
								{
									do
									{
										if (uf_show_5111e0b(0x320,&string("Initiating installation procedure..."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									if (uf_cf4740)
									{
										string msg = "RIF incompatible with " + uf_d20c94 + ".";
										do
										{
											if (uf_show_5111e0b(0x325,&msg,0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
									}
									else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")) || uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("zioWasImprinted_g")))
									{
										do
										{
											if (uf_cf1080.push_5121f0(new UfPhrase2(0x29d,0,0,0,UfHE(),UfHE())))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										do
										{
											uf_logPhrase_5141b0(0x195,0,0,0,UfHE(),0);
										}
										while (0);
									}
									else
										uf_cec138->unknown966ed0();
								}
								break;
							}
							case 73:
								if (CELLAT(UfPoint(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),-1,0))->getProp_45d550().isValid_9b7230() && !CELLAT(UfPoint(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),-1,0))->getProp_45d550().get_9b64f0()->unknown457b10() && CELLAT(UfPoint(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),-9,0))->getProp_45d550().isValid_9b7230() && !CELLAT(UfPoint(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),-9,0))->getProp_45d550().get_9b64f0()->unknown457b10())
								{
									if (uf_d1eacc || uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrUfdRegistered_g")))
										uf_cefc4c->zionAttacked_731b10(1);
									else
									{
										uf_d2c658.add_472b90(0x2f,-999999);
										do
										{
											uf_logPhrase_5141b0(0x168,0,0,0,UfHE(),0);
										}
										while (0);
										uf_cec138->unknown967c90();
										uf_d1e860.setEntryText_46f700("zioWasImprinted_g","1");
										uf_d1e860.setEntryText_46f700("garCommArraySupport_g","0");
										uf_cefaa8->unknown793690();
										if (uf_cf462c == 8)
										{
											UfHE fl = uf_cefc4c->unknown715230(8,0x4c);
											if (fl.isValid_9b7230())
												uf_cefc4c->unknown6c65a0(fl,"FL_Dialogue_ZIO",0);
										}
										UfVHI parts;
										uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb8b0(&parts);
										for (unsigned m = 0; m < parts.size_9b9260(); m++)
										{
											if (parts.at_9b81f0(m).get_9b65b0()->unknown457f90() == 0xd2)
											{
												do
												{
													if (uf_show_5111e0b(0x29e,&parts.at_9b81f0(m).get_9b65b0()->getName_571db0(0,0),0,0,uf_cefc4c->getPlayer_4630f0(),UfHE(),0,0))
														uf_cec058->bubble_8758d0(true);
													uf_cec0b4->scrollToEnd_7b4f10();
												}
												while (false);
												parts.at_9b81f0(m).get_9b65b0()->remove_57dbe0(1,0,1,1);
											}
										}
									}
								}
								break;
							case 74:
							case 75:
							{
								if (bX == 0x4a)
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								UfHE z = uf_cefc4c->unknown6c5dc0("Zionite",w3->pos_45d1a0(),5,0,0x22,0xe,0);
								if (z.isValid_9b7230() && uf_cefc4c->isVisible_4631c0(w3->pos_45d1a0()))
								{
									string msg9 = z.get_9b6570()->getName_416f40() + " bursts out of the Twisted Machinery.";
									uf_message_49c610(0x320,UfHE(),&msg9,0);
									int *fx;
									if (uf_lookup2_9d7980("P_Hostile_Zionite",&fx))
										uf_playEffect_55ca10(*fx,w3->pos_45d1a0(),0);
								}
								uf_opR1d_454260(&w3->pos_45d1a0(),0xb2);
								break;
							}
							case 76:
								if (entity.get_9b6570())
								{
									UfItemDef *cl;
									if (uf_findByName_9d7a40(uf_d2d1c4,"RU-N14's Throwing Claymores",&cl))
									{
										entity.get_9b6570()->unknown5de480(cl);
										if (uf_cefc4c->unknown4631f0(entity))
										{
											uf_message_49c610(0x322,entity,&string("[name]: \"Time for a live test!\""),&entity.get_9b6570()->getPosition_45a4a0());
											string msg = entity.get_9b6570()->getName_416f40() + " pulls out a set of special claymores.";
											uf_message_49c610(0x320,entity,&msg,&entity.get_9b6570()->getPosition_45a4a0());
											uf_cec054->unknown49ada0(uf_caed20 + 0x7d0);
										}
									}
								}
								break;
							case 77:
								if (uf_cf462c == 8 || rng.chance_406c90(0x32))
								{
									int idx = uf_d1dd58.at_9b81f0(uf_d1e888.get_9b7910()->unknown46ed20());
									if (idx == uf_caf160 && uf_cf462c == 8)
									{
										for (unsigned m = 0; m < uf_d1dd58.size_9b9260(); m++)
										{
											if (uf_d1dd58.at_9b81f0(m) != uf_caf160)
											{
												idx = uf_d1dd58.at_9b81f0(m);
												uf_d1dd58.at_9b81f0(m) = uf_caf160;
												break;
											}
										}
									}
									if (idx)
									{
										UfHE h = uf_cefc4c->placeEntity_6c58c0(uf_d25de0.at_9b81f0(idx),w3->pos_45d1a0(),5,0,0x22,0xe,0);
										if (h.isValid_9b7230())
										{
											h.get_9b6570()->ai_45b590()->unknown459470(UfRect(UfPoint(0x6e,0x41),0x14));
											h.get_9b6570()->unknown639730(0);
											h.get_9b6570()->unknown6396a0("ZIO_Hero_Defender_Widen",0);
											h.get_9b6570()->unknown6396a0("ZIO_Hero_Defender_Talk",0);
											if (uf_cf462c == 8)
												h.get_9b6570()->unknown6396a0("FL_Dialogue_ZIO_Death",0);
											uf_message_49c610(0x320,UfHE(),&string("A strange signal echoes through Zion."),0);
											uf_sound_4541b0(0x12c,0,0);
										}
									}
								}
								break;
							case 78:
							{
								UfHE e = w3->getEntity_45d250();
								e.get_9b6570()->ai_45b590()->unknown459410(uf_cfd44c.getArea_9b4400());
								break;
							}
							case 79:
							{
								bool newBig = uf_d1e888.get_9b7910()->type == 0x14;
								UfRectP r;
								if (newBig)
									r.set_40b300(0x6b,0x3f,0x74,0x42);
								else
									r.set_40b300(0x55,0x22,0x5e,0x25);
								if (uf_cefc4c->isVisible_4631c0(r.a) || uf_cefc4c->isVisible_463190(r.a.x,r.b.y) || uf_cefc4c->isVisible_4631c0(r.b) || uf_cefc4c->isVisible_463190(r.b.x,r.a.y))
								{
									int *fx;
									if (uf_lookup2_9d7980("P_Quarantine_Scan_E",&fx))
									{
										if (newBig)
										{
											uf_playEffect_55ca10(*fx,UfPoint(0x6b,0x3f),&UfPoint(0x74,0x3f));
											uf_playEffect_55ca10(*fx,UfPoint(0x6b,0x40),&UfPoint(0x74,0x40));
											uf_playEffect_55ca10(*fx,UfPoint(0x6b,0x41),&UfPoint(0x74,0x41));
											uf_playEffect_55ca10(*fx,UfPoint(0x6b,0x42),&UfPoint(0x74,0x42));
										}
										else
										{
											uf_playEffect_55ca10(*fx,UfPoint(0x55,0x22),&UfPoint(0x5e,0x22));
											uf_playEffect_55ca10(*fx,UfPoint(0x55,0x23),&UfPoint(0x5e,0x23));
											uf_playEffect_55ca10(*fx,UfPoint(0x55,0x24),&UfPoint(0x5e,0x24));
											uf_playEffect_55ca10(*fx,UfPoint(0x55,0x25),&UfPoint(0x5e,0x25));
										}
										if (uf_lookup2_9d7980("P_Quarantine_Scan_Sound",&fx))
										{
											if (newBig)
												uf_playEffect_55ca10(*fx,UfPoint(0x70,0x40),0);
											else
												uf_playEffect_55ca10(*fx,UfPoint(0x5a,0x23),0);
										}
									}
								}
								UfVHE2 eB;
								int count9 = 0;
								for (int x = r.a.x; x <= r.b.x; x++)
								{
									for (int y = r.a.y; y <= r.b.y; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230() && !uf_containsEntity_9d31e0(eB,(*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250()))
										{
											eB.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250());
											(*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->removeByName_45b440("ZIOWAR_Quarantine_Mark");
											if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->unknown45a9d0())
											{
												(*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->set_44e2c0(0);
												if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->isPlayer_5c7600())
												{
													do
													{
														uf_logPhrase_5141b0(0x165,0,0,0,UfHE(),0);
													}
													while (0);
												}
												else if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().eq_9b78e0(uf_cefc4c->getEntity671_463110()) && uf_cefb48)
													uf_cefb48->say_49e250((uf_d1e888.get_9b7910()->type != 0x14) + 0x6a,0,uf_b91ccd);
												count9++;
											}
											if (newBig && (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->isPlayer_5c7600() && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("installedRif_g")))
											{
												uf_cf45d8.unlock_77fbc0(0x180);
												uf_d257e9 = true;
											}
										}
									}
								}
								string msg(uf_d1e888.get_9b7910()->type == 0x14 ? "PUBLIC SERVICE ANNOUNCEMENT: " : "ANNOUNCEMENT: ");
								msg += "Quarantine Array scanned " + uf_countString_407a80(eB.size_9b9260(),"system") + ", cleaned " + uf_intToString_4051f0(count9) + ".";
								do
								{
									uf_cf1080.set_451400(false);
									if (false)
										uf_sound_4541b0(-1,0,0);
									do
									{
										if (uf_show_5111e0b(0x324,&msg,0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (false);
								break;
							}
							case 80:
							{
								UfVHI parts;
								if (uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb8b0(&parts))
								{
									int n = 0;
									for (unsigned m = 0; m < parts.size_9b9260(); m++)
									{
										bool changed = false;
										if (parts.at_9b81f0(m).get_9b65b0()->unknown457d10())
										{
											parts.at_9b81f0(m).get_9b65b0()->unknown5797c0();
											UfPart *pt = uf_cec088->unknown894e70(parts.at_9b81f0(m));
											if (pt)
											{
												uf_cec088->toggle_8993e0(pt,0);
												pt->unknown4a9120();
												if (parts.at_9b81f0(m).get_9b65b0()->getNestedField_4578c0() > 1)
													uf_cec088->unknown896820(parts.at_9b81f0(m));
											}
											changed = true;
										}
										if (parts.at_9b81f0(m).get_9b65b0()->trap_9b6bf0() < parts.at_9b81f0(m).get_9b65b0()->unknown457c80())
										{
											uf_d2c658.add_4729d0(0x178,parts.at_9b81f0(m).get_9b65b0()->unknown457c80() - parts.at_9b81f0(m).get_9b65b0()->trap_9b6bf0(),uf_b91cce,-1);
											parts.at_9b81f0(m).get_9b65b0()->set_450460(parts.at_9b81f0(m).get_9b65b0()->unknown457c80());
											UfPart *pt2 = uf_cec088->unknown894e70(parts.at_9b81f0(m));
											if (pt2)
												pt2->drawStatus_4a8e70(0);
											changed = true;
										}
										if (parts.at_9b81f0(m).get_9b65b0()->getField_415ee0())
										{
											parts.at_9b81f0(m).get_9b65b0()->unknown458390(0);
											UfPart *pt3 = uf_cec088->unknown894e70(parts.at_9b81f0(m));
											if (pt3)
											{
												uf_cec088->toggle_8993e0(pt3,0);
												pt3->unknown4a9120();
												if (parts.at_9b81f0(m).get_9b65b0()->getNestedField_4578c0() > 1)
													uf_cec088->unknown896820(parts.at_9b81f0(m));
											}
											changed = true;
										}
										if (parts.at_9b81f0(m).get_9b65b0()->getEffect_457b70(0x6e))
										{
											parts.at_9b81f0(m).get_9b65b0()->unknown4585c0(0x6e);
											UfVPartP plist;
											if (uf_cec088->findParts_4a9a40(parts.at_9b81f0(m),&plist))
											{
												for (unsigned k = 0; k < plist.size_9b9260(); k++)
												{
													plist.at_9b81f0(k)->putChar_4180b0(0,0,0x20);
													plist.at_9b81f0(k)->unknown890710(0);
												}
											}
											changed = true;
										}
										if (parts.at_9b81f0(m).get_9b65b0()->getNestedField_4578a0() == 3)
											parts.at_9b81f0(m).get_9b65b0()->set_44fc60(0);
										if (changed)
											n++;
									}
									if (n)
									{
										do
										{
											uf_logPhrase_5141b0(0x17d,&uf_countString_407a80(n,"part"),0,0,UfHE(),0);
										}
										while (0);
									}
								}
								if (uf_cefb48)
									uf_cefb48->say_49e250(0x6f,0,uf_b91ccf);
								break;
							}
							case 81:
							{
								UfHE h = w3->getEntity_45d250();
								bool m31 = uf_cefc4c->unknown463710();
								string msg(m31 ? "[name]: \"Let me deal with this, you get out of here!\"" : "[name]: \"I heard there was danger around here, I'd suggest staying clear until it cools off.\"");
								if (m31)
									uf_cefc4c->unknown7149a0(h);
								uf_message_49c610(0x322,h,&msg,&h.get_9b6570()->getPosition_45a4a0());
								h.get_9b6570()->unknown6396a0("ZIO_Cave_Rescue_Hero_2",0);
								h.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
								break;
							}
							case 82:
							{
								UfHE h = w3->getEntity_45d250();
								UfHE node;
								if (!uf_findNode_470180(3,-1,uf_d1e888.id,&node) && !uf_findNode_470180(4,-1,uf_d1e888.id,&node))
									break;
								uf_d1e860.addExit_7892d0(node,w3->pos_45d1a0(),h.get_9b6570()->getName_416f40());
								h.get_9b6570()->ai_45b590()->unknown459540(w3->pos_45d1a0());
								uf_message_49c610(0x322,h,&string("[name]: \"There's a hidden path right here.\""),&h.get_9b6570()->getPosition_45a4a0());
								h.get_9b6570()->unknown6396a0("ZIO_Cave_Rescue_Hero_3",0);
								break;
							}
							case 83:
							{
								UfHE h = w3->getEntity_45d250();
								h.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
								break;
							}
							case 84:
							{
								UfVHE &g = uf_cefc4c->group_463890(2).get_9b7250()->members_416f40();
								for (unsigned m = 0; m < g.size_9b9260(); m++)
								{
									if (g.at_9b81f0(m).get_9b6570()->getAiType_45a2a0() == 3)
									{
										uf_cefc4c->unknown6c65a0(g.at_9b81f0(m),"DEE_Derelict_Fear_Talk",0);
										break;
									}
								}
								break;
							}
							case 85:
							{
								UfPoint &c = uf_cefc4c->unknown4184d0();
								UfHE z = uf_cefc4c->unknown6c5dc0("Z-Imprinter",c,5,0,0x22,0xe,0);
								if (z.isValid_9b7230())
								{
									z.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
									for (int k = 0; k < 2; k++)
									{
										UfHE l = uf_cefc4c->unknown6c5dc0("Z_Light_5",c,5,0,0x22,0xe,0);
										if (l.isValid_9b7230())
											l.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(z,0);
									}
								}
								if (uf_d25450.b0)
									uf_d25450.pokeWall_6bdf10();
								break;
							}
							case 86:
							{
								UfVHE &g = uf_cefc4c->group_463890(5).get_9b7250()->members_416f40();
								for (unsigned m = 0; m < g.size_9b9260(); m++)
								{
									if (g.at_9b81f0(m).get_9b6570()->getFaction_45a2c0() == 0x3d)
										g.at_9b81f0(m).get_9b6570()->ai_45b590()->unknown459470(UfRect(9,0,0x14,0x31));
								}
								break;
							}
							case 87:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isValid_9b7230() && uf_cefc4c->unknown463400(w))
								{
									UfVHE &g = uf_cefc4c->group_463890(2).get_9b7250()->members_416f40();
									for (unsigned m = 0; m < g.size_9b9260(); m++)
									{
										if (uf_strEq_9ccb50(g.at_9b81f0(m).get_9b6570()->getName_45a280(),"Warbot"))
										{
											UfHE wb = g.at_9b81f0(m);
											if (uf_cefc4c->unknown465200(w.get_9b6570()->getPosition_45a4a0(),wb.get_9b6570()->getPosition_45a4a0()))
											{
												uf_message_49c610(0x322,w,&string("[name]: \"I like your friend there. Seems ready for the good fight.\""),&w.get_9b6570()->getPosition_45a4a0());
												w.get_9b6570()->removeEffects_45b4c0(defVal,true);
											}
											break;
										}
									}
								}
								break;
							}
							case 88:
								uf_cefc4c->unknown73a490();
								break;
							case 89:
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warMaincAttacked_g")))
									uf_cefc4c->unknown73c750();
								break;
							case 90:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isValid_9b7230())
								{
									UfRect rA;
									uf_cfd44c.getRect_9b4430(w.get_9b6570()->getPosition_45a4a0(),10,rA);
									UfVPt c2;
									UfVPt demoPts;
									for (int x = rA.x1; x <= rA.x2; x++)
									{
										for (int y = rA.y1; y <= rA.y2; y++)
										{
											if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230())
											{
												if ((*uf_cfd44c.at_9ceda0(x,y))->getPropNT_45d550().get_9b64f0()->unknown45c8e0("WAR_Enhanced_Grunt_Spawn"))
													c2.push_back_9b3020(UfPoint(x,y));
												else if ((*uf_cfd44c.at_9ceda0(x,y))->getPropNT_45d550().get_9b64f0()->unknown45c8e0("WAR_Enhanced_Demolisher_Spawn"))
													demoPts.push_back_9b3020(UfPoint(x,y));
											}
										}
									}
									int *bx;
									uf_lookup2_9d7980("Teleport_hTR",&bx);
									UfVHE2 grunts;
									UfVHE2 demos;
									for (unsigned m = 0; m < c2.size_9b9a50(); m++)
									{
										UfHE g = uf_cefc4c->unknown6c5dc0("Enhanced Grunt",c2.at_9e7c10(m),9,0,0x19,0xe,0);
										if (g.isValid_9b7230())
										{
											grunts.push_back_9b80b0(g);
											g.get_9b6570()->ai_45b590()->unknown459540(uf_cefc4c->zones_462e10()->at_9b81f0(0)->pt);
											if (uf_cefc4c->isVisible_4631c0(g.get_9b6570()->getPosition_45a4a0()))
											{
												string msg = g.get_9b6570()->getName_416f40() + " warps into view.";
												uf_message_49c610(0x320,UfHE(),&msg,&g.get_9b6570()->getPosition_45a4a0());
												do
												{
													uf_logPhrase_5141b0(0x1c3,&g.get_9b6570()->getName_416f40(),0,0,g,0);
												}
												while (0);
												if (bx)
													uf_cefc50->new_508610(uf_cefc50)->init_503b20((int)bx,g.get_9b6570()->getPosition_45a4a0(),&uf_d2e20c,0,0,0,9,0);
											}
										}
									}
									for (unsigned m2 = 0; m2 < demoPts.size_9b9a50(); m2++)
									{
										UfHE d = uf_cefc4c->unknown6c5dc0("Enhanced Demolisher",demoPts.at_9e7c10(m2),9,0,0x19,0xe,0);
										if (d.isValid_9b7230())
										{
											demos.push_back_9b80b0(d);
											d.get_9b6570()->ai_45b590()->unknown459540(uf_cefc4c->zones_462e10()->at_9b81f0(0)->pt);
											if (uf_cefc4c->isVisible_4631c0(d.get_9b6570()->getPosition_45a4a0()))
											{
												string msg2 = d.get_9b6570()->getName_416f40() + " warps into view.";
												uf_message_49c610(0x320,UfHE(),&msg2,&d.get_9b6570()->getPosition_45a4a0());
												do
												{
													uf_logPhrase_5141b0(0x1c3,&d.get_9b6570()->getName_416f40(),0,0,d,0);
												}
												while (0);
												if (bx)
													uf_cefc50->new_508610(uf_cefc50)->init_503b20((int)bx,d.get_9b6570()->getPosition_45a4a0(),&uf_d2e20c,0,0,0,9,0);
											}
										}
									}
									if (demos.size_9b9260() >= 1)
										demos.at_9b81f0(0).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(w,0);
									for (int k = 0; k < 2 && k < grunts.size_9b9260(); k++)
									{
										grunts.at_9b81f0(k).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(w,0);
										grunts.at_9b81f0(k).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(w,0);
									}
									if (demos.size_9b9260() >= 3)
									{
										demos.at_9b81f0(1).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(demos.at_9b81f0(2),0);
										if (grunts.size_9b9260() >= 3)
											grunts.at_9b81f0(2).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(demos.at_9b81f0(2),0);
									}
									bool reach = false;
									for (unsigned k2 = 0; k2 < grunts.size_9b9260(); k2++)
									{
										if (uf_cefc4c->isReachable_465230(w.get_9b6570()->unknown5c7d30(),w.get_9b6570()->getPosition_45a4a0(),grunts.at_9b81f0(k2).get_9b6570()->getPosition_45a4a0()))
										{
											reach = true;
											break;
										}
									}
									if (!reach)
									{
										for (unsigned k3 = 0; k3 < demos.size_9b9260(); k3++)
										{
											if (uf_cefc4c->isReachable_465230(w.get_9b6570()->unknown5c7d30(),w.get_9b6570()->getPosition_45a4a0(),demos.at_9b81f0(k3).get_9b6570()->getPosition_45a4a0()))
											{
												reach = true;
												break;
											}
										}
									}
									if (reach)
										w.get_9b6570()->unknown6396a0("WAR_Enh_Reinforce_Talk",0);
								}
								break;
							}
							case 91:
								if (uf_cf6514 == 1)
								{
									uf_cf6514 = 2;
									if (!uf_cefc4c->unknown464450())
										uf_cefc4c->unknown465890(uf_cf6510);
								}
								break;
							case 92:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (!e.get_9b6570()->ai_45b590()->unknown458f30())
								{
									UfVecU ids;
									UfRect r;
									uf_cfd44c.getRect_9b4430(e.get_9b6570()->getPosition_45a4a0(),0xf,r);
									for (int x = r.x1; x <= r.x2; x++)
									{
										for (int y = r.y1; y <= r.y2; y++)
										{
											if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->unknown44ab40() != -1 && !(*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->unknown457b10())
												uf_fn9db000(ids,(*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->unknown44ab40());
										}
									}
									if (!ids.empty_9b86e0())
									{
										UfVMark &marks = uf_d31640.at_9b8070(uf_randomRec_9d5d00(ids));
										int best = 0;
										int bestD = uf_distanceCeil_40a3f0(e.get_9b6570()->getPosition_45a4a0(),marks.at_9b81f0(0).get_9b64f0()->pos_4184d0());
										int d;
										for (unsigned k = 1; k < marks.size_9b9260(); k++)
										{
											d = uf_distanceCeil_40a3f0(e.get_9b6570()->getPosition_45a4a0(),marks.at_9b81f0(k).get_9b64f0()->pos_4184d0());
											if (d < bestD)
											{
												bestD = d;
												best = k;
											}
										}
										UfPoint g0(marks.at_9b81f0(best).get_9b64f0()->pos_4184d0());
										int m34 = uf_maxInt_9cdb60(e.get_9b6570()->ai_45b590()->unknown4592e0(),marks.at_9b81f0(best).get_9b64f0()->def_9b8f00()->x8c ? marks.at_9b81f0(best).get_9b64f0()->def_9b8f00()->x8c->x3c : 0);
										if (m34)
										{
											uf_cfd44c.getRect_9b4430(g0,m34,r);
											for (int x2 = r.x1; x2 <= r.x2; x2++)
											{
												for (int y2 = r.y1; y2 <= r.y2; y2++)
												{
													if ((*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250().get_9b6570()->unknown45aaa0(e))
														goto end92;
												}
											}
										}
										{
										UfVHE2 list;
										e.get_9b6570()->unknown5d6c30(&list);
										if (!list.empty_9b86e0())
										{
											UfVecU w(10,0);
											e.get_9b6570()->unknown5d7700(&list,&w);
											UfPropDef *gA = marks.at_9b81f0(best).get_9b64f0()->def_9b8f00();
											for (int k2 = 0; k2 < 10; k2++)
											{
												if (w.at_9b81f0(k2) && w.at_9b81f0(k2) * gA->xa8[k2] / 100 * gA->info->x20[k2] / 100 >= marks.at_9b81f0(best).get_9b64f0()->getNestedField_45c630())
												{
													UfPoint aim;
													UfVPt aX;
													UfVecU pb;
													UfVecU a4;
													if (uf_cefc4c->unknown7170a0(e,g0,aX,pb,a4,aim,0,4,1,1))
													{
														e.get_9b6570()->set_45b090(e.get_9b6570()->get_45a6e0() + 1);
														e.get_9b6570()->unknown45b0b0();
														UfVShot v;
														int pd[1];	// NOTE: unreferenced 4-byte slot at ebp-0x5754 in the exe (name picks stack bucket 0)
														int extra;
														uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfShoot(e,1,g0,aim,&extra,v,0,UfHE())));
													}
													break;
												}
											}
										}
										}
									}
								end92:
									;
								}
								break;
							}
							case 93:
							{
								UfHE w = w3->getEntity_45d250();
								UfVHE2 m38;
								if (!w.get_9b6570()->ai_45b590()->getFollowers_580a90(&m38,0xf) || m38.size_9b9260() < 2)
								{
									uf_cefc4c->unknown6c65a0(w,"RES_Warlord_Reinforce_T",0);
									UfVRoute *m51 = uf_cefc4c->unknown4645f0();
									int bestI = 0;
									UfVPt path;
									uf_cefc4c->unknown7168e0(w.get_9b6570()->getPosition_45a4a0(),(const UfPoint&)m51->front_9b7060(),w.get_9b6570(),&path);
									int bestLen = path.size_9b9a50();
									for (unsigned k = 1; k < m51->size_9b5100(); k++)
									{
										uf_cefc4c->unknown7168e0(w.get_9b6570()->getPosition_45a4a0(),(const UfPoint&)m51->front_9b7060(),w.get_9b6570(),&path);
										int len = path.size_9b9a50();
										if (len < bestLen)
										{
											bestI = k;
											bestLen = len;
										}
									}
									for (int n = m38.size_9b9260(); n < 2; n++)
									{
										UfHE ne;
										if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("resDoshDispatched_g")) && rng.chance_406c90(0x21))
										{
											ne = uf_cefc4c->unknown6c5dc0("DD-05H",m51->at_9b8070(bestI).center_40b620(),w.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350(),0,0x22,0xe,0);
											uf_d1e860.setEntryText_46f700("resDoshDispatched_g","1");
											uf_cefc4c->unknown6c65a0(w,"RES_Warlord_Sees_Dosh",0);
											if (CELLAT(m51->at_9b8070(bestI).center_40b620())->getProp_45d550().isValid_9b7230())
											{
												CELLAT(m51->at_9b8070(bestI).center_40b620())->getProp_45d550().get_9b64f0()->unknown665b90("RES_PlasticHeart_Spawn",0);
												uf_cefc4c->unknown464e60(CELLAT(m51->at_9b8070(bestI).center_40b620())->getProp_45d550());
											}
										}
										else
											ne = uf_cefc4c->unknown6c5dc0("Knight",(const UfPoint&)m51->at_9b8070(bestI),w.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350(),0,0x22,0xe,0);
										if (ne.isValid_9b7230())
											ne.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(w,0);
									}
									string gC = "ANNOUNCEMENT: Warlord escort dispatched to " + uf_cefc4c->unknown463060(w.get_9b6570()->getPosition_45a4a0()) + " route. See that they get there.";
									do
									{
										uf_cf1080.set_451400(false);
										if (false)
											uf_sound_4541b0(-1,0,0);
										do
										{
											if (uf_show_5111e0b(0x324,&gC,0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
								}
								break;
							}
							case 94:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (e.get_9b6570()->unknown45ab20("Warlord Statue") || e.get_9b6570()->ai_45b590()->unknown459070() && e.get_9b6570()->ai_45b590()->unknown459070()->type == 4)
								{
									uf_message_49c610(0x322,e,&string("[name]: \"We are GR-1FF!\""),&e.get_9b6570()->getPosition_45a4a0());
									e.get_9b6570()->removeEffects_45b4c0(defVal,true);
								}
								break;
							}
							case 95:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								if (e.get_9b6570()->ai_45b590()->getFollowEntity_458ed0().isNull_9b65d0() || !e.get_9b6570()->unknown45ab20("Warlord Statue") && (!e.get_9b6570()->ai_45b590()->unknown459070() || e.get_9b6570()->ai_45b590()->unknown459070()->type != 4))
								{
									e.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
									e.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
									e.get_9b6570()->ai_45b590()->unknown459540(*(const UfPoint*)&uf_randomArea_9d7d20(uf_cefc4c->unknown4645f0()));
									e.get_9b6570()->removeEffects_45b4c0(defVal,true);
								}
								break;
							}
							case 96:
							{
								UfHE myY = ENTX;
								if (!myY.get_9b6570())
									goto nextEff;
								UfHE gD;
								UfVHE &g = myY.get_9b6570()->getGroup_45a3f0().get_9b7250()->members_416f40();
								for (unsigned m = 0; m < g.size_9b9260(); m++)
								{
									if (g.at_9b81f0(m).get_9b6570()->getFaction_45a2c0() == 0x11 && uf_strEq_9ccb50(g.at_9b81f0(m).get_9b6570()->getName_45a280(),"DD-05H"))
									{
										gD = g.at_9b81f0(m);
										break;
									}
								}
								if (gD.isValid_9b7230() && uf_cefc4c->isReachable_465230(9999,myY.get_9b6570()->getPosition_45a4a0(),gD.get_9b6570()->getPosition_45a4a0()))
								{
									if (uf_cefc4c->unknown4631f0(myY))
										uf_message_49c610(0x322,entity,&string("[name]: \"Ah, help has arri--I'm flattered.\""),&entity.get_9b6570()->getPosition_45a4a0());
									myY.get_9b6570()->removeEffects_45b4c0(defVal,true);
								}
								break;
							}
							case 97:
							{
								UfHE h = w3->getEntity_45d250();
								if (uf_cefc4c->unknown4631f0(h))
								{
									UfHE t = uf_cefc4c->unknown715230(2,0x5e);
									if (uf_cf4a00 || t.isValid_9b7230() && uf_cefc4c->isReachable_465230(9999,h.get_9b6570()->getPosition_45a4a0(),t.get_9b6570()->getPosition_45a4a0()))
									{
										h.get_9b6570()->unknown6396a0("RES_Warlord_Dialogue3",0);
										h.get_9b6570()->unknown6396a0("RES_Warlord_Dialog3_End",0);
										h.get_9b6570()->unknown6396f0("RES_Warlord_Dialogue",1);
									}
								}
								break;
							}
							case 98:
								if (uf_d1e888.get_9b7910()->type == 0x22)
									uf_cefc4c->unknown7409f0(1);
								else
									uf_cefc4c->unknown740300(1);
								break;
							case 99:
								uf_cefc4c->unknown740300(0);
								break;
							case 100:
								if (w3)
								{
									UfHP p = w3->getProp_45d550();
									if (p.get_9b64f0()->isTrap_45cb70())
									{
										if (!p.get_9b64f0()->unknown44b020()->unknown65cf80() && rng.chance_406c90(0x32))
										{
											do
											{
												if (uf_show_5111e0(0x21a,&p.get_9b64f0()->getName_45c5b0(),0,0,UfHE(),UfHE(),p.get_9b64f0()->pos_4184d0(),0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											CELLAT(p.get_9b64f0()->pos_4184d0())->unknown66ce10(0,0,0,0);
										}
									}
									else if (p.get_9b64f0()->def_9b8f00()->x8c)
										p.get_9b64f0()->unknown45ce10(0,0,0,UfHE());
									else if (p.get_9b64f0()->def_9b8f00()->xf4 && p.get_9b64f0()->unknown457b10() != 1)
										p.get_9b64f0()->disableMachine_65ed00();
								}
								break;
							case 101:
							{
								UfPoint a(0x2d,0x23);
								UfPoint b(0x2d,0x24);
								if (CELLAT(a)->getProp_45d550().isNull_9b65d0() || CELLAT(a)->getProp_45d550().get_9b64f0()->unknown457b10())
								{
									do
									{
										if (uf_show_5111e0b(0x321,&string("Connection aborted."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									do
									{
										uf_logPhrase_5141b0(0x1a5,0,0,0,UfHE(),0);
									}
									while (0);
								}
								else
								{
									do
									{
										if (uf_show_5111e0b(0x321,&string("Project G-00 loaded."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									do
									{
										uf_logPhrase_5141b0(0x1a6,0,0,0,UfHE(),0);
									}
									while (0);
									uf_sound_4541b0(0x94,0,0);
									CELLAT(a)->getProp_45d550().get_9b64f0()->setSoundMute_65f320(0);
									uf_d2d2a0.unknown454540();
									uf_d2d2a0.unknown500010();
									uf_cefc4c->unknown6c6b90(b,"CET_Manufacture_Spawn",0,-1);
									uf_cefc4c->unknown6c6b90(b,"CET_Manufacture_Stop",0,-1);
								}
								break;
							}
							case 102:
							{
								UfPoint a(0x2d,0x23);
								UfPoint b(0x2d,0x24);
								uf_message_49c610(0x320,UfHE(),&string("Cetus Manufacturing Module falls silent."),0);
								uf_opR1d_454260(&a,0x95);
								CELLAT(a)->getProp_45d550().get_9b64f0()->setSoundMute_65f320(1);
								CELLAT(b)->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
								uf_d2c658.add_472b90(0x39,-999999);
								break;
							}
							case 103:
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("cetGuardsRemaining_g")))
								{
									int n = 0;
									UfVHE &g = uf_cefc4c->group_463890(3).get_9b7250()->members_416f40();
									for (unsigned m = 0; m < g.size_9b9260(); m++)
									{
										if (uf_strEq_9ccb50(g.at_9b81f0(m).get_9b6570()->getName_45a280(),"Cetus Guard"))
											n++;
									}
									uf_d1e860.setEntryText_46f700("cetGuardsRemaining_g",uf_intToString_4051f0(n));
								}
								if (uf_cf462c == 8 && uf_cf46e4.at_9b81f0(7) == 0)
								{
									UfHE f = uf_cefc4c->unknown715230(8,0x4a);
									if (f.isValid_9b7230())
									{
										uf_cefc4c->unknown6c65a0(f,"FL_Dialogue_CET",0);
										uf_cf46e4.at_9b81f0(7) = 1;
									}
								}
								break;
							case 104:
							case 105:
							{
								UfVPt exits9;
								uf_cefc4c->unknown714000(&exits9);
								UfPoint eA = uf_randomPoint_9d5350(exits9);
								UfPoint aB(0x18,0x18);
								UfWL cX;
								int n;
								if (bX == 0x68)
								{
									n = 10;
									cX.add_9ba310(0x10,10);
									UF_ALERT("ALERT: Rogue bot located, all non-essential units route around Archives area.")
								}
								else
								{
									n = 0x10;
									cX.add_9ba310(0x10,4);
									cX.add_9ba310(0x15,6);
									cX.add_9ba310(0x18,4);
									cX.add_9ba310(0x13,2);
									UF_ALERT("ALERT: Multiple hostiles detected in Archives area, dispatching reinforcements.")
								}
								do
								{
									uf_logPhrase_5141b0(0x1af,0,0,0,UfHE(),0);
								}
								while (0);
								UfHE h;
								UfEntityDef *d;
								for (int k = 0; k < n; k++)
								{
									d = uf_cefc4c->unknown6c5600(1,cX.pick_9ba470(),0,1);
									if (!d)
										continue;
									UfHE hd = uf_cefc4c->placeEntity_6c58c0(d,eA,3,0,3,0xe,0);
									if (hd.isValid_9b7230())
									{
										UfRect r;
										uf_cfd44c.getRect_9b4430(aB,0x19,r);
										hd.get_9b6570()->ai_45b590()->unknown459470(r);
										hd.get_9b6570()->ai_45b590()->unknown459520(aB);
									}
								}
								break;
							}
							case 106:
								uf_cf6428.unknown687520(UfHE(),&uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0);
								uf_cf6428.unknown687520(UfHE(),&uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0);
								UF_ALERT("ALERT: Weapon containment breached. Dispatching heavy reinforcements to area.")
								do
								{
									uf_logPhrase_5141b0(0x1d7,0,0,0,UfHE(),0);
								}
								while (0);
								break;
							case 107:
							{
								const int goal = 0xf;
								bool newDone = false;
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("armValgurisCogmindKillCount_g")) >= goal)
								{
									uf_cefc4c->unknown6c65a0(entity,"ARM_Valg_Talk_Win",0);
									uf_d1e860.setEntryText_46f700("armValgurisGoalState_g","1");
									newDone = true;
								}
								else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("armValgurisKillCount_g")) >= goal)
								{
									uf_cefc4c->unknown6c65a0(entity,"ARM_Valg_Talk_Lose",0);
									uf_d1e860.setEntryText_46f700("armValgurisGoalState_g","2");
									newDone = true;
								}
								if (newDone)
								{
									uf_cefc4c->unknown6c65a0(entity,"ARM_Valg_Exit_Trigger",0);
									entity.get_9b6570()->unknown6396f0("ARM_Valg_Check_Kills",1);
								}
								break;
							}
							case 108:
							{
							exit108:
								UfPoint dst(-1);
								for (unsigned m = 0; m < uf_cefc4c->zones_462e10()->size_9b9260(); m++)
								{
									if (uf_cefc4c->zones_462e10()->at_9b81f0(m)->loc.get_9b7910()->inRange_46ecb0())
									{
										dst = uf_cefc4c->zones_462e10()->at_9b81f0(m)->pt;
										break;
									}
								}
								if (dst.x == -1)
									goto skip108;
								entity.get_9b6570()->ai_45b590()->unknown4582d0(0x19);
								entity.get_9b6570()->ai_45b590()->unknown459540(dst);
							skip108:
								entity.get_9b6570()->unknown6396f0("ARM_Valg_Exit_Trigger",1);
								break;
							}
							case 109:
								if (entity.get_9b6570()->unknown5d1280(1))
								{
									uf_message_49c610(0x322,entity,&string("[name]: \"It looks like I'll be here for a while. Be on your way, friend.\""),&entity.get_9b6570()->getPosition_45a4a0());
									entity.get_9b6570()->unknown639730(1);
								}
								break;
							case 110:
								if (entity.get_9b6570()->unknown5d5250())
								{
									uf_message_49c610(0x322,entity,&string("[name]: \"I need to rearm. Keep up the good fight!\""),&entity.get_9b6570()->getPosition_45a4a0());
									entity.get_9b6570()->unknown639730(1);
									goto exit108;
								}
								break;
							case 111:
								uf_cefc4c->unknown7480e0(1);
								break;
							case 112:
							{
								UfRect area(UfPoint(2,6),UfPoint(0x1d,0x21));
								UfVHP list;
								for (int x = area.x1; x <= area.x2; x++)
								{
									for (int y = area.y1; y <= area.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230() && uf_strEq_9ccb50((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->location_45c590(),"LAB_Scan_Trigger"))
											list.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550());
									}
								}
								if (!list.empty_9b86e0())
								{
									for (unsigned m = 0; m < list.size_9b9260(); m++)
									{
										if (rng.chance_406c90(0x21))
										{
											UfVPt adjTmp;
											uf_getAdjacentCells_4fab80(list.at_9b81f0(m).get_9b64f0()->pos_4184d0(),&adjTmp);
											uf_shuffle_9d7350(adjTmp);
											for (unsigned k = 0; k < adjTmp.size_9b9a50(); k++)
											{
												if (CELLAT(adjTmp.at_9e7c10(k))->getProp_45d550().isNull_9b65d0() && CELLAT(adjTmp.at_9e7c10(k))->getField_4550b0() && area.contains_40b750(adjTmp.at_9e7c10(k)))
												{
													list.at_9b81f0(m).get_9b64f0()->unknown65f270(adjTmp.at_9e7c10(k));
													break;
												}
											}
										}
									}
									bool found = false;
									for (unsigned m2 = 0; m2 < list.size_9b9260(); m2++)
									{
										if (CELLAT(list.at_9b81f0(m2).get_9b64f0()->pos_4184d0())->getEntity_45d250().isValid_9b7230())
										{
											found = true;
											break;
										}
										found = CELLAT(list.at_9b81f0(m2).get_9b64f0()->pos_4184d0())->getEntity_45d250().isValid_9b7230();
										if (!found)
										{
											UfVPt sur;
											uf_surrounding_4faaf0(list.at_9b81f0(m2).get_9b64f0()->pos_4184d0(),&sur);
											for (unsigned k2 = 0; k2 < sur.size_9b9a50(); k2++)
											{
												if (CELLAT(sur.at_9e7c10(k2))->getEntity_45d250().isValid_9b7230())
												{
													found = true;
													goto done112;
												}
											}
										}
									}
								done112:
									if (found)
										uf_cefc4c->unknown7480e0(1);
								}
								break;
							}
							case 113:
							{
								int x = 0x81;
								int y0 = 0x1b;
								UfHP cp;
								for (int y = y0; y <= y0 + 10; y++)
								{
									if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getPropNT_45d550().get_9b64f0()->unknown45c8e0("SEC_Power_Cell_Trigger"))
									{
										cp = (*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550();
										break;
									}
								}
								if (cp.isNull_9b65d0())
									goto end113;
								if (!uf_cefc4c->unknown6c6700(cp,"SEC_Power_Cell_Trigger",0))
									;
							end113:
								break;
							}
							case 114:
							{
								UfItemDef *tb;
								if (item.isValid_9b7230() && uf_findByName_9d7a40(uf_d2d1c4,"Terrabomb",&tb))
									uf_cefc4c->unknown747060(item.get_9b65b0()->pos_575920(),tb->xf4,tb->x190);
								break;
							}
							case 115:
								uf_cf6428.unknown68c6d0(w3->getEntity_45d250());
								break;
							case 116:
							{
								int radius = 0x10;
								uf_clearDijkstra_4faf40();
								uf_cfe568.unknown40ca20(w3->pos_45d1a0(),0x22,&uf_cfe5e8,0);
								if (uf_d15e58.empty_9b86e0())
									goto end116;
								{
									UfVPt nLo(uf_d15e58);
									UfPoint next;
									for (unsigned m = 1; m < nLo.size_9b9a50(); m++)
									{
											if (CELLAT(nLo.at_9e7c10(m))->getItem_45d8f0().isValid_9b7230() && uf_nextLineStep_40ff60(UfPoint(nLo.at_9e7c10(m)),w3->pos_45d1a0(),&next))
											{
												bool ok = true;
												if (!CELLAT(next)->unknown45d990())
												{
													ok = false;
													UfVPt nb;
													if (uf_commonNeighbors_4fac50(nLo.at_9e7c10(m),next,&nb))
													{
														UfVFloat d;
														for (unsigned k = 0; k < nb.size_9b9a50(); k++)
														{
															if (CELLAT(nb.at_9e7c10(k))->unknown45d990())
																d.push_back_9b84b0(uf_distance_40a450(nb.at_9e7c10(k),w3->pos_45d1a0()));
															else
																uf_eraseStep_9d7300(nb,k);
														}
														if (!d.empty_9b86e0())
														{
															int bi = uf_minIndex_9d7d70(d);
															if (d.at_9b81f0(bi) < uf_distance_40a450(nLo.at_9e7c10(m),w3->pos_45d1a0()))
															{
																next = nb.at_9e7c10(bi);
																ok = true;
															}
														}
													}
												}
												if (ok)
													CELLAT(nLo.at_9e7c10(m))->getItem_45d8f0().get_9b65b0()->unknown57a0f0(next,0,0);
											}
											if (CELLAT(nLo.at_9e7c10(m))->unknown45d230() && uf_nextLineStep_40ff60(UfPoint(nLo.at_9e7c10(m)),w3->pos_45d1a0(),&next))
											{
												bool ok2 = true;
												if (!CELLAT(next)->unknown45da50())
												{
													ok2 = false;
													UfVPt nb2;
													if (uf_commonNeighbors_4fac50(nLo.at_9e7c10(m),next,&nb2))
													{
														UfVFloat d2;
														for (unsigned k2 = 0; k2 < nb2.size_9b9a50(); k2++)
														{
															if (CELLAT(nb2.at_9e7c10(k2))->unknown45da50())
																d2.push_back_9b84b0(uf_distance_40a450(nb2.at_9e7c10(k2),w3->pos_45d1a0()));
															else
																uf_eraseStep_9d7300(nb2,k2);
														}
														if (!d2.empty_9b86e0())
														{
															int bi2 = uf_minIndex_9d7d70(d2);
															if (d2.at_9b81f0(bi2) < uf_distance_40a450(nLo.at_9e7c10(m),w3->pos_45d1a0()))
															{
																next = nb2.at_9e7c10(bi2);
																ok2 = true;
															}
														}
													}
												}
												if (ok2)
													CELLAT(nLo.at_9e7c10(m))->unknown66b740(CELLAT(next));
											}
									}
								}
							end116:
								break;
							}
							case 117:
							{
								UfHE ok5 = ENTX;
								if (!ok5.get_9b6570())
									goto nextEff;
								UfEntityDef *d = ok5.get_9b6570()->def_9b4350();
								if (d->x48 == 0x79)
								{
									uf_d2c658.add_4729d0(0x164,1,d->name4,-1);
									uf_cf4bc0.push_back_9b06f0(d->s4c.empty() ? ok5.get_9b6570()->getName_416f40() : d->s4c);
									uf_cf4bd0.push_back_9b9280(uf_d1e860.unknown46f530());
									do
									{
										uf_logPhrase_5141b0(0x13,&(d->s4c.empty() ? ok5.get_9b6570()->getName_416f40() : d->s4c),0,0,ok5,0);
									}
									while (0);
									if (uf_cf4bc0.size_9b0650() == 0xf)
										uf_cf45d8.unlock_77fbc0(0x164);
									uf_cf6888.unknown6998a0(0xc,d->x68,0);
								}
								break;
							}
							case 118:
							{
								for (int x = 0; x < uf_cfd44c.getWidth_9fcd80(); x++)
								{
									for (int y = 0; y < uf_cfd44c.getHeight_9b8f00(); y++)
										uf_cefc4c->unknown7243c0(x,y,1);
								}
								uf_reveal_794da0(9,0,0,0x26);
								uf_reveal_794da0(6,0,0,0x26);
								uf_reveal_794da0(7,0,0,0x26);
								uf_reveal_794da0(5,0,0,0x26);
								uf_reveal_794da0(8,0,0,0x26);
								UfVZone *zs = uf_cefc4c->zones_462e10();
								for (unsigned m = 0; m < zs->size_9b9260(); m++)
								{
									if (zs->at_9b81f0(m)->h14.isNull_9b65d0() && !uf_b90480[zs->at_9b81f0(m)->loc.get_9b7910()->type])
									{
										uf_cefc4c->announceMachine_71dd30(zs->at_9b81f0(m)->loc);
										uf_cefc4c->unknown4647a0(zs->at_9b81f0(m)->pt,1);
										zs->at_9b81f0(m)->bd = true;
										zs->at_9b81f0(m)->unknown6c16d0("FOUND");
										uf_cec054->labelAccess_80e3a0(1,zs->at_9b81f0(m));
									}
								}
								break;
							}
							case 119:
							{
								int t = entity.get_9b6570()->unknown45acb0(0);
								if (t == 0)
								{
									if (entity.get_9b6570()->getField_490840() < entity.get_9b6570()->unknown5ca260())
										uf_cf6428.wake_68d480();
								}
								else if (uf_cefc4c->getTurn_464270() >= t)
								{
									uf_cf6454.resetField_9b7270();
									entity.get_9b6570()->unknown45b360(0);
									entity.get_9b6570()->removeEffects_45b4c0(defVal,true);
									entity.get_9b6570()->unknown6396a0("FRG_Superfortress_Work",0);
									entity.get_9b6570()->unknown5fdab0();
									entity.get_9b6570()->setAI_64ecf0(new UfEntityAI(entity,0x22,0xe));
									entity.get_9b6570()->ai_45b590()->unknown459540(UfPoint(uf_cefc4c->unknown464610(),0x4a,0x6f));
									if (uf_cefc4c->unknown4631f0(entity))
										uf_message_49c610(0x320,UfHE(),&string("Superfortress completes startup sequence."),0);
									uf_opR1d_454260(&entity.get_9b6570()->pos_45a4c0(),0x121);
								}
								break;
							}
							case 120:
							{
								int fx = 0;
								if (uf_cefc4c->getTurn_464270() >= entity.get_9b6570()->unknown45acb0(0x99) + 5 && rng.chance_406c90(10))
								{
									UfVHI *inv = entity.get_9b6570()->getInventoryList_45ab00();
									UfEntityDef::UfVRcp *rv = &entity.get_9b6570()->def_9b4350()->v160;
									int pick = uf_caf164;
									int id;
									int c_;
									for (unsigned m = 0; m < rv->size_9b5100(); m++)
									{
										id = rv->at_9b8070(m).front_9b7060()->x0;
										c_ = rv->at_9b8070(m).front_9b7060()->x4;
										for (unsigned k = 0; k < inv->size_9b9260(); k++)
										{
											if (inv->at_9b81f0(k).get_9b65b0()->getNestedField_457820() == id)
											{
												if (--c_ == 0)
													break;
											}
										}
										if (c_)
										{
											pick = id;
											break;
										}
									}
									if (pick != uf_caf164)
									{
										UfHI it = uf_cefc4c->unknown6c51d0(uf_d2d1c4.at_9b81f0(pick),entity,1,0);
										if (it.isValid_9b7230())
										{
											do
											{
												if (uf_show_5111e0b(0x7b,&it.get_9b65b0()->getName_571db0(0,0),0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											fx = 1;
											entity.get_9b6570()->unknown639470(0x99,uf_cefc4c->getTurn_464270());
										}
									}
								}
								if (!entity.get_9b6570()->unknown5cba50() || uf_cefc4c->getTurn_464270() > entity.get_9b6570()->unknown45acb0(0x9a) + 0x1e && rng.chance_406c90(5) && entity.get_9b6570()->ai_45b590()->unknown458f30())
								{
									UfVHI *inv2 = entity.get_9b6570()->getInventoryList_45ab00();
									for (unsigned k = 0; k < inv2->size_9b9260(); k++)
									{
										if (inv2->at_9b81f0(k).get_9b65b0()->getType_44aec0() == 3)
										{
											entity.get_9b6570()->unknown5deb40(inv2->at_9b81f0(k).get_9b65b0()->unknown577600(100));
											do
											{
												if (uf_show_5111e0b(0x7c,&inv2->at_9b81f0(k).get_9b65b0()->getName_571db0(0,0),0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											inv2->at_9b81f0(k).get_9b65b0()->remove_57dbe0(0,1,1,1);
											k--;
										}
									}
									int old = entity.get_9b6570()->getRoomCount_448fe0(3);
									UfVIDef2 utils;
									UfVIDef2 pTo;
									for (unsigned i = 0; i < uf_d2d1c4.size_9b9260(); i++)
									{
										if (uf_d2d1c4.at_9b81f0(i)->b23a)
											(uf_d2d1c4.at_9b81f0(i)->x44 == 0x18 ? utils : pTo).push_back_9b9d30(uf_d2d1c4.at_9b81f0(i));
									}
									if (!utils.empty_9b86e0() && rng.chance_406c90((entity.get_9b6570()->ai_45b590()->unknown458f30() - 1) * 5))
									{
										UfHI u = uf_cefc4c->unknown6c51d0(uf_randomRec_9d5d00(utils),entity,1,0);
										if (u.isValid_9b7230())
										{
											do
											{
												if (uf_show_5111e0b(0x7b,&u.get_9b65b0()->getName_571db0(0,0),0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											old -= u.get_9b65b0()->getNestedField_4578c0();
										}
									}
									while (old)
									{
										UfItemDef *o = uf_randomRec_9d5d00(pTo);
										if (old >= o->x4c)
										{
											UfHI u2 = uf_cefc4c->unknown6c51d0(o,entity,1,0);
											if (u2.isValid_9b7230())
											{
												do
												{
													if (uf_show_5111e0b(0x7b,&u2.get_9b65b0()->getName_571db0(0,0),0,0,entity,UfHE(),0,0))
														uf_cec058->bubble_8758d0(true);
													uf_cec0b4->scrollToEnd_7b4f10();
												}
												while (false);
												old -= u2.get_9b65b0()->getNestedField_4578c0();
											}
										}
									}
									fx = 2;
									entity.get_9b6570()->unknown639470(0x9a,uf_cefc4c->getTurn_464270());
								}
								if (fx)
									uf_opR1d_454260(&entity.get_9b6570()->pos_45a4c0(),(fx != 2) + 0x122);
								if (entity.get_9b6570()->ai_45b590()->unknown458f30())
								{
									fx = 0;
									UfVHE2 nearby;
									entity.get_9b6570()->unknown5c8880(&nearby);
									uf_shuffle_9d9fc0(nearby);
									for (unsigned m = 0; m < nearby.size_9b9260(); m++)
									{
										if (nearby.at_9b81f0(m).get_9b6570()->unknown45a880() < 100 && nearby.at_9b81f0(m).get_9b6570()->getField_490840() < 0x32 && nearby.at_9b81f0(m).get_9b6570()->unknown45aaa0(entity) && rng.chance_406c90(5))
										{
											do
											{
												if (uf_show_5111e0b(0x7c,&nearby.at_9b81f0(m).get_9b6570()->getName_416f40(),0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											nearby.at_9b81f0(m).get_9b6570()->unknown637bb0();
											fx = 1;
											break;
										}
									}
									if (uf_cefc4c->getTurn_464270() >= entity.get_9b6570()->unknown45acb0(0x9b) + 3 && uf_cefc4c->getTurn_464270() > entity.get_9b6570()->unknown45acb0(0x9a) + 5)
									{
										int ch = (entity.get_9b6570()->ai_45b590()->unknown458f30() - 1) * 5;
										if (entity.get_9b6570()->getField_490840() < entity.get_9b6570()->unknown5ca260())
											ch += 0x19;
										if (rng.chance_406c90(ch) || entity.get_9b6570()->unknown5d5250())
										{
											UfVPt spots;
											entity.get_9b6570()->unknown5c89d0(&spots);
											uf_shuffle_9d7350(spots);
											UfPoint sp(-1);
											for (unsigned m2 = 0; m2 < spots.size_9b9a50(); m2++)
											{
												if (uf_cfd44c.contains_9b43b0(spots.at_9e7c10(m2)) && CELLAT(spots.at_9e7c10(m2))->canPlaceEntity_66ad20(1))
												{
													sp = spots.at_9e7c10(m2);
													break;
												}
											}
											if (sp.x != -1)
											{
												UfVEDef2 defs;
												for (unsigned i2 = 0; i2 < uf_d25de0.size_9b9260(); i2++)
												{
													if (uf_d25de0.at_9b81f0(i2)->b138)
														defs.push_back_9b9d30(uf_d25de0.at_9b81f0(i2));
												}
												if (!defs.empty_9b86e0())
												{
													UfHE ne = uf_cefc4c->placeEntity_6c58c0(uf_randomRec_9d5d00(defs),sp,3,0,0x22,0xe,0);
													if (ne.isValid_9b7230())
													{
														UfRect r;
														uf_cfd44c.getRect_9b4430(sp,10,r);
														ne.get_9b6570()->ai_45b590()->unknown459470(r);
														do
														{
															if (uf_show_5111e0b(0x7b,&ne.get_9b6570()->getName_416f40(),0,0,entity,UfHE(),0,0))
																uf_cec058->bubble_8758d0(true);
															uf_cec0b4->scrollToEnd_7b4f10();
														}
														while (false);
														entity.get_9b6570()->unknown639470(0x9b,uf_cefc4c->getTurn_464270());
														fx = 2;
													}
												}
											}
										}
									}
									if (fx)
										uf_opR1d_454260(&entity.get_9b6570()->pos_45a4c0(),(fx != 2) + 0x124);
								}
								break;
							}
							case 121:
								if (!uf_cf645c && uf_cf6428.unknown68d980(1,1,0))
								{
									do
									{
										if (uf_show_5111e0b(0x324,&string("ALERT: Protoforge research compromised, high security lockdown imminent, T-100."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									do
									{
										uf_logPhrase_5141b0(0x6b,0,0,0,UfHE(),0);
									}
									while (0);
								}
								break;
							case 123:
							{
								UfHE q12 = ENTX;
								if (!q12.get_9b6570())
									goto nextEff;
								UfHE t = uf_cefc4c->unknown715230(3,0x21);
								if (t.isValid_9b7230())
								{
									q12.get_9b6570()->ai_45b590()->chase_5b4710(t,-2,1,1,0);
									uf_cefc4c->escort_743350(0,0,1);
									UfVHE &g = uf_cefc4c->group_463890(10).get_9b7250()->members_416f40();
									for (unsigned m = 0; m < g.size_9b9260(); m++)
									{
										if (uf_distanceCeil_40a3f0(q12.get_9b6570()->getPosition_45a4a0(),g.at_9b81f0(m).get_9b6570()->getPosition_45a4a0()) <= 0x14 && g.at_9b81f0(m).get_9b6570()->isXomCandidate_5d51a0())
											g.at_9b81f0(m).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(q12,0);
									}
								}
								break;
							}
							case 122:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								e.get_9b6570()->ai_45b590()->unknown459380(UfPoint(uf_cefc4c->unknown464610(),0x51,0x6c));
								uf_cefc4c->unknown742c80();
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("frgResearchMorePatrolsCalled_g")))
								{
									uf_cefc4c->unknown7430a0(2,0);
									uf_d1e860.setEntryText_46f700("frgResearchMorePatrolsCalled_g","1");
									do
									{
										uf_cf1080.set_451400(true);
										if (false)
											uf_sound_4541b0(-1,0,0);
										do
										{
											if (uf_show_5111e0b(0x324,&string("ALERT: Tinkerer labs infiltrated, dispatching additonal patrols."),0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
								}
								break;
							}
							case 124:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								e.get_9b6570()->ai_45b590()->unknown459410(uf_cefc4c->unknown464670());
								break;
							}
							case 125:
							{
								UfHE e = ENTX;
								if (!e.get_9b6570())
									goto nextEff;
								e.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
								break;
							}
							case 126:
								UF_ALERT("ALERT: Sigix Quarantine Chamber accessed without registered guard. Dispatching lockdown squad.")
								uf_cf6428.spawnResponseParty_68c2f0(2,UfHE(),uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0(),0);
								break;
							case 127:
								if (!uf_cf645c && !uf_cf6474 && uf_d1e860.unknown46f4b0(1) && uf_d1e888.get_9b7910()->type != 0xd && uf_d1e888.get_9b7910()->type != 0xe && uf_d1e888.get_9b7910()->type != 0x22 && uf_d1e888.get_9b7910()->type != 0x23)
								{
									do
									{
										uf_cf1080.set_451400(true);
										if (false)
											uf_sound_4541b0(-1,0,0);
										do
										{
											if (uf_show_5111e0b(0x324,&string("ALERT: Sigix Warrior active in local area. Maximum security lockdown in progress."),0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									uf_cf6464 = 5;
									uf_cf6428.unknown68d980(1,1,1);
								}
								break;
							case 128:
							{
								UfVHE &g = uf_cefc4c->group_463890(2).get_9b7250()->members_416f40();
								if (!g.empty_9b86e0())
								{
									for (int i = g.size_9b9260() - 1; i >= 0; i--)
									{
										if (g.at_9b81f0(i).get_9b6570()->getFaction_45a2c0() == 0x56 || g.at_9b81f0(i).get_9b6570()->getFaction_45a2c0() == 0x58 || g.at_9b81f0(i).get_9b6570()->getFaction_45a2c0() == 0x57)
											g.at_9b81f0(i).get_9b6570()->changeFaction_5dc780(uf_cefc4c->group_463890(5),0);
									}
								}
								break;
							}
							case 129:
							{
								UfHP p7 = PROPX;
								if (!p7.get_9b64f0())
									goto nextEff;
								UfHP q = p7;
								string title(uf_d1e900.at_9b06a0(0x1f));
								uf_cefc88 = true;
								UfHE h2;
								UfPoint q42(-1);
								bool busy5 = false;
								uf_cefc4c->unknown74bb90(q,&h2,&q42,&busy5);
								string msg1("Accessing seal controls...");
								if (busy5)
								{
									msg1 += "\nError: Seal state transition in progress.";
									uf_cec100->addNew_90d550(title,msg1,3,-1,0);
								}
								else if (h2.isNull_9b65d0() || q42.x == -1)
								{
									msg1 += "\nError: Unable to establish connection.";
									uf_cec100->addNew_90d550(title,msg1,3,-1,0);
								}
								else
								{
									msg1 += "\nDisengaging subsurface cave network seal C" + uf_intToString_4051f0(rng.rangeInt_406d70(100,999)) + ".";
									msg1 += "\nWarning: Hostile activity detected below.";
									uf_cefc4c->unknown6c6b90(q42,"COM_Cave_Seal_Timer",0,-1);
									uf_cec100->addNew_90d550(title,msg1,1,-1,0);
								}
								break;
							}
							case 130:
							{
								UfHP seal;
								UfVPt q48;
								uf_surrounding_4faaf0(w3->pos_45d1a0(),&q48);
								for (unsigned m = 0; m < q48.size_9b9a50(); m++)
								{
									if (CELLAT(q48.at_9e7c10(m))->getProp_45d550().isValid_9b7230() && !CELLAT(q48.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown45cb10() && CELLAT(q48.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown44ab40() != -1 && !CELLAT(q48.at_9e7c10(m))->getProp_45d550().get_9b64f0()->unknown457b10())
									{
										seal = CELLAT(q48.at_9e7c10(m))->getProp_45d550();
										break;
									}
								}
								UfPoint sp(-1);
								if (seal.isValid_9b7230())
								{
									UfVHP marks(uf_d31640.at_9b8070(seal.get_9b64f0()->unknown44ab40()));
									for (unsigned m2 = 0; m2 < marks.size_9b9260(); m2++)
									{
										if (marks.at_9b81f0(m2).get_9b64f0()->unknown44a630() == 0x97)
										{
											sp = marks.at_9b81f0(m2).get_9b64f0()->pos_4184d0();
											break;
										}
									}
									for (unsigned m3 = 0; m3 < marks.size_9b9260(); m3++)
										marks.at_9b81f0(m3).get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								}
								if (sp.x != -1 || uf_cefc4c->findPropSpotNear_71c3c0(w3->pos_45d1a0(),sp,0))
								{
									UfFaction *f;
									if (uf_findByName_9d7710(uf_cf35b0,"COM_Cave_Spawn",&f) && CELLAT(sp)->unknown45df50(uf_cefaa8->createE_793360(f)))
									{
										CELLAT(sp)->getProp_45d550().get_9b64f0()->unknown45cc50(sp);
										UfAbil *ab;
										if (uf_findByName_9d7de0(uf_d2c408,"COM_Cave_Spawn",&ab))
										{
											CELLAT(sp)->getProp_45d550().get_9b64f0()->unknown665b10(ab,0);
											uf_cefc4c->unknown464e60(CELLAT(sp)->getProp_45d550());
											uf_d1ec20.push_back_9b32e0(sp);
											uf_d1ec30.push_back_9b9280(0);
											uf_d1ec40.push_back_9b9280(0);
											void *xd;
											if (uf_findByName_9d7be0(uf_cfd2cc,"COM_Cave_Seal",&xd))
												uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),xd,sp,UfHE(),UfPoint(-1),UfPoint(-1))));
										}
									}
								}
								if (uf_d1ec50 == -1)
								{
									if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("zioWasImprinted_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("zioAttackedLocals_g")))
										uf_d1ec50 = 3;
									else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warMetWarlord_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warAttackedLocals_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warWarlordDestroyed_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("zioWasImprinted_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrAttackedLocals_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("scrUfdRegistered_g")))
										uf_d1ec50 = 2;
									else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")))
										uf_d1ec50 = 1;
									else
										uf_d1ec50 = 0;
								}
								break;
							}
							case 131:
							{
								int maxN = 4;
								UfRange delay(0x64,0x96);
								int q49 = uf_indexOfPoint_9d53a0(uf_d1ec20,w3->pos_45d1a0());
								if (q49 == -1)
									goto end131;
								if (uf_d1ec30.at_9b81f0(q49) < 4 && (uf_d1ec30.at_9b81f0(q49) == 0 || uf_cefc4c->getTurn_464270() >= uf_d1ec40.at_9b81f0(q49)))
								{
									switch (uf_d1ec50)
									{
										case 0:
										{
											UfWLS wl;
											wl.add_9b9f50("Thug_7",0x14);
											wl.add_9b9f50("Savage_7",5);
											wl.add_9b9f50("Butcher_7",5);
											wl.add_9b9f50("Guerilla_7",0xf);
											wl.add_9b9f50("Wizard_7",0xf);
											wl.add_9b9f50("Fireman_7",5);
											wl.add_9b9f50("Mutant_7",0xf);
											wl.add_9b9f50("Mutant_8",0x14);
											int n = uf_d1ec30.at_9b81f0(q49) == 1 ? rng.rangeInt_406d70(12,18) : rng.rangeInt_406d70(4,6);
											UfHE first;
											UfBox areaRef = uf_cfd44c.getArea_9b4400();
											for (int k = 0; k < n; k++)
											{
												UfEntityDef *d;
												if (!uf_findByName_9d7530(uf_d25de0,wl.pick_9b9fd0(),&d))
													continue;
												UfHE rb1 = uf_cefc4c->placeEntity_6c58c0(d,w3->pos_45d1a0(),5,0,0x22,0xe,0);
												if (rb1.isValid_9b7230())
												{
													rb1.get_9b6570()->ai_45b590()->unknown459470(areaRef);
													if (first.isNull_9b65d0() && uf_d1ec30.at_9b81f0(q49) == 0)
													{
														uf_cefc4c->unknown6c65a0(rb1,"COM_Derelict_Talk",0);
														first = rb1;
													}
												}
											}
											do
											{
												uf_logPhrase_5141b0(0x211,&string("Wild derelicts"),0,0,UfHE(),&w3->pos_45d1a0());
											}
											while (0);
											if (uf_d25450.b0)
												uf_d25450.unknown69e700(0x75,uf_cefc4c->isVisible_4631c0(w3->pos_45d1a0()) ? 1 : 0,0);
											break;
										}
										case 1:
										{
											UfPoint sp;
											if (uf_cefc4c->findPropSpotNear_71c3c0(w3->pos_45d1a0(),sp,0))
												uf_cefc4c->unknown6c6b90(sp,uf_d1ec30.at_9b81f0(q49) ? "COM_Cave_Spawn_Assemb_X" : "COM_Cave_Spawn_Assemb_1",0,-1);
											break;
										}
										case 2:
										{
											int waves = uf_d1ec30.at_9b81f0(q49) == 0 ? 3 : 1;
											if (uf_d1eb68 >= 0x1e)
												waves++;
											UfVVStr groups;
											UfVecU weights;
											int rb4 = uf_d1eb68;
											if (rb4 == 0)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),6,"Wasp_7");
												weights.push_back_9b9280(0xa);
											}
											if (rb4 == 0)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Thug_7");
												weights.push_back_9b9280(0xa);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Savage_7");
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Butcher_7");
											}
											if (rb4 == 0)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),5,"Butcher_7");
												weights.push_back_9b9280(0xa);
											}
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),5,"Thug_7");
											weights.push_back_9b9280(0xa);
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Guerilla_7");
											weights.push_back_9b9280(0xa);
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Wasp_7");
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Wizard_7");
											weights.push_back_9b9280(0xa);
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Mutant_8");
											weights.push_back_9b9280(0xa);
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Mutant_7");
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Martyr_7");
											weights.push_back_9b9280(0xa);
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Mutant_8");
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Thug_7");
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),5,"Fireman_7");
											weights.push_back_9b9280(0xa);
											groups.push_back_9b2d50(UfVStr2());
											groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Marauder_8");
											weights.push_back_9b9280(0xa);
											if (rb4 >= 0xa)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),5,"Thug_7");
												weights.push_back_9b9280(0x32);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0xa)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),4,"Guerilla_7");
												weights.push_back_9b9280(0x32);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0xa)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),4,"Wizard_7");
												weights.push_back_9b9280(0x32);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0xa)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Mutant_8");
												weights.push_back_9b9280(0x32);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),2,"Mutant_7");
											}
											if (rb4 >= 0x14)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),4,"Mutant_8");
												weights.push_back_9b9280(0x64);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0x14)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Marauder_8");
												weights.push_back_9b9280(0x64);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0x14)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),8,"Butcher_7");
												weights.push_back_9b9280(0x64);
											}
											if (rb4 >= 0x14)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),8,"Fireman_7");
												weights.push_back_9b9280(0x64);
											}
											if (rb4 >= 0x1e)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Troll");
												weights.push_back_9b9280(0x96);
											}
											if (rb4 >= 0x1e)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Knight");
												weights.push_back_9b9280(0x96);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0x1e)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Guerilla_7");
												weights.push_back_9b9280(0x96);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Thug_7");
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),3,"Wizard_7");
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											if (rb4 >= 0x1e)
											{
												groups.push_back_9b2d50(UfVStr2());
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),8,"Thug_7");
												weights.push_back_9b9280(0x96);
												groups.back_9b5ac0().insert_9b0860(groups.back_9b5ac0().end_9e9b30(),1,"Surgeon_6");
											}
											UfWL wl(weights);
											int b3 = 0x32;
											UfWLS bosses;
											bosses.add_9b9f50("Commander",1);
											bosses.add_9b9f50("Knight",1);
											bosses.add_9b9f50("Troll",1);
											int fac = !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("comPlayerSurrendered_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warAttackedLocals_g")) ? 9 : 5;
											UfHE leaderTmp;
											UfBox area_ = uf_cfd44c.getArea_9b4400();
											for (int w = 0; w < waves; w++)
											{
												UfHE boss;
												UfHE last;
													int h1 = wl.pick_9ba470();
												UfVStr2 &h5 = groups.at_9b8070(h1);
												for (unsigned k = 0; k < h5.size_9b0650(); k++)
												{
													if (k == 0 && rng.chance_406c90(0x32))
													{
														boss = uf_cefc4c->unknown6c5dc0(bosses.pick_9b9fd0(),w3->pos_45d1a0(),fac,0,0x22,0xe,0);
														if (boss.isValid_9b7230())
															boss.get_9b6570()->ai_45b590()->unknown459470(area_);
													}
													last = uf_cefc4c->unknown6c5dc0(h5.at_9b06a0(k),w3->pos_45d1a0(),fac,0,0x22,0xe,0);
													if (last.isValid_9b7230())
													{
														last.get_9b6570()->ai_45b590()->unknown459470(area_);
														if (boss.isNull_9b65d0())
															boss = last;
														else
															last.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(boss,0);
													}
												}
												if (boss.isValid_9b7230() && !uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb680(uf_cefc4c->group_463890(fac)) && (rng.chance_406c90(0x32) || leaderTmp.isNull_9b65d0() && uf_d1ec30.at_9b81f0(q49) == 0))
													boss.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
												if (boss.isValid_9b7230() && leaderTmp.isNull_9b65d0() && uf_d1ec30.at_9b81f0(q49) == 0 && !uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb680(uf_cefc4c->group_463890(fac)))
												{
													uf_cefc4c->unknown6c65a0(boss,"COM_Warlord_Squad_Talk",0);
													leaderTmp = boss;
												}
												if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("comWarlordArrived_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("warWarlordDestroyed_g")))
												{
													UfHE wlord = uf_cefc4c->unknown6c5dc0("Warlord_B",w3->pos_45d1a0(),fac,0,0x22,0xe,0);
													if (wlord.isValid_9b7230())
													{
														uf_cefc4c->unknown6c65a0(wlord,"WAR_Warlord_Death",0);
														uf_cefc4c->unknown6c65a0(wlord,"COM_Warlord_Arrive_Talk",0);
														uf_cefc4c->unknown6c65a0(wlord,"COM_Warlord_Arrive_Done",0);
														uf_cefc4c->unknown6c65a0(wlord,"COM_Warlord_Statu_Check",0);
														uf_cefc4c->unknown6c65a0(wlord,"COM_Warlord_Mainc_Check",0);
														wlord.get_9b6570()->ai_45b590()->unknown459470(area_);
														wlord.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),2);
														uf_d1e860.setEntryText_46f700("comWarlordArrived_g","1");
														if (boss.isValid_9b7230())
															boss.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(wlord,0);
													}
												}
											}
											if (uf_d1eb68 && uf_d1ec30.at_9b81f0(q49) == 1 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("comCommArrayBodyguadsArrived_g")) && fac == 9)
											{
												UfVStr2 sq;
												if (uf_cefc4c->spawnSquads_73e5c0(w3->pos_45d1a0(),&sq))
													uf_d1e860.setEntryText_46f700("comCommArrayBodyguadsArrived_g","1");
											}
											if (uf_cefc4c->isVisible_4631c0(w3->pos_45d1a0()))
											{
												uf_message_49c610(0x320,UfHE(),&string("Derelicts emerge from the dark tunnel."),0);
												do
												{
													uf_logPhrase_5141b0(0x211,&string("Derelicts"),0,0,UfHE(),&w3->pos_45d1a0());
												}
												while (0);
											}
											break;
										}
										case 3:
											int h8 = uf_d1ec30.at_9b81f0(q49) == 0 ? 3 : 1;
											UfVVStr rc1;
											UfVecU weights3;
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Z_Light_9");
											rc1.back_9b5ac0().push_back_9b06f0("Z_Light_9");
											rc1.back_9b5ac0().push_back_9b06f0("Z_Light_9");
											rc1.back_9b5ac0().push_back_9b06f0("Z_Light_9");
											weights3.push_back_9b9280(0xa);
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Z_Heavy_9");
											rc1.back_9b5ac0().push_back_9b06f0("Z_Heavy_9");
											rc1.back_9b5ac0().push_back_9b06f0("Z_Heavy_9");
											weights3.push_back_9b9280(0xf);
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Wizard_7");
											rc1.back_9b5ac0().push_back_9b06f0("Wizard_7");
											rc1.back_9b5ac0().push_back_9b06f0("Wizard_7");
											weights3.push_back_9b9280(0xa);
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_8");
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_8");
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_7");
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_7");
											weights3.push_back_9b9280(0xa);
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Martyr_7");
											rc1.back_9b5ac0().push_back_9b06f0("Martyr_7");
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_8");
											rc1.back_9b5ac0().push_back_9b06f0("Mutant_8");
											weights3.push_back_9b9280(0xa);
											rc1.push_back_9b2d50(UfVStr2());
											rc1.back_9b5ac0().push_back_9b06f0("Fireman_7");
											rc1.back_9b5ac0().push_back_9b06f0("Fireman_7");
											rc1.back_9b5ac0().push_back_9b06f0("Fireman_7");
											rc1.back_9b5ac0().push_back_9b06f0("Fireman_7");
											rc1.back_9b5ac0().push_back_9b06f0("Fireman_7");
											weights3.push_back_9b9280(0xa);
											UfWL hs(weights3);
											int maxN3 = 0x32;
											UfWLS d9;
											d9.add_9b9f50("Z_Experiment_8",1);
											d9.add_9b9f50("Z_Experiment_10",1);
											int fac3 = uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("comPlayerSurrendered_g")) ? 5 : 2;
											UfHE rd9;
											UfBox re9 = uf_cfd44c.getArea_9b4400();
											for (int w = 0; w < h8; w++)
											{
												UfHE boss;
												UfHE last;
												int b9;
													int i1 = hs.pick_9ba470();
												UfVStr2 &iA = rc1.at_9b8070(i1);
												for (unsigned k = 0; k < iA.size_9b0650(); k++)
												{
													if (k == 0 && rng.chance_406c90(0x32))
													{
														b9 = uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")) ? 1 : fac3;
														boss = uf_cefc4c->unknown6c5dc0(d9.pick_9b9fd0(),w3->pos_45d1a0(),b9,0,0x22,0xe,0);
														if (boss.isValid_9b7230())
															boss.get_9b6570()->ai_45b590()->unknown459470(re9);
													}
													b9 = iA.at_9b06a0(k).find("Z_",0) != string::npos && uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")) ? 1 : fac3;
													last = uf_cefc4c->unknown6c5dc0(iA.at_9b06a0(k),w3->pos_45d1a0(),b9,0,0x22,0xe,0);
													if (last.isValid_9b7230())
													{
														last.get_9b6570()->ai_45b590()->unknown459470(re9);
														if (boss.isNull_9b65d0())
															boss = last;
														else
															last.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(boss,0);
													}
												}
												if (boss.isValid_9b7230() && !uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb680(uf_cefc4c->group_463890(fac3)) && (rng.chance_406c90(0x32) || rd9.isNull_9b65d0() && uf_d1ec30.at_9b81f0(q49) == 0))
													boss.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
												if (boss.isValid_9b7230() && rd9.isNull_9b65d0() && uf_d1ec30.at_9b81f0(q49) == 0 && !uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cb680(uf_cefc4c->group_463890(fac3)))
												{
													uf_cefc4c->unknown6c65a0(boss,"COM_Zionite_Talk",0);
													rd9 = boss;
												}
											}
											if (uf_cefc4c->isVisible_4631c0(w3->pos_45d1a0()))
											{
												uf_message_49c610(0x320,UfHE(),&string("Zionites emerge from the dark tunnel."),0);
												do
												{
													uf_logPhrase_5141b0(0x211,&string("Zionites"),0,0,UfHE(),&w3->pos_45d1a0());
												}
												while (0);
											}
											uf_cf45d8.unlock_77fbc0(0x1b3);
											break;
									}
									uf_d1ec30.at_9b81f0(q49)++;
									uf_d1ec40.at_9b81f0(q49) = uf_cefc4c->getTurn_464270() + delay.randomInRange_40c130();
								}
							end131:
								break;
							}
							case 132:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isValid_9b7230())
								{
									UfRect r(0x99,0x4a,0xab,0x50);
									if (uf_cefc4c->unknown463400(w) && r.contains_40b750(w.get_9b6570()->getPosition_45a4a0()))
									{
										for (int x = r.x1; x <= r.x2; x++)
										{
											for (int y = r.y1; y <= r.y2; y++)
											{
												if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().get_9b6570()->getFaction_45a2c0() == 0x5c)
												{
													uf_cefc4c->unknown6c6600(w,"COM_Warlord_Statu_Check");
													uf_cefc4c->unknown6c65a0(w,"COM_Warlord_Statues_T",0);
													goto end132;
												}
											}
										}
									}
								}
							end132:
								break;
							}
							case 133:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isValid_9b7230())
								{
									UfHE s = uf_cefc4c->unknown715230(2,0x5e);
									if (s.isValid_9b7230() || uf_cf4a00)
										uf_cefc4c->unknown6c65a0(w,"RES_Warlord_Sigix_Check",0);
								}
								break;
							}
							case 134:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230())
								{
									w.get_9b6570()->unknown6396f0("COM_Warlord_Mainc_Talk",1);
									w.get_9b6570()->unknown6396f0("COM_Warlord_Mainc_Done",1);
									w.get_9b6570()->unknown6396f0("COM_Warlord_Mainc_Check",1);
									uf_cefc4c->unknown6c65a0(w,"COM_Warlord_MaincB_Talk",0);
								}
								break;
							}
							case 135:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230() && !w.get_9b6570()->getTarget_45a760())
								{
									UfHE m = uf_cefc4c->unknown715230(3,0x5f);
									if (uf_strEq_9ccb50(m.get_9b6570()->getName_45a280(),"MAINC_A"))
									{
										uf_cefc4c->unknown6c65a0(w,"COM_Warlord_Mainc_Talk",0);
										uf_cefc4c->unknown6c65a0(w,"COM_Warlord_Mainc_Done",0);
									}
									else
										uf_cefc4c->unknown6c65a0(w,"COM_Warlord_MaincB_Talk",0);
								}
								break;
							}
							case 136:
							{
								UfHE m = uf_cefc4c->unknown715230(3,0x5f);
								if (m.isValid_9b7230())
								{
									uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Warlord_Bye",0);
									uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Warlord_Zya",0);
									uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Shuts_Warlord",0);
								}
								break;
							}
							case 137:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230())
								{
									UfHE m = uf_cefc4c->unknown715230(3,0x5f);
									if (m.isValid_9b7230() && w.get_9b6570()->ai_45b590()->unknown458fb0(m))
									{
										w.get_9b6570()->unknown6396f0("COM_Warlord_Mainc_Check",1);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Shuts_W_Timer",0);
									}
								}
								break;
							}
							case 138:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230())
									w.get_9b6570()->unknown45b070(string("ZY-L1N"));
								break;
							}
							case 139:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230())
								{
									UfHE m = uf_cefc4c->unknown715230(3,0x5f);
									if (m.isValid_9b7230() && uf_cefc4c->unknown72a850(0x18,m,w))
									{
										if (uf_cefc4c->unknown4631f0(w))
										{
											string msg("Warlord shuts down.");
											uf_message_49c610(0x320,UfHE(),&msg,0);
											do
											{
												uf_logPhrase_5141b0(0x217,0,0,0,UfHE(),0);
											}
											while (0);
											uf_cf45d8.unlock_77fbc0(0x1b2);
										}
										w.get_9b6570()->unknown5fd900(8,0);
										w.get_9b6570()->unknown639730(0);
										m.get_9b6570()->unknown6396f0("COM_Mainc_Warlord_Bye",1);
										m.get_9b6570()->unknown6396f0("COM_Mainc_Warlord_Zya",1);
										m.get_9b6570()->unknown6396f0("COM_Mainc_Shuts_Warlord",1);
										m.get_9b6570()->unknown6396f0("COM_Mainc_Shuts_W_Timer",1);
									}
								}
								break;
							}
							case 140:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isValid_9b7230())
								{
									uf_cefc4c->unknown6c65a0(w,"COM_Warlord_Win",0);
									uf_cefc4c->unknown6c65a0(w,"COM_Warlord_Win_Done",0);
								}
								break;
							}
							case 141:
								uf_d1e860.setEntryText_46f700("comWarlordVictory_g","1");
								uf_cefc4c->unknown464710(4);
								break;
							case 142:
								uf_d1e860.setEntryText_46f700("comPlayerSurrenderedVictory_g","1");
								uf_cefc4c->unknown464710(4);
								break;
							case 143:
							{
								UfHE w = uf_cefc4c->unknown715230(9,0x5b);
								if (w.isNull_9b65d0())
									w = uf_cefc4c->unknown715230(5,0x5b);
								if (w.isValid_9b7230() && w.get_9b6570()->getTarget_45a760() < 6 || uf_cefc4c->unknown715230(2,0x5e).isValid_9b7230())
									uf_d1e860.setEntryText_46f700("comMajorNpcsPresent_g","1");
								break;
							}
							case 144:
							{
								UfHE s = uf_cefc4c->unknown715230(2,0x5e);
								if (s.isValid_9b7230())
								{
									uf_cefc4c->unknown6c65a0(s,"COM_Sigix_Dialogue",0);
									uf_cefc4c->unknown6c65a0(s,"COM_Sigix_Dialogue_End",0);
								}
								break;
							}
							case 145:
							{
								UfRect r(UfPoint(0x91,0x46),3,3);
								for (int x = r.x1; x <= r.x2; x++)
								{
									for (int y = r.y1; y <= r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230() && uf_strEq_9ccb50((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->location_45c590(),"COM_Door_Hackable"))
											(*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
									}
								}
								break;
							}
							case 146:
							{
								UfHE rh3;
								UfVHE &g = uf_cefc4c->group_463890(3).get_9b7250()->members_416f40();
								for (int i = g.size_9b9260() - 1; i >= 0; i--)
								{
									if (uf_strEq_9ccb50(g.at_9b81f0(i).get_9b6570()->getName_45a280(),"MAINC_B"))
									{
										rh3 = g.at_9b81f0(i);
										break;
									}
								}
								if (rh3.isValid_9b7230())
									uf_cefc4c->giveItem_6c52b0("MAIN.C Data Core",rh3,0,0);
								break;
							}
							case 147:
								uf_cefc4c->unknown747860(0,1);
								break;
							case 148:
								uf_cefc4c->unknown7457f0();
								break;
							case 149:
							{
								UfHE e9 = ENTX;
								if (!e9.get_9b6570())
									goto nextEff;
								UfRect c5;
								uf_cfd44c.getRect_9b4430(e9.get_9b6570()->pos_45a4c0(),2,c5);
								for (int x = c5.x1; x <= c5.x2; x++)
								{
									for (int y = c5.y1; y <= c5.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().isValid_9b7230() && !(*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->isPassableFor_65e1d0(UfHE()))
											(*uf_cfd44c.at_9ceda0(x,y))->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
										if (!(*uf_cfd44c.at_9ceda0(x,y))->isPassableFor_66ab30(UfHE()))
											(*uf_cfd44c.at_9ceda0(x,y))->trigger_45e110(0,0,UfHE());
									}
								}
								UfVPt bD;
								bD.push_back_9b3020(UfPoint(c5.x1 + 2,c5.y1));
								bD.push_back_9b3020(UfPoint(c5.x1,c5.y1 + 2));
								bD.push_back_9b3020(UfPoint(c5.x2,c5.y1 + 2));
								bD.push_back_9b3020(UfPoint(c5.x1 + 2,c5.y2));
								UfVPt b_;
								b_.push_back_9b3020(UfPoint(c5.x1,c5.y1));
								b_.push_back_9b3020(UfPoint(c5.x2,c5.y1));
								b_.push_back_9b3020(UfPoint(c5.x1,c5.y2));
								b_.push_back_9b3020(UfPoint(c5.x2,c5.y2));
								UfVHE2 aR;
								UfEntityDef *c4;
								if (uf_findByName_9d7530(uf_d25de0,"M Shell/Atk",&c4))
								{
									UfHE s;
									for (unsigned k = 0; k < bD.size_9b9a50(); k++)
									{
										s = uf_cefc4c->placeEntity_6c58c0(c4,bD.at_9e7c10(k),3,0,0x22,0xe,0);
										if (s.isValid_9b7230())
											aR.push_back_9b80b0(s);
									}
								}
								UfVHE2 defs;
								UfEntityDef *dd;
								if (uf_findByName_9d7530(uf_d25de0,"M Shell/Def",&dd))
								{
									UfHE s2;
									for (unsigned k2 = 0; k2 < b_.size_9b9a50(); k2++)
									{
										s2 = uf_cefc4c->placeEntity_6c58c0(dd,b_.at_9e7c10(k2),3,0,0x22,0xe,0);
										if (s2.isValid_9b7230())
										{
											defs.push_back_9b80b0(s2);
											if (k2 < aR.size_9b9260())
												s2.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(aR.at_9b81f0(k2),0);
										}
									}
								}
								UfEntityDef *he;
								if (uf_findByName_9d7530(uf_d25de0,"MAINC_B",&he))
								{
									UfHE m;
									uf_appendVector_9d7f20(bD,b_);
									uf_shuffle_9d7350(bD);
									for (unsigned k3 = 0; k3 < bD.size_9b9a50(); k3++)
									{
										m = uf_cefc4c->placeEntity_6c58c0(he,bD.at_9e7c10(k3),3,0,0x22,0xe,0);
										if (m.isValid_9b7230())
											break;
									}
									if (m.isNull_9b65d0() && !defs.empty_9b86e0())
									{
										UfPoint dp(defs.at_9b81f0(0).get_9b6570()->getPosition_45a4a0());
										defs.at_9b81f0(0).get_9b6570()->unknown637bb0();
										m = uf_cefc4c->placeEntity_6c58c0(he,dp,3,0,0x22,0xe,0);
									}
									if (m.isValid_9b7230())
									{
										m.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(uf_cefc4c->getPlayer_4630f0(),0);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Dialogue_B",0);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Reinforce_B",0);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Reinf2_B",0);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Hack",0);
										uf_cefc4c->unknown6c65a0(m,"COM_Mainc_Death_B",0);
										string msg("MAIN.C's core emerges from the shell as its internal framework transforms into a squad of autonomous robots.");
										uf_message_49c610(0x320,UfHE(),&msg,&e9.get_9b6570()->getPosition_45a4a0());
										do
										{
											uf_logPhrase_5141b0(0x221,0,0,0,e9,0);
										}
										while (0);
										uf_shuffle_9d9fc0(aR);
										for (unsigned k4 = 0; k4 < aR.size_9b9260(); k4++)
											aR.at_9b81f0(k4).get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(k4 < aR.size_9b9260() / 2 ? m : uf_cefc4c->getPlayer_4630f0(),0);
									}
									else
										uf_logError_404f10("checkTriggers()::Anti-Sigix Form","no spawn point");
								}
								break;
							}
							case 150:
							{
								do
								{
									uf_cf1080.set_451400(true);
									if (false)
										uf_sound_4541b0(-1,0,0);
									do
									{
										if (uf_show_5111e0b(0x324,&string("ALERT: LRC-V3 rejoined 0b10. Threat protocols amended."),0,0,UfHE(),UfHE(),0,0))
											uf_cec058->bubble_8758d0(true);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (false);
								UfVHE2 a6(uf_cefc4c->group_463890(2).get_9b7250()->members_416f40());
								uf_appendVector_9d49c0(a6,uf_cefc4c->group_463890(9).get_9b7250()->members_416f40());
								if (!a6.empty_9b86e0())
								{
									UfHG g5 = uf_cefc4c->group_463890(5);
									for (int i = a6.size_9b9260() - 1; i >= 0; i--)
									{
										if ((a6.at_9b81f0(i).get_9b6570()->getAiType_45a2a0() == 3 || a6.at_9b81f0(i).get_9b6570()->getAiType_45a2a0() == 0) && a6.at_9b81f0(i).ne_9b6510(uf_cefc4c->getEntity671_463110()))
											a6.at_9b81f0(i).get_9b6570()->changeFaction_5dc780(g5,1);
									}
								}
								UfArr2 *arr = uf_cefc4c->unknown4638c0();
								for (int i2 = 0; i2 <= 2; i2++)
								{
									*arr->at_9ceda0(3,i2) = 2;
									*arr->at_9ceda0(i2,3) = 2;
								}
								uf_cf6428.resetField_9b7270();
								UfVVPt *b6 = uf_cefc4c->unknown459070m();
								for (int a = 0; a < 9; a++)
								{
									for (unsigned b = 0; b < b6->at_9b8070(a).size_9b9a50(); b++)
										CELLAT(b6->at_9b8070(a).at_9e7c10(b))->getProp_45d550().get_9b64f0()->unknown45cb30()->x28 = -1;
								}
								uf_d1e860.setEntryText_46f700("comConduitDisabled_g",uf_intToString_4051f0(1));
								UfVHP conds;
								conds.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(0x71,0x49))->getProp_45d550());
								conds.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(0x74,0x4c))->getProp_45d550());
								for (unsigned k = 0; k < conds.size_9b9260(); k++)
								{
									if (conds.at_9b81f0(k).isValid_9b7230() && uf_strEq_9ccb50(conds.at_9b81f0(k).get_9b64f0()->location_45c590(),"COM_0b10_Conduit") && !conds.at_9b81f0(k).get_9b64f0()->unknown457b10())
										conds.at_9b81f0(k).get_9b64f0()->disableMachine_65ed00();
								}
								for (int x = 0xf; x < uf_cfd44c.getWidth_9fcd80(); x++)
								{
									for (int y = 0; y < uf_cfd44c.getHeight_9b8f00(); y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->unknown45d0e0() != uf_cefb80->x0)
											uf_cefc4c->unknown7243c0(x,y,0);
									}
								}
								uf_reveal_794da0(9,0,0,0x26);
								uf_reveal_794da0(6,0,0,0x26);
								uf_reveal_794da0(7,0,0,0x26);
								uf_reveal_794da0(5,0,0,0x26);
								uf_reveal_794da0(8,0,0,0x26);
								UfVZone *zs = uf_cefc4c->zones_462e10();
								for (unsigned m = 0; m < zs->size_9b9260(); m++)
								{
									if (zs->at_9b81f0(m)->h14.isNull_9b65d0() && !uf_b90480[zs->at_9b81f0(m)->loc.get_9b7910()->type])
									{
										uf_cefc4c->announceMachine_71dd30(zs->at_9b81f0(m)->loc);
										uf_cefc4c->unknown4647a0(zs->at_9b81f0(m)->pt,1);
										zs->at_9b81f0(m)->bd = true;
										zs->at_9b81f0(m)->unknown6c16d0("FOUND");
										uf_cec054->labelAccess_80e3a0(1,zs->at_9b81f0(m));
									}
								}
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("comMaincReinforced_g")))
								{
									uf_d1e860.setEntryText_46f700("comMaincReinforced_g","0");
									for (unsigned k2 = 0; k2 < uf_d1ec00.size_9b9260(); k2++)
									{
										if (uf_d1ec00.at_9b81f0(k2).get_9b6570())
											uf_d1ec00.at_9b81f0(k2).get_9b6570()->ai_45b590()->unknown459380(uf_d1ec10.at_9e7c10(k2));
									}
								}
								UfHE mc = uf_cefc4c->unknown715230(3,0x5f);
								if (mc.isValid_9b7230())
								{
									mc.get_9b6570()->unknown6396f0("COM_Mainc_Death_B",1);
									uf_cefc4c->unknown6c65a0(mc,"COM_Mainc_Death_C",0);
									mc.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(UfHE(),0);
									mc.get_9b6570()->ai_45b590()->unknown459380(UfPoint(0x72,0x49));
								}
								uf_cefc4c->group_463890(3).get_9b7250()->resetField_45e460();
								uf_cefc4c->group_463890(3).get_9b7250()->unknown458460();
								UfZone *e3 = 0;
								for (unsigned m2 = 0; m2 < zs->size_9b9260(); m2++)
								{
									if (zs->at_9b81f0(m2)->loc.get_9b7910()->type == 0x23)
									{
										e3 = zs->at_9b81f0(m2);
										break;
									}
								}
								if (e3)
								{
									CELLAT(e3->pt)->unknown66a050(*uf_cefb9c,2,1);
									delete e3;
									uf_eraseZone_9d51d0(*zs,e3);
									e3 = 0;
								}
								for (int x2 = 0; x2 < 0x10; x2++)
								{
									for (int y2 = 0; y2 < uf_cfd44c.getHeight_9b8f00(); y2++)
									{
										if ((*uf_cfd44c.at_9ceda0(x2,y2))->getProp_45d550().isValid_9b7230() && uf_strEq_9ccb50((*uf_cfd44c.at_9ceda0(x2,y2))->getProp_45d550().get_9b64f0()->location_45c590(),"ARM_Dimension_Slip_Node"))
										{
											(*uf_cfd44c.at_9ceda0(x2,y2))->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,0,UfHE());
											break;
										}
									}
								}
								uf_d1ec54 = uf_cefc4c->unknown4642f0() + rng.rangeInt_406d70(100,150);
								uf_d1ec58 = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(400,500);
								break;
							}
							case 151:
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("accZhirovRetrievedSGEMP_g")))
								{
									UfHE z;
									UfHE bB;
									UfHE b;
									if (uf_cefc4c->unknown6f0f80(&z,&bB,&b))
									{
										uf_cefc4c->unknown6c65a0(z,"COM_Zhirov_Dialogue_1",0);
										uf_cefc4c->unknown6c65a0(z,"COM_Zhirov_Dialogue_End",0);
									}
								}
								break;
							case 152:
							{
								uf_d1e860.setEntryText_46f700("comZhirovActivatedSGEMP_g","1");
								uf_cf6428.resetField_9b7270();
								UfVHE2 ents;
								uf_appendVector_9d49c0(ents,uf_cefc4c->group_463890(3).get_9b7250()->members_416f40());
								uf_appendVector_9d49c0(ents,uf_cefc4c->group_463890(4).get_9b7250()->members_416f40());
								for (unsigned k = 0; k < ents.size_9b9260(); k++)
									ents.at_9b81f0(k).get_9b6570()->unknown5fd900(8,0);
								UfHE i6 = uf_cefc4c->unknown715230(9,0x5b);
								if (i6.isNull_9b65d0())
									i6 = uf_cefc4c->unknown715230(5,0x5b);
								if (i6.isValid_9b7230())
									i6.get_9b6570()->unknown5fd900(8,0);
								UfVVPt *marks = uf_cefc4c->unknown459070m();
								for (int a = 0; a < 9; a++)
								{
									while (!marks->at_9b8070(a).empty_9b86e0())
										CELLAT(marks->at_9b8070(a).back_9e8c10())->getProp_45d550().get_9b64f0()->disableMachine_65ed00();
								}
								uf_d1e860.setEntryText_46f700("comConduitDisabled_g",uf_intToString_4051f0(1));
								UfVHP i9;
								i9.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(0x71,0x49))->getProp_45d550());
								i9.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(0x74,0x4c))->getProp_45d550());
								for (unsigned k2 = 0; k2 < i9.size_9b9260(); k2++)
								{
									if (i9.at_9b81f0(k2).isValid_9b7230() && uf_strEq_9ccb50(i9.at_9b81f0(k2).get_9b64f0()->location_45c590(),"COM_0b10_Conduit") && !i9.at_9b81f0(k2).get_9b64f0()->unknown457b10())
										i9.at_9b81f0(k2).get_9b64f0()->disableMachine_65ed00();
								}
								if (uf_d25450.b0)
									uf_d1ec68 = uf_cefc4c->unknown4642d0() + 100;
								break;
							}
							case 153:
							{
								int e2 = uf_cefc4c->group_463890(3).get_9b7250()->members_416f40().size_9b9260() > uf_cefc4c->group_463890(5).get_9b7250()->members_416f40().size_9b9260() ? 3 : 5;
								int g2 = e2 == 3 ? 5 : 3;
								UfVHE2 ents(uf_cefc4c->group_463890(e2).get_9b7250()->members_416f40());
								if (ents.size_9b9260() < 20 && uf_cefc4c->group_463890(g2).get_9b7250()->members_416f40().size_9b9260() < 20)
								{
									uf_appendVector_9d49c0(ents,uf_cefc4c->group_463890(g2).get_9b7250()->members_416f40());
									for (unsigned k = 0; k < ents.size_9b9260(); k++)
									{
										if (!ents.at_9b81f0(k).get_9b6570()->getTarget_45a760())
										{
											if (uf_cefc4c->unknown4631f0(ents.at_9b81f0(k)))
											{
												string s("[name] shuts down.");
												do
												{
													if (uf_show_5111e0b(0x320,&s,0,0,ents.at_9b81f0(k),UfHE(),0,0))
														uf_cec058->bubble_8758d0(true);
													uf_cec0b4->scrollToEnd_7b4f10();
												}
												while (false);
											}
											ents.at_9b81f0(k).get_9b6570()->unknown5fd900(8,0);
											ents.at_9b81f0(k).get_9b6570()->unknown639730(0);
										}
									}
								}
								else
								{
									UfBox area = uf_cfd44c.getArea_9b4400();
									for (unsigned k2 = 0; k2 < ents.size_9b9260(); k2++)
									{
										if (rng.chance_406c90(50))
											ents.at_9b81f0(k2).get_9b6570()->changeFaction_5dc780(uf_cefc4c->group_463890(g2),1);
										ents.at_9b81f0(k2).get_9b6570()->ai_45b590()->unknown459470(area);
									}
								}
								UfVVPt *marks = uf_cefc4c->unknown459070m();
								for (int a = 0; a < 9; a++)
								{
									while (!marks->at_9b8070(a).empty_9b86e0())
										CELLAT(marks->at_9b8070(a).back_9e8c10())->getProp_45d550().get_9b64f0()->disableMachine_65ed00();
								}
								if (uf_d25450.b0 && !uf_d1ec68)
									uf_d1ec68 = uf_cefc4c->unknown4642d0() + 100;
								break;
							}
							case 154:
								if ((*uf_cfd44c.at_9ceda0(0x72,0x49))->getProp_45d550().isValid_9b7230())
									(*uf_cfd44c.at_9ceda0(0x72,0x49))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
								if ((*uf_cfd44c.at_9ceda0(0x72,0x4a))->getProp_45d550().isValid_9b7230())
									(*uf_cfd44c.at_9ceda0(0x72,0x4a))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
								if ((*uf_cfd44c.at_9ceda0(0x73,0x4b))->getProp_45d550().isValid_9b7230())
									(*uf_cfd44c.at_9ceda0(0x73,0x4b))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
								if ((*uf_cfd44c.at_9ceda0(0x74,0x4b))->getProp_45d550().isValid_9b7230())
									(*uf_cfd44c.at_9ceda0(0x74,0x4b))->getProp_45d550().get_9b64f0()->unknown45ce10(1,0,1,UfHE());
								uf_cefc4c->unknown6c6b90(UfPoint(0x72,0x49),"COM_Conduit_Interaction",0,-1);
								uf_cefc4c->unknown6c6b90(UfPoint(0x72,0x4a),"COM_Conduit_Interaction",0,-1);
								uf_cefc4c->unknown6c6b90(UfPoint(0x73,0x4b),"COM_Conduit_Interaction",0,-1);
								uf_cefc4c->unknown6c6b90(UfPoint(0x74,0x4b),"COM_Conduit_Interaction",0,-1);
								break;
							case 155:
								uf_d2c658.add_472b90(0x5b,-999999);
								do
								{
									uf_logPhrase_5141b0(0x223,0,0,0,UfHE(),0);
								}
								while (0);
								uf_cec138->start_969b60();
								break;
							case 156:
							{
								UfEntityDef *d = 0;
								string rif;
								if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0ExplorationCount_g")) >= 15 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0SpawnedA6_g")))
								{
									uf_findByName_9d7530(uf_d25de0,"A6",&d);
									rif = "ac0SpawnedA6_g";
								}
								else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0ExplorationCount_g")) >= 30 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0SpawnedA5_g")) && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("labA5Dead_g")))
								{
									uf_findByName_9d7530(uf_d25de0,"A5",&d);
									rif = "ac0SpawnedA5_g";
								}
								else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0ExplorationCount_g")) >= 50 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0SpawnedA4_g")))
								{
									uf_findByName_9d7530(uf_d25de0,"A4",&d);
									rif = "ac0SpawnedA4_g";
								}
								else if (uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0ExplorationCount_g")) >= 75 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0SpawnedA3_g")))
								{
									uf_findByName_9d7530(uf_d25de0,"A3",&d);
									rif = "ac0SpawnedA3_g";
								}
								if (d)
								{
									UfPoint pp(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
									UfRect rj5;
									uf_cfd44c.getRect_9b4430(pp,uf_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5c7d30(),rj5);
									UfPoint pX;
									for (int t = 0; t < 200; t++)
									{
										rj5.randomPoint_40be30(&pX);
										if (uf_cefc4c->isVisible_4631c0(pX) && (*uf_cfd44c.atPoint_9ced70(pX))->isPassableFor_66ab30(UfHE()) && (t >= 100 || pp.distanceTo_409fb0(pX) >= 10) && uf_cefc4c->unknown716940(pX,uf_cefc4c->unknown4184d0(),0,0))
										{
											UfHE e = uf_cefc4c->placeEntity_6c58c0(d,pX,0xc,0,0x22,0xe,0);
											if (e.isValid_9b7230())
											{
												e.get_9b6570()->ai_45b590()->chase_5b4710(uf_cefc4c->getPlayer_4630f0(),1,1,1,0);
												string msgA = e.get_9b6570()->getName_416f40() + " warps into view.";
												uf_message_49c610(0x320,UfHE(),&msgA,0);
												do
												{
													uf_logPhrase_5141b0(0x226,&e.get_9b6570()->getName_416f40(),0,0,e,0);
												}
												while (0);
												int *fx;
												if (uf_lookup2_9d7980("Teleport_hTR",&fx))
													uf_cefc50->new_508610(uf_cefc50)->init_503b20((int)fx,e.get_9b6570()->getPosition_45a4a0(),&uf_d2e20c,0,0,0,9,0);
												uf_d1e860.setEntryText_46f700(rif,"1");
												break;
											}
										}
									}
								}
								break;
							}
							case 157:
							{
								UfVVPt *marks = uf_cefc4c->unknown459070m();
								for (unsigned k = 0; k < marks->at_9b8070(7).size_9b9a50(); k++)
								{
									if (uf_strEq_9ccb50(CELLAT(marks->at_9b8070(7).at_9e7c10(k))->getProp_45d550().get_9b64f0()->location_45c590(),"Gate Controls"))
									{
										CELLAT(marks->at_9b8070(7).at_9e7c10(k))->getProp_45d550().get_9b64f0()->unknown45cb30()->x28 = -1;
										break;
									}
								}
								if (!uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("ac0RanGateTestB_g")))
									uf_cefc4c->unknown749240();
								break;
							}
							case 158:
								uf_cec138->unknown96ada0(0);
								break;
							case 159:
							{
								UfHE e = w3->getEntity_45d250();
								if (e.get_9b6570()->getField_490840() <= 325 || e.get_9b6570()->unknown45a780() || e.get_9b6570()->unknown5cc190(3))
									uf_cefc4c->unknown748a00(0,0);
								break;
							}
							case 160:
								uf_cefc4c->unknown748a00(0,0);
								break;
							case 161:
								if (w3->unknown45d230())
								{
									int *fx;
									if (uf_lookup2_9d7980("AC0_Singularity_Destroy",&fx))
										uf_playEffect_55ca10(*fx,w3->pos_45d1a0(),0);
									w3->unknown45de40();
								}
								break;
							case 162:
							{
								int radius = 6;
								uf_clearDijkstra_4faf40();
								uf_cfe568.unknown40ca20(w3->pos_45d1a0(),0xe,&uf_cfe5e8,0);
								if (uf_d15e58.empty_9b86e0())
									goto end162;
								{
								UfVPt pts6(uf_d15e58);
								UfPoint dest;
								for (unsigned i = 1; i < pts6.size_9b9a50(); i++)
								{
									if (CELLAT(pts6.at_9e7c10(i))->getEntity_45d250().isValid_9b7230() && uf_nextLineStep_40ff60(UfPoint(pts6.at_9e7c10(i)),uf_d1ec6c,&dest))
									{
										bool ok = true;
										if (!CELLAT(dest)->canPlaceEntity_66ad20(CELLAT(pts6.at_9e7c10(i))->getEntity_45d250().get_9b6570()->getSize_45a360()))
										{
											ok = false;
											UfVPt nb;
											if (uf_commonNeighbors_4fac50(pts6.at_9e7c10(i),dest,&nb))
											{
												UfVFloat dd;
												for (unsigned j = 0; j < nb.size_9b9a50(); j++)
												{
													if (CELLAT(nb.at_9e7c10(j))->canPlaceEntity_66ad20(CELLAT(pts6.at_9e7c10(i))->getEntity_45d250().get_9b6570()->getSize_45a360()))
														dd.push_back_9b84b0(uf_distance_40a450(nb.at_9e7c10(j),w3->pos_45d1a0()));
													else
														uf_eraseStep_9d7300(nb,j);
												}
												if (!dd.empty_9b86e0())
												{
													int mi = uf_minIndex_9d7d70(dd);
													if (dd.at_9b81f0(mi) < uf_distance_40a450(pts6.at_9e7c10(i),w3->pos_45d1a0()))
													{
														dest = nb.at_9e7c10(mi);
														ok = true;
													}
												}
											}
										}
										if (ok)
										{
											if (uf_cefc4c->isVisible_4631c0(dest) || uf_cefc4c->isVisible_4631c0(pts6.at_9e7c10(i)))
											{
												if (CELLAT(pts6.at_9e7c10(i))->getEntity_45d250().get_9b6570()->isPlayer_5c7600())
												{
													do
													{
														if (uf_show_5111e0b(0x320,&string("Drawn towards the singularity."),0,0,UfHE(),UfHE(),0,0))
															uf_cec058->bubble_8758d0(true);
														uf_cec0b4->scrollToEnd_7b4f10();
													}
													while (false);
												}
												else
												{
													do
													{
														if (uf_show_5111e0b(0x320,&string("[name] drawn towards the singularity."),0,0,CELLAT(pts6.at_9e7c10(i))->getEntity_45d250(),UfHE(),0,0))
															uf_cec058->bubble_8758d0(true);
														uf_cec0b4->scrollToEnd_7b4f10();
													}
													while (false);
												}
											}
											CELLAT(pts6.at_9e7c10(i))->getEntity_45d250().get_9b6570()->unknown5ddac0(dest,0);
										}
									}
									if (CELLAT(pts6.at_9e7c10(i))->getItem_45d8f0().isValid_9b7230() && uf_nextLineStep_40ff60(UfPoint(pts6.at_9e7c10(i)),uf_d1ec6c,&dest))
									{
										bool ok2 = true;
										if (!CELLAT(dest)->unknown45d990())
										{
											ok2 = false;
											UfVPt nb2;
											if (uf_commonNeighbors_4fac50(pts6.at_9e7c10(i),dest,&nb2))
											{
												UfVFloat dd2;
												for (unsigned j2 = 0; j2 < nb2.size_9b9a50(); j2++)
												{
													if (CELLAT(nb2.at_9e7c10(j2))->unknown45d990())
														dd2.push_back_9b84b0(uf_distance_40a450(nb2.at_9e7c10(j2),w3->pos_45d1a0()));
													else
														uf_eraseStep_9d7300(nb2,j2);
												}
												if (!dd2.empty_9b86e0())
												{
													int mi2 = uf_minIndex_9d7d70(dd2);
													if (dd2.at_9b81f0(mi2) < uf_distance_40a450(pts6.at_9e7c10(i),w3->pos_45d1a0()))
													{
														dest = nb2.at_9e7c10(mi2);
														ok2 = true;
													}
												}
											}
										}
										if (ok2)
											CELLAT(pts6.at_9e7c10(i))->getItem_45d8f0().get_9b65b0()->unknown57a0f0(dest,0,0);
									}
									if (CELLAT(pts6.at_9e7c10(i))->unknown45d230() && uf_nextLineStep_40ff60(UfPoint(pts6.at_9e7c10(i)),uf_d1ec6c,&dest))
									{
										bool ok3 = true;
										if (!CELLAT(dest)->unknown45da50())
										{
											ok3 = false;
											UfVPt nb3;
											if (uf_commonNeighbors_4fac50(pts6.at_9e7c10(i),dest,&nb3))
											{
												UfVFloat dd3;
												for (unsigned j3 = 0; j3 < nb3.size_9b9a50(); j3++)
												{
													if (CELLAT(nb3.at_9e7c10(j3))->unknown45da50())
														dd3.push_back_9b84b0(uf_distance_40a450(nb3.at_9e7c10(j3),w3->pos_45d1a0()));
													else
														uf_eraseStep_9d7300(nb3,j3);
												}
												if (!dd3.empty_9b86e0())
												{
													int mi3 = uf_minIndex_9d7d70(dd3);
													if (dd3.at_9b81f0(mi3) < uf_distance_40a450(pts6.at_9e7c10(i),w3->pos_45d1a0()))
													{
														dest = nb3.at_9e7c10(mi3);
														ok3 = true;
													}
												}
											}
										}
										if (ok3)
											CELLAT(pts6.at_9e7c10(i))->unknown66b740(CELLAT(dest));
									}
								}
								}
							end162:
								break;
							}
							case 163:
							{
								int hits = uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("craigsPointyStickHits"));
								hits++;
								uf_d1e860.setEntryText_46f700("craigsPointyStickHits",uf_intToString_4051f0(hits));
								if (rng.chance_406c90(hits * 7))
								{
									UfItemDef *stick;
									UfItemDef *slayer;
									if (uf_findByName_9d7a40(uf_d2d1c4,"CR-A16's Pointy Stick",&stick) && uf_findByName_9d7a40(uf_d2d1c4,"CR-A16's Behemoth Slayer",&slayer))
									{
										UfVHI *inv = uf_cefc4c->getPlayer_4630f0().get_9b6570()->getInventoryList_45ab00();
										for (unsigned k = 0; k < inv->size_9b9260(); k++)
										{
											if (inv->at_9b81f0(k).get_9b65b0()->def_9b4350() == stick && inv->at_9b81f0(k).get_9b65b0()->getType_44aec0() == 3)
											{
												UfVHE2 aW;
												uf_cec088->unknown8987b0(inv->at_9b81f0(k),&aW);
												inv->at_9b81f0(k).get_9b65b0()->remove_57dbe0(1,0,0,1);
												UfHI ni = uf_cefc4c->unknown6c51d0(slayer,uf_cefc4c->getPlayer_4630f0(),1,0);
												if (ni.isValid_9b7230())
												{
													uf_cf47cc.push_back_9b9280(ni.get_9b65b0()->id_9fcd80());
													uf_d25628.addItemAttachCount_778560(ni.get_9b65b0()->getNestedField_457820(),1,0);
													UfPart *part = uf_cec088->unknown894e70(ni);
													if (part)
														uf_cec088->toggle_8993e0(part,1);
													uf_cec088->unknown89d610(ni,10);
													if (!aW.empty_9b86e0())
														uf_cec088->unknown898860(ni,&aW);
												}
												uf_sound_4541b0(0x114,0,0);
												string msg("CR-A16's Pointy Stick's crusty surface crumbles away to reveal its sleek core, which hums to life.");
												uf_message_49c610(0x320,UfHE(),&msg,&uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
												uf_d2c658.add_472b90(0x1f,-999999);
												do
												{
													uf_logPhrase_5141b0(0x54,0,0,0,UfHE(),0);
												}
												while (0);
												uf_cf45d8.unlock_77fbc0(0x129);
												break;
											}
										}
									}
								}
								break;
							}
							case 164:
								if (entity.get_9b6570()->getTarget_45a760() || !entity.get_9b6570()->isXomCandidate_5d51a0())
								{
									UfHE md = uf_cefc4c->unknown6c5dc0("Master Drone",entity.get_9b6570()->getPosition_45a4a0(),0,0,0x22,0xe,0);
									if (md.isValid_9b7230())
									{
										string name(entity.get_9b6570()->getName_416f40());
										string rob("Mastered ");
										if (name.find(rob,0) == string::npos)
											goto skip164;
										name.erase(name.find(rob,0),rob.size());
										entity.get_9b6570()->unknown45b070(name);
									skip164:
										string msg = md.get_9b6570()->getName_416f40() + " extracts itself from " + entity.get_9b6570()->getName_416f40() + ".";
										uf_message_49c610(0x320,UfHE(),&msg,&entity.get_9b6570()->getPosition_45a4a0());
										uf_opR1d_454260(&entity.get_9b6570()->getPosition_45a4a0(),0xa2);
										entity.get_9b6570()->unknown45b360(0x7b);
										entity.get_9b6570()->removeEffects_45b4c0(defVal,true);
										entity.get_9b6570()->changeFaction_5dc780(uf_cefc4c->group_463890(3),1);
									}
								}
								break;
							case 165:
								if (uf_d1e888.get_9b7910()->type == 0x15 && !uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("datHostileToDataMiner_g")))
									uf_cefc4c->unknown731960();
								break;
							case 166:
							{
								UfRect r;
								uf_cfd44c.getRect_9b4430(item.get_9b65b0()->pos_575920(),5,r);
								for (int x = r.x1; x <= r.x2; x++)
								{
									for (int y = r.y1; y <= r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230())
										{
											UfHE e = (*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250();
											if (e.get_9b6570()->unknown5cc8e0().isValid_9b7230() && !e.get_9b6570()->ai_45b590()->unknown459070())
											{
												e.get_9b6570()->ai_45b590()->unknown459070() = new UfJob(1,uf_cefc4c->getTurn_464270() + 10,UfHE(),UfHI(),item.get_9b65b0()->pos_575920());
												goto done166;
											}
										}
									}
								}
							done166:
								break;
							}
							case 167:
								if (uf_strNe_9ceb30(entity.get_9b6570()->getName_45a280(),"DD-05H"))
									break;
								if (entity.get_9b6570()->ai_45b590()->unknown459070())
									goto end167;
								if (uf_strNe_9ceb30(item.get_9b65b0()->name_457860(),"Warlord Statue"))
									break;
								entity.get_9b6570()->ai_45b590()->unknown459070() = new UfJob(4,-1,UfHE(),item,UfPoint(-1));
							end167:
								break;
							case 168:
							{
								UfHE suf = ENTX;
								if (!suf.get_9b6570())
									goto nextEff;
								UfVHI *inv = suf.get_9b6570()->getInventoryList_45ab00();
								UfVHI cand;
								for (unsigned k = 0; k < inv->size_9b9260(); k++)
								{
									if (inv->at_9b81f0(k).get_9b65b0()->unknown457cf0() && !inv->at_9b81f0(k).get_9b65b0()->unknown457ad0() && inv->at_9b81f0(k).get_9b65b0()->def_9b4350()->x94 != 2 && !inv->at_9b81f0(k).get_9b65b0()->unknown577fb0())
										cand.push_back_9b80b0(inv->at_9b81f0(k));
								}
								if (!cand.empty_9b86e0())
								{
									uf_shuffle_9d9fc0(cand);
									int cnt = 0;
									for (int n = rng.rangeInt_406d70(4,6), to8 = 0; n > 0 && to8 < cand.size_9b9260(); n--, to8++)
									{
										if (cand.at_9b81f0(to8).get_9b65b0()->unknown57a620())
											cnt++;
									}
									if (cnt)
									{
										do
										{
											if (uf_show_5111e0b(0x204,&string("PWNED!M4+R1X_E1337"),0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
									}
								}
								break;
							}
							case 169:
								uf_cec138->unknown965c10(0x14,0,1);
								break;
							case 170:
							{
								int v = item.get_9b65b0()->getEffectValue_457be0(1);
								UfEntityDef *tos = item.get_9b65b0()->def_9b4350()->getRecord_56f3c0();
								UfHE e;
								UfPoint p;
								if (uf_cefc4c->findPlaceableNear_71c150(item.get_9b65b0()->pos_575920(),p,tos->x9c))
									e = uf_cefc4c->placeEntity_6c58c0(tos,p,v,0,0x22,0xe,0);
								if (e.isNull_9b65d0())
									goto end170;
								do
								{
									if (uf_show_5111e0b(e.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()) ? 0x28c : 0x28b,0,0,0,e,UfHE(),0,0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (false);
								do
								{
									uf_logPhrase_5141b0(0x5b,&e.get_9b6570()->getName_416f40(),0,0,e,0);
								}
								while (0);
								uf_opR1d_454260(&e.get_9b6570()->getPosition_45a4a0(),0xc2);
								uf_d2c658.add_4729d0(0x3b3,1,uf_b91cd9,-1);
							end170:
								break;
							}
							case 171:
							{
								int v = item.get_9b65b0()->getEffectValue_457be0(1);
								UfEntityDef *d = item.get_9b65b0()->def_9b4350()->getRecord_56f3c0();
								UfHE u10;
								UfPoint p;
								if (uf_cefc4c->findPlaceableNear_71c150(item.get_9b65b0()->pos_575920(),p,d->x9c))
									u10 = uf_cefc4c->placeEntity_6c58c0(d,p,v,0,0x22,0xe,0);
								if (u10.isNull_9b65d0())
									goto end171;
								u10.get_9b6570()->unknown5fd900(6,0);
								uf_cefc4c->unknown6c65a0(u10,"Botcube_Build",0);
								uf_cefc4c->unknown6c65a0(u10,"Botcube_Collect_Matter",0);
								uf_cefc4c->unknown6c65a0(u10,uf_strEq_9ccb50(item.get_9b65b0()->name_457860(),"Botcube") ? "Botcube_Death" : "Botcube_Death_Large",0);
								do
								{
									if (uf_show_5111e0b(u10.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()) ? 0x290 : 0x28f,&item.get_9b65b0()->getName_571db0(0,0),0,0,u10,UfHE(),0,0))
										uf_cec058->bubble_8758d0(true);
									uf_cec0b4->scrollToEnd_7b4f10();
								}
								while (false);
								do
								{
									uf_logPhrase_5141b0(0x5d,&item.get_9b65b0()->getName_571db0(0,0),0,0,u10,0);
								}
								while (0);
								uf_cf45d8.unlock_77fbc0(0x82);
								uf_opR1d_454260(&u10.get_9b6570()->getPosition_45a4a0(),0xc3);
							end171:
								break;
							}
							case 172:
							{
								UfVHI items2;
								int range = uf_strEq_9ccb50(entity.get_9b6570()->getName_45a280(),"Mutated Botcube") ? 5 : 7;
								UfRect r;
								UfPoint c(entity.get_9b6570()->getPosition_45a4a0());
								uf_cfd44c.getRect_9b4430(c,range / 2,r);
								for (int x = r.x1; x <= r.x2; x++)
								{
									for (int y = r.y1; y <= r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230() && (*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->def_9b4350()->b275 && (c.is_409cb0(x,y) || uf_cefc4c->unknown465200(c,UfPoint(x,y)) && uf_cefc4c->unknown7178d0(UfHE(),UfPoint(x,y),&uf_d2e20c,c,&uf_d2e20c,0)))
											items2.push_back_9b7cf0((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0());
									}
								}
								bool done = false;
								if (!items2.empty_9b86e0())
								{
									UfVecU u20;
									entity.get_9b6570()->unknown5c93d0(&u20);
									UfVecU slots;
									slots.push_back_9b9280(1);
									slots.push_back_9b9280(0);
									slots.push_back_9b9280(2);
									slots.push_back_9b9280(3);
									for (unsigned k = 0; k < slots.size_9b9260(); k++)
									{
										int s = slots.at_9b81f0(k);
										int up7 = 0x1f;
										if (s == 1 && entity.get_9b6570()->unknown5d1440() != 6)
											up7 = entity.get_9b6570()->unknown5d1440() + 9;
										if (u20.at_9b81f0(s))
										{
											UfVHI m;
											for (unsigned j = 0; j < items2.size_9b9260(); j++)
											{
												if (items2.at_9b81f0(j).get_9b65b0()->unknown4578a0() == s && u20.at_9b81f0(s) >= items2.at_9b81f0(j).get_9b65b0()->unknown4578c0() && (up7 == 0x1f || items2.at_9b81f0(j).get_9b65b0()->unknown457880() == up7))
													m.push_back_9b80b0(items2.at_9b81f0(j));
											}
											if (!m.empty_9b86e0())
											{
												uf_shuffle_9d9fc0(m);
												UfHI best = m.at_9b81f0(0);
												for (unsigned j2 = 1; j2 < m.size_9b9260(); j2++)
												{
													if (m.at_9b81f0(j2).get_9b65b0()->unknown457920() > best.get_9b65b0()->unknown457920())
														best = m.at_9b81f0(j2);
												}
												uf_cec054->unknown8195a0(best.get_9b65b0()->pos_575920(),best.get_9b65b0()->unknown457a30(),6);
												best.get_9b65b0()->unknown57a190(entity,s,0,0);
												if (best.get_9b65b0()->unknown457f90() == 0xd4)
												{
													int cnt[4];
													uf_fillInts_9e2be0(cnt,4,0);
													UfVecU upX;
													if (best.get_9b65b0()->def_9b4350()->unknown56fae0(&upX))
													{
														for (unsigned q = 0; q < upX.size_9b9260(); q++)
															cnt[upX.at_9b81f0(q)]++;
													}
													entity.get_9b6570()->unknown45b100(cnt);
												}
												uf_opR1d_454260(&entity.get_9b6570()->getPosition_45a4a0(),0xc4);
												done = true;
												break;
											}
										}
									}
								}
								if (!done)
								{
									UfItemDef *bd;
									if (uf_findByName_9d7a40(uf_d2d1c4,uf_strEq_9ccb50(entity.get_9b6570()->getName_45a280(),"Mutated Botcube") ? "Botcube" : "Lrg. Botcube",&bd))
									{
										if (entity.get_9b6570()->getInventoryList_45ab00()->empty_9b86e0())
										{
											do
											{
												if (uf_show_5111e0b(0x293,&bd->name24,0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											entity.get_9b6570()->unknown637bb0();
											uf_cefc4c->unknown6c5400(bd,c);
										}
										else
										{
											entity.get_9b6570()->removeEffects_45b4c0(defVal,true);
											entity.get_9b6570()->unknown5fdab0();
											int ai = 8;
											bool big = false;
											int n = 0;
											UfVHI *inv = entity.get_9b6570()->getInventoryList_45ab00();
											for (unsigned k = 0; k < inv->size_9b9260(); k++)
											{
												if (inv->at_9b81f0(k).get_9b65b0()->unknown4578a0() == 3)
												{
													if (!inv->at_9b81f0(k).get_9b65b0()->def_9b4350()->v13c.empty_9b86e0() && inv->at_9b81f0(k).get_9b65b0()->def_9b4350()->v13c.at_9b81f0(0) >= 50)
														big = true;
													if ((inv->at_9b81f0(k).get_9b65b0()->unknown457880() == 0x17 || inv->at_9b81f0(k).get_9b65b0()->unknown457880() == 0x15) && inv->at_9b81f0(k).get_9b65b0()->def_9b4350()->x128 != 3)
														n++;
												}
											}
											if (n >= 2)
												ai = 0xc;
											else if (big)
												ai = 0xb;
											entity.get_9b6570()->ai_45b590()->set_44bef0(ai);
											entity.get_9b6570()->ai_45b590()->unknown459470(uf_cfd44c.getArea_9b4400());
											if (entity.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350() == 1)
												entity.get_9b6570()->ai_45b590()->unknown5b5380(new UfJob2(2,UfHE(),UfPoint(-1)));
											do
											{
												if (uf_show_5111e0b(entity.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()) ? 0x292 : 0x291,&bd->name24,0,0,entity,UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											string k0;
											switch (entity.get_9b6570()->unknown5d1440())
											{
												case 0:
													k0 = "treaded form";
													break;
												case 1:
													k0 = "legged form";
													break;
												case 2:
													k0 = "wheeled form";
													break;
												case 3:
													k0 = "hovering form";
													break;
												case 4:
													k0 = "flying form";
													break;
												default:
													k0 = "core form";
											}
											UfVStr2 weapons;
											weapons.push_back_9b06f0("gun");
											weapons.push_back_9b06f0("cannon");
											weapons.push_back_9b06f0("launcher");
											weapons.push_back_9b06f0("melee weapon");
											weapons.push_back_9b06f0("special weapon");
											UfVecU counts(5u,0u);
											for (unsigned w = 0; w < inv->size_9b9260(); w++)
											{
												switch (inv->at_9b81f0(w).get_9b65b0()->unknown457880())
												{
													case 0x14:
													case 0x16:
														counts.at_9b81f0(0)++;
														break;
													case 0x15:
													case 0x17:
														counts.at_9b81f0(1)++;
														break;
													case 0x18:
														counts.at_9b81f0(2)++;
														break;
													case 0x1a:
													case 0x1b:
													case 0x1c:
													case 0x1d:
														counts.at_9b81f0(3)++;
														break;
													case 0x19:
														counts.at_9b81f0(4)++;
												}
											}
											if (uf_anyNonZero_9d7f70(counts))
											{
												k0 += ", armed with ";
												bool sep = false;
												for (unsigned w2 = 0; w2 < counts.size_9b9260(); w2++)
												{
													if (counts.at_9b81f0(w2))
													{
														if (sep)
															k0 += ", ";
														else
															sep = true;
														k0 += uf_countString_407a80(counts.at_9b81f0(w2),weapons.at_9b06a0(w2));
													}
												}
											}
											else
												k0 += " (unarmed)";
											do
											{
												uf_logPhrase_5141b0(0x5e,&bd->name24,&k0,0,entity,0);
											}
											while (0);
											uf_opR1d_454260(&entity.get_9b6570()->getPosition_45a4a0(),0xc5);
											if (uf_cefb5c)
											{
												string vUp("```\n");
												vUp += entity.get_9b6570()->getName_416f40() + ":\n";
												UfVHI parts;
												entity.get_9b6570()->unknown5cb8b0(&parts);
												if (parts.empty_9b86e0())
													vUp += "Failed!\n";
												else
												{
													if (!parts.empty_9b86e0())
													{
														UfVHI sorted;
														sorted.push_back_9b80b0(parts.back_9b6540());
														parts.pop_back_9e8cd0();
														while (!parts.empty_9b86e0())
														{
															if (sorted.back_9b6540().get_9b65b0()->getNestedField_457820() < parts.back_9b6540().get_9b65b0()->getNestedField_457820())
															{
																sorted.push_back_9b80b0(parts.back_9b6540());
																parts.pop_back_9e8cd0();
															}
															else
															{
																for (unsigned q = 0; q < sorted.size_9b9260(); q++)
																{
																	if (parts.back_9b6540().get_9b65b0()->getNestedField_457820() <= sorted.at_9b81f0(q).get_9b65b0()->getNestedField_457820())
																	{
																		uf_insert_9d8fc0(sorted,q,parts.back_9b6540());
																		parts.pop_back_9e8cd0();
																		break;
																	}
																}
															}
														}
														parts = sorted;
													}
													UfVecU dup;
													for (unsigned i2 = 0; i2 < parts.size_9b9260(); i2++)
													{
														dup.push_back_9b9280(1);
														for (unsigned j3 = i2 + 1; j3 < parts.size_9b9260(); j3++)
														{
															if (parts.at_9b81f0(i2).get_9b65b0()->getNestedField_457820() == parts.at_9b81f0(j3).get_9b65b0()->getNestedField_457820())
															{
																dup.at_9b81f0(i2)++;
																uf_eraseStep_9d6440(parts,j3);
															}
														}
													}
													for (unsigned k3 = 0; k3 < parts.size_9b9260(); k3++)
													{
														string line = parts.at_9b81f0(k3).get_9b65b0()->unknown573860(0,0);
														line += " (" + uf_intToString_4051f0(entity.get_9b6570()->unknown5ccb50(parts.at_9b81f0(k3))) + "%)";
														if (dup.at_9b81f0(k3) > 1)
															line += " x" + uf_intToString_4051f0(dup.at_9b81f0(k3));
														vUp += "  " + line + "\n";
													}
												}
												vUp += "```";
												uf_replaceAll_407f00(vUp,"\n","\\n");
												uf_cefb5c->addComment_4f9f50(vUp);
											}
										}
									}
								}
								break;
							}
							case 173:
								if (entity.get_9b6570()->unknown45a940() < 100 && !entity.get_9b6570()->ai_45b590()->unknown459070())
									entity.get_9b6570()->ai_45b590()->unknown459070() = new UfJob(3,uf_cefc4c->getTurn_464270() + 20,UfHE(),UfHI(),UfPoint(-1));
								break;
							case 174:
							{
								UfPoint p(item.get_9b65b0()->pos_575920());
								if (uf_cefc4c->isVisible_4631c0(p))
								{
									string msg = item.get_9b65b0()->getName_571db0(0,0) + " falls apart.";
									uf_message_49c610(0x320,UfHE(),&msg,&p);
								}
								item.get_9b65b0()->remove_57dbe0(1,0,5,1);
								UfItemDef *sub;
								if (uf_findByName_9d7a40(uf_d2d1c4,"XL Autogun Subcomponent",&sub))
								{
									for (int i = 0; i < 4; i++)
										uf_cefc4c->unknown6c5400(sub,p);
								}
								break;
							}
							case 175:
							{
								UfHE ent = item.get_9b65b0()->unknown457b50();
								if (ent.get_9b6570()->isPlayer_5c7600())
								{
									UfHI gun;
									UfVHI *inv = ent.get_9b6570()->getInventoryList_45ab00();
									for (unsigned k = 0; k < inv->size_9b9260(); k++)
									{
										if (uf_strEq_9ccb50(inv->at_9b81f0(k).get_9b65b0()->name_457860(),"Hyp. EM Gauss Rifle") && !inv->at_9b81f0(k).get_9b65b0()->unknown457d10() && !inv->at_9b81f0(k).get_9b65b0()->unknown457db0() && uf_cefc4c->getTurn_464270() >= inv->at_9b81f0(k).get_9b65b0()->unknown44ab90() && (gun.isNull_9b65d0() || inv->at_9b81f0(k).get_9b65b0()->trap_9b6bf0() > gun.get_9b65b0()->trap_9b6bf0()))
											gun = inv->at_9b81f0(k);
									}
									UfItemDef *cs;
									if (gun.isValid_9b7230() && uf_findByName_9d7a40(uf_d2d1c4,"Modified EM Gauss Rifle",&cs))
									{
										string iC = item.get_9b65b0()->getName_571db0(0,0) + " attaches itself to " + gun.get_9b65b0()->getName_571db0(0,0) + ".";
										uf_message_49c610(0x320,UfHE(),&iC,&ent.get_9b6570()->getPosition_45a4a0());
										uf_d2c658.add_472b90(0x20,-999999);
										do
										{
											uf_logPhrase_5141b0(0x55,0,0,0,UfHE(),0);
										}
										while (0);
										item.get_9b65b0()->remove_57dbe0(1,0,1,1);
										bool small = gun.get_9b65b0()->getType_44aec0() <= 3;
										bool act = gun.get_9b65b0()->unknown457cf0();
										int pct = gun.get_9b65b0()->unknown457ca0();
										UfVHE2 links;
										uf_cec088->unknown8987b0(gun,&links);
										gun.get_9b65b0()->remove_57dbe0(1,0,0,1);
										UfHI vv2 = uf_cefc4c->unknown6c51d0(cs,ent,small,0);
										if (vv2.isValid_9b7230())
										{
											if (pct < 100)
												vv2.get_9b65b0()->set_450460(uf_maxInt_9cdb60(1,vv2.get_9b65b0()->unknown457c80() * pct / 100));
											if (vv2.get_9b65b0()->getType_44aec0() <= 3)
											{
												uf_cf47cc.push_back_9b9280(vv2.get_9b65b0()->id_9fcd80());
												uf_d25628.addItemAttachCount_778560(vv2.get_9b65b0()->getNestedField_457820(),1,0);
												UfPart *part = uf_cec088->unknown894e70(vv2);
												if (part)
												{
													if (pct < 100)
														part->drawStatus_4a8e70(0);
													if (act)
														uf_cec088->toggle_8993e0(part,1);
													uf_cec088->unknown89d610(vv2,10);
													if (!links.empty_9b86e0())
														uf_cec088->unknown898860(vv2,&links);
												}
											}
											else if (pct < 100)
											{
												UfInvItem *ii = uf_cec08c->unknown8a1fd0(vv2,0);
												if (ii)
													ii->drawBar_4aa310();
											}
											uf_sound_4541b0(0x113,0,0);
										}
									}
								}
								break;
							}
							case 177:
								if (item.get_9b65b0()->getEffectValue_457be0(0x79) == 3)
									break;
							case 176:
							{
								UfHE dN = item.get_9b65b0()->unknown457b50();
								UfVHI rings;
								UfVHI *inv = dN.get_9b6570()->getInventoryList_45ab00();
								for (unsigned k = 0; k < inv->size_9b9260(); k++)
								{
									if (inv->at_9b81f0(k).get_9b65b0()->def_9b4350() == uf_cefbf0)
										rings.push_back_9b80b0(inv->at_9b81f0(k));
								}
								if (!rings.empty_9b86e0())
								{
									if (bX == 176)
									{
										if (rings.size_9b9260() >= 3)
										{
											UfHI obl;
											for (unsigned k2 = 0; k2 < inv->size_9b9260(); k2++)
											{
												if (uf_strEq_9ccb50(inv->at_9b81f0(k2).get_9b65b0()->name_457860(),"Disassembled Obliterator") && (obl.isNull_9b65d0() || inv->at_9b81f0(k2).get_9b65b0()->trap_9b6bf0() > obl.get_9b65b0()->trap_9b6bf0()))
													obl = inv->at_9b81f0(k2);
											}
											UfItemDef *ww3;
											if (obl.isValid_9b7230() && uf_findByName_9d7a40(uf_d2d1c4,"PL-3XN's Obliterator",&ww3))
											{
												string msg = "Three rings perfectly hook into " + item.get_9b65b0()->getName_571db0(0,0) + ".";
												uf_message_49c610(0x320,UfHE(),&msg,&dN.get_9b6570()->getPosition_45a4a0());
												uf_d2c658.add_472b90(0x21,-999999);
												do
												{
													uf_logPhrase_5141b0(0x10e,0,0,0,UfHE(),0);
												}
												while (0);
												int t = item.get_9b65b0()->trap_9b6bf0();
												item.get_9b65b0()->remove_57dbe0(1,0,1,1);
												UfHI z18 = uf_cefc4c->unknown6c51d0(ww3,dN,0,0);
												if (z18.isValid_9b7230())
												{
													msg = "Assembled " + ww3->name24 + ".";
													uf_message_49c610(0x320,UfHE(),&msg,&dN.get_9b6570()->getPosition_45a4a0());
													uf_cf45d8.unlock_77fbc0(0x14f);
													if (t < z18.get_9b65b0()->trap_9b6bf0())
													{
														z18.get_9b65b0()->set_450460(t);
														UfInvItem *ii = uf_cec08c->unknown8a1fd0(z18,0);
														if (ii)
															ii->drawBar_4aa310();
													}
													uf_sound_4541b0(0xfb,0,0);
													for (int r3 = 0; r3 < 3; r3++)
														rings.at_9b81f0(r3).get_9b65b0()->remove_57dbe0(1,0,1,1);
												}
											}
										}
									}
									else
									{
										int add = uf_minInt_9cdb30(rings.size_9b9260(),3 - item.get_9b65b0()->getEffectValue_457be0(0x79));
										item.get_9b65b0()->getEffect_457b70(0x79)->value += add;
										item.get_9b65b0()->unknown4585c0(0x7a);
										int rings2 = item.get_9b65b0()->getEffect_457b70(0x79)->value;
										if (rings2 == 3)
											item.get_9b65b0()->unknown4585c0(0x5a);
										else
											item.get_9b65b0()->getEffect_457b70(0x5a)->value = 5;
										UfPart *part = uf_cec088->unknown894e70(item);
										if (part)
											part->unknown4a9120();
										string hm = "Hooked additional ring into " + item.get_9b65b0()->getName_571db0(0,0) + ".";
										uf_message_49c610(0x320,UfHE(),&hm,&dN.get_9b6570()->getPosition_45a4a0());
										do
										{
											uf_logPhrase_5141b0(0x10f,0,0,0,UfHE(),0);
										}
										while (0);
										uf_sound_4541b0(0xfc,0,0);
										for (int r4 = 0; r4 < add; r4++)
											rings.at_9b81f0(r4).get_9b65b0()->remove_57dbe0(1,0,1,1);
									}
								}
								break;
							}
							case 178:
							case 179:
							case 180:
							{
								UfHE ent = item.get_9b65b0()->unknown457b50();
								if (ent.get_9b6570() && ent.get_9b6570()->isPlayer_5c7600())
								{
									if (bX == 178)
									{
										if (item.get_9b65b0()->getType_44aec0() == 2 && item.get_9b65b0()->unknown457cf0())
										{
											if (uf_cf4a70.x0 == -1)
											{
												uf_cf4a70.x0 = uf_d386b8.randomInRange_40c130();
												uf_cf4a70.x4 = uf_d30550.randomInRange_40c130();
												uf_cf4a70.b8 = false;
												uf_cf4a70.xc = uf_cefc4c->getTurn_464270() + uf_d35b7c.randomInRange_40c130();
												uf_cf4a70.v10.clear_9b3560();
												uf_cf4a70.x20 = 360;
												uf_cf4a70.x24 = 0;
											}
											if (uf_cefc4c->getPlayer_4630f0().get_9b6570()->get_45a6e0() > 0)
											{
												uf_cf4a70.x0--;
												if (!uf_cf4a70.b8 && uf_cf4a70.x0 <= uf_cf4a70.x4)
												{
													uf_cec054->unknown49adc0(500);
													uf_cf4a70.b8 = true;
													uf_sound_4541b0(0x109,0,0);
												}
											}
											if (uf_cefc4c->getTurn_464270() >= uf_cf4a70.xc)
											{
												uf_cf4a70.v10.push_back_9b32e0(ent.get_9b6570()->getPosition_45a4a0());
												switch (uf_cf4a70.v10.size_9b9a50())
												{
													case 1:
														break;
													case 2:
														if (uf_cf4a70.v10.at_9e7c10(0).test_409b90(uf_cf4a70.v10.at_9e7c10(1)))
														{
															uf_cf4a70.x20 = 360;
															uf_cf4a70.x24 = 0;
															uf_cf4a70.v10.pop_back_9b33e0();
														}
														else
														{
															uf_cf4a70.x20 = 0x13b;
															uf_cf4a70.x24 = (int)uf_angleBetween_40a680(uf_cf4a70.v10.at_9e7c10(uf_cf4a70.v10.size_9b9a50() - 2),uf_cf4a70.v10.back_9e8c10());
														}
														break;
													default:
														if (uf_cf4a70.v10.back_9e8c10().test_409b90(uf_cf4a70.v10.at_9e7c10(uf_cf4a70.v10.size_9b9a50() - 2)))
														{
															uf_fn9d06d0(&uf_cf4a70.x20,0x2d,0x168);
															uf_cf4a70.v10.pop_back_9b33e0();
														}
														else
														{
															int ang = (int)uf_angleBetween_40a680(uf_cf4a70.v10.at_9e7c10(uf_cf4a70.v10.size_9b9a50() - 2),uf_cf4a70.v10.back_9e8c10());
															bool z26 = uf_angleInArc_4065d0(uf_cf4a70.x24,uf_cf4a70.x20,ang);
															if (z26)
															{
																if (uf_cf4a70.x20 > 0x2d)
																	uf_cf4a70.x20 -= 0x2d;
																uf_cf4a70.x24 = ang;
															}
															else
															{
																if (uf_cf4a70.x20 < 360)
																	uf_cf4a70.x20 += 0x2d;
																bool cw;
																if (abs(ang - uf_cf4a70.x24) == 180)
																	cw = rng.chance_406c90(50);
																else if (ang - uf_cf4a70.x24 > 0)
																	cw = ang - uf_cf4a70.x24 < 180;
																else
																	cw = abs(ang - uf_cf4a70.x24) > 180;
																if (cw)
																{
																	uf_cf4a70.x24 += 0x2d;
																	if (uf_cf4a70.x24 > 360)
																		uf_cf4a70.x24 -= 360;
																}
																else if ((uf_cf4a70.x24 -= 0x2d) < 0)
																	uf_cf4a70.x24 += 360;
															}
														}
												}
												uf_cf4a70.xc = uf_cefc4c->getTurn_464270() + uf_cf39cc.randomInRange_40c130();
											}
											if (uf_cf4a70.x0 == 0)
											{
												if (ent.get_9b6570()->teleport_63b5a0(item.get_9b65b0()->unknown457fb0(),item.get_9b65b0()->unknown457fd0()))
													uf_cf45d8.unknown46df70();
											}
										}
									}
									else if (bX == 179)
									{
										UfHI lc;
										UfHI eX;
										UfVHI *inv = ent.get_9b6570()->getInventoryList_45ab00();
										for (unsigned k = 0; k < inv->size_9b9260(); k++)
										{
											if (uf_strEq_9ccb50(inv->at_9b81f0(k).get_9b65b0()->name_457860(),"L-Cannon") && !inv->at_9b81f0(k).get_9b65b0()->unknown457d10() && uf_cefc4c->getTurn_464270() >= inv->at_9b81f0(k).get_9b65b0()->unknown44ab90())
												lc = inv->at_9b81f0(k);
											if (uf_strEq_9ccb50(inv->at_9b81f0(k).get_9b65b0()->name_457860(),"Drained L-Cannon") && !inv->at_9b81f0(k).get_9b65b0()->unknown457d10() && uf_cefc4c->getTurn_464270() >= inv->at_9b81f0(k).get_9b65b0()->unknown44ab90())
												eX = inv->at_9b81f0(k);
										}
										if (lc.isValid_9b7230())
										{
											UfFx *fx = lc.get_9b65b0()->getEffect_457b70(0x47);
											if (!fx)
												uf_logError_404f10("checkTriggers()","LC missing ammoRemainingTrait");
											else
											{
												fx->value += lc.get_9b65b0()->def_9b4350()->getValue_457330(0x47);
												if (lc.get_9b65b0()->getType_44aec0() > 3)
													uf_cec08c->unknown8a54c0(lc,0);
												string msg = item.get_9b65b0()->getName_571db0(0,0) + " charges " + lc.get_9b65b0()->getName_571db0(0,0) + ".";
												uf_message_49c610(0x320,UfHE(),&msg,&ent.get_9b6570()->getPosition_45a4a0());
												do
												{
													uf_logPhrase_5141b0(0x58,0,0,0,UfHE(),0);
												}
												while (0);
												item.get_9b65b0()->remove_57dbe0(1,0,1,1);
											}
											break;
										}
										else if (eX.isValid_9b7230())
										{
											UfItemDef *lcd;
											if (uf_findByName_9d7a40(uf_d2d1c4,"L-Cannon",&lcd))
											{
												string jB = item.get_9b65b0()->getName_571db0(0,0) + " attaches itself to " + eX.get_9b65b0()->getName_571db0(0,0) + ".";
												uf_message_49c610(0x320,UfHE(),&jB,&ent.get_9b6570()->getPosition_45a4a0());
												uf_d2c658.add_472b90(0x22,-999999);
												do
												{
													uf_logPhrase_5141b0(0x57,0,0,0,UfHE(),0);
												}
												while (0);
												if (uf_cefb48)
													uf_cefb48->say_49e250(0x72,0,uf_b91cda);
												item.get_9b65b0()->remove_57dbe0(1,0,0,1);
												bool small = eX.get_9b65b0()->getType_44aec0() <= 3;
												bool act = eX.get_9b65b0()->unknown457cf0();
												int ammo = eX.get_9b65b0()->trap_9b6bf0();
												UfVHE2 links;
												uf_cec088->unknown8987b0(eX,&links);
												eX.get_9b65b0()->remove_57dbe0(1,0,0,1);
												lc = uf_cefc4c->unknown6c51d0(lcd,ent,small,0);
												if (lc.isValid_9b7230())
												{
													bool changed = false;
													if (ammo != lc.get_9b65b0()->trap_9b6bf0())
													{
														lc.get_9b65b0()->set_450460(ammo);
														changed = true;
													}
													if (lc.get_9b65b0()->getType_44aec0() <= 3)
													{
														uf_cf47cc.push_back_9b9280(lc.get_9b65b0()->id_9fcd80());
														uf_d25628.addItemAttachCount_778560(lc.get_9b65b0()->getNestedField_457820(),1,0);
														UfPart *part = uf_cec088->unknown894e70(lc);
														if (part)
														{
															if (changed)
																part->drawStatus_4a8e70(0);
															if (act)
																uf_cec088->toggle_8993e0(part,1);
															uf_cec088->unknown89d610(lc,10);
															if (!links.empty_9b86e0())
																uf_cec088->unknown898860(lc,&links);
														}
													}
													if (changed)
													{
														UfInvItem *ii = uf_cec08c->unknown8a1fd0(lc,0);
														if (ii)
															ii->drawBar_4aa310();
													}
													uf_sound_4541b0(0x111,0,0);
												}
												break;
											}
										}
									}
								}
								bool hit3 = false;
								switch (bX)
								{
									case 178:
										if (item.get_9b65b0()->getType_44aec0() == 2 && !item.get_9b65b0()->unknown457cf0())
											hit3 = true;
										break;
									case 179:
										if (!item.get_9b65b0()->unknown457cf0())
											hit3 = true;
										break;
									case 180:
										if (item.get_9b65b0()->getType_44aec0() != 2)
											hit3 = true;
								}
								if (hit3)
								{
									if (item.get_9b65b0()->trap_9b6bf0() > 1)
										item.get_9b65b0()->unknown458310(1);
									if (item.get_9b65b0()->trap_9b6bf0() == 1)
									{
										if (ent.get_9b6570() && ent.get_9b6570()->isPlayer_5c7600() || item.get_9b65b0()->getType_44aec0() == 5 && uf_cefc4c->isVisible_4631c0(item.get_9b65b0()->pos_575920()))
										{
											string msg = item.get_9b65b0()->getName_571db0(0,0);
											if (eff->type == 178)
												msg += " twisted beyond recognition.";
											else
												msg += " containment failure.";
											uf_message_49c610(0x320,UfHE(),&msg,&item.get_9b65b0()->pos_575920());
										}
										item.get_9b65b0()->setBroken_5795b0(-2,1);
										item.get_9b65b0()->unknown458690(defVal,1);
										if (!item.get_9b65b0()->unknown44a7d0() || !item.get_9b65b0()->unknown44a7d0()->hasTypeFlagB_4565a0())
											uf_cefc4c->unknown465030(item);
									}
									else if (uf_cefc4c->getTurn_464270() % 10 == 0)
									{
										if (ent.get_9b6570() && ent.get_9b6570()->isPlayer_5c7600() || item.get_9b65b0()->getType_44aec0() == 5 && uf_cefc4c->isVisible_4631c0(item.get_9b65b0()->pos_575920()))
										{
											string msg = item.get_9b65b0()->getName_571db0(0,0) + " integrity failing.";
											uf_message_49c610(0x320,UfHE(),&msg,&item.get_9b65b0()->pos_575920());
										}
									}
									if (ent.get_9b6570() && ent.get_9b6570()->isPlayer_5c7600())
									{
										UfPart *part = uf_cec088->unknown894e70(item);
										if (part)
											part->drawStatus_4a8e70(1);
										else
										{
											UfInvItem *ii = uf_cec08c->unknown8a1fd0(item,0);
											if (ii)
												ii->drawBar_4aa310();
										}
									}
								}
								break;
							}
							case 181:
							{
								UfItemDef *dl;
								if (item.get_9b65b0()->getEffectValue_457be0(0x47) == -1)
								if (uf_findByName_9d7a40(uf_d2d1c4,"Drained L-Cannon",&dl))
								{
									if (item.get_9b65b0()->unknown457b50().get_9b6570() && item.get_9b65b0()->unknown457b50().get_9b6570()->isPlayer_5c7600())
									{
										string msg = item.get_9b65b0()->getName_571db0(0,0) + " capacitor depleted.";
										uf_message_49c610(0x320,UfHE(),&msg,&item.get_9b65b0()->pos_575920());
										if (uf_cefc4c->isVisible_4631c0(item.get_9b65b0()->pos_575920()))
										{
											do
											{
												uf_logPhrase_5141b0(0x59,0,0,0,UfHE(),0);
											}
											while (0);
										}
									}
									UfHE z37 = item.get_9b65b0()->unknown457b50();
									UfPoint p(item.get_9b65b0()->pos_575920());
									bool small = item.get_9b65b0()->getType_44aec0() <= 3;
									bool act = item.get_9b65b0()->unknown457cf0();
									int ammo = item.get_9b65b0()->trap_9b6bf0();
									item.get_9b65b0()->remove_57dbe0(1,0,0,1);
									UfHI dA;
									if (!z37.get_9b6570())
										dA = uf_cefc4c->unknown6c5400(dl,p);
									else
										dA = uf_cefc4c->unknown6c51d0(dl,z37,small,0);
									if (dA.isValid_9b7230())
									{
										bool changed = false;
										if (ammo != dA.get_9b65b0()->trap_9b6bf0())
										{
											dA.get_9b65b0()->set_450460(ammo);
											changed = true;
										}
										if (dA.get_9b65b0()->getType_44aec0() <= 3)
										{
											uf_cf47cc.push_back_9b9280(dA.get_9b65b0()->id_9fcd80());
											uf_d25628.addItemAttachCount_778560(dA.get_9b65b0()->getNestedField_457820(),1,0);
											UfPart *part = uf_cec088->unknown894e70(dA);
											if (part)
											{
												if (changed)
													part->drawStatus_4a8e70(0);
												if (act)
													uf_cec088->toggle_8993e0(part,1);
											}
										}
										if (changed)
										{
											UfInvItem *ii = uf_cec08c->unknown8a1fd0(dA,0);
											if (ii)
												ii->drawBar_4aa310();
										}
										uf_sound_4541b0(0x112,0,0);
									}
								}
								break;
							}
							case 182:
								entity.get_9b6570()->setField_4514e0(-999);
								entity.get_9b6570()->unknown45b360(0x32);
								entity.get_9b6570()->die_633790(0,8,uf_cefc4c->getPlayer_4630f0(),1,0,0,0,0);
								break;
							case 183:
							{
								UfItemDef *sd = 0;
								UfVHI *aInv = entity.get_9b6570()->getInventoryList_45ab00();
								for (unsigned k = 0; k < aInv->size_9b9260(); k++)
								{
									if (uf_strEq_9ccb50(aInv->at_9b81f0(k).get_9b65b0()->unknown457990(),"Sapper Charge"))
									{
										sd = aInv->at_9b81f0(k).get_9b65b0()->def_9b4350();
										break;
									}
								}
								if (sd)
								{
									UfPoint pTmp(entity.get_9b6570()->getPosition_45a4a0());
									UfBlast z43;
									z43.init_455880(sd->x1a0,sd->x1a0->x30,&pTmp,&pTmp,&pTmp);
									UfRect r;
									uf_cfd44c.getRect_9b4430(pTmp,sd->x1a0->x3c,r);
									int friendly = 0;
									int c1 = 0;
									for (int x = r.x1; x <= r.x2; x++)
									{
										for (int y = r.y1; y <= r.y2; y++)
										{
											if ((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250().isValid_9b7230() && z43.a20.at_9cfe20(x,y) && pTmp.ne_409cf0(x,y))
											{
												if (entity.get_9b6570()->isHostileTo_45aa70((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250()))
													c1 += z43.a20.at_9cfe20(x,y);
												else if (entity.get_9b6570()->unknown45aaa0((*uf_cfd44c.at_9ceda0(x,y))->getEntity_45d250()))
													friendly += z43.a20.at_9cfe20(x,y);
											}
										}
									}
									if (c1 > friendly)
									{
										if (uf_cefc4c->isVisible_4631c0(pTmp))
										{
											string msg = entity.get_9b6570()->getName_416f40() + " self-destructs.";
											uf_message_49c610(0x320,UfHE(),&msg,&pTmp);
										}
										uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),sd->x1a0,pTmp,UfHE(),UfPoint(-1),UfPoint(-1))));
									}
								}
								break;
							}
							case 184:
							{
								UfHI zz5;
								UfVHI *inv = entity.get_9b6570()->getInventoryList_45ab00();
								for (unsigned k = 0; k < inv->size_9b9260(); k++)
								{
									if (uf_strEq_9ccb50(inv->at_9b81f0(k).get_9b65b0()->unknown457990(),"Sapper Charge"))
									{
										zz5 = inv->at_9b81f0(k);
										break;
									}
								}
								if (zz5.isValid_9b7230() && CELLAT(entity.get_9b6570()->getPosition_45a4a0())->hasBlockingObject_45d7b0())
								{
									zz5.get_9b65b0()->unknown57a0f0(entity.get_9b6570()->getPosition_45a4a0(),1,0);
									if (zz5.get_9b65b0())
										uf_cefc4c->unknown728fa0(zz5);
								}
								break;
							}
							case 185:
								if (!prop.get_9b64f0()->unknown457b10())
								{
									UfMach *m = prop.get_9b64f0()->unknown45cb30();
									if (m->x28 == 0)
									{
										UfEntityDef *el;
										if (uf_findByName_9d7530(uf_d25de0,"Elite_4",&el))
										{
											UfHE leader;
											UfPoint dest(uf_cefc4c->unknown7141a0());
											for (int i = 0; i < 3; i++)
											{
												UfHE e = uf_cefc4c->placeEntity_6c58c0(el,prop.get_9b64f0()->pos_4184d0(),10,0,0x19,0xe,0);
												if (e.isValid_9b7230())
												{
													e.get_9b6570()->ai_45b590()->unknown459540(dest);
													e.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(0x22),1));
													if (leader.isValid_9b7230())
														e.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(leader,0);
													else
													{
														leader = e;
														uf_cefc4c->unknown6c65a0(e,"FAC_Elite_Fedlink_Talk",0);
														uf_cf6428.unknown684250(prop.get_9b64f0()->pos_4184d0(),0);
														m->x28 = -1;
													}
												}
											}
										}
									}
									break;
								}
							case 186:
							{
								UfVHI *items = uf_cefc4c->getItems_4655e0();
								UfVPt *poss = uf_cefc4c->getItemPositions_465600();
								uf_cf6570.push_back_9e8d90(UfVecU());
								uf_cf6580.push_back_9b5610(UfVPt());
								UfRect r;
								uf_cfd44c.getRect_9b4430(w3->pos_45d1a0(),6,r);
								for (int x = r.x1; x <= r.x2; x++)
								{
									for (int y = r.y1; y <= r.y2; y++)
									{
										if ((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().isValid_9b7230())
										{
											uf_cf6570.back_9b5ac0().push_back_9b9280((*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->getNestedField_457820());
											uf_cf6580.back_9b5ac0().push_back_9b3020(UfPoint(x,y));
											int idx = uf_indexOfEntity_9d3110(*items,(*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0());
											if (idx == -1)
												uf_logError_404f10("checkTriggers()","GAR item not registered");
											else
											{
												uf_eraseAt_9da940(*items,idx);
												uf_eraseAt_9d5190(*poss,idx);
											}
											(*uf_cfd44c.at_9ceda0(x,y))->getItem_45d8f0().get_9b65b0()->remove_57dbe0(0,0,1,1);
										}
									}
								}
								if (uf_cf6570.back_9b5ac0().empty_9b86e0())
								{
									uf_logError_404f10("checkTriggers()","no GAR_OOD items found");
									uf_cf6570.pop_back_9b7610();
									uf_cf6580.pop_back_9b5880();
								}
								break;
							}
							case 187:
							{
								UfVPt aAdj;
								uf_getAdjacentCells_4fab80(w3->pos_45d1a0(),&aAdj);
								UfHP relay;
								for (unsigned k = 0; k < aAdj.size_9b9a50(); k++)
								{
									if (CELLAT(aAdj.at_9e7c10(k))->getProp_45d550().isValid_9b7230() && !CELLAT(aAdj.at_9e7c10(k))->getProp_45d550().get_9b64f0()->unknown457b10() && uf_strEq_9ccb50(CELLAT(aAdj.at_9e7c10(k))->getProp_45d550().get_9b64f0()->location_45c590(),"GAR_Relay"))
									{
										relay = CELLAT(aAdj.at_9e7c10(k))->getProp_45d550();
										break;
									}
								}
								if (relay.isNull_9b65d0())
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								else
								{
									UfEntityDef *d = uf_cefc4c->unknown6c5600(1,0x19,1,0);
									UfPoint p(uf_cefc4c->zones_462e10()->at_9b81f0(rng.rangeInt_406d70(0,uf_minInt_9cdb30(2,uf_cefc4c->zones_462e10()->size_9b9260()) - 1))->pt);
									UfHE aPct = uf_cefc4c->placeEntity_6c58c0(d,p,3,0,2,0xe,0);
									if (aPct.isValid_9b7230())
									{
										UfVPt route;
										route.push_back_9b32e0(aPct.get_9b6570()->getPosition_45a4a0());
										route.push_back_9b32e0(w3->pos_45d1a0());
										aPct.get_9b6570()->ai_45b590()->unknown4593d0(route);
										int cols = uf_d2f130.randomInRange_40c130();
										if (uf_cf462c == 5)
											cols = cols * uf_ba780c;
										for (int i = 0; i < cols; i++)
										{
											UfItemDef *t = uf_d2ae08.pick_9ba470();
											UfHI aY = uf_cefc4c->unknown6c51d0(t,aPct,0,0);
											if (aY.isValid_9b7230())
												aY.get_9b65b0()->set_44fc60(uf_d1e860.unknown789250(aY.get_9b65b0()->def_9b4350()->x64 * uf_ba65d8[uf_cf4718]));
										}
										w3->getProp_45d550().get_9b64f0()->unknown665be0(0);
										w3->getProp_45d550().get_9b64f0()->unknown665b90("GAR_Relay_Tweak_Done",0);
									}
								}
								break;
							}
							case 188:
							{
								UfHE e = w3->getEntity_45d250();
								if (e.isValid_9b7230())
								{
									e.get_9b6570()->setAI_64ecf0(new UfEntityAI(e,0x19,0xe));
									e.get_9b6570()->ai_45b590()->unknown459540(uf_randomRec_9d5d00(*uf_cefc4c->zones_462e10())->pt);
									e.get_9b6570()->unknown6396f0("GAR_Relay_Tweak_Swap_AI",1);
								}
								break;
							}
							case 189:
							{
								UfPoint p(w3->pos_45d1a0());
								w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								if (uf_d1e88c.at_9b81f0(uf_d1e88c.size_9b9260() - 2).get_9b7910()->inRange_46ecb0())
								{
									UfHL prev = uf_d1e88c.at_9b81f0(uf_d1e88c.size_9b9260() - 2);
									UfVZone *zs = uf_cefc4c->zones_462e10();
									UfZone *far3;
									if (zs->at_9b81f0(0)->loc.get_9b7910()->depth == prev.get_9b7910()->depth)
										far3 = new UfZone(p,zs->at_9b81f0(0)->loc,1,UfHE(),UfHE());
									else
									{
										UfHL nl = uf_cefaa8->createB_793120();
										nl.get_9b7910()->init_46eb70(prev.get_9b7910()->type,prev.get_9b7910()->depth,8,0);
										nl.get_9b7910()->v0c = prev.get_9b7910()->v0c;
										nl.get_9b7910()->b2f = true;
										far3 = new UfZone(p,nl,1,UfHE(),UfHE());
									}
									far3->kind = 0;
									zs->push_back_9b9d30(far3);
									int far7 = uf_indexOfName4_9d7b80(uf_cfb844,"STAIRS_GAR");
									CELLAT(far3->pt)->unknown66a050(far7,2,0);
								}
								break;
							}
							case 190:
							{
								UfVPt farC;
								uf_getAdjacentCells_4fab80(w3->pos_45d1a0(),&farC);
								UfHP as;
								for (unsigned k = 0; k < farC.size_9b9a50(); k++)
								{
									if (CELLAT(farC.at_9e7c10(k))->getProp_45d550().isValid_9b7230() && !CELLAT(farC.at_9e7c10(k))->getProp_45d550().get_9b64f0()->unknown457b10() && uf_strEq_9ccb50(CELLAT(farC.at_9e7c10(k))->getProp_45d550().get_9b64f0()->location_45c590(),"GAR_Heavy_Assembler"))
									{
										as = CELLAT(farC.at_9e7c10(k))->getProp_45d550();
										break;
									}
								}
								if (as.isNull_9b65d0())
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								else
								{
									UfEntityDef *d = uf_cefc4c->unknown6c5600(1,0x1a,0,1);
									if (d)
									{
										UfPoint p;
										if (uf_cefc4c->findPlaceableNear_71c150(w3->pos_45d1a0(),p,d->x9c))
										{
											UfHE e = uf_cefc4c->placeEntity_6c58c0(d,p,3,0,0x19,0xe,0);
											if (e.isValid_9b7230())
											{
												UfZone *z2 = uf_cefc4c->zones_462e10()->at_9b81f0(rng.rangeInt_406d70(0,uf_minInt_9cdb30(2,uf_cefc4c->zones_462e10()->size_9b9260()) - 1));
												e.get_9b6570()->ai_45b590()->unknown459540(z2->pt);
												UfHI part = e.get_9b6570()->unknown5d2380(0xd);
												if (part.isValid_9b7230())
													part.get_9b65b0()->setBroken_5795b0(-2,0);
												uf_opR1d_454260(&p,0x86);
												string msg;
												if (uf_cefc4c->isVisible_4631c0(p))
												{
													msg = as.get_9b64f0()->getName_45c5b0() + " finishes assembling " + e.get_9b6570()->getName_416f40() + ".";
													uf_message_49c610(0x320,UfHE(),&msg,0);
												}
												const string *far_ = &uf_cfaca0[z2->loc.get_9b7910()->type];
												msg = "ALERT: Dispatching Heavy support to " + *far_ + ".";
												UF_ALERTP(&msg)
												do
												{
													uf_logPhrase_5141b0(0x197,far_,0,0,UfHE(),0);
												}
												while (0);
											}
										}
									}
								}
								break;
							}
							case 191:
								if (!uf_cf65a8.turn)
								{
									UfVPt fars;
									uf_getAdjacentCells_4fab80(w3->pos_45d1a0(),&fars);
									UfHP as;
									for (unsigned k = 0; k < fars.size_9b9a50(); k++)
									{
										if (CELLAT(fars.at_9e7c10(k))->getProp_45d550().isValid_9b7230() && !CELLAT(fars.at_9e7c10(k))->getProp_45d550().get_9b64f0()->unknown457b10() && uf_strEq_9ccb50(CELLAT(fars.at_9e7c10(k))->getProp_45d550().get_9b64f0()->location_45c590(),"GAR_QS_Assembler"))
										{
											as = CELLAT(fars.at_9e7c10(k))->getProp_45d550();
											break;
										}
									}
									if (as.isNull_9b65d0())
										w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
									else
									{
										uf_cf65a8.turn = uf_cefc4c->getTurn_464270() + rng.rangeInt_406d70(100,150);
										uf_cf65a8.p = w3->pos_45d1a0();
										const string *gTmp = &uf_cfaca0[uf_cefc4c->zones_462e10()->at_9b81f0(0)->loc.get_9b7910()->type];
										string msg = "ALERT: Unique threat detected in " + *gTmp + ", assembling Q-Series response.";
										UF_ALERTP(&msg)
										do
										{
											uf_logPhrase_5141b0(0x198,gTmp,0,0,UfHE(),0);
										}
										while (0);
									}
								}
								break;
							case 192:
							{
								UfVHE2 squad;
								UfVPt around;
								uf_surrounding_4faaf0(w3->pos_45d1a0(),&around);
								for (unsigned k = 0; k < around.size_9b9a50(); k++)
								{
									if (CELLAT(around.at_9e7c10(k))->getEntity_45d250().isValid_9b7230() && CELLAT(around.at_9e7c10(k))->getEntity_45d250().get_9b6570()->getTarget_45a760() == 2)
										squad.push_back_9b7cf0(CELLAT(around.at_9e7c10(k))->getEntity_45d250());
								}
								if (!squad.empty_9b86e0())
								{
									UfZone *z = uf_cefc4c->zones_462e10()->at_9b81f0(rng.rangeInt_406d70(0,uf_minInt_9cdb30(2,uf_cefc4c->zones_462e10()->size_9b9260()) - 1));
									for (unsigned k2 = 0; k2 < squad.size_9b9260(); k2++)
									{
										squad.at_9b81f0(k2).get_9b6570()->unknown5fdab0();
										squad.at_9b81f0(k2).get_9b6570()->setAI_64ecf0(new UfEntityAI(squad.at_9b81f0(k2),0x19,0xe));
										squad.at_9b81f0(k2).get_9b6570()->ai_45b590()->unknown459540(z->pt);
									}
									string msg = "ALERT: Dispatching investigation squad to " + uf_cfaca0[z->loc.get_9b7910()->type] + ".";
									UF_ALERTP(&msg)
								}
								w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								break;
							}
							case 193:
							{
								UfHE gain = records->at_9b81f0(i)->e;
								UfVMsg *msgs = uf_cefc4c->unknown464570();
								for (unsigned k = 0; k < msgs->size_9b9260(); k++)
								{
									if (msgs->at_9b81f0(k)->e.eq_9b78e0(gain))
									{
										do
										{
											if (uf_show_5111e0b(msgs->at_9b81f0(k)->x4,&msgs->at_9b81f0(k)->s8,0,0,gain,UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										uf_deleteObjectAndStep_9d7fb0(*msgs,k);
									}
								}
								break;
							}
							case 194:
							{
								UfPoint p(uf_randomRec_9d5d00(*uf_cefc4c->zones_462e10())->pt);
								UfHE fr = uf_cefc4c->unknown6c5dc0("A-27 Freighter",p,3,0,0x14,0xe,0);
								if (fr.isValid_9b7230())
								{
									int hVal = uf_d1e860.unknown46f4e0() + 1;
									UfPoint hC(hVal,hVal + 2);
									if (hC.y > 9)
										hC.shift_40bf50(9 - hC.y);
									uf_cf6428.unknown6901e0(fr,1,uf_d30348.randomInRange_40c130(),uf_d21760.randomInRange_40c130(),hC,1,0x2a);
									if (uf_b939c0[uf_d1e860.unknown46f4e0()].a && rng.chance_406c90(uf_b939c0[uf_d1e860.unknown46f4e0()].a))
									{
										UfVStr2 specials;
										specials.push_back_9b06f0("Active Cooling Armor");
										specials.push_back_9b06f0("Exp. Thermic Cannon");
										int hit7 = 1;
										UfVIDefP picks;
										int hitC = fr.get_9b6570()->unknown5c8e20(0);
										int cap = fr.get_9b6570()->unknown5ca210();
										UfVHI c9;
										fr.get_9b6570()->unknown5cb830(&c9);
										UfItemDef *gi;
										for (int t = 0; t < 1; t++)
										{
											if (uf_findByName_9d7a40(uf_d2d1c4,uf_randomString_9d3280(specials),&gi))
											{
												picks.push_back_9b9d30(gi);
												hitC += gi->x4c;
												while (hitC > cap)
												{
													if (c9.empty_9b86e0())
													{
														uf_logError_404f10("GAR_Cargo_Convoy","Unable to make room for special items");
														goto done194;
													}
													UfHI rem = uf_popRandom_9d8030(c9);
													hitC -= rem.get_9b65b0()->unknown4578c0();
													rem.get_9b65b0()->remove_57dbe0(0,0,1,1);
												}
											}
										}
										for (unsigned k = 0; k < picks.size_9b9260(); k++)
											uf_cefc4c->unknown6c51d0(picks.at_9b81f0(k),fr,0,0);
									done194:
										;
									}
									if (uf_b939c0[uf_d1e860.unknown46f4e0()].b && rng.chance_406c90(uf_b939c0[uf_d1e860.unknown46f4e0()].b))
									{
										int n = fr.get_9b6570()->unknown45a810();
										while (n)
										{
											uf_cefc4c->unknown6c51d0(uf_d31700.pick_9ba470(),fr,0,0);
											n--;
										}
									}
									UfHE esc;
									UfEntityDef *ed = uf_cefc08;
									for (int n2 = uf_ba6608[uf_cf4718]; n2 > 0; n2--)
									{
										esc = uf_cefc4c->placeEntity_6c58c0(ed,fr.get_9b6570()->getPosition_45a4a0(),3,0,0x22,0xe,0);
										if (esc.isValid_9b7230())
										{
											esc.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(fr,0);
											esc.get_9b6570()->ai_45b590()->setField_4505b0(4);
										}
										else
											uf_logWarning_404e50("GAR_Cargo_Convoy","Carrier spawn failed");
									}
									ed = uf_cefc4c->unknown6c5600(1,0x13,0,1);
									if (ed)
									{
										esc = uf_cefc4c->placeEntity_6c58c0(ed,fr.get_9b6570()->getPosition_45a4a0(),3,0,0x22,0xe,0);
										if (esc.isValid_9b7230())
											esc.get_9b6570()->ai_45b590()->setFollowEntity_5b2f80(fr,0);
									}
								}
								break;
							}
							case 195:
								uf_cf6428.spawnWarlordRaid_68e1f0(0);
								break;
							case 196:
							{
								UfVHE &mem = uf_cefc4c->group_463890(9).get_9b7250()->members_416f40();
								if (!mem.empty_9b86e0())
								{
									UfVZone zs(*uf_cefc4c->zones_462e10());
									for (unsigned k = 0; k < zs.size_9b9260(); k++)
									{
										if (zs.at_9b81f0(k)->kind != 0 && zs.at_9b81f0(k)->kind != 1)
											uf_eraseAt_9ce6d0(zs,k);
									}
									if (!zs.empty_9b86e0())
									{
										UfZone *z = uf_randomRec_9d5d00(zs);
										z->kind = 0;
										bool said = false;
										for (unsigned k2 = 0; k2 < mem.size_9b9260(); k2++)
										{
											mem.at_9b81f0(k2).get_9b6570()->setAI_64ecf0(new UfEntityAI(mem.at_9b81f0(k2),0x19,0xe));
											mem.at_9b81f0(k2).get_9b6570()->ai_45b590()->unknown459540(z->pt);
											if (!said && uf_cefc4c->unknown4631f0(mem.at_9b81f0(k2)))
											{
												uf_cefc4c->unknown6c65a0(mem.at_9b81f0(k2),"GAR_W_Retreat_Talk",0);
												said = true;
											}
										}
										do
										{
											uf_logPhrase_5141b0(0x19b,0,0,0,UfHE(),0);
										}
										while (0);
									}
								}
								break;
							}
							case 197:
							{
								UfPoint cC(uf_cefc4c->getPlayer_4630f0().get_9b6570()->getPosition_45a4a0());
								UfPoint theFar;
								UfVZone *zs = uf_cefc4c->zones_462e10();
								theFar = zs->at_9b81f0(0)->pt;
								int best = uf_distanceCeil_40a3f0(cC,theFar);
								for (unsigned k = 1; k < zs->size_9b9260(); k++)
								{
									int dd = uf_distanceCeil_40a3f0(cC,zs->at_9b81f0(k)->pt);
									if (dd > best)
									{
										best = dd;
										theFar = zs->at_9b81f0(k)->pt;
									}
								}
								UfVPt path;
								if (uf_cfe568.findPath_40c9a0(cC,theFar,uf_cefc30,0,path))
								{
									int radius = 0x19;
									UfRect hit_;
									uf_cfd44c.getRect_9b4430(theFar,0x19,hit_);
									for (int x = hit_.x1; x <= hit_.x2; x++)
									{
										for (int y = hit_.y1; y <= hit_.y2; y++)
										{
											if ((*uf_cfd44c.at_9ceda0(x,y))->unknown45dc70())
												(*uf_cfd44c.at_9ceda0(x,y))->unknown66a050(*uf_cefb9c,2,0);
										}
									}
									int nA = 3;
									UfVPt spots;
									UfPoint sp;
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 200; b++)
										{
											sp = hit_.randomPoint_40be90();
											if (CELLAT(sp)->isPassableFor_66ab30(UfHE()) && CELLAT(sp)->getProp_45d550().isNull_9b65d0() && uf_cefc4c->unknown716940(sp,cC,0,0))
											{
												spots.push_back_9b32e0(sp);
												break;
											}
										}
									}
									if (!spots.empty_9b86e0())
									{
										for (unsigned s = 0; s < spots.size_9b9a50(); s++)
										{
											UfVPt p2;
											uf_cfe568.findPath_40c9a0(cC,spots.at_9e7c10(s),uf_cefc30,0,p2);
											uf_appendUnique_9d80a0(path,p2);
											uf_cefc4c->unknown6c6b90(spots.at_9e7c10(s),"GAR_Assembled_Spawn",0,-1);
										}
										int cB = 0x28;
										for (int x2 = hit_.x1; x2 <= hit_.x2; x2++)
										{
											for (int y2 = hit_.y1; y2 <= hit_.y2; y2++)
											{
												if ((*uf_cfd44c.at_9ceda0(x2,y2))->isPassableFor_66ab30(UfHE()) && (*uf_cfd44c.at_9ceda0(x2,y2))->getEntity_45d250().isNull_9b65d0() && rng.chance_406c90(0x28) && !uf_fn9d0ce0(path,UfPoint(x2,y2)))
													(*uf_cfd44c.at_9ceda0(x2,y2))->unknown66d580(0);
											}
										}
										if (!uf_cf65a8.xc)
											uf_cf65a8.x10 = uf_cefc4c->unknown4642d0() + rng.rangeInt_406d70(10,50);
										do
										{
											uf_cf1080.set_451400(false);
											if (false)
												uf_sound_4541b0(-1,0,0);
											do
											{
												if (uf_show_5111e0b(0x324,&string("ALERT: Infestation breaching garrison interior. Local demolisher support unavailable."),0,0,UfHE(),UfHE(),0,0))
													uf_cec058->bubble_8758d0(true);
												uf_cec0b4->scrollToEnd_7b4f10();
											}
											while (false);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										do
										{
											uf_logPhrase_5141b0(0x19c,0,0,0,UfHE(),0);
										}
										while (0);
										UfRange cnt(0xf,0x19);
										UfEntityDef *ad = uf_cefc4c->unknown6c5600(3,0x3c,0,1);
										if (!ad)
										{
											uf_logError_404f10("BS::turnUpdate()","no Assembled data found");
											return false;
										}
										int fac = uf_stringToInt_405610(uf_d1e860.getEntryText_46f6d0("usedCoreResetMatrix_g")) ? 2 : 5;
										for (unsigned s2 = 0; s2 < spots.size_9b9a50(); s2++)
										{
											for (int m = cnt.randomInRange_40c130(); m > 0; m--)
											{
												UfHE e = uf_cefc4c->placeEntity_6c58c0(ad,spots.at_9e7c10(s2),fac,0,0x22,0xe,0);
												if (e.isValid_9b7230() && uf_cefc4c->unknown4631f0(e))
												{
													string msg = e.get_9b6570()->getName_416f40() + " squeezes its way out of a hidden crevice.";
													uf_message_49c610(0x320,UfHE(),&msg,0);
												}
											}
											uf_opR1d_454260(&spots.at_9e7c10(s2),0x102);
										}
										uf_cefc4c->unknown7456a0();
										if (uf_d25450.b0)
											uf_d25450.unknown69e700(0x4b,0,0.0f);
									}
								}
								break;
							}
							case 198:
								if (uf_d1eb9c.at_9b81f0(uf_d1e860.unknown46f4e0()) != 1)
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								else if (uf_cefc4c->unknown4642b0() >= w3->pos_45d1a0().distanceTo_409fb0(uf_cefc4c->unknown4184d0()) + 10)
								{
									void *xd;
									if (uf_findByName_9d7be0(uf_cfd2cc,"DSF_Explode",&xd))
										uf_cefc4c->addRecord_777a20(uf_cefaa8->createA_7930e0(new UfExpl(UfHE(),xd,w3->pos_45d1a0(),UfHE(),UfPoint(-1),UfPoint(-1))));
									w3->getProp_45d550().get_9b64f0()->unknown45ce10(0,0,1,UfHE());
								}
								break;
							case 199:
							{
								UfEntityDef *an;
								if (uf_findByName_9d7530(uf_d25de0,"Anomaly",&an))
								{
									UfPoint p(entity.get_9b6570()->getPosition_45a4a0());
									string name(entity.get_9b6570()->getName_416f40());
									int myG = entity.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350();
									entity.get_9b6570()->unknown637bb0();
									uf_caf43c = 0xc;
									UfHE hops = uf_cefc4c->placeEntity_6c58c0(an,p,myG,0,0x22,0xe,0);
									if (hops.isValid_9b7230())
									{
										hops.get_9b6570()->unknown45b340(new UfFx(uf_d2f0f8.at_9b81f0(0x2a),uf_cefc4c->getTurn_464270()));
										do
										{
											if (uf_show_5111e0b(0x2f7,&name,&hops.get_9b6570()->getName_416f40(),0,hops,UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										int *fx = 0;
										UfVPt &pts = hops.get_9b6570()->path_45d1a0();
										for (unsigned k = 0; k < pts.size_9b9a50(); k++)
										{
											if (uf_cefc4c->isVisible_4631c0(pts.at_9e7c10(k)) && (fx || uf_lookup2_9d7980("Anomaly_Polymorph",&fx)))
												uf_cefc50->new_508610(uf_cefc50)->init_503b20((int)fx,pts.at_9e7c10(k),&uf_d2e20c,0,0,0,9,0);
										}
									}
								}
								break;
							}
							case 200:
							{
								UfItemDef *d = uf_cefc4c->selectRandomItem_6c3bc0(0,8,0x12);
								if (d)
								{
									UfHI it = uf_cefc4c->unknown6c5400(d,w3->pos_45d1a0());
									if (it.isValid_9b7230())
										uf_cefc4c->addListB24_465540(it);
								}
								break;
							}
							case 201:
								uf_cefc4c->unknown71e7c0(w3->pos_45d1a0(),rng.rangeInt_406d70(15,40),0);
								break;
							case 202:
							{
								UfHE node;
								if (!uf_findNode_470180(6,-1,uf_d1e884,&node))
									goto end202;
								uf_d1e860.addExit_7892d0(node,entity.get_9b6570()->pos_45a4c0(),"N/A");
								((UfHL&)node).get_9b7910()->b25 = true;
							end202:
								break;
							}
							case 203:
								uf_cf46e4.at_9b81f0(10) = 1;
								break;
							case 204:
								if (uf_cf462c == 8)
								{
									UfHE z = uf_cefc4c->unknown715230(4,0x56);
									if (z.isValid_9b7230())
										uf_cefc4c->unknown6c65a0(z,"FL_Dialogue_ZHI",0);
								}
								break;
							case 205:
								if (uf_cf462c == 8)
								{
									string msg("^6_IRUELGGHQ QRWLFH: Li wklv zhuh FGGD wkhvh zrxogq'w eh Dvvhpeohg...");
									uf_fn510360(msg);
									do
									{
										uf_cf1080.set_451400(3);
										if (false)
											uf_sound_4541b0(-1,0,0);
										do
										{
											if (uf_show_5111e0b(0x324,&msg,0,0,UfHE(),UfHE(),0,0))
												uf_cec058->bubble_8758d0(true);
											uf_cec0b4->scrollToEnd_7b4f10();
										}
										while (false);
										uf_cec0b4->scrollToEnd_7b4f10();
									}
									while (false);
								}
								break;
							case 206:
								if (!entity.get_9b6570()->isHostileTo_45aa70(uf_cefc4c->getPlayer_4630f0()))
								{
									UfVZone *zs = uf_cefc4c->zones_462e10();
									for (unsigned k = 0; k < zs->size_9b9260(); k++)
									{
										if (zs->at_9b81f0(k)->bd && uf_between_9daf80(0xf,zs->at_9b81f0(k)->loc.get_9b7910()->type,0x12) && uf_distanceCeil_40a3f0(zs->at_9b81f0(k)->pt,entity.get_9b6570()->getPosition_45a4a0()) <= 0x32)
										{
											entity.get_9b6570()->setAI_64ecf0(new UfEntityAI(entity,0x19,0xe));
											entity.get_9b6570()->ai_45b590()->unknown459540(zs->at_9b81f0(k)->pt);
											uf_cefc4c->unknown6c65a0(entity,"Liberate_Leave_Dialogue",0);
											entity.get_9b6570()->removeEffects_45b4c0(defVal,true);
											break;
										}
									}
								}
								break;
							case 207:
							{
								int lim = 0x14;
								if (item.get_9b65b0()->unknown457cd0() >= 0x14)
								{
									UfHE ow = item.get_9b65b0()->unknown457b50();
									if (ow.get_9b6570())
									{
										bool done = false;
										UfVPt iVal;
										uf_cfd44c.getNeighbors_9ce500(ow.get_9b6570()->getPosition_45a4a0(),&iVal);
										for (unsigned k = 0; k < iVal.size_9b9a50(); k++)
										{
											if (CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().isValid_9b7230() && CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().get_9b6570()->getFaction_45a2c0() == 0x3c && CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().get_9b6570()->unknown45aaa0(ow))
											{
												item.get_9b65b0()->unknown458360(CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().get_9b6570()->getField_490840());
												done = true;
												string myMsg = CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().get_9b6570()->getName_416f40() + " melds with Sigix Exoskeleton.";
												uf_message_49c610(0x320,UfHE(),&myMsg,&item.get_9b65b0()->pos_575920());
												uf_cf45d8.unlock_77fbc0(0x1a4);
												CELLAT(iVal.at_9e7c10(k))->getEntity_45d250().get_9b6570()->unknown637bb0();
												uf_opR1d_454260(&iVal.at_9e7c10(k),0x104);
												int *fx;
												if (uf_lookup2_9d7980("Sigix_Exo_Absorb",&fx))
													uf_playEffect_55ca10(*fx,ow.get_9b6570()->getPosition_45a4a0(),0);
												if (item.get_9b65b0()->unknown457cd0() < 0x14)
													break;
											}
										}
										if (done && ow.get_9b6570()->isPlayer_5c7600())
										{
											UfPart *part = uf_cec088->unknown894e70(item);
											if (part)
												part->drawStatus_4a8e70(0);
										}
									}
								}
								break;
							}
							case 208:
								if (!uf_cf4ac8)
								{
									uf_cf4ac8 = new UfItemRec(item);
									if (uf_d25860.empty_9b86e0())
										uf_cefaa8->unknown792890();
								}
								break;
							case 209:
								uf_cefc4c->unknown74cb00();
								break;


						}
						break;
					}


				}
				if (false) {}
				uf_d2ac98.push_back_9b9d30(eff->type);
				if (eff->x40)
					uf_cec054->unknown49adc0(eff->x40);
			nextEff:
				;
			}
			if (defVal->b60)
			{
				switch (uf_ba5f40[type])
				{
					case 0:
					{
						UfHE e = uf_ba6288[type] ? records->at_9b81f0(i)->e : entity;
						if (e.get_9b6570())
							e.get_9b6570()->removeEffects_45b4c0(defVal,true);
						break;
					}
					case 1:
						if (prop.get_9b64f0())
						{
							UfVecU2 ids(1,defVal->id);
							uf_fn51d5e0(prop,ids,true);
						}
						break;
					case 2:
						if (item.get_9b65b0())
						{
							UfVecU2 ids(1,defVal->id);
							uf_fn51d730(item,ids,true);
						}
						break;
				}
			}
			else if (defVal->b61)
			{
				switch (uf_ba5f40[type])
				{
					case 0:
					{
						UfHE e = uf_ba6288[type] ? records->at_9b81f0(i)->e : entity;
						if (e.get_9b6570())
							e.get_9b6570()->unknown637bb0();
						break;
					}
					case 1:
						if (prop.get_9b64f0())
							prop.get_9b64f0()->unknown45ce10(1,0,1,UfHE());
						break;
					case 2:
						if (item.get_9b65b0())
							item.get_9b65b0()->remove_57dbe0(item.get_9b65b0()->isPlayer_5758f0(),1,1,1);
						break;
				}
			}
		}
	}
	return !uf_d2ac98.empty_9b86e0();
}
