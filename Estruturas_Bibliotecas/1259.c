#include <stdlib.h>
#include <stdio.h>

void ordena(int *vect, int inicio, int fim){
    int i = inicio, j = fim;
    int meio = (inicio + fim) / 2;
    int pivo = (vect[i] + vect[j] + vect[meio]) / 3;
    
    if(inicio >= fim) return;

    while(i <= j){
        while(vect[i] < pivo) i++;
        while(vect[j] > pivo) j--;

        if(i <= j){
            int troca = vect[i];
            vect[i] = vect[j];
            vect[j] = troca;
            i++;
            j--;
        }
    }

    if (inicio < j) ordena(vect, inicio, j);
    if(i < fim) ordena(vect, i, fim);

}

int main(){
    int *vetorPares, *vetorImpares, par = 0, im = 0, n, value;

    scanf("%d%*c", &n);
    
    vetorPares = (int*)malloc(n * sizeof(int));
    vetorImpares = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d%*c", &value);
        if(value % 2 == 0){
            vetorPares[par] = value;
            par++;
        }
        else {
            vetorImpares[im] = value;
            im++;
        }
    }

    ordena(vetorPares, 0, par - 1);
    ordena(vetorImpares, 0, im - 1);

    for(int i = 0; i < par; i++){
        printf("%d\n", vetorPares[i]);
    }


    for(int j = im-1; j >= 0; j--){
        printf("%d\n", vetorImpares[j]);
    }

    free(vetorPares);
    free(vetorImpares);
    
    return 0;

}