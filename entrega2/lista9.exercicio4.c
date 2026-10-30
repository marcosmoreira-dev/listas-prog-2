/*Tendo o seguinte trecho de código (compilável e executável corretamente):
#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome);
char * get_sobrenome(char *nome);
main()
{
int i;
char **nomes;
char *sobrenome;
nomes = (char **) malloc(MAX*sizeof(char *));
for ( i=0 ; i<MAX ; i++) {
nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
}
atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo");
atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos
Santos");
for (i=0 ; i<MAX ; i++) {
sobrenome = get_sobrenome(nomes[i]);
printf("\n%s ", sobrenome);
printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf
}
printf("\n%c", nomes[0][3]); // 3o printf
}
a. Implemente a função atribui, conforme o seu protótipo (dica: somente 1 linha de
código no corpo da função).
b. Implemente a função get_sobrenome, conforme o seu protótipo, que retorna a última
palavra do nome.
c. O que será impresso no segundo printf?
d. O que será impresso no terceiro printf?*/
#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome);
char * get_sobrenome(char *nome);
int main(){
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for ( i=0 ; i<MAX ; i++) {
    nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }
    atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos Santos");
    for (i=0 ; i<MAX ; i++){
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf
    }
    printf("\n%c", nomes[0][3]); // 3o printf
    printf("\nc) Sera impresso 0,0,2,3. Isso ocorre porque apenas os sobrenomes Belmonte e Santos\nsatisfazem a condicao (strlen(sobrenome) ser maior que 5) para imprimir os valors de i.");
    printf("\nd) Sera impresso a letra a que e o caracterere de indice 3 do vetor Fulano Silva");
    return 0;
}
void atribui(char **nomes, int indice, char *nome){
    strcpy(nomes[indice], nome);
}
char * get_sobrenome(char *nome){
    int ultimo_espaco = -1;
    int caracteres = strlen(nome);
    for(int i = 0; nome[i] != '\0'; i++){
        if(nome[i] == ' ') ultimo_espaco = i;
    }
     if(ultimo_espaco == -1) return nome;
    char *sobrenome = (char*) malloc((caracteres - ultimo_espaco + 1) * sizeof(char));
    strcpy(sobrenome, nome + (ultimo_espaco + 1));
    return sobrenome;
}