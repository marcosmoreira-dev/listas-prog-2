/*5. O que será impresso na tela pelo seguinte programa:*/
#include <stdio.h>
#include <string.h>
int main(){
char frase[80]="o rato roeu a roupa do rei de roma";
char *p;
p = frase;
p[2]='m';
p[6]='\0';
printf("%s\n", frase);
p = p + 3;
printf("%s\n",p);
printf("%d\n",strlen(frase));
printf("\n1. Define a string e depois define o ponteiro p\n2. Aponta o ponteiro para a string e muda a letra 'r' por m\n3. Define a setima posicao como o final da string\n4. Imprime: 'o mato '\n5. Avanca o ponteiro em 3 posicoes e imprime 'ato'\n6. Imprime 6\n");
return 0;
}