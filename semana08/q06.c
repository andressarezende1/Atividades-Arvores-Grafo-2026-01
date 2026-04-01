#include <stdio.h>
#include <string.h>

int pesquisaBinaria(char dados[][20], int tamanho, char nome[]){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(dados[i], nome) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    char dados[5][20] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
    char nome[20] = "Carlos";

    int resultado = pesquisaBinaria(dados, 5, nome);

    if(resultado != -1){
        printf("\nNome %s encontrado na posicao %d", nome, resultado);
    } else {
        printf("Nome %s nao encontrado", nome);
    }

    return 0;
}