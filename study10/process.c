#include"process.h"
#include<string.h>
#include<unistd.h>
#define SIZE 101
#define STYLE '='

void Process()
{
  const char* lable = "|/-\\";
  char processbuff[SIZE];
  int len = strlen(lable);
  memset(processbuff,'\0',sizeof(processbuff));
  int cnt = 0;
  while(cnt<=100)
  {
    printf("[%-100s][%d%%][%c]\r",processbuff,cnt,lable[cnt%len]);
    fflush(stdout);
    processbuff[cnt] = STYLE;
    cnt++;
    usleep(50000);
  }
  printf("\n");
}

void FlushProcess(double total,double curr)
{
  if(curr > total)
    curr = total;
  double rate = curr / total*100;
  int cnt = (int)rate;

  char processbuff[SIZE]; 
  memset(processbuff,'\0',sizeof(processbuff));
  int i = 0;
  for(i = 0;i<cnt;i++)
  {
    processbuff[i] = STYLE;
  }
  static char* lable = "|/-\\";
  static int index = 0;
  printf("[%-100s][%.1lf%%][%c]\r",processbuff,rate,lable[index++]);
  index %= strlen(lable);
  fflush(stdout);
  if(curr >= total)
  {
    printf("\n");
  }
}
