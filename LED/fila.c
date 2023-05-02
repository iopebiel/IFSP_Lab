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
    Fila * f1;
    f1 = CriaFila();
    printf("\nQual item deseja adicionar a FILA 1?");
    char item1[MAX_SIZE], item2[MAX_SIZE];
    scanf("%s", item1);
    FilaInsere(f1, item1);
    Fila * f2;
    f2 = CriaFila();
    printf("\nQual item deseja adicionar a FILA 2?");
    scanf("%s", item2);
    FilaInsere(f2, item2);
    if (ComparaFilas(f1, f2) == 0)
        printf("\nAs String são iguais");
    else
        printf("\nAs strings são diferentes");
}

Fila * CriaFila(void)
{
    Fila * f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int FilaVazia(Fila * f)
{
    return (f->inicio == NULL);
}

void FilaInsere (Fila * f, char item[MAX_SIZE])
{
    No * novo = (No *)malloc(sizeof(No));
    if (novo == NULL) 
    {
        printf("Sem memoria\novo"); 
        exit(1);
    }
    strcpy (novo->info, item);
    novo->prox = NULL;
    if (!FilaVazia(f))
    {   
        f->fim->prox = novo;
    }
    f->fim = novo;   
    if (f->inicio == NULL)
        f->inicio = novo;
}

int ComparaFilas (Fila* f1, Fila* f2)
{
    return strcmp((f1->fim)->info, (f2->fim)->info);
}
