#include <stdio.h>
#include <sys/time.h>

void ordenacaoPorInsercao(int vetor[]) {
    int i, chave, j;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    while(i < 50)
    {
        for (i = 1; i < 50; i++) {
            chave = vetor[i];
            j = i - 1;

            // Move os elementos maiores do que a chave para a direita
            // até encontrar a posição correta para inserir a chave
            while (j >= 0 && vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                j = j - 1;
            }
            vetor[j + 1] = chave;
        }

    }


    gettimeofday(&end, 0);
    long segundos = end.tv_sec - begin.tv_sec;
    long microsegundos = end.tv_usec - begin.tv_usec;
    double tPassado = segundos + microsegundos*1e-6;

    printf("\nTempo medido: %.3f segundos.\n", tPassado);

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

    ordenacaoPorInsercao(vetor);

    printf("\nArray apos a ordenacao: \n");
    imprimirArray(vetor);

    return 0;
}
