#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    struct node* next;
};

// Declaração das funções
void addnode(int value, struct node** ini);

int main(){
    int choice, value;
    struct node* ini = NULL;

    addnode(2, &ini);
    addnode(3, &ini);
    addnode(4, &ini);

}

// Função para adicionar um novo nó na lista
void addnode(int value, struct node** ini) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    // Aloca memória para um novo nó
    
    newnode->value = value;
    // Define o valor e o próximo nó como nulo
    
    if (*ini == NULL) {
        newnode->next = newnode;
        *ini = newnode;
        return;
    }
    // Verifica se a lista está vazia, se sim, define o próximo nó como ele mesmo

    newnode->next = (*ini)->next;
    (*ini)->next = newnode;
    *ini = newnode;
    // Adiciona o novo nó ao fim da lista encadeada circular
}
