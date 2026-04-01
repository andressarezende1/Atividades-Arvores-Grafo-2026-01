#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int *dupli ){
    *dupli = 0;
    for(int i = 0; i < tamanho; i++){
        if(dados[i] != alvo){
        }
        if(dados[i] == alvo){
            (*dupli)++;
        }
    }
    return *dupli;
}

int main(){
    int dados[]= {12, 45, 12, 67, 89, 45, 23};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 45;

    int dupli;

    int resultado = pesquisaSequencial(dados, tamanho, alvo, &dupli);

    if(resultado != -1){
        printf("O numero %d possui duplicacao, %d vezes", alvo, dupli);
    } else {
        printf("O numero %d nao possui duplicacao", alvo);
    }

    return 0;
}