#include<iostream>
#include<cstdio>
#include<string>
#include<unistd.h>
void* Routine(void *args)
{
    std::string name = static_cast<const char*>(args);
    while(true)
    {
        std::cout << "新线程...  name： " <<name<< std::endl;
    }
}
int main()
{
    const int num = 10;
    for(int i = 0;i < num; i++)
    {
        pthread_t tid;
        char threadname[64];
        snprintf(threadname,sizeof(threadname),"thread-%d", i+1);
        int n = pthread_create(&tid,nullptr,Routine,threadname);
        (void)n;
    }
    // pthread_t tid;
    // int n = pthread_create(&tid,nullptr,Routine,(void*)"thraed-1");
    // (void)n;

    while(true)
    {
        std::cout << "主线程..." << std::endl;
        sleep(1);
    }
}