#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// insere um valor na posição correta em uma pequena lista já ordenada. Ordenando aos poucos

void insertionsort(int arr[], int n){
    int i, j, chave, trocou = 0, compara = 0;
    for(i = 1; i < n; i++){// percorre todas as posições
        chave = arr[i]; // define a chave na posição arr[0] - POR EUQUANTO
        j = i - 1; // o j é a posição anterior ao i
        while (j >= 0 && arr[j] > chave){ // enquanto o j maior ou igual a 0 E o valor da posição j for maior que a chave
            compara++; // contabiliza uma comparacao 
            printf("Comparando %d e %d -> %d e maior, movendo para frente \n", arr[j], chave, arr[j]);
            arr[j+1] = arr[j]; // define a posição arr[0] p/ arr[j]
            trocou++; // contabiliza uma troca
            j--; // decrementa
        }
        arr[j+1] = chave; // atualiza a chave, linha 10 
        trocou++; 
        printf("Colocado %d na posicao correta\n", chave);
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

    insertionsort(arr, n);

    printf("\nArray ordenado: ");
    printArray(arr, n);

    clock_t inicio, fim;
    double tempo_ms;
    inicio = clock();
    insertionsort(arr, n);
    fim = clock();
    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f ms\n", tempo_ms);

    return 0;
}
