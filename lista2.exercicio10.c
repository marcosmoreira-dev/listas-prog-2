/*O maior divisor comum (MDC) de dois números inteiros é o maior número inteiro
que faz uma divisão exata (com resto zero) desses dois números. Por exemplo, o MDC de
32 e 40 é 8, o MDC de 9 e 27 é 9 e o MDC de 13 e 25 é 1. Implemente uma função que
receba como parâmetros dois números inteiros x e y e calcule o MDC desses números.
Essa função deve ter o seguinte protótipo:
int mdc (int x, int y);*/
#include <stdio.h>
int mdc(int x, int y);
int main(){
int x,y,valor_mdc;
printf("Digite dois numero inteiros: \n");
scanf("%i", &x);
scanf("%i", &y);
valor_mdc = mdc(x,y);
printf("O MDC entre %i e %i: %i", x,y,valor_mdc);
return 0;
}
int mdc(int x, int y){
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    int aux;
    while(y != 0){
        aux = x % y;
        x = y;
        y = aux;
    }
    return x;
}
