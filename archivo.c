#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


void* thread_run(void* data){
        sleep(2);
        printf("[TH_1:%ld]: Hola desde el thread............ \n",pthread_self());
        sleep(1);
        (*(int*)data)++;
        printf("[TH_1:%ld]: saliendo............ \n",pthread_self());
        //pthread_exit(data);
}


/*MAIN*/
int main(){
pthread_t thread;
int data=0;
int thread_rc;
printf("[MAIN:%ld]: Starting............ \n",pthread_self());
if((thread_rc=pthread_create(&thread,NULL,thread_run,&data))!=0){
printf("Error creando el thread",thread_rc);
return -1;
}
sleep(1);
printf("[MAIN:%ld]: Thread asignado............ \n",pthread_self());
int *ptr_output_data;
pthread_join(thread,(void **)&ptr_output_data);
printf("[MAIN:%ld]: thread returns............ \n",pthread_self(), *ptr_output_data);
return 0;
}