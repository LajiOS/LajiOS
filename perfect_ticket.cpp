#include "header.h"
#include <iostream>

using namespace std;
#define cosumer ""
#define producer ""
#define processq ""
const char* filename="data.txt";
int main() {
    //开始
    cout<<"start"<<endl;

    //创建文件
    FileManager fm;
    HANDLE hFile=fm.create(filename);

    //创建文件映射
    HANDLE hMapping=makeShareFile(hFile);

    //文件映射到空间并初始化
    HANDLE hFileMapping = openShareMem;
	LPVOID pFile=mapViewShareMem(hFileMapping);

    if(pFile!=NULL){
        ShareMemory *sm=(ShareMemory*)pFile;
        shareMemory->init();

        SemManager sem;
        sem.createSem();
        sem.createSemCos();
        UnmapViewOfFile(pFile);
        pFile=NULL;
    }
    else{
        printf("OpenFileMapping error");
    }
    CloseHandle(hFileMapping);
    //进程创建与处理
    start(0,producer);
    start(0,processq);
    //优先级的共享文件
    hMapping=makeShareFileCos();
    hFileMapping=OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHARE_COS_QUEUE);
    pFile=mapViewShareMem(hFileMapping);
    if(!pFile){
        PriorProcessQueue *ppq=(PriorProcessQueue*)pFile;
        SemManager sem;
        sem.openSemCos();
        for(int i=0;i<USER_NUM;i++){
            sleep();
            int prior=rand()%USER_NUM;
            P(sem.empty_cos);
            P(sem.mutex_cos);
            ppq->addCos(i,prior);
            V(sem.full_cos);
            V(sem.mutex_cos);
        }
    }



    cout<<"end"<<endl;
    return 0;
}