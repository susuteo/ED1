#include <stdlib.h>
#include <string.h>
#include "node.h"

Node* createNode(int id, const char* type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    
    newNode->id = id;
    strncpy(newNode->type, type, 4);
    newNode->type[4] = '\0';
    newNode->input1 = 0.0;
    newNode->input2 = 0.0;
    newNode->output = 0.0;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}