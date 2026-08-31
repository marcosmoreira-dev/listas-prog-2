/* 3. Faça um programa que imprima os n primeiros termos da série de Fibonacci, lembrando que esta série é definida da seguinte forma:
termo1 = 1
termo2 = 1
termon = termon−1 + termon−2
O usuário do programa deve fornecer o número de termos, e estes devem ser impressos separados por um espaço. Por exemplo, se o usuário pedir os 6 primeiros termos da série de Fibonacci, o programa deve ter a seguinte saída:
1 1 2 3 5 8 */

// proximo = atual + anterior

#include <stdio.h>

void calcula_fibonacci(int n);

int main(void) {
    int numero;

    printf("Digite a quantidade de termos para calcular o Fibonacci: ");
    scanf("%d", &numero);

    calcula_fibonacci(numero);

    return 0;
}

void calcula_fibonacci(int n) {
    if (n <= 0) {
        return;
    }

    int a = 1;
    int b = 1;
    int proximo;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d", a);
        } else if (i == 2) {
            printf(" %d", b);
        } else {
            proximo = a + b;
            printf(" %d", proximo);
            a = b;
            b = proximo;
        }
    }
}
