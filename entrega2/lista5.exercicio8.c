/*8. Faça um programa que dado 2 palavras, determine:
a. Se as palavras são iguais;
b. Verifique se a segunda palavra é uma sub string da primeira. Ex: casa e casamento.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 200
int identifica_igual(char* s1, char* s2){
    if(strlen(s1) != strlen(s2)) return 0;
    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}
int identifica_sub_string(char* s1, char* s2){
    int len2 = strlen(s2), ind2, ind1, conta_igual;
    if(strlen(s1) < len2) return 0;
    for(int j = 0; s1[j] != '\0'; j++){
        if(s1[j] == s2[0]){
            ind1 = j;
            conta_igual = 0;
            for(ind2 = 0; ind2 < len2; ind2++){
                if(s1[ind1] == s2[ind2]){
                    conta_igual++;
                }
                ind1++;
                if(conta_igual == len2) return 1;
            }
        }
    }
    return 0;
}
int main(){
    char* palavra1 = (char*) malloc(max * sizeof(char));
    char* palavra2 = (char*) malloc(max * sizeof(char));
    if(palavra1 == NULL || palavra2 == NULL) return 1;
    printf("Digite duas palavras: \n");
    scanf(" %[^\n]", palavra1);
    scanf(" %[^\n]", palavra2);
    if(identifica_igual(palavra1, palavra2)){
        printf("\nA %s e igual a %s\n", palavra1, palavra2);
    }
    else printf("\nAs palavras nao sao iguais\n");
    if(identifica_sub_string(palavra1, palavra2)){
        printf("\n%s e sub string de %s\n", palavra2, palavra1);
    }
    else printf("\n%s nao e sub string de %s\n", palavra2, palavra1);
    free(palavra1);
    free(palavra2);
    return 0;
}