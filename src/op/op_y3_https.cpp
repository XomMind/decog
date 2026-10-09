// op_y3: HttpsConnection (WinINet transport used for scoresheet/news uploads), 0x4f90d0-0x4f9f50.
// NOTE: member names are placeholders; method names come from the logError strings where available.
#include <string>
#include <windows.h>
#include <wininet.h>
using namespace std;

string intToString(int value);
void logError(string location, string message);
extern string OpC_key_d25664;	// NOTE: placeholder name (player GUID string)

class HttpsConnection
{
public:
	HttpsConnection();
	virtual ~HttpsConnection();
	bool connectToHttpsServer(string verb);
	bool sendHttpsRequest(string& headers, string& data, string* dataPtr);
	string readResponse();	// NOTE: placeholder name
	void closeHandles();	// NOTE: placeholder name
	bool checkResponseHeader();

	HINTERNET hInternet;
	HINTERNET hRequest;
	HINTERNET hConnect;
	string agent;
	string server;
	string path;
	INTERNET_PORT port;
	DWORD flags;
	string responseHeader;
};

HttpsConnection::HttpsConnection()
{
	hInternet = NULL;
	hRequest = NULL;
	hConnect = NULL;
	agent = "";
	port = INTERNET_DEFAULT_HTTPS_PORT;
	flags = INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE|INTERNET_FLAG_SECURE|INTERNET_FLAG_KEEP_CONNECTION|INTERNET_FLAG_IGNORE_CERT_CN_INVALID;
}

bool HttpsConnection::connectToHttpsServer(string verb)
{
	try
	{
		hInternet = InternetOpenA(agent.c_str(),0,NULL,NULL,0);
		if (hInternet == NULL)
		{
			logError("HttpsConnection::connectToHttpsServer()","Unable to open internet (code "+intToString(GetLastError())+")");
			return false;
		}
		hConnect = InternetConnectA(hInternet,server.c_str(),port,"","",INTERNET_SERVICE_HTTP,0,0);
		if (hConnect == NULL)
		{
			logError("HttpsConnection::connectToHttpsServer()","Unable to connect to internet (code "+intToString(GetLastError())+")");
			closeHandles();
			return false;
		}
		hRequest = HttpOpenRequestA(hConnect,verb.c_str(),path.c_str(),NULL,"",NULL,flags,0);
		if (hRequest == NULL)
		{
			logError("HttpsConnection::connectToHttpsServer()","Cannot perform HTTP request (code "+intToString(GetLastError())+")");
			closeHandles();
			return false;
		}
	}
	catch (...)
	{
		logError("HttpsConnection::connectToHttpsServer()","Memory exception (code "+intToString(GetLastError())+")");
		return false;
	}
	return true;
}

bool HttpsConnection::sendHttpsRequest(string& headers, string& data, string* dataPtr)
{
	try
	{
		for (int attempt = 0; attempt < 20; attempt++)
		{
			BOOL sent;
			if (data.empty() && dataPtr == NULL)
				sent = HttpSendRequestW(hRequest,NULL,0,NULL,0);
			else
			{
				wstring wHeaders(((const string&)headers).begin(),((const string&)headers).end());
				if (!data.empty())
				{
					string body = data;
					sent = HttpSendRequestW(hRequest,wHeaders.c_str(),wHeaders.size(),&body[0],body.size());
				}
				else
					sent = HttpSendRequestW(hRequest,wHeaders.c_str(),wHeaders.size(),&(*dataPtr)[0],dataPtr->size());
			}
			if (sent)
			{
				if (!checkResponseHeader())
					return false;
				return true;
			}
			logError("HttpsConnection::sendHttpsRequest()","Cannot perform HTTP request (code "+intToString(GetLastError())+")");
			return false;
		}
	}
	catch (...)
	{
		logError("HttpsConnection::sendHttpsRequest()","Memory exception (code "+intToString(GetLastError())+")");
		return false;
	}
	return false;
}

string HttpsConnection::readResponse()
{
	string response;
	char buffer[1024];
	DWORD numBytesRead;
	BOOL result;
	do
	{
		result = InternetReadFile(hRequest,buffer,1023,&numBytesRead);
		buffer[numBytesRead] = 0;
		int length = strlen(buffer);
		response += buffer;
		memset(buffer,0,1024);
	}
	while (result && numBytesRead != 0);
	return response;
}

void HttpsConnection::closeHandles()
{
	if (hInternet != NULL)
	{
		InternetCloseHandle(hInternet);
		hInternet = NULL;
	}
	if (hConnect != NULL)
	{
		InternetCloseHandle(hConnect);
		hConnect = NULL;
	}
}

bool HttpsConnection::checkResponseHeader()
{
	LPVOID buffer = NULL;
	DWORD size = 0;
retry:
	if (!HttpQueryInfoW(hRequest,HTTP_QUERY_RAW_HEADERS_CRLF,buffer,&size,NULL))
	{
		if (GetLastError() == ERROR_HTTP_HEADER_NOT_FOUND)
		{
			return true;
		}
		else
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				buffer = new char[size];
				goto retry;
			}
			else
			{
				if (buffer)
					delete[] buffer;
				return false;
			}
		}
	}
	if (buffer)
	{
		wchar_t *wchars = (wchar_t*)buffer;
		wstring header(wchars);
		responseHeader.assign(header.begin(),header.end());
		delete[] buffer;
		if (responseHeader.find("HTTP/1.1 200") == string::npos && responseHeader.find("HTTP/1.1 204") == string::npos)
		{
			string code(responseHeader.begin()+9,responseHeader.begin()+12);
			logError("HttpsConnection::checkResponseHeader()","Connection failed, server response "+code);
			if (code == "422" && OpC_key_d25664.size() != 36)
				logError("HttpsConnection::checkResponseHeader()","GUID error detected");
			return false;
		}
	}
	return true;
}
