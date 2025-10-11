#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int array[], int esq, int dir, int x) {
    if (esq > dir) return -1;
    else {
        int meio = (esq + dir)/2;
        if (array[meio] == x) {
            return meio;
        } else if (x < array[meio]) {
            buscaBinaria(array, esq, meio-1, x);
        } else {
            buscaBinaria(array, meio+1, dir, x);
        }
    }
}

int main() {
    int array[10] = {1, 3, 5, 7, 8, 10, 11, 15, 19, 23};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int valorBusca = 3;

    printf("%d", buscaBinaria(array, 0, arraySize, valorBusca));

    return 0;
}