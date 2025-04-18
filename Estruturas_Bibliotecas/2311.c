#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float dificuldade;
    float notas[7];
    float maxima;
} Atletas;

void merge(Atletas *atletas, int inicio1, int fim1, int inicio2, int fim2){
    int i = inicio1, j = inicio2, k = 0;
    Atletas *atletasTemp = (Atletas*)malloc((fim2 - inicio1 + 1) * sizeof(Atletas));

    while(i <= fim1 && j <= fim2){
        if(atletas[i].maxima < atletas[j].maxima){
            atletasTemp[k++] = atletas[i++];
        } else {
            atletasTemp[k++] = atletas[j++];
        }
    }

    while(i <= fim1){
        atletasTemp[k++] = atletas[i++];
    }
    while(j <= fim2){
        atletasTemp[k++] = atletas[j++];
    }

    for(i = inicio1, k = 0; i <= fim2; i++, k++){
        atletas[i] = atletasTemp[k];
    }

    free(atletasTemp);
}

void merge_sort(Atletas *atletas, int inicio, int final){
    if(inicio >= final) return;
    int meio = (inicio + final) / 2;
    merge_sort(atletas, inicio, meio);
    merge_sort(atletas, meio + 1, final);
    merge(atletas, inicio, meio, meio + 1, final);
}

void printar(Atletas *atletas, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%s %.2f\n", atletas[i].nome, atletas[i].maxima);
    }
}

int main(){
    int n;
    Atletas *atletas;
    
    scanf("%d%*c", &n);
    atletas = (Atletas*)malloc(n * sizeof(Atletas));

    for(int i = 0; i < n; i++){
        fgets(atletas[i].nome, 50, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0'; 

        scanf("%f%*c", &atletas[i].dificuldade);
        for(int j = 0; j < 7; j++){
            scanf("%f%*c", &atletas[i].notas[j]);
        }

        float maxima = atletas[i].notas[0], minima = atletas[i].notas[0];
        for(int j = 1; j < 7; j++){
            if(atletas[i].notas[j] > maxima) maxima = atletas[i].notas[j];
            if(atletas[i].notas[j] < minima) minima = atletas[i].notas[j];
        }

        atletas[i].maxima = 0;
        for(int j = 0; j < 7; j++){
            if(atletas[i].notas[j] == maxima || atletas[i].notas[j] == minima){
                continue;
            }
            else{
                atletas[i].maxima += atletas[i].notas[j];
            }
        }

        atletas[i].maxima *= atletas[i].dificuldade;
    }

    merge_sort(atletas, 0, n - 1);
    printar(atletas, n);

    free(atletas);
    return 0;
}
