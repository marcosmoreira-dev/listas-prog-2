/*Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os
elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o
10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o
vetor Y.*/
#include <stdio.h>
int main(){
    int vetor_x[10], vetor_y[10];
    printf("Digite os 10 elementos do vetor: \n");
    for(int i = 0; i < 10; i++){
        scanf("%i", &vetor_x[i]);
    }
    for(int j = 0; j < 10; j++){
        vetor_y[9-j] = vetor_x[j];
    }
    for(int n = 0; n < 10; n++){
        printf("%i ", vetor_y[n]);
    }
    return 0;
}
