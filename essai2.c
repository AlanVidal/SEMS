#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


main(){
	int pid;
	pid =fork();
	if(pid == 0){
		execl("/bin/ls","ls" ,"-l" ,NULL);
		printf(" je suis lefils mon pid %d : celui du pere %d \n",getpid(), getppid());
	}else{
		printf("Je suis le pere mon  %d,  pid du fils %d\n ",getpid(), pid);
		wait();
	}
}
