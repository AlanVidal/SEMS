#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int pip[2];

handler(){
	write( STDERR_FILENO ,"Error ! ", 8);
}



main(){
	int nbEcrit;
	int pid;
	extern handler();


/*Ouverture d'un pipe*/
	if(pipe(pip)){
		perror("pipe");
		exit(1);
	}

	pid = fork();
	if(pid==0){
		close(pip[0]);
		close(pip[1]);
		printf("je suis le fils\n");
		exit(1);
	}else{
		close(pip[0]);
		for(;;){
			signal(SIGPIPE, handler);
			if((nbEcrit = write(pip[1], "ABC", 3)) == -1){
				perror("pb write");
				exit(1);
			}else{
				printf("retour du write : %d\n", nbEcrit);
			}
		}
	}
}
