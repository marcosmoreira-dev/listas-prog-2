/*Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1*/
#include <stdio.h>
void remove_termo(char* v, char c);
void conta_termo(char* v);
int main(){
    char string[50];
    printf("Digite uma frase de no maximo 50 caracteres: \n");
    scanf(" %[^\n]", string);
    conta_termo(string);
}
void remove_termo(char* v, char c){
    int existe;
    while(1){
        existe = 0;
        for(int m = 0; v[m] != '\0'; m++){
            if(v[m] == c) existe = 1;
        }
        if(existe){
            for(int j = 0; v[j] != '\0'; j++){
                if(v[j] == c){
                    for(int l = j; v[l] != '\0'; l++){
                        v[l] = v[l+1];
                    }
                    j--;
                }
            }
        }
        else break;
    }
}
void conta_termo(char* v){
    int cont;
    char carac;
    while(v[0] != '\0'){
        cont = 0;
        carac = v[0];
        for(int l = 0; v[l] != '\0'; l++){
            if(v[l] == carac) cont++;
        }
        printf("'%c' = %i\n", carac, cont);
        remove_termo(v, carac);
    }
}
