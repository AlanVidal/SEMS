#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


main(){
	int pid;
	pid =fork();
	if(pid == 0){
		execl("/bin/ls","ls" ,"-l" ,NULL);
		printf("fils : pid du fils %d : celui du pere %d \n",getpid(), getppid());
	}else{
		printf("pere : pid du pere %d,  pid du fils %d\n ",getpid(), pid);
		wait();
	}
}
