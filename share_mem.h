#ifndef __SHAREMEM_H
#define __SHAREMEM_H

#define STATION_NUM 10
#define MAX_TICKET 30
#define USER_NUM 100
#define SHARE_MEM_NAME "BUFFER"
#define PWLENGTH 100
const int ticketLeftBase=0;
const int refundsCntBase=STATION_NUM*STATION_NUM*sizeof(int);
const int moneyLeftBase=refundsCntBase+USER_NUM*sizeof(int);
const int passwordBase=moneyLeftBase+USER_NUM*sizeof(int);
class ShareMemory {
public:
    int ticketLeft[STATION_NUM][STATION_NUM];
    int refundsCnt[USER_NUM];
    int moneyLeft[USER_NUM];
    char password[USER_NUM][PWLENGTH];  
};
void init(ShareMemory sm);
void addTicket(ShareMemory sm,int s,int t);
void buyTicket(ShareMemory sm,int s,int t);
bool defuctMoney(ShareMemory sm,int cos,int money);
bool addRefund(ShareMemory sm,int cos);
LPVOID openShareMem();
HANDLE makeShareFile();
#endif
