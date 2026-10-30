/*7. Considere o tipo Aluno, que representa um aluno da disciplina, e o tipo Prova, que representa a
prova de um aluno, ambos descritos a seguir:
O seguinte algoritmo de ordenação bolha foi implementado, utilizando as funções auxiliares
compara e troca, para ordenar um vetor de ponteiros para o tipo Prova:
Essa função ordena o vetor em ordem decrescente de nota da prova --- que equivale à soma das
notas das quatro questões ---, com desempate pela ordem alfabética do nome do aluno. Por 
exemplo, se Maria e Ana tiram 6.0 e Sandra tira 7.0, a ordem deve ser Sandra, Ana e Maria.
Implemente as funções compara e troca de forma que o algoritmo descrito funcione corretamente.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aluno {
int mat; /* Matricula do aluno */
char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;
struct prova {
Aluno a; /* Aluno que fez a prova */
float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;
int compara(Prova * s, Prova* t){
    float nota1 = 0, nota2 = 0;
    nota1 += (s->q1 + s->q2 + s->q3+ s->q4);
    nota2 += (t->q1 + t->q2 + t->q3 + t->q4);
    if(nota1 < nota2) return 1;
    if(nota1 == nota2){
        if(strcmp(s->a.nome, t->a.nome) > 0) return 1;
    }
    return 0;
}
void troca(Prova ** s, Prova** t){
    Prova* aux = *s;
    *s = *t;
    *t = aux;
}
void ordena(int n, Prova** v){
int fim,i;
for(fim=n-1; fim>0; fim--)
for(i=0; i<fim; i++)
if(compara(v[i],v[i+1]))
troca(&v[i],&v[i+1]);
}
int main(){
    Prova a1 = {{1289, "Maria"}, 1.5, 1.5, 1.5, 1.5};
    Prova a2 = {{3183, "Sandra"}, 2.5, 1.5, 1.5, 1.5};
    Prova a3 = {{7126, "Ana"}, 1.5, 1.5, 3, 0};
    Prova* alunos[3] = {&a1, &a2, &a3};
    ordena(3, alunos);
    for(int j = 0; j < 3; j++){
        float nota = (alunos[j]->q1 + alunos[j]->q2 + alunos[j]->q3 + alunos[j]->q4);
        printf("Aluno: %s; Nota: %.2f\n", alunos[j]->a.nome, nota);
    }
    return 0;
}