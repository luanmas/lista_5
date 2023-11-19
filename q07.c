#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT 0

void gerarValoresAleatorios(int *,int *, int);
void exibirValores(int *, int);
double *calcMSE(int *,int *, int , double *);

int main (int argc , char *argv[]) {
    int *pVetorA;
    int *pVetorB;
    double *mse;
    if(argc < 2) {
        puts("Necessário colocar a quantidade de elementos!");
        exit(1);
    }
    int qtdElementos = atoi(argv[1]);
    pVetorA = malloc(qtdElementos * sizeof(int));
    pVetorB = malloc(qtdElementos * sizeof(int));
    mse = malloc(1 * sizeof(int));

    gerarValoresAleatorios(pVetorA, pVetorB, qtdElementos);
    exibirValores(pVetorA, qtdElementos);
    exibirValores(pVetorB, qtdElementos);
    calcMSE(pVetorA, pVetorB, qtdElementos, mse);

    printf("Valor MSE: %.2f\n" , *mse);

    free(mse);
    free(pVetorA);
    free(pVetorB);
}

void gerarValoresAleatorios (int *a, int *b, int q) {
    srand(time(NULL));
    for(int i = 0; i < q; i++) {
        *(a+i) =  INIT + rand() % 100; 
    }

    for(int k = 0;k < q; k++) {
        *(b+k) =  INIT + rand() % 100; 
    }
}

void exibirValores(int *p , int q) {
    for(int k = 0; k < q; k++) {
        printf("Valor 0%d : %d | Endereço : %p\n", k+1, *(p+k), p+k);
    }
    puts("================");
}

double *calcMSE (int *a, int *b, int q, double *mse) {
    int diferenca;
    double somaQuadrados = 0.0;

    for(int i = 0; i < q; i++) {
        diferenca = abs(*(a+i) - *(b+i));
        somaQuadrados += (diferenca * diferenca);
    }

    *mse = (somaQuadrados / q);
    return mse;
}