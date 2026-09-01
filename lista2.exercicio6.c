/*Fazer um programa que sorteie um número de 0 a 100 e que permita que o usuário
(sem conhecer o número sorteado) tente acertar. Caso não acerte, o programa deve
imprimir uma mensagem informando se o número sorteado é maior ou menor que a
tentativa feita. Ao acertar o número, o programa deve imprimir a quantidade de tentativas
feitas.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int sortearnumero0_100(void);
int main(int){
int num_user,num_sort,condicao,opcao;
condicao = 1;
printf("Tente adivinhar o numero (0-100): \n");
while(condicao){
    printf("Digite um numero(0-100): \n");
    scanf("%i", &num_user);
    num_sort = sortearnumero0_100();
    while(num_user != num_sort){
        system("cls");
        if(num_user < 0 || num_user > 100){
            printf("Invalido! Tente Novamente: \n");
            scanf("%i", &num_user);
        }
        else if(num_user < num_sort){
            printf("O numero sorteado e maior. Tente Novamente: \n");
            scanf("%i", &num_user);
        }
        else{
            printf("O numero sorteado e menor. Tente Novamente: \n");
            scanf("%i", &num_user);
        }
    }
    printf("Acertou! \n");
    printf("Jogar novamente? \n");
    printf("1. Sim \n");
    printf("2. Nao \n");
    scanf("%i", &opcao);
    if(opcao == 1) continue;
    else break;
}
return 0;
}
int sortearnumero0_100(void){
    srand(time(NULL));
    int n = rand() % 101;
    return n;
}

