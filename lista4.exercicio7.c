/*Camel case é a denominação em inglês para a prática de escrever, a partir de palavras
compostas ou frases, expressões constituídas pelo agrupamento dessas palavras com a letra inicial
maíuscula e as demais minúsculas, unidas sem espaços. Por exemplo, “NotaDaProva” seria o
correspondente em camel case à expressão “nota da prova”. Este é um padrão muito utilizado
para a criação de nomes de entidades em diversas linguagens de programação, como Java, Ruby e
Python. Escreva uma função em C que recebe uma cadeia de caracteres e a transforma em uma
cadeia no padrão camel case, ou seja, remove os espaços em branco e converte para maiúsculas
as letras iniciais de cada palavra. Por simplificação, considere que a cadeia de entrada contém
apenas letras minúsculas (entre ‘a’ e ‘z’ e espaços em branco. Por exemplo, se a cadeia “media da
turma” for passada para a função, será transformada na cadeia “MediaDaTurma”. O protótipo da
função é:

void CamelCase (char *s);

Obs.: uma outra prática é manter a primeira letra minúscula. Por exemplo: “media da turma” será
transformada na cadeia “mediaDaTurma”. Escolha qual a forma mais apropriada.
char s[20];
strcpy(s,”media da turma”);
CamelCase(s);*/
#include <stdio.h>
char char_maius(char c);
void CamelCase(char* s);
int main(){
    char texto[20];
    printf("Escreva uma frase de no maximo 20 caracteres: \n");
    scanf(" %19[^\n]", texto);
    CamelCase(texto);
    printf("%s", texto);
}
char char_maius(char c){
    if (c >= 'a' && c <= 'z') c = (c - 'a') + 'A';
    return c;
}
void CamelCase(char* s){
    s[0] = char_maius(s[0]);
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] == ' '){
            s[i + 1] = char_maius(s[i + 1]);
            for(int j = i; s[j] != '\0'; j++){
                s[j] = s[j+1];
            }
            i--;
        }  
    }
}
