#include "header.h"
#include <iostream>

using namespace std;
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
    HANDLE hFileMapping = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHARE_MEM_NAME);
	LPVOID pFile=MapViewOfFile(
		hFileMapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0);

    if(pFile!=NULL){
        ShareMemory *sm=(ShareMemory*)pFile;
        shareMemory->init();

        SemManager sem;
        sem.createSem();
        UnmapViewOfFile(pFile);
        pFile=NULL;
    }
    else{
        printf("OpenFileMapping error");
    }
    CloseHandle(hFileMapping);

    //进程创建与处理
    return 0;
}