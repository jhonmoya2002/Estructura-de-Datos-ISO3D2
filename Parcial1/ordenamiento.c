#include "ordenamiento.h"
#include <stdio.h>

void bubbleSort(Competidor **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (calcularTotal(*(arr + j)) < calcularTotal(*(arr + j + 1))) {
                Competidor *temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void selectionSort(Competidor **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (calcularTotal(*(arr + j)) > calcularTotal(*(arr + maxIdx))) {
                maxIdx = j;
            }
        }
        Competidor *temp = *(arr + i);
        *(arr + i) = *(arr + maxIdx);
        *(arr + maxIdx) = temp;
    }
}

void insertionSort(Competidor **arr, int n) {
    for (int i = 1; i < n; i++) {
        Competidor *key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && calcularTotal(*(arr + j)) < calcularTotal(key)) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

void mostrarArreglo(Competidor **arr, int n) {
    for (int i = 0; i < n; i++) {
        mostrarCompetidor(*(arr + i));
    }
}
