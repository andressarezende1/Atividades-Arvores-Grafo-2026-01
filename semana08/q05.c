#include <stdio.h>

void BubbleSort (int dados[], int tamanho){
    int i, j, temp;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - 1; j++){
            if(dados[j] > dados[j+1]){
                temp = dados[j];
                dados[j] = dados[j+1];
                dados[j+1] = temp;
            }
        }
    }
}

void exibirArray(int dados[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", dados[i]);
    }
}

int pesquisaBinaria(int dados[], int esquerda, int direita, int valor){
    int comparacoes = 0;
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == valor){
            return meio;
        } else if (dados[meio] < valor){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1;
}

int main(){
    int dados[] = {45, 12, 78, 3, 56, 89, 23, 67};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int valor = 78;

    printf("\nDados não ordenados:");
    exibirArray(dados, tamanho);

    BubbleSort(dados, tamanho);

    printf("\nDados ordenados:");
    exibirArray(dados, tamanho);

    printf("\n Iniciando a pesquisa...");
    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, valor);

    if(resultado != -1){
        printf("\nValor %d encontrado", valor);
    } else {
        printf("\nValor %d não encontrado", valor);
    }

    return 0;
}