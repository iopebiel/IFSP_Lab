#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[20];
    int prioridade;
    struct no *proximo;
} No;

typedef No *pNo;

typedef struct {
    No *inicio;
    No *fim;
} FilaPrioridade;

typedef FilaPrioridade *pFilaPrioridade;

pFilaPrioridade criar_fila_prioridade() {
    pFilaPrioridade f = (pFilaPrioridade)malloc(sizeof(FilaPrioridade));
    f->inicio = f->fim = NULL;
    return f;
}

int FilaVazia(pFilaPrioridade f)
{
    return (f->inicio == NULL);
}

void insere(pFilaPrioridade f, No item)
{
    pNo novo = (pNo)malloc(sizeof(No));
    printf("\nNo alocado para insercao de elemento na fila.");
    if (novo == NULL)
    {
        printf("Sem memoria\n");
        exit(1);
    }
    strcpy (novo->nome, item.nome);
    novo->prioridade = item.prioridade;
    printf("\nCopia do valor para o no.");
    novo->proximo = NULL;
    if (FilaVazia(f))
    {
        f->inicio = novo;
        printf("\nDefinicao do no como no inicial.");
    }
    else
    {
        f->fim->proximo = novo;
        printf("\nAlteracao do ultimo no para insercao de proximo.");
    }
    f->fim = novo;
    novo->proximo = f->inicio;
    printf("\nDefinicao do novo no como o ultimo da fila.\n");
}

pNo extrai_maximo(pFilaPrioridade fila) {
    int prioridademax = 0;
    pNo noprioridademax;
    pNo atual = fila->inicio;
    while (!FilaVazia(fila))
    {
        if (atual->prioridade > prioridademax)
            {
                prioridademax = atual->prioridade;
                noprioridademax = atual;
            }
        if(atual != fila->fim)
            atual = atual->proximo;
        else
            break;
    }
    return noprioridademax;
}

void imprime(pFilaPrioridade fila) {
    pNo aux = fila->inicio;
    int i = 1;
    printf("\nElemento %d: \nNome: %s \nPrioridade: %d\n", i, aux->nome, aux->prioridade);
    i++;
    aux = aux->proximo;
    while (i != 0)
    {
        printf("\nElemento %d: \nNome: %s \nPrioridade: %d\n", i, aux->nome, aux->prioridade);
        if (aux == fila->fim)
            break;
        aux = aux->proximo;
        i++;
    }
}

pNo anterior(pNo excluido, pFilaPrioridade f)
{
    pNo atual = f->inicio;
    while (atual->proximo != excluido)
    {
        atual = atual->proximo;
    }
    return atual;
}

void removerno(No **noexcluido,No **noanterior, pFilaPrioridade f)
{
    (*noanterior)->proximo = (*noexcluido)->proximo;
    if ((*noexcluido) == f->inicio)
        f->inicio = (*noexcluido)->proximo;
    if ((*noexcluido) == f->fim)
        f->fim = (*noanterior);
    (*noexcluido)->proximo = NULL;
    free(*noexcluido);
}

int main() {
    int prioridade;
    pFilaPrioridade fila;
    No novo_item;
    pNo noexcluido;
    pNo noanterior;

    fila = criar_fila_prioridade();

    prioridade = 5;
    strcpy(novo_item.nome, "jose");
    novo_item.prioridade = prioridade;
    insere(fila, novo_item);

    strcpy(novo_item.nome, "maria");
    prioridade = 2;
    novo_item.prioridade = prioridade;
    insere(fila, novo_item);

    strcpy(novo_item.nome, "gabriel");
    prioridade = 7;
    novo_item.prioridade = prioridade;
    insere(fila, novo_item);

    imprime(fila);

    noexcluido = extrai_maximo(fila);

    printf("\nElemento Maximo\nNome: %s\nPrioridade: %d\n", noexcluido->nome, noexcluido->prioridade);
    noanterior = anterior(noexcluido, fila);
    removerno(&noexcluido, &noanterior, fila);
    printf("\n\n-----apos exclusao-----\n\n");

    imprime(fila);

    return 0;
}