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
    int *valoresExtremos;
    valoresExtremos = malloc(2 * sizeof(int));
    int *maiorValor = p+0;
    int *menorValor = p+0;
    for(int k = 1; k < q; k++) {
        menorValor = *menorValor < *(p+k) ? menorValor : (p+k);
    }
    valoresExtremos = menorValor;

    for(int j = 1; j < q; j++) {
        maiorValor = *maiorValor > *(p+j) ? maiorValor : (p+j);
    }
    valoresExtremos = maiorValor;
    printf("Maior valor: %d | Endereço : %p\n", *valoresExtremos, valoresExtremos);
    printf("Menor valor: %d | Endereço : %p\n", *(valoresExtremos+1), (valoresExtremos+1));
}