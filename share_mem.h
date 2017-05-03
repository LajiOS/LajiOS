#ifndef __SHAREMEM_H
#define __SHAREMEM_H

#include "header.h"

class ShareMemory {
private:
    int* ticketLeft;
public:
    void init();

    void addTicket(int s,int t);
    void buyTicket(int s,int t);

    void createShareMem();
    void openShareMem();
};


#endif
