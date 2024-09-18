#ifndef USUARIO_H
#define USUARIO_H

// Definir la estructura para los usuarios
struct Usuario {
    char curp[20];
    float saldo;
    int id;
};

// Declaración de funciones
void nuevoRegistro(struct Usuario usuarios[], int *contaregis);
void mostrarUsuarios(struct Usuario usuarios[], int contaregis);
void buscarRegistro(struct Usuario usuarios[], int contaregis);
void eliminarRegistro(struct Usuario usuarios[], int *contaregis);
void realizarTransaccion(struct Usuario usuarios[], int contaregis);

#endif