#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int id){
    int comparacoes = 0;
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;

        if(dados[meio] == id){
            return meio;
        } else if (dados[meio] < id){
            esquerda = meio + 1;
        } else{
            direita = meio - 1;
        }
    }

    return -1;
}

int main(){
    int dados[] = {101, 203, 305, 407, 509, 611, 713};
    int tamanho = sizeof(dados)/sizeof(dados[0]);
    int id = 611;

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, id);

    if(resultado != -1){
        printf("\n Acesso permitido");
    } else {
        printf("\n Usuário não encontrado");
    }

    return 0;
}