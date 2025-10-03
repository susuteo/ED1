//SUELLEN TEODORICO DOS SANTOS SILVA
//          15489275

#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    int digito;
    struct Nodo* prox;
} Nodo;

typedef struct {
    Nodo* inicio;
} Lista;

Lista* cria_lista();
void insere_inicio(Lista* li, int digito);
void insere_final(Lista* li, int digito);
void exibe_lista(Lista* li);
void libera_lista(Lista* li);
int soma_listas(Lista* li1, Lista* li2, Lista* resultado);

#endif

