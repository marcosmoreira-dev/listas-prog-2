/*4. Implemente um programa que leia do usuário vários nomes completos de pessoas,
até que o usuário digite a palavra “fim”. Esses nomes devem ser armazenados em um
vetor. Imprima no final a média e a variância do tamanho dos nomes.*/
#define max 400
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int ind = 0, soma = 0;
    float soma_va = 0;
    char** vetor = (char**) malloc(max * sizeof(char*));
    while(1){
        vetor[ind] = (char*) malloc(max * sizeof(char));
        printf("\nDiga o nome completo: \n");
        scanf(" %[^\n]", vetor[ind]);
        if (strcmp(vetor[ind], "fim") == 0 || strcmp(vetor[ind], "FIM") == 0) {
            free(vetor[ind]);
            break;
        }
        ind++;
        }
    for(int i = 0; i < ind; i++){
        soma += strlen(vetor[i]);
    }
    float media = (float) soma / ind;
    for(int j = 0; j < ind; j++){
        soma_va += (strlen(vetor[j]) - media) * (strlen(vetor[j]) - media);
    }
    float variancia = soma_va/ind;
    printf("\nMedia = %.2f", media);
    printf("\nVariancia = %.2f", variancia);
    for(int k = 0; k < ind; k++) free(vetor[k]);
    free(vetor);
    return 0;
}