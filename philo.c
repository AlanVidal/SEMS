
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 
pthread_mutex_t fourchette[5];
int nbrPhilo = 5;

void fourchetteLock( void *i){
	int iTmp = *((int*)i);

	pthread_mutex_lock(&fourchette[iTmp]);
	printf("Philo %d prend fourchette de droite\n", iTmp);
        sleep(1);
        pthread_mutex_lock(&fourchette[(iTmp-1)%nbrPhilo]);
        printf("Philo %d prend fourchette de gauche\n", iTmp);
	sleep(2);	 

        pthread_mutex_unlock(&fourchette[iTmp]);
        printf("Philo %d rend fourchette de droite\n", iTmp);
        sleep(1);
	pthread_mutex_unlock(&fourchette[(iTmp-1)%nbrPhilo]);
        printf("Philo %d rend fourchette de gauche\n", iTmp);
	sleep(2);

}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc,char **argv){
	if(argc ==2){
		nbrPhilo = atoi(argv[1]);
	}


	pthread_t num_thread[nbrPhilo];
	int compteur[nbrPhilo];
	


	for(int i = 0; i < nbrPhilo ; i++){
		compteur[i]=i;
	       if(pthread_create(&num_thread[i], NULL,(void*(*)()) fourchetteLock, &compteur[i] )==-1){
        	        perror("pb thread_create\n");
        	}

	
	}
        for(int i = 0; i < nbrPhilo ; i++){
        	pthread_join(num_thread[i],NULL);

	}


}


