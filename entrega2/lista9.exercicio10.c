/*10. Faça as funções que são invocadas pela função main.*/
#include <stdio.h>
#define MAX 4
struct aluno{
    char nome[81];
    int media;
};
void le(struct aluno classe[]){
    for(int i = 0; i < MAX; i++){
        printf("Nome: \n");
        scanf(" %[^\n]", classe[i].nome);
        printf("Media: \n");
        scanf("%i", &classe[i].media);
    }
}
void imprime(struct aluno classe[]){
    for(int i = 0; i < MAX; i++){
        printf("Nome: %s\nMedia: %i\n", classe[i].nome, classe[i].media);
    }
}
void ordena_medias(struct aluno classe[]){
    int ini, fim;
    for(fim = MAX - 1; fim > 0; fim--){
        int troca = 0;
        for(ini = 0; ini < fim; ini++){
            if(classe[ini].media > classe[ini + 1].media){
                troca = 1;
                struct aluno aux = classe[ini];
                classe[ini] = classe[ini + 1];
                classe[ini + 1] = aux;
            }
        }
        if(troca == 0) return;
    }
}
int main (void){
struct aluno turma[MAX];
le(turma);
puts ("Imprimindo dados lidos da turma.");
puts ("Digite qualquer coisa para continuar.");
getchar ();
imprime ( turma );
ordena_medias ( turma );
puts (" Imprimindo dados ordenados da turma.");
puts (" Digite qualquer coisa para continuar .");
getchar ();
imprime ( turma );
getchar ();
}