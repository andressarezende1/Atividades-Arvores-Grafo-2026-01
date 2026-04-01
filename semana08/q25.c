#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int *verificacoes){
    *verificacoes = 0;
    for(int i = 0; i < tamanho; i++){
        (*verificacoes)++;
        if(dados[i] != alvo){
        }
        if(dados[i] == alvo){
            return i;
        }
    }
    return -1;
}

int main(){
    int dados[]= {77, 12, 89, 34, 56, 23, 90};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 23;

    int verificacoes;

    int resultado = pesquisaSequencial(dados, tamanho, alvo, &verificacoes);

    if(resultado > -1){
        printf("O valor %d foi encontrado!\n", alvo);
        printf("Verificacoes realizadas: %d", verificacoes);
    } else {
        printf("O valor %d nao foi encontrado!\n", alvo);
        printf("Verificacoes realizadas: %d", verificacoes);
    }

    return 0;
}