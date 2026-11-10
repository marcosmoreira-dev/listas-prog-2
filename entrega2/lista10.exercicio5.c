/* 5) Escreva um programa que leia de um arquivo, cujo nome será fornecido pelo usuário,
um conjunto de números reais e armazene em um vetor. O programa ao final calcula a
media dos números lidos.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 100

int main() {
    char nomeFicheiro[100];
    double vetor[MAX_ELEMENTOS];
    int quantidade = 0;
    double soma = 0.0;
    double media;

    printf("Introduza o nome do ficheiro: ");
    scanf("%99s", nomeFicheiro);

    FILE *ficheiro = fopen(nomeFicheiro, "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro '%s'.\n", nomeFicheiro);
        return 1;
    }

    while (quantidade < MAX_ELEMENTOS && fscanf(ficheiro, "%lf", &vetor[quantidade]) == 1) {
        soma += vetor[quantidade];
        quantidade++;
    }

    fclose(ficheiro);

    if (quantidade > 0) {
        media = soma / quantidade;
        printf("Total de números lidos: %d\n", quantidade);
        printf("A média dos números lidos é: %.2lf\n", media);
    } else {
        printf("Nenhum número válido foi encontrado no ficheiro.\n");
    }

    return 0;
}