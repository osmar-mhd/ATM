#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

#define SALDO_INICIAL 10000.0

// Función para agregar un nuevo registro
void nuevoRegistro(struct Usuario usuarios[], int *contaregis) {
    if (*contaregis < 100) {
        struct Usuario nuevo;
        nuevo.id = *contaregis + 1;
        nuevo.saldo = SALDO_INICIAL; // Asignar saldo inicial

        printf("A- Nuevo Registro.\n");
        printf("\t Datos del registro:\n");

        // Leer la CURP del usuario
        printf("\t Curp: ");
        fgets(nuevo.curp, sizeof(nuevo.curp), stdin);
        // Eliminar el salto de línea del final si existe
        nuevo.curp[strcspn(nuevo.curp, "\n")] = '\0';

        usuarios[*contaregis] = nuevo; // Guardar el usuario en el array
        (*contaregis)++; // Incrementar el contador de registros

        printf("****Registro completado.****\n");
        printf("\t Curp: %s\n", nuevo.curp);
        printf("\t ID: %d\n", nuevo.id);
        printf("\t Saldo Inicial: %.2f\n", nuevo.saldo);
        printf("Presione cualquier tecla para continuar...");
        getchar();  // Esperar una tecla para continuar
    } else {
        printf("Límite de registros alcanzado.\n");
    }
}

// Función para mostrar todos los usuarios registrados
void mostrarUsuarios(struct Usuario usuarios[], int contaregis) {
    if (contaregis == 0) {
        printf("No hay registros.\n");
    } else {
        for (int i = 0; i < contaregis; i++) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Curp: %s\n", usuarios[i].curp);
            printf("Saldo: %.2f\n", usuarios[i].saldo);
            printf("-----------------------------\n");
        }
    }
    printf("Presione cualquier tecla para continuar...");
    getchar();  // Esperar una tecla para continuar
}

// Función para buscar un registro por ID
void buscarRegistro(struct Usuario usuarios[], int contaregis) {
    int id;
    int encontrado = 0;
    printf("Ingrese el ID a buscar: ");
    scanf("%d", &id);
    getchar();  // Limpiar el buffer después de la lectura

    for (int i = 0; i < contaregis; i++) {
        if (usuarios[i].id == id) {
            printf("Registro encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Curp: %s\n", usuarios[i].curp);
            printf("Saldo: %.2f\n", usuarios[i].saldo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un registro con el ID %d.\n", id);
    }

    printf("Presione cualquier tecla para continuar...");
    getchar();  // Esperar una tecla para continuar
}

// Función para eliminar un registro por ID
void eliminarRegistro(struct Usuario usuarios[], int *contaregis) {
    int id;
    int encontrado = 0;
    printf("Ingrese el ID del registro a eliminar: ");
    scanf("%d", &id);
    getchar();  // Limpiar el buffer después de la lectura

    for (int i = 0; i < *contaregis; i++) {
        if (usuarios[i].id == id) {
            // Desplazar los registros hacia arriba para sobreescribir el eliminado
            for (int j = i; j < *contaregis - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*contaregis)--; // Reducir el contador de registros
            encontrado = 1;
            printf("Registro con ID %d eliminado.\n", id);
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un registro con el ID %d.\n", id);
    }

    printf("Presione cualquier tecla para continuar...");
    getchar();  // Esperar una tecla para continuar
}

// Nueva función para manejar transacciones
void realizarTransaccion(struct Usuario usuarios[], int contaregis) {
    int id;
    float monto;
    int encontrado = 0;

    printf("Ingrese el ID del usuario para realizar la transacción: ");
    scanf("%d", &id);
    getchar();  // Limpiar el buffer después de la lectura

    for (int i = 0; i < contaregis; i++) {
        if (usuarios[i].id == id) {
            printf("Ingrese el monto a retirar: ");
            scanf("%f", &monto);
            getchar();  // Limpiar el buffer después de la lectura

            if (monto > usuarios[i].saldo) {
                printf("Saldo insuficiente.\n");
            } else {
                usuarios[i].saldo -= monto;
                printf("Transacción exitosa.\n");
                printf("Saldo restante: %.2f\n", usuarios[i].saldo);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un usuario con el ID %d.\n", id);
    }

    printf("Presione cualquier tecla para continuar...");
    getchar();  // Esperar una tecla para continuar
}
