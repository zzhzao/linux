#include<iostream>
#include<signal.h>
void PrintPending(sigset_t &pending)
{
    for(int signo = 31; signo > 0;signo--)
    {
        if(sigismember(&pending,signo))
        {
            std::cout << '1';
        }
        else
        {
            std::cout << '0';
        }
    }
    std::cout<< std::endl;
}

int main()
{
    sigset_t block_set,old_set;

    sigemptyset(&block_set);
    sigemptyset(&old_set);

    sigaddset(&block_set,SIGINT);

    int n = sigprocmask(SIG_SETMASK,&block_set,&old_set);
    (void)n;
    int cnt = 1;
    std::cout << "pid : " << getpid() << std::endl;
    while(true)
    {
        sigset_t  pending;
        sigemptyset(&pending);
        n = sigpending(&pending);
        (void)n;
        PrintPending(pending);

        // 解除屏蔽
        if(cnt == 20)
        {
            int n = sigprocmask(SIG_SETMASK,&old_set,nullptr);
            (void)n;
        }
        cnt++;
        sleep(1);
    }

    return 0;
}
