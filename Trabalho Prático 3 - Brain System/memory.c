#include "memory.h"

static double memorySlots[3] = {0.0, 0.0, 0.0};

void initMemory() {
    for(int i = 0; i < 3; i++) {
        memorySlots[i] = 0.0;
    }
}

void storeMemory(int pos, double value) {
    if(pos >= 0 && pos < 3) {
        memorySlots[pos] = value;
    }
}

double recallMemory(int pos) {
    if(pos >= 0 && pos < 3) {
        return memorySlots[pos];
    }
    return 0.0;
}