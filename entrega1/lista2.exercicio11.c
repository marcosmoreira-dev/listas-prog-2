/* Faça um algoritmo para ler dois números inteiros e 
calcular e mostrar o valor resultante se elevarmos a base
 representada pelo primeiro à potência representada pelo 
 segundo. Dica: busque qual a função que faz a potenciação.
*/

#include <stdio.h>
#include <math.h>

int main(){
    int base, exp, conta;

    printf("Digite um valor para a base da exponenciação: \n");
    scanf("%d", &base);
    printf("Digite um valor para o expoente: \n");
    scanf("%d", &exp);

    conta=pow(base,exp);

    printf("Resultado: %d \n", conta);
    return 0;
}
