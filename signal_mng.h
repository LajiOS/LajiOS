#ifndef __SIGNALMNG_H
#define __SIGNALMNG_H

#include "share_mem.h"

#define SEM_MUTEX "MUTEX"
#define SEM_FULL "FULL"
#define SEM_EMPTY "EMPTY"
#define SEM_MUTEX_COS "MUTEX_COS" 
#define SEM_FULL_COS "FULL_COS"
#define SEM_EMPTY_COS "EMPTY_COS"
#define MAX_REFUNDS 3

// Redefined in sem.h
class SemManager {
public:
    HANDLE mutex;
    HANDLE full[STATION_NUM][STATION_NUM];
    HANDLE empty[STATION_NUM][STATION_NUM];

    HANDLE mutex_cos;
    HANDLE full_cos;
    HANDLE empty_cos;
public:
    void createSem();
    void openSem();
    void closeSem();

    void createSemCos();
    void openSemCos();
    void closeSemCos();
};
void P(HANDLE semHandle);
void V(HANDLE semHandle);

#endif
