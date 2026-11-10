/* 1. Considere uma lista encadeada que armazena valores reais, na qual cada elemento é do
tipo Elemento, descrito abaixo:
struct elemento {
float info; /* Valor real armazenado 
struct elemento *prox; /* Ponteiro para o próximo elemento 
};
typedef struct elemento Elemento;
Escreva uma função que recebe como parâmetros o ponteiro lst, para o primeiro elemento
da lista, e os valores min e max, e remove e libera todos os elementos desta lista que
armazenam valores menores que min ou maiores que max. A função deve retornar o
ponteiro para o início da lista, que pode ter sido modificado, e tem o seguinte protótipo:
Elemento* filtra(Elemento *lst, float min, float max);
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float info;          
    struct elemento *prox; 
};
typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max);

Elemento* insere(Elemento *lst, float valor) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = lst;
    return novo;
}

void imprime(Elemento *lst) {
    Elemento *p;
    for (p = lst; p != NULL; p = p->prox) {
        printf("%.2f -> ", p->info);
    }
    printf("NULL\n");
}

void meuliberar(Elemento *lst) {
    Elemento *p = lst;
    while (p != NULL) {
        Elemento *t = p->prox;
        free(p);
        p = t;
    }
}

Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *atual = lst;
    Elemento *anterior = NULL;

    while (atual != NULL) {
        if (atual->info < min || atual->info > max) {
            Elemento *temp = atual;

            if (anterior == NULL) {
                lst = atual->prox;
                atual = lst;
            } else {
                anterior->prox = atual->prox;
                atual = atual->prox;
            }

            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    return lst;
}

int main(void) {
    Elemento *lista = NULL;

    lista = insere(lista, -3.0);
    lista = insere(lista, 12.0);
    lista = insere(lista, 0.5);
    lista = insere(lista, 8.4);
    lista = insere(lista, 2.0);
    lista = insere(lista, 15.5);

    printf("Lista original:\n");
    imprime(lista);

    float min = 1.0;
    float max = 10.0;

    printf("\nFiltrando elementos fora do intervalo [%.1f, %.1f]...\n", min, max);
    lista = filtra(lista, min, max);

    printf("\nLista apos a filtragem:\n");
    imprime(lista);

    meuliberar(lista);

    return 0;
}