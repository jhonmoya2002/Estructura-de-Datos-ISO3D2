#ifndef JUGADOR_H
#define JUGADOR_H
#define MAX_NOMBRE 4
typedef struct {
    char iniciales[MAX_NOMBRE];
    int puntaje;
} Jugador;
Jugador crearJugador();
void mostrarJugador(Jugador j);
#endif
