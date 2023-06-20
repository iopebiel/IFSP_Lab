#include <stdio.h>
#include <stdlib.h>
#define MAX_PILHAS 4
#define MAX_CONTAINERS 3

typedef struct Container {
    int codigo;
    struct Container* prox;
} Container;

typedef struct Pilha {
    int tamanho;
    Container* topo;
} Pilha;

void inicializarPilhas(Pilha** pilhas) {
    for (int i = 0; i < MAX_PILHAS; i++) {
        pilhas[i] = (Pilha*)malloc(sizeof(Pilha));
        pilhas[i]->tamanho = 0;
        pilhas[i]->topo = NULL;
    }
}

Container* criarContainer(int codigo) {
    Container* novoContainer = (Container*)malloc(sizeof(Container));
    novoContainer->codigo = codigo;
    novoContainer->prox = NULL;
    return novoContainer;
}

void empilharContainer(Pilha** pilhas, int codigo) {
    for (int i = 0; i < MAX_PILHAS; i++) {
        Container* atual = pilhas[i]->topo;
        while (atual != NULL) {
            if (atual->codigo == codigo) {
                printf("Codigo invalido!\n");
                return;
            }
            atual = atual->prox;
        }
    }

    int menorTamanho = pilhas[0]->tamanho;
    int menorIndice = 0;
    for (int i = 1; i < MAX_PILHAS; i++) {
        if (pilhas[i]->tamanho < menorTamanho) {
            menorTamanho = pilhas[i]->tamanho;
            menorIndice = i;
        }
    }

    if (menorTamanho == MAX_CONTAINERS) {
        printf("Impossivel empilhar!\n");
        return;
    }

    Container* novoContainer = criarContainer(codigo);
    novoContainer->prox = pilhas[menorIndice]->topo;
    pilhas[menorIndice]->topo = novoContainer;
    pilhas[menorIndice]->tamanho++;
}

void desempilharContainer(Pilha** pilhas, int codigo) {
    int pilhaEncontrada = -1;
    Container* containerEncontrado = NULL;
    for (int i = 0; i < MAX_PILHAS; i++) {
        Container* atual = pilhas[i]->topo;
        if (atual != NULL && atual->codigo == codigo) {
            pilhaEncontrada = i;
            containerEncontrado = atual;
            break;
        }
    }
    if (containerEncontrado == NULL) {
        printf("Impossivel desempilhar!\n");
        return;
    }

    if (containerEncontrado != pilhas[pilhaEncontrada]->topo) {
        printf("Impossivel desempilhar!\n");
        return;
    }

    pilhas[pilhaEncontrada]->topo = containerEncontrado->prox;
    pilhas[pilhaEncontrada]->tamanho--;
    free(containerEncontrado);
}

void mostrarPilhas(Pilha** pilhas) {
    for (int i = 0; i < MAX_PILHAS; i++) {
        printf("Pilha %d: ", i + 1);
        Container* atual = pilhas[i]->topo;
        while (atual != NULL) {
            printf("%d ", atual->codigo);
            atual = atual->prox;
        }
        printf("\n");
    }
}

void liberarPilhas(Pilha** pilhas) {
    for (int i = 0; i < MAX_PILHAS; i++) {
        Container* atual = pilhas[i]->topo;
        while (atual != NULL) {
            Container* proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        free(pilhas[i]);
    }
}

int main() {
    Pilha* pilhas[MAX_PILHAS];
    inicializarPilhas(pilhas);
    int opcao;
    int codigo;
    do {
        printf("1 - Adicionar container\n");
        printf("2 - Remover container\n");
        printf("3 - Mostrar pilhas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o codigo do container: ");
                scanf("%d", &codigo);
                empilharContainer(pilhas, codigo);
                break;
            case 2:
                printf("Digite o codigo do container: ");
                scanf("%d", &codigo);
                desempilharContainer(pilhas, codigo);
                break;
            case 3:
                mostrarPilhas(pilhas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    } while (opcao != 0);

    liberarPilhas(pilhas);
    return 0;

}