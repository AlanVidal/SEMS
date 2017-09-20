#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


main(){
	int pid;
	pid =fork();
	if(pid == 0){
		printf("pid du fils %d : celui du pere",pid, getppid());
	}else{
		printf("pid du pere %d,  pid du fils ", pid, getpid());
		wait();
	}
}
