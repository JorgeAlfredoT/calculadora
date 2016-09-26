#include<stdio.h>

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
