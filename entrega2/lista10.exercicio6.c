/* 6) Faça um programa que gere 10 arquivos com o nome “testeXX”, onde XX é ”01”, ...,
”10” (exemplo: teste01.txt”). Cada arquivo deve conter dentro dele o texto ”Texto do
arquivo [NÚMERO DO ARQUIVO]”.
*/


#include <stdio.h>

int main() {
    char nome_arquivo[30];

    for (int i = 1; i <= 10; i++) {
        sprintf(nome_arquivo, "teste%02d.txt", i);

        FILE *arquivo = fopen(nome_arquivo, "w");

        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s\n", nome_arquivo);
            return 1;
        }

        fprintf(arquivo, "Texto do arquivo %02d\n", i);

        fclose(arquivo);
    }

    printf("10 arquivos criados com sucesso!\n");

    return 0;
}
