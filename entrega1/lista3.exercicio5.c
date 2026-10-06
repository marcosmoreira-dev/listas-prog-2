/*Implemente a função max_vet, que recebe como parâmetro um vetor de números de ponto
flutuante (vet) de tamanho n e retorna o maior número armazenado nesse vetor. Essa função deve
obedecer o protótipo: float max_vet (int n, float * vet);
Faça também a função main.*/
#include <stdio.h>
float max_vet (int n, float * vet);
int main(){
    int num;
    printf("Digite o tamanho do vetor: \n");
    scanf("%i", &num);
    printf("Digite os elementos do vetor: \n");
    float vetor[num];
    for(int i = 0; i < num; i++){
        scanf("%f", &vetor[i]);
    }
    float maior = max_vet(num, vetor);
    printf("O maior numero do vetor e: %.2f", maior);
    return 0;
}
float max_vet (int n, float * vet){
    float aux = vet[0];
    for(int j = 0; j < n; j++){
        if(vet[j] > aux) aux = vet[j];
    }
    return aux;
}
