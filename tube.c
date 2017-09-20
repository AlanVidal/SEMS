#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pip1[2];
int pip2[2];

main(){
	int idfils;
	char rep[7], mesg[5];
	char *msg = "hello";

	(pipe(pip1));
        (pipe(pip2));
	idfils=fork();
	if(idfils){
		close(pip1[1]);
		close(pip2[0]);
		write(pip1[0], msg, strlen(msg)+1);
		read(pip2[1],rep,strlen(msg));
		printf("message du fils : %s\n",rep);
		wait();
	}else{
		close(pip1[0]);
		close(pip2[1]);
		read(pip1[1],mesg, strlen(msg)+1);
		printf("La chaine recu par le fils est : %s\n", mesg);
		write(pip2[0],"bonjour",strlen(msg));
		exit(0);	
	
	}
		


}
