// NOTE: private partial layout and external call-site declarations for camera scrolling872ef0.
#include <vector>
#include <cstdlib>
using namespace std;
struct ScrollPoint{int x,y;ScrollPoint()throw();ScrollPoint(int)throw();ScrollPoint(int,int)throw();ScrollPoint(const ScrollPoint&)throw();ScrollPoint&operator+=(const ScrollPoint&)throw();ScrollPoint operator-(const ScrollPoint&)const throw();ScrollPoint&operator=(const ScrollPoint&)throw();};
struct ScrollEntity{const ScrollPoint&position()throw();};
struct ScrollH{int id;ScrollEntity*operator->()const throw();};
struct ScrollArray{int*at(int,int)throw();};
struct ScrollWorld{ScrollH player()throw();ScrollArray*array()throw();int value()throw();int range()throw();};
struct ScrollGrid{void bounds(const ScrollPoint&,int,ScrollPoint&,ScrollPoint&)throw();};
struct ScrollView{void center(ScrollPoint,bool)throw();void bounds(ScrollPoint&,ScrollPoint&)throw();};
struct ScrollInts{void*layout[4];ScrollInts(int,int);~ScrollInts()throw();int&operator[](unsigned)throw();unsigned size()const throw();};
extern ScrollWorld*scrollWorld;extern ScrollView*scrollView;extern ScrollGrid scrollGrid;extern bool scrollEnabled;extern int scrollSpan,scrollModeA,scrollModeB,scrollModeSelect;// NOTE: two borrowed column views of the actual interleaved direction records.
struct ScrollDirectionColumn {int value;int nextCoordinate;};
extern ScrollDirectionColumn scrollDirectionsX_d015d8[],scrollDirectionsY_d015dc[];extern int scrollLast;
int scrollClamp(int,int,int)throw();int scrollSum(ScrollInts&)throw();
class DeltaScroll{public:char pad[0x1c];ScrollPoint offset;char gap24[2];bool blocked;char gap27[5];int direction;void move(int,int,bool);};
void DeltaScroll::move(int dir,int speed,bool smooth){
 if(scrollEnabled&&!blocked){
  int count=scrollSpan;
  int p=scrollModeSelect==0?scrollModeA:scrollModeB;
  switch(p){
   case 0:break;
   case 1:case 2:{
    ScrollPoint a(-count*scrollDirectionsX_d015d8[dir].value,-count*scrollDirectionsY_d015dc[dir].value);
    if(p==2&&smooth&&direction!=8&&(abs(dir-direction)==1||abs(dir-direction)==7)){a.x+=(offset.x-a.x)/2;a.y+=(offset.y-a.y)/2;}
    offset=a;
    scrollView->center(scrollWorld->player()->position(),false);
    break;
   }
   case 3:{
    int key=-(speed*2);
    offset+=ScrollPoint(scrollDirectionsX_d015d8[dir].value*key,scrollDirectionsY_d015dc[dir].value*key);
    switch(dir){
     case 0:case 4:if(offset.x>0)offset.x--;else if(offset.x<0)offset.x++;break;
     case 2:case 6:if(offset.y>0)offset.y--;else if(offset.y<0)offset.y++;break;
     default:if(offset.x>offset.y)offset.x--;else if(offset.x<offset.y)offset.y--;break;
    }
    offset.x=scrollClamp(-count,offset.x,count);offset.y=scrollClamp(-count,offset.y,count);
    ScrollInts name(4,-1);
    ScrollArray*data=scrollWorld->array();int index=scrollWorld->value();
    ScrollPoint w;ScrollPoint type;int range=scrollWorld->range();
    scrollGrid.bounds(scrollWorld->player()->position(),range,w,type);
    for(int j=w.y;j<=type.y;j++){for(int n=w.x;n<=type.x;n++){if(*data->at(n,j)==index){name[0]=j;goto found0;}}}found0:;
    for(int j=type.y;j>=w.y;j--){for(int n=w.x;n<=type.x;n++){if(*data->at(n,j)==index){name[2]=j;goto found2;}}}found2:;
    for(int j=w.x;j<=type.x;j++){for(int n=w.y;n<=type.y;n++){if(*data->at(j,n)==index){name[3]=j;goto found3;}}}found3:;
    for(int j=type.x;j>=w.x;j--){for(int n=w.y;n<=type.y;n++){if(*data->at(j,n)==index){name[1]=j;goto found1;}}}found1:;
    scrollView->center(scrollWorld->player()->position(),false);
    ScrollPoint a;ScrollPoint i;scrollView->bounds(a,i);
    while(name[0]<a.y&&name[2]<i.y){a.y--;i.y--;offset.y++;}
    while(name[2]>i.y&&name[0]>a.y){a.y++;i.y++;offset.y--;}
    while(name[3]<a.x&&name[1]<i.x){a.x--;i.x--;offset.x++;}
    while(name[1]>i.x&&name[3]>a.x){a.x++;i.x++;offset.x--;}
    scrollView->center(scrollWorld->player()->position(),false);
    break;
   }
   case 4:
    ScrollArray*data=scrollWorld->array();int index=scrollWorld->value();
    ScrollPoint w;ScrollPoint type;int b=scrollWorld->range();
    scrollGrid.bounds(scrollWorld->player()->position(),b,w,type);
    ScrollInts a(type.x-w.x+1,0);ScrollInts key(type.y-w.y+1,0);
    for(int p=w.x,count=0;p<=type.x;p++,count++){for(int first=w.y,text=0;first<=type.y;first++,text++){if(*data->at(p,first)==index){a[count]++;key[text]++;}}}
    int count=scrollSum(a)/2;int map=scrollSum(key)/2;ScrollPoint record(-1);
    for(unsigned j=0;j<a.size();j++){count-=a[j];if(count<=0){record.x=w.x+j;break;}}
    for(unsigned j=0;j<key.size();j++){map-=key[j];if(map<=0){record.y=w.y+j;break;}}
    offset=scrollWorld->player()->position()-record;
    scrollView->center(scrollWorld->player()->position(),false);
    break;
  }
 }
 scrollLast=dir;
}
