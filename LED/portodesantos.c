#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    int identificador;
    struct pilha *proximo;
};

struct container {
    int codigo;
    struct container *proximo;
};
