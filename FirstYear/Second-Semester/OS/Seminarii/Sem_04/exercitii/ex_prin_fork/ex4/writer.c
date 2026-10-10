#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char* argv[])
{
 char* fifo1 = "./fifo1";
 char* fifo2 = "./fifo2";

 mkfifo(fifo1,0644);
 mkfifo(fifo2,0644);
 int fd1 = open(fifo1,O_WRONLY);
 if(fd1 == - 1)
 {
  perror("open()");
 exit(EXIT_FAILURE);
 }

 int a,b;
 printf("a= b="); scanf("%d %d",&a,&b);
 write(fd1,&a,sizeof(int));
 write(fd1,&b,sizeof(int));

 int fd2 = open(fifo2,O_RDONLY);
 if(fd2 == -1)
 {
 perror("open()");
 exit(EXIT_FAILURE);
}
int sum = 0;
read(fd2,&sum,sizeof(int));
printf("SUM = %d",sum);

close(fd1);
close(fd2);
unlink(fifo1);
unlink(fifo2);
}