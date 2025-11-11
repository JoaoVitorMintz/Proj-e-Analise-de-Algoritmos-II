#include <stdio.h>
#include <stdlib.h>

#define TAM 15

// Estrutura de árvore utilizando struct:
typedef struct Node {
    char simbolo;
    int freq;
    struct Node *esq, *dir;
} Node;

Node* alocar_no(char simbolo, int freq) {
    Node novo = (Node*) malloc(sizeof(Node));
    novo->simbolo = simbolo;
    novo->freq = freq;
    novo->dir = novo->esq = NULL;
    return novo;
}

void troca(Node** a, Node** b) {
    Node* temporario = *a;
    *a = *b;
    *b = temporario;
}

void heapify(Node* heap[], int n, int i) {
    int menor = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq<n && heap[dir]->freq < heap[menor]->freq) {
        menor = esq;
    }
    if (dir<n && heap[dir]->freq < heap[menor]->freq) {
        menor = dir;
    }
    if (menor != i) {
        troca(&heap[i], &heap[menor]);
        heapify(heap, n, menor);
    }
}


Node* Huffman(char C[], int f[], int n) {
    Node* Q[TAM];
    for (int i = 0; i < n; i++)
        Q[i] = alocar_no(C[i], f[i]);

    int tam = n;

    while (tam > 1) {
        Node* x = extrai_min(Q, &tam);
        Node* y = extrai_min(Q, &tam);
        Node* z = alocar_no('-', x->freq + y->freq);
        z->esq = x;
        z->dir = y;
        insere(Q, &tam, z);
    }

    return Q[0]; // raiz da árvore
}

int main() {
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] =  { 45,  13,  12,  16,   9,   5};

    int n = sizeof(letras) / sizeof(letras[0]);

    Node* raiz = Huffman(letras, freq, n);

    int arr[TAM], topo = 0;
    printf("Codigos de Huffman:\n");
    imprime_codigos(raiz, arr, topo);

    return 0;
}