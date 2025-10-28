#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
//  printf("argc:%d\n",argc);
//  int i = 0;
//  for(;i<argc;i++)
//  {
//    printf("argv[%d]->%s\n",i,argv[i]);
//  }
  if(argc != 2)
  {
    printf("该命令使用错误\n");
    return 1;
  }
  if(strcmp(argv[1],"-a" )== 0)
  {
    printf("我现在执行的是第一种功能\n");
  }
  else if(strcmp(argv[1],"-b" )== 0)
  {
    printf("我现在执行的是第二种功能\n");
  }
  else if(strcmp(argv[1],"-c" )== 0)
  {
    printf("我现在执行的是第三种功能\n");
  }
  else 
  {
    printf("执行默认功能\n");
  }
  return 0;
}
