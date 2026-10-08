// NOTE: private partial layouts for the predicted-explosion union helper at 0x515ab0.
struct LB2EPoint { int x,y; };
struct LB2EData { char pad00[0x3c]; int intensity; };
struct LB2EView {
 void *a0;
 int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
 int width_44a630() throw();
 int left_9b6bf0() throw();
 int height_418900() throw();
 int top_44afb0() throw();
 int right_9b6c10() throw();
 int bottom_9b6c30() throw();
 void pad_9d00b0(int,int,int,int);
 void add_9d0140(LB2EView *);
};
struct LB2EExplosion {
 LB2EData *data;
 int value;
 LB2EPoint target,origin,target2;
 LB2EView view;
 LB2EExplosion();
 ~LB2EExplosion();
 void init_455880(LB2EData *,int,const LB2EPoint &,const LB2EPoint &,const LB2EPoint &);
 void update_515ab0(LB2EData *);
};
void LB2EExplosion::update_515ab0(LB2EData *newData) {
 LB2EExplosion explosion;
 explosion.init_455880(newData,value,target,origin,target2);
 LB2EView *area=&explosion.view;
 if(area->width_44a630()>view.width_44a630() || area->height_418900()>view.height_418900())
  view.pad_9d00b0(view.left_9b6bf0()-area->left_9b6bf0(),area->right_9b6c10()-view.right_9b6c10(),view.top_44afb0()-area->top_44afb0(),area->bottom_9b6c30()-view.bottom_9b6c30());
 else if(area->width_44a630()<view.width_44a630() || area->height_418900()<view.height_418900())
  area->pad_9d00b0(area->left_9b6bf0()-view.left_9b6bf0(),view.right_9b6c10()-area->right_9b6c10(),area->top_44afb0()-view.top_44afb0(),view.bottom_9b6c30()-area->bottom_9b6c30());
 view.add_9d0140(area);
 if(newData->intensity>data->intensity) data=newData;
}
