#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "operations.h"

Node* insertNode(Node* root, int id, const char* type) {
    if (!root) {
        return createNode(id, type);
    }
    
    if (id < root->id) {
        root->left = insertNode(root->left, id, type);
    } else if (id > root->id) {
        root->right = insertNode(root->right, id, type);
    }
    
    return root;
}

void setNodeInput(Node* root, int id, double value) {
    if (!root) return;
    
    if (root->id == id) {
        root->input1 = value;
        return;
    }
    
    setNodeInput(root->left, id, value);
    setNodeInput(root->right, id, value);
}

double simulate(Node* root) {
    if (!root) return 0.0;
    
    if (strcmp(root->type, "INP1") == 0) {
        return root->input1;
    }
    
    root->input1 = root->left ? simulate(root->left) : 0.0;
    root->input2 = root->right ? simulate(root->right) : 0.0;
    
    return processNode(root);
}