#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int alvo, int *comparacoes){
    *comparacoes = 0;
    for(int i = 0; i < tamanho; i++){
        (*comparacoes)++;
        if(dados[i] != alvo){
        }
        if(dados[i] == alvo){
            return i;
        }
    }
    return -1;
}

int main(){
    int dados[]= {321, 105, 876, 432, 210, 654, 999, 111};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 321;

    int comparacoes;

    int resultado = pesquisaSequencial(dados, tamanho, alvo, &comparacoes);

    if(resultado != -1){
        printf("A pagina %d foi visitada\n", alvo);
        printf("Posicao: %d\n", resultado);
        printf("Numero de comparacoes: %d", comparacoes);
    } else {
        printf("A pagina %d não foi visitada\n", alvo);
    }

    return 0;
}