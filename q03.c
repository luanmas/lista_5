#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT 0

void gerarValoresAleatorios(int *, int);
void exibirValores(int *, int);
void exibirValoresExtremos(int *, int);

int main (int argc , char *argv[]) {
    int *pElementos;
    if(argc < 2) {
        puts("Necessário colocar a quantidade de elementos!");
        exit(1);
    }
    int qtdElementos = atoi(argv[1]);
    pElementos = malloc(qtdElementos * sizeof(int));

    if(pElementos == NULL) {
        puts("Memória não alocada!");
        exit(1);
    }

    gerarValoresAleatorios(pElementos, qtdElementos);
    exibirValores(pElementos, qtdElementos);
    exibirValoresExtremos(pElementos , qtdElementos);

    free(pElementos);
}

void gerarValoresAleatorios (int *p, int q) {
    srand(time(NULL));
    for(int i = 0; i < q; i++) {
        *(p+i) =  INIT + rand() % 100; 
    }
}

void exibirValores(int *p , int q) {
    for(int k = 0; k < q; k++) {
        printf("Valor 0%d : %d | Endereço : %p\n", k+1, *(p+k), p+k);
    }
}

void exibirValoresExtremos(int *p , int q) {
    int *valoresExtremos = malloc(2 * sizeof(int));

    if (valoresExtremos == NULL) {
        puts("Memória não alocada!");
        exit(2);
    }

    int *maiorValor = p;
    int *menorValor = p;

    for (int k = 1; k < q; k++) {
        if (*(p + k) > *maiorValor) {
            maiorValor = p+k;
        }
        if (*(p + k) < *menorValor) {
            menorValor = p+k;
        }
    }

    valoresExtremos[0] = *menorValor;
    valoresExtremos[1] = *maiorValor;

    printf("Maior valor: %d | Endereço : %p\n", valoresExtremos[1], maiorValor);
    printf("Menor valor: %d | Endereço : %p\n", valoresExtremos[0], menorValor);

    free(valoresExtremos);
}