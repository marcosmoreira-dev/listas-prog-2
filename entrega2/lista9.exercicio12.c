/*12. Criar um tipo Livro e um tipo Biblioteca tal como dado abaixo:
(A) Criar uma função Livro * fillLivro() que preenche os campos da estrutura Livro e retorna
esse novo livro.
(B) Criar uma função Biblioteca * fillBiblioteca(int numLivros) que preenche os campos da
estrutura do tipo Biblioteca realizando chamadas a função fillLivro em um número de vezes igual
ao número contido na variável numLivros.
(C) Criar uma função void valorBiblioteca(Biblioteca * b1, int numLivros) que fornece o
montante gasto para se comprar todos os exemplares existentes na biblioteca.
(D) Criar uma função Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) que retorna o livro
com maior número de exemplares.
(E) Criar um programa que ilustra o funcionamento das funções anteriores.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Livro {
int ano;
char titulo[100];
char autor[100];
int nVolume; // Número de exemplares de um dado livro.
float preco;
}Livro;
typedef struct Biblioteca {
Livro **V; // Armazena a informação de n livros !!
int nLivros; // Número de livros existentes na biblioteca.
}Biblioteca;
Livro * fillLivro(){
    Livro * l;
    l = (Livro*) malloc(sizeof(Livro));
    if(l == NULL) return NULL;
    printf("\nAno de lancamento do livro: \n");
    scanf("%i", &l->ano);
    printf("Titulo do Livro: \n");
    scanf(" %[^\n]", l->titulo);
    printf("Nome do autor: \n");
    scanf(" %[^\n]", l->autor);
    printf("Numero de exemplares: \n");
    scanf("%i", &l->nVolume);
    printf("Preco do livro em R$: \n");
    scanf("%f", &l->preco);
    return l;
}
Biblioteca * fillBiblioteca(int numLivros){
    Biblioteca* b = (Biblioteca*) malloc(sizeof(Biblioteca));
    if(b == NULL) return NULL;
    b->nLivros = numLivros;
    b->V = (Livro**) malloc(numLivros * sizeof(Livro*));
    for(int i = 0; i < numLivros;i++){
        b->V[i] = fillLivro();
    }
    return b;
}
void valorBiblioteca(Biblioteca * b1, int numLivros){
    float montante = 0;
    for(int j = 0; j < numLivros; j++){
        montante += (b1->V[j]->preco * b1->V[j]->nVolume);
    }
    printf("\nMontante gasto para comprar todos os exemplares R$%.2f\n", montante);
}
Livro * maiorBiblioteca(Biblioteca * b1, int numLivros){
    Livro *maior_livro = b1->V[0];
    for(int k = 0; k < numLivros; k++){
        if(b1->V[k]->nVolume > maior_livro->nVolume) maior_livro = b1->V[k];
        }
    return maior_livro;
}
int main(){
    int n_livros;
    printf("Biblioteca\n");
    printf("Numero de livros: \n");
    while(1){
        scanf("%i", &n_livros);
        if(n_livros > 0) break;
        else printf("Invalido\n");
    }
    Biblioteca* biblioteca = fillBiblioteca(n_livros);
    if(biblioteca == NULL) return 1;
    valorBiblioteca(biblioteca, n_livros);
    printf("\nLivro com maior numero de exemplares: \n");
    Livro* mais_exmp = maiorBiblioteca(biblioteca, n_livros);
    if(mais_exmp == NULL) return 1;
    printf("Titulo: %s", mais_exmp->titulo);
    for(int i = 0; i < biblioteca->nLivros; i++) free(biblioteca->V[i]);
    free(biblioteca->V);
    free(biblioteca);
    return 0;
}