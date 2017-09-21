#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

 
pthread_mutex_t f0;
pthread_mutex_t f1;

fourchetteLock(){
		pthread_mutex_lock(&f0);
		printf("Lock \n");
                pthread_mutex_lock(&f1);
 
                pthread_mutex_unlock(&f0);
                printf("Lock : %d \n");
                pthread_mutex_unlock(&f1);
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

main(){


	pthread_t num_thread[2];
	int nbrPhilo = 5;


	for(int i = 0; i < nbrPhilo ; i++){

	       if(pthread_create(&num_thread[i], NULL,(void *(*)())fourchetteLock, NULL)==-1){
        	        perror("pb thread_create\n");
        	}

	
	}
	


	pthread_join(num_thread[0],NULL);
        pthread_join(num_thread[1],NULL);



}


