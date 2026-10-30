/*1. O que será impresso na tela?*/
#include <stdio.h>
void f1 ( int v) {
v = v + 1;
printf (" f1 = %d\n " , v );
}
void f2 ( int *v) {
*v = *v + 1;
printf (" f2 = %d\n " , *v );
}
int f3 ( int v) {
v = v + 1;
printf (" f3 = %d\n " , v );
return v;
}
int main (void) {
int v = 1;
f1 ( v );
f2 (&v );
v = f3 ( v );
printf (" main = %d \n" , v );
printf("\n1. Cria o inteiro v com valor 1\n2. De forma local, um é somado a v que e impresso como 2\n3. Agora como ponteiro, o endreco de v recebe 1+1, ou seja, 2 que e impresso\n");
printf("4. Na terceira funcao, que retorna um inteiro, recebe o valor v e retorna 2 + 1 para o proprio v\n5. No main e impresso v apos a funcao: 3\n");
return 0;
}