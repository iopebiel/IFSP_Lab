#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Definição da estrutura da lista encadeada
struct node{
    int value;
    struct node* next;
};

// Declaração das funções
void addnode(int value, struct node** ini);
void removenode(struct node** node);
void printlist(struct node** );

int main(){
    int choice, value;
    struct node* ini = NULL;
    // Inicializa a lista como nula
    
    // Laço do-while que executa até que o usuário decida encerrar o programa
    do {
        printf("Gostaria de:\n1-Inserir um elemento na lista.\n2-Remover um elemento na lista.\n3-imprimir a lista.\n4- encerrar.");
        scanf("%d", &choice);
        // Lê a opção escolhida pelo usuário

        switch (choice) {
            case 1: 
                scanf("%d", &value); 
                addnode(value, ini); 
                break;
            case 2: 
                removenode(); 
                break;
            case 3: 
                printlist(); 
                break;
        }
        // Executa a função correspondente à opção escolhida pelo usuário

    } while (choice != 4);
    // Encerra o programa se o usuário escolher a opção 4
}

// Função para adicionar um novo nó na lista
void addnode(int value, struct node** ini) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    // Aloca memória para um novo nó
    
    newnode->value = value;
    newnode->next = NULL;
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

// Função para remover um nó da lista
void removenode () {
   
}

// Função para imprimir a lista encadeada
void printlist() {
    
}