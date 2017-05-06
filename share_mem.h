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
    char password[USER_NUM][100];
    

    
};
void init(ShareMemory sm);
void addTicket(ShareMemory sm,int s,int t);
void buyTicket(ShareMemory sm,int s,int t);
bool defuctMoney(ShareMemory sm,int cos,int money);
bool addRefund(ShareMemory sm,int cos);
LPVOID openShareMem();
HANDLE makeShareFile();
#endif
