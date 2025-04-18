#include <stdio.h>
#include <stdlib.h>

int main(){

    int x;
    while(scanf("%d%*c", &x) == 1){
        int *vetor;
        vetor = (int*)malloc(x * sizeof(int));
        for(int i = 0; i < x; i++){
            scanf("%d%*c", &vetor[i]);
        }
        for(int i = 0; i < x; i++){
            for(int j = i; j < x; j++){
                if(vetor[j] < vetor[i]){
                    int temp = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = temp;
                }
            }
        }

        for(int i = 0; i < x; i++){
            printf("%04d\n", vetor[i]);
        }
    }

}