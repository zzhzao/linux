#include"process.h"
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
double total = 1024.0;
double speed = 1.0; //下载速度


typedef void(*callback_t)(double,double);
double SpeedFloat(double start,double range)
{
  int int_range = (int)range;
  return start + rand()%int_range + (range - int_range);
}
void Download(int total,callback_t cb)
{
  double curr = 0.0;
  while(true)
  {
    if(curr > total)
    {
      curr = total;
     // FlushProcess(total,curr);
    cb(total,curr); 
      break;
    }
   // FlushProcess(total,curr);
    cb(total,curr);
    curr += SpeedFloat(speed,10.3);
    usleep(30000);
  }
}
int main()
{
 // Process();
  Download(2000.0,FlushProcess);
  return 0;
}
