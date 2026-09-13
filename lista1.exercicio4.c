/* Um funcionário da UFF precisa validar as notas de 3 provas fornecidas por um professor e 
indicar: a média, se está aprovado/reprovado e se tem direito de realizar a VS. Inicialmente, 
faça um programa que recebe como entrada as 3 notas e mostre os resultados solicitados. 
Posteriormente, coloque o código de cálculo da média em uma função. Em um passo seguinte, 
realize os controles necessários para não receber notas inválidas.*/

#include<stdio.h>

float media(float nota1, float nota2, float nota3){
    float media = (nota1+nota2+nota3)/3;
    return media;
} 

int main(){
    float n1, n2, n3, ret;

    do{
    printf(" Escreva a primeira nota: \n");
    scanf("%f", &n1);
    }while (n1<0 || n1>10);
    
    do{
    printf("Escreva a segunda nota: \n");
    scanf("%f", &n2);
    }while (n2<0 || n2>10);

    do{
    printf("Escreva a terceira nota: \n");
    scanf("%f", &n3);
    }while (n3<0 && n3>10);

    ret = media(n1,n2,n3);
    if (ret>=6){
        printf("Aprovado com média: %.2f\n", ret);
    } else if (ret>=4 && ret<6){
        printf("VS com média: %.2f\n", ret);
    }else{
        printf("Reprovado com nota: %.2f", ret);
}
