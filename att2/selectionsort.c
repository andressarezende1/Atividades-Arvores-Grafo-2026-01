#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Seleciona o menor valor da lista e coloca na primeira posição. Seleciona o segundo menor valor e coloca na segunda posição...

void selectionsort(int arr[], int n){
    int i, j, minIndex, temp, trocou = 0, compara = 0;

    for(i = 0; i < n -1; i++){ // percorre todas as posições
        minIndex = i; // define que o menor valor está na posição arr[0] - POR ENQUANTO

        for(j = i + 1; j < n; j++){ // percorre todos os valores de todas posições
            compara++; // contabiliza uma comparação
            printf("Comparando %d e %d\n", arr[minIndex], arr[j]); // compara o valor da posição arr[0] com o proximo arr[1]
            if(arr[j] < arr[minIndex]){ // se o arr[1] for menor que o arr[0]
                minIndex = j; // então encontra o menor valor, redefine o menor valor para o valor(j) do arr[1] POR ENQUANTO
                printf("Novo valor menor encontrado: %d\n", arr[minIndex]);
            }
        }
        temp = arr[minIndex]; // define a primeira posição como arr[minIndex] (j) 
        arr[minIndex] = arr[i]; // faz a troca do valor da posição arr[minIndex] p/ arr[i] - linha 11
        arr[i] = temp; // define o novo valor para a primeira posição POR ENQUANTO
        trocou++; // contabiliza uma troca
        printf("Trocou o %d por %d\n", arr[i], arr[minIndex]);
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

    selectionsort(arr, n);

    printf("\nArray ordenado: ");
    printArray(arr, n);

    clock_t inicio, fim;
    double tempo_ms;
    inicio = clock();
    selectionsort(arr, n);
    fim = clock();
    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f ms\n", tempo_ms);

    return 0;
}
