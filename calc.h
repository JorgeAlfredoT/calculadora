#include<ctype.h>
#define TAMANO 10 // maximo tamaño de la pila.
#define NUMBER '0'

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


//#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){//inicio ------- getop obtiene el siguiente operador u operando
   int i,c;
   while((s[0] = c = getch() ) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   if (!isdigit(c) && c != '.')
      return c; // no es un numero

   i=0;
   if(isdigit(c)) // reune la parte entera
      while(isdigit (s[++i] = c = getch() ));
         ;
   if(c == '.') // reune la parte ffraccionaria
         while(isdigit (s[++i] = c = getch() ))
            ;
   s[i] = '\0';
   if( c != EOF )
      ungetch(c);
   return NUMBER;
}//fin


#define SC 100

char buf[SC]; // buffer para ungetch
int ll=0; // siguiente posicion libre de ll.

int getch(void){//inicio-------obtine un posible ya regresado caracteres1
   if (ll > 0)
      return buf[--ll];
   else
      return getchar();
}//fin

void ungetch(int c){//inicio ------- regresa caractrer de la entrada
   if ( ll >= SC)
      printf("ungetch:demasiados caracteres \n");
   else
      buf[ll++] = c;
}
