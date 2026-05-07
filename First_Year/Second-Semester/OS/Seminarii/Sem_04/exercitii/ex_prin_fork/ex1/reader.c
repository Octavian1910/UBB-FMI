#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char* fifo = "./fifo1";

    int fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int x;

    read(fd, &x, sizeof(int));

    if (x % 2 == 0)
        printf("Numarul %d este PAR\n", x);
    else
        printf("Numarul %d este IMPAR\n", x);

    close(fd);

    return 0;
}