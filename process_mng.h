#ifndef __PROCESSMNG_H
#define __PROCESSMNG_H

HANDLE start(int id,char *szFilename);

void sleep();

void waitForChildProcess();

#endif
