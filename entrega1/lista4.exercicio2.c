/*Escreva um programa em C para ler um vetor R (de 5 elementos) e um vetor S (de 10
elementos). Gere um vetor X que possua os elementos comuns a R e a S. Considere que pode
existir repetição de elementos no mesmo vetor. Nesta situação somente uma ocorrência do
elemento comum aos dois deve ser copiada para o vetor X. Após o término da cópia, escrever o
vetor X.*/
#include <stdio.h>
int main(){
    int vetor_r[5], vetor_s[10], vetor_x[5], tam = 0, existe = 0;
    printf("Diga os elementos do vetor R: ");
    for(int i = 0; i < 5; i++){
        scanf("%i", &vetor_r[i]);
    }
    printf("Diga os elementos do vetor S: ");
    for(int j = 0; j < 10; j++){
        scanf("%i", &vetor_s[j]);
    }
    for(int m = 0; m < 5; m++){
        for(int n = 0; n < 10; n++){
            if(vetor_r[m] == vetor_s[n]){
                int nao_existe = 1;
                for(int o = 0; o < tam; o++){
                    if(vetor_r[m] == vetor_x[o]){
                        nao_existe = 0;
                        break;
                    }
                }
                if(nao_existe){
                    vetor_x[tam] = vetor_r[m];
                    tam++;
                }
                break;
            }
        }
    }
    for(int p = 0; p < tam; p++){
        printf("%i ", vetor_x[p]);
    }
    return 0;
}
