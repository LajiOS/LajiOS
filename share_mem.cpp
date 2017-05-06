
#include "share_mem.h"
#include<Windows.h>
#include <iostream>

void init(ShareMemory sm) {
    for (int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            sm.ticketLeft[i][j]=rand()%MAX_TICKET;
        }
    }
    memset(sm.refundsCnt,0,sizeof(sm.refundsCnt));
    for(int i=0;i<USER_NUM;i++){
        sm.moneyLeft[i]=1000;
    }
}

void addTicket(ShareMemory sm,int s,int t) {
    sm.ticketLeft[s][t]++;
}

void buyTicket(ShareMemory sm,int s,int t) {
    sm.ticketLeft[s][t]--;
}

bool defuctMoney(ShareMemory sm,int cos,int money){
    if(sm.moneyLeft[cos]<money){
        std::cout<<"no money"<<endl;
        return false;
    }
    else{
        sm.moneyLeft[cos]-=money;
        return true;
    }
}

bool addRefund(ShareMemory sm,int cos){
    if(sm.refundsCnt[cos]>MAX_REFUNDS){
        std::cout<<"no more refund ticket"<<endl;
        return false;
    }
    else {
        sm.refundsCnt[cos]++;
        return true;
    }
}

HANDLE openShareMem() {
    HANDLE hFileMapping=OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHARE_MEM_NAME);
	
    return hFileMapping;
}
LPVOID mapViewShareMem(HANDLE hFileMapping){
    LPVOID pFile=MapViewOfFile(
		hFileMapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0);
    return pFile;
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