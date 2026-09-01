/*Escreva um programa em C para ler um valor X e um valor Z (se Z for menor que X
deve ser lido um novo valor para Z). Contar quantos números inteiros devemos somar em
sequência (a partir do X inclusive) para que a soma ultrapasse a Z o mínimo possível.
Escrever o valor final da contagem.
Exemplo:
X Z Resposta
3 20 5 (3+4+5+6+7=25)
2 10 4 (2+3+4+5=14)
30 40 2 (30+31=61)*/
#include <stdio.h>
void soma_ultrapassar_z(int X, int Z);
int main(){
int condicao,X,Z;
condicao = 1;
while(condicao != 0){
    printf("Digite o valor de X: \n");
    scanf("%i", &X);
    printf("Digite o valor de Z: \n");
    scanf("%i", &Z);
    if(Z > X) break;
}
soma_ultrapassar_z(X,Z);
return 0;
}
void soma_ultrapassar_z(int X, int Z){
    int quantidade = 1;
    int aux = X;
    int soma = X;
    printf("%i", X);
    while(soma < Z){
        aux++;
        quantidade++;
        printf(" + %i",aux);
        soma += aux;
    }
    printf(" = %i\n", soma);
    printf("Foram necessarios %i numeros inteiros", quantidade);
}
