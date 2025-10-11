#include <stdio.h>

void printArray(int array[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf(", ");
}

void backtracking(int s[], int v[], int n, int index) {
    if (index == n) printArray(s, n);
    else {
        for (int i = 0; i <= n-1; i++) {
        s[index] = v[i];
        backtracking(s, v, n, index + 1);
        }
    }
}

int main() {
    int n = 3;
    int v[3] = {1, 2, 3};
    int s[3];

    backtracking(s, v, n, 0);

    return 0;
}