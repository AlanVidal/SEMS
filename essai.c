#include <stdio.h>

main(){
	int pid;
	pid =fork();
	if(pid == 0){
		for(;;)printf("Je suis le fils\n");
	}else{
		for(;;)printf("Je suis le pere\n");
	}
}
