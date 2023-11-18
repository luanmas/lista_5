#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarValoresAleatorios(float *, int);
void exibirValores(float *, int);
void somatorioVetor(float *, int); 

int main (int argc , char *argv[]) {
    float *pElementos;
    if(argc < 2) {
        puts("Necessário colocar a quantidade de elementos!");
        exit(1);
    }
    int qtdElementos = atoi(argv[1]);
    pElementos = malloc(qtdElementos * sizeof(int));

    gerarValoresAleatorios(pElementos, qtdElementos);
    exibirValores(pElementos, qtdElementos);
    somatorioVetor(pElementos, qtdElementos);

    free(pElementos);
}

void gerarValoresAleatorios (float *p, int q) {
    srand(time(NULL));
    for(int i = 0; i < q; i++) {
        *(p+i) = ((float)rand() / RAND_MAX) * 100.0;
    }
}

void exibirValores(float *p , int q) {
    for(int k = 0; k < q; k++) {
        printf("Valor 0%d : %.2f | Endereço : %p\n", k+1, *(p+k), p+k);
    }
}

void somatorioVetor(float *p , int q) {
    float somatorio = 0.0;
    for(int j = 0; j < q; j++) {
        somatorio += *(p+j);
    }
    printf("Somatório Total : %.2f\n" , somatorio);
}