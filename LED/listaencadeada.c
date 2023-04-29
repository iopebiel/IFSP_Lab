#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura da lista encadeada
struct node{
    int value;
    struct node* next;
};

// Declaração das funções
void addnode(int value, struct node** initial);
void removenode(struct node** initial);
void freenode(struct node** node);
void printnode(struct node** initial);

int main(){
    int choice, value;
    struct node* initial = NULL;
    // Inicializa a lista como nula
    
    // Laço do-while que executa até que o usuário decida encerrar o programa
    do {
        printf("Gostaria de:\n1-Inserir um elemento na lista.\n2-Remover um elemento na lista.\n3- encerrar.");
        scanf("%d", &choice);
        // Lê a opção escolhida pelo usuário

        switch (choice) {
            case 1: 
                scanf("%d", &value); 
                addnode(value, &initial); 
                break;
            case 2: 
                removenode(&initial); 
                break;
        }
        // Executa a função correspondente à opção escolhida pelo usuário

    } while (choice != 3);
    // Encerra o programa se o usuário escolher a opção 3
}
// Função para adicionar um novo nó na lista
void addnode(int value, struct node** initial) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    printf("Nó alocado.");
    // Aloca memória para um novo nó
    
    newnode->value = value;
    // Define o valor para o nó
    
    if (*initial == NULL) {
        newnode->next = newnode;
        *initial = newnode;
        printf("\nprimeiro nó inicializado.\n");
        return;
    }
    // Verifica se a lista está vazia, se sim, define o próximo nó como ele mesmo

    newnode->next = (*initial)->next;
    (*initial)->next = newnode;
    *initial = newnode;
    printf("\nNovo nó adicionado ao fim da lista encadeada circular.\n");
    // Adiciona o novo nó ao fim da lista encadeada circular
}


// Função para remover o nó inicial da lista
void removenode(struct node** initial) {
    if (*initial == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    // Verifica se a lista está vazia, se sim, retorna uma mensagem de erro
    
    struct node* removednode = (*initial)->next;
    printf("\nMarcado o nó inicial para remoção.");
    (*initial)->next = removednode->next;
    printf("\nProximo nó alterado.");
    // Remove o nó inicial e define o próximo nó como o próximo nó após o nó inicial
    
    if (*initial == removednode) {
        *initial = NULL;
        printf("\nNó inicial removido e ponteiro inicial alterado para nulo.");
    }
    // Se o nó inicial foi o único nó da lista, define o ponteiro inicial como nulo
    
    freenode(&removednode);
    printf("\nNó removido");
    // Desaloca a memória do nó removido
}

// Função para desalocar a memória de um nó
void freenode(struct node** node) {
    free(*node);
    *node = NULL;
    printf("\nNó desalocado");
}