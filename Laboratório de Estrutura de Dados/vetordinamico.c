#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char matricula[10];
    char nome[15];
    int ano;
} registro;


int main()
{
    registro *p;
    int n, i;
    scanf("%d", &n);
    p = malloc(sizeof(registro)*n);
    for (i = 0; i < n; i++)
    {
        scanf(" %s", p[i].matricula);
        scanf(" %s", p[i].nome);
        scanf("%d", &p[i].ano);
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n",p[i].matricula);
        printf("%s\n",p[i].nome);
        printf("%d\n",p[i].ano);
    }
    
    free(p)

    return 0;
}