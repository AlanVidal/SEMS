#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


main(){
	int pid;
	pid =fork();
	if(pid == 0){
		printf("pere : pid du fils %d : celui du pere %d \n",getpid(), getppid());
	}else{
		printf("fils : pid du pere %d,  pid du fils %d\n ",getppid(), pid);
		wait();
	}
}
