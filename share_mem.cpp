
#include "share_mem.h"
#include<Windows.h>
#include <iostream>

void ShareMemory::init() {
    for (int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            ticketLeft[i][j]=rand()%MAX_TICKET;
        }
    }
    memset(refundsCnt,0,sizeof(refundsCnt));
    for(int i=0;i<USER_NUM;i++){
        moneyLeft[i]=1000;
    }
}

void ShareMemory::addTicket(int s,int t) {
    ticketLeft[s][t]++;
}

void ShareMemory::buyTicket(int s,int t) {
    ticketLeft[s][t]--;
}

bool ShareMemory::defuctMoney(int cos,int money){
    if(moneyLeft[cos]<money){
        std::cout<<"no money"<<endl;
        return false;
    }
    else{
        moneyLeft[cos]-=money;
        return true;
    }
}

bool ShareMemory::addRefund(int cos){
    if(refundsCnt[cos]>MAX_REFUNDS){
        std::cout<<"no more refund ticket"<<endl;
        return false;
    }
    else {
        refundsCnt[cos]++;
        return true;
    }
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

HANDLE makeShareFile(HANDLE hFile){
    HANDLE hMapping=CreateFileMapping(
        hFile,//传入文件句柄
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