#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "PostCalcualtor2.h"
#include "ListBaseStack2.c"

int EvalRPNExp(char exp[]) {
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for(i = 0; i < expLen; i++) {
        tok = exp[i];

        if(isdigit(tok)) {
            // 숫자면 정수로 바꿔서 스택에 쌓아준다.
            SPush(&stack, tok - '0');
        }
        else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) {
                case '+':
                    SPush(&stack, op1 + op2);
                    break;
                case '-':
                    SPush(&stack, op1 - op2);
                    break;
                case '*':
                    SPush(&stack, op1 * op2);
                    break;
                case '/':
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }
    return SPop(&stack);
}