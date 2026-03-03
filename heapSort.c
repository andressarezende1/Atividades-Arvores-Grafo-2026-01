#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(int vet[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]); // imprime cada elemento com espaço
    }
    printf("\n"); // quebra de linha após imprimir o vetor
}

// Função que garante a propriedade de Max-Heap
void organizarSubarvore(int vet[], int n, int indiceRaiz) {
    int maior = indiceRaiz; // assume que o maior elemento é a raiz
    int esquerda = 2 * indiceRaiz + 1; // índice do filho esquerdo
    int direita = 2 * indiceRaiz + 2;   // índice do filho direito

    // verifica se o filho esquerdo existe e é maior que a raiz
    if (esquerda < n && vet[esquerda] > vet[maior])
        maior = esquerda;

    // verifica se o filho direito existe e é maior que o maior atual
    if (direita < n && vet[direita] > vet[maior])
        maior = direita;

    // se o maior não for a raiz, faz a troca e continua recursivamente
    if(maior != indiceRaiz){
        printf(" -> Trocando %d por %d\n", vet[indiceRaiz], vet[maior]);
        int aux = vet[indiceRaiz]; 
        vet[indiceRaiz] = vet[maior]; 
        vet[maior] = aux; 

        organizarSubarvore(vet, n, maior); // chamada recursiva
    }
}

int main(){
    int vet[] = {30, 12, 45, 6, 18, 3};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor inicial: ");
    imprimirVetor(vet, n);

    // Construindo o Max-Heap
    // Inicia com o ultimo que possui filhos e vai subindo
    for(int i = n/2 - 1; i >= 0; i--){
        organizarSubarvore(vet, n, i); // Organiza cada subárvore
    }

    printf("\nMax-Heap construida: ");
    imprimirVetor(vet, n);

    // Primeira extração da raiz
    int temp = vet[0];        // Guarda o maior elemento (raiz)
    vet[0] = vet[n-1];        // Coloca o último elemento na raiz
    vet[n-1] = temp;          // Move o maior para o final do vetor

    organizarSubarvore(vet, n-1, 0);     // Reorganiza o heap desconsiderando o último elemento

    printf("\nApós a primeira extração da raiz: ");
    imprimirVetor(vet, n);

    return 0;
}