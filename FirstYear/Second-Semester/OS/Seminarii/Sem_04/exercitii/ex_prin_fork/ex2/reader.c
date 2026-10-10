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