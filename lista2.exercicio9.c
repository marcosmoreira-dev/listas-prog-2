/*Implementar a função INVERTE que recebe um número unsigned int como parâmetro
e retorna este número escrito ao contrário. Ex: 431 <-> 134.*/
#include <stdio.h>
unsigned int inverter_unint(unsigned int numero);
int main(){
unsigned int n;
printf("Digite um numero inteiro positivo: \n");
scanf("%u", &n);
unsigned int num_invertido = inverter_unint(n);
printf("O numero invertido e: %u\n", num_invertido);
return 0;
}
unsigned int inverter_unint(unsigned int numero){
    unsigned int invertido = 0;
    while(numero > 0){
        invertido = (invertido * 10) + (numero % 10);
        numero /= 10;
    }
    return invertido;
}
