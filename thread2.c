#include <stdio.h>
#include <pthread.h>
 
int a = 0;

io(){
        for(;;){
		pthread_mutex_lock;
        	a = a +1;
		printf("thread1 : %d \n",a);
        	pthread_mutex_unlock;
	}
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

main(){


	pthread_t num_thread;

	if(pthread_create(&num_thread, NULL,(void *(*)())io, NULL)==-1){
		perror("pb thread_create\n");
	}
       	
	for(;;){
		pthread_mutex_lock;
		a = a +10;
       		printf("thread0 : %d \n ",a);
	        pthread_mutex_unlock;

	}
			


	pthread_join(num_thread,NULL);
	
}


