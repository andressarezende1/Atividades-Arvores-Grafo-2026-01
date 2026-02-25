#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Compara os valores adjacentes e troca suas posições caso estiver errada. Realiza esse processo até que a lista esteja ordenada.

void bubblesort(int arr[], int n){
    int i, j, temp, trocou = 0, compara = 0;

    for(i = 0; i < n - 1; i++){ // percorre todas as posições
        for(j = 0; j < n - 1; j++){ // percorre todos os valores de todas posições
            compara++; // contabiliza uma comparação
            printf("Comparando %d e %d\n", arr[j], arr[j+1]); // compara o valor arr[0] com o seu adjacente arr[1]

            if(arr[j] > arr[j+1]){ // se o arr[0] for maior que o arr[1]
                temp = arr[j]; // define a primeira posição como arr[0]
                arr[j] = arr[j+1]; // faz a troca do valor da posição arr[1] p/ arr[0]
                arr[j+1] = temp; // define o novo valor para a primeira posição POR ENQUANTO

                trocou++; // contabiliza uma troca
                printf("Trocou o %d por %d\n", arr[j], arr[j+1]);
            }
        }
    }
    printf("Quantidade de comparacoes: %d", compara);
    printf("\nQuantidade de trocas: %d", trocou);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {64, 90, 34, 25, 5, 70, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    bubblesort(arr, n);

    printf("\nArray ordenado: ");
    printArray(arr, n);

    clock_t inicio, fim;
    double tempo_ms;
    inicio = clock();
    bubblesort(arr, n);
    fim = clock();
    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f ms\n", tempo_ms);

    return 0;
}
