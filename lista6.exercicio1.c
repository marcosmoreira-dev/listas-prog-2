/*Escreva uma função em C que receba como parâmetros um vetor (vet) de n números
reais e um ponteiro para inteiro (tam) e retorne o ponteiro para um novo vetor, alocado
dinamicamente, contendo somente os elementos do vetor original que são maiores que
a média de todos os valores. Por exemplo, o vetor {5.5, 3.2, 2.5, 9.4, 7.5, 4.1, 5.4, 8.0,
6.9}, daria origem ao vetor {9.4, 7.5, 8.0, 6.9}, de tamanho 4. No ponteiro para inteiro
deverá ser armazenado o tamanho do novo vetor. Se não for possível alocar o novo
vetor, a função deve retornar NULL.
float *acima_da_media(int n, float *vet, int *tam);
1) Calcular a média de vet
2) verificar quantos elementos de vet são maiores do que a média
3) alocar dinamicamente um vetresposta conforme o tamanho verificado no item 2
4) preencher o vetresposta com os elementos do item 2
5) atualizar a variável ponteiro tam com o tamanho do novo vetor*/
#include <stdio.h>
#include <stdlib.h>
float *acima_da_media(int n, float *vet, int *tam);
int main(){
    int num, tamanho = 0;
    printf("Tamanho do vetor: \n");
    scanf("%i", &num);
    float* vetor = (float *) malloc (num * sizeof(float));
    if(vetor == NULL){
        printf("Memoria nao foi alocada\n");
        return 1;
    }
    printf("Diga os elementos do vetor: \n");
    for(int i = 0; i < num; i++){
        scanf("%f", &vetor[i]);
    }
    float* resultados = acima_da_media(num, vetor, &tamanho);
    if(resultados == NULL)printf("Nenhum elemento acimda media ou erro de alocacao\n");
    else{
        for(int m = 0; m < tamanho; m++){
            printf("%.2f ", resultados[m]);
        }
        free(resultados);
    }
    free(vetor);
}
float *acima_da_media(int n, float *vet, int *tam){
    float soma = 0;
    int pos = 0;
    for(int j = 0; j < n; j++){
        soma+= vet[j];
    }
    float media = soma/n;
    for(int k = 0; k < n; k++){
        if(vet[k] > media) (*tam)++;
    }
    if(*tam == 0) return NULL;
    float* novo_vetor = (float*) malloc(*tam * sizeof(float));
    if(novo_vetor == NULL) return NULL;
    for(int l = 0; l < n; l++){
        if(vet[l] > media){
            novo_vetor[pos] = vet[l];
            pos++;
        }
    }
    return novo_vetor;
}
