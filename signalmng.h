#ifndef SIGNALMNG_H
#define SIGNALMNG_H
#include "sharemem.h"

union semun{
    int val;
    struct semid_ds *buf;
    ushort *array;
    struct seminfo *__buf;
};

class sem{
public:
    union semun mutexTicket;
    union semun mutexMoney;
    union semun full[STATION+1];
    union semun empty[STATION+1]
    int createSemSet(){
        sem_set_id=semget(255,3,IPC_CREAT|0600);
        if(sem_set_id==-1){
            cout<<"set sem error"<<endl;
            exit(-1);
        }
        return sem_set_id;
    }
    void createSem(){

    }
    void openSem(){

    }
}
void P(int sem_set_id,struct sembuf &sem_op,int index){
    sem_op.sem_num=index;
    sem_op.sem_op=-1;
    sem_op.sem_flg=0;
    semop(sem_set_id,&sem_op,1);
}
void V(int sem_set_id,struct sembuf &sem_op,int index){
    sem_op.sem_num=index;
    sem_op.sem_op=1;
    sem_op.sem_flg=0;
    semop(sem_set_id,&sem_op,1);
}

#endif
