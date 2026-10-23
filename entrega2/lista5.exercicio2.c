/*2. Mostre e explique (comentando as linhas de código) o que será impresso na tela:*/
#include<stdio.h>
#include<string.h>
int main()
{
char texto[]= "foi muito facil"; //Cria a string texto que contem "foi muito facil"
int i; //Define o int i para o looping for
for (i = 0; texto[i]!='\0'; i++) //Percorre o looping for ate o "final" da string
{
if (texto[i] == ' ') break; //Para o looping ao encontrar o primeiro espaco
}
i++; //acrescenta 1 ao innteiro I a cada passagem, parando o inteiro na posicao apos o primeiro espaco
printf("\nSera impresso = 'muito facil'\n");
for ( ; texto[i]!='\0'; i++) //faz outro looping a partir do primeiro espaco (Inteiro I)
{
printf("%c", texto[i]); //Imprime cada char a partir do primeiro espaco: "muito facil"
}
return 0;
}
