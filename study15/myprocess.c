#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 // printf("我是一个进程 pid :%d,ppid:%d \n",getpid(),getppid());

 // fork();

 // printf("我是一个进程(fork) pid :%d,ppid:%d \n",getpid(),getppid());

 // sleep(1);
//  
// // return 0;
// 
//  printf("我是父进程 pid :%d,ppid:%d \n",getpid(),getppid());

  pid_t id =  fork();
  if(id < 0)
  {
    return 1;
  }
  else if(id == 0)
  {
  while(1)
  {
  printf("我是子进程 pid :%d,ppid:%d，id:%d    %p   \n",getpid(),getppid(),id,&id);
    sleep(1);
  }
  }
  else{
  while(1)
  {
  printf("我是父进程 pid :%d,ppid:%d,id:%d    %p   \n",getpid(),getppid(),id,&id);
    sleep(1);
  }
  }

 
//  sleep(1);
// 
//  while(1)
//  {
//    printf("I am a process, pid : %d\n",getpid());
//    sleep(1);
//  }
}
