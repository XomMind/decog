#include <string>
#include <vector>
using std::string;
// NOTE: address-named private interfaces; Map is a borrowed partial view.
struct LB30Point{int x,y;};struct LB30Entity{const string&name45a280()throw();};struct LB30Shoot;
struct LB30EntityHandle{int id;LB30Entity*get9b6570()const throw();};
struct LB30ShootHandle{int id;bool valid9b7230()const throw();bool equal9b78e0(LB30ShootHandle)const throw();bool different9b6510(LB30ShootHandle)const throw();LB30Shoot*get9b64d0()const throw();};
struct LB30ItemHandle{int id;};struct LB30Child{LB30Point from,to;};struct LB30ShootElement;
template<class T>struct LB30NativeVec{T*first,*last,*end;std::allocator<T>allocator;LB30NativeVec();~LB30NativeVec();};
struct LB30Shoot{void*vtable;LB30ShootHandle record04;int unknown08,unknown0c;LB30EntityHandle entity;int attackMode;LB30Point target,point20;LB30EntityHandle targetEntity;LB30NativeVec<LB30Child>children;bool isMisfire,isAutonomousWeapon,flag3e;LB30EntityHandle targetingEntity;LB30NativeVec<LB30ItemHandle>items;int weaponsFired,activeComponents,unknown5c,unknown60,unknown64,unknown68;LB30NativeVec<LB30ShootElement>owner6c;};
struct LB30Pool{void remove9d3540(LB30ShootHandle,bool);};extern LB30Pool lb30_d20404;
bool lb30_contains9d31e0(LB30NativeVec<LB30ShootHandle>&,LB30ShootHandle);
bool lb30_remove9d2f00(LB30NativeVec<LB30ShootHandle>&,LB30ShootHandle);
void lb30_warning404e50(string,string);string lb30_int4051f0(int);string lb30_point40a4a0(const LB30Point*);
struct LB30Map{char omitted[0xa30];LB30NativeVec<LB30ShootHandle>dynamicObjects;char omittedA40[0x38];LB30ShootHandle paused;void setPaused733070(LB30ShootHandle);};
static_assert(sizeof(LB30Point)==8,"Point ABI");
static_assert(sizeof(LB30ShootHandle)==4,"record handle ABI");
static_assert(sizeof(LB30NativeVec<LB30Child>)==16,"native vector ABI");
static_assert(sizeof(LB30Shoot)==124,"Shoot owners and natural padding");
void LB30Map::setPaused733070(LB30ShootHandle state){
 if(paused.valid9b7230()){
  if(paused.equal9b78e0(state))lb30_warning404e50("BS::setPausedShootState()","Found matching pausedShootState already set...");
  else{
   lb30_warning404e50("BS::setPausedShootState()","Found unresolved pausedShootState...");
   if(!paused.get9b64d0())lb30_warning404e50("BS::setPausedShootState()","  (data not valid!)");
  }
  if(paused.get9b64d0()){
   lb30_warning404e50("BS::setPausedShootState()","  [existing state]:");
   lb30_warning404e50("BS::setPausedShootState()","  -entity "+(paused.get9b64d0()->entity.get9b6570()?paused.get9b64d0()->entity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -attackMode "+lb30_int4051f0(paused.get9b64d0()->attackMode));
   lb30_warning404e50("BS::setPausedShootState()","  -target "+lb30_point40a4a0(&paused.get9b64d0()->target));
   lb30_warning404e50("BS::setPausedShootState()","  -targetEntity "+(paused.get9b64d0()->targetEntity.get9b6570()?paused.get9b64d0()->targetEntity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -isMisfire "+lb30_int4051f0(paused.get9b64d0()->isMisfire?1:0));
   lb30_warning404e50("BS::setPausedShootState()","  -isAutonomousWeapon "+lb30_int4051f0(paused.get9b64d0()->isAutonomousWeapon?1:0));
   lb30_warning404e50("BS::setPausedShootState()","  -targetingEntity "+(paused.get9b64d0()->targetingEntity.get9b6570()?paused.get9b64d0()->targetingEntity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -weaponsFired "+lb30_int4051f0(paused.get9b64d0()->weaponsFired));
   lb30_warning404e50("BS::setPausedShootState()","  -activeComponents "+lb30_int4051f0(paused.get9b64d0()->activeComponents));
   if(lb30_contains9d31e0(dynamicObjects,paused)){
    lb30_warning404e50("BS::setPausedShootState()","  (found in dynamicObjects, removed)");
    lb30_remove9d2f00(dynamicObjects,paused);
   }else lb30_warning404e50("BS::setPausedShootState()","  (not found in dynamicObjects)");
   lb30_d20404.remove9d3540(paused,true);
  }
  if(paused.different9b6510(state)){
   lb30_warning404e50("BS::setPausedShootState()","  [new state]:");
   lb30_warning404e50("BS::setPausedShootState()","  -entity "+(state.get9b64d0()->entity.get9b6570()?state.get9b64d0()->entity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -attackMode "+lb30_int4051f0(state.get9b64d0()->attackMode));
   lb30_warning404e50("BS::setPausedShootState()","  -target "+lb30_point40a4a0(&state.get9b64d0()->target));
   lb30_warning404e50("BS::setPausedShootState()","  -targetEntity "+(state.get9b64d0()->targetEntity.get9b6570()?state.get9b64d0()->targetEntity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -isMisfire "+lb30_int4051f0(state.get9b64d0()->isMisfire?1:0));
   lb30_warning404e50("BS::setPausedShootState()","  -isAutonomousWeapon "+lb30_int4051f0(state.get9b64d0()->isAutonomousWeapon?1:0));
   lb30_warning404e50("BS::setPausedShootState()","  -targetingEntity "+(state.get9b64d0()->targetingEntity.get9b6570()?state.get9b64d0()->targetingEntity.get9b6570()->name45a280():string("NULL")));
   lb30_warning404e50("BS::setPausedShootState()","  -weaponsFired "+lb30_int4051f0(state.get9b64d0()->weaponsFired));
   lb30_warning404e50("BS::setPausedShootState()","  -activeComponents "+lb30_int4051f0(state.get9b64d0()->activeComponents));
  }
 }
 paused=state;
}
