/*6. Considere que você digitou o seu nome para o programa abaixo. O que será impresso?
Indique o que você digitou. Justifique sua resposta. (não vale ponto para apresentação)*/
#include <stdio.h>
#include <string.h>
#define MAX 50
int main (void){
char texto[MAX +2], temp;
int tam , i;
gets(texto);
tam = strlen (texto);
for (i = 0; i < tam ; i ++) {
temp = texto[i];
texto[i] = texto[ tam -1 - i ];
texto[strlen(texto) -1 - i] = temp ;
}
puts(texto);
printf("\n1. Define o char texto e temp; define tam e i como inteiros\n2. Recebe o texto do usuario(meu nome) com gets\n3. Da o valor de len do texto para tam\n");
printf("4. Faz um for que incremente 1 em i ate que fique no mesmo tamanho que tam\n 5. Nessse loopimg, percorre toda a string a invertendo e depois a invertendo novamente,\n");
printf("uma vez que texto[i] recebe texto[0] e depois texto[0] recebe temp que e o ultima caracteres, porem ao percorre toda a string a inversao e desfeita pela propria funcao\n");
printf("6. Imprime a exata string original\n");
return 0;
}