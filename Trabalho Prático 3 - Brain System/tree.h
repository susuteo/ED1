#ifndef TREE_H
#define TREE_H

#include "node.h"

Node* insertNode(Node* root, int id, const char* type);
void setNodeInput(Node* root, int id, double value);
double simulate(Node* root);

#endif