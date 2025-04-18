#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double v, js, jc, i;
    int m;
    while(scanf("%lf %lf %d", &v, &i, &m) == 3){
        js = i * v * m;

        jc = v * pow((1 + i), m);

        printf("DIFERENCA DE VALOR = %.2lf\n", ((jc - js)-v) + 1e-9);
        printf("JUROS SIMPLES = %.2lf\n", js + 1e-9);
        printf("JUROS COMPOSTO = %.2lf\n", (jc - v) + 1e-9);
    }

    return 0;

}