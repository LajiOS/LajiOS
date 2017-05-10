#ifndef __FILEMNG_H
#define __FILEMNG_H

#include "share_mem.h"

class FileManager {
public:
    HANDLE create(char *filename);
    HANDLE open(char *filename);
    void read(int consumer_id);
    void write(int consumer_id,int money_change);
};

#endif