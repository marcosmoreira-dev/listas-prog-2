/*9. Faça um programa onde o usuário digita 3 informações a respeito de uma pessoa: Nome,
endereço e telefone. Concatene essas três informações em uma única string.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char* string = (char*) malloc(400 * sizeof(char));
    if(string == NULL) return 1;
    string[0] = '\0';
    printf("Digite o Nome, o endereco e o telefone de uma pessoa: \n");
    for(int i = 0; i < 3; i++){
        char* aux = (char*) malloc(100 * sizeof(char));
        if(aux == NULL) return 1;
        scanf(" %[^\n]", aux);
        strcat(string, aux);
        if(i < 2) strcat(string, " - ");
        free(aux);
    }
    printf("String concatenada: %s", string);
    free(string);
    return 0;
}