#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "Task.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sys/syscall.h>


class Res
{
public:
    int code;
    std::string name;
    std::string info;
};

void *routine(void *args)
{
      pthread_detach(pthread_self());
    std::string name = static_cast<const char *>(args);
    while (true)
    {
        std::cout << "new thread " << std::endl;

        sleep(1);
        break;
    }

    return (void*)10;
}

int main()
{

    pthread_t tid;
    pthread_create(&tid,nullptr,routine,(void*)"thread - 1");

    pthread_detach(tid);

    // void* retval = nullptr;
    // int n = pthread_join(tid,&retval);
    // if(n == 0)
    // {
    //     std::cout << "join success : " << (long long)retval << std::endl;
    // }
    return 0;
}