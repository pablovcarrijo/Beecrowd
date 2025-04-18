#include <stdlib.h>
#include <stdio.h>

void merge(int *vect, int inicio1, int fim1, int inicio2, int fim2){
    int i = inicio1, j = inicio2, k = 0;
    int *aux;

    aux = (int*)malloc((fim2 - inicio1 + 1) * sizeof(int));

    while(i <= fim1 && j <= fim2){
        if(vect[i] > vect[j]){
            aux[k++] = vect[i++];
        }
        else {
            aux[k++] = vect[j++];
        }
    }

    while(i <= fim1){
        aux[k++] = vect[i++];
    }
    while(j <= fim2){
        aux[k++] = vect[j++];
    }

    for(int i = inicio1, j = 0; i <= fim2; i++, j++){
        vect[i] = aux[j];
    }
    free(aux);

}

void merge_sort(int *vect, int inicio, int fim){
    if(inicio >= fim) return;
    int meio = (inicio + fim) / 2;
    merge_sort(vect, inicio, meio);
    merge_sort(vect, meio + 1, fim);

    merge(vect, inicio, meio, meio+1, fim);

}   

int main(){
    
    int n, m, count;
    int *fila;
    int *temp;
    
    scanf("%d*%c", &n);
    for(int i = 0; i < n; i++){
        count = 0;
        scanf("%d%*c", &m);

        fila = (int*)malloc(m * sizeof(int));
        temp = (int*)malloc(m * sizeof(int));

        for(int i = 0; i < m; i++){
            scanf("%d%*c", &fila[i]);
        }

        for(int i = 0; i < m; i++){
            temp[i] = fila[i];
        }

        merge_sort(temp, 0, m-1);

        for(int i = 0; i < m; i++){
            if(temp[i] == fila[i]){
                count ++;
            }
        }
        printf("%d\n", count);
        free(temp);
        free(fila);

    }

}

// #include <stdlib.h>
// #include <stdio.h>

// #define MAX 100000  // Definir um tamanho máximo para evitar malloc repetitivo

// int aux[MAX];  // Vetor auxiliar global para evitar malloc dentro de merge()

// void merge(int *vect, int inicio1, int fim1, int inicio2, int fim2) {
//     int i = inicio1, j = inicio2, k = 0;

//     while (i <= fim1 && j <= fim2) {
//         if (vect[i] > vect[j]) {  // Ordem decrescente
//             aux[k++] = vect[i++];
//         } else {
//             aux[k++] = vect[j++];
//         }
//     }

//     while (i <= fim1) {
//         aux[k++] = vect[i++];
//     }
//     while (j <= fim2) {
//         aux[k++] = vect[j++];
//     }

//     for (i = inicio1, k = 0; i <= fim2; i++, k++) {
//         vect[i] = aux[k];
//     }
// }

// void merge_sort(int *vect, int inicio, int fim) {
//     if (inicio >= fim) return;
//     int meio = (inicio + fim) / 2;
//     merge_sort(vect, inicio, meio);
//     merge_sort(vect, meio + 1, fim);
//     merge(vect, inicio, meio, meio + 1, fim);
// }   

// int main() {
//     int n, m, count;
    
//     int *fila = (int*)malloc(MAX * sizeof(int));  // Aloca uma vez só
//     int *temp = (int*)malloc(MAX * sizeof(int));

//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         count = 0;
//         scanf("%d", &m);

//         for (int j = 0; j < m; j++) {
//             scanf("%d", &fila[j]);
//             temp[j] = fila[j];  // Copia direto
//         }

//         merge_sort(temp, 0, m - 1);

//         for (int j = 0; j < m; j++) {
//             if (temp[j] == fila[j]) {
//                 count++;
//             }
//         }
//         printf("%d\n", count);
//     }

//     free(fila);
//     free(temp);
//     return 0;
// }
