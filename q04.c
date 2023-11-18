#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT 0

void gerarValoresAleatorios(int *, int);
void exibirValores(int *, int);
void gettarValoresExtremos(int *p , int q);
// void normalizacaoDados(int *p , int q);

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
    // normalizacaoDados(pElementos , qtdElementos);
    gettarValoresExtremos(pElementos , qtdElementos);
    // puts("Valores Extremos \n");
    // exibirValores(valoresExtremos , 2);

    free(pElementos);
}

void gerarValoresAleatorios (int *p, int q) {
    srand(time(NULL));
    for(int i = 0; i < q; i++) {
        *(p+i) =  INIT + rand() % 50; 
    }
}

void exibirValores(int *p , int q) {
    for(int k = 0; k < q; k++) {
        printf("Valor 0%d : %d | Endereço : %p\n", k+1, *(p+k), p+k);
    }
}

void gettarValoresExtremos(int *p , int q) {
    int *valoresExtremos;
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

    valoresExtremos = menorValor;
    valoresExtremos = maiorValor;

    printf("Maior valor: %d | Endereço : %p\n", valoresExtremos[0], maiorValor);
    printf("Menor valor: %d | Endereço : %p\n", valoresExtremos[1], menorValor);
    free(valoresExtremos);
    // return valoresExtremos;
}

// void normalizacaoDados(int *p , int q) {
    // int *valoresExtremos = gettarValoresExtremos(p,q);
    // int *dadosNormalizado;

    // for(int k = 0; k < q; k++) {
    //     *dadosNormalizado = (*(p+k) + valoresExtremos[0]) / (valoresExtremos[1] - valoresExtremos[0]);      
    // }
    // puts("\n\nNormalização de dados :");
    // exibirValores(dadosNormalizado, q);
    // printf("Maior valor : %d\n" , valoresExtremos[0]);
    // printf("Menor valor : %d" , valoresExtremos[1]);
// }