#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main() {
    int X[N], Y[N];
    int M[N][N] = {0};

    srand(time(NULL));

    for (int i = 0; i < N; ++i) {
        X[i] = rand() % N;
        Y[i] = rand() % N;
    }

    printf("Vetor X: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", X[i]);
    }
    printf("\n");

    printf("Vetor Y: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    for (int i = 0; i < N; ++i) {
        M[X[i]][Y[i]]++;
    }

    printf("\nMatriz M (coocorrências):\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
