//SUELLEN TEODORICO DOS SANTOS SILVA
//          15489275

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    li->inicio = NULL;
    return li;
}

void insere_inicio(Lista* li, int digito) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->digito = digito;
    novo->prox = li->inicio;
    li->inicio = novo;
}

void insere_final(Lista* li, int digito) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->digito = digito;
    novo->prox = NULL;
    if (li->inicio == NULL) {
        li->inicio = novo;
    } else {
        Nodo* temp = li->inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void exibe_lista(Lista* li) {
    Nodo* temp = li->inicio;
    int primeiro = 1; // Para controlar se estamos no primeiro dígito não-zero

    while (temp != NULL) {
        if (temp->digito != 0 || !primeiro) {
            printf("%d", temp->digito);
            primeiro = 0; // Agora já imprimimos um dígito não-zero
        }
        temp = temp->prox;
    }
    // Caso a lista seja toda composta por zeros
    if (primeiro) {
        printf("0");
    }
    printf("\n");
}

void libera_lista(Lista* li) {
    Nodo* temp = li->inicio;
    while (temp != NULL) {
        Nodo* aux = temp;
        temp = temp->prox;
        free(aux);
    }
    free(li);
}

int soma_listas(Lista* li1, Lista* li2, Lista* resultado) {
    Nodo* n1 = li1->inicio;
    Nodo* n2 = li2->inicio;
    int vai_um = 0;

    while (n1 != NULL || n2 != NULL || vai_um != 0) {
        int soma = vai_um;

        if (n1 != NULL) {
            soma += n1->digito;
            n1 = n1->prox;
        }
        if (n2 != NULL) {
            soma += n2->digito;
            n2 = n2->prox;
        }

        vai_um = soma / 10;  // Calcula se haverá "vai um"
        soma = soma % 10;    // Obtém o dígito da soma

        insere_final(resultado, soma); // Insere na lista de resultado
    }

    return vai_um; // Retorna o vai um final, se existir
}
