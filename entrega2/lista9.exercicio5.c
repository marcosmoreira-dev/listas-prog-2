/*5. Considere um sistema de apoio escolar que armazena as informações sobre as notas dos alunos
de uma turma em um vetor de ponteiros para variáveis do tipo Aluno, descrito a seguir:
5a. Escreva uma função que aloca espaço em memória para n alunos. A função tem o seguinte
protótipo: Aluno ** alocaAlunos(int n);
5b. Escreva uma função que atribui a um determinado elemento do vetor de ponteiros para
estruturas os dados passados como parâmetro. A função recebe o vetor a, o índice do vetor e os
dados a serem preenchidos na estrutura. A função tem o seguinte protótipo:*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct endereco {
char rua[100]; /* Nome da rua */
int numero; /* Numero do imovel */
} Endereco;
typedef struct notas {
float p1, p2, p3; /* Notas nas provas */
} Notas;
typedef struct aluno {
int mat; /* Matricula do aluno */
char nome[81]; /* Nome do aluno */
Notas nota; /* Notas nas provas */
Endereco *end; /* Endereco do aluno */
} Aluno;
Aluno** alocaAlunos(int n){
    Aluno** vetor = (Aluno**) malloc(n * sizeof(Aluno*));
    for(int i = 0; i < n; i++){
        vetor[i] = (Aluno*) malloc(sizeof(Aluno));
        vetor[i]->end = (Endereco*) malloc(sizeof(Endereco));
    }
    return vetor;
}
void atribui(Aluno ** a, int indice, int matricula, char *nome, float nota1, float nota2, float nota3, char *nomeRua, int numero){
    a[indice]->mat = matricula;
    strcpy(a[indice]->nome, nome);
    a[indice]->nota.p1 = nota1;
    a[indice]->nota.p2 = nota2;
    a[indice]->nota.p3 = nota3;
    strcpy(a[indice]->end->rua, nomeRua);
    a[indice]->end->numero = numero;
}
void mostra_alunos(Aluno** a, int n){
    for(int i = 0; i < n; i++){
        printf("\nMatricula: %i\nNome: %s\n", a[i]->mat, a[i]->nome);
        printf("P1: %.2f\nP2: %.2f\nP3: %.2f\n", a[i]->nota.p1, a[i]->nota.p2, a[i]->nota.p3);
        printf("Endereco: %s\nNumero: %i\n", a[i]->end->rua, a[i]->end->numero);
    }
}
int main(){
Aluno **alunos;
alunos = alocaAlunos(3);
atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);
mostra_alunos(alunos, 3);
for(int j = 0; j < 3; j ++){
    free(alunos[j]->end);
    free(alunos[j]);
}
free(alunos);
return 0;
}