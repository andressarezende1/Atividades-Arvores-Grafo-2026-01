#include <stdio.h>

int pesquisaBinaria(int dados[], int esquerda, int direita, int nota){
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == nota){
            return meio;
        } else if (dados[meio] < nota){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    int dados[] = {2, 3, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int nota = 9;

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, nota);

    int contar = 0;

    for(int i = 0; i < tamanho; i++){
        if(dados[i] > nota){
            contar++;
        }
    } 

    if(resultado != -1){
        printf("A nota %d existe.", nota);
        printf("Quantidade de alunos com nota maior: %d\n", contar);
    } else {
        printf("A nota %d não existe.", nota);
    }

    return 0;
}