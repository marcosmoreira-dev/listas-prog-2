/*Seja o seguinte trecho de programa:
int i=3,j=5;
int *p, *q;
p = &i;
q = &j;
Qual é o valor das seguintes expressões ?
a) p == &i; b) *p - *q c) **&p d) 3* - *p/(*q)+7*/
#include <stdio.h>
int main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    if(p == &i) printf("a) True\n");
    else printf("a) False\n");
    int b = *p - *q;
    printf("b) %i\n", b);
    int c = **&p;
    printf("c) %i\n", c);
    int d = 3 * - *p / (*q) + 7;
    printf("d) %i\n", d);
    return 0;
}
