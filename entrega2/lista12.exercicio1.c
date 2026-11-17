/*1. O que será impresso na tela?
int mdc_recursiva(int a, int b) {
printf("\n%d e %d", a, b);
if (a % b == 0) return b;
return mdc_recursiva (b, a % b);
}
int main() {
int a=32, b=18;
printf("\nResultado=%d",mdc_recursiva(a, b));
}*/
#include <stdio.h>
int main(){
    printf("\nSera impresso:\n32 e 18\n18 e 14\n14 e 4\n4 e 2\nResultado = 2");
}

