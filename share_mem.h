#ifndef __SHAREMEM_H
#define __SHAREMEM_H

#define STATION_NUM 10
#define MAX_TICKET 30
#define SHARE_MEM_NAME "BUFFER"
class ShareMemory {
private:
    int ticketLeft[STATION_NUM][STATION_NUM];
public:
    void init();

    void addTicket(int s,int t);
    void buyTicket(int s,int t);
    LPVOID openShareMem();
};

HANDLE makeShareFile();
#endif
