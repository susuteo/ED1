#include <string.h>
#include <math.h>
#include "node.h"
#include "operations.h"
#include "memory.h"

double evaluateLogic(const char* type, double input1, double input2) {
    if (strcmp(type, "AND2") == 0) {
        return (input1 != 0.0 && input2 != 0.0) ? 1.0 : 0.0;
    }
    if (strcmp(type, "OR-2") == 0) {
        return (input1 != 0.0 || input2 != 0.0) ? 1.0 : 0.0;
    }
    if (strcmp(type, "XOR2") == 0) {
        return ((input1 != 0.0) != (input2 != 0.0)) ? 1.0 : 0.0;
    }
    if (strcmp(type, "NOT2") == 0) {
        return (input1 == 0.0) ? 1.0 : 0.0;
    }
    return 0.0;
}

double evaluateMath(const char* type, double input1, double input2) {
    if (strcmp(type, "ADD2") == 0) return input1 + input2;
    if (strcmp(type, "SUB2") == 0) return input1 - input2;
    if (strcmp(type, "MLT2") == 0) return input1 * input2;
    if (strcmp(type, "DIV2") == 0) return input2 != 0.0 ? input1 / input2 : 0.0;
    if (strcmp(type, "MOD2") == 0) return fmod(input1, input2);
    if (strcmp(type, "PERC") == 0) return (input1 * input2) / 100.0;
    if (strcmp(type, "SQR2") == 0) return sqrt(input1 + input2);
    if (strcmp(type, "POW2") == 0) return pow(input1 + input2, 2);
    if (strcmp(type, "BIN2") == 0) return (input1 + input2 == 0.0) ? 0.0 : 1.0;
    if (strcmp(type, "CTE0") == 0) return 0.0;
    if (strcmp(type, "CTE1") == 0) return 1.0;
    if (strcmp(type, "MV12") == 0) {
        if (input2 == 1.0) { storeMemory(0, input1); return input1; }
        return recallMemory(0);
    }
    if (strcmp(type, "MV22") == 0) {
        if (input2 == 1.0) { storeMemory(1, input1); return input1; }
        return recallMemory(1);
    }
    if (strcmp(type, "MV32") == 0) {
        if (input2 == 1.0) { storeMemory(2, input1); return input1; }
        return recallMemory(2);
    }
    return 0.0;
}

double evaluateConditional(const char* type, double input1, double input2) {
    if (strcmp(type, "IFGT") == 0) return input1 > input2 ? 1.0 : 0.0;
    if (strcmp(type, "IFLT") == 0) return input1 < input2 ? 1.0 : 0.0;
    if (strcmp(type, "IFEQ") == 0) return input1 == input2 ? 1.0 : 0.0;
    if (strcmp(type, "IPGT") == 0) return input1 > input2 ? input1 : input2;
    if (strcmp(type, "IPLT") == 0) return input1 < input2 ? input1 : input2;
    return 0.0;
}

double processNode(Node* node) {
    if (node == NULL) return 0.0;
    
    if (strcmp(node->type, "INP1") == 0) {
        return node->input1;
    }

    double input1 = node->left ? processNode(node->left) : 0.0;
    double input2 = node->right ? processNode(node->right) : 0.0;
    
    double result = 0.0;
    
    //  lógicas
    if (strstr("AND2 OR-2 XOR2 NOT2", node->type)) {
        result = evaluateLogic(node->type, input1, input2);
    }
    //  matemáticas
    else if (strstr("ADD2 SUB2 MLT2 DIV2 MOD2 PERC SQR2 POW2 BIN2 CTE0 CTE1 MV12 MV22 MV32", node->type)) {
        result = evaluateMath(node->type, input1, input2);
    }
    //  condicionais
    else if (strstr("IFGT IFLT IFEQ IPGT IPLT", node->type)) {
        result = evaluateConditional(node->type, input1, input2);
    }
    
    node->output = result;
    return result;
}