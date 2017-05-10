#ifndef __PROCESSMNG_H
#define __PROCESSMNG_H

#include<vector>
HANDLE start(int id,char *szFilename);

void sleep();

void waitForChildProcess();

struct PriorCos{
    int cos_id;
    int prior;
};
class PriorProcessQueue{
public:
    vector<PriorCos> pc;

    void Process();

    int getFirstCos();
};

#endif
