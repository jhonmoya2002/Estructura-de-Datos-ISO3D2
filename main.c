#include <stdio.h>
#include <stdlib.h>


typedef struct Contenedor {
    int id;
    float pesoVacio; // Tara
    float pesoCarga;
    float pesoTotal;
    float precio;
    struct Contenedor *anterior;
    struct Contenedor *siguiente;
} Contenedor;


Contenedor *inicio = NULL;
Contenedor *fin = NULL;
int contadorID = 1;

void insertarContenedor() {
        Contenedor *nuevo = (Contenedor*)malloc(sizeof(Contenedor));
    if (nuevo == NULL) {
        printf("\nError: No hay memoria disponible.\n");
        return;
    }

    nuevo->id = contadorID++;
    printf("\n--- Nuevo Contenedor ID: %d ---\n", nuevo->id);
    printf("Peso vacio (Tara): ");
    scanf("%f", &nuevo->pesoVacio);
    printf("Peso de carga: ");
    scanf("%f", &nuevo->pesoCarga);
    printf("Precio o costo asociado: ");
    scanf("%f", &nuevo->precio);


    nuevo->pesoTotal = nuevo->pesoVacio + nuevo->pesoCarga;

    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;


    if (inicio == NULL) {
        inicio = fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        nuevo->anterior = fin;
        fin = nuevo;
    }
    printf("Contenedor registrado con exito. Peso Total: %.2f\n", nuevo->pesoTotal);
}


Contenedor* buscarContenedor(int id) {
    Contenedor *actual = inicio;
    while (actual != NULL) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void mostrarBusqueda() {
    int id;
    printf("\nIngrese ID a buscar: ");
    scanf("%d", &id);
    Contenedor *encontrado = buscarContenedor(id);
    if (encontrado == NULL) {
        printf("No se encontro contenedor con ID %d\n", id);
    } else {
        printf("\n--- Contenedor Encontrado ---\n");
        printf("ID: %d\n", encontrado->id);
        printf("Peso Vacio (Tara): %.2f\n", encontrado->pesoVacio);
        printf("Peso Carga: %.2f\n", encontrado->pesoCarga);
        printf("Peso Total: %.2f\n", encontrado->pesoTotal);
        printf("Precio: %.2f\n", encontrado->precio);
    }
}


void actualizarContenedor() {
    int id;
    printf("\nIngrese ID a actualizar: ");
    scanf("%d", &id);
    Contenedor *encontrado = buscarContenedor(id);
    if (encontrado == NULL) {
        printf("No se encontro contenedor con ID %d\n", id);
        return;
    }
    printf("\nActualizando ID %d\n", id);
    printf("Nuevo Peso vacio (Tara): ");
    scanf("%f", &encontrado->pesoVacio);
    printf("Nuevo Peso de carga: ");
    scanf("%f", &encontrado->pesoCarga);
    printf("Nuevo Precio: ");
    scanf("%f", &encontrado->precio);
    encontrado->pesoTotal = encontrado->pesoVacio + encontrado->pesoCarga;
    printf("Actualizado con exito. Nuevo Peso Total: %.2f\n", encontrado->pesoTotal);
}


void eliminarContenedor() {
    int id;
    printf("\nIngrese ID a eliminar: ");
    scanf("%d", &id);
    Contenedor *encontrado = buscarContenedor(id);
    if (encontrado == NULL) {
        printf("No se encontro contenedor con ID %d\n", id);
        return;
    }
    
    if (encontrado->anterior != NULL) {
        encontrado->anterior->siguiente = encontrado->siguiente;
    } else {
        inicio = encontrado->siguiente; // Era el primero
    }
    if (encontrado->siguiente != NULL) {
        encontrado->siguiente->anterior = encontrado->anterior;
    } else {
        fin = encontrado->anterior; // Era el ultimo
    }
    free(encontrado); // Liberar memoria
    printf("Contenedor ID %d eliminado correctamente.\n", id);
}

void mostrarTodos() {
    if (inicio == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }
    printf("\n--- LISTA DE CONTENEDORES (Adelante) ---\n");
    Contenedor *actual = inicio;
    while (actual != NULL) {
        printf("ID: %d | Tara: %.2f | Carga: %.2f | Total: %.2f | Precio: %.2f\n",
               actual->id, actual->pesoVacio, actual->pesoCarga, actual->pesoTotal, actual->precio);
        actual = actual->siguiente;
    }
    printf("\n--- LISTA (Atras - Recorrido inverso) ---\n");
    actual = fin;
    while (actual != NULL) {
        printf("ID: %d | Total: %.2f\n", actual->id, actual->pesoTotal);
        actual = actual->anterior;
    }
}

void liberarMemoria() {
    Contenedor *actual = inicio;
    while (actual != NULL) {
        Contenedor *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

int main() {
    int opcion;
    do {
        printf("\n===== SISTEMA DE CONTENEDORES PORTUARIOS =====\n");
        printf("1. Insertar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar todos\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: insertarContenedor(); break;
            case 2: mostrarBusqueda(); break;
            case 3: actualizarContenedor(); break;
            case 4: eliminarContenedor(); break;
            case 5: mostrarTodos(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 0);

    liberarMemoria();
    return 0;
}