
#include "share_mem.h"
#include<Windows.h>

void ShareMemory::init() {
    for (int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            ticketLeft[i][j]=rand()%MAX_TICKET;
        }
    }
}

void ShareMemory::addTicket(int s,int t) {
    ticketLeft[s][t]++;
}

void ShareMemory::buyTicket(int s,int t) {
    ticketLeft[s][t]--;
}


LPVOID ShareMemory::openShareMem() {
    HANDLE hFileMapping=OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHARE_MEM_NAME);
	LPVOID pFile=MapViewOfFile(
		hFileMapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0);
}

HANDLE makeShareFile(){
    HANDLE hMapping=CreateFileMapping(
        INVALID_HANDLE_VALUE,//使用页式临时文件
        NULL,
        PAGE_READWRITE,
        0,
        sizeof(shareMemory),
        SHARE_MEM_NAME);
    if(hMapping!=INVALID_HANDLE_VALUE){
        //在文件上创建视图
        LPVOID pData=MapViewOfFile(
            hMapping,
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            0);
        if(pData!=NULL){
            ZeroMemory(pData,sizeof(shareMemory));
        }
        UnmapViewOfFile(pData);//撤销文件映射对象
    }
    return hMapping;
}