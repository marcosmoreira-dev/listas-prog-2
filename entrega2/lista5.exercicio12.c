/*12. Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1*/
#include <stdio.h>
#include <stdlib.h>
char* marcador(char l, char* m, int* n){
    (*n)++;
    int aux = *n;
    m = (char*) realloc(m, (aux + 1)* sizeof(char));
    m[aux - 1] = l;
    m[aux] = '\0';
    return m;
}
int nao_esta_no_marcador(char l, char* m){
    for(int j = 0; m[j] != '\0'; j++){
        if(l == m[j]) return 0;
    }
    return 1;
}
int main(){
    int indice = 0, contador;
    char* marca = (char*) malloc(1 * sizeof(char));
    if(marca == NULL) return 1;
    marca[0] = '\0';
    char* string = (char*) malloc(51 * sizeof(char));
    if(string == NULL) return 1;
    printf("Digite sua string: \n");
    scanf(" %[^\n]", string);
    for(int i = 0; string[i] != '\0'; i++){
        contador = 0;
        if(nao_esta_no_marcador(string[i], marca)){
            marca = marcador(string[i], marca, &indice);
            for(int k = 0; string[k] != '\0'; k++){
                if(string[k] == string[i]) contador++;
            }
            printf("'%c' = %i\n", string[i], contador);
        }
    }
    free(string);
    free(marca);
    return 0;
}