/*11. Criar um tipo Aluno e um tipo Materia tal como dado abaixo:
(A) Criar uma função Aluno* fillAluno() que preenche os campos da estrutura do tipo Aluno com
dados fornecidos pelo usuário.
(B) Criar uma função Materia * fillMateria(int numAlunos) que preenche os campos da estrutura
do tipo Materia realizando chamadas a função fillAluno em um número de vezes igual ao número
contido na variável numAlunos.
(C) Criar uma função void mediaMateria(Materia *m1) que fornece a média de cada prova do
ano para os alunos contidos na variável m1 e assim preenche o campo media de m1.
(D) Criar uma função void mostraMateria(Materia *m1) que mostra as informações dos alunos
contidas na variável m1.
(E) Criar um programa que ilustra o funcionamento das funções anteriores.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Aluno {
int matricula;
float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
char nome[100];
}Aluno;
typedef struct Materia {
Aluno *V; // Armazena a informação de n alunos !!
float media[5]; // Armazena as 5 médias do ano.
int nAlunos; // Número de alunos matriculados no curso.
}Materia;
Aluno* fillAluno(){
    Aluno* a;
    a = (Aluno*) malloc(sizeof(Aluno));
    a->vNotas = (float*) malloc(5 * sizeof(float));
    printf("\nNumero de matricula: \n");
    scanf("%i", &a->matricula);
    printf("\nDigite as 5 notas: \n");
    for(int i = 0; i < 5; i++){
        while(1){
            scanf("%f", &a->vNotas[i]);
            if(a->vNotas[i] <= 10 && a->vNotas[i] >= 0) break;
            else printf("\nNota invalida!\n");
        }
    }
    printf("\nNome do aluno: \n");
    scanf(" %[^\n]", a->nome);
    return a;
}
Materia * fillMateria(int numAlunos){
    Materia* m;
    m = (Materia*) malloc(sizeof(Materia));
    m->nAlunos = numAlunos;
    m->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    for(int j = 0; j < numAlunos; j++){
        Aluno* aux = fillAluno();
        m->V[j] = *aux;
        free(aux);
    }
    return m;
}
void mediaMateria(Materia *m1){
    float soma;
    for(int k = 0; k < 5; k++){
        soma = 0;
        for(int l = 0; l < m1->nAlunos ; l++){
            soma += m1->V[l].vNotas[k];
        }
        m1->media[k] = soma / m1->nAlunos;
    }
}
void mostraMateria(Materia *m1){
    for(int i = 0; i < m1->nAlunos; i++){
        printf("\nMatricula: %i", m1->V[i].matricula);
        for(int j = 0; j < 5; j++){
            printf("\nNota %i: %.2f", j+1, m1->V[i].vNotas[j]);
        }
        printf("\nNome: %s", m1->V[i].nome);
    }
    printf("\nMedias: \n");
    for(int l = 0; l < 5; l++){
        printf("Media %i: %.2f\n", l+1, m1->media[l]);
    }
    printf("\nTotal de alunos: %i\n", m1->nAlunos);
}
int main(){
    int num;
    printf("Deseja adicionar quantos alunos: \n");
    while(1){
        scanf("%i", &num);
        if(num > 0) break;
        else printf("Invalido\n");
    }
    Materia * materia = fillMateria(num);
    mediaMateria(materia);
    mostraMateria(materia);
    for(int j = 0; j < materia->nAlunos; j++){
        free(materia->V[j].vNotas);
    }
    free(materia->V);
    free(materia);
    return 0;
}