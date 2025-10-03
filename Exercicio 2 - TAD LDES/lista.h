#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    float temperatura;
    int umidade;
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio;
    int tamanho;
} Lista;

Lista* criarLista();
void inserirFinal(Lista* lista, float temperatura, int umidade);
void exibirLista(Lista* lista);
void liberarLista(Lista* lista);

#endif
