/* 1. Faça um programa que verifique se um determinado número é primo. O número a ser testado deve ser fornecido pelo usuário do programa. O programa deve imprimir a mensagem “NUMERO PRIMO” caso o número seja primo, e “NUMERO NAO PRIMO” caso contrário. */

#include <stdio.h>
#include <stdbool.h>

bool eh_primo(int a) {
    if (a <= 1){
        return false;
    }

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int numero;
    
    printf("Digite um numero para testar se ele e primo: ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrada invalida. \n");
        return 1;
    }

    if (eh_primo(numero)) {
        printf("NUMERO PRIMO");
    } else {
        printf("NUMERO NÃO PRIMO");
    };
    
    return 0;
};
