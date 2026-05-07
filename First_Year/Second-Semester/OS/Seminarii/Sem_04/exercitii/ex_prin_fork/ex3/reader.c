#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argvp[])
{
 char* fifo = "./fifo1";
 int fd = open(fifo,O_RDONLY);
 if(fd == -1)
 {
  perror("open()");
  exit(EXIT_FAILURE);
 }

 char c;
 read(fd,&c,sizeof(c));
 char sir[100];
 read(fd,&sir,sizeof(sir));
 int cnt = 0;
 for(int i = 0 ; sir[i] != '\0' ; ++i)
 {
   if(sir[i] == c)
   {
      ++cnt;
    }
 }
 printf("Litera %c apare de %d ori\n",c,cnt);
 close(fd);
 return 0;
}