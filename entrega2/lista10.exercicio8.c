/* 8) Escreva um programa que grave os dados de alunos conforme a estrutura abaixo em
um arquivo do tipo binário de acesso aleatório.
typedef struct _ALUNO {
char nome [81];
float nota1 , nota2;
} ALUNO;
a. Faça uma função para mostrar os alunos que tem média maior do que 6,0.
b. Faça um menu de opções para incluir, alterar, consultar e excluir um aluno.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    int id;              
    char nome[81];
    float nota1, nota2;
    int ativo;           
} ALUNO;

const char *NOME_ARQUIVO = "alunos.dat";

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrarAlunosMediaMaior6() {
    FILE *file = fopen(NOME_ARQUIVO, "rb");
    if (file == NULL) {
        printf("\nErro ao abrir o arquivo ou nenhum aluno cadastrado ainda.\n");
        return;
    }

    ALUNO aluno;
    int encontrados = 0;

    printf("\n=== ALUNOS COM MÉDIA SUPERIOR A 6.0 ===\n");
    while (fread(&aluno, sizeof(ALUNO), 1, file) == 1) {
        if (aluno.ativo) {
            float media = (aluno.nota1 + aluno.nota2) / 2.0f;
            if (media > 6.0f) {
                printf("ID: %d | Nome: %s | Nota 1: %.2f | Nota 2: %.2f | Média: %.2f\n",
                       aluno.id, aluno.nome, aluno.nota1, aluno.nota2, media);
                encontrados++;
            }
        }
    }

    if (encontrados == 0) {
        printf("Nenhum aluno encontrado com média maior que 6.0.\n");
    }

    fclose(file);
}

void incluirAluno() {
    FILE *file = fopen(NOME_ARQUIVO, "rb+");
    if (file == NULL) {
        file = fopen(NOME_ARQUIVO, "wb+");
        if (file == NULL) {
            printf("\nErro ao criar o arquivo.\n");
            return;
        }
    }

    ALUNO aluno;
    aluno.ativo = 1;

    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    aluno.id = (int)(tamanho / sizeof(ALUNO)) + 1;

    printf("\n--- Incluir Aluno (ID: %d) ---\n", aluno.id);
    printf("Nome: ");
    limparBuffer();
    fgets(aluno.nome, 81, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; 

    printf("Nota 1: ");
    scanf("%f", &aluno.nota1);

    printf("Nota 2: ");
    scanf("%f", &aluno.nota2);

    fwrite(&aluno, sizeof(ALUNO), 1, file);
    fclose(file);

    printf("Aluno cadastrado com sucesso!\n");
}

void alterarAluno() {
    FILE *file = fopen(NOME_ARQUIVO, "rb+");
    if (file == NULL) {
        printf("\nArquivo não encontrado.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do aluno que deseja alterar: ");
    scanf("%d", &id);

    long pos = (id - 1) * sizeof(ALUNO);
    fseek(file, 0, SEEK_END);
    long total_tamanho = ftell(file);

    if (pos < 0 || pos >= total_tamanho) {
        printf("Aluno com ID %d não existe.\n", id);
        fclose(file);
        return;
    }

    fseek(file, pos, SEEK_SET);
    ALUNO aluno;
    fread(&aluno, sizeof(ALUNO), 1, file);

    if (!aluno.ativo) {
        printf("Aluno com ID %d encontra-se excluído.\n", id);
        fclose(file);
        return;
    }

    printf("Dados atuais: Nome: %s | Nota 1: %.2f | Nota 2: %.2f\n", aluno.nome, aluno.nota1, aluno.nota2);
    printf("Novos dados:\n");

    printf("Novo Nome: ");
    limparBuffer();
    fgets(aluno.nome, 81, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    printf("Nova Nota 1: ");
    scanf("%f", &aluno.nota1);

    printf("Nova Nota 2: ");
    scanf("%f", &aluno.nota2);

    fseek(file, pos, SEEK_SET);
    fwrite(&aluno, sizeof(ALUNO), 1, file);

    fclose(file);
    printf("Dados do aluno atualizados com sucesso!\n");
}

void consultarAluno() {
    FILE *file = fopen(NOME_ARQUIVO, "rb");
    if (file == NULL) {
        printf("\nArquivo não encontrado.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do aluno que deseja consultar: ");
    scanf("%d", &id);

    long pos = (id - 1) * sizeof(ALUNO);
    fseek(file, 0, SEEK_END);
    long total_tamanho = ftell(file);

    if (pos < 0 || pos >= total_tamanho) {
        printf("Aluno com ID %d não encontrado.\n", id);
        fclose(file);
        return;
    }

    fseek(file, pos, SEEK_SET);
    ALUNO aluno;
    fread(&aluno, sizeof(ALUNO), 1, file);

    if (aluno.ativo) {
        float media = (aluno.nota1 + aluno.nota2) / 2.0f;
        printf("\n--- ALUNO ENCONTRADO ---\n");
        printf("ID: %d\nNome: %s\nNota 1: %.2f\nNota 2: %.2f\nMédia: %.2f\n",
               aluno.id, aluno.nome, aluno.nota1, aluno.nota2, media);
    } else {
        printf("Aluno com ID %d foi excluído.\n", id);
    }

    fclose(file);
}

void excluirAluno() {
    FILE *file = fopen(NOME_ARQUIVO, "rb+");
    if (file == NULL) {
        printf("\nArquivo não encontrado.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do aluno que deseja excluir: ");
    scanf("%d", &id);

    long pos = (id - 1) * sizeof(ALUNO);
    fseek(file, 0, SEEK_END);
    long total_tamanho = ftell(file);

    if (pos < 0 || pos >= total_tamanho) {
        printf("Aluno com ID %d não encontrado.\n", id);
        fclose(file);
        return;
    }

    fseek(file, pos, SEEK_SET);
    ALUNO aluno;
    fread(&aluno, sizeof(ALUNO), 1, file);

    if (!aluno.ativo) {
        printf("Aluno já se encontra excluído.\n");
        fclose(file);
        return;
    }

    aluno.ativo = 0;
    fseek(file, pos, SEEK_SET);
    fwrite(&aluno, sizeof(ALUNO), 1, file);

    fclose(file);
    printf("Aluno excluído com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n================ MENU ================\n");
        printf("1. Incluir Aluno\n");
        printf("2. Alterar Aluno\n");
        printf("3. Consultar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Mostrar alunos com média > 6.0\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirAluno();
                break;
            case 2:
                alterarAluno();
                break;
            case 3:
                consultarAluno();
                break;
            case 4:
                excluirAluno();
                break;
            case 5:
                mostrarAlunosMediaMaior6();
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}