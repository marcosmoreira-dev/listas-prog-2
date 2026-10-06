/*  Implemente uma função que calcule as raízes de uma equação do segundo grau, 
do tipo ax2 + bx + c = 0. Observação: para o cálculo da raiz quadrada de um número, 
utilize a função sqrt. Consulte a documentação de como usá-la no programa.*/

#include<stdio.h>
#include<math.h>

double funcao(double raiz, double a, double b);
double funcaoo(double raiz, double a, double b);

int main(){

    double a, b, c, raiz, delta, x1, x2, ret, rett;

    do{
    printf("Coloque o parâmetro a: \n");
    scanf("%lf", &a);
    }while(a==0);

    printf("Coloque o parâmetro b: \n");
    scanf("%lf", &b);

    printf("Coloque o parâmetro c: \n");
    scanf("%lf", &c);

    delta = (b*b) -(4*a*c);
    if (delta>=0){
    raiz = sqrt(delta);
    }else{
        printf("Não é possível calcular");
        return 0;
    }

    ret = funcao(raiz,a,b);
    rett = funcaoo(raiz,a,b);

    printf("Esses são os resultados da equação de segundo grau: %.2lf  e %.2lf \n", ret, rett);
    return 0;
    }

    double funcao(double raiz, double a, double b){
        return (-b +raiz)/(2*a);
    }
    double funcaoo(double raiz, double a, double b){
        return (-b -raiz)/(2*a);
}
