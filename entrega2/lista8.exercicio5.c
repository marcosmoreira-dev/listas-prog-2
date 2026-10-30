/*Faça um programa que, dados duas matrizes, chame funções para retornar:
a) a soma destas duas matrizes
b) a soma das diagonais de cada matriz (atualize os parâmetros passados por referência)
c) a multiplicação das duas matrizes*/
#include <stdio.h>
#include <stdlib.h>
int** aloca_matriz(int lin, int col);
int** cria_matriz(int lin, int col);
void soma_diagonal(int** mat, int lin, int *dp, int* ds);
void mostra_matriz(int** mat, int lin, int col);
void libera_matriz(int** mat, int lin);
int** soma_matriz(int** mat1, int** mat2, int lin, int col);
int** multi_matriz(int** mat1, int** mat2, int lin, int col);
int main(){
    printf("Crie sua matriz: \n");
    int linha, coluna, diagonal_p, diagonal_s;
    printf("Diga o numero de linhas e colunas: \n");
    while(1){
        scanf("%i", &linha);
        if(linha > 0)break;
        else printf("Tente Novamente: \n");
    }
    while(1){
        scanf("%i", &coluna);
        if(coluna > 0) break;
        else printf("Tente Novamente: \n");
    }
    int** matriz1 = cria_matriz(linha, coluna);
    if(matriz1 == NULL){
        printf("Erro de alocacao\n");
        return 1;
    }
    mostra_matriz(matriz1, linha, coluna);
    printf("Crie a outra matriz: \n");
    int** matriz2 = cria_matriz(linha, coluna);
    if(matriz2 == NULL){
        printf("Erro de alocacao\n");
        libera_matriz(matriz1, linha);
        return 1;
    }
    printf("Soma das matrizes\n");
    mostra_matriz(matriz2, linha, coluna);
    int** matriz_soma = soma_matriz(matriz1, matriz2, linha, coluna);
    if(matriz_soma == NULL){
        printf("Erro de alocacao\n");
        libera_matriz(matriz1, linha);
        libera_matriz(matriz2, linha);
        return 1;
    }
    printf("a)\n");
    mostra_matriz(matriz_soma, linha, coluna);
    libera_matriz(matriz_soma, linha);
    printf("b)\n");
    if(linha != coluna)printf("As matrizes nao sao quadradas! \n");
    else{
        soma_diagonal(matriz1, linha, &diagonal_p, &diagonal_s);
        printf("Diagonais da matriz 1: %i e %i\n", diagonal_p, diagonal_s);
        soma_diagonal(matriz2, linha, &diagonal_p, &diagonal_s);
        printf("Diagonais da matriz 2: %i e %i\n", diagonal_p, diagonal_s);
    }
    printf("c)\n");
    if(linha != coluna)printf("As matrizes nao sao quadradas! \n");
    else{
        int** matriz_multi = multi_matriz(matriz1, matriz2, linha, coluna);
        if(matriz_multi == NULL){
        printf("Erro de alocacao\n");
        return 1;
        }
        printf("Multiplicacao das matrizes: \n");
        mostra_matriz(matriz_multi, linha, coluna);
        libera_matriz(matriz_multi, linha);
    }
    libera_matriz(matriz1, linha);
    libera_matriz(matriz2, linha);
    return 0;
}
int** aloca_matriz(int lin, int col){
    int** mat = (int**) malloc(lin * sizeof(int*));
    if(mat == NULL) return NULL;
    for(int i = 0; i < lin; i++){
        mat[i] = (int*) malloc(col * sizeof(int));
        if(mat[i] == NULL) return NULL;
    }
    return mat;
}
void libera_matriz(int** mat, int lin){
    for(int i = 0; i < lin; i++){
        free(mat[i]);
    }
    free(mat);
}
int** cria_matriz(int lin, int col){
    int** mat = aloca_matriz(lin, col);
    if(mat == NULL) return NULL;
    printf("Preencha a sua matriz com numeros inteiros: \n");
    for(int m = 0; m < lin; m++){
        for(int n = 0; n < col; n++){
            scanf("%i", &mat[m][n]);
        }
    }
    return mat;
}
void mostra_matriz(int** mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%2i ", mat[i][j]);
        }
        printf("\n");
    }
}
int** soma_matriz(int** mat1, int** mat2, int lin, int col){
    int** soma_mat = aloca_matriz(lin, col);
    if(soma_mat == NULL) return NULL;
    for(int j = 0; j < lin; j++){
    for(int k = 0; k < col; k ++){
        soma_mat[j][k] = mat1[j][k] + mat2[j][k];
    }
    }
    return soma_mat;
}
void soma_diagonal(int** mat, int lin, int* dp, int* ds){
    *dp = 0;
    *ds = 0;
    for(int l = 0; l < lin; l++){
        *dp += mat[l][l];
        *ds += mat[l][lin - l - 1];
    }
}
int** multi_matriz(int** mat1, int** mat2, int lin, int col){
    int** mul_mat = aloca_matriz(lin, col);
    if(mul_mat == NULL) return NULL;
    for(int l = 0; l < lin; l++){
        for(int m = 0; m < col; m++){
            mul_mat[l][m] = 0;
            for(int n = 0; n < col; n++){
                mul_mat[l][m] += mat1[l][n] * mat2[n][m];
            }
        }
    }
    return mul_mat;
}