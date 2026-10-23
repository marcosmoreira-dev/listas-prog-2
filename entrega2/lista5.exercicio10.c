/*10. Fazer um programa para cadastro e diálogo de login. O programa deve:
a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente os
caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.
b. Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.
c. Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos
descritos nos itens a e b.
d. Comparar o nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário, informar “Acesso
negado”.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int compara(char* u, char* s, char* nu, char* su){
    if(strlen(u) != strlen(nu)) return 0;
    if(strlen(s) != strlen(su)) return 0;
    for(int j = 0; nu[j] != '\0'; j++){
        if(u[j] != nu[j]) return 0;
    }
    for(int k = 0; su[k] != '\0'; k++){
        if(s[k] != su[k]) return 0;
    }
    return 1;
}
int main(){
    int indice = 0;
    char* user = (char*) malloc(9 *sizeof(char));
    char* senha = (char*) malloc(9 * sizeof(char));
    if(user == NULL) return 1;
    printf("Digite o nome de usuario: \n");
    while(indice < 8){
        char l = getch();
        if(l == '\r') break;
        if((l >= '0' && l <= '9') || (l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')){
            user[indice] = l;
            putchar(l);
            indice++;
        }
    }
    user[indice] = '\0';
    indice = 0;
    printf("\nUsuario %s cadastrado\n", user);
    printf("Cadastre a senha: \n");
    while(indice < 8){
        char s = getch();
        if(s == '\r') break;
        if((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')){
            senha[indice] = s;
            putchar('*');
            indice++;
        }
    }
    senha[indice] = '\0';
    printf("\nSenha cadastrada!\n");
    printf("Fazer login: \n");
    while(1){
        char* novo_user = (char*) malloc(9 *sizeof(char));
        if(novo_user == NULL) return 1;
        char* senha_user = (char*) malloc(9 *sizeof(char));
        if(senha_user == NULL) return 1;
        indice = 0;
        while(indice < 8){
            char l = getch();
            if(l == '\r') break;
            if((l >= '0' && l <= '9') || (l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')){
                novo_user[indice] = l;
                putchar(l);
                indice++;
            }
        }
        novo_user[indice] = '\0';
        printf("\n");
        indice = 0;
        while(indice < 8){
            char s = getch();
            if(s == '\r') break;
            if((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')){
                senha_user[indice] = s;
                putchar('*');
                indice++;
            }
        }
        senha_user[indice] = '\0';
        if(compara(user, senha, novo_user, senha_user)){
            printf("\nOK\n"); 
            free(senha_user);
            free(novo_user);
            break;
        }
        else{
            printf("\nAcesso negado\n");
            free(senha_user);
            free(novo_user);
        }
    }
    free(user);
    free(senha);
    return 0;
}