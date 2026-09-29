#include <stdio.h>
#include "jugador.h"

Jugador crearJugador() {
    Jugador j;
    printf("Ingresa iniciales (3 letras): ");
    scanf("%3s", j.iniciales);
    printf("Ingresa puntaje: ");
    scanf("%d", &j.puntaje);
    return j;
}

void mostrarJugador(Jugador j) {
    printf("%s - %d puntos\n", j.iniciales, j.puntaje);
}
