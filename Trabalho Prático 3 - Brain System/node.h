#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int id;
    char type[5];
    double input1;
    double input2;
    double output;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id, const char* type);
void freeTree(Node* root);

#endif