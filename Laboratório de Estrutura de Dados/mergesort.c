#include <stdio.h>
#include <sys/time.h>
#include <stdio.h>

// Função para mesclar dois subvetores em ordem crescente
void mesclar(int vetor[], int esquerda[], int tamanhoEsquerda, int direita[], int tamanhoDireita) {
    int i = 0, j = 0, k = 0;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

// Função principal que implementa o algoritmo Merge Sort
void ordenacaoMesclar(int vetor[], int tamanho) {
    if (tamanho < 2)
        return;

    int meio = tamanho / 2;
    int esquerda[meio];
    int direita[tamanho - meio];

    for (int i = 0; i < meio; i++) {
        esquerda[i] = vetor[i];
    }

    for (int i = meio; i < tamanho; i++) {
        direita[i - meio] = vetor[i];
    }

    ordenacaoMesclar(esquerda, meio);
    ordenacaoMesclar(direita, tamanho - meio);
    mesclar(vetor, esquerda, meio, direita, tamanho - meio);
}

void imprimirArray(int vetor[]) {
    int i;
    for (i = 0; i < 50; i++)
    {
        if (i == 49)
        {
            printf("%d", vetor[i]);
            break;
        }
        printf("%d, ", vetor[i]);
    }

    printf("\n");
}

int main() {
    FILE *arquivo = fopen("C:\\Users\\POP\\Downloads\\NumerosAleatorios.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int i = 0, numero, vetor[50];

    while(fscanf(arquivo, "%d\n", &numero) == 1)
    {
        vetor[i] = numero;
        i++;
    }

    fclose(arquivo);
    printf("Array antes da ordenacao: \n");
    imprimirArray(vetor);
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    ordenacaoMesclar(vetor, 50);

    gettimeofday(&end, 0);
    long segundos = end.tv_sec - begin.tv_sec;
    long microsegundos = end.tv_usec - begin.tv_usec;
    double tPassado = segundos + microsegundos*1e-6;

    printf("\nTempo medido: %.3f segundos.\n", tPassado);
    printf("\nArray apos a ordenacao: \n");
    
    imprimirArray(vetor);

    return 0;
}




