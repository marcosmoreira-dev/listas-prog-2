/*Escreva um programa que realize a leitura da idade, da altura e do sexo de n pessoas. Ao final,
mostre o número de mulheres com idade entre 20 e 35 anos e o número de homens com altura
maior que 1,80m. Calcule e mostre também a variância da altura.*/
#include <stdio.h>
void varianca_altura(int n, float *v_altura);
int main(){
    int sexo, quant_homens = 0, quant_mulheres = 0, num_pessoas, x = 1;
    while(x == 1){
        printf("Quantidade de pessoas: \n");
        scanf("%i", &num_pessoas);
        if(num_pessoas <= 0) printf("Tente Novamente:\n");
        else break;
    }
    int idade[num_pessoas];
    float altura[num_pessoas];
    for(int i = 0; i < num_pessoas; i++){
        printf("Diga o sexo: \n");
        printf("1. Masculino\n");
        printf("2. Feminino\n");
        scanf("%i", &sexo);
        printf("Informe a idade: ");
        scanf("%i", &idade[i]);
        printf("Informe a altura em metros: ");
        scanf("%f", &altura[i]);
        if(sexo == 2){
            if(idade[i] >= 20 && idade[i] <= 35){
                quant_mulheres++;
            }
        }
        else if(sexo == 1){
            if(altura[i] > 1.8)quant_homens++;
        }
    }
    printf("Mulheres com idade entre 20 e 35: %i\n", quant_mulheres);
    printf("Homens maiores que 1.80m: %i\n", quant_homens);
    varianca_altura(num_pessoas, altura);
    return 0;
}
void varianca_altura(int n, float *v_altura){
    float soma_altura = 0;
    float soma_diferencas = 0;
    float varianca;
    for(int j = 0; j < n; j++){
        soma_altura += v_altura[j];
    }
    float media = soma_altura / n;
    for(int m = 0; m < n; m++){
        float aux = v_altura[m] - media;
        soma_diferencas += aux * aux;
    }
    varianca = soma_diferencas / n;
    printf("A varianca das alturas e: %.2f", varianca);
}
