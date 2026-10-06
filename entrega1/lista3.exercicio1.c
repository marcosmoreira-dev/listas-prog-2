/* 1. Implemente a função calcula_circulo, que calcula a área e a circunferência de um círculo de raio
r. Essa função deve obedecer o protótipo:
void calc_circulo(float r, float * circunferencia, float * area);
Fórmulas:
A = π r
2 ; c = 2 π r ; π = 3.14159265
Note que essa passagem dos 2 últimos parâmetros é uma passagem por referência. */

#include <stdio.h>
#include <math.h>

#define PI 3.1415

void calc_circulo(float r, float *circunferencia, float *area) {
    *area = PI * r * r;
    *circunferencia = 2 * PI * r;
}

int main() {
    float r, area, circ;
    scanf("%f", &r);
    calc_circulo(r, &circ, &area);
    printf("c = %.2f\na = %2f", circ, area);
    return 0;
}
