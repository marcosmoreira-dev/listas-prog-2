/*Implemente um programa que chame a função média com o seguinte protótipo:
float media(int n, float *v)*/
#include <stdio.h>
float media(int n, float *v);
int main(){
    int num;
    printf("Numero de elementos do vetor: \n");
    scanf("%i", &num);
    float vetor[num];
    printf("Elementos do vetor: \n");
    for(int i = 0; i < num; i++){
        scanf("%f", &vetor[i]);
    }
    float valor_media = media(num, vetor);
    printf("A media dos valores do vetor e: %.2f", valor_media);
    return 0;
}
float media(int n, float *v){
    float soma = 0, valor;
    for(int j = 0; j < n; j++){
        soma += v[j];
    }
    valor = soma / n;
    return valor;
}
