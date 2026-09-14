/* Faça operações de arredondamento para cima e para baixo com números float. Dica:
Pesquise o documento “Cartão de Referência da Linguagem C” para encontrar quais
funções devem ser usadas no programa. */ 

#include <stdio.h>
#include <math.h>

int main() {
    float numero;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    printf("Arredondado para cima: %.0f\n", ceil(numero));
    printf("Arredondado para baixo: %.0f\n", floor(numero));

    return 0;
}

