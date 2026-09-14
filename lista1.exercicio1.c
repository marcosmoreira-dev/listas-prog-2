/* Fazer um programa para receber um número inteiro de segundos do usuário e imprimir 
a quantidade correspondente em horas, minutos e segundos. */

#include <stdio.h>

int main(void) {
    
    int horas, minutos, segundos;
    
    printf("Digite o número de segundos:");
    scanf("%d", &segundos);
    
    horas = segundos / 3600;
    segundos = segundos % 3600;
    minutos = segundos / 60;
    segundos = segundos % 60;
    
    printf("Horas: %d, minutos: %d e segundos: %d", horas, minutos, segundos);
    return 0;
}