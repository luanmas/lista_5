#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarizarMatriz(int** M, int** S, int linhas, int colunas, int limiar) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (M[i][j] > limiar) {
                S[i][j] = 1;
            } else {
                S[i][j] = 0;
            }
        }
    }
}

void exibirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas, limiar;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    int** M = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; ++i) {
        M[i] = (int*)malloc(colunas * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            M[i][j] = rand() % 100;
        }
    }

    printf("\nMatriz M gerada:\n");
    exibirMatriz(M, linhas, colunas);

    printf("\nDigite o limiar (t): ");
    scanf("%d", &limiar);

    int** S = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; ++i) {
        S[i] = (int*)malloc(colunas * sizeof(int));
    }

    binarizarMatriz(M, S, linhas, colunas, limiar);

    printf("\nMatriz S resultante:\n");
    exibirMatriz(S, linhas, colunas);

    for (int i = 0; i < linhas; ++i) {
        free(M[i]);
        free(S[i]);
    }
    free(M);
    free(S);

    return 0;
}
