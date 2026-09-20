/*Faça um programa que informe quais são os números que se repetem em
um vetor. O programa deve seguir os seguintes passos:
a) Leia um inteiro do usuário e aloque um vetor de inteiros
dinamicamente com este tamanho. Depois, preencha todo o vetor de
inteiros com valores entre 0 e 9.
b) Imprima na tela os valores que se repetem no vetor.

- Exemplo de execução do programa:
> Entradas:
tam = 9
vet = |1|5|8|4|4|5|0|8|8|
> Saída:
5, 8, 4
- Obs.: Faça tudo na main.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int tam, numero = 0, repete = 0, ja_apareceu = 0;
    printf("Tamanho do vetor: \n");
    while(1){
        scanf("%i", &tam);
        if(tam <= 0) printf("Invalido!\n");
        else break;
    }
    int* vetor = (int*) malloc(tam * sizeof(int));
    if(vetor == NULL){
        printf("Nao alocou\n");
        return 1;
    }
    printf("Diga os elementos do vetor: \n");
    for(int i = 0; i < tam; i++){
        while(1){
            scanf("%i", &vetor[i]);
            if(vetor[i] < 0 || vetor[i] > 9) printf("Invalido\n");
            else break;
        }
    }
    printf("Aqueles que se repetem sao: \n");
    for(int j = 0; j < tam; j++){
        ja_apareceu = 0;
        repete = 0;
        numero = vetor[j];
        for(int k = 0; k < tam; k++){
            if(numero == vetor[k]) repete++;
        }
        if(repete >= 2){
            for(int l = j - 1; l >= 0; l--){
                if(vetor[l] == numero) ja_apareceu = 1;
            }
            if(ja_apareceu){}
            else printf("%i ", numero);
        }
    }
    free(vetor);
    return 0;
}
