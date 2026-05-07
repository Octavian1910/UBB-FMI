/*
1. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură un număr natural şi îl trimite prin pipe
procesului copil, iar procesul copil verifică şi afişează dacă acest număr este par sau impar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

  if(pid == 0 )
  {
     close(fd[1]);
    int a;
     read(fd[0],&a,sizeof(int));
     if(a % 2 == 0)
     {
      printf("[CHILD] %d este par\n",a);
      }
     else printf("[CHILD] %d este impar\n",a);

    close(fd[0]);
    exit(0);

  }
   close(fd[0]);
  int a;
   printf("[PARENT] a = ");  scanf("%d",&a);

   write(fd[1],&a,sizeof(int));
   int status;
   wait(&status);
   printf("[PARENT] Child has endend with status %d :\n",status);
  close(fd[1]);
  return 0;
}