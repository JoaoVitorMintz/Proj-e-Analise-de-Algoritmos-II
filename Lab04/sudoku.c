#include <stdio.h>

void mostra_matriz(int mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int pode_colocar_valor(int i, int mat[4][4], int lin, int col) {
    for (int k = 0; k < 4; k++) {
        if (mat[lin][k] == i) {
            return 0;
        }
    }

    for (int k = 0; k < 4; k++) {
        if (mat[k][col] == i) {
            return 0;
        }
    }

    int iniLin = lin - lin % 2;
    int iniCol = col - col % 2;

    for (int j = 0; j < 2; j++) {
        for (int x = 0; x < 2; x++) {
            if (mat[iniLin + j][iniCol + x] == i) return 0;
        }
    }
    return 1;
}

int sudoku(int mat[4][4], int lin, int col) {
    if (col == 4) {
        lin += 1;
        col = 0;
    }
    if (lin == 4) {
        mostra_matriz(mat);
    }
    else if (mat[lin][col] != 0) sudoku(mat, lin, col + 1);
    else {
        for (int i = 1; i <= 4; i++) {
            if (pode_colocar_valor(i, mat, lin, col)) {
                mat[lin][col] = i;
                sudoku(mat, lin, col + 1);
                mat[lin][col] = 0;
            }
        }
    }
}

int main() {
    int matriz[4][4] = {{0, 2, 4, 0}, {1, 0, 0, 3}, {4, 0, 0, 2}, {0, 1, 3, 0}};
    sudoku(matriz, 0, 0);
}
