/*1. Faça um programa com uma função que calcule o número de vogais existentes em uma string. A
função recebe a string e atualiza a resposta (número de vogais) em uma variável que foi passada por
referência.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void conta_vogal(char* s, int *n_vogal){
    for(int i = 0; i < (strlen(s)); i++){
        if(strchr("aeiouAEIOU", s[i]) != NULL) (*n_vogal)++;
    }
}
int main(){
    int numero_vogais = 0;
    char* string = (char*) malloc(200 * sizeof(char));
    printf("\nDigite a string: \n");
    scanf(" %[^\n]", string);
    conta_vogal(string, &numero_vogais);
    printf("\nExistem %i vogais na string", numero_vogais);
    free(string);
    return 0;
}