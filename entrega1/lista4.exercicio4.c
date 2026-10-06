/*Implemente uma função que receba como parâmetros um vetor de números inteiros v e seu
comprimento n, e verifique se os elementos do vetor correspondem aos termos de uma PA
(Progressão Aritmética), isto é, se existe um número inteiro k tal que v[i]=v[0]+k*i. Caso os
elementos do vetor correspondam aos termos de uma PA, a função deve retornar o valor
calculado para k. Por exemplo, se for passado para essa função o vetor {2,10,18,26,34} a função
deve retornar o valor 8. Caso o vetor não corresponda a uma PA, a função deve retornar o valor 0.
Assuma que o vetor sempre terá pelo menos 3 elementos. Essa função deve ter o seguinte
protótipo:
int testa_PA(int n, int* v)*/
#include <stdio.h>
int testa_PA(int n, int* v);
int main(){
    int num, razao;
    while(1){
        printf("Numero de elementos do vetor: \n");
        scanf("%i", &num);
        if(num < 3)printf("Tente Novamente!\n");
        else break;
    }
    int vetor[num];
    printf("Elementos do vetor: \n");
    for(int i = 0; i < num; i++){
        scanf("%i", &vetor[i]);
    }
    if(testa_PA(num, vetor)){
        razao = testa_PA(num, vetor);
        printf("A razao da PA e: %i\n", razao);  
    }
    else printf("O vetor nao corresponde a uma PA ou todos os elementos sao iguais\n");
    return 0;
}
int testa_PA(int n, int* v){
    int k, e_uma_pa = 1,verifica = 0;
    k = v[1] - v[0];
    for(int j = 0; j < (n - 1); j++){
        verifica = v[j+1] - v[j];
        if(verifica != k){
            e_uma_pa--;
            break;
        }
    }
    if(e_uma_pa) return k;
    else return 0;
}
