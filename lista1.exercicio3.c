/* Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois números 
reais. O programa deve retornar o resultado da operação 
recebida sobre estes dois números.*/

#include<stdio.h>
int main(){
    float a, b, op;
    char sinal;
    printf("Insira dois números: \n");
    scanf("Insira um sinal: \n");
    gets(sinal); -> scanf(" %c", &sinal);
    if (sinal=='+'){
        float soma = a+b;
        op=soma;
    }else if(sinal=='-'){
        float sub = a-b;
        op=sub;
    }else if(sinal=='*'){
        float mult = a*b;
        op=mult;
    }else if(sinal=='/'){
        float div = a/b;
        op=div;
    }
    printf("Esse é o resultado da operação: %f\n", op);
    return 0;
}
