#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// divide a lista ao meio, ordena cada metade recursivamente 
// e depois intercala as duas partes ordenadas

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
    int trocou = 0, compara = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; 

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        compara++;
        printf("Comparando %d e %d\n", L[i], R[j]);

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            trocou++; 
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printf("Arr apos a fusao: ");
    printArray(arr, right + 1);

    printf("Quantidade de comparacoes: %d\n", compara);
    printf("Quantidade de trocas: %d\n", trocou);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[] = {64, 90, 34, 25, 5, 70, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArray ordenado: ");
    printArray(arr, n);

    clock_t inicio = clock();
    mergeSort(arr, 0, n - 1);
    clock_t fim = clock();
    double tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f ms\n", tempo_ms);

    return 0;
}