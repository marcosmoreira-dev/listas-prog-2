/* 1) Considere o tipo Funcionario, que representa um funcionário de uma empresa,
definido pela estrutura a seguir:
struct funcionario {
char nome[81]; /* nome do funcionário 
float valor_hora; /* valor da hora de trabalho em Reais 
int horas_mes; /* horas trabalhadas em um mês 
};
typedef struct funcionario Funcionario;
Escreva uma função em C que preencha um vetor de ponteiros para Funcionario com os
dados lidos de um arquivo texto. Essa função deve receber como parâmetros o vetor de
ponteiros para Funcionario (representado pelo seu comprimento e pelo endereço de seu
primeiro elemento) previamente alocado e o nome do arquivo de entrada. Nesse arquivo
de entrada, os dados de cada funcionário são armazenados em duas linhas: uma com o
seu nome (cadeia com até 80 caracteres), e outra com o valor de sua hora de trabalho e
com o número de horas trabalhadas em um mês (nessa ordem). Um exemplo desse
formato é mostrado abaixo.
João da Silva
15.0 160
Manuel Santos
15.0 80
Fulana de Tal
23.5 40
Considere que: não existem linhas em branco no arquivo; o parâmetro vet já vem com
todas as suas posições inicializadas com NULL; o comprimento do vetor (parâmetro n) é
no mínimo igual à quantidade de registros de funcionários no arquivo de entrada; se não
for possível abrir o arquivo, a função deve imprimir a mensagem “ERRO” e terminar a
execução do programa. A função implementada deve ter o seguinte protótipo:
void carrega (int n, Funcionario** vet, char* arquivo);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[81];       
    float valor_hora;    
    int horas_mes;       
};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo);

int main(void) {
    int n = 10; 

    Funcionario** vet = (Funcionario**) malloc(n * sizeof(Funcionario*));
    if (vet == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        vet[i] = NULL;
    }

    carrega(n, vet, "entrada.txt");

    printf("--- FUNCIONÁRIOS CARREGADOS ---\n");
    for (int i = 0; i < n && vet[i] != NULL; i++) {
        printf("Nome: %s\n", vet[i]->nome);
        printf("Valor/Hora: R$ %.2f\n", vet[i]->valor_hora);
        printf("Horas/Mês: %d\n", vet[i]->horas_mes);
        printf("-------------------------------\n");
    }

    for (int i = 0; i < n; i++) {
        if (vet[i] != NULL) {
            free(vet[i]);
        }
    }
    free(vet);

    return 0;
}

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    int i = 0;
    char nome_temp[81];

    while (i < n && fgets(nome_temp, sizeof(nome_temp), fp) != NULL) {
        size_t len = strlen(nome_temp);
        if (len > 0 && nome_temp[len - 1] == '\n') {
            nome_temp[len - 1] = '\0';
        }

        vet[i] = (Funcionario*) malloc(sizeof(Funcionario));
        if (vet[i] == NULL) {
            fclose(fp);
            exit(1);
        }

        strcpy(vet[i]->nome, nome_temp);

        if (fscanf(fp, "%f %d\n", &vet[i]->valor_hora, &vet[i]->horas_mes) != 2) {
            break;
        }

        i++;
    }

    fclose(fp);
}