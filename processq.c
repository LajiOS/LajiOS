#include "header.h"
#include <Windows.h>

#define consumer ""
int main(int argc,char *argv[]){
	HANDLE hs[USER_NUM];
    HANDLE hFileMapping=OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHARE_COS_QUEUE);
	LPVOID pFile=MapViewOfFile(
		hFileMapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0);
	if(pFile!=NULL){
		PriorProcessQueue *ppq=(PriorProcessQueue*)(pFile);
		SemManager sem;
        sem.openSem();
        int cnt=0;
        while(cnt<USER_NUM){
            P(sem.full_cos);
            P(sem.mutex_cos);
            int index=ppq->getFirstCos();
            PriorCos cos =ppq->pc[index];
            //开始创建子进程
            hs[cos.cos_id]=start(cos.cos_id,consumer);
            pc.erase(index);
            V(sem.empty_cos);
            V(sem.mutex_cos);
            sleep();
        }
		UnmapViewOfFile(pFile);
		pFile=NULL;
	}
	else{
		printf("OpenFileMapping error");
	}
	CloseHandle(hFileMapping);
	WaitForMutiObjects(hs,USER_NUM);
}