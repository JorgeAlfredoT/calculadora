#include<stdio.h>
#include"calc.h"

#define TAMANO 10 // maximo tamaño de la pila.

int e=0;
float pila[TAMANO];

void push(float n){//inicio  --- introduce  a la pila
   if(e<TAMANO)
      pila[e++]=n;
   else
      printf("error pila lleno, ,no puede efetuarse push %g\n",n);
}//fin

float pop(void){// pop extrae el valor superior de la pila
   if(e>0)
      return pila[--e];
   else{
      printf("error pila vacia\n");
      return 0.0;
   }
}//fin
