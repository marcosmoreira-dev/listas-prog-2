/* Considerando a existência de notas (cédulas) nos valores R$ 100, R$ 50, R$ 20, R$ 10,
R$ 5, R$ 2 e R$ 1, escreva um programa que capture um valor inteiro em reais (R$) e
determine o menor número de notas para se obter o montante fornecido. A função deve
ter o seguinte protótipo:
int total_de_notas(int valor); */


#include <stdio.h>

int total_de_notas(int valor);


int main() {
    
    int valor, resultado;
    printf("Digite o número desejado: ");
    scanf("%d", &valor);
    
    resultado = total_de_notas(valor);
    printf("Menor numero de notas: %d\n", resultado);
    return 0;
}

int total_de_notas(int valor) {
    
    int total = 0;

    total += valor / 100;
    valor = valor % 100;

    total += valor / 50;
    valor = valor % 50;

    total += valor / 20;
    valor = valor % 20;

    total += valor / 10;
    valor = valor % 10;

    total += valor / 5;
    valor = valor % 5;

    total += valor / 2;
    valor = valor % 2;

    total += valor / 1;

    return total;
    
}