/*Escreva um programa que tenha uma função que retorne se a soma de cada uma de
suas linhas totaliza o mesmo valor para todas as linhas.*/
#include <stdio.h>
#include <stdlib.h>
int** cria_matriz(int *lin, int *col);
int confere_soma(int lin, int col, int** mat);
int main(){
    int linha, coluna,bol;
    printf("Gere sua matriz: \n");
    int** matriz = cria_matriz(&linha, &coluna);
    if(matriz == NULL){
        printf("Erro de alocação");
        return 1;
    }
    printf("Sua Matriz: \n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%2i ", matriz[i][j]);
        }
        printf("\n");  
    }
    bol = confere_soma(linha, coluna, matriz);
    if(bol)printf("Todas as linhas possuem a mesma soma\n");
    else printf("Nem todas as linhas possuem a mesma soma\n");
    for(int g = 0; g < linha; g++){
        free(matriz[g]);
    }
    free(matriz);
    return 0;
}
int** cria_matriz(int *lin, int *col){
    printf("Diga o numero de linhas e colunas: \n");
    while(1){
        scanf("%i", lin);
        if(*lin > 0)break;
        else printf("Tente Novamente: \n");
    }
    while(1){
        scanf("%i", col);
        if(*col > 0) break;
        else printf("Tente Novamente: \n");
    }
    int** mat = (int**) malloc(*lin * sizeof(int*));
    if(mat == NULL) return NULL;
    for(int k = 0; k < *lin; k++){
        mat[k] = (int*) malloc(*col * sizeof(int));
        if(mat[k] == NULL) return NULL;
    }
    printf("Preencha a sua matriz com numeros inteiros: \n");
    for(int m = 0; m < *lin; m++){
        for(int n = 0; n < *col; n++){
            scanf("%i", &mat[m][n]);
        }
    }
    return mat;
}
int confere_soma(int lin, int col, int** mat){
    int soma1 = 0, soma2 = 0;
    for(int i = 0; i < col; i++){
        soma1 += mat[0][i];
    }
    for(int j = 1;j < lin; j++){
        soma2 = 0;
        for(int m = 0; m < col; m++){
            soma2 += mat[j][m];
        }
        if(soma1 != soma2) return 0; 
    }
    printf("A soma e: %i\n", soma1);
    return 1;
}