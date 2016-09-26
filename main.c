#include<stdio.h>
#include<stdlib.h>
#include"calc.h"

#define MAXIMOOPERADOR 100

int main(){
   int tipo;
   float op2;
   char s[MAXIMOOPERADOR];

   while(( tipo = getop(s) ) != EOF ){
      switch(tipo){
         case NUMBER :
            push(atof(s));
            break;
         case'+':
            push( pop() + pop() );
            break;
         case '*':
            push( pop() * pop() );
            break;
         case '-':
            op2=pop();
            push( pop() - op2 );
            break;
         case '/':
            op2=pop();
            if (op2 == 0.0)
               printf("error: divisor cero\n");
            else
               push( pop() / op2 );
            break;
         case '\n':
            printf("Respuesta: %.8g\n", pop() );
            break;
         default:
            printf("error, comando desconocido %s\n",s);
            break;
      }

   }
   return 0;
}
