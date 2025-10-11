#include <stdio.h>

#define n 8

int subSeq(int nums[n],int index, int prev) {
    int maxLen = 0;

    for (int i = index; i < n; i++) {
        if (nums[i] > prev) {
            int len = 1 + subSeq(nums, nums[i], i+1);
            if (len > maxLen) maxLen = len;
        }
    }
    return maxLen;
}

int main() {
    int nums[n] = {10, 9, 2, 5, 3, 7, 101, 18};

    printf("Entrada: nums = [");
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("]");

    int resultado = subSeq(nums, 0, -1000000);

    printf("\nSaida: %d", resultado);

    return 0;
}