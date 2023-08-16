#ifndef __C_L_LINKED_LIST__
#define __C_L_LINKED_LIST__
#include "CLinkedList.c"

typedef int Data;

typedef struct _listStack {
    List * plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);


#endif