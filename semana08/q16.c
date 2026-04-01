#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int voto, int *ocorrencias ){
    *ocorrencias = 0;
    for(int i = 0; i < tamanho; i++){
        if(dados[i] != voto){
        }
        if(dados[i] == voto){
            (*ocorrencias)++;
        }
    }
    return *ocorrencias;
}

int main(){
    int dados[]= {3, 1, 4, 2, 5, 3, 2, 1, 4};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int voto = 1;

    int ocorrencias;

    int resultado = pesquisaSequencial(dados, tamanho, voto, &ocorrencias);

    if(resultado != -1){
        printf("Numero de ocorrencias: %d", ocorrencias);
    } else {
        printf("Não há");
    }

    return 0;
}