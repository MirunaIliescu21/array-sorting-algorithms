#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // Ultimii i elemente sunt deja sortate, deci nu mai avem nevoie să le verificăm
        for (j = 0; j < n-i-1; j++) {
            // Comparăm elementul curent cu următorul și le interschimbăm dacă nu sunt în ordine
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vectorul nesortat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Apelăm funcția de sortare
    bubble_sort(arr, n);

    printf("\nVectorul sortat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

