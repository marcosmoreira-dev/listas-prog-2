/*Modifique o programa anterior da seguinte forma:
a) Passo igual ao da questão 1.
b) Ao invés de calcular e imprimir na main as repetições, crie uma
função 'repeticao' para fazer esse trabalho. A função deve seguir o
protótipo
void repeticao(int *vet, int tam);
Onde 'vet' e 'tam' foram lidos no passo a).

- Exemplo de execução: idêntico ao anterior.
- Obs.: A impressão é feita dentro da função 'repeticao'.*/
#include <stdio.h>
#include <stdlib.h>
void repeticao(int *vet, int tam);
int main(){
    int tam;
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
    repeticao(vetor, tam);
    free(vetor);
    return 0;

}
void repeticao(int *vet, int tam){
    int ja_apareceu = 0,repete = 0, numero;
    printf("Aqueles que se repetem sao: \n");
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
            else printf("%i ", numero);
        }
    }
}
