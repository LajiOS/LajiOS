#ifndef __SIGNALMNG_H
#define __SIGNALMNG_H

#include "share_mem.h"

#define SEM_MUTEX "MUTEX"
#define SEM_FULL "FULL"
#define SEM_EMPTY "EMPTY"

#define MAX_REFUNDS 3



// Redefined in sem.h
class SemManager {
private:
    HANDLE mutex;
    HANDLE full[STATION_NUM][STATION_NUM];
    HANDLE empty[STATION_NUM][STATION_NUM];
public:
    void createSem();
    void openSem();
};
void P(HANDLE semHandle);
void V(HANDLE semHandle);

#endif
