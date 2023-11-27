#include <stdio.h>
#include <stdlib.h>

// Funcție pentru a combina două subliste sortate într-o singură listă sortată
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crează subliste temporare
    int LeftSublist[n1], RightSublist[n2];

    // Copiază datele în sublistele temporare LeftSublist[] și RightSublist[]
    for (i = 0; i < n1; i++) {
        LeftSublist[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        RightSublist[j] = arr[middle + 1 + j];
    }

    // Interclasare: combină subliste
    i = 0; // Indexul inițial al primei subliste
    j = 0; // Indexul inițial al celei de-a doua subliste
    k = left; // Indexul inițial al listei combinate

    while (i < n1 && j < n2) {
        if (LeftSublist[i] <= RightSublist[j]) {
            arr[k] = LeftSublist[i];
            i++;
        } else {
            arr[k] = RightSublist[j];
            j++;
        }
        k++;
    }

    // Copiază elementele rămase din LeftSublist[], dacă există
    while (i < n1) {
        arr[k] = LeftSublist[i];
        i++;
        k++;
    }

    // Copiază elementele rămase din RightSublist[], dacă există
    while (j < n2) {
        arr[k] = RightSublist[j];
        j++;
        k++;
    }
}

// Funcție pentru a efectua sortarea Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Găsește punctul mijlociu al listei
        int middle = left + (right - left) / 2;

        // Sortează prima și a doua jumătate a listei
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combina cele două jumătăți sortate
        merge(arr, left, middle, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vectorul nesortat: ");
    printArray(arr, n);

    // Aplică Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Vectorul sortat: ");
    printArray(arr, n);

    return 0;
}

