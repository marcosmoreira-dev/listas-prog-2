/*6. Um cadastro de pessoas é representado por um vetor de ponteiros para o tipo Pessoa, conforme
descrito a seguir:
Considere que esse vetor está em ordem crescente de código, e, além disso, o código é a
identificação única da pessoa. Aplicando a técnica de busca binária, implemente uma função que
verifique se um código fornecido como parâmetro existe no vetor. A função retorna o ponteiro
para esta pessoa (Pessoa *). Caso contrário, a função deve retornar NULL. A função recebe como
parâmetros o ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o
tamanho do vetor, e o código. Seu protótipo é:
Faça também um programa para testar essa função.*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct pessoa {
int codigo;
char nome[81];
};
typedef struct pessoa Pessoa;
Pessoa** aloca_pessoa(int n){
    Pessoa** p = (Pessoa**) malloc(n * sizeof(Pessoa*));
    if(p == NULL) return NULL;
    for(int i = 0; i < n; i++){
        p[i] = (Pessoa*) malloc(sizeof(Pessoa));
        if(p[i] == NULL) return NULL;
    }
    return p;
}
void atribui_pessoa(Pessoa** p, int ind, int cod_pessoa, char* nome_pessoa){
    p[ind]->codigo = cod_pessoa;
    strcpy(p[ind]->nome, nome_pessoa);
}
Pessoa* busca(int n, Pessoa** vet, int codigo){
    int ini = 0, fim = n - 1;
    while(ini <= fim){
        int meio = (ini + fim)/2;
        if(vet[meio]->codigo == codigo) return vet[meio];
        if(vet[meio]->codigo > codigo) fim = meio - 1;
        else ini = meio + 1;
    }
    return NULL;
}
int main(){
    Pessoa** pessoas = aloca_pessoa(4);
    if(pessoas == NULL) return 1;
    atribui_pessoa(pessoas, 0, 1234, "Henrique");
    atribui_pessoa(pessoas, 1, 1235, "Pedro");
    atribui_pessoa(pessoas, 2, 1236, "Ana");
    atribui_pessoa(pessoas, 3, 1237, "Julia");
    Pessoa * buscando = busca(4, pessoas, 1270);
    if(buscando == NULL) printf("Pessoa nao cadastrada!\n");
    else{
        printf("Codigo: %i\nNome: %s\n", buscando->codigo, buscando->nome);
    }
    for(int i = 0; i < 4; i ++){
        free(pessoas[i]);
    }
    free(pessoas);
    return 0;
}