#pragma once

#include <stdio.h>

#define SIZE 1024
#define NON_BUFFER  1 // 1
#define LINE_BUFFER 2 // 10
#define FULL_BUFFER 4 // 000 ... 000 100

#define MODE 0666

typedef struct  _myFILE
{
    int fd;
    int flags;
    int flush_mode;
    char outbuffer[SIZE];
    int pos;
    int cap;
}myFILE;

myFILE *myfopen(const char *pathname, const char *mode); // r, w, a, r+, w+..
int myfputs(const char *str, myFILE *fp);
void myfflush(myFILE *fp);
void myfclose(myFILE *fp);

