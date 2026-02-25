#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// escolhe um pivo, e separa em duas listas, (menor e maior que o pivo), 
// e realiza esse procedimento recursivamente.

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int trocou = 0, compara = 0;
    int pivot = arr[high]; // ultimo elemento
    int i = low - 1; // menor elemento

    printf("\n Partition de %d a %d com pivo %d\n", low, high, pivot);

    for (int j = low; j < high; j++){ // percorre toda a partição
        compara++; // contabiliza uma comparacao
        printf("Comparando %d e pivo %d\n", arr[j], pivot);

        if(arr[j] < pivot){ // se o elemento for menor que o pivo
            i++; // vai para o proximo
            if(i != j){ // se o atual i for diferente do j, antes comparado
                trocou++; // contabiliza uma troca
                printf("Trocando %d e %d\n", arr[i], arr[j]);
            }
            int temp = arr[i]; // define a posição temp
            arr[i] = arr[j]; // troca o i p/ j
            arr[j] = temp; // redefine o temp
        }
    }

    // Colocando o pivo na posicao correta
    int temp = arr[i+1]; // o temp é definido pela proxima posicao a ser analisada
    arr[i + 1] = arr[high]; // que troca para ser o da linha do pivo
    arr[high] = temp; // redefine o temp

    printf("Pivo %d colocado na posição correta (%d)\n", pivot, i+1);

    printf("Array apos posicao: ");
    printArray(arr, high + 1);

    printf("Quantidade de comparacoes: %d\n", compara);
    printf("Quantidade de trocas: %d\n", trocou);

    return i + 1; // retorna a posicao do pivo
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){
    int arr[] = {64, 90, 34, 25, 5, 70, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    quicksort(arr, 0, n -1);

    printf("\nArray ordenado: ");
    printArray(arr, n);

    clock_t inicio = clock();
    quicksort(arr, 0, n -1);
    clock_t fim = clock();
    double tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f ms\n", tempo_ms);

    return 0;
}