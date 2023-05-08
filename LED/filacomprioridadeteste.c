#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[20];
    int prioridade;
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

pFilaPrioridade criar_fila_prioridade() {
    FilaPrioridade f = (pFilaPrioridade)malloc(sizeof(FilaPrioridade));
    f->inicio = f->fim = NULL;
    return f;
}

void insere(pFilaPrioridade f, Item item) 
{   
    No *novo = (No *)malloc(sizeof(No));
    printf("\nNo alocado para insercao de elemento na fila.");
    if (novo == NULL)
    {
        printf("Sem memoria\n");
        exit(1);
    }
    strcpy (novo->nome, item->nome);
    novo->prioridade = item->prioridade;
    printf("\nCopia do valor para o no.");
    novo->prox = NULL;
    if (!FilaVazia(f))
    {
        f->fim->prox = novo;
        printf("Alteracao do ultimo no para insercao de próximo.");
    }
    f->fim = novo;
    printf("\nDefinicao do novo no como o ultimo da fila.");
    if (f->inicio == NULL)
    {
        f->inicio = novo;
        printf("\nDefinicao do no como no inicial.");
    }
}

int FilaVazia(pFilaPrioridade f)
{
    return (f->inicio == NULL);
}

Item extrai_maximo(pFilaPrioridade fila) {
    
}

void imprime(pFilaPrioridade fila) {
    for (int j = 0; j < fila->n; j++) {
        printf("Elemento %d:\nNome: %s\nPrioridade: %d\n\n", j,
               fila->vetor[j].nome, fila->vetor[j].prioridade);
    }
}


