#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int cod){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        printf("Inicio: %d | Meio: %d | Fim: %d\n", esquerda, meio, direita);
        if(dados[meio] == cod){
            return meio;
        } else if(dados[meio] < cod){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[] = {1001, 1020, 1055, 1100, 1200, 1300, 1500};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int cod = 1300; 

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, cod);

    if(resultado != -1){
        printf("Codigo %d localizado na posicao %d\n", cod, resultado);
    } else {
        printf("Codigo %d nao encontrado\n", cod);
    }

    return 0;
}