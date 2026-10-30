/*A distância entre várias cidades é dada pela tabela abaixo (em km):
a) Construa um programa que leia a tabela acima e informe ao usuário a distância entre
duas cidades por ele requisitadas, até que ele entre com o código 0 para ambas as
cidades;
b) Elabore um programa que imprima a tabela sem repetições, isto é, se a distância
entre as cidades 1 e 3 foi impressa, não é necessário imprimir a distância entre 3 e 1;
c) Dado um determinado percurso, imprima o total percorrido:
Exemplo: dado o percurso 1, 2, 3, 2, 5, 1, 4, teremos:
15 + 10 + 10 + 28 + 12 + 5 = 80 km.*/
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
int** marcador(int* lin_mar, int** matriz_marcador, int c1, int c2){
    (*lin_mar)++;
    int aux = *lin_mar;
    if(aux > 1){
        matriz_marcador = realloc(matriz_marcador, aux * sizeof(int*));
        matriz_marcador[aux - 1] = (int*) malloc(2 * sizeof(int));
        matriz_marcador[aux - 1][0] = c1;
        matriz_marcador[aux - 1][1] = c2;
    }
    else{
        matriz_marcador[aux - 1][0] = c1;
        matriz_marcador[aux - 1][1] = c2;
    }
    return matriz_marcador;
}
int checa_repeticao(int** matriz_marcador, int c1, int c2, int lin_mar){
    int aux = lin_mar;
    int aux1, aux2;
    for(int i = 0; i < aux; i++){
        aux1 = matriz_marcador[i][0];
        aux2 = matriz_marcador[i][1];
        if((aux1 == c1 && aux2 == c2) || (aux1 == c2 && aux2 == c1)) return 1;
    }
    return 0;
}
void mostra_matriz_semrepeticao(int** mat, int lin){
    for(int i = 0; i < lin; i++) {
        for(int j = i + 1; j < lin; j++) { // j começa em i + 1
            printf("Cidade %d ate Cidade %d: %d \n", i + 1, j + 1, mat[i][j]);
        }
    }
}
int main(){
    int linha, coluna, distancia, linha_marcador = 0, opcao, soma;
    int** matriz_marca = aloca_matriz(1,2);
    int** mapa_matriz = aloca_matriz(5,5);
    mapa_matriz[0][0] = 0; mapa_matriz[0][1] = 15; mapa_matriz[0][2] = 30; mapa_matriz[0][3] = 5; mapa_matriz[0][4] = 12;
    mapa_matriz[1][0] = 15; mapa_matriz[1][1] = 0; mapa_matriz[1][2] = 10; mapa_matriz[1][3] = 17; mapa_matriz[1][4] = 28;
    mapa_matriz[2][0] = 30; mapa_matriz[2][1] = 10; mapa_matriz[2][2] = 0; mapa_matriz[2][3] = 3; mapa_matriz[2][4] = 11;
    mapa_matriz[3][0] = 5; mapa_matriz[3][1] = 17; mapa_matriz[3][2] = 3; mapa_matriz[3][3] = 0; mapa_matriz[3][4] = 80;
    mapa_matriz[4][0] = 12; mapa_matriz[4][1] = 28; mapa_matriz[4][2] = 11; mapa_matriz[4][3] = 80; mapa_matriz[4][4] = 0;
    while(1){
    printf("1. Distancia entre duas cidades\n");
    printf("2. Percurso\n");
    printf("3. Mostrar\n");
    printf("4. Sair\n");
    scanf("%i", &opcao);
    if(opcao == 1){
        while(1){
            printf("\nDigite duas cidades(coloque 0 duas vezes para parar): \n");
            while(1){
                scanf("%i", &linha);
                if(linha >= 0 && linha <= 5) break;
                else printf("\nInvalido\n");
            }
            printf("Cidade 1: %i\n", linha);
            while(1){
                scanf("%i", &coluna);
                if(coluna >= 0 && coluna <= 5) break;
                else printf("\nInvalido\n");
            }
            printf("Cidade 2: %i\n", coluna);
            if(linha == 0 && coluna == 0) break;
            if(linha == 0 || coluna == 0){
                printf("Invalido\n");
                continue;
            }
            if(checa_repeticao(matriz_marca, linha, coluna, linha_marcador)) printf("\nDistancia ja impressa\n");
            else{
                printf("Distancia entre as duas cidades: %i", mapa_matriz[linha - 1][coluna - 1]);
                matriz_marca = marcador(&linha_marcador, matriz_marca, linha, coluna);
            }
        }
    }
    else if(opcao == 2){
        printf("\nPercurso\n");
        soma = 0;
        printf("Digite a cidade de partida (1 a 5): ");
        while(1){
            scanf("%i", &linha);
            if(linha >= 1 && linha <= 5) break;
            else printf("Invalido! Digite entre 1 e 5: ");
        }
        printf("Digite as proximas cidades do percurso (digite 0 para encerrar):\n");
        while(1){
            while(1){
                scanf("%i", &coluna);
                if(coluna >= 0 && coluna <= 5) break;
                else printf("Invalido! Digite entre 1 e 5 (ou 0 para encerrar): ");
                }
                if(coluna == 0) break;
                soma += mapa_matriz[linha - 1][coluna - 1];
                linha = coluna;
            }
            printf("Percurso total percorrido: %i \n", soma);
    }
    else if(opcao == 3){
        mostra_matriz_semrepeticao(mapa_matriz, 5);
    }
    else break;
    }
    libera_matriz(mapa_matriz, 5);
    if (linha_marcador == 0) {
    free(matriz_marca[0]);
    free(matriz_marca);
    } 
    else libera_matriz(matriz_marca, linha_marcador);
    return 0;
}