// NOTE: private partial sound-system aliases; fields and roles are reconstructed.
#include <string>
#include <vector>
using std::string;using std::vector;
struct LC8Point {int x,y;LC8Point(const LC8Point&) throw();};
struct LC8Entity {LC8Point position45a4c0();};
struct LC8H {int id;LC8Entity*get9b6570() const;};
struct LC8Sound {char pad[8];vector<int> buffers;char gap[0x34-0x18];int type;char gap2[0x68-0x38];int volume;};
struct LC8Group {int prop;LC8Sound*sound;int volume;LC8Group(const LC8Group&) throw();};
void lc8_clear9d0670(vector<LC8Group*>&);void lc8_limit9d06d0(int*,int,int);int lc8_index9cf560(LC8Sound**,unsigned,LC8Sound*);void lc8_insert9dbdc0(vector<int>&,int,int);void lc8_move9d5760(vector<LC8Group>&,unsigned,unsigned);void lc8_fill9e2be0(LC8Sound**,int,int);
string lc8_int4051f0(int);string lc8_point40a4a0(const LC8Point&);void lc8_error404f10(string,string);
struct LC8Mixer {void halt41a210(int);void volume419c10(int,int);void play41a230(int,int,int,int,double);};extern LC8Mixer*lc8_mixer_cefa90;
struct LC8Buffer {int id;};extern vector<LC8Buffer*>lc8_buffers_d2c34c;extern vector<LC8Sound*>lc8_sounds_d2e9a0;
struct LC8Logs {void refresh499360(vector<LC8Group>*);};struct LC8Map {LC8Logs*log49abd0();};extern LC8Map*lc8_map_cec054;
extern int lc8_volume_d28c94[];extern int lc8_min_d28e00;extern int lc8_music_d28ca0;extern bool lc8_musicEnabled_d28c93;
struct LC8Ambient {vector<LC8Group*>sources;vector<LC8Point>points;vector<LC8H>props;LC8Sound*channelSounds[12];int channels[12];LC8H old;bool flag;LC8H listener;LC8Point pos;int music;void collect4ff4c0(const LC8Point&,vector<LC8Group*>*);void update4ff710();};
void LC8Ambient::update4ff710(){
 points.clear();props.clear();LC8Point h=listener.get9b6570()->position45a4c0();const LC8Point &source=h;
 lc8_clear9d0670(sources);collect4ff4c0(source,&sources);
 vector<LC8Group> vec2;vector<int> parts;
 for(unsigned i=0;i<sources.size();i++){
  unsigned j;for(j=0;j<vec2.size();j++){
   if(vec2[j].sound==sources[i]->sound){lc8_limit9d06d0(&vec2[j].volume,sources[i]->volume,100);goto merged;}
  }
  vec2.push_back(LC8Group(*sources[i]));
  merged:;
 }
 int current=0;
 for(unsigned i=0;i<vec2.size();i++){
  int idx=lc8_index9cf560(channelSounds,12,vec2[i].sound);
  if(idx!=-1){lc8_insert9dbdc0(parts,0,channels[idx]);lc8_move9d5760(vec2,i,0);channelSounds[idx]=0;current++;}
 }
 for(int i=0;i<12;i++)if(channelSounds[i])lc8_mixer_cefa90->halt41a210(channels[i]);
 lc8_fill9e2be0(channelSounds,12,0);
 if(lc8_map_cec054->log49abd0())lc8_map_cec054->log49abd0()->refresh499360(&vec2);
 int value=0;
 for(int i=0;i<vec2.size();i++){
  if(i>=12){lc8_error404f10("AmbientSoundSystem::updateAmbient()","Ambient sounds at position ("+lc8_point40a4a0(source)+") exceeded channel limit ("+lc8_int4051f0(12)+")");break;}
  vec2[i].volume=vec2[i].volume*vec2[i].sound->volume/100*lc8_volume_d28c94[vec2[i].sound->type]/10;
  if(lc8_min_d28e00 && vec2[i].volume<lc8_min_d28e00)vec2[i].volume=lc8_min_d28e00;
  if(vec2[i].volume>value)value=vec2[i].volume;
  if(i<current){channels[i]=parts[i];channelSounds[i]=vec2[i].sound;lc8_mixer_cefa90->volume419c10(channelSounds[i]->buffers.front(),vec2[i].volume);}
  else{
   int j;for(j=0;j<12;j++){
    if(lc8_buffers_d2c34c[channels[j]]){
     int k;for(k=0;k<12;k++)if(channelSounds[k] && channels[k]==j)goto used;
     channels[i]=j;break;
     used:;
    }
   }
   channelSounds[i]=vec2[i].sound;lc8_mixer_cefa90->volume419c10(channelSounds[i]->buffers.front(),vec2[i].volume);
   lc8_mixer_cefa90->play41a230(lc8_buffers_d2c34c[channels[i]]->id,channelSounds[i]->buffers.front(),-1,3000,0.0);
  }
 }
 if(music!=322 && lc8_musicEnabled_d28c93){
  if(value>0)lc8_mixer_cefa90->volume419c10(lc8_sounds_d2e9a0[music]->buffers.front(),(100-value/2)*lc8_music_d28ca0/10);
  else lc8_mixer_cefa90->volume419c10(lc8_sounds_d2e9a0[music]->buffers.front(),100*lc8_music_d28ca0/10);
 }
}
