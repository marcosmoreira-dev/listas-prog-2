/*1. Escreva uma função em C que receba um vetor de caracteres e faça a ordenação
desses elementos usando os métodos da Bolha e do QuickSort. Após finalizar esses
programas, utilize a função qsort do C para realizar a ordenação.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void buble_sort(int n, char* v){
    int i,fim;
    for(fim = n - 1; fim > 0; fim--){
        int troca = 0;
        for(i = 0; i < fim; i++){
            if(v[i] > v[i + 1]){
                char aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
                troca = 1;
                printf("%s\n", v);
            }
        }
        if(troca == 0) return;
    }
}
int posicao_pivo(int n, char* v){
    char pivo = v[n-1];
    int i = -1;
    for(int j = 0; j < n - 1; j++){
        if(v[j] <= pivo){
            i++;
            char aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    char aux = v[i+1];
    v[i+1] = v[n-1];
    v[n-1] = aux;
    return i+1;
}
void quick_sort(int n, char* v){
    if(n <= 1) return;
    int pos_pivo = posicao_pivo(n, v);
    quick_sort(pos_pivo, v);
    quick_sort(n - pos_pivo - 1, &v[pos_pivo + 1]);
    printf("%s\n", v);
}
int compara_chars(const void *a, const void *b){
    char char_a = *(const char *)a;
    char char_b = *(const char *)b;
    return char_a - char_b;
}
int main(){
    char* vetor = (char*) malloc(6 * sizeof(char));
    if(vetor == NULL) return 1;
    vetor[0] = 'c'; vetor[1] = 'a'; vetor[2] = 'e'; vetor[3] = 'd'; vetor[4] = 'b'; vetor[5] = '\0';
    int n = strlen(vetor);
    char* v1 = (char*) malloc((n + 1) * sizeof(char));
    if(v1 == NULL) return 1;
    strcpy(v1, vetor);
    printf("Metodo bubble sort: \n");
    buble_sort(n, v1);
    free(v1);
    printf("Metodo quick sort: \n");
    char* v2 = (char*) malloc((n + 1) * sizeof(char));
    if(v2 == NULL) return 1;
    strcpy(v2, vetor);
    quick_sort(n, v2);
    free(v2);
    char* v3 = (char*) malloc((n + 1) * sizeof(char));
    if(v3 == NULL) return 1;
    strcpy(v3, vetor);
    printf("Qsort: \n");
    qsort(v3, n,sizeof(char), compara_chars);
    printf("%s\n", v3);
    free(v3);
    free(vetor);
    return 0;
}