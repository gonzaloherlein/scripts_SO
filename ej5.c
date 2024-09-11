#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main (int argc, char *argv[]) { 
	int num,i,j; pid_t pid,nuevo; 
	for (i= 0; i< 2; i++) {
	pid= getpid();
		for (j= 0; j< i+2; j++) {
			nuevo = fork(); /* 1 */
			printf("Creacion proceso Hijo\n");
			printf ("Soy el Hijo %d y mi padre tiene %d de PID.\n",getpid(), getppid());
			if (nuevo != 0) {
				nuevo= fork(); /* 2 */
				printf("Creacion proceso Hijo\n");
				printf ("Soy el Hijo %d y mi padre tiene %d de PID.\n",getpid(), getppid());
				break;
			}
		}
		if (pid!= getpid())
		break;
	}
}