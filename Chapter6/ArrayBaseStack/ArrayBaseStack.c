#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) {
    pstack->topIndex = - 1;
}

int SIsEmpty(Stack * pstack) {
    if(pstack->topIndex == -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void SPush(Stack * pstack, Data data) {
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) {
    int rdx;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdx = pstack->topIndex;
    pstack->topIndex -= 1;

    return pstack->stackArr[rdx];
}

Data SPeek(Stack * pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}