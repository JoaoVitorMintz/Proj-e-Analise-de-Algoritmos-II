int exemplo(int arr[], int a, int b) {
    if (a < 1 || b < 1) return 0;
    int m = (a+b)/2;

    exemplo(arr, m, b);
    exemplo(arr, a, m);
    exemplo(arr, a, b);
    exemplo(arr, m, m);
}