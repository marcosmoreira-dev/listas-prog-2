// // 13. Fazer um programa para:
// a. declarar variáveis a, b, c, d do tipo int.
// b. declarar variáveis e, f, g, h do tipo float.
// c. declarar vetor v de 10 elementos do tipo char.
// d. declarar variável x do tipo int.
// e. criar um ponteiro apontando para o endereço de a.
// f. incrementar o ponteiro, mostrando o conteúdo do endereço apontado (em forma de número).
// Caso o endereço coincida com o endereço de alguma outra variável, informar o fato.

#include <stdio.h>
int main() {
    int a, b, c, d;
    float e, f, g, h;
    char v[10];
    int x;

    int *ptr = &a;

    printf("Endereço de a: %p\n", (void*)&a);
    printf("Endereço de b: %p\n", (void*)&b);
    printf("Endereço de c: %p\n", (void*)&c);
    printf("Endereço de d: %p\n", (void*)&d);
    printf("Endereço de e: %p\n", (void*)&e);
    printf("Endereço de f: %p\n", (void*)&f);
    printf("Endereço de g: %p\n", (void*)&g);
    printf("Endereço de h: %p\n", (void*)&h);
    printf("Endereço de v: %p\n", (void*)v);
    printf("Endereço de x: %p\n", (void*)&x);

    ptr++;

    printf("Conteúdo do endereço apontado pelo ponteiro após incremento: %d\n", *ptr);

    if ((void*)ptr == (void*)&b) {
        printf("O ponteiro agora aponta para b.\n");
    } else if ((void*)ptr == (void*)&c) {
        printf("O ponteiro agora aponta para c.\n");
    } else if ((void*)ptr == (void*)&d) {
        printf("O ponteiro agora aponta para d.\n");
    } else if ((void*)ptr == (void*)&e) {
        printf("O ponteiro agora aponta para e.\n");
    } else if ((void*)ptr == (void*)&f) {
        printf("O ponteiro agora aponta para f.\n");
    } else if ((void*)ptr == (void*)&g) {
        printf("O ponteiro agora aponta para g.\n");
    } else if ((void*)ptr == (void*)&h) {
        printf("O ponteiro agora aponta para h.\n");
    } else if ((void*)ptr == (void*)v) {
        printf("O ponteiro agora aponta para v.\n");
    } else if ((void*)ptr == (void*)&x) {
        printf("O ponteiro agora aponta para x.\n");
    } else {
        printf("O ponteiro não coincide com o endereço de nenhuma outra variável.\n");
    }
    return 0;
}
