/*Elabore um programa que, dado 2 vetores inteiros de 20 posições, efetue as respectivas
operações indicadas por um terceiro vetor de caracteres de 20 posições também fornecido pelo
usuário, contendo as quatro operações aritméticas em qualquer combinação, armazenando os
resultados num quarto vetor.*/
#include <stdio.h>
void operacao_vetores(int* v1, int* v2, float* r, char* op);
int main(){
    int vetor1[20], vetor2[20];
    float resultados[20];
    printf("Digite os valores do primeiro vetor: \n");
    for(int i = 0; i < 20; i++){
        scanf("%i", &vetor1[i]);
    }
    printf("Digite os valores do segundo vetor: \n");
    for(int j = 0; j < 20; j++){
        scanf("%i", &vetor2[j]);
    }
    char operacoes[20];
    printf("Digite as operacoes: \n");
    for(int k = 0; k < 20; k++){
    scanf(" %c", &operacoes[k]);
    }
    operacao_vetores(vetor1, vetor2, resultados, operacoes);
    for(int l = 0; l < 20; l++){
    printf("%i %c %i = %.2f\n", vetor1[l], operacoes[l], vetor2[l], resultados[l]);
    }
    return 0;
}
void operacao_vetores(int* v1, int* v2, float* r, char* op){
    char operador;
    for(int m = 0; m < 20; m++){
        operador = op[m];
        if(operador == '+')r[m] = v1[m] + v2[m];
        if(operador == '-')r[m] = v1[m] - v2[m];
        if(operador == '*')r[m] = v1[m] * v2[m];
        if(operador == '/'){
            if(v2[m] == 0)r[m] = 0;
            else r[m] = (float)v1[m] / v2[m];
        }
    }
}
