/*Escreva um programa em linguagem C que faça a leitura e calcule a soma de duas
matrizes.*/
#include <stdio.h>
#include <stdlib.h>
int** cria_matriz(int *lin, int *col);
int** cria_matriz2(int lin, int col);
int** soma_matriz(int** mat1, int** mat2, int lin, int col);
int main(){
    int linha, coluna;
    printf("Crie sua matriz: \n");
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
    printf("Crie a segunda matriz: ");
    int** matriz2 = cria_matriz2(linha, coluna);
    if(matriz2 == NULL){
        printf("Erro de alocação");
     return 1;
    }
    printf("Sua Matriz: \n");
    for(int k = 0; k < linha; k++){
        for(int l = 0; l < coluna; l++){
            printf("%2i ", matriz2[k][l]);
        }
        printf("\n");  
    }
    int** matriz_soma = soma_matriz(matriz, matriz2, linha, coluna);
    if(matriz_soma == NULL){
        printf("Erro de alocação");
        return 1;
    }
    for(int g = 0; g < linha; g++){
        free(matriz[g]);
    }
    free(matriz);
        for(int h = 0; h < linha; h++){
        free(matriz2[h]);
    }
    free(matriz2);
    printf("A soma das matrizes e: \n");
    for(int m = 0; m < linha; m++){
        for(int n = 0; n < coluna; n++){
            printf("%2i ", matriz_soma[m][n]);
        }
        printf("\n");  
    }
    for(int p = 0; p < linha; p++){
        free(matriz_soma[p]);
    }
    free(matriz_soma);
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

int** cria_matriz2(int lin, int col){
    int** mat2 = (int**) malloc(lin * sizeof(int*));
    if(mat2 == NULL) return NULL;
    for(int k = 0; k < lin; k++){
        mat2[k] = (int*) malloc(col * sizeof(int));
        if(mat2[k] == NULL) return NULL;
    }
    printf("Preencha a sua matriz com numeros inteiros: \n");
    for(int m = 0; m < lin; m++){
        for(int n = 0; n < col; n++){
            scanf("%i", &mat2[m][n]);
        }
    }
    return mat2;
}
int** soma_matriz(int** mat1, int** mat2, int lin, int col){
    int** soma_mat = (int**) malloc(lin * sizeof(int*));
    if(soma_mat== NULL) return NULL;
    for(int i = 0; i < lin; i++){
        soma_mat[i] = (int*) malloc(col * sizeof(int));
        if(soma_mat[i] == NULL) return NULL;
    }
    for(int j = 0; j < lin; j++){
        for(int k = 0; k < col; k ++){
            soma_mat[j][k] = mat1[j][k] + mat2[j][k];
        }
    }
    return soma_mat;
}