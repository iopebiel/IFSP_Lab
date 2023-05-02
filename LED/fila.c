#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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
    printf("Qual item deseja adicionar a FILA 1?");
    char item[MAX_SIZE];
    scanf("%s", item);
    FilaInsere(f1, item);
    Fila * f2;
    f2 = CriaFila();
    printf("Qual item deseja adicionar a FILA 2?");
    scanf("%s", item);
    FilaInsere(f2, item);
    if (ComparaFilas(f1, f2) == 0)
        printf("As String são iguais");
    else
        printf("As strings são diferentes");
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
    strcpy (item, n->info);
    n->prox = NULL;
    if (FilaVazia(f))
        f->fim->prox = n;
    else 
        f->ini = n;
    f->fim = n;   
}

int ComparaFilas (Fila* f1, Fila* f2)
{
    return strcmp(f1->ini, f2->ini);
}
