/*Implemente a função maiores, que recebe como parâmetro um vetor de números inteiros (vet) de
tamanho n e um valor x. A função deve retornar quantos números maiores do que x existem nesse
vetor. Essa função deve obedecer ao protótipo:
int maiores(int n, int * vet, int x);*/
#include <stdio.h>
int maiores(int n, int * vet, int x);
int main(){
    int num, param;
    printf("Digite o numero de elementos no vetor: \n");
    scanf("%i", &num);
    printf("Digite os elementos do vetor: \n");
    int vetor[num];
    for(int i = 0; i < num; i++){
        scanf("%i", &vetor[i]);
    }
    printf("Digite o parametro: \n");
    scanf("%i", &param);
    int num_maiores = maiores(num, vetor, param);
    if(num_maiores == 0)printf("Nao existem numeros maiores!");
    else printf("Existem %i numeros maiores que %i", num_maiores, param);
    return 0;
}
int maiores(int n, int * vet, int x){
    int n_maior = 0;
    for(int i = 0; i < n ;i++){
        if(x < vet[i]) n_maior++;
    }
    return n_maior;
}
