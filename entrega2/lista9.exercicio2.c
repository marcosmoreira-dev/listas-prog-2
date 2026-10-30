/*Tendo o seguinte código:
typedef struct data {
int dia;
int mes;
char nomeMes[12];
} Data;
main()
{
Data aniversarios[3] = { {5,1,"JANEIRO"},
{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
int a;
Data *p_dt;
p_dt=&aniversarios[2];
printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
strcpy(p_dt->nomeMes, "MARÇO");
printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));
Data p_dt2 = (Data *) malloc(sizeof(Data));
p_dt2 = &aniversarios[0];
}
a. O programa acima pode ter no máximo 1 erro. Caso tiver, explique qual é o erro.
b. Qual o valor mostrado na tela no segundo (último) printf?*/
#include <stdio.h>
int main(){
    printf("a) O erro e que pdt2 nao foi definido como um ponteiro, mas sim como uma variavel simples.\nIsso vai causar um erro ao tentar atribuir um endereco ao p_dt2, como em p_dt2 = &aniversarios[0]\n");
    printf("b) Sera exbido o numero 5 das 5 letras que compoem MARCO\n");
    return 0;
}
