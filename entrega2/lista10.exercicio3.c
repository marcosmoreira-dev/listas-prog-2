/* 3) Considere um arquivo texto com as notas dos alunos de uma disciplina. Cada linha do
arquivo contém a matrícula de um aluno (cadeia de nove caracteres), seguida pelos
valores de suas três notas (P1, P2 e P3). Considere ainda que não existem linhas em
branco no arquivo. Um exemplo desse formato é mostrado abaixo.
9010087-2 2.0 4.3 6.5
8820324-3 7.0 8.2 8.5
9210478-5 6.0 7.5 7.8
9020256-8 3.0 0.5 4.2
Escreva uma função que receba como parâmetros o número de matrícula de um aluno e o
nome de um arquivo com as notas de uma disciplina no formato descrito acima, e retorne
a média do aluno na disciplina. A média de um aluno é calculada pela fórmula
(P1+P2+P3)/3. Caso o número de matrícula passado como parâmetro não seja encontrado
no arquivo, a função deve retornar -1.0. Por exemplo, considerando um arquivo com o
conteúdo apresentado acima, sua função deve retornar 7.9 caso o número de matrícula
passado como parâmetro seja “8820324-3”. O protótipo da função deve ser:
float media (char* mat, char* nome_arquivo);
Obs.: Se não for possível abrir o arquivo de entrada, a função deve imprimir a mensagem
“ERRO” e terminar a execução do programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo);

int main(void) {
    char matricula_busca[] = "8820324-3";
    float resultado = media(matricula_busca, "notas.txt");

    if (resultado != -1.0f) {
        printf("A media do aluno %s eh: %.1f\n", matricula_busca, resultado);
    } else {
        printf("Matricula %s nao encontrada no arquivo.\n", matricula_busca);
    }

    char matricula_inexistente[] = "0000000-0";
    resultado = media(matricula_inexistente, "notas.txt");

    if (resultado != -1.0f) {
        printf("A media do aluno %s eh: %.1f\n", matricula_inexistente, resultado);
    } else {
        printf("Matricula %s nao encontrada no arquivo.\n", matricula_inexistente);
    }

    return 0;
}

float media(char* mat, char* nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char mat_atual[20];
    float p1, p2, p3;

    while (fscanf(fp, "%s %f %f %f", mat_atual, &p1, &p2, &p3) == 4) {
        if (strcmp(mat_atual, mat) == 0) {
            fclose(fp);
            return (p1 + p2 + p3) / 3.0f;
        }
    }

    fclose(fp);
    return -1.0f;
}