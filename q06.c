#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarValoresAleatorios(int *, int);
void exibirValores(int *, int);
void calcMediaVetor(int *, int);
void calcMedianaVetor(int *, int); 

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
    // calcMediaVetor(pElementos , qtdElementos);
    calcMedianaVetor(pElementos , qtdElementos);

    free(pElementos);
}

void gerarValoresAleatorios (int *p, int q) {
    srand(time(NULL));
    for(int i = 0; i < q; i++) {
        *(p+i) = rand() % 15;
    }
}

void exibirValores(int *p , int q) {
    for(int k = 0; k < q; k++) {
        printf("Valor 0%d : %d | Endereço : %p\n", k+1, *(p+k), p+k);
    }
}

void calcMediaVetor(int *p , int q) {
    int media = 0;

    for(int j = 0; j < q; j++) {
        media += *(p+j);
    }

    printf("Media : %d\n" , (media/q));
}

void calcMedianaVetor(int *p , int q) {     
    float valorMediana;
    for (int i = 0; i < q - 1; i++) {
        for(int j = 0; j < q - 1 - i; j++) {
            if(*(p+j) > *(p+j+1)){
                int temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;                
            }
        }
    }

    puts("=============\n");
    puts("Valores ordenados:\n");
    exibirValores(p , q);

    if(!(q % 2)){
        valorMediana = (*(p+(q/2)) + *(p+((q/2) - 1))) / 2;
        printf("Mediana : %.2f" , valorMediana);
    }else {
        valorMediana = *(p+(q/2));
        printf("Mediana : %.2f" , valorMediana);
    }

}