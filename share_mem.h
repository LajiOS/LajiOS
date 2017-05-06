#ifndef __SHAREMEM_H
#define __SHAREMEM_H

#define STATION_NUM 10
#define MAX_TICKET 30
#define USER_NUM 100
#define SHARE_MEM_NAME "BUFFER"
class ShareMemory {
public:
    int ticketLeft[STATION_NUM][STATION_NUM];
    int refundsCnt[USER_NUM];
    int moneyLeft[USER_NUM];
    void init();

    void addTicket(int s,int t);
    void buyTicket(int s,int t);
    bool defuctMoney(int cos,int money);
    bool addRefund(int cos);
    LPVOID openShareMem();
};

HANDLE makeShareFile();
#endif
