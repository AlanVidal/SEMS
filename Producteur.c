#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "buff.h"


struct structBuff buffer = {"",0,0 };


writeBuff(char wMsg[256]){
    int msgSize = sizeof(wMsg);
 
    for(int i =0; i <msgSize; i++){
            if(buffer.buffI%msgSize!= buffer.j-1){
                buffer.msg[buffer.buffI%msgSize] = wMsg[i]; 
                  printf("%c\n",wMsg[i]);
              }
            buffer.buffI++
            ;
        }
}
readBuff(){
    char tabRead[256];
    if(buffer.buffI != buffer.j){
        for(int i =0; i <sizeof(buffer); i++){
        tabRead[i] = buffer.msg[buffer.j];
        } 
        printf("Buffer : %d \n", tabRead);
    }
    
}


int main(){
    
    pthread_t num_thread[2];
    
    pthread_create(&num_thread[0], NULL, (char *(*)()) writeBuff,"Test 1");
    pthread_create(&num_thread[1], NULL, (void *(*)()) readBuff,NULL);
        
   
    
   
    
    
}
