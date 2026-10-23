/*4. Escreva um programa em C para ler uma palavra e escrever:
-A primeira letra da palavra.
-A última letra da palavra.
-O número de letras existente na palavra (não usar a função strlen())*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int indice, conta_letra = 0;
    char* palavra = (char*) malloc(100 * sizeof(char));
    printf("\nDigite uma palavra: \n");
    scanf(" %[^\n]", palavra);
    for(indice = 0; palavra[indice] != '\0'; indice++);
    indice--;
    printf("Primeira Letra: \n");
    for(int i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] != ' '){
            printf("%c\n", palavra[i]);
            break;
        }
    }
    printf("Ultima Letra: \n");
    for(indice; indice >= 0; indice--){
        if(palavra[indice] != ' '){
            printf("%c\n", palavra[indice]);
            break;
        }
    }
    for(int j = 0; palavra[j] != '\0'; j++){
        if(palavra[j] != ' ') conta_letra++;
    }
    printf("Numero de letras na palavra: %i\n", conta_letra);
    free(palavra);
    return 0;
}

