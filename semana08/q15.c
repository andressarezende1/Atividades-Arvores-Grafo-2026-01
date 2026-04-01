#include <stdio.h>

void BubbleSort(int dados[], int tamanho){
    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - 1; j++){
            if(dados[j] > dados[j+1]){
                int temp = dados[j];
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

int pesquisaBinaria(int dados[], int esquerda, int direita, int alvo, int *comparacoes){
    *comparacoes = 0;
    while(esquerda <= direita){
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda)/2;
        if(dados[meio] == alvo){
            return meio;
        } else if(dados[meio] < alvo){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[] = {88, 23, 45, 12, 67, 34, 90, 10};
    int tamanho = sizeof(dados)/sizeof(dados[0]);
    int alvo = 67;
    int comparacoes;

    printf("Array original (nao ordenado): ");
    exibirArray(dados, tamanho);
    printf("\n");

    printf("\nBusca binaria antes da ordenacao:\n");
    int resultadoAntes = pesquisaBinaria(dados, 0, tamanho-1, alvo, &comparacoes);
    if(resultadoAntes != -1){
        printf("Valor %d encontrado!\n", alvo);
        printf("Na posicao: %d\n", resultadoAntes);
        printf("Comparacoes realizadas: %d\n", comparacoes);
    } else {
        printf("Valor %d nao encontrado\n", alvo);
        printf("Comparacoes realizadas: %d\n", comparacoes);
    }

    BubbleSort(dados, tamanho);

    printf("\nArray ordenado: ");
    exibirArray(dados, tamanho);
    printf("\n");

    printf("\nBusca binaria apos a ordenacao:\n");
    int resultadoDepois = pesquisaBinaria(dados, 0, tamanho-1, alvo, &comparacoes);
    if(resultadoDepois != -1){
        printf("Valor %d encontrado!\n", alvo);
        printf("Na posicao: %d\n", resultadoDepois); 
        printf("Comparacoes realizadas: %d\n", comparacoes);
    } else {
        printf("Valor %d nao encontrado\n", alvo);
        printf("Comparacoes realizadas: %d\n", comparacoes);
    }

    return 0;
}


/*
Quando a busca binaria foi realizada com o conjunto de dados sem ordenação o custo de comparacoes aumentaram e não foi encontrado o alvo, já com a pesquisa dos dados já ordenados o custo diminuiu e teve mais eficiencia em localizar o alvo.
*/