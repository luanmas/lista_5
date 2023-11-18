#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT 0

void gerarValoresAleatorios(int *, int);
void exibirValores(int *, int);
void exibirMenorValor(int *, int);

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
    exibirMenorValor(pElementos , qtdElementos);

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

void exibirMenorValor(int *p , int q) {
    int *menorValor = (p+0);
    for(int j = 1; j < q; j++) {
        menorValor = *menorValor < *(p+j) ? menorValor : (p+j);
    }

    printf("Menor valor: %d | Endereço : %p\n", *menorValor, menorValor);
}