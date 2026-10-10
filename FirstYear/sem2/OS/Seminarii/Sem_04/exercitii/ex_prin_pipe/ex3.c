/*3. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură un caracter c şi un şir s şi le trimite prin
pipe procesului copil, iar procesul copil verifică şi afişează numărul de apariţii ale
caracterului c în şirul s.
*/
#include <stdio.h> // pt  printf scanf perror
#include <stdlib.h> // pt exit si failure
#include <unistd.h> //  pt pipe fork read write etc
#include <sys/wait.h>
#include <string.h>

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
        char c;
        read(fd[0],&c,sizeof(c));
        char s[100];
        read(fd[0],s,sizeof(s));
        int cnt = 0;
        for(int i = 0 ; i < strlen(s) ; ++i)
        {
            if(s[i] == c)
                cnt++;
        }

        printf("[CHILD] Caracterul %c apare de %d ori \n",c,cnt);
        close(fd[0]);
        exit(0);

  }

  close(fd[0]);
  char c;
  printf("c = "); scanf(" %c",&c);
  char s[100];
  printf(" s = "); getchar(); fgets(s,sizeof(s),stdin);

  write(fd[1],&c,sizeof(char));
  write(fd[1],s,sizeof(s));

  close(fd[1]);
  int status;
  wait(&status);
  printf("[PARENT] CHILD has ended with status %d",status);
  return 0;
}