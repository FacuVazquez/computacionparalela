#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int compartida = 0;

const char *mensaje[2] = {"Thread1 instancia x", "Thread2 instancia y"};

void *threadType1(void *arg){
        int r = rand() % 200000;
        float random = r > 0 ? r/200000.0 : 0;
        printf("thread1 instancia %d \n",*((int *)arg));
        sleep(random);
        compartida++;
}


void *threadType2(void *arg){   
        int r = rand() % 200000;
        float random = r > 0 ? r/200000.0 : 0;
        printf("thread2 instancia %d \n",*((int *)arg));
        sleep(random);
        printf("Compartida %d \n",compartida);

}

void *threadTypes(void *arg){
        int r = rand() % 200000;
        float random = r > 0 ? r/200000.0 : 0;
        sleep(random);
}

void *create_threadType1(void *args){
        int n = *((int *)args);
        pthread_t t1[n-1];
        int i;
        for(i=0;i<n;i++){
                pthread_create(t1+i,NULL,threadType1,(void *)&i);
        }

        int r = rand() % 200000;
        float random = r > 0 ? r/200000.0 : 0;
        sleep(random);


        for(i=0;i<n;i++){
                pthread_join(t1[i],NULL);
        }

}

void *create_threadType2(void *args){

        int m = *((int *)args);
        pthread_t t2[m-1];
        int i;
        for(i=0;i<m;i++){
                pthread_create(t2+i,NULL,threadType2,(void *)&i);
        }

        int r = rand() % 200000;
        float random = r > 0 ? r/200000.0 : 0;
        sleep(random);

        for(i=0;i<m;i++){
                pthread_join(t2[i],NULL);
        }

}


void threadFunction(int n, int m) {
        pthread_t h1,h2;
        
        pthread_create(&h1, NULL, create_threadType1, (void *)&n);
        pthread_create(&h2, NULL, create_threadType2, (void *)&m);
        pthread_join(h1,NULL);
        pthread_join(h2,NULL);
        
        // create_threadType1(n);
        //create_threadType2(m);
}


int main(int argc, char *argv[]){
        printf("MAIN \n");
        int n;
        int m;
        printf("Ingrese un nùmero n: ");
        scanf("%d",&n);
        printf("Ingrese un nùmero m: ");
        scanf("%d",&m);
        threadFunction(n,m);
        printf("Fin del programa \n");
        return 0;
}
