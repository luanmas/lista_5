#include <stdio.h>
#include <stdlib.h>


int main (int argc , char * argv[]) {

    if(argc < 2) {
        puts("Necessário colocar os números e a operação!");
        exit(1);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    char op = *(argv[3]);

    switch (op) {
        case 's' :
        puts("Operação de soma escolhida\n");
        num1 += num2;
        break;

        case 'm' :
        puts("Operação de multiplicação escolhida\n");
        num1 *= num2;
        break;

        default :
        puts("Operação de soma escolhida\n");
        num1 += num2;
    }

    printf("Valor da operação : %d\n" , num1);
}