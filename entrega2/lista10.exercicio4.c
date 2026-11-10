/* 4) Faça um programa que leia um nome de “arquivo .c” digitado pelo usuário e gere um
novo que remove as linhas com comentários “//”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 1024

int main() {
    char nomeEntrada[256];
    char nomeSaida[256];
    char linha[TAM_LINHA];
    FILE *origem, *destino;

    printf("Digite o nome do arquivo .c (ex: programa.c): ");
    if (scanf("%255s", nomeEntrada) != 1) {
        printf("Erro ao ler o nome do arquivo.\n");
        return 1;
    }

    origem = fopen(nomeEntrada, "r");
    if (origem == NULL) {
        printf("Erro ao abrir o arquivo '%s'. Verifique se ele existe.\n", nomeEntrada);
        return 1;
    }

    snprintf(nomeSaida, sizeof(nomeSaida), "sem_comentarios_%s", nomeEntrada);

    destino = fopen(nomeSaida, "w");
    if (destino == NULL) {
        printf("Erro ao criar o arquivo de saída '%s'.\n", nomeSaida);
        fclose(origem);
        return 1;
    }

    while (fgets(linha, sizeof(linha), origem) != NULL) {
        if (strstr(linha, "//") == NULL) {
            fputs(linha, destino);
        }
    }

    printf("Arquivo processado com sucesso! Salvo como: %s\n", nomeSaida);

    fclose(origem);
    fclose(destino);

    return 0;
}