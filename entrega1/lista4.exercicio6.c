/*A cadeia que representa a parte local de um endereço de e-mail Hotmail válido (aquela parte
que vem à esquerda do “@”) tem no máximo 64 caracteres e pode conter apenas letras (‘a’ a ‘z’) e
números (‘0’ a ‘9’), e os caracteres ponto (‘.’), hífen (‘-’) e sublinhado (‘_’). Quaisquer outros
caracteres especiais ou letras acentuadas não são permitidos. Além disso, a cadeia deve conter no
mínimo duas letras ou números, seu primeiro caractere tem que ser necessariamente uma letra, e
o caractere ponto (“.”) não pode aparecer em sequência ou ser o último da cadeia. Por exemplo,
“jsilva”, “t.o.n.y-99_”, “x-__7-” são strings válidas, enquanto “3marias”, “_peter”, “bia.”, “abc...z”
são incorretas. Escreva uma função em C que receba como parâmetros a cadeia s, representando
a parte local de um endereço de e-mail, e retorne 1 se a cadeia for válida de acordo com as
condições descritas, ou 0, se for inválida. A função deve ter o seguinte protótipo:
int valida_mail(char *s);*/
#include <stdio.h>
#include <stdlib.h>
int conta_char(char *s);
int valida_mail(char *s);
int main(){
    char *email = (char*) malloc (65 * sizeof(char));
    if (email == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    printf("Diga a parte local de um e-mail Hotmail: \n");
    scanf("%64s", email);
    if(valida_mail(email))printf("E-mail valido");
    else printf("Invalido");
    free(email);
    return 0;
}
int conta_char(char *s){
    int i = 0,cont = 0;
    while(s[i] != '\0'){
        cont++;
        i++;
    }
    return cont;
}
int valida_mail(char *s){
    int tam = conta_char(s);
    int letra_num = 0;
    if(tam == 0 || tam > 64)return 0;
    if(s[0] < 'a' || s[0] > 'z')return 0;
    if(s[tam - 1] == '.')return 0;
    for(int j = 0; j < tam - 1; j++){
        if(s[j] == '.' && s[j + 1] == '.')return 0;
    }
    for(int m = 0; m < tam; m++){
        if((s[m] >= 'a' && s[m] <= 'z') || (s[m] >= '0' && s[m] <= '9')){
            letra_num++;
        }
        else{
            if(s[m] != '.' && s[m] != '-' && s[m] != '_')return 0;
        }
    }
    if(letra_num < 2)return 0;
    else return 1;
}
