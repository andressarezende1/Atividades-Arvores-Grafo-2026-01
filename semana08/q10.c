#include <stdio.h>

int pesquisaSequencial (int listaA[], int tamanhoA, int alvoA){
    for(int i = 0; i < tamanhoA; i++){
        if(listaA[i] != alvoA){
        }
        if(listaA[i] == alvoA){
            return 1;
        }
    }
    return -1;
}

int pesquisaBinaria(int listaB[], int esquerda, int direita, int alvoB){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(listaB[meio] == alvoB){
            return meio;
        } else if (listaB[meio] < alvoB){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int listaA[] = {34, 7, 23, 89, 12, 55, 1, 67, 90, 18};
    int tamanhoA = sizeof(listaA) / sizeof(listaA[0]);
    int alvoA = 55;

    int listaB[1000000];
    int tamanhoB = 1000000;

    for(int i = 0; i < tamanhoB; i++){
        listaB[i] = i;
    }

    int alvoB = 55;

    int resultadoSeq = pesquisaSequencial(listaA, tamanhoA, alvoA); // Lista A
    int resultadoBin = pesquisaBinaria(listaB, 0, tamanhoB - 1, alvoB); // Lista B

    return 0;
}

/*
Lista A - não ordenado - pesquisa sequencial
Para conjunto de dados pequenos e desordenados, a busca sequencial é mais recomenda. Uma vez que possui complexidade 0(n) e não hpa custo de ordenação, além disso, como a lista é pequena, o seu desempenho é satisfatorio.

Lista B - ordenado - pesquisa binaria
Para conjunto grandes e já ordenados é recomendado a utilização da busca binaria, pois possui complexidade O(log n), torna-se rápida e eficiente para o conjunto.
*/