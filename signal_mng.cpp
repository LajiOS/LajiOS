#include "signal_mng.h"
#include<Windows.h>
#include<tchar.h>

void SemManager::createSem() {
    mutex=CreateSemaphore(
				NULL,
				1,
				1,
				SEM_MUTEX);
    mutex_cos=CreateSemaphore(
				NULL,
				1,
				1,
				SEM_MUTEX_COS);
    for(int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            char semf[100];
            sprintf(semf,"FULL%d%d",i,j);
            full[i][j]=CreateSemaphore(
                NULL,
                0,
                ticketLeft[i][j],
                semf
            );

            char seme[100];
            sprintf(seme,"EMPTY%d%d",i,j);
            empty[i][j]=CreateSemaphore(
                NULL,
                ticketLeft[i][j],
                ticketLeft[i][j],
                seme
            );
        }
    }
}
void SemManager::openSem() {
    mutex=openSemaphore(
        SEMAPHORE_ALL_ACCESS,
        FALSE,
        SEM_MUTEX
    );
    mutex_cos=openSemaphore(
        SEMAPHORE_ALL_ACCESS,
        FALSE,
        SEM_MUTEX_COS
    );
    for(int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            char semf[100];
            sprintf(semf,"FULL%d%d",i,j);
            full[i][j]=openSemaphore(
                SEMAPHORE_ALL_ACCESS,
                FALSE,
                semf
            );

            char seme[100];
            sprintf(seme,"EMPTY%d%d",i,j);
            empty[i][j]=openSemaphore(
                SEMAPHORE_ALL_ACCESS,
                FALSE,
                seme
            );
        }
    }
}

void SemManager::closeSem(){
    CloseHandle(mutex);
    for(int i=0;i<STATION_NUM;i++){
        for(int j=0;j<STATION_NUM;j++){
            CloseHandle(empty[i][j]);
            CloseHandle(full[i][j]);
        }
    }
    CloseHandle(mutex_cos);
}

void SemManager::createSemCos() {
    mutex_cos=CreateSemaphore(
				NULL,
				1,
				1,
				SEM_MUTEX_COS);
    full_cos=CreateSemaphore(
				NULL,
				0,
				USER_NUM,
				SEM_FULL_COS);
    empty_cos=CreateSemaphore(
				NULL,
				USER_NUM,
				USER_NUM,
				SEM_EMPTY_COS);
}
void SemManager::openSemCos() {
    mutex_cos=openSemaphore(
        SEMAPHORE_ALL_ACCESS,
        FALSE,
        SEM_MUTEX_COS
    );
    full_cos=openSemaphore(
        SEMAPHORE_ALL_ACCESS,
        FALSE,
        SEM_FULL_COS
    );
    empty_cos=openSemaphore(
        SEMAPHORE_ALL_ACCESS,
        FALSE,
        SEM_EMPTY_COS
    );
}

void SemManager::closeSemCos(){
    CloseHandle(mutex_cos);

}

void P(HANDLE semHandle) {
    WaitForSingleObject(semHandle, INFINITE);
}

void V(HANDLE semHandle){
    ReleaseSemaphore(semHandle, 1, NULL);
}
