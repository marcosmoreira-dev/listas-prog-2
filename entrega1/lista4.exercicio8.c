/*Inicialize um vetor de inteiros aleatoriamente e percorra o vetor usando dois ponteiros : um
começando do início do vetor e outro do final até se encontrarem no meio. Obs : O vetor deve
conter um número par de elementos.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int num;
    while(1){
        printf("Numero de elementos do vetor(deve ser par): \n");
        scanf(" %i", &num);
        if(num > 0 && num % 2 == 0) break;
        else printf("Invalido! Tente novamente! \n");
    }
    int vetor[num];
    srand(time(NULL));
    for(int i = 0; i < num; i++){
        vetor[i] = rand() % 100;
        printf("%i\n", vetor[i]);
    }
    int *p1 = vetor;
    int *p2 = &vetor[num - 1];
    while(p1 < p2){
        printf("p1 = %i\n", *p1);
        printf("p2 = %i\n", *p2);
        p1++;
        p2--;
    }
    printf("Se encontraram");
    return 0;
}
