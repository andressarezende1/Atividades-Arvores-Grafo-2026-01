#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int alvo){
    while(esquerda <= direita){
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

int pesquisaBinariaRecursiva(int dados[], int esquerda, int direita, int alvo){
    if(esquerda > direita){
        return -1;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    if(dados[meio] == alvo){
        return meio;
    } else if(dados[meio] < alvo){
        return pesquisaBinariaRecursiva(dados, meio + 1, direita, alvo);
    } else {
        return pesquisaBinariaRecursiva(dados, esquerda, meio - 1, alvo);
    }
}

int main(){
    int dados[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int tamanho = sizeof(dados)/sizeof(dados[0]);
    int alvo = 10;

    int resultadoIter = pesquisaBinaria(dados, 0, tamanho - 1, alvo);
    printf("Iterativa: elemento %d encontrado na posicao %d\n", alvo, resultadoIter);

    int resultadoRec = pesquisaBinariaRecursiva(dados, 0, tamanho - 1, alvo);
    printf("Recursiva: elemento %d encontrado na posicao %d\n", alvo, resultadoRec);

    return 0;
}

/*
    A versão recursiva compromete a legibilidade da estrutura, pois o código se torna mais difícil de entender. Além disso, como cada chamada recursiva consome memória na pilha, ela gasta mais memória do que a versão iterativa.
*/