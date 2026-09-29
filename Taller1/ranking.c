#include <stdio.h>
#include "ranking.h"
void inicializarRanking(Ranking* r){ r->cantidad=0; }
int intentarAgregar(Ranking* r, Jugador nuevo){
 if(r->cantidad<MAX_RANKING){ r->top[r->cantidad++]=nuevo; return 1; }
 int m=0; for(int i=1;i<r->cantidad;i++) if(r->top[i].puntaje<r->top[m].puntaje) m=i;
 if(nuevo.puntaje>r->top[m].puntaje){ r->top[m]=nuevo; return 1; } return 0;
}
void mostrarRanking(Ranking r){ printf("\n--- RANKING TOP 3 ---\n"); for(int i=0;i<r.cantidad;i++){ printf("%d. ",i+1); mostrarJugador(r.top[i]); } }
