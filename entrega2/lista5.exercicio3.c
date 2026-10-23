/*3. Construa uma função que receba como argumento de entrada uma cadeia de 20 caracteres e um
caractere e retorne o número de vezes que este caractere aparece na cadeia.*/
#include <stdio.h>
#include <stdlib.h>
int conta_char(char* s, char l){
    int conta_char = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == l) conta_char++;
    }
    return conta_char;
}
int main(){
    char* cadeia = (char*) malloc(21 * sizeof(char));
    printf("\nDigite a string: \n");
    scanf(" %[^\n]", cadeia);
    char letra = 'p';
    int num = conta_char(cadeia, letra);
    printf("\nA letra %c aparece %i vezes na cadeia\n", letra, num);
    free(cadeia);
    return 0;
}