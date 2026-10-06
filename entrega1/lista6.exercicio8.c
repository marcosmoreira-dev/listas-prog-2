/*Modifique novamente o seu programa da seguinte forma:
a) Passo igual aos das questões 1 e 2.
b) A sua função repeticao não mais imprimirá o resultado, mas sim a
main. Para isso, será necessário que a sua função 'repeticao' siga o
seguinte protótipo:
int *repeticao(int *vet, int tam, int *n);
A sua função 'repeticao' agora alocará um novo vetor de inteiros
dinamicamente que deverá ser preenchido com os valores que se repetem.
O tamanho desse vetor deve ser gravado na variável n, que referencia
uma variável na main (crie uma variável na main para isso). A função
'repeticao' retornará para a main este novo vetor resposta.
c) Imprima na main o vetor retornado pela função 'repeticao'.

- Exemplo de execução do programa:
> Entradas:
tam = 9
vet = |1|5|8|4|4|5|0|8|8|
> Valores contidos nas variáveis após a execução da função 'repeticao'
(não devem ser exibidos):
n = 3
resposta = |5|8|4|
> Saída:
5, 8, 4*/
#include <stdio.h>
#include <stdlib.h>
int *repeticao(int *vet, int tam, int *n);
int main(){
    int tam,num;
    printf("Tamanho do vetor: \n");
    while(1){
        scanf("%i", &tam);
        if(tam <= 0) printf("Invalido!\n");
        else break;
    }
    int* vetor = (int*) malloc(tam * sizeof(int));
    if(vetor == NULL){
        printf("Nao alocou\n");
        return 1;
    }
    printf("Diga os elementos do vetor: \n");
    for(int i = 0; i < tam; i++){
        while(1){
            scanf("%i", &vetor[i]);
            if(vetor[i] < 0 || vetor[i] > 9) printf("Invalido\n");
            else break;
        }
    }
    int* repetem = repeticao(vetor, tam, &num);
    free(vetor);
    if(repetem == NULL){
        printf("Invalido ou sem repeticoes \n");
        return 1;
    }
    else{
        printf("Aqueles que repetem sao: \n");
        for(int j = 0; j < num; j++){
            printf("%i ", repetem[j]);
        }
        free(repetem);
    }
    return 0;
}
int *repeticao(int *vet, int tam, int *n){
    *n = 0;
    int ja_apareceu = 0,repete = 0, numero, pos = 0;
    for(int j = 0; j < tam; j++){
        ja_apareceu = 0;
        repete = 0;
        numero = vet[j];
        for(int k = 0; k < tam; k++){
            if(numero == vet[k]) repete++;
        }
        if(repete >= 2){
            for(int l = j - 1; l >= 0; l--){
                if(vet[l] == numero) ja_apareceu = 1;
            }
            if(ja_apareceu){}
            else (*n)++;
        }
    }
    if(*n == 0)return NULL;
    int* repeticoes = (int*) malloc(*n * sizeof(int));
    if(repeticoes == NULL)return NULL;
        for(int j = 0; j < tam; j++){
        ja_apareceu = 0;
        repete = 0;
        numero = vet[j];
        for(int k = 0; k < tam; k++){
            if(numero == vet[k]) repete++;
        }
        if(repete >= 2){
            for(int l = j - 1; l >= 0; l--){
                if(vet[l] == numero) ja_apareceu = 1;
            }
            if(ja_apareceu){}
            else {
                repeticoes[pos] = numero;
                pos++;
            }
        }
    }
    return repeticoes;
}
