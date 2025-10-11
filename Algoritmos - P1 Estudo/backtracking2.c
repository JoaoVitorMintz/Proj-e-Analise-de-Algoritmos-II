#include <stdio.h>

void printArray(int array[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf(", ");
}

void permutacao(int s[], int n, int index, int usado[], int v[]) {
    if (index == n) printArray(s, n);
    else {
        for (int i = 0; i <= n; i++) {
            if (!usado[i]) {
                s[index] = v[i];
                usado[i] = 1;
                permutacao(s, n, index + 1, usado, v);
                usado[i] = 0;
            }
            
        }
    }
}

int main() {
    int v[3] = {1, 2, 3};
    int s[3];
    int n = 3;
    int usado[3] = {0};

    permutacao(s, n, 0, usado, v);

    return 0;
}