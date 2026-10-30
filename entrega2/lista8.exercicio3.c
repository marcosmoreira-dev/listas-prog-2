/*3. Sabendo que:
E ainda sabendo que uma matriz simétrica é aquela em que a matriz original é igual a
sua transposta, faça uma função que identifique se uma matriz é simétrica. Utilize
funções para cada atividade do programa.*/
#include <stdio.h>
#include <stdlib.h>
int** aloca_matriz(int lin, int col);
int** cria_matriz(int lin, int col);
void libera_matriz(int** mat, int lin);
void mostra_matriz(int** mat, int lin, int col);
int** transposta_matriz(int** mat, int lin, int col);
int identifica_matriz_simetrica(int** mat, int** mat_tra, int lin, int col);
int** aloca_matriz(int lin, int col){
    int** mat = (int**) malloc(lin * sizeof(int*));
    if(mat == NULL) return NULL;
    for(int i = 0; i < lin; i++){
        mat[i] = (int*) malloc(col * sizeof(int));
        if(mat[i] == NULL) return NULL;
    }
    return mat;
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
void libera_matriz(int** mat, int lin){
    for(int i = 0; i < lin; i++){
        free(mat[i]);
    }
    free(mat);
}
void mostra_matriz(int** mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%2i ", mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Crie sua matriz: \n");
    int linha, coluna;
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
    int** matriz = cria_matriz(linha, coluna);
    if(matriz == NULL){
        printf("Erro de alocacao\n");
        return 1;
    }
    printf("MATRIZ ORIGINAL: \n");
    mostra_matriz(matriz, linha, coluna);
    int** matriz_trans = transposta_matriz(matriz, linha, coluna);
    if(matriz_trans == NULL){
        printf("Erro de alocacao\n");
        libera_matriz(matriz, linha);
        return 1;
    }
    printf("\nMATRIZ TRANSPOSTA; \n");
    mostra_matriz(matriz_trans, coluna, linha);
    if(identifica_matriz_simetrica(matriz, matriz_trans, linha, coluna)) printf("\nE simetrica\n");
    else printf("\nNao e simetrica\n");
    libera_matriz(matriz, linha);
    libera_matriz(matriz_trans, coluna);
    return 0;
}
int** transposta_matriz(int** mat, int lin, int col){
    int** mat_tra = aloca_matriz(col, lin);
    if(mat_tra == NULL) return NULL;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j ++){
            mat_tra[i][j] = mat[j][i];
        }
    }
    return mat_tra;
}
int identifica_matriz_simetrica(int** mat, int** mat_tra, int lin, int col){
    if(lin != col) return 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] != mat_tra[i][j]) return 0;
        }
    }
    return 1;
}
