/*7. Faça um programa que dado um nome completo, retorne a abreviatura deste nome. Não se devem
abreviar as preposições como: do, de, etc. A abreviatura deve vir separada por pontos. Ex: Paulo
Jose de Almeida Prado. Abreviatura: P.J.A.P.*/
#define max 400
#include <stdio.h>
#include <stdlib.h>
int identifica_maiuscula(char letra);
char* abreviatura(char* s);
int main(){
    char* nome = (char*) malloc(max * sizeof(char));
    printf("\nDigite um nome completo: \n");
    scanf(" %[^\n]", nome);
    char* abreviado;
    abreviado = abreviatura(nome);
    free(nome);
    printf("\nAbreviacao: %s\n", abreviado);
    free(abreviado);
}
int identifica_maiuscula(char letra){
    if(letra >= 'A' && letra <= 'Z') return 1;
    return 0;
}
char* abreviatura(char* s){
    char* a = (char*) malloc(max * sizeof(char));
    int ind1 = 0, ind2 = 0;
    while(s[ind1] != '\0'){
        if(identifica_maiuscula(s[ind1])){
            a[ind2] = s[ind1];
            ind2++;
            a[ind2] = '.';
            ind2++;
        }
        ind1++;
    }
    a[ind2] = '\0';
    return a;
}
