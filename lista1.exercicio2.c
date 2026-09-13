/*Fazer um programa que recebe 3 valores inteiros do usuário e mostra o maior deles, o menor deles,
 os valores pares e a média. */

#include<stdio.h>
int main(){
    int n1, n2, n3, maior, soma=0, menor, pares[3], qtdpares=0;
    float media;
    printf("Insira um número: \n ");
    scanf("%d", &n1);
    printf("Insira um número: \n");
    scanf("%d", &n2);
    printf("Insira um número: \n");
    scanf("%d", &n3);
    maior = n1;
    menor = n1;
    if (n2>maior){
        maior=n2;
    }if(n3>maior){
        maior=n3;
    }if(n2<menor){
        menor=n2;
    }if(n3<menor){
        menor=n3;
    }
    if(n1%2==0){
        pares[qtdpares]=n1;
        qydpares++;
    }else if(n2%2==0){
        pares[qtdpares]=n2;
        qydpares++;
    }else if(n3%2==0){
        pares[qtdpares]=n3;
        qydpares++;
    }
    media = (n1+n2+n3)/3;
    printf("Essa é a média %f, esse é o maior número %d, esse é o menor número %d\n", media, maior, menor);

    printf("E esses são os pares encontrados: \n");
    for(int i =0; i<qtdpares; i++){
        printf("%d",pares[i]);
    }
    return 0;
}
