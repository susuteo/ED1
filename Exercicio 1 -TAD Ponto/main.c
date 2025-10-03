#include <stdio.h>
#include "ponto.h"

int main() {
    float x1, y1, x2, y2;

    // Lê o primeiro ponto
    scanf("%f %f", &x1, &y1);
    Ponto* p1 = criaPonto(x1, y1);

    // Lê o segundo ponto
    scanf("%f %f", &x2, &y2);
    Ponto* p2 = criaPonto(x2, y2);

    // Calcula e exibe a distância
    float distancia = calculaDistancia(p1, p2);
    printf("%.2f\n", distancia);

    // Libera a memória dos pontos
    liberaPonto(p1);
    liberaPonto(p2);

    return 0;
}
