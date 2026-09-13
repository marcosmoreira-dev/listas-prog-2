/* Fazer um programa que sorteie um número de 0 a 100 e que 
permita que o usuário (sem conhecer o número sorteado) tente 
acertar. Caso não acerte, o programa deve imprimir uma mensagem
 informando se o número sorteado é maior ou menor que a 
 tentativa feita. Ao acertar o número, o programa deve imprimir
a quantidade de tentativas feitas. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int numero, soma=1;
    srand(time(NULL));
    int sorteado = rand()%101;

    printf("Escreva um número: ");
    scanf("%d", &numero);

    while (numero!=sorteado){
        if (numero>sorteado){
            printf("Chuta mais pra baixo ");
        }else{
            printf("Chuta mais pra cima ");
        }
        scanf("%d", &numero);
        soma = soma + 1;

    }
    printf("Você acertou depois de %d tentativas!", soma);
    return 0;
}


