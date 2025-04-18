#include <stdio.h>
#include <stdlib.h>

// Função de comparação para o qsort
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);  // Ordem decrescente
}

int main() {
    int N, K, L;
    scanf("%d", &N);  // Número de cartas
    int A[N], B[N];    // Vetores para armazenar os valores das cartas

    // Ler os valores de A (face da frente)
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Ler os valores de B (face de trás)
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    // Ler K e L
    scanf("%d %d", &K, &L);

    long long maxSoma = 0;

    // Somar as K cartas mais à esquerda
    long long somaFrente = 0;
    for (int i = 0; i < K; i++) {
        somaFrente += A[i];
    }

    // Array para armazenar as cartas viradas (as B que podem ser viradas)
    int viradas[K];

    // Vamos tentar pegar `x` cartas da esquerda e `K-x` da direita
    for (int x = 0; x <= K; x++) {
        // Inicializando as cartas viradas
        int idx = 0;
        long long somaFrenteAtual = somaFrente;

        // Pegar `x` cartas da esquerda
        for (int i = 0; i < x; i++) {
            viradas[idx++] = B[i];
        }

        // Pegar `K-x` cartas da direita
        for (int i = N - 1; i >= N - (K - x); i--) {
            somaFrenteAtual += A[i];
            viradas[idx++] = B[i];
        }

        // Ordenar as cartas viradas para escolher as L melhores
        qsort(viradas, K, sizeof(int), compare);

        // Soma das melhores L viradas
        long long somaTras = 0;
        for (int i = 0; i < L; i++) {
            somaTras += viradas[i];
        }

        // A soma final será somaFrente + somaTras
        long long totalSoma = somaFrenteAtual + somaTras;
        if (totalSoma > maxSoma) {
            maxSoma = totalSoma;  // Atualiza o máximo
        }
    }

    printf("%lld\n", maxSoma);  // Exibe a maior pontuação possível

    return 0;
}
