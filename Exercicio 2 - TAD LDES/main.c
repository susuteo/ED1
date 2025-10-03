#include <stdio.h>
#include "lista.h"

int main() {
    Lista* lista = criarLista();
    float temperatura;
    int umidade;

    while (1) {
        scanf("%f", &temperatura);
        if (temperatura == -100) break;
        scanf("%d", &umidade);
        inserirFinal(lista, temperatura, umidade);
    }

    exibirLista(lista);
    liberarLista(lista);

    return 0;
}
