#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int chave;
} Item;
    
typedef struct {
    Item *v;
    int n, tamanho;
} FP;

typedef FP *p_fp;


int main() 
{
    char n[20];
    int prioridade;
    Item novoItem;
    Item excluido;
    
    p_fp f1 = criar_filaprio(5);
    prioridade = 5;
    strcpy (novoItem.nome,"jose");
    novoItem.chave = prioridade;
    insere(f1, novoItem);
    strcpy (novoItem.nome,"maria");
    prioridade = 2;
    novoItem.chave = prioridade;
    insere(f1, novoItem);
    imprime(f1);
    excluido = extrai_maximo(f1);
    printf ("Elemento Maximo: %s \n %d", excluido.nome, excluido.chave);
    printf("\n apos exclusão\n");
    imprime(f1);

    return 0;
}

void troca(Item *a, Item *b) 
{
    Item t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam) 
{
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    
    return fprio;
}

void insere(p_fp fprio, Item item) 
{
    fprio->v[fprio->n] = item;  
    fprio->n++;
}

Item extrai_maximo(p_fp fprio) 
{
    int j, max = 0;
    for (j = 1; j < fprio->n; j++) 
    {
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
    }
    troca(&(fprio->v[max]), &(fprio->v[fprio->n-1]));
    fprio->n--;
    
    return fprio->v[fprio->n];
}

void imprime (p_fp fprio)
{
    for (int j = 0; j < fprio->n; j++)
        printf("Elemento %d: \n Nome: %s \n Prioridade: %d", j,
    fprio->v[j].nome, fprio->v[j].chave);
}