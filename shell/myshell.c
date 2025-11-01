#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

# define MAX_SIZE 128

char* GetUserName()
{
  char* name = getenv("USER");
  if(name == NULL)
  {
    return "None";
  }
  return name;
}
char* GetHostName()
{
  char* hostname = getenv("HOSTNAME");
  if(hostname == NULL)
  {
    return "None";
  }
  return hostname;
}

const char* GetPwd()
{
  char* pwd = getenv("PWD");
  if(pwd == NULL)
  {
    return "None";
  }
  return pwd;
}


void PrintCommandLine()
{
  printf("[%s@%s %s#] ",GetUserName(),GetHostName(),GetPwd());//用户名@主机名 当前路径
  fflush(stdout);
}


int GetCommand(char command_line[],int size)
{

    if(NULL == fgets(command_line,size,stdin))
      return 0;
    command_line[strlen(command_line) -1] = '\0';
    return strlen(command_line);
}


int main()
{

  char command_line[MAX_SIZE] = {0}; 

  while(1)
  {
    PrintCommandLine();

    if(0 == GetCommand(command_line,sizeof(command_line)))
    {
      continue;
    }


    printf("%s\n",command_line);
   // sleep(1);
  }


  return 0;
}
