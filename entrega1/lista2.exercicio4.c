/*4. Escreva um programa que sorteie uma letra do alfabeto de ‘a’ a ‘z’ e o usuário é perguntado qual é essa letra. O programa deve informar se a letra é maior ou menor e quando o usuário a acertou.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Inicializa o gerador para sortear letras diferentes a cada execucao

    char sorteada = 'a' + (rand() % 26);
    char palpite;

    do {
        printf("Digite uma letra: \n");
        scanf(" %c", &palpite);

        if (palpite < sorteada) {
            printf("A letra sorteada é maior que o seu palpite.");
        } else if (palpite > sorteada) {
            printf("A letra sorteada é menor que o seu palpite.");
        } else if (palpite == sorteada) {
            printf("Você acertou!");
            break;
        }
    } while (palpite != sorteada);
    
    return 0;
}
