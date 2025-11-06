#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
  const char* filename = "log.txt";
  int fd = open(filename,O_RDONLY);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }

  char buffer[1024];
  ssize_t n = read(fd,buffer,sizeof(buffer)-1);
  if(n>0)
  {
    buffer[n] = 0;
  }
  printf("%s",buffer);


  return 0;
}
