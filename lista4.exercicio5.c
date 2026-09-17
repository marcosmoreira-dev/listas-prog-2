/*Desde março deste ano, os 33 táxis da cidade de Rio das Ostras tiveram que instalar a aferir
taxímetros para o cálculo do valor das corridas. De acordo com a tabela em vigor, a tarifa inicial
(ou bandeirada) custa R$4,95. Além disso, para cada quilômetro percorrido são cobrados mais
R$2,50, na bandeira 1, ou R$3,00, na bandeira 2. Escreva uma função em C que calcula os valores
da corrida de táxi em Rio das Ostras. A função recebe como parâmetros o valor real dist,
correspondendo à distância percorrida pelo táxi (em quilômetros), e os ponteiros b1 e b2,
indicando os endereços onde devem ser armazenados, respectivamente, os valores calculados
para a corrida na bandeira 1 e na bandeira 2.
void calcula_corrida(float dist, float *b1, float *b2);*/
#include <stdio.h>
void calcula_corrida(float dist, float *b1, float *b2);
int main(){
    float distancia, bandeira1, bandeira2;
    int opc;
    while(1){
        printf("Informe a distancia percorrida pelo Taxi em km: \n");
        scanf("%f", &distancia);
        if(distancia > 0)break;
        else printf("Tente Novamente!\n");
    }
    calcula_corrida(distancia, &bandeira1, &bandeira2);
    while(1){
        printf("1. Bandeira 1: \n");
        printf("2. Bandeira 2: \n");
        scanf("%i", &opc);
        if(opc == 1){
            printf("Valor da corrida R$ %.2f\n", bandeira1);
            break;
        }
        else if(opc == 2){
            printf("Valor da corrida R$ %.2f\n", bandeira2); 
            break;
        }
        else printf("Opcao invalida, tente novamente!\n");
}
return 0;
}
void calcula_corrida(float dist, float *b1, float *b2){
    *b1 = 4.95 + (2.50 * dist);
    *b2 = 4.95 + (3.00 * dist);
}
