/*O cadastro de uma turma de n alunos é representado por um vetor de inteiros,
contendo a matrícula de cada aluno, e um vetor de reais, contendo a nota final de cada
aluno, de tal modo que para uma mesma posição do vetor (mesmo índice), a matrícula e
a nota se referem a um mesmo estudante. Considere que um aluno está aprovado se
tem nota final maior ou igual a 5,0. Escreva uma função que recebe como parâmetros o
inteiro n, o ponteiro mat para o vetor de matrículas, o ponteiro notas para o vetor de
notas e um ponteiro para a variável inteira tam. A função deve contar o número de
alunos aprovados, criar um novo vetor de inteiros alocado dinamicamente com o 
tamanho exato para conter apenas a matrícula desses alunos, e armazenar no novo
vetor as matrículas correspondentes. Finalmente, a função deverá armazenar o
tamanho do novo vetor na variável tam e retornar o ponteiro para seu primeiro
elemento. O protótipo da função é:
int *aprovados(int n, int *mat, float *notas, int *tam);*/
#include <stdio.h>
#include <stdlib.h>
#define media 5
int *aprovados(int n, int *mat, float *notas, int *tam);
int main(){
    int num, tamanho;
    while(1){
        printf("Diga o numero de alunos: \n");
        scanf("%i", &num);
        if(num <= 0) printf("Inválido\n");
        else break;
    }
    int * matriculas = (int *) malloc(num * sizeof(int));
    if(matriculas == NULL){
        printf("Nao foi possivel alocar\n");
        return 1;
    } 
    float * notas = (float *) malloc(num * sizeof(float));
    if(notas == NULL){
        printf("Nao foi possivel alocar\n");
        return 1;
    }
    printf("Diga o numero da matricula desses alunos e a nota: \n");
    for(int i = 0; i < num; i++){
        scanf("%i", &matriculas[i]);
        scanf("%f", &notas[i]);
    }
    int * mat_aprovados = aprovados(num, matriculas, notas, &tamanho);
    if(mat_aprovados == NULL)printf("Erro de alocacao ou invalido!");
    else{
        printf("Os aprovados sao: ");
        for(int j = 0; j < tamanho; j++){
            printf("%i ", mat_aprovados[j]);
        }
        free(mat_aprovados);
    }
    free(matriculas);
    free(notas);
    return 0;
}
int *aprovados(int n, int *mat, float *notas, int *tam){
    *tam = 0;
    int pos = 0;
    for(int k = 0; k < n; k++){
        if(notas[k] >= media) (*tam)++;
    }
    if(*tam == 0) return NULL;
    int * m_aprovados = (int *) malloc(*tam * sizeof(int));
    if(m_aprovados == NULL) return NULL;
    for(int l = 0; l < n; l++){
        if(notas[l] >= media){
            m_aprovados[pos] = mat[l];
            pos++;
        }
    }
    return m_aprovados;
}
