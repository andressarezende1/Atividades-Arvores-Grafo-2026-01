#include <stdio.h>

int pesquisaBinaria(long long dados[], int esquerda, int direita, long long alvo){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == alvo){
            return meio;
        } else if (dados[meio] < alvo){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    long long dados[] = {11987654321LL, 11991234567LL, 11993456789LL, 11995678901LL, 11997890123LL};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    long long alvo = 11993456789LL;

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    if(resultado != -1){
        printf("Numero encontrado na posicao %d", resultado);
    } else {
        printf("Numero não encontrado.");
    }
}