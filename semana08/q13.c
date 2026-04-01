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
    int dados[] = {45, 12, 78, 33, 90, 21, 56, 67};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 90; 

    int verificacoes;

    int resultado = pesquisaSequencial(dados, tamanho, alvo, &verificacoes);

    if(resultado != -1){
        printf("A leitura %d ocorreu", alvo);
        printf("\nVerificacoes realizadas: %d", verificacoes);
    } else {
        printf("A leitura %d não ocorreu", alvo);
    }

}