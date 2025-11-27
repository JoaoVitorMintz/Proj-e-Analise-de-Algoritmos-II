#include <stdio.h>

#define n 3
double x[n];

void ordenar(double v[], double w[], double d[]) {
    for (int i = 0; i < n; i++) {
        d[i] = v[i]/w[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (d[i] < d[j]) {
                double auxD = d[i];
                d[i] = d[j];
                d[j] = auxD;

                double auxW = w[i];
                w[i] = w[j];
                w[j] = auxW;

                double auxV = v[i];
                v[i] = v[j];
                v[j] = auxV;
            }
        }
    }
}

void mochila(double v[], double w[], double d[], int W) {
    ordenar(v, w, d);
    int i = 0;

    while (i < n && W > 0) {
        if (w[i] <= W) {
            x[i] = 1;
            W -= w[i];
        } else {
            x[i] = W/w[i];
            W = 0;
        }
        i++;
    }
}

int main() {
    double valores[n] = {60, 100, 120};
    double peso[n] = {10, 20, 30};
    double densidade[n];
    int W = 50;

    for (int i = 0; i < n; i++) x[i] = 0.0;

    mochila(valores, peso, densidade, W);

    for (int i = 0; i < n; i++) printf("%.2f ", x[i]);
    
    return 0;
}