#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* criaPonto(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void liberaPonto(Ponto* p) {
    free(p);
}

float calculaDistancia(Ponto* p1, Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return -1;
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}
