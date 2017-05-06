#include "file_mng.h"
#include<Windows.h>
HANDLE FileManager::create(char *filename){
    HANDLE hFile=CreateFile(
        filename,
        GENERIC_READ|GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL
    );
    return hFile;
}
void FileManager::init() {

}

void FileManager::open(char *filename){
    HANDLE hFile=CreateFile(
        filename,
        GENERIC_READ|GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL
    );
    return hFile;
}
void FileManager::read(int consumer_id) {

}
void FileManager::write(int consumer_id,int money_change) {
    
}