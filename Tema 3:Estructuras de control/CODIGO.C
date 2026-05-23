#include <stdio.h>
#include <stdlib.h>

void limpiarBuffer() {
    while(getchar() != '\n');
}

void analizarNumero() {
    int x;

    printf("Dame un numero entero:\n");
    if(scanf("%d", &x) != 1) {
        printf("Entrada invalida\n");
        limpiarBuffer();
        return;
    }

    if(x % 2 == 0)
        printf("El numero %d es PAR\n", x);
    else
        printf("El numero %d es IMPAR\n", x);
}

void calculadora() {
    int x, y, opcion;

    printf("Dame 2 numeros enteros:\n");
    if(scanf("%d %d", &x, &y) != 2) {
        printf("Entrada invalida\n");
        limpiarBuffer();
        return;
    }

    printf("Selecciona una operacion:\n");
    printf("1) Sumar\n");
    printf("2) Restar\n");
    printf("3) Regresar\n");

    if(scanf("%d", &opcion) != 1) {
        printf("Entrada invalida\n");
        limpiarBuffer();
        return;
    }

    switch(opcion) {
        case 1:
            printf("Resultado: %d\n", x + y);
            break;
        case 2:
            printf("Resultado: %d\n", x - y);
            break;
        case 3:
            printf("Regresando al menu...\n");
            break;
        default:
            printf("Opcion invalida\n");
    }
}

void menu() {
    char opcion;

    while(1) {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("a) Analizar numero\n");
        printf("b) Calculadora\n");
        printf("c) Salir\n");

        if(scanf(" %c", &opcion) != 1) {   // ← AQUI ESTABA EL ERROR
            printf("Entrada invalida\n");
            limpiarBuffer();
            continue;
        }

        switch(opcion) {
            case 'a':
                analizarNumero();
                break;
            case 'b':
                calculadora();
                break;
            case 'c':
                printf("Adios mundo\n");
                return;
            default:
                printf("Opcion invalida\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
