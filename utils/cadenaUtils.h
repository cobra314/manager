//
// Created by root on 7/2/20.
//

#ifndef MANAGER_CADENAUTILS_H
#define MANAGER_CADENAUTILS_H

int tamanoCadena(char cadena[]);
int tamanoCadena(char cadena[])
{
    int largo=0;
    while (cadena[largo]!='\0')	largo++;
    return largo;
}

void imprimir (char * arreglo, int a);
void imprimir (char * arreglo, int tam) {
    int cont = 1;
    for (int i = 0; i < tam; i++) {
        printf("%c", *(arreglo + i));
        cont++;
    }
}

#endif //MANAGER_CADENAUTILS_H
