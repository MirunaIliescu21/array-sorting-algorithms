#include <stdio.h>

// Funcție pentru a găsi valoarea maximă într-un vector
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Funcție pentru a efectua sortarea după cifra specificată (exp)
void countingSort(int arr[], int n, int exp) {
    const int RADIX = 10; // Baza sistemului numeric (10 pentru sistemul zecimal)
    int output[n];
    int count[RADIX] = {0};

    // Contorizează aparițiile fiecărei cifre
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % RADIX]++;
    }

    // Actualizează count[i] pentru a conține pozițiile efective ale cifrelor în output[]
    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    // Construiește vectorul output[]
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    // Copiază vectorul output[] în arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Funcție pentru a efectua sortarea Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Aplică counting sort pentru fiecare cifră
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Funcție pentru a afișa un vector
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vectorul nesortat: ");
    printArray(arr, n);

    // Aplică Radix Sort
    radixSort(arr, n);

    printf("Vectorul sortat: ");
    printArray(arr, n);

    return 0;
}

