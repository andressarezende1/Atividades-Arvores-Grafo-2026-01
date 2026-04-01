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
    int dados[] = {15, 17, 19, 21, 23, 25, 27, 30};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 26; 

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    if(resultado < tamanho && dados[resultado] == alvo){
        printf("A temperatura %d foi registrada", alvo);
    } else {
        printf("A temperatura %d nao foi registrada\n", alvo);
        printf("Poderia ser inserida na posicao %d\n", resultado);
    }

    return 0;
}