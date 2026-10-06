/*Todo ano um concurso de programação premia os participantes que obtêm a maior
média ponderada em uma bateria de dois testes. Escreva uma função que recebe sete
parâmetros: o inteiro n indicando a quantidade de participantes do concurso, o ponteiro
inscr para o vetor de inteiros que contém as inscrições desses participantes, o ponteiro
t1 para o vetor de reais que contém a nota de cada participante no primeiro teste, o
inteiro p1 que indica o peso dessa nota na média ponderada, o ponteiro t2 para o vetor
de reais que contém a nota de cada participante no segundo teste, o inteiro p2 que
indica o peso dessa nota na média ponderada, e um ponteiro para a variável inteira tam.
A função deve:
● calcular a média ponderada de cada participante;
● criar um novo vetor de inteiros alocado dinamicamente com o tamanho exato
para conter apenas as inscrições dos participantes que obtiveram a maior média (pode
haver empate);
● armazenar no novo vetor as inscrições correspondentes (em qualquer ordem);
● armazenar o tamanho do novo vetor na variável tam; e
● retornar o ponteiro para o novo vetor.
Considere que para uma mesma posição do vetor (mesmo índice), a inscrição e as notas
se referem a um mesmo participante. O protótipo da função é:
int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);*/
#include <stdio.h>
#include <stdlib.h>
int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);
int main(){
    int num, peso1, peso2, tamanho;
    printf("Numero de participantes: \n");
    while(1){
        scanf("%i", &num);
        if(num <= 0)printf("Invalido\n");
        else break;
    }
    int *inscricoes = (int *) malloc(num * sizeof(int));
    if(inscricoes == NULL){
        printf("Nao foi possivel alocar!\n");
        return 1;
    }
    float *teste1 = (float *) malloc(num * sizeof(float));
    if(teste1 == NULL){
        printf("Nao foi possivel alocar!\n");
        return 1;
    }
    float *teste2 = (float *) malloc(num * sizeof(float));
    if(teste2 == NULL){
        printf("Nao foi possivel alocar!\n");
        return 1;
    }
    printf("Peso dos teste 1 e 2, respectivamente: \n");
    while(1){
        scanf("%i", &peso1);
        scanf("%i", &peso2);
        if(peso1 <= 0 || peso2 <= 0)printf("Invalido\n");
        else break;
    }
    printf("Diga a inscricao, o teste 1 e o teste 2 de cada participante: \n");
    for(int i = 0; i < num; i++){
        scanf("%i", &inscricoes[i]);
        scanf("%f", &teste1[i]);
        scanf("%f", &teste2[i]);
    }
    int* insc_maiores_notas = premiados(num, inscricoes, teste1, peso1, teste2, peso2, &tamanho);
    if(insc_maiores_notas == NULL)printf("Erro de alocao ou invalido!");
    else{
        printf("Aquele(s) com a(s) maior(es) nota(s) foi(foram): \n");
        for(int j = 0; j < tamanho; j++){
            printf("%i ", insc_maiores_notas[j]);
        }
        free(insc_maiores_notas);
    }
    free(inscricoes);
    free(teste1);
    free(teste2);
    return 0;
}
int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam){
    *tam = 0;
    int pos = 0;
    float* medias = (float *) malloc(n * sizeof(float));
    float maior = 0;
    if(medias == NULL) return NULL;
    for(int k = 0; k < n; k++){
        medias[k] = ((t1[k] * p1) + (t2[k] * p2))/(p1 + p2);
    }
    for(int l = 0; l < n; l++){
        if(medias[l] > maior) maior = medias[l];
    }
    for(int m = 0; m < n; m++){
        if(medias[m] == maior)(*tam)++;
    }
    int* prem = (int *) malloc(*tam * sizeof(int));
    if(prem == NULL) return NULL;
    for(int p = 0; p < n; p++){
        if(medias[p] == maior){
            prem[pos] = inscr[p];
            pos++;
        }
    }
    free(medias);
    return prem;
}
