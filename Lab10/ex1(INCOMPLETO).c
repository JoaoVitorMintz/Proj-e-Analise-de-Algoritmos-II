#include <stdio.h>
#include <stdbool.h>

bool verifica(int palitos[], int tam, int index, int soma) {
    if (index == tam) return soma % 4 == 0;

    soma += palitos[index];

    return verifica(palitos, tam, index+1, soma);
    
}

int main() {

    int palitos_de_fosforo[5] = {1, 4, 5, 5, 5};
    int tam = sizeof(palitos_de_fosforo) / sizeof(palitos_de_fosforo[0]);

    if(verifica(palitos_de_fosforo, tam, 0, 0)) {
        printf("Pode construir um quadrado");
    } else {
        printf("Não pode construir um quadrado");
    }

    return 0;

}