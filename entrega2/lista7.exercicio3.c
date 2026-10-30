/*3. Escrever um programa que declare, inicialize e imprima um vetor de 10 inteiros. O
vetor deve conter os 10 primeiros múltiplos de 5. A inicialização do vetor e a sua
impressão devem ser feitas por funções. Generalize para um vetor de n elementos.*/
#include <stdio.h>
#include <stdlib.h>
void inicializa_vetor(int* v, int n){
    int num = 5;
    for(int i = 0; i < n; i++){
        v[i] = num;
        num += 5;
    }
}
void imprime_vetor(int* v, int n){
    for(int j = 0; j < n; j++){
        printf("5 x %i = %i\n", j+1, v[j]);
    }
}
int main(){
    int numero;
    printf("Quantidade de multiplos de 5: \n");
    while(1){
        scanf("%i", &numero);
        if(numero > 0) break;
        else printf("Invalido\n");
    }
    int* vetor = (int*) malloc(numero * sizeof(int));
    inicializa_vetor(vetor, numero);
    imprime_vetor(vetor, numero);
    free(vetor);
    return 0;
}