#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 200

typedef struct Node {
    char simbolo;
    int freq;
    struct Node *esq, *dir;
} Node;

Node* alocar_no(char simbolo, int freq) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->simbolo = simbolo;
    novo->freq = freq;
    novo->esq = novo->dir = NULL;
    return novo;
}

void troca(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(Node* heap[], int n, int i) {
    int menor = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < n && heap[esq]->freq < heap[menor]->freq)
        menor = esq;
    if (dir < n && heap[dir]->freq < heap[menor]->freq)
        menor = dir;
    if (menor != i) {
        troca(&heap[i], &heap[menor]);
        heapify(heap, n, menor);
    }
}

Node* extrai_min(Node* heap[], int* n) {
    Node* min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return min;
}

void insere(Node* heap[], int* n, Node* no) {
    int i = (*n)++;
    heap[i] = no;
    while (i != 0 && heap[(i-1)/2]->freq > heap[i]->freq) {
        troca(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
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
    return Q[0];
}

char codigos[256][50]; // armazena código de cada caractere

void gera_codigos(Node* raiz, char codigo[], int topo) {
    if (raiz->esq) {
        codigo[topo] = '0';
        gera_codigos(raiz->esq, codigo, topo+1);
    }
    if (raiz->dir) {
        codigo[topo] = '1';
        gera_codigos(raiz->dir, codigo, topo+1);
    }

    if (!raiz->esq && !raiz->dir) {
        codigo[topo] = '\0';
        strcpy(codigos[(unsigned char)raiz->simbolo], codigo);
    }
}

int compacta(char texto[], int bits[]) {
    int k = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char* codigo = codigos[(unsigned char)texto[i]];
        for (int j = 0; codigo[j] != '\0'; j++)
            bits[k++] = (codigo[j] == '1');
    }
    return k; // retorna quantidade de bits gerados
}

void descompacta(Node* raiz, int bits[], int tamBits) {
    Node* atual = raiz;

    printf("\nTexto descompactado: ");

    for (int i = 0; i < tamBits; i++) {
        if (bits[i] == 0)
            atual = atual->esq;
        else
            atual = atual->dir;

        if (!atual->esq && !atual->dir) {
            printf("%c", atual->simbolo);
            atual = raiz;
        }
    }
    printf("\n");
}

int main() {
    char letras[] = {'a','b','c','d','e','f'};
    int freq[] =  { 45,13,12,16,9, 5 };
    int n = sizeof(letras)/sizeof(letras[0]);

    Node* raiz = Huffman(letras, freq, n);

    char codigo[50];
    gera_codigos(raiz, codigo, 0);

    printf("Codigos Gerados:\n");
    for (int i = 0; i < n; i++)
        printf("%c -> %s\n", letras[i], codigos[(unsigned char)letras[i]]);

    char texto[] = "face";
    printf("\nTexto original: %s\n", texto);

    int bits[TAM];
    int tamBits = compacta(texto, bits);

    printf("\nBits compactados: ");
    for (int i = 0; i < tamBits; i++)
        printf("%d", bits[i]);

    descompacta(raiz, bits, tamBits);

    return 0;
}