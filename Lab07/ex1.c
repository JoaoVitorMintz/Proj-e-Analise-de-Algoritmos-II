#include <stdio.h>

int subSeq(int v[], int index, int n, int maiorAtual, int comprimentoAtual);

int main()
{
    int vetor[8] = {10,9,2,5,3,7,101,18};
    int n = sizeof(vetor) / sizeof(int);
    
    
    printf("Quantidade da maior subsequência crescente: %d", subSeq(vetor, 0, n, -1, 0));
    
    return 0;
}

int subSeq(int v[], int index, int n, int maiorAtual, int comprimentoAtual) {
    if (index == n) return comprimentoAtual;
    
    int comElemAtual = 0;
    int semElemAtual = 0;
    
    if (v[index] > maiorAtual) {
        comElemAtual = subSeq(v, index + 1, n, v[index], comprimentoAtual + 1);
    }  
        semElemAtual = subSeq(v, index + 1, n, maiorAtual, comprimentoAtual);
        
        if (comElemAtual > semElemAtual) {
            return comElemAtual;
        } else {
            return semElemAtual;
        }
}