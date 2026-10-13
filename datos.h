#ifndef DATOS_H
#define DATOS_H

typedef struct {
    int id;
    char nombre[50];
    int *puntajes;
    int numPuntajes;
} Competidor;

Competidor* crearCompetidor(int id, char *nombre, int numPuntajes);
void liberarCompetidor(Competidor *c);
void mostrarCompetidor(Competidor *c);
int calcularTotal(Competidor *c);
float calcularPromedio(Competidor *c);

#endif