// NOTE: private partial multi-destination frontier pathfinder views.
#include <vector>
struct LC11Point {int x,y;LC11Point() throw();LC11Point(const LC11Point&) throw();LC11Point&operator=(const LC11Point&) throw(); /* 453b40; copy/assignment folded at46ca50 */};
struct LC11Callback {virtual bool neighbors(int,int,int*,int*,void*)=0;virtual bool pass(int,int,void*)=0;virtual bool cost(int,int,int,int,void*,int&)=0;};
struct LC11Search {unsigned width,height;bool custom,diagonal;unsigned closed,open;unsigned *heap,*state,*xs,*ys;int *parentX,*parentY,*priority,*travel;bool path40dd50(int,int,std::vector<LC11Point>&,LC11Callback*,void*,std::vector<LC11Point>&);bool path40d280(int,int,int,int,LC11Callback*,void*,std::vector<LC11Point>&) throw();};
#define AT(x,y) ((x)*height+(y))
#define UPHEAP(angle) {while((angle)!=1){if(priority[heap[angle]]<priority[heap[(angle)/2]]){a=heap[(angle)/2];heap[(angle)/2]=heap[angle];heap[angle]=a;(angle)/=2;}else break;}}
bool LC11Search::path40dd50(int startX,int startY,std::vector<LC11Point>&goals,LC11Callback*cb,void*data,std::vector<LC11Point>&out){
 out.clear();
 for(int i=goals.size()-1;i>=0;i--)if(startX==goals[i].x&&startY==goals[i].y)goals.erase(goals.begin()+i);
 for(int i=goals.size()-1;i>=0;i--)if(!cb->pass(goals[i].x,goals[i].y,data))goals.erase(goals.begin()+i);
 if(goals.size()==1)return path40d280(startX,startY,goals[0].x,goals[0].y,cb,data,out);
 if(goals.size()==0)return false;
 int score,point;int pick=1;int choices=diagonal?8:4;unsigned id=1;unsigned num,n,self,angle;bool failed=false;LC11Point list;int distance,bottom,a,energy,h;int root[9],ny[9];
 if(closed>1000000){for(unsigned i=0;i<(width+1)*(height+1);i++)state[i]=0;closed=10;}
 travel[AT(startX,startY)]=0;closed+=2;open=closed-1;heap[1]=1;xs[1]=startX;ys[1]=startY;num=1;
 for(;;){if(num){
  distance=xs[heap[1]];bottom=ys[heap[1]];state[AT(distance,bottom)]=closed;
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
   if(cb->cost(distance,bottom,point,energy,data,h)){
   if(state[AT(point,energy)]!=open){
    num++;angle=num;heap[num]=id;xs[id]=point;ys[id]=energy;id++;
     travel[AT(point,energy)]=travel[AT(distance,bottom)]+h;priority[heap[angle]]=travel[AT(point,energy)];parentX[AT(point,energy)]=distance;parentY[AT(point,energy)]=bottom;UPHEAP(angle);
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
 for(unsigned i=0;i<goals.size();i++)if(state[AT(goals[i].x,goals[i].y)]==open){list=goals[i];failed=true;break;}
 if(failed)break;
 }else break;
 }
 if(failed){out.push_back(list);do{int x=parentX[AT(list.x,list.y)];list.y=parentY[AT(list.x,list.y)];list.x=x;out.insert(out.begin(),list);}while(list.x!=startX||list.y!=startY);}
 return failed;
}
