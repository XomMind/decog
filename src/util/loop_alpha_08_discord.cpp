// NOTE: private aliases and partial Discord queue/HTTPS layouts.
#include <string>
#include <windows.h>
#include <ctype.h>
using std::string;
struct LA8Messages {char data[16];bool empty9b86e0()const throw();string &front9b7060() throw();};
struct LA8Discord {string path;void *thread;HANDLE mutex;LA8Messages messages;};
extern LA8Discord *la8_cefb5c;extern int la8_cf4b34;extern string la8_cf2998[];extern string la8_d21928,la8_d28ccc,la8_cf0c44;
struct LA8Https {LA8Https();virtual ~LA8Https();void agent4533e0(const string&);void server453400(const string&);void path453420(const string&);bool connect4f91a0(string);bool send4f9710(string&,string&,string*);string response4f9ae0();void *internet,*request,*connect;string userAgent,serverName,requestPath;unsigned short port;unsigned flags;string responseHeader; };
void la8_replace407f00(string&,string,string);void la8_error404f10(string,string);void la8_warn404e50(string,string);string la8_int4051f0(int);float la8_float405ab0(const string&);void la8_erase9cfab0(LA8Messages&,int);void la8_quit449780(int) throw();
extern "C" __declspec(dllimport) void __cdecl SDL_Delay(unsigned);
int la8_discord4fa0c0(string *data) {
 while(true) {
  if(!la8_cefb5c) break;
  unsigned delay=65;
  if(!la8_cefb5c->messages.empty9b86e0()) {
   string first=la8_cf2998[la8_cf4b34];
   string text=first+" "+la8_cefb5c->messages.front9b7060();
   LA8Https a;
   a.agent4533e0("Cogmind "+la8_d21928);a.server453400("discord.com");a.path453420(la8_cefb5c->path);
   if(a.connect4f91a0("POST")) {
    la8_replace407f00(text,"\"","'");
    string heat="Content-Type: application/json\r\n";
    string msg="{ \"username\": \""+la8_d28ccc+"\", \"content\": \""+text+"\" }";
    if(!a.send4f9710(heat,msg,0)) {
     string response=a.response4f9ae0();
     if(!response.empty()) {
      la8_error404f10("discordWebhookThread()","server response: "+response);
      if(response.find("rate limited")!=string::npos) {
       unsigned pos=response.find(la8_cf0c44);
       if(pos==string::npos) {la8_error404f10("discordWebhookThread()","unable to find rate limit");delay+=1000;}
       else {
        string value;
        for(unsigned i=pos+la8_cf0c44.length()+1;i<response.length() && (isdigit(response[i]) || response[i]=='.');i++) value+=response[i];
        delay+=la8_float405ab0(value)*1000.0;
        if(delay>=10000) la8_warn404e50("discordWebhookThread()","long wait: "+la8_int4051f0(delay));
       }
      } else if(response.find("invalid JSON")!=string::npos) {
       la8_error404f10("discordWebhookThread()","invalid JSON, attempted (first 100 chars sent): "+(msg.length()<=100?string(msg):string(msg.begin(),msg.begin()+100)));
       if(data) la8_error404f10("discordWebhookThread()","invalid JSON returned (first 100 chars): "+(data->length()<=100?string(*data):string(data->begin(),data->begin()+100)));
      }
     }
    } else {
     if(WaitForSingleObject(la8_cefb5c->mutex,INFINITE)==WAIT_OBJECT_0) la8_erase9cfab0(la8_cefb5c->messages,0);
     ReleaseMutex(la8_cefb5c->mutex);
    }
   }
  }
  SDL_Delay(delay);
 }
 la8_quit449780(7);return 0;
}
