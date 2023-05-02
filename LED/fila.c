#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 15

struct elemFila {
    char info[MAX_SIZE];    
    struct elemFila * prox;
};

typedef struct elemFila ElemFila;

struct fila {
    ElemFila * ini;
    ElemFila * fim;
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
    f->ini = f->fim = NULL;
    return f;
}

int FilaVazia(Fila * f)
{
    return (f->ini == NULL);
}

void FilaInsere (Fila * f, char item[MAX_SIZE])
{
    ElemFila * n = (ElemFila *)malloc(sizeof(ElemFila));
    if (n == NULL) 
    {
        printf("Sem memoria\n"); 
        exit(1);
    }
    strcpy (n->info, item);
    n->prox = NULL;
    if (FilaVazia(f))
    {   
        f->ini = n;
        f->fim = n;
    }
    else 
        f->ini = n;
    f->fim = n;   
}

int ComparaFilas (Fila* f1, Fila* f2)
{
    return strcmp((f1->fim)->info, (f2->fim)->info);
}
