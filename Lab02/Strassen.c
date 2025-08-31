#include <stdio.h>
#include <stdlib.h>

// Função para alocar matriz n x n
int** alocaMatriz(int n) {
    int** mat = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*) calloc(n, sizeof(int));
    }
    return mat;
}

// Função para liberar memória da matriz
void liberaMatriz(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Soma de matrizes C = A + B
void soma(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtração de matrizes C = A - B
void subtrai(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Algoritmo de Strassen
void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Aloca submatrizes
    int** A11 = alocaMatriz(k);
    int** A12 = alocaMatriz(k);
    int** A21 = alocaMatriz(k);
    int** A22 = alocaMatriz(k);
    int** B11 = alocaMatriz(k);
    int** B12 = alocaMatriz(k);
    int** B21 = alocaMatriz(k);
    int** B22 = alocaMatriz(k);

    // Divide A e B em quadrantes
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

    // Aloca matrizes auxiliares
    int** M1 = alocaMatriz(k);
    int** M2 = alocaMatriz(k);
    int** M3 = alocaMatriz(k);
    int** M4 = alocaMatriz(k);
    int** M5 = alocaMatriz(k);
    int** M6 = alocaMatriz(k);
    int** M7 = alocaMatriz(k);

    int** temp1 = alocaMatriz(k);
    int** temp2 = alocaMatriz(k);

    // Calcula M1 a M7
    soma(A11, A22, temp1, k);     // temp1 = A11 + A22
    soma(B11, B22, temp2, k);     // temp2 = B11 + B22
    strassen(temp1, temp2, M1, k);

    soma(A21, A22, temp1, k);     // temp1 = A21 + A22
    strassen(temp1, B11, M2, k);

    subtrai(B12, B22, temp2, k);  // temp2 = B12 - B22
    strassen(A11, temp2, M3, k);

    subtrai(B21, B11, temp2, k);  // temp2 = B21 - B11
    strassen(A22, temp2, M4, k);

    soma(A11, A12, temp1, k);     // temp1 = A11 + A12
    strassen(temp1, B22, M5, k);

    subtrai(A21, A11, temp1, k);  // temp1 = A21 - A11
    soma(B11, B12, temp2, k);     // temp2 = B11 + B12
    strassen(temp1, temp2, M6, k);

    subtrai(A12, A22, temp1, k);  // temp1 = A12 - A22
    soma(B21, B22, temp2, k);     // temp2 = B21 + B22
    strassen(temp1, temp2, M7, k);

    // Combina resultados em C
    int** C11 = alocaMatriz(k);
    int** C12 = alocaMatriz(k);
    int** C21 = alocaMatriz(k);
    int** C22 = alocaMatriz(k);

    // C11 = M1 + M4 - M5 + M7
    soma(M1, M4, temp1, k);
    subtrai(temp1, M5, temp2, k);
    soma(temp2, M7, C11, k);

    // C12 = M3 + M5
    soma(M3, M5, C12, k);

    // C21 = M2 + M4
    soma(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    subtrai(M1, M2, temp1, k);
    soma(temp1, M3, temp2, k);
    soma(temp2, M6, C22, k);

    // Junta quadrantes em C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    // Libera memória
    liberaMatriz(A11, k); liberaMatriz(A12, k);
    liberaMatriz(A21, k); liberaMatriz(A22, k);
    liberaMatriz(B11, k); liberaMatriz(B12, k);
    liberaMatriz(B21, k); liberaMatriz(B22, k);
    liberaMatriz(M1, k); liberaMatriz(M2, k);
    liberaMatriz(M3, k); liberaMatriz(M4, k);
    liberaMatriz(M5, k); liberaMatriz(M6, k);
    liberaMatriz(M7, k); liberaMatriz(temp1, k);
    liberaMatriz(temp2, k);
    liberaMatriz(C11, k); liberaMatriz(C12, k);
    liberaMatriz(C21, k); liberaMatriz(C22, k);
}

// Função para imprimir matriz
void imprimeMatriz(int** M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 2; // tamanho da matriz (deve ser potência de 2)
    
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
