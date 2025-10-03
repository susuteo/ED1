#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int id;                
    char tipo[5];          
    double input1;          
    double input2;          
    double output;          
    struct Nodo *left;      
    struct Nodo *right;    
} Nodo;

Nodo* criarNodo(int id, const char *tipo) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("FAIL\n");
        exit(1);
    }
    novo->id = id;
    strcpy(novo->tipo, tipo);
    novo->input1 = 0.0;
    novo->input2 = 0.0;
    novo->output = 0.0;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

Nodo* inserirNodo(Nodo *raiz, int id, const char *tipo) {
    if (raiz == NULL) {
        return criarNodo(id, tipo);
    }
    if (id < raiz->id) {
        raiz->left = inserirNodo(raiz->left, id, tipo);
    } else if (id > raiz->id) {
        raiz->right = inserirNodo(raiz->right, id, tipo);
    }
    return raiz;
}

Nodo* buscarNodo(Nodo *raiz, int id) {
    if (raiz == NULL || raiz->id == id) {
        return raiz;
    }
    if (id < raiz->id) {
        return buscarNodo(raiz->left, id);
    }
    return buscarNodo(raiz->right, id);
}

Nodo* carregarArvore(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("FAIL\n");
        exit(1);
    }

    Nodo *raiz = NULL;
    int id;
    char tipo[5];

    while (fscanf(file, "%d", &id) == 1 && id >= 0) {
        if (fscanf(file, "%s", tipo) != 1) {
            printf("FAIL\n");
            fclose(file);
            exit(1);
        }
        
        // Validar tipo do nodo
        if (strcmp(tipo, "AND2") != 0 && strcmp(tipo, "OR-2") != 0 && 
            strcmp(tipo, "XOR2") != 0 && strcmp(tipo, "NOT2") != 0 && 
            strcmp(tipo, "INP1") != 0) {
            printf("FAIL\n");
            fclose(file);
            exit(1);
        }
        
        raiz = inserirNodo(raiz, id, tipo);
    }
    fclose(file);
    return raiz;
}

void carregarEntradas(Nodo *raiz, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("FAIL\n");
        exit(1);
    }

    int id;
    double valor;

    while (fscanf(file, "%d", &id) == 1 && id >= 0) {
        if (fscanf(file, "%lf", &valor) != 1) {
            printf("FAIL\n");
            fclose(file);
            exit(1);
        }
        
        if (valor != 0.0 && valor != 1.0) {
            printf("FAIL\n");
            fclose(file);
            exit(1);
        }

        Nodo *nodo = buscarNodo(raiz, id);
        if (nodo && strcmp(nodo->tipo, "INP1") == 0) {
            nodo->input1 = valor;
            nodo->output = valor;
        } else {
            printf("FAIL\n");
            fclose(file);
            exit(1);
        }
    }
    fclose(file);
}

void atualizarEntradas(Nodo *nodo) {
    if (nodo == NULL) return;
    
    atualizarEntradas(nodo->left);
    atualizarEntradas(nodo->right);
    
    if (nodo->left) nodo->input1 = nodo->left->output;
    if (nodo->right) nodo->input2 = nodo->right->output;
}

double simular(Nodo *nodo) {
    if (nodo == NULL) return 0.0;
    
    // Se for nodo de entrada, retorna o valor já definido
    if (strcmp(nodo->tipo, "INP1") == 0) {
        return nodo->output;
    }

    // Simula os filhos primeiro
    simular(nodo->left);
    simular(nodo->right);
    
    // Atualiza as entradas com os valores dos filhos
    if (nodo->left) nodo->input1 = nodo->left->output;
    if (nodo->right) nodo->input2 = nodo->right->output;

    // Realiza a operação lógica correspondente
    if (strcmp(nodo->tipo, "AND2") == 0) {
        nodo->output = (nodo->input1 > 0.5 && nodo->input2 > 0.5) ? 1.0 : 0.0;
    } else if (strcmp(nodo->tipo, "OR-2") == 0) {
        nodo->output = (nodo->input1 > 0.5 || nodo->input2 > 0.5) ? 1.0 : 0.0;
    } else if (strcmp(nodo->tipo, "XOR2") == 0) {
        int in1 = nodo->input1 > 0.5;
        int in2 = nodo->input2 > 0.5;
        nodo->output = (in1 != in2) ? 1.0 : 0.0;
    } else if (strcmp(nodo->tipo, "NOT2") == 0) {
        nodo->output = (nodo->input1 <= 0.5) ? 1.0 : 0.0;
    }

    return nodo->output;
}

int main() {
    Nodo *raiz = carregarArvore("brain.txt");
    if (!raiz) {
        printf("FAIL\n");
        return 1;
    }

    carregarEntradas(raiz, "input.txt");
    printf("%.2f\n", simular(raiz));

    return 0;
}