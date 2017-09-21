
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 
pthread_mutex_t fourchette[4];

void fourchetteLock( void *i){
		int iTmp = *((int*)i);

		pthread_mutex_lock(&fourchette[iTmp]);
		printf("Lock %d\n", iTmp);
                pthread_mutex_lock(&fourchette[iTmp-1%4]);
 
                pthread_mutex_unlock(&fourchette[iTmp]);
                printf("Lock %d\n", iTmp);
                pthread_mutex_unlock(&fourchette[iTmp-1%4]);

}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){

        int nbrPhilo = 4;
	pthread_t num_thread[nbrPhilo];
	int compteur[nbrPhilo];
	for(int i = 0; i < nbrPhilo ; i++){ compteur[i]=i;  }



	for(int i = 0; i < nbrPhilo ; i++){

	       if(pthread_create(&num_thread[i], NULL,(void*(*)()) fourchetteLock, &compteur[i] )==-1){
        	        perror("pb thread_create\n");
        	}

	
	}
        for(int i = 0; i < nbrPhilo ; i++){
        	pthread_join(num_thread[i],NULL);

	}


}


