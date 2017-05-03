#include "signal_mng.h"

void SemManager::init() {

}
int SemManager::createSemSet() {

}
void SemManager::createSem() {

}
void SemManager::openSem() {

}

void SemManager::P(int sem_set_id, struct sembuf &sem_op, int index) {
    sem_op.sem_num = index;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

void SemManager::V(int sem_set_id, struct sembuf &sem_op, int index){
    sem_op.sem_num = index;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}
