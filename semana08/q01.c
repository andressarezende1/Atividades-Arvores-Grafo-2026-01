#include <stdio.h>

int pesquisaSequencial(int dados[], int tamanho, int matri) {
    for (int i = 0; i < tamanho; i++) {
        if(dados[i] != matri) {
		}
        if (dados[i] == matri) {        	
            return i;
        }
    }
    return -1;
}

int main() {
    int dados[] = {512, 102, 678, 205, 789, 317, 404};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    
    int matri;
    printf("Informe a matricula do aluno: ");
    scanf("%d", &matri);

    printf("\nIniciando a pesquisa ..\n\n");
    int resultado = pesquisaSequencial(dados, tamanho, matri);

    if(resultado != -1) {
        printf("\nAluno da matricula %d esta presente", matri);
        printf("\nNa posicao %d \n", resultado);
    } else {
        printf("\nAluno da matricula %d nao foi encontrado", matri);
    }

    return 0;
}

