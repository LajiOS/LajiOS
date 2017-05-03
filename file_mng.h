#ifndef __FILEMNG_H
#define __FILEMNG_H

class FileManager {
private:
    char *filename;
public:
    void init();
    void readFile(int consumer_id);
    void writeFile(int consumer_id,int money_change);
};

#endif