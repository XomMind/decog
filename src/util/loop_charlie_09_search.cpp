// NOTE: private partial priority-frontier pathfinder views, not FOV semantics.
struct LC9Callback {virtual bool neighbors(int,int,int*,int*,void*)=0;virtual bool cost(int,int,int,int,void*,int*)=0;virtual bool visit(int,int,void*,int)=0;};
struct LC9Search {unsigned width,height;bool custom,diagonal;unsigned closed,open;unsigned *heap,*state,*xs,*ys;int *parentX,*parentY,*priority,*travel;void flood40e990(int,int,int,LC9Callback*,void*);};
#define AT(x,y) ((x)*height+(y))
#define UPHEAP(angle) {while((angle)!=1){if(priority[heap[angle]]<priority[heap[(angle)/2]]){a=heap[(angle)/2];heap[(angle)/2]=heap[angle];heap[angle]=a;(angle)/=2;}else break;}}
void LC9Search::flood40e990(int startX,int startY,int limit,LC9Callback*cb,void*data){
 int score,point;unsigned id;int pick=1;int choices=diagonal?8:4;unsigned num,n,self,angle;int distance,bottom,a,energy,h;int root[9],ny[9];id=1;
 if(closed>1000000){for(unsigned i=0;i<(width+1)*(height+1);i++)state[i]=0;closed=10;}
 travel[AT(startX,startY)]=0;priority[1]=0;closed+=2;open=closed-1;heap[1]=1;xs[1]=startX;ys[1]=startY;num=1;
 for(;;){if(num){
  distance=xs[heap[1]];bottom=ys[heap[1]];state[AT(distance,bottom)]=closed;
  if(cb->visit(distance,bottom,data,priority[heap[1]]))break;
  heap[1]=heap[num];num--;self=1;
  for(;;){n=self;
   if(n*2+1<=num){if(priority[heap[n]]>=priority[heap[n*2]])self=n*2;if(priority[heap[self]]>=priority[heap[n*2+1]])self=n*2+1;}
   else if(n*2<=num){if(priority[heap[n]]>=priority[heap[n*2]])self=n*2;}
   if(n!=self){a=heap[n];heap[n]=heap[self];heap[self]=a;}else break;
  }
  if(custom)pick=!cb->neighbors(distance,bottom,root,ny,data);
  root[1]=distance-1;ny[1]=bottom;root[2]=distance+1;ny[2]=bottom;root[3]=distance;ny[3]=bottom-1;root[4]=distance;ny[4]=bottom+1;
  if(diagonal){root[5]=distance-1;ny[5]=bottom-1;root[6]=distance+1;ny[6]=bottom-1;root[7]=distance-1;ny[7]=bottom+1;root[8]=distance+1;ny[8]=bottom+1;}
  for(int i=pick;i<=choices;i++){
   point=root[i];energy=ny[i];if((unsigned)point<width&&(unsigned)energy<height&&state[AT(point,energy)]!=closed){
   if(cb->cost(distance,bottom,point,energy,data,&h)){
   if(state[AT(point,energy)]!=open){
    travel[AT(point,energy)]=travel[AT(distance,bottom)]+h;
    if(travel[AT(point,energy)]+h>limit)state[AT(point,energy)]=closed;
    else{
     num++;angle=num;heap[num]=id;xs[id]=point;ys[id]=energy;id++;
     priority[heap[angle]]=travel[AT(point,energy)];parentX[AT(point,energy)]=distance;parentY[AT(point,energy)]=bottom;UPHEAP(angle);
    }
    state[AT(point,energy)]=open;
   }else{
    score=travel[AT(distance,bottom)]+h;
    if(score<travel[AT(point,energy)]){
     parentX[AT(point,energy)]=distance;parentY[AT(point,energy)]=bottom;travel[AT(point,energy)]=score;
     for(unsigned j=1;j<=num;j++)if(xs[heap[j]]==point&&ys[heap[j]]==energy){priority[heap[j]]=travel[AT(point,energy)];angle=j;UPHEAP(angle);}
    }
   }
  }
 }}
 }else break;
 }
}
