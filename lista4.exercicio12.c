/*Faça um programa que receba uma string do usuário (máx. 20 caracteres) e um caracter
qualquer. O programa deve remover todas as ocorrências do caracter da string e mostrar o
resultado.*/
#include <stdio.h>
void remover_termo(char* v);
int main(){
    char string[20];
    printf("Digite ate 20 caracteres: \n");
    scanf(" %[^\n]", string);
    remover_termo(string);
    printf("Apos a remocao: \n");
    int i = 0;
    while(string[i] != '\0'){
        printf("%c", string[i]);
        i++;
    }
}
void remover_termo(char* v){
    char caracter;
    int existe = 0;
    printf("Diga o caracter a ser removido: ");
    scanf(" %c", &caracter);
    while(1){
        existe = 0;
        for(int k = 0; v[k] != '\0'; k++){
            if(v[k] == caracter) existe = 1;
        }
        if(existe){
            for(int j = 0; v[j] != '\0'; j++){
                if(v[j] == caracter){
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
