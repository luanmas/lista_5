#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main() {
    int N;

    printf("Digite o tamanho da matriz N x N (max %d): ", MAX_SIZE);
    scanf("%d", &N);

    if (N <= 0 || N > MAX_SIZE) {
        printf("Tamanho da matriz inválido. Por favor, insira um valor entre 1 e %d.\n", MAX_SIZE);
        return 1;
    }

    int matriz[MAX_SIZE][MAX_SIZE];
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }

    // Exibe a matriz gerada
    printf("Matriz gerada:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    int somaDiagonal = 0;
    for (int i = 0; i < N; ++i) {
        somaDiagonal += matriz[i][i];
    }

    if (somaDiagonal % 2 == 0) {
        printf("\nA soma da diagonal principal e par.\n");
    } else {
        printf("\nA soma da diagonal principal e impar.\n");
    }

    return 0;
}
