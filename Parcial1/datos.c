#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

Competidor* crearCompetidor(int id, char *nombre, int numPuntajes) {
    Competidor *c = (Competidor*) malloc(sizeof(Competidor));
    if (c == NULL) return NULL;
    c->id = id;
    strcpy(c->nombre, nombre);
    c->numPuntajes = numPuntajes;
    c->puntajes = (int*) malloc(numPuntajes * sizeof(int));
    
    for (int i = 0; i < numPuntajes; i++) {
        *(c->puntajes + i) = rand() % 100;
    }
    return c;
}

void liberarCompetidor(Competidor *c) {
    if (c != NULL) {
        free(c->puntajes);
        free(c);
    }
}

int calcularTotal(Competidor *c) {
    int total = 0;
    for (int i = 0; i < c->numPuntajes; i++) {
        total += *(c->puntajes + i);
    }
    return total;
}

float calcularPromedio(Competidor *c) {
    return (float)calcularTotal(c) / c->numPuntajes;
}

void mostrarCompetidor(Competidor *c) {
    printf("ID: %d | Nombre: %s | Total: %d | Prom: %.2f | Puntajes: ",
           c->id, c->nombre, calcularTotal(c), calcularPromedio(c));
    for (int i = 0; i < c->numPuntajes; i++) {
        printf("%d ", *(c->puntajes + i));
    }
    printf("\n");
}
