#include <stdio.h>

int pesquisaBinaria(int arr[], int esquerda, int direita, int alvo) {
    int comparacoes = 0;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        printf("\n--> Comparacao %d:\n", ++comparacoes);
        printf("Intervalo atual: esquerda = %d, direita = %d\n", esquerda, direita);
        printf("Indice do meio: %d (valor = %d)\n", meio, arr[meio]);

        if (arr[meio] == alvo) {
            printf("Valor %d encontrado na posicao %d\n", alvo, meio);
            return meio;
        } else if (arr[meio] < alvo) {
            printf("%d eh maior que %d, indo para a metade direita\n", alvo, arr[meio]);
            esquerda = meio + 1;
        } else {
            printf("%d eh menor que %d, indo para a metade esquerda\n", alvo, arr[meio]);
            direita = meio - 1;
        }
    }

    printf("\nBusca encerrada. Valor %d nao encontrado.\n", alvo);
    return -1;
}

int main() {
    int dados[] = {11, 22, 33, 44, 55, 66, 77}; 
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 10; 

    printf("Iniciando pesquisa binaria...\n");
    pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    return 0;
}