/*
5. Să se scrie un program C care creează un proces copil cu care comunică prin pipe. Procesul părinte citeşte
dintr-un fişier de tip text două numere întregi pe care le trimite prin pipe procesului copil,
iar procesul copil returnează prin pipe suma lor.
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
 int p2c[2];
 int rez = pipe(p2c);
 if(rez == -1)
 {
  perror("pipe()");
  exit(EXIT_FAILURE);
 }
 int c2p[2];
 rez = pipe(c2p);
 if(rez == -1)
 {
  perror("pipe()");
  exit(EXIT_FAILURE);
 }

 int pid = fork();
 if(pid == -1)
 {
  perror("fork()");
  exit(EXIT_FAILURE);
 }
 if(pid == 0)
 {
   close(p2c[1]);
   close(c2p[0]);
   int a;
   read(p2c[0],&a,sizeof(int));


  int b;
  read(p2c[0],&b,sizeof(int));

  int sum;
  sum = a + b;
  write(c2p[1],&sum,sizeof(int));
  close(p2c[0]);
  close(c2p[1]);
  exit(0);
 }
 close(p2c[0]);
 close(c2p[1]);
 FILE* f = fopen(argv[1],"r");

 if(f == NULL)
 {
  perror("fopen()");
  exit(EXIT_FAILURE);
 }



  int a,b;
 fscanf(f,"%d %d",&a,&b);
 write(p2c[1],&a,sizeof(int));
 write(p2c[1],&b,sizeof(int));
 int sum = 0;
 read(c2p[0],&sum,sizeof(int));
 printf("[PARENT] Sum = %d \n",sum);
 close(c2p[0]);
 close(p2c[1]);
  int status;
  wait(&status);
  printf("[PARENT] Child endend with status %d",status);
  fclose(f);
 return 0;
}
