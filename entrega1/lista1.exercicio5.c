/*Defina as variáveis a, b e c (tipo de dado) para obter todas as 
possíveis respostas para os 
valores de ‘c’:
Suponha que:
a = 3
b = a / 2       
c = b + 3.1      
Valores possíveis para ‘c’?
1. c = 4.6
2. c = 4.1
3. c = 4
*/

#include<stdio.h>
int main(){
    // Primeiro caso
    float a, b, c;
    a = 3;
    b = a/2;
    c = b + 3.1;
    printf(" Primeiro resultado de C: %f\n", c);
    // Segundo caso
    int a, b;
    float c;
    a = 3;
    b = a/2;
    c = b + 3.1;
    printf("Segundo resultado de C: %f\n", c);
    // Terceiro caso
    int a, b, c;
    a = 3;
    b = a/2;
    c = b + 3.1;
    printf("Terceiro resultado de C: %d\n", c);
    return 0; 
}
