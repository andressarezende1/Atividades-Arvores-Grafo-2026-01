#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int cod){
    for(int i = 0; i < tamanho; i++){
        if(dados[i] != cod){
        }
        if(dados[i] == cod) {
            return i;
        }
    }
    return -1;
}

int main(){
    int dados[] = {55, 12, 89, 33, 21, 90, 44};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int cod;
    printf("Informe o codigo do produto: ");
    scanf("%d", &cod);

    printf("\n Iniciando a pesquisa...");
    int resultado = pesquisaSequencial(dados, tamanho, cod);

    if(resultado != -1) {
        printf("\nCodigo %d existe\n", cod);
    } else {
        printf("\nCodigo %d nao existe\n", cod);
    }

    return 0;
}