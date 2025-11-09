#include "mystdio.h"
#include <string.h> // string.h 你也可以封装
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define TRY_FLUSH 1
#define MUST_FLUSH 2

myFILE *myfopen(const char *pathname, const char *mode) // r, w, a, r+, w+..
{
    int fd = -1;
    int flags = 0;
    if(strcmp(mode, "r") == 0)
    {
        flags = O_RDONLY;
        fd = open(pathname, flags);
    }
    else if(strcmp(mode, "w") == 0)
    {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
        fd = open(pathname, flags, MODE);
    }
    else if(strcmp(mode, "a") == 0)
    {
        flags = O_WRONLY | O_CREAT | O_APPEND;
        fd = open(pathname, flags, MODE);
    }
    else
    {
        // TODO
    }
    if(fd < 0)
        return NULL;

    myFILE *fp = (myFILE *)malloc(sizeof(myFILE));
    if(fp == NULL)
        return NULL;

    fp->fd = fd;
    fp->flags = flags;
    fp->flush_mode = LINE_BUFFER;
    fp->cap = SIZE;
    fp->pos = 0;

    return fp;
}

static void myfflushcore(myFILE *fp, int flag)
{
    if(fp->pos == 0)
        return;
    if((fp->flush_mode & LINE_BUFFER) || (flag & MUST_FLUSH))
    {
        // "abcd\n"
        if((fp->outbuffer[fp->pos-1] == '\n') || (flag & MUST_FLUSH))
        {
            // 写到内核中
            write(fp->fd, fp->outbuffer, fp->pos);
            fp->pos = 0; // 清空缓冲区
        }
    }
    else if(fp->flush_mode & FULL_BUFFER)
    {
        //if(fp->pos == fp->cap)
    }
    else if(fp->flush_mode & NON_BUFFER)
    {
        // write();
    }
}

void myfflush(myFILE *fp)
{
    myfflushcore(fp, MUST_FLUSH);
}

int myfputs(const char *str, myFILE *fp)
{
    if(strlen(str) == 0)
        return 0;
    // step 1:向文件流里面写，本质是: 文件缓冲区 -> 拷贝
    memcpy(fp->outbuffer + fp->pos, str, strlen(str));
    fp->pos += strlen(str);

    // step 2: 如果条件允许，可以自己刷新
    myfflushcore(fp, TRY_FLUSH);
    return strlen(str);
}

void myfclose(myFILE *fp)
{
    // 1. 强制刷新到内核
    myfflush(fp);

    // 1.2 强制刷新到磁盘
    fsync(fp->fd); // 不是必选的

    // 2. 关闭文件
    close(fp->fd);

    // 3. free
    free(fp);
}
