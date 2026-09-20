/*Escreva uma função em C que receba como parâmetro uma cadeia de caracteres,
contendo apenas letras entre 'A' e 'Z' ou 'a' e 'z' e espaços em branco, e retorne uma
nova cadeia -- alocada dinamicamente --, contendo uma cópia da cadeia original, mas
sem espaços em branco no início ou no final, isto é, sem qualquer caractere ' ' (espaço)
localizado antes da primeira letra ou depois da última letra da cadeia. Por simplificação,
considere que a cadeia de entrada possui no mínimo uma letra (entre 'A' e 'Z' ou 'a' e
'z'). Por exemplo, se a cadeia “ nota do aluno ” (com três espaços em branco no início
e dois no final) for passada para a função, a cadeia retornada deve ser “nota do aluno”,
sem nenhum espaço no início ou no final. Se não for possível alocar dinamicamente a
nova cadeia, a função deve retornar NULL. O protótipo da função é:
char *compactar(char *s);*/
#include <stdio.h>
#include <stdlib.h>
char *compactar(char *s);
int main(){
    int num = 100, n_e_letra = 0;
    char *string = (char *) malloc(num * sizeof(char));
    if(string == NULL){
        printf("Nao alocou!\n");
        return 1;
    }
    while(1){
        n_e_letra = 0;
        printf("Digite uma frase de ate 100 caracteres: \n");
        scanf(" %[^\n]", string);
        for(int i = 0; string[i] != '\0'; i++){
            if((('a' <= string[i] && string[i] <= 'z') || ('A' <= string[i] && string[i] <= 'Z')) || string[i] == ' '){}
            else n_e_letra++;
        }
        if(n_e_letra) printf("Digite apenas letras\n");
        else break;
    }
    char *sem_espaco = compactar(string);
    if(sem_espaco == NULL)printf("Nao foi possivel alocar ou invalido!");
    else{
        printf("%s\n", sem_espaco);
        free(sem_espaco);
    }
    free(string);
    return 0;
}
char *compactar(char *s){
    int inicio = 0, fim = 0, tam_original = 0, pos = 0;
    while(s[inicio] == ' '){
        inicio++;
    }
    while(s[tam_original] != '\0') {
        tam_original++;
    }
    fim = tam_original - 1;
    while(s[fim] == ' '){
        fim--;
    }
    int nova_tam = (fim - inicio + 1);
    char* nova_cadeia = (char *) malloc((nova_tam + 1) * sizeof(char));
    if(nova_cadeia == NULL) return NULL;
    for(int j = inicio; j <= fim; j++){
        nova_cadeia[pos] = s[j];
        pos++;
    }
    nova_cadeia[pos] = '\0';
    return nova_cadeia;
}
