/*Escreva um programa para declarar um vetor de caracteres de tamanho 26 e imprimir o
seu conteúdo. O vetor deve ser inicializado com as letras minúsculas do alfabeto. A
inicialização do vetor e a sua impressão devem ser feitas por funções.*/
#include <stdio.h>
#include <stdlib.h>
void inicializa_vetor(char* v){
    for(int i = 0; i < 26; i++){
        v[i] = 'a' + i;
    }
    v[26] = '\0';
}
void imprime_vetor(char* v){
    for(int j = 0; v[j] != '\0'; j++){
        printf("%c\n", v[j]);
    }
}
int main(){
    char* vetor = (char*) malloc(27 * sizeof(char));
    inicializa_vetor(vetor);
    imprime_vetor(vetor);
    free(vetor);
    return 0;
}