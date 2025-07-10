#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main
{
  printf("before: only one line");
  fork();
  printf("after:only one line");
  sleep(1);
}
