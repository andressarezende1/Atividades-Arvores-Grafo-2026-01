#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int id, int *comparacoes){
    *comparacoes = 0;

    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        (*comparacoes)++;

        if(dados[meio] == id){
            return meio;
        } else if(dados[meio] < id){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[] = {10, 23, 35, 47, 59, 62, 78, 91};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int id = 59;
    int comparacoes = 0;

    printf("\nIniciando pesquisa...\n");
    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, id, &comparacoes);

    if(resultado != -1)
        printf("\nLivro do ID %d encontrado.", id);

    printf("\nNumero de iteracoes realizadas: %d", comparacoes);

    return 0;
}