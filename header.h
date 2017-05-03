#ifndef __HEADER_H
#define __HEADER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

using namespace std;


#define STATION_NUM 5


#define SHM_KEY 555
#define SEM_KEY 333
#define SXM_ACCESS_RIGHT 0666   // shm sem access permissions


#endif