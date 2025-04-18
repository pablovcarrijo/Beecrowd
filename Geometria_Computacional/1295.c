#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordena(double *vetor, int inicio, int fim){
    int i = inicio, j = fim;
    int meio = (inicio + fim) / 2;
    
    if(inicio >= fim) return;

    while(i <= j){
        while(vetor[i] < vetor[meio]){
            i++;
        }
        while(vetor[j] > vetor[meio]){
            j--;
        }
        if(i <= j){
            double troca = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = troca;
            i++;
            j--;
        }
    }

    ordena(vetor, inicio, j);
    ordena(vetor, i, fim);

}

int main(){

    int n, x, y, **coordenadas, k;
    double *distance;

    while(scanf("%d", &n) && n != 0){

        distance = (double*)malloc((n*(n-1))/2 * sizeof(double));
        coordenadas = (int**)malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++){
            coordenadas[i] = (int*)malloc(2 * sizeof(int));
        }

        for(int i = 0; i < n; i++){
            scanf("%d%*c", &x);
            scanf("%d%*c", &y);
            coordenadas[i][0] = x;
            coordenadas[i][1] = y;
        }

        k = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double dx = coordenadas[i][0] - coordenadas[j][0];
                double dy = coordenadas[i][1] - coordenadas[j][1];
                distance[k++] = sqrt(dx * dx + dy * dy);

            }
        }

        ordena(distance, 0, k-1);

        if(distance[0] > 10000){
            printf("INFINITY\n");
        }
        else{
            printf("%.4f\n", distance[0]);
        }
        for(int i = 0; i < n; i++){
            free(coordenadas[i]);
        }
        free(coordenadas);
        free(distance);
    
    }
}