/* 3. Crie uma lista encadeada onde cada elemento contém informações de um aluno. Crie
funções para o gerenciamento da lista: imprimir, excluir, incluir e alterar.
Aplique essas funções a partir de uma lista carregado do arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float nota;
} Aluno;

typedef struct No {
    Aluno info;
    struct No* prox;
} No;

No* criar_no(Aluno aluno);
void incluir(No** inicio, Aluno aluno);
void imprimir(No* inicio);
void excluir(No** inicio, int id);
void alterar(No* inicio, int id);
void carregar_de_ficheiro(No** inicio, const char* nome_ficheiro);
void guardar_em_ficheiro(No* inicio, const char* nome_ficheiro);
void libertar_lista(No** inicio);

int main() {
    No* lista = NULL;
    const char* nome_ficheiro = "alunos.txt";

    carregar_de_ficheiro(&lista, nome_ficheiro);

    int opcao, id;
    Aluno novo_aluno;

    do {
        printf("\n--- MENU DE GERENCIAMENTO ---\n");
        printf("1. Imprimir lista\n");
        printf("2. Incluir aluno\n");
        printf("3. Excluir aluno\n");
        printf("4. Alterar aluno\n");
        printf("0. Sair e guardar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                imprimir(lista);
                break;
            case 2:
                printf("Digite o ID do aluno: ");
                scanf("%d", &novo_aluno.id);
                getchar();
                printf("Digite o Nome do aluno: ");
                fgets(novo_aluno.nome, sizeof(novo_aluno.nome), stdin);
                novo_aluno.nome[strcspn(novo_aluno.nome, "\n")] = '\0'; 
                printf("Digite a Nota do aluno: ");
                scanf("%f", &novo_aluno.nota);
                
                incluir(&lista, novo_aluno);
                printf("Aluno incluido com sucesso!\n");
                break;
            case 3:
                printf("Digite o ID do aluno a excluir: ");
                scanf("%d", &id);
                excluir(&lista, id);
                break;
            case 4:
                printf("Digite o ID do aluno a alterar: ");
                scanf("%d", &id);
                alterar(lista, id);
                break;
            case 0:
                guardar_em_ficheiro(lista, nome_ficheiro);
                printf("Dados guardados no ficheiro. A encerrar...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    libertar_lista(&lista);
    return 0;
}

No* criar_no(Aluno aluno) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->info = aluno;
    novo->prox = NULL;
    return novo;
}

void incluir(No** inicio, Aluno aluno) {
    No* novo = criar_no(aluno);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void imprimir(No* inicio) {
    if (inicio == NULL) {
        printf("\nA lista esta vazia.\n");
        return;
    }
    printf("\n--- LISTA DE ALUNOS ---\n");
    No* atual = inicio;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Nota: %.2f\n", atual->info.id, atual->info.nome, atual->info.nota);
        atual = atual->prox;
    }
}

void excluir(No** inicio, int id) {
    if (*inicio == NULL) {
        printf("Lista vazia. Nao e possivel excluir.\n");
        return;
    }

    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->info.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Aluno com ID %d nao encontrado.\n", id);
        return;
    }

    if (anterior == NULL) { 
        *inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Aluno com ID %d excluido com sucesso!\n", id);
}

void alterar(No* inicio, int id) {
    No* atual = inicio;
    while (atual != NULL && atual->info.id != id) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Aluno com ID %d nao encontrado.\n", id);
        return;
    }

    getchar(); 
    printf("Digite o novo Nome para o aluno: ");
    fgets(atual->info.nome, sizeof(atual->info.nome), stdin);
    atual->info.nome[strcspn(atual->info.nome, "\n")] = '\0';
    
    printf("Digite a nova Nota: ");
    scanf("%f", &atual->info.nota);

    printf("Dados do aluno alterados com sucesso!\n");
}

void carregar_de_ficheiro(No** inicio, const char* nome_ficheiro) {
    FILE* arq = fopen(nome_ficheiro, "r");
    if (arq == NULL) {
        printf("Ficheiro '%s' nao encontrado. Uma nova lista sera criada.\n", nome_ficheiro);
        return;
    }

    Aluno a;
    while (fscanf(arq, "%d;%49[^;];%f\n", &a.id, a.nome, &a.nota) == 3) {
        incluir(inicio, a);
    }

    fclose(arq);
    printf("Dados carregados com sucesso do ficheiro '%s'.\n", nome_ficheiro);
}

void guardar_em_ficheiro(No* inicio, const char* nome_ficheiro) {
    FILE* arq = fopen(nome_ficheiro, "w");
    if (arq == NULL) {
        printf("Erro ao abrir o ficheiro para escrita!\n");
        return;
    }

    No* atual = inicio;
    while (atual != NULL) {
        fprintf(arq, "%d;%s;%.2f\n", atual->info.id, atual->info.nome, atual->info.nota);
        atual = atual->prox;
    }

    fclose(arq);
}

void libertar_lista(No** inicio) {
    No* atual = *inicio;
    No* prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}