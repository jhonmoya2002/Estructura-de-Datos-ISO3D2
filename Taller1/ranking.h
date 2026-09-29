#ifndef RANKING_H
#define RANKING_H
#include "Jugador.h"

#define MAX_RANKING 3

typedef struct {
    Jugador top[MAX_RANKING];
    int cantidad;
} Ranking;

void inicializarRanking(Ranking* r);
int intentarAgregar(Ranking* r, Jugador nuevo);
void mostrarRanking(Ranking r);

#endif
