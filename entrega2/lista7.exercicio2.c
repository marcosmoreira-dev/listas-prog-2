/*2. O que será impresso na tela? Mostre o andamento da execução.*/
#include <stdio.h>
#include <string.h>
int main (void) {
char *frase = "Otimo teste";
char *p , misterio[80];
int i = 0;
int j = 0;
p = frase + strlen ( frase ) - 1;
while (*p != ' ') {
misterio[i] = *p;
i ++; p --;
}
misterio[i] = ' '; i ++;
while ( frase[j] != ' ') {
misterio [i] = frase[j];
j ++; i ++;
}
misterio[i] ='\0';
puts (misterio);
printf("\n1. E criado o ponteiro frase contendo 'Otimo teste', o ponteiro p e o vetor misterio\n2. Cria-se os inteiros i e j tendo ambos valor 0\n");
printf("3. p aponta para a ultima posicao de frase\n4. misterio recebe etset, uma vez que *p aponta para  o ultimo 'e' de teste e vai decaindo ao avancar do loop\n");
printf("5. misterio recebe um espaco apos etset, indicador anda mais uma casa\n6. No proximo looping, misterio recebe Otimo apos o espaco de etset, uma vez que j = 0 e vai ate o primeiro espaco\n");
printf("7. No final, e impresso: etset Otimo\n");
return 0;
}