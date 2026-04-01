#include <stdio.h>

int pesquisaBinaria( int dados[], int esquerda, int direita, int alvo){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == alvo){
            return meio;
        } else if (dados[meio] < alvo){
            esquerda = meio + 1;
        } else{
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[] = {5, 10, 15, 20, 25, 30};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 20;

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    if (resultado != -1){
        printf("Indice: %d", resultado);
    } else {
        printf("-1");
    }

    return 0;
}
