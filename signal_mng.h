#ifndef __SIGNALMNG_H
#define __SIGNALMNG_H

#include "header.h"
#include "share_mem.h"

// Redefined in sem.h
union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
    struct seminfo *__buf;
};

class SemManager {
private:
    union semun mutexTicket;
    union semun mutexMoney;
    union semun* full;
    union semun* empty;
public:
    void init();
    int createSemSet();
    void createSem();
    void openSem();

    void P(int sem_set_id,struct sembuf &sem_op,int index);    
    void V(int sem_set_id,struct sembuf &sem_op,int index);
};

#endif
