/*8. Uma agenda é representada por um vetor de ponteiros para o tipo Compromisso, que
representa as informações sobre um compromisso diário, conforme descrito a seguir:
Considere que esse vetor está em ordem cronológica, ou seja, ordem crescente de acordo com a
data de cada compromisso, e, além disso, não há mais de um compromisso com uma mesma data.
Aplicando a técnica de busca binária, implemente uma função que, dada uma data (dia, mês e
ano), se há no vetor algum compromisso com essa data, retorna o ponteiro para este
compromisso. Caso contrário, a função deve retornar NULL. A função recebe como parâmetros o
ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o tamanho do vetor, e
os inteiros d, m e a, representando uma data. Seu protótipo é*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct data {
int dd, mm, aa; /* Dia, mes e ano */
};
typedef struct data Data;
struct compromisso {
char descricao[81]; /* Descricao do compromisso */
Data* dta; /* Data do compromisso */
};
typedef struct compromisso Compromisso;
Compromisso** aloca_compromissos(int n){
    Compromisso** c = (Compromisso**) malloc(n * sizeof(Compromisso*));
    if(c == NULL) return NULL;
    for(int i = 0; i < n; i++){
        c[i] = (Compromisso*) malloc(sizeof(Compromisso));
        c[i]->dta = (Data*) malloc(sizeof(Data));
        if(c[i]== NULL|| c[i]->dta == NULL) return NULL;
    }
    return c;
}
void atribui_compromissos(Compromisso**c,int ind, char* desc, int dia, int mes, int ano){
    strcpy(c[ind]->descricao, desc);
    c[ind]->dta->aa = ano;
    c[ind]->dta->mm = mes;
    c[ind]->dta->dd = dia;
}
Compromisso* busca(int n, Compromisso** vet, int d, int m, int a){
    int ini = 0, fim = n - 1;
    while(ini <= fim){
        int meio =(ini + fim)/2;
        if((vet[meio]->dta->aa == a) && (vet[meio]->dta->mm == m) && (vet[meio]->dta->dd == d))
            return vet[meio];
        if(vet[meio]->dta->aa != a){
            if(vet[meio]->dta->aa > a) fim = meio - 1;
            else ini = meio + 1;
        }
        else if(vet[meio]->dta->mm != m){
            if(vet[meio]->dta->mm > m) fim = meio - 1;
            else ini = meio + 1;
        }
        else{
            if(vet[meio]->dta->dd > d) fim = meio - 1;
            else ini = meio + 1;
        }
    }
    return NULL;
}
int main(){
    Compromisso** datas = aloca_compromissos(4);
    atribui_compromissos(datas, 0, "Nascimento", 1, 4, 1998);
    atribui_compromissos(datas, 1, "Compra Carro", 1, 5, 2002);
    atribui_compromissos(datas, 2, "Festa", 8, 5, 2002);
    atribui_compromissos(datas, 3, "Escola", 1, 4, 2006);
    Compromisso* buscando = busca(4, datas, 8, 5, 2002);
    if(buscando == NULL) printf("Compromisso nao existe\n");
    else{
        printf("Compromisso: %s\n", buscando->descricao);
        printf("Dia: %i\nMes: %i\nAno: %i\n", buscando->dta->dd, buscando->dta->mm, buscando->dta->aa);
    }
    for(int i = 0; i < 4;i++){
        free(datas[i]->dta);
        free(datas[i]);
    }
    free(datas);
    return 0;
}