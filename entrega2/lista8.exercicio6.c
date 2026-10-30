/*6. Vamos supor que várias pedras do jogo de xadrez estão no tabuleiro. Para facilitar a
indicação das peças, vamos convencionar:
O tabuleiro é o seguinte:
1 – peões 3 – torres 5 – reis 0 – ausência de peças
2 – cavalos 4 – bispos 6 – rainhas
a) Construa um programa que determine a soma total de peões e bispos e a quantidade
de posições com ausência de peças;
b) Escreva outro programa que determine qual a quantidade de cada tipo de peça no
tabuleiro.*/
#include <stdio.h>
#include <stdlib.h>
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
int main(){
    int** matriz = aloca_matriz(8, 8);
    if(matriz == NULL){
        printf("Erro de alocacao\n");
        return 1;
    }
    matriz[0][0] = 1; matriz[0][1] = 3; matriz[0][2] = 0; matriz[0][3] = 5; matriz[0][4] = 4; matriz[0][5] = 0; matriz[0][6] = 2; matriz[0][7] = 1;
    matriz[1][0] = 1; matriz[1][1] = 0; matriz[1][2] = 1; matriz[1][3] = 0; matriz[1][4] = 0; matriz[1][5] = 1; matriz[1][6] = 0; matriz[1][7] = 0;
    matriz[2][0] = 0; matriz[2][1] = 0; matriz[2][2] = 0; matriz[2][3] = 0; matriz[2][4] = 1; matriz[2][5] = 0; matriz[2][6] = 6; matriz[2][7] = 0;
    matriz[3][0] = 1; matriz[3][1] = 0; matriz[3][2] = 0; matriz[3][3] = 1; matriz[3][4] = 1; matriz[3][5] = 0; matriz[3][6] = 0; matriz[3][7] = 1;
    matriz[4][0] = 0; matriz[4][1] = 1; matriz[4][2] = 0; matriz[4][3] = 4; matriz[4][4] = 0; matriz[4][5] = 0; matriz[4][6] = 1; matriz[4][7] = 0;
    matriz[5][0] = 0; matriz[5][1] = 0; matriz[5][2] = 3; matriz[5][3] = 1; matriz[5][4] = 0; matriz[5][5] = 0; matriz[5][6] = 1; matriz[5][7] = 1;
    matriz[6][0] = 1; matriz[6][1] = 0; matriz[6][2] = 6; matriz[6][3] = 6; matriz[6][4] = 0; matriz[6][5] = 0; matriz[6][6] = 1; matriz[6][7] = 0;
    matriz[7][0] = 1; matriz[7][1] = 0; matriz[7][2] = 5; matriz[7][3] = 0; matriz[7][4] = 1; matriz[7][5] = 1; matriz[7][6] = 0; matriz[7][7] = 6;
    int peoes = 0, cavalos = 0, torres = 0, bispos = 0, reis = 0, rainhas = 0, ausentes = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(matriz[i][j] == 1) peoes++;
            if(matriz[i][j] == 2) cavalos++;
            if(matriz[i][j] == 3) torres++;
            if(matriz[i][j] == 4) bispos++;
            if(matriz[i][j] == 5) reis++;
            if(matriz[i][j] == 6) rainhas++;
            if(matriz[i][j] == 0) ausentes++;
        }
    }
    printf("\nExistem: %i peoes", peoes);
    printf("\nExistem: %i cavalos", cavalos);
    printf("\nExistem: %i torres", torres);
    printf("\nExistem: %i bispos", bispos);
    printf("\nExistem: %i reis", reis);
    printf("\nExistem: %i rainhas", rainhas);
    printf("\nExistem: %i pecas ausentes", ausentes);
    libera_matriz(matriz, 8);
    return 0;
}