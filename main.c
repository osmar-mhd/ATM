#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

// Prototipo de funciones
void mostrarMenu();

int main() {
    struct Usuario usuarios[100]; // Array de usuarios
    int contaregis = 0; // Contador de registros
    char op; // Menu
    char si = 's';

    // Intro
    printf("\t\t\t\t ATM.\n");

    // Menú principal
    do {
        mostrarMenu();
        printf("\nSeleccione una opción: ");
        scanf(" %c", &op);

        switch (op) {
            case 'A':
            case 'a':
                nuevoRegistro(usuarios, &contaregis);
                break;

            case 'B':
            case 'b':
                buscarRegistro(usuarios, contaregis);
                break;

            case 'C':
            case 'c':
                eliminarRegistro(usuarios, &contaregis);
                break;

            case 'D':
            case 'd':
                mostrarUsuarios(usuarios, contaregis);
                break;

            case 'E':
            case 'e':
                realizarTransaccion(usuarios, contaregis);
                break;

            case 'F':
            case 'f':
                printf("Saliendo del programa...\n");
                si = 'n';
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (si == 's' || si == 'S');

    return 0;
}

void mostrarMenu() {
    printf("\tMENU\n");
    printf("\tA- Nuevo Registro.\n");
    printf("\tB- Búsqueda de registro.\n");
    printf("\tC- Eliminación de registro.\n");
    printf("\tD- Mostrar todos los registros.\n");
    printf("\tE- Realizar transacción.\n");
    printf("\tF- Salir.\n");
}