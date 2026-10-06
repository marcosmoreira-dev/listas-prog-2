/*2. Faça um programa que calcule e imprima a soma dos n primeiros números naturais ímpares. O usuário do programa deve fornecer quantos números devem ser somados.*/

#include <stdio.h>

int calcula_soma(int n) {  
    int soma = 0;
    int impar;
    
    for (int i = 1; i <= n; i++) {
        impar = 2 * i - 1;
        soma = soma + impar;
    }

    return soma;
}

int main(void) {
    int n;
    int resultado;

    printf("Quantos numeros impares voce quer somar? ");
    scanf("%d", &n);

    resultado = calcula_soma(n);

    printf("A soma dos %d primeiros impares e: %d\n", n, resultado);

    return 0;
}