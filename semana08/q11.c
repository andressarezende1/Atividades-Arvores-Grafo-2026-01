#include <stdio.h>

int pesquisaSequencial (int dados[], int tamanho, int cod, int *comparacoes){
    *comparacoes = 0;
    for(int i = 0; i < tamanho; i++){
        (*comparacoes)++;
        if(dados[i] != cod){

        }
        if (dados[i] == cod){
            return i;
        }
    }
    return -1;
}

int main(){
    int dados[] = {903, 112, 457, 221, 678, 345, 789, 150};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int cod = 345;
    int comparacoes;

    int resultado = pesquisaSequencial(dados, tamanho, cod, &comparacoes);

    if(resultado != -1){
        printf("Codigo %d encontrado!\n", cod);
        printf("Posicoo: [%d]", resultado);
        printf("Comparacoes: %d", comparacoes);
    }

}