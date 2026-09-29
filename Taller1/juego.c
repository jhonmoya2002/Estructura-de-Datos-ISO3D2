#include <stdio.h>
#include "ranking.h"
int main(){ 
 Ranking r; 
 inicializarRanking(&r); 
 int n; 
 printf("Cuantos jugadores? "); 
 scanf("%d",&n); 
 for(int i=0;i<n;i++){ 
   Jugador j=crearJugador(); 
   intentarAgregar(&r,j); 
 } 
 mostrarRanking(r); 
 return 0; 
}
