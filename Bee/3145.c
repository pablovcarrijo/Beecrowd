#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y;
    float calc;

    scanf("%d%*c", &y);
    scanf("%d%*c", &x);
    y += 2;
    calc = (float)x / (float)y;
    printf("%.2f\n", calc);

}