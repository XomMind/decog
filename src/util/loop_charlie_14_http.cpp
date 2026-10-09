// Partial Http owner and private named external aliases, raw 4d08e0.
#include <string>
#include <cstring>
using namespace std;
typedef struct _TCPsocket *TCPsocket;
struct IPaddress{unsigned host;unsigned short port;};
extern "C" __declspec(dllimport) int SDLNet_ResolveHost(IPaddress*,const char*,unsigned short);
extern "C" __declspec(dllimport) TCPsocket SDLNet_TCP_Open(IPaddress*);
extern "C" __declspec(dllimport) void SDLNet_TCP_Close(TCPsocket);
extern "C" __declspec(dllimport) int SDLNet_TCP_Recv(TCPsocket,void*,int);
extern "C" __declspec(dllimport) char *SDL_GetError();
void logInfo(string,string);void logMessage(string);void logError(string,string);
string intToString(int);string lc14_toString9d5500(unsigned);
void lc14_remove408100(string&,char);
extern string lc14_version_d21928;
struct LC14Log{int end410e50(int);};extern LC14Log *lc14_cefa64;
struct LC14Http{string host,path;int port;void send449850(TCPsocket,const string&);string newsCheck(bool);};
string LC14Http::newsCheck(bool quiet){
 if(!quiet)logInfo("Http::newsCheck()","Checking version and retrieving news");
 string current;
 TCPsocket x=NULL;
 string header="POST "+path+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"User-Agent: Cogmind - "+lc14_version_d21928+"\r\n"+"Content-Type: application/x-www-form-urlencoded\r\n";
 if(!quiet)logMessage("Resolving address...");
 IPaddress i;
 if(SDLNet_ResolveHost(&i,host.c_str(),port)==0){
  if(!quiet)logMessage("Connecting...");
  x=SDLNet_TCP_Open(&i);
  if(!x){if(!quiet)logError("Http::newsCheck()","Unable to connect.");return current;}
  if(!quiet)logMessage("Sending content...");
  string request="version="+lc14_version_d21928;
  send449850(x,header);send449850(x,"Content-length: ");
  send449850(x,lc14_toString9d5500(request.size()));send449850(x,"\r\n\r\n");send449850(x,request.c_str());
  if(!quiet)logMessage("Waiting for ACK...");
  char text[5000];int u=SDLNet_TCP_Recv(x,text,5000);text[u]=0;
  string response=text;
  if(!quiet)logMessage("Got "+intToString(u)+" bytes: "+response);
  if(u<10){if(!quiet)logError("Http::newsCheck()","Too few bytes received");return current;}
  else if(memcmp(text,"HTTP/1.",7)!=0){if(!quiet)logError("Http::newsCheck()","Wrong HTTP version");return current;}
  else if(memcmp(text+8," 2",2)!=0){if(!quiet)logError("Http::newsCheck()","POST failed");return current;}
  else if(!quiet)logMessage("POST succeeded");
  if(!quiet)logMessage("Closing socket...");SDLNet_TCP_Close(x);x=NULL;
  unsigned a1=response.find("update_content:");
  if(a1==string::npos){if(!quiet)logError("Http::newsCheck()","Invalid news format");return current;}
  current.assign(response.begin()+a1,response.end());
  lc14_remove408100(current,'\r');
  unsigned end=current.rfind("</END>");
  if(end==string::npos){if(!quiet)logError("Http::newsCheck()","Invalid news syntax, missing closing tag");}
  else{current.erase(current.begin()+end,current.end());}
 }else{
  if(!quiet)logError("Http::newsCheck()","Unable to resolve address:"+host+":"+intToString(port));
  if(!quiet)logError("Http::newsCheck()","SDL_net error:"+string(SDL_GetError()));
 }
 if(x)SDLNet_TCP_Close(x);
 if(!quiet)lc14_cefa64->end410e50(2);
 return current;
}
