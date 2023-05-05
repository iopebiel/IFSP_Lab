#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int prioridade;
} Item;

typedef struct {
    Item *vetor;
    int n, tamanho;
} FilaPrioridade;

typedef FilaPrioridade *pFilaPrioridade;

void troca(Item *a, Item *b);
pFilaPrioridade criar_fila_prioridade(int tamanho);
void insere(pFilaPrioridade fila, Item item);
Item extrai_maximo(pFilaPrioridade fila);
void imprime(pFilaPrioridade fila);

int main() {
    char nome[20];
    int prioridade;
    Item novo_item;
    Item item_excluido;

    pFilaPrioridade fila = criar_fila_prioridade(5);

    prioridade = 5;
    strcpy(novo_item.nome, "jose");
    novo_item.prioridade = prioridade;
    insere(fila, novo_item);

    strcpy(novo_item.nome, "maria");
    prioridade = 2;
    novo_item.prioridade = prioridade;
    insere(fila, novo_item);

    imprime(fila);

    item_excluido = extrai_maximo(fila);
    printf("Elemento Maximo: %s\n%d\n", item_excluido.nome, item_excluido.prioridade);
    printf("\n\n-----apos exclusao-----\n\n");
    imprime(fila);

    return 0;
}

void troca(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

pFilaPrioridade criar_fila_prioridade(int tamanho) {
    pFilaPrioridade fila = malloc(sizeof(FilaPrioridade));
    fila->vetor = malloc(tamanho * sizeof(Item));
    fila->n = 0;
    fila->tamanho = tamanho;

    return fila;
}

void insere(pFilaPrioridade fila, Item item) {
    fila->vetor[fila->n] = item;
    fila->n++;
}

Item extrai_maximo(pFilaPrioridade fila) {
    int j, max = 0;
    for (j = 1; j < fila->n; j++) {
        if (fila->vetor[max].prioridade < fila->vetor[j].prioridade) {
            max = j;
        }
    }
    troca(&(fila->vetor[max]), &(fila->vetor[fila->n - 1]));
    fila->n--;

    return fila->vetor[fila->n];
}

void imprime(pFilaPrioridade fila) {
    for (int j = 0; j < fila->n; j++) {
        printf("Elemento %d:\nNome: %s\nPrioridade: %d\n\n", j,
               fila->vetor[j].nome, fila->vetor[j].prioridade);
    }
}