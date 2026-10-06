/*Faça um programa com funções para:
a. ler 7 valores inteiros e os armazene em um vetor;
b. listar o conteúdo do vetor com as referidas posições de armazenamento;
b. pesquisar no vetor um valor inteiro qualquer de entrada e retornar a posição deste valor.
Caso esse valor não esteja presente no vetor, então retornar –1;
c. trocar valores contidos no vetor pela seguinte política: cada elemento i dentro do vetor
será substituído pela soma de todos os (i-1) elementos mais o elemento i. Por exemplo, dado um
vetor [1; 2; 3; 4; 5], após a aplicação da função teríamos esse vetor preenchido com os seguintes
valores [1; 3; 6; 10; 15]. Para esta tarefa utilize um vetor auxiliar.*/
#include <stdio.h>
void criar_vetor(int* v);
void lista_poscont(int* v);
int pesquisa_valor(int* v);
void valor_politica(int* v);
int main(){
    int vetor[7];
    criar_vetor(vetor);
    lista_poscont(vetor);
    int posicao = pesquisa_valor(vetor);
    if(posicao != -1){
        printf("O valor esta ou aparece pela primeira vez na posicao: %i\n", posicao);
    }
    else printf("O valor nao esta no vetor");
    valor_politica(vetor);
    for(int m = 0; m < 7; m++){
        printf("%i ", vetor[m]);
    }
    return 0;
}
void criar_vetor(int* v){
    printf("Digite os elementos do vetor: \n");
    for(int i = 0; i < 7; i++){
        scanf("%i", &v[i]);
    }
}
void lista_poscont(int* v){
    for(int j = 0; j < 7; j++){
    printf("Posicao: %p ; Conteudo: %i\n", &v[j], v[j]);
    }
}
int pesquisa_valor(int* v){
    int valor, existe = 0, pos;
    printf("Valor de entrada: \n");
    scanf("%i", &valor);
    for(int k = 0; k < 7; k++){
        if(v[k] == valor){
            pos = k;
            existe++;
            break;
        }
    }
    if(existe) return pos;
    else return -1;
}
void valor_politica(int* v){
    int aux[7];
    aux[0] = v[0];
    for(int l = 1; l < 7; l++){
        aux[l] = v[l - 1] + v[l];
        v[l] = aux[l];
    }
}
