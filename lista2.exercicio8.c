/*O número 3025 possui a seguinte característica: 30 + 25 = 55 -> 55*55 = 3025. Fazer
um programa para obter todos os números de 4 algarismos com a mesma característica do
número 3025.*/
#include <stdio.h>
#include <stdlib.h>
void num_caracteristica(void);
int main(){
printf("O numero 3025 possui a seguinte caracteristica: 30 + 25 = 55 -> 55*55 = 3025\n");
printf("Todos os numeros de 4 algarismos com a mesma caracteristica do numero 3025: \n");
num_caracteristica();
}
void num_caracteristica(void){
    int aux1,aux2,teste;
    for (int num = 1000; num <= 9999; num++) {
        aux1 = num / 100;     
        aux2 = num % 100;      
        teste = (aux1 + aux2) * (aux1 + aux2);

        if (teste == num)
            printf("%d\n", num);
    }
}
