#include <stdio.h>
#include <stdlib.h>

int pip1[2];
int pip2[2];

main(){
	int idfils;
	char rep[7], mesg[5];
	(pipe(pip1));
        (pipe(pip2));
	idfils=fork();
	if(idfils){
		close(pip1[0]);
		close(pip2[0]);
		write(pip1[1], "hello", 5);
		iread(pip2[1],rep,7);
		printf("message du fils : %s\n",rep);
		wait();
	}else{
		close(pip1[0]);
		close(pip2[1]);
		read(pip1[2],mesg,5);
		printf("La chaine recu par le fils est : %s\n", mesg);
		write(pip2[0],"bonjour",7);
		exit(0);	
	
	}
		


}
