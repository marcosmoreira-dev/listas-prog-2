/* 2) Considere um arquivo texto onde cada linha contém a matrícula de um aluno e seu
respectivo CR, como ilustra o exemplo a seguir:
9010087-2 7.3
8820324-3 8.7
9210478-5 9.2

9020256-8 6.7
Implemente uma função que receba como parâmetros o nome de um arquivo no formato
descrito acima e a matrícula de um aluno, e retorne o CR do aluno. Se não for encontrado
no arquivo a matrícula procurada, a função deve retornar –1.0. Se não for possível abrir o
arquivo, a função deve imprimir a mensagem "ERRO" e terminar a execução do
programa. O protótipo dessa função deve ser:
float busca (char* arquivo, char* matricula);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula);

int main() {
    char nome_arquivo[] = "alunos.txt";
    char matricula_procurada[] = "8820324-3";

    float cr = busca(nome_arquivo, matricula_procurada);

    if (cr != -1.0) {
        printf("CR do aluno %s: %.1f\n", matricula_procurada, cr);
    } else {
        printf("Matrícula %s não encontrada no arquivo.\n", matricula_procurada);
    }

    return 0;
}

float busca(char* arquivo, char* matricula) {
    FILE *fp = fopen(arquivo, "r");
    
    if (fp == NULL) {
        printf("ERRO\n");
        exit(1);
    }
    
    char mat_lida[20];
    float cr;
    
    while (fscanf(fp, "%s %f", mat_lida, &cr) == 2) {
        if (strcmp(mat_lida, matricula) == 0) {
            fclose(fp);
            return cr; 
        }
    }
    
    fclose(fp);
    return -1.0; 
}