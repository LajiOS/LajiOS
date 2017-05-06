#ifndef __SHARE_MEM_PROCESS_H
#define __SHARE_MEM_PROCESS_H
#include"process_mng.h"
#include <vector>
#define SHARE_COS_QUEUE "SHARE_COS"
struct PriorCos{
    int cos_id;
    int prior;
};
class PriorProcessQueue{
public:
    vector<PriorCos> pc;

    void addCos(int cos_id,int prior){
        PriorCos cos;
        cos.cos_id=cos_id;
        cos.prior=prior;
        pc.push_back(cos);
    }

    int getFirstCos(){
        int pmax=-1;
        int pmaxIndex=0;
        for(int i=0;i<pc.size();i++){
            if(pc[i].prior>pmax){
                pmaxIndex=i;
                pmax=pc[i].prior;
            }
        }
        return pmaxIndex;
    }

    void deleteCos(int index){
        pc.erase(index);
    }
};

HANDLE makeShareFileCos(HANDLE hFile){
    HANDLE hMapping=CreateFileMapping(
        hFile,//页式临时文件
        NULL,
        PAGE_READWRITE,
        0,
        sizeof(PriorProcessQueue),
        SHARE_COS_QUEUE);
    if(hMapping!=INVALID_HANDLE_VALUE){
        //在文件上创建视图
        LPVOID pData=MapViewOfFile(
            hMapping,
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            0);
        if(pData!=NULL){
            ZeroMemory(pData,sizeof(PriorProcessQueue));
        }
        UnmapViewOfFile(pData);//撤销文件映射对象
    }
    return hMapping;
}
#endif