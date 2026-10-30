/*9. Faça a função main para funcionar com a função ordena.:*/
#include <stdio.h>
typedef struct aluno{
    char nome[81];
    int media;
} ALUNO;
void ordena (ALUNO turma[], int tam){
int i, foraOrdem , jaOrdenados = 0;
ALUNO temp;
do {
foraOrdem = 0;
for (i = 0; i < 4 - 1 - jaOrdenados ; i++) {
if (turma[i]. media > turma[i+1]. media) {
temp = turma[i];
turma[i] = turma[i+1];
turma[i+1] = temp ;
foraOrdem = 1;
}
}
jaOrdenados ++;
} while ( foraOrdem );
}
int main(){
    ALUNO classe[] = {{"Rogerio Carlos", 8}, {"Ana Paulo", 5}, {"Maria Julia", 9}, {"Miguel Santos", 2}};
    ordena(classe, 4);
    for(int i = 0; i < 4; i++){
        printf("Nome: %s\nMedia: %i\n", classe[i].nome, classe[i].media);
    }
    return 0;
}