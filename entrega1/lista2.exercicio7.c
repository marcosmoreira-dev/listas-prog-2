/*  Escreva um programa que calcule o salário semanal de 
um trabalhador. As entradas são o número de horas trabalhadas
 na semana e o valor da hora. Até 40 h/semana não se acrescenta
 nenhum adicional. Acima de 40h e até 60h há um bônus de 50% 
para essas horas. Acima de 60h há um bônus de 100% para essas
 horas.*/

#include <stdio.h>

int main(){
    float horas, valor, total;

    printf("Quantas horas você trabalha? \n");
    scanf("%f", &horas);
    printf("Qual o valor da hora? \n");
    scanf("%f", &valor);

    if(horas<=40){
        total = horas*valor;
        printf("Não há acréscimos, logo, seu salário é R$%2.f\n", total);
    }else if(horas>40 && horas<=60){
        total = (valor*40) + (valor*(horas-40)*(1.5));
        printf("O acréscimo é de 50%, logo, seu salário é de R$%2.f\n", total);
    }else{
        total = (valor*40) + (valor*(horas-40));
        printf("O acréscimo é de 100%, logo, seu salário é de R$%2.f\n", total);
    }
    return 0;
}
