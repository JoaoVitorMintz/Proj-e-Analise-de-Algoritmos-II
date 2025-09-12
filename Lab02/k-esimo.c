#include <stdio.h>

void bubbleSort(int arr[], int esq, int dir) {
    for (int i = esq; i <= dir; i++) {
        for (int j = esq; j < dir - (i - esq); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int medianaCincoElem(int arr[], int esq, int dir) {
    bubbleSort(arr, esq, dir);
    int n = dir - esq + 1;
    return arr[esq + n / 2];
}

int particionar(int arr[], int esq, int dir, int pivot) {
    int i;
    for (i = esq; i <= dir; i++) {
        if (arr[i] == pivot) {
            int temp = arr[i];
            arr[i] = arr[dir];
            arr[dir] = temp;
            break;
        }
    }

    int armazena = esq;
    for (i = esq; i < dir; i++) {
        if (arr[i] < pivot) {  
            int temp = arr[armazena];
            arr[armazena] = arr[i];
            arr[i] = temp;
            armazena++;
        }
    }

    int temp = arr[armazena];
    arr[armazena] = arr[dir];
    arr[dir] = temp;
    return armazena;
}

int selectK(int arr[], int left, int dir, int k) {
    if (left == dir)
        return arr[left];

    int numMedians = 0;
    int medians[(dir - left) / 5 + 1];
    
    for (int i = left; i <= dir; i += 5) {
        int subDir = i + 4;
        if (subDir > dir) subDir = dir;
        
        bubbleSort(arr, i, subDir);
        int n = subDir - i + 1;
        medians[numMedians] = arr[i + n / 2];
        numMedians++;
    }

    int medOfMed;
    if (numMedians == 1) {
        medOfMed = medians[0];
    } else {
        int tempArr[numMedians];
        for (int i = 0; i < numMedians; i++) {
            tempArr[i] = medians[i];
        }
        medOfMed = selectK(tempArr, 0, numMedians - 1, numMedians / 2 + 1);
    }

    int pivotIndex = particionar(arr, left, dir, medOfMed);
    int rank = pivotIndex - left + 1;

    if (k == rank)
        return arr[pivotIndex];
    else if (k < rank)
        return selectK(arr, left, pivotIndex - 1, k);
    else
        return selectK(arr, pivotIndex + 1, dir, k - rank);
}

int main() {
    int A[] = {7, 2, 1, 8, 6, 3, 5, 4, 10, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 4; 

    int kth = selectK(A, 0, n - 1, k);
    printf("k-ésimo menor elemento é: %d\n", kth);

    return 0;
}