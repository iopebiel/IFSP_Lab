#include <stdio.h>
#include <stdlib.h>
int **cria(int linha, int coluna);
void libera(int **mat, int linha);
int main()
{
 int **matriz;
 int linha, coluna;
 printf("\nDigite o número de linhas...");
 scanf(“%d”, &linha);
 printf("\nDigite o número de colunas...");
 scanf(“%d, &coluna);
 printf("\nCriando a matriz alocada dinamicamente...");
 matriz = cria(linha, coluna); //ponteiro da matriz que será utilizada será
repassada por return.

 printf("\nLiberando a matriz alocada dinamicamente\n");
 libera(matriz, linha);
 return 0;
}
int **cria(int linha, int coluna)
{ // criação uma matriz de dimensão m por n;
 int **matriz;
 int i;
 matriz = (int **) malloc(linha*sizeof(int *)); // Alocação de memória para o
ponteiro da matriz.
 if (matriz == NULL) {
 printf("Não foi possível alocar memória para a matriz.\n");
 return NULL;
 }
 for (i = 0; i < linha; i++)
 {
 matriz[i] = (int *)malloc(coluna * sizeof(int)); // Criação de espaços de
memória para os vetores de cada linha da matriz.
 if (matriz[i] == NULL)
 {
 printf("Erro:Não foi possível alocar memória para a linha %d da
matriz.\n", i);
 return NULL;
 }
 }
 printf("\nMatriz de ordem %dx%d alocada com sucesso!\n", linha, coluna);
 return matriz;
}
void libera(int **mat, int linha)
{ // libera a memória alocada para a matriz;
 int i;
 printf("Liberando memoria de cada linha da matriz...\n");
 for (i = 0; i < linha; i++)
 free(mat[i]); // liberando memória alocada de cada linha.
 free(mat); // libera a memória alocada para o ponteiro da matriz.
 printf("Liberação do ponteiro da Matriz concluida com sucesso!\n");
}