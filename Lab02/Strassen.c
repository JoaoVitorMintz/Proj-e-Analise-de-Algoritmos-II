#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int n) {
    int** mat = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*) calloc(n, sizeof(int));
    }
    return mat;
}

void liberaMatriz(int** mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

void soma(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtrai(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int** A11 = alocaMatriz(k); int** A12 = alocaMatriz(k);
    int** A21 = alocaMatriz(k); int** A22 = alocaMatriz(k);
    int** B11 = alocaMatriz(k); int** B12 = alocaMatriz(k);
    int** B21 = alocaMatriz(k); int** B22 = alocaMatriz(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    int** M1 = alocaMatriz(k); int** M2 = alocaMatriz(k);
    int** M3 = alocaMatriz(k); int** M4 = alocaMatriz(k);
    int** M5 = alocaMatriz(k); int** M6 = alocaMatriz(k);
    int** M7 = alocaMatriz(k);
    int** T1 = alocaMatriz(k); int** T2 = alocaMatriz(k);

    soma(A11, A22, T1, k);
    soma(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    soma(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    subtrai(B12, B22, T2, k);
    strassen(A11, T2, M3, k);

    subtrai(B21, B11, T2, k);
    strassen(A22, T2, M4, k);

    soma(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    subtrai(A21, A11, T1, k);
    soma(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    subtrai(A12, A22, T1, k);
    soma(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    int** C11 = alocaMatriz(k);
    int** C12 = alocaMatriz(k);
    int** C21 = alocaMatriz(k);
    int** C22 = alocaMatriz(k);

    soma(M1, M4, T1, k);
    subtrai(T1, M5, T2, k);
    soma(T2, M7, C11, k);

    soma(M3, M5, C12, k);

    soma(M2, M4, C21, k);

    subtrai(M1, M2, T1, k);
    soma(T1, M3, T2, k);
    soma(T2, M6, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    liberaMatriz(A11, k); liberaMatriz(A12, k);
    liberaMatriz(A21, k); liberaMatriz(A22, k);
    liberaMatriz(B11, k); liberaMatriz(B12, k);
    liberaMatriz(B21, k); liberaMatriz(B22, k);
    liberaMatriz(M1, k); liberaMatriz(M2, k);
    liberaMatriz(M3, k); liberaMatriz(M4, k);
    liberaMatriz(M5, k); liberaMatriz(M6, k);
    liberaMatriz(M7, k); liberaMatriz(T1, k);
    liberaMatriz(T2, k);
    liberaMatriz(C11, k); liberaMatriz(C12, k);
    liberaMatriz(C21, k); liberaMatriz(C22, k);
}

void imprimeMatriz(int** M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int n = 2;

    int** A = alocaMatriz(n);
    int** B = alocaMatriz(n);
    int** C = alocaMatriz(n);

    // Exemplo
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    strassen(A, B, C, n);

    printf("Resultado:\n");
    imprimeMatriz(C, n);

    liberaMatriz(A, n);
    liberaMatriz(B, n);
    liberaMatriz(C, n);

    return 0;
}