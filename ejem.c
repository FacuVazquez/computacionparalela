/*
– Escribir un programa en C que reciba como argumento dos números enteros, N y
M. Dichos números son utilizados para crear N threads de tipo 1 y M threads de tipo 2. La
funcionalidad de los threads es la siguiente:

THREAD tipo 1: Debe mostrar por pantalla el siguiente mensaje: “Thread1 instancia x”, siendo x el
número de thread creado (entre 0 y N-1). Luego se suspenderá por un tiempo aleatorio entre 0 y 1
segundo (llamada usleep o sleep) y posteriormente incrementará la variable global “Compartida”.

THREAD tipo 2: Debe mostrar por pantalla el siguiente mensaje: “Thread2 instancia y”, siendo y el
número de thread creado (entre 0 y M-1). Posteriormente se suspenderá por un tiempo aleatorio
entre 0 y 1 segundo. Finalmente leerá y mostrará por pantalla el valor de la variable global
“Compartida”. 

Cuando los threads finalicen su ejecución, el padre debe mostrar por pantalla “Fin del programa”.
Nota: Para realizar este ejercicio deben utilizarse las llamadas pthread_create y pthread_join
*/


#include<stdio.h>
#include<pthread.h>

void *threadType1(void *arg){
    printf("Thread1 instancia %d \n",*((int *)arg)-1);
}

void *threadType2(void *arg){
    printf("Thread1 instancia %d \n",*((int *)arg)-1);
}

void create_threadType1(int n){
    pthread_t t1[n-1];
    for(int i = 0; i <=n-1; i++){
        pthread_create(t1+i,NULL,threadType1,(void *)&i);
    }

    for(int i = 0; i <=n-1; i++){
        printf("Finaliza el trhead t1 %d\n", i);
        pthread_join(t1[i],NULL);
    }
}

void create_threadType2(int m){

    pthread_t t2[m-1];
    for(int i = 0; i <=m-1; i++){
        pthread_create(t2+i,NULL,threadType2,(void *)&i);
    }


    for(int i = 0; i <=m-1; i++){
        printf("Finaliza el trhead t2 %d\n", i);
        pthread_join(t2[i],NULL);
    }
}



void threadFunction(int n, int m){
    printf("n es %d \n",n);
    create_threadType1(n);
    printf("m es %d \n",m);
    create_threadType2(m);
}


/* MAIN */
int main(void)
{
 printf("HOLA MUNDO\n");
 int n;
 int m;
 printf("Ingrese un nùmero n: ");
 scanf("%d",&n);
 printf("Ingrese un nùmero m: ");
 scanf("%d",&m);
 threadFunction(n,m);
 return 0;
}