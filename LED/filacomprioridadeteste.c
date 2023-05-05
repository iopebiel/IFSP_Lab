#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int prioridade;
} Item;

typedef struct no{
    Item *vetor;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaPrioridade;

typedef FilaPrioridade *pFilaPrioridade;

void troca(Item *a, Item *b);
pFilaPrioridade criar_fila_prioridade();
void insere(pFilaPrioridade fila, Item item);
Item extrai_maximo(pFilaPrioridade fila);
void imprime(pFilaPrioridade fila);

int main() {
    char nome[20];
    int prioridade;
    Item novo_item;
    Item item_excluido;

    pFilaPrioridade fila = criar_fila_prioridade();

    prioridade = 5;
    strcpy(novo_item.nome, "jose");
    novo_item.prioridade = prioridade;
    insere(fila, no, novo_item);

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

pFilaPrioridade criar_fila_prioridade() {
    FilaPrioridade *f = (Fila *)malloc(sizeof(Fila));
    
    f->inicio = f->fim = ;
    return f;
}

void insere(pFilaPrioridade fila, Item item) {
    
    [fila->n] = item;
    fila->;
}

Item extrai_maximo(pFilaPrioridade fila) {
    int j, max = 0;
    for (j = 1; j < fila->n; j++) {
        if (fila->vetor[max].prioridade < fila->vetor[j].prioridade) {
            max = j;
        }
    }
    troca(&(fila->vetor[max]), &(fila->vetor[fila->n - 1]));
    fila->;

    return fila->vetor[fila];
}

void imprime(pFilaPrioridade fila) {
    for (int j = 0; j < fila->n; j++) {
        printf("Elemento %d:\nNome: %s\nPrioridade: %d\n\n", j,
               fila->vetor[j].nome, fila->vetor[j].prioridade);
    }
}


