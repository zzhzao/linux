#include"processbar.h"
#include<string.h>
#include<unistd.h>
const char *lable ="|/-\\";
void processbar()
{	
	char bar[NUM];
	
	memset(bar,'\0',sizeof(bar));
	int cnt = 0;
	int len = strlen(lable);
	while(cnt <= TOP)
	{
	  printf("[%-100s][%d%%][%c]\r",bar,cnt,lable[cnt%len]);
	  fflush(stdout);
	  bar[cnt++] = STYLE;
	  usleep(100000);
	}
	printf("\n");
}


