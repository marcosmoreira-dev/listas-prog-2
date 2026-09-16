/*Fazer um programa para receber uma frase do usuário, caracter a caracter usando getch() e
armazenando no vetor (máx. 80 caracteres). Quando o usuário digita enter (‘\r’) a recepção é
finalizada. Mostrar cada palavra da frase em uma linha separada*/
#include <stdio.h>
#include <conio.h>
void imprimir_frase(char *vetor);
int main(){
    char frase[80];
    int num = 80;
    char caracter;
    printf("Digite uma frase de no maximo 80 caracteres: ");
    for(int i = 0; i < 80; i++){
        caracter = getch();
        frase[i] = caracter;
        if(frase[i] == '\r') break;
        printf("%c", frase[i]);
    }
    frase[num] = '\0';
    imprimir_frase(frase);
    return 0;
}
void imprimir_frase(char *vetor){
    for(int j = 0; vetor[j] != '\0'; j++){
        if(vetor[j] == ' '){
            printf("\n");
        }
        else printf("%c", vetor[j]);
    }
}
