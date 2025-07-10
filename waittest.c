#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
   pid_t id = fork();
    if(id < 0) {
        perror("fork");
        return 1;
    }
    else if(id == 0)
    {
        int *p = NULL;
          
        int cnt = 5;
        while(cnt)
        {
            printf("I am child, pid:%d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--; 
            sleep(1);
                            
        }
        exit(0);
                                                                                                            
     } else
     {                                                                              
       int cnt = 10;
       while(cnt){                                                                                                         printf("I am father, pid:%d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
       cnt--;
       sleep(1);}                                                                                                                                   
        pid_t ret = wait(NULL);
	if(ret == id)
  	{
	  printf("wait succcess , ret : %d \n", ret);
	}
	sleep(5);
     }                                    
      return 0;  
}
