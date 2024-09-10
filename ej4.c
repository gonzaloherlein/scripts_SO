#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num, n;
    pid_t nuevo;
    for (num = 1; num <= n; num++) {
        nuevo = fork();
        if ((num == n) && (nuevo == 0))
            execlp("ls", "ls", "-l", NULL);
    }
    return 0;
}
