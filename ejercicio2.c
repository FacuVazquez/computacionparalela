/*
Escribir un programa en C que reciba como argumento dos números enteros, N yM. 
Dichos números son utilizados para crear N threads de tipo 1 y M threads de tipo 2. 
La funcionalidad de los threads es la siguiente:
    THREAD tipo 1: Debe mostrar por pantalla el siguiente mensaje: “Thread1 instancia x”, siendo x el
            número de thread creado (entre 0 y N-1). Luego se suspenderá por un tiempo aleatorio entre 0 y 1
            segundo (llamada usleep o sleep) y posteriormente incrementará la variable global “Compartida”.
    THREAD tipo 2: Debe mostrar por pantalla el siguiente mensaje: “Thread2 instancia y”, siendo y el
            número de thread creado (entre 0 y M-1). Posteriormente se suspenderá por un tiempo aleatorio
            entre 0 y 1 segundo. Finalmente leerá y mostrará por pantalla el valor de la variable global
            “Compartida”.   
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int compartida = 0;

int create_processType1(int n){
    // printf("Esto es n %d \n",n);
        int i;
        for(i=0;i<n;i++){
            printf("Proceso tipo 1 %d \n",i);
            if(fork() == 0){
            // TODO: Ver el PID del proceso si es 0 meter el codigo para que haga el hijo 
            compartida++;
            exit(0);
            // return 0;
            }
        }

}

int create_processType2(int m){
    // printf("Esto es m %d \n",m);
        int i;
        for(i=0;i<m;i++){
            printf("Proceso tipo 2 %d\n",i);
            if(fork() == 0){
            // TODO: Ver el PID del proceso si es 0 meter el codigo para que haga el hijo 
            printf("compartida: %d\n",compartida);
            exit(0);
            // return 0;
            }
        }
}

void processFunction(int n,int m){
    // printf("Esto es n %d y m %d \n",n,m);
    create_processType1(n);
    create_processType2(m);
}


int main(int argc, char *argv[]){
        printf("MAIN \n");
        int n;
        int m;
        printf("Ingrese un nùmero n: ");
        scanf("%d",&n);
        printf("Ingrese un nùmero m: ");
        scanf("%d",&m);
        processFunction(n,m);
        printf("Fin del programa \n");
        return 0;
}