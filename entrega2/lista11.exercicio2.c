/* 2. Considere listas encadeadas que armazenam valores inteiros, nas quais cada elemento é
do tipo Elemento, descrito abaixo:
struct elemento {
int info; /* Valor inteiro armazenado 
struct elemento *prox; /* Ponteiro para o próximo elemento 
};
typedef struct elemento Elemento;
Escreva uma função que cria uma cópia de uma lista encadeada, ou seja, cria uma nova
lista encadeada cujo conteúdo armazenado é idêntico --- tem os mesmos valores e na
mesma ordem --- ao de uma lista original. A função recebe como parâmetro o ponteiro
para o primeiro elemento da lista original (àquela a ser copiada) e retorna um ponteiro
para a nova lista (a cópia). A lista original não deve ser alterada. O protótipo da função é:
Elemento* copia(Elemento* lst);
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;               
    struct elemento *prox;  
};
typedef struct elemento Elemento;

Elemento* copia(Elemento* lst);

Elemento* criar_no(int valor);
void imprimir_lista(Elemento* lst);
void liberar_lista(Elemento* lst);

int main() {
    Elemento* original = criar_no(10);
    original->prox = criar_no(20);
    original->prox->prox = criar_no(30);

    Elemento* copia_lista = copia(original);

    printf("Lista Original: ");
    imprimir_lista(original);

    printf("Lista Copiada:  ");
    imprimir_lista(copia_lista);

    liberar_lista(original);
    liberar_lista(copia_lista);

    return 0;
}

Elemento* copia(Elemento* lst) {
    if (lst == NULL) {
        return NULL;
    }

    Elemento* nova_head = NULL;
    Elemento* atual_nova = NULL;
    Elemento* p = lst;

    while (p != NULL) {
        Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
        if (novo == NULL) {
            return NULL;
        }

        novo->info = p->info;
        novo->prox = NULL;

        if (nova_head == NULL) {
            nova_head = novo;
        } else {
            atual_nova->prox = novo;
        }

        atual_nova = novo;
        p = p->prox;
    }

    return nova_head;
}


Elemento* criar_no(int valor) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
    }
    return novo;
}

void imprimir_lista(Elemento* lst) {
    Elemento* p = lst;
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

void liberar_lista(Elemento* lst) {
    Elemento* p = lst;
    while (p != NULL) {
        Elemento* temp = p;
        p = p->prox;
        free(temp);
    }
}