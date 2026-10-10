#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int ePrim(int x)
{
 if(x < 2) return 0;
 for(int i = 2 ; i * i <= x ; ++i)
  if(x % i == 0)
   return 0;

 return 1;

}


int main()
{
 char* fifo="./fifo1";
 int fd = open(fifo,O_RDONLY);
 if( fd == -1)
 {
  perror("open()");
  exit(EXIT_FAILURE);
}

 int a;
 read(fd,&a,sizeof(int));



if(ePrim(a))
{
 printf("Numarul %d este PRIM\n",a);
}
else printf("Numarul %d nu este Prim\n",a);


close(fd);
return 0;
}
[octa@Octavian ex2]$ cat writer.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char* argv[])
{
  char* fifo = "./fifo1";
  int rez = mkfifo(fifo,0644);
  if(rez == -1)
 {
  perror("mkfifo()");
  exit(EXIT_FAILURE);
 }

 int fd = open(fifo,O_WRONLY);
 if(fd == -1)
 {
 perror("open()");
 exit(EXIT_FAILURE);
 }

 int a;
 printf("a = ");scanf(" %d",&a);
 write(fd,&a,sizeof(int));
 close(fd);
 unlink(fifo);
 return 0;
}