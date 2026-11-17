/*2. Faça uma função recursiva para imprimir a soma dos números ímpares de um vetor.*/
#include <stdio.h>
#include <stdlib.h>
void imprime_soma_impar_recursiva(int* v, int n, int soma){
    if(n == 0){
        printf("Soma = %i", soma);
        return;
    }
    if(v[n-1] % 2 != 0) soma += v[n-1];
    imprime_soma_impar_recursiva(v, n-1, soma);
}
int main(){
    int* vetor = (int*) malloc(6 * sizeof(int));
    if(vetor == NULL) return 1;
    vetor[0] = 2;
    vetor[1] = 3;
    vetor[2] = 4;
    vetor[3] = 5;
    vetor[4] = 6;
    vetor[5] = 7;
    imprime_soma_impar_recursiva(vetor, 6, 0);
    free(vetor);
    return 0;
}