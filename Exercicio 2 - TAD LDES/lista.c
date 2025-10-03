#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserirFinal(Lista* lista, float temperatura, int umidade) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->temperatura = temperatura;
    novo->umidade = umidade;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Node* temp = lista->inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }

    lista->tamanho++;
}

void exibirLista(Lista* lista) {
    Node* temp = lista->inicio;
    int dia = 1;
    
    while (temp != NULL) {
        printf("Dia %d: %.1f %d\n", dia, temp->temperatura, temp->umidade);
        temp = temp->proximo;
        dia++;
    }
}

void liberarLista(Lista* lista) {
    Node* atual = lista->inicio;
    Node* proximo;
    
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}
