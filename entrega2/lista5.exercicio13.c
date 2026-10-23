/*13. Faça um programa que demonstre o uso de 3 funções da biblioteca string.h que ainda não
tenham sido usadas em listas de exercícios da disciplina.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    printf("Funcao: strstr\n");
    char texto[] = "Eu gosto de bolo";
    char busca[] = "gosto";
    char *posicao = strstr(texto, busca);
    if (posicao != NULL){
        printf("Texto: %s\n", texto);
        printf("Palavra '%s' encontrada a partir da posicao: %s\n" ,busca, posicao);
    }
    else printf("Palavra nao encontrada.\n\n");
    printf("Funcao strtok\n");
    char string_dados[] = "Pedro;25 anos;Engenharia;Niteroi";
    const char delimitador[] = ";";
    printf("String original: %s\n", string_dados);
    printf("Dados fatiados:\n");
    char *slice = strtok(string_dados, delimitador);
    int contador = 1;
    while (slice != NULL){
        printf("  Campo %i: %s\n", contador++, slice);
        slice = strtok(NULL, delimitador);
    }
    printf("Funcao memset\n");
    char *preencher = (char*) malloc(30 * sizeof(char));
    if (preencher == NULL) return 1;
    memset(preencher, '*', 29);
    preencher[29] = '\0';
    printf("Apos ser preenchido com o memset: %s\n", preencher);
    memset(preencher, 0, 30);
    printf("Comprimento apos o 'reset': %i\n", strlen(preencher));
    free(preencher);
    return 0;
}