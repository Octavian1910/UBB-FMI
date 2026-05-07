/*
2. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură un număr natural şi îl trimite prin pipe procesului copil,
iar procesul copil verifică şi afişează dacă acest număr este prim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
int main(int argc,char* argv[])
{

  int fd[2];
  int rez = pipe(fd);
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
      close(fd[1]);
     int n;
     bool ok = true;
     read(fd[0],&n,sizeof(int));

     if(n < 2)
       ok = false;
    if(n > 2 && n%2 == 0)
         ok = false;

     for(int i = 3 ; i <= n/2 ; i+=2)
     {
        if(n % i == 0)
           ok = false;
     }
        if(ok == true)
       {
         printf("[CHILD] %d este prim",n);
       }else printf("[CHILD] %d nu este prim",n);

    close(fd[0]);
    exit(0);
  }
    close(fd[0]);

    int a;
    printf("a = ");scanf("%d",&a);
    write(fd[1],&a,sizeof(a));

    close(fd[1]);
    int status;
    wait(&status);
    printf("[PARENT] Child has finished with status %d",status);
    return 0;


}
