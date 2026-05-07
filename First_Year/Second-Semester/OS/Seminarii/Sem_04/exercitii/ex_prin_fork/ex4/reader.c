#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc,char* argv[])
{
 char* fifo1 = "./fifo1";
 char* fifo2 = "./fifo2";


 int fd1 = open(fifo1,O_RDONLY);

 if (fd1 == -1)
 {
  perror("open()");
  exit(EXIT_FAILURE);
 }
 int a,b;
 read(fd1,&a,sizeof(int));
 read(fd1,&b,sizeof(int));
 int sum = 0;
 sum = a + b;
 int fd2 = open(fifo2,O_WRONLY);
 if( fd2 == -1)
 {
 perror("open()");
 exit(EXIT_FAILURE);
 }

 write(fd2,&sum,sizeof(int));
 close(fd1);
 close(fd2);
return 0;
}