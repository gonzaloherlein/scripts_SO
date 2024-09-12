#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    int i, j;
    pid_t pid, nuevo, nuevo1;
    time_t ini, fin;
    ini = time(NULL);
    for (i= 0; i< 2; i++){
        pid= getpid();
        for (j= 0; j< i+2; j++){
            nuevo= fork();
            if(nuevo== 0){
                nuevo1= fork();
                if(nuevo1== 0){
                    ini = time(NULL);
                    execlp ("xload", "xload", NULL);
                } else {
                    wait(NULL);
                    fin = time(NULL);
                    printf("El proceso xload tarda: %ld segundos\n", fin - ini);
                    exit(0);
                }   
            } else {
                wait(NULL);
            }
        }
        if (pid == getpid()) {
            pid_t kcalc_pid = fork();
            if(kcalc_pid == 0){
                ini = time(NULL);
                execlp("kcalc", "kcalc", NULL);
            }else {
                wait(NULL);
                fin = time(NULL);
                printf("El proceso kcalc tarda: %ld segundos\n", fin - ini);
            }
        }
    }
    fin = time(NULL);
    printf("El tiempo total es: %ld segundos\n", fin - ini);
    return 0;
}
