#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "node.h"  

double processNode(Node* node);
double evaluateLogic(const char* type, double input1, double input2);
double evaluateMath(const char* type, double input1, double input2);
double evaluateConditional(const char* type, double input1, double input2);

#endif