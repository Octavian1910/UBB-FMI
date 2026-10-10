#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc,char* argv[])
{
 char* fifo = "./fifo1";

 int rez = mkfifo(fifo,0644);
 if(rez == -1)
 {
  perror("fifo()");
  exit(EXIT_FAILURE);
 }

  int fd = open(fifo,O_WRONLY);
  if(fd == -1)
  {
   perror("open()");
   exit(EXIT_FAILURE);
 }
  char c;
  printf("c = "); scanf("%c",&c);
  write(fd,&c,sizeof(char));
  char sir[100];
  printf("sir = "); getchar(); fgets(sir,100,stdin);
  write(fd,&sir,sizeof(sir));
  unlink(fifo);
  close(fd);
 return 0;
}