#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 15

struct no {
    char info[MAX_SIZE];    
    struct no *prox;
};

typedef struct no No;

struct fila {
    No * inicio;
    No * fim;
};
typedef struct fila Fila;

Fila * CriaFila(void);
int FilaVazia(Fila * f);
void FilaInsere (Fila * f, char item[MAX_SIZE]);
int ComparaFilas (Fila* f1, Fila* f2);

int main () {
    Fila *f1;
    char item1[MAX_SIZE], item2[MAX_SIZE];
    printf("\nIniciando a criação da FILA 1...");
    f1 = CriaFila();
    printf("\nQual item deseja adicionar a FILA 1?\n");
    scanf("%s", item1);
    FilaInsere(f1, item1);
    Fila *f2;
    printf("\nIniciando a criação da FILA 2...");
    f2 = CriaFila();
    printf("\nQual item deseja adicionar a FILA 2?\n");
    scanf("%s", item2);
    FilaInsere(f2, item2);
    if (ComparaFilas(f1, f2) == 0)
        printf("\nAs String são iguais");
    else
        printf("\nAs strings são diferentes");
}

Fila * CriaFila(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    printf("\nFila alocada. ");
    f->inicio = f->fim = NULL;
    printf("E inicializada.")
    return f;
}

void FilaInsere (Fila *f, char item[MAX_SIZE])
{
    No *novo = (No *)malloc(sizeof(No));
    printf("\nNó alocado para inserção de elemento na fila.");
    if (novo == NULL) 
    {
        printf("Sem memoria\n"); 
        exit(1);
    }
    strcpy (novo->info, item);
    printf("\nCopia do valor para o nó.");
    novo->prox = NULL;
    if (!FilaVazia(f))
    {   
        f->fim->prox = novo;
        printf("Alteração do último nó para inserção de próximo.");
    }
    f->fim = novo; 
    printf("\nDefinição do novo nó como o último da fila.");  
    if (f->inicio == NULL)
    {    
        f->inicio = novo;
        printf("\nDefinição do nó como nó inicial."); 
    }
}

int FilaVazia(Fila *f)
{
    return (f->inicio == NULL);
}

int ComparaFilas (Fila* f1, Fila* f2)
{
    return strcmp((f1->fim)->info, (f2->fim)->info);
}
