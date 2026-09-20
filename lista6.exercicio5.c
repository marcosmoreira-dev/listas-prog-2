/*Júlio César, o imperador romano, usava a Cifra de César para enviar ordens secretas
aos seus generais. Este código consiste em trocar cada letra de uma mensagem pela
terceira letra seguinte. Ou seja, a letra ‘a’ é substituída por ‘d’, ‘b’ é substituída por ‘e’,
‘c’ é substituída por ‘f’, e assim por diante. As exceções são as três últimas letras do
alfabeto, ‘x’, ‘y’ e ‘z’, que são substituídas, respectivamente, por ‘a’, ‘b’ e ‘c’. Por
exemplo, a palavra “zebra” se transformaria em “cheud”. Escreva uma função que
codifique uma mensagem de acordo com a Cifra de César, aplicando a codificação
apenas às letras da mensagem, maiúsculas ou minúsculas, e preservando os demais
caracteres. Essa função deve receber como parâmetro uma cadeia de caracteres com a
mensagem a ser codificada e retornar o ponteiro para uma nova cadeia de caracteres,
alocada dinamicamente, com a mensagem codificada. A cadeia de caracteres original
não pode ser alterada. A função deve ter o seguinte protótipo:
char* cifra_cesar(char* msg);*/
#include <stdio.h>
#include <stdlib.h>
char* compactar(char *s);
char* cifra_cesar(char* msg);
int main(){
    int num = 300, n_e_letra = 0;
    char* mensagem = (char *) malloc(num * sizeof(char));
    if(mensagem == NULL){
        printf("Nao alocou!\n");
        return 1;
    }
    while(1){
    n_e_letra = 0;
    printf("Digite uma frase de ate 300 caracteres: \n");
    scanf(" %[^\n]", mensagem);
    for(int i = 0; mensagem[i] != '\0'; i++){
        if((('a' <= mensagem[i] && mensagem[i] <= 'z') || ('A' <= mensagem[i] && mensagem[i] <= 'Z')) || mensagem[i] == ' '){}
        else n_e_letra++;
    }
    if(n_e_letra) printf("Digite apenas letras\n");
    else break;
    }
    char* mensagem_semesp = compactar(mensagem);
    if(mensagem_semesp == NULL){
        printf("Nao foi possivel alocar\n");
        return 1;
    }
    free(mensagem);
    char* mensagem_cifra = cifra_cesar(mensagem_semesp);
    free(mensagem_semesp);
    if(mensagem_cifra == NULL){
        printf("Nao foi possivel alocar");
        return 1;
    }
    else{
        printf("%s\n", mensagem_cifra);
        free(mensagem_cifra);
    }

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
char* cifra_cesar(char* msg){
    int tam = 0;
    for(int k = 0; msg[k] != '\0'; k++){
        tam++;
    }
    char* cifra = (char*) malloc((tam + 1)* sizeof(char));
    if(cifra == NULL) return NULL;
    for(int l = 0; l < tam; l++){
        if(msg[l] == 'x'){
            cifra[l] = 'a';
        }
        else if(msg[l] == 'X'){
            cifra[l] = 'A';
        }
        else if(msg[l] == 'y'){
            cifra[l] = 'b';
        }
        else if(msg[l] == 'Y'){
            cifra[l] = 'B';
        }
        else if(msg[l] == 'z'){
            cifra[l] = 'c';
        }
        else if(msg[l] == 'Z'){
            cifra[l] = 'C';
        }
        else if(msg[l] == ' '){
            cifra[l] = msg[l];
        }
        else{
            cifra[l] = msg[l] + 3;
        }
    }
    cifra[tam] = '\0';
    return cifra;
}
