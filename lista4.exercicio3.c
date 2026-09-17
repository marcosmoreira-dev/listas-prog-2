/*O que será impresso na tela pelo seguinte programa:
int main()
{
int numbers[5];
int *p;
int n;
p = numbers;
*p = 10;
p++;
*p = 20;
p = &numbers[2];
*p = 30;
p = numbers + 3;
*p = 40;
p = numbers;
*(p + 4) = 50;
for (n = 0; n < 5; n++)
printf(“%d”, numbers[n]);
}*/
#include <stdio.h>
int main(){
    int numbers[5];
    int *p;
    int n;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;
    for (n = 0; n < 5; n++){
         printf("%d", numbers[n]);
    }
    printf("\nSera mostrado 1020304050.\np aponta para a posicao 0 de numbers e depois atribui 10,\ndepois avanca mais uma posicao com p++ e atribui 20 repetindo esse\nprocesso (de maneiras diferentes) ate a quinta posicao(numbers[4]) onde atribui 50.\nApos isso, usa um loop for para imprimir os elementos desse vetor.");
    return 0;    
}
