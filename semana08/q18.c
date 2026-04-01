#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int *qtd ){
    *qtd = 0;
    for(int i = 0; i < tamanho; i++){
        (*qtd)++;
        if(dados[i] != alvo){
        }
        if(dados[i] == alvo){
            return i;
        }
    }
    return -1;
}

int main(){
    int dados[]= {501, 123, 876, 234, 654, 345, 999};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 939;

    int qtd;

    int resultado = pesquisaSequencial(dados, tamanho, alvo, &qtd);

    if(resultado != -1){
        printf("Filme %d encontrado na posicao %d", alvo, resultado);
    } else {
        printf("Filme %d nao encontrado\n", alvo);
        printf("Quantidade de elementos verificados: %d", qtd);
    }

    return 0;
}