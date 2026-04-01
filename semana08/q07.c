#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int *operacoes){
    *operacoes = 0;

    for(int i = 0; i < tamanho; i++){
        (*operacoes)++; 
        if(dados[i] != alvo) {
		}
        if(dados[i] == alvo){
            return i;
        }
    }
    return -1;
}

int pesquisaBinaria (int dados[], int esquerda, int direita, int alvo, int *operacoes){
    *operacoes = 0;

    while(esquerda <= direita){
        (*operacoes)++; 

        int meio = esquerda + (direita - esquerda) / 2;

        if(dados[meio] == alvo){
            return meio;
        } 
        else if (dados[meio] < alvo){
            esquerda = meio + 1;
        } 
        else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[1000];
    int tamanho = 1000;
    int operacoes;

    for(int i = 0; i < tamanho; i++){
        dados[i] = i; 
    }

    int alvo = 20;

    int resultadoSeq = pesquisaSequencial(dados, tamanho, alvo, &operacoes);
    printf("Busca Sequencial:\n");
    printf("Resultado: %d\n", resultadoSeq);
    printf("Operacoes: %d\n\n", operacoes);

    int resultadoBin = pesquisaBinaria(dados, 0, tamanho - 1, alvo, &operacoes);
    printf("Busca Binaria:\n");
    printf("Resultado: %d\n", resultadoBin);
    printf("Operacoes: %d\n\n", operacoes);

    return 0;
}

/*

Na busca sequencial percorre elemento por elemento, no qual realiza n/2 operacoes (1000/2 -> 500), tendo a sua complexidade O(n)

Na busca binaria divide o vetor ao meio a cada operacao realizada, realizado log2(n) operacoes (10), tendo a sua complexidade O(log n)

Portanto, a busca binaria e mais eficiente para vetores grandes e já ordenados, uma vez que realiza menos operacoes para a busca do que a sequencial.

*/