#include "process_mng.h"

#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<iostream>
using namespace std;
HANDLE start(int id,char *szFilename)
{
    char szCmdLine[MAX_PATH];
    sprintf(szCmdLine, "\"%s\" %d", szFilename, id);
    STARTUPINFO si;
    si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;
	PROCESS_INFORMATION pi;
	bool flagCreate = CreateProcess(
		szFilename,
		szCmdLine,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);
	if (!flagCreate) {
		cout << "create process fail" << endl;
		exit(EXIT_FAILURE);
	}
    //hs[id] = pi.hProcess;
    return pi.hProcess;
}

void sleep(){
	srand((unsigned)(GetCurrentProcessId() + time(NULL)));
	int t=rand()%5000;
	Sleep(t);
}

void WaitForMutiObjects(HANDLE *hs,int size){
    for(int i=1;i<=size;i++){
        WaitForSingleObject(hs[i], INFINITE);
        CloseHandle(hs[i]);
    }
}