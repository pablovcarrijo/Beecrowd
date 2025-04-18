#include <stdio.h>
#include <math.h>

double calcular(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    return (pow(phi, n) - pow(psi, n)) / sqrt(5);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%.1lf\n", calcular(n)); 
    return 0;
}
