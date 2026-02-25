#include <stdio.h>
#include <stdlib.h>  // Para malloc e free
#include <time.h>    // Para o clock  

// Declaração de varaiveis globais
// Contagens de comparações e movimentações
long long comparacoes = 0; 
long long movimentacoes = 0;

// ##### Bubble Sort #####
void bubbleSort(int arr[], int n){
    int i, j, temp, trocou;
    comparacoes = 0;
    movimentacoes = 0;

    // printf("\nProcesso do Bubble Sort:\n");

    for(i = 0; i < n - 1; i++) {
        trocou = 0;
        // printf("\nPasso %d:\n", i);

        for(j = 0; j < n - 1; j++) {
            // printf("Comparando %d e %d\n", arr[j], arr[j + 1]);
            comparacoes++;
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
                movimentacoes++;
                // printf("Trocando %d e %d\n", arr[j], arr[j + 1]);
            }
        }

        // printf("Passagem %d concluida: ", i);
        /*
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        */

        if(trocou == 0) {
            // printf("Nenhuma troca ocorreu, array já está ordenado!\n");
            break;
        }
    }
}

// ##### Selection Sort #####
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    comparacoes = 0;
    movimentacoes = 0;

    // printf("\nProcesso do Selection Sort:\n");

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        // printf("\nPasso %d: Buscando o menor elemento a partir do Indice %d\n", i + 1, i);

        for (j = i + 1; j < n; j++) {
            // printf("Comparando %d e %d\n", arr[minIndex], arr[j]);
            comparacoes++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                // printf("Novo menor encontrado: %d\n", arr[minIndex]);
            }
        }

        if (minIndex != i) {
            // printf("Trocando %d com %d\n", arr[i], arr[minIndex]);
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            movimentacoes++;
        }
    }
}

// ##### Imprimir array #####
void imprimirArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    // Definição de diferentes tamanhos de vetores
    int tamanhos[] = {100, 1000, 10000};

    // Calcula o numero de tamanhos no array
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Nome de cada coluna
    printf("%-12s %-10s %-15s %-15s %-15s\n",
        "Algoritmo", "Tamanho", "Tempo(ms)", "Comparacoes", "Movimentacoes");

    // Loop para testar cada tamanho de vetor
    for(int t = 0; t < numTamanhos; t++){
        int tamanho = tamanhos[t];

        // ### Bubble Sort ###
        // Alocação dinamica de memaria de acordo com a qualidade de posições
        int *vetor = (int*) malloc(tamanho * sizeof(int));
        // Criação do vetor em ordem descrecente
        for (int i = 0; i < tamanho; i++) { 
            vetor[i] = tamanho - i; 
        }

        // Medição de tempo de execução (clock)
        clock_t inicio, fim;
        double tempo_ms;
        inicio = clock();
        bubbleSort(vetor, tamanho);
        fim = clock();
        tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

        // Imprime resultados para cada caracteristica de comparação
        printf("%-15s %-10d %-12.2f %-15I64d %-15I64d\n", 
            "Bubble Sort", tamanho, tempo_ms, comparacoes, movimentacoes);
        
        // Libera a memória
        free(vetor);

        // ### Selection Sort ###
        vetor = (int*) malloc(tamanho * sizeof(int));
        for(int i = 0; i < tamanho; i++) {
            vetor[i] = tamanho - i;
        }

        inicio = clock();
        selectionSort(vetor, tamanho);
        fim = clock();
        tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

        printf("%-15s %-10d %-12.2f %-15I64d %-15I64d\n", 
            "Selection Sort", tamanho, tempo_ms, comparacoes, movimentacoes);

        free(vetor);
    }

    return 0;
}


// Desenvolvido no VSCODE
// Linguagem C