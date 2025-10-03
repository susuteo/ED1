#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto* criaPonto(float x, float y);
void liberaPonto(Ponto* p);
float calculaDistancia(Ponto* p1, Ponto* p2);

#endif
