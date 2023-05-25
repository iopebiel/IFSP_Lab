#include <stdio.h>

void ordenacaoPorInsercao(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        // Move os elementos maiores do que a chave para a direita
        // até encontrar a posição correta para inserir a chave
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void imprimirArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: \n");
    imprimirArray(arr, n);

    ordenacaoPorInsercao(arr, n);

    printf("Array após a ordenação: \n");
    imprimirArray(arr, n);

    return 0;
}