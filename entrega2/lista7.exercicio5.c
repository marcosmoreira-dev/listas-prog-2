/*5. Escreva um programa que leia uma linha de caracteres do teclado de tamanho 80. A
linha somente contém letras. Divida a linha em blocos de 5 letras. Dentro de cada bloco o
seu programa deve trocar a primeira letra pela letra seguinte no alfabeto, a segunda letra
por duas letras adiante no alfabeto, a terceira por três letras adiante e assim até a quinta.
Os espaços em branco devem ser retirados da frase. Considere o seguinte exemplo.
1. Frase lida:
EVA VIU A UVA
2. Retirada dos espaços em branco:
EVAVIUAUVA
3. Divisão em blocos de 5 (blocos indicados por tipos diferentes):
EVAVIUAUVA
4. Criptografia:
FXDANVCYAF
Portanto, o que será impresso pelo programa é:
FXDANVCYAF*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void tira_espaco(char* v){
    for(int i = 0; v[i] != '\0'; i++){
        if(v[i] == ' '){
            for(int j = i; v[j] != '\0'; j++){
                v[j] = v[j+1];
            }
            i--;
        }
    }
    printf("\nSem espaco: %s\n", v);
}
void criptografa(char * v){
    int bloco = 1;
    for(int k = 0; v[k] != '\0'; k++){
        if(bloco > 5) bloco = 1;
        char aux = v[k];
        if(aux >= 'A' && aux <= 'Z'){
            v[k] = 'A' + (int)(aux - 'A' + bloco) % 26;
        } 
        else if(aux >= 'a' && aux <= 'z'){
            v[k] = 'a' + (int)(aux - 'a' + bloco) % 26;
        }
        bloco++;
    }
    printf("Criptografado: %s\n", v);
}
int main(){
    printf("Digite uma string de ate 80 caracteres: \n");
    char* string = (char*) malloc(81 * sizeof(char));
    int quant = 0;
    while(quant < 80){
        char l = getch();
        if(l == '\n' || l == '\r') break;
        if((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z') || (l == ' ')){
            putchar(l);
            string[quant] = l;
            quant++;
        }
    }
    string[quant] = '\0';
    tira_espaco(string);
    criptografa(string);
    free(string);
}