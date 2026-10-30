/*Uma instituição de pesquisa recolheu amostras de estados brasileiros a respeito do
salário da população. Tendo o seguinte código:
char * estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};
typedef struct assalariados {
char nome[51];
char sexo;
int idade;
float salario;
char estado[3];
} Assalariados;
Assalariados * cadastra(char *nome, char sexo, int idade, float
salario, char *estado);
void relatorio(Assalariados ** ptr, int numAssalariados);
void imprime(Assalariados ** ptr, int numAssalariados);
main(void) {
Assalariados **pessoas;
int numAssalariados=3;
pessoas = (Assalariados **) malloc (numAssalariados *
sizeof(Assalariados *));
pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
imprime(pessoas, numAssalariados);
relatorio(pessoas,numAssalariados);
}
a. Implemente a função cadastra, que atribui os parâmetros recebidos aos campos da
estrutura Assalariados.
b. Implemente a função imprime, que imprime todos os elementos do vetor de
Assalariados.
c. Implemente a função relatório, que imprime a quantidade de homens por estado com
mais de 40 anos que recebem salários superiores a R$ 1000,00. Caso a quantidade no
estado analisado seja zero, então não imprime nada. A mensagem de impressão deve ser:
Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};
typedef struct assalariados {
char nome[51];
char sexo;
int idade;
float salario;
char estado[3];
} Assalariados;
Assalariados * cadastra(char *nome, char sexo, int idade, float
salario, char *estado){
    Assalariados * vetor = (Assalariados*) malloc(sizeof(Assalariados));
    strcpy(vetor->nome, nome);
    strcpy(vetor->estado, estado);
    vetor->sexo = sexo;
    vetor->idade = idade;
    vetor->salario = salario;
    return vetor;
}
void imprime(Assalariados ** ptr, int numAssalariados){
    printf("Elementos do vetor assalariados\n");
    for(int i = 0; i < numAssalariados;i++){
        printf("Nome: %s\n", ptr[i]->nome);
        printf("Sexo: %c\n", ptr[i]->sexo);
        printf("Idade: %i\n", ptr[i]->idade);
        printf("Salario: R$%.2f\n", ptr[i]->salario);
        printf("Estado: %s\n", ptr[i]->estado);
    }
}
void relatorio(Assalariados ** ptr, int numAssalariados){
    for(int j = 0; j < 27; j++){
        int conta_homem = 0;
        for(int k = 0; k < numAssalariados; k++){
            if(strcmp(ptr[k]->estado, estado[j]) == 0 && ptr[k]->salario > 1000 && ptr[k]->sexo == 'M' && ptr[k]->idade > 40) conta_homem++;
        }
        if(conta_homem > 0){
            printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n", estado[j], conta_homem);
        }
    }
}
int main(){
    Assalariados **pessoas;
    int numAssalariados=3;
    pessoas = (Assalariados **) malloc (numAssalariados *
    sizeof(Assalariados *));
    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    imprime(pessoas, numAssalariados);
    relatorio(pessoas,numAssalariados);
    for (int i = 0; i < numAssalariados; i++) {
    free(pessoas[i]);
    }
    free(pessoas);
    return 0;
}