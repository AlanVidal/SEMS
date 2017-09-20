#include <stdio.h>
#include <pthread.h>
 
int a = 0;
/*
StartXThread(int nbrThread){
        for(;;){
		if(pthread_create(&num_thread, NULL,(void *(*)())io, NULL)==-1){
                	perror("pb thread_create\n");
        	}

	}
}
*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

main(){
	int nbrPhilo = 3;
	pthread_t num_thread;
	thread = (pthread_t*) malloc(nbrPhilo * sizeOf(pthread_t));	


       	/*
	for(;;){
		pthread_mutex_lock;
		a = a +10;
       		printf("thread0 : %d \n ",a);
	        pthread_mutex_unlock;

	}
	*/		


	pthread_join(num_thread,NULL);
	
}


