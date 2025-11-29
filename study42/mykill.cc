#include<iostream>
#include<signal.h>

void Usage(const std::string &cmd)
{
    std::cout << "Usage : "<< cmd  << " signumber who" << std::endl;
}

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    int signumber = std::stoi(argv[1]);
    pid_t pid = std::stoi(argv[2]);

    kill(pid,signumber);
    return 0;
}