#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int posicoes[]){
    int ocorrencias = 0;
    for(int i = 0; i < tamanho; i++){
        if(dados[i] != alvo){
        }
        if(dados[i] == alvo){
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }

    return ocorrencias;
}

int main(){
    int dados[]= {10, 25, 10, 30, 45, 25, 60, 10};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 10;

    int posicoes[tamanho];

    int resultado = pesquisaSequencial(dados, tamanho, alvo, posicoes);

    if(resultado > 0){
        printf("Numero de ocorrencias: %d\n", resultado);
        printf("Posicoes: ");

        for(int i = 0; i < resultado; i++){
            printf("%d ", posicoes[i]);
        }
    } else {
        printf("Nao ha ocorrencias\n");
    }

    return 0;
}