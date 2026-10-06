/*Fazer uma função denominada divs() que:
a. recebe como parâmetro um número inteiro n por valor e dois números inteiros max e min por
referência;
b. retorna 0 se o número num é primo e 1 caso contrário. Se o número não for primo, as variáveis
max e min devem assumir os valores do menor e do maior divisores inteiros do número,
respectivamente, desconsiderando o número 1 e o próprio número num.*/
#include <stdio.h>
int divs(int n, int *max, int *min);
int main(){
    int num, maximo, minimo;
    printf("Digite um numero inteiro: \n");
    scanf("%i", &num);
    if (divs(num, &maximo, &minimo)){
        printf("O maior divisor e: %i\n", maximo);
        printf("O menor divisor e: %i\n", minimo);
    }
    else printf("%i e primo!(ou nao possui divisores)", num);
    return 0;
}
int divs(int n, int *max, int *min){
    if(n <= 1) return 0;
    int cont_div = 0;
    for(int i = n;i > 0; i--){
        if(n % i == 0) cont_div++;
    }
    if(cont_div == 2)return 0;
    else{
        for(int i = n - 1;i >= 2; i--){
            if(n % i == 0){
                *max = i; 
                break;
        }
    }
        for(int i = 2;i < n; i++){
            if(n % i == 0){
                *min = i; 
                break;
        }
        }
        return 1;
    }
}
