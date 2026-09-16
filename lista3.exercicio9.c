/*Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões referenciam o valor
do terceiro elemento da matriz?
a) *(pulo + 2) b) *(pulo + 4) c) pulo + 4 d) pulo + 2*/
#include <stdio.h>
int main(){
    int pulo[] = {1,2,3,4,5,6,7,8};
    printf("a) %i\n", *(pulo + 2));
    printf("b) %i\n", *(pulo + 4));
    printf("c) %i\n", pulo + 4);
    printf("d) %i\n", pulo + 2);
    printf("A opcao a) mostra o terceiro elemento da matriz!");
}
