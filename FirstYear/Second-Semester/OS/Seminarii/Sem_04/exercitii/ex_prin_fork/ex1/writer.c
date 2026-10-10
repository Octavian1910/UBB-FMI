#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char* fifo = "./fifo1";

    // creează FIFO dacă nu există
    if (mkfifo(fifo, 0644) == -1) {
        perror("mkfifo");
    }

    int fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int x;
    printf("Introdu un numar: ");
    scanf("%d", &x);

    write(fd, &x, sizeof(int));

    close(fd);

    return 0;
}