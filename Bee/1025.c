#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vetor, int n, int c){
    int resultado = -1, esquerda = 0, direita = n - 1;
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(vetor[meio] == c){
            resultado = meio;
            direita = meio - 1;
        }
        else if(vetor[meio] < c){
            esquerda = meio + 1;
        }
        else if(vetor[meio] > c){
            direita = meio - 1;
        }
    }
    return resultado;
}

void quick_sort(int *vetor, int n){
    int i, j, grupo, troca;

    if(n < 2){
        return;
    }
    else {
        grupo = vetor[n/2];
    }

    for(i = 0, j = n - 1; ; i++, j--){
            
        while(vetor[i] < grupo){
            i++;
        }

        while(vetor[j] > grupo){
            j--;
        }

        if(i >= j) break;
        else{
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
        }
    }

    quick_sort(vetor, i);
    quick_sort(vetor + i, n - i);

}

int main(){


    int n, c, k = 0;
    int *busca;
    int *vetor;

    while(1){
        scanf("%d %d%*c", &n, &c);
        if(n == 0 && c == 0) break;
        busca = (int *)malloc(c * sizeof(int));
        vetor = (int *)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d%*c", &vetor[i]);
        }
        for(int i = 0; i < c; i++){
            scanf("%d%*c", &busca[i]);
        }

        quick_sort(vetor, n);

        printf("CASE# %d:\n", ++k);
        for(int i = 0; i < c; i++){
            int pos = buscaBinaria(vetor, n, busca[i]);
            if(pos != -1){
                printf("%d found at %d\n", busca[i], pos + 1);
            }
            else{
                printf("%d not found\n", busca[i]);
            }

        }
        free(busca);
        free(vetor);

    }


}