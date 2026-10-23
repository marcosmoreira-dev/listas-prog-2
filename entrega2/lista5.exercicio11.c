/*11. Fazer um programa que receba uma string de no máximo 20 caracteres do usuário e mostre o
conteúdo desta string de forma invertida.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main(){
    char* string = (char*) malloc(21 * sizeof(char));
    if(string == NULL) return 1;
    int indice = 0;
    printf("Digite uma string: \n");
    while(indice < 20){
        char s = getchar();
        if(s == '\n') break;
        string[indice] = s;
        indice++;
    }
    string[indice] = '\0';
    indice--;
    printf("\nInvertido: \n");
    for(int i = indice; i >= 0; i--){
        printf("%c", string[i]);
    }
    free(string);
    return 0;
}