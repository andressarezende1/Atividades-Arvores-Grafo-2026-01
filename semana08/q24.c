#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int alvo){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == alvo){
            return meio;
        } else if(dados[meio] < alvo){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return esquerda;
}

int main(){
    int dados[] = {5, 15, 25, 35, 45, 55};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 26; 

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    printf("O valor %d pode ser inserido na posicao %d\n", alvo, resultado);

    return 0;
}