#include <stdio.h>
#include <stdbool.h>

bool verifica(int palitos[], int tam, int index, int lados[], int lado_alvo) {
    if (index == tam) {
        return lados[0] == lado_alvo && lados[1] == lado_alvo &&
               lados[2] == lado_alvo && lados[3] == lado_alvo;
    }

    for (int i = 0; i < 4; i++) {
        if (lados[i] + palitos[index] <= lado_alvo) {
            lados[i] += palitos[index];

            if (verifica(palitos, tam, index + 1, lados, lado_alvo)) {
                return true;
            }

            lados[i] -= palitos[index];
        }
    }

    return false;
}

int main() {
    int palitos_de_fosforo[5] = {1, 4, 5, 5, 5};
    int tam = sizeof(palitos_de_fosforo) / sizeof(palitos_de_fosforo[0]);

    // calcula a soma total
    int soma = 0;
    for (int i = 0; i < tam; i++) soma += palitos_de_fosforo[i];

    if (soma % 4 != 0) {
        printf("Não pode construir um quadrado\n");
        return 0;
    }

    int lado_alvo = soma / 4;
    int lados[4] = {0, 0, 0, 0};

    if (verifica(palitos_de_fosforo, tam, 0, lados, lado_alvo)) {
        printf("Pode construir um quadrado\n");
    } else {
        printf("Não pode construir um quadrado\n");
    }

    return 0;
}
