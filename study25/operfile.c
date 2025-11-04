#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  int fd = open("log.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
  int fda = open("loga.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
  int fdb = open("logb.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
  if(fd < 0)
  {
    perror("open");
  }
  printf("fd:%d",fd);
  printf("fda:%d",fda);
  printf("fdb:%d",fdb);


  const char* msg = "abcdefg";
  write(fd,msg,strlen(msg));

  return 0;
}




//int main()
//{
//
//  printf("我是一个进程，pid:%d\n",getpid());
//  const char* filename = "log.txt";
//  FILE* fp = fopen(filename,"w");
//  if(fp == NULL)
//  {
//    perror("fopen");
//    return 1;
//  }
//
//  fclose(fp);
//  sleep(5);
//  return 0;
//}
