#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 // while(1)
 // {
 //   printf("我是一个进程：%d \n",getpid());
 // }
 // 
 //
  //int a = 0;
  //scanf("%d",&a);

  //printf("%d\n",a);

  //return 0;
    

  printf("父进程：%d\n",getpid());
  sleep(3);
  pid_t id = fork();
  if(id == 0)
  {
    while(1)
    {
       printf("子进程：%d\n,父进程：%d",getpid(),getppid());
       sleep(1);
    }
  }
  else{
    while(1)
    {
      printf("父进程：%d\n",getpid());
      sleep(1);
    }
  }
}
