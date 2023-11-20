#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "deque.h"
#include "Estudante.h"

/******************************************************************************/
void freeEstudante(void* e)
{
    if (e != NULL) {
        Estudante* estudante = (Estudante*)e;
        free(estudante->nome);
        free(estudante->prontuario);
        free(estudante);
    }
}

/******************************************************************************/
int cmpEstudante(void* e1, void* e2)
{
    if (e1 == NULL || e2 == NULL) {
        return 0;  // Ou outro valor que faça sentido para o seu caso
    }

    Estudante* estudante1 = (Estudante*)e1;
    Estudante* estudante2 = (Estudante*)e2;

    // Comparação com base no prontuário
    return strcmp(estudante1->prontuario, estudante2->prontuario);
}

/******************************************************************************/
void printEstudante(void* e, FILE* pFile)
{
    if (e != NULL && pFile != NULL) {
        Estudante* estudante = (Estudante*)e;
        fprintf(pFile, "(%s, %s)", estudante->nome, estudante->prontuario);
    }
}

/******************************************************************************/
Estudante* createEstudante(char* nome, char* prontuario)
{
    assert(nome != NULL && prontuario != NULL);
    Estudante* ret = malloc(sizeof(Estudante));
    if (ret == NULL) {
        fprintf(stderr, "Memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    ret->nome = strdup(nome);
    ret->prontuario = strdup(prontuario);
    return ret;
}

/******************************************************************************/
void testaEstudante()
{
   //Cria a lista
   Deque* lista = createDeque(&freeEstudante, &cmpEstudante, &printEstudante);

   //Preenche a lista com alguns valores
   char nomeAux[200];
   char prontuarioAux[50];
   for (int i = 0; i < 10; i++) {
      sprintf(nomeAux, "Estudante-%02d", i);
      sprintf(prontuarioAux, "SL%02d", i);
      Estudante* est = createEstudante(nomeAux, prontuarioAux);
      pushBackElement(lista, est);
   }

   //Percorre a lista usando iteradores
   DequeIterator* it = createDequeIterator(lista);

   printf("Vai até o fim do iterador\n");
   while (DIteratorHasNext(it)) {
        Estudante* e2 = (Estudante*) DIteratorNext(it);
        printf("%s, %s\n", e2->nome, e2->prontuario);
   }

   printDeque(lista, stdout);
   printf("\n");

   destroyDequeIterator(it);
   destroyDeque(lista, true);

}
