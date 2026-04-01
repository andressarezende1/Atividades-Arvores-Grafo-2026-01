#include <stdio.h>

int pesquisaBinaria(long long dados[], int esquerda, int direita, long long alvo, int *etapas){
    *etapas = 0;
    while(esquerda <= direita){
        (*etapas)++;
        int meio = esquerda + (direita - esquerda) / 2;
        if(dados[meio] == alvo){
            return meio;
        } else if (dados[meio] < alvo){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    long long dados[] = { 1234567890LL, 2345678901LL, 3456789012LL, 4567890123LL, 5678901234LL, 6789012345LL, 7890123456LL, 8901234567LL,10012345678LL, 11123456789LL, 12234567890LL, 13345678901LL};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    for(int i = 0; i < tamanho; i++){
        dados[i] = i;
    }

    long long alvo = 1234567890LL;

    int etapas;

    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo, &etapas);

    if(resultado != -1){
        printf("CPF %d cadastrado.\n", alvo);
        printf("Na posicao: %d", resultado);
        printf("\nEtapas realizadas: %d", etapas);
    } else {
        printf("CPF %d não cadastrado.\n", alvo);
    }
}