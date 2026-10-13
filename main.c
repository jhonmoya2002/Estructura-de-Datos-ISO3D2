#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "datos.h"
#include "ordenamiento.h"

int main() {
    srand(time(NULL));
    int n = 5;
    int numPuntajes = 3;

    Competidor* competidores[5];

    // Crear 5 competidores de ejemplo
    competidores[0] = crearCompetidor(1, "Juan", numPuntajes);
    competidores[1] = crearCompetidor(2, "Ana", numPuntajes);
    competidores[2] = crearCompetidor(3, "Luis", numPuntajes);
    competidores[3] = crearCompetidor(4, "Maria", numPuntajes);
    competidores[4] = crearCompetidor(5, "Carlos", numPuntajes);

    printf("=== ANTES DE ORDENAR ===\n");
    for(int i=0; i<n; i++) {
        mostrarCompetidor(competidores[i]);
    }

    bubbleSort(competidores, n);
    printf("\n=== DESPUES DE ORDENAR ===\n");
    for(int i=0; i<n; i++) {
        mostrarCompetidor(competidores[i]);
    }

    // Liberar memoria
    for(int i=0; i<n; i++) {
        free(competidores[i]->puntajes);
        free(competidores[i]);
    }

    return 0;
}