/* 7) Um arquivo do tipo texto, chamado ‘‘numeros.txt’’ contém uma quantidade
desconhecida de números reais. Escreva um programa que leia estes números, os coloque
em ordem crescente e depois os grave em um arquivo binário chamado ‘‘numeros.bin’’.
*/

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    double diff = *(double*)a - *(double*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    FILE *arquivoTexto = fopen("numeros.txt", "r");
    if (arquivoTexto == NULL) {
        printf("Erro ao abrir o arquivo numeros.txt\n");
        return 1;
    }

    int capacidade = 10;
    int qtd = 0;
    double *numeros = (double*) malloc(capacidade * sizeof(double));

    if (numeros == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivoTexto);
        return 1;
    }

    double valor;
    while (fscanf(arquivoTexto, "%lf", &valor) == 1) {
        if (qtd >= capacidade) {
            capacidade *= 2;
            double *temp = (double*) realloc(numeros, capacidade * sizeof(double));
            if (temp == NULL) {
                printf("Erro ao realocar memória.\n");
                free(numeros);
                fclose(arquivoTexto);
                return 1;
            }
            numeros = temp;
        }
        numeros[qtd++] = valor;
    }
    fclose(arquivoTexto);

    if (qtd == 0) {
        printf("Nenhum número foi lido do arquivo.\n");
        free(numeros);
        return 0;
    }

    qsort(numeros, qtd, sizeof(double), comparar);

    FILE *arquivoBinario = fopen("numeros.bin", "wb");
    if (arquivoBinario == NULL) {
        printf("Erro ao criar o arquivo numeros.bin\n");
        free(numeros);
        return 1;
    }

    fwrite(numeros, sizeof(double), qtd, arquivoBinario);
    fclose(arquivoBinario);

    printf("Sucesso! %d números foram ordenados e gravados em 'numeros.bin'.\n", qtd);

    free(numeros);
    return 0;
}