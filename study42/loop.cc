#include<iostream>
#include<unistd.h>


int main()
{
    while(true)
    {
        std::cout << "我是一个死循环..." << getpid() << std::endl;
        sleep(1);
    }
    return 0;
}