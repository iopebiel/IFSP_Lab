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

void troca(No *a, No *b);
pFilaPrioridade criar_fila_prioridade();
void insere(pFilaPrioridade fila, No item);
No extrai_maximo(pFilaPrioridade fila);
void imprime(pFilaPrioridade fila);

int main() {
    char nome[20];
    int prioridade;
    No novo_item;
    No item_excluido;

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
    removerno(item_excluido);
    printf("\n\n-----apos exclusao-----\n\n");
    imprime(fila);

    return 0;
}

void troca(No *a, No *b) {
    No temp = *a;
    *a = *b;
    *b = temp;
}

pFilaPrioridade criar_fila_prioridade() {
    FilaPrioridade f = (pFilaPrioridade)malloc(sizeof(FilaPrioridade));
    f->inicio = f->fim = NULL;
    return f;
}

void insere(pFilaPrioridade f, No item) 
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
    novo->proximo = NULL;
    if (!FilaVazia(f))
    {
        f->fim->proximo = novo;
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

No extrai_maximo(pFilaPrioridade fila) {
    int prioridademax;
    pNo noprioridademax;
    pNo atual = fila->inicio->proximo;
    while (atual->proximo != fila->inicio)
    {
        if (atual->prioridade > prioridademax)
            {
                prioridademax = atual->prioridade;
                noprioridademax = atual;
            }
        atual->proximo = atual->proximo->proximo;
    }
    return noprioridademax;
}

]void removeno(struct node** noexclusao) {
    struct node* noremovido = (*noexclusao)->next;
    printf("\nMarcado o nó inicial para remoção.");
    (*noexclusao)->next = noremovido->next;
    printf("\nProximo nó alterado.");
    // Remove o nó inicial e define o próximo nó como o próximo nó após o nó inicial
    
    if (*noexclusao == noremovido) {
        *noexclusao = NULL;
        printf("\nNó inicial removido e ponteiro inicial alterado para nulo.");
    }
    // Se o nó inicial foi o único nó da lista, define o ponteiro inicial como nulo
    
    freenode(&noremovido);
    printf("\nNó removido\n");
    // Desaloca a memória do nó removido
}
void imprime(pFilaPrioridade fila) {

    }




