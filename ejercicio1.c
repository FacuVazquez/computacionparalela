#include<stdio.h>
#include<pthread.h>

/* MAIN */
void threadFunction(int n, int m){
    printf("ESTOY EN LA FUNCTION DE LOS THREADS\n");
    printf("n es %d",n);
    printf("\nm es %d",m);
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
 threadFunction(n,m); //Function call

 return 0;
}