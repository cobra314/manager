//
// Created by root on 7/2/20.
//

#ifndef MANAGER_FUNCIONES_H
#define MANAGER_FUNCIONES_H
#include "cadenaUtils.h"
#include "../structs/universidad.h"

struct Universidad obtenerUniversidad();
struct Universidad obtenerUniversidad() {

    char parametroUniversidad[50];
    printf("Escriba el nombre de la Universidad : ");
    gets(parametroUniversidad);
    int tam_cadena = tamanoCadena(parametroUniversidad);
    char tmpArreglo[tam_cadena];

    char *nombreUniversidad = &tmpArreglo[0];
    nombreUniversidad = (int *) malloc(tam_cadena * sizeof(int *));

    for (int i = 0; i < tam_cadena; i++) {
        *(nombreUniversidad + i) = parametroUniversidad[i];
    }

    struct Universidad universidad;
    universidad.tamanio_nombre = tam_cadena;
    universidad.nombre = nombreUniversidad;

    return universidad;
}

#endif //MANAGER_FUNCIONES_H
