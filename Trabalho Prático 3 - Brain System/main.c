#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "tree.h"
#include "memory.h"

void trimString(char* str) {
    char* start = str;
    while(isspace((unsigned char)*start)) start++;
    
    if(*start == 0) {
        *str = 0;
        return;
    }
    
    char* end = str + strlen(str) - 1;
    while(end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    
    memmove(str, start, end - start + 2);
}

Node* buildTree(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    Node* root = NULL;
    char line[256];
    int id;
    char type[5];

    while (fgets(line, sizeof(line), file)) {
        trimString(line);
        id = atoi(line);
        if (id < 0) break;

        if (fgets(line, sizeof(line), file)) {
            trimString(line);
            strncpy(type, line, 4);
            type[4] = '\0';
            root = insertNode(root, id, type);
        }
    }

    fclose(file);
    return root;
}

void loadInputs(Node* root, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return;

    char line[256];
    int id;
    double value;

    while (fgets(line, sizeof(line), file)) {
        trimString(line);
        id = atoi(line);
        if (id < 0) break;

        if (fgets(line, sizeof(line), file)) {
            trimString(line);
            value = atof(line);
            setNodeInput(root, id, value);
        }
    }

    fclose(file);
}

int main() {
    Node* root = buildTree("brain.txt");
    if (!root) {
        printf("FAIL\n");
        return 1;
    }

    loadInputs(root, "inputs.txt");

    double result = simulate(root);
    
    printf("%.2f\n", result);

    freeTree(root);
    return 0;
}