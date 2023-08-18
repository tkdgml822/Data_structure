#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.c"

int GetOpPrec(char op) {
    switch (op) {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;

    }

    return -1;
}

int WhoPrecOp(char op1, char op2) {
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec) {
        return 1;
    }
    else if (op1Prec < op2Prec) {
        return -1;
    }
    else {
        return 0;
    }
}

void ConvToRPNExp(char exp[]) {
    Stack stack;
    int expLen = strlen(exp);
    // exp의 배열의 길이만큼 공간 확보
    char * convExp = (char*)malloc(expLen + 1);

    int i, idx = 0;
    char tok, popOp;

    // convExp을 0으로 전부 초기화
    // memset(대상, 초기화 할 값, 어느정도 값으로 초기화 할지)
    memset(convExp, 0, sizeof(char) * expLen + 1);
    StackInit(&stack);

    for(i = 0; i < expLen; i++) {
        tok = exp[i];
        // '\0'이 들어가는 것을 막기위해 쓰입니다. 그리고 숫자만 들어갑니다.
        // 예) '1' -> '0이 이아닌 다른 값', 'H' -> 0
        if(isdigit(tok)) {
            convExp[idx++] = tok;
        }
        else {
            switch(tok) {
                case '(':
                    // 
                    SPush(&stack, tok);
                    break;
                case ')':
                    // stack에 쌓여 있는 연산들을 가지고 온다 그리고 맨 마지막에 있는 '('을 마주하면 break문이 실행이된다.
                    while(1) {
                        popOp = SPop(&stack);
                        if(popOp == '(') {
                            break;
                        }
                        convExp[idx++] = popOp;
                    }
                    break;
                // WhoPrecOp(SPeek(&stack), tok) -> 현재 맨 위에 있는 연산자와 방금 가져온 연산자(tok)를 비교
                // !SIsEmpty(&stack) -> 데이터가 있는지 검사한다. 없으면 TRUE가 나오기 때문에 !연산자로 인해 FALSE가 된다.
                case '+': case '-':
                case '*': case '/':
                    // SPeek(&stack)가 더 크면 1이 나오는데 이 뜻은 방금 입력된 연산자 보다 이미 있는 연산자가 더 크다는 뜻이다.
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
                        // 이미있는 연산자가 더 크면 그릇을 옮긴후 입력된 연산자를 넣어준다.
                        convExp[idx++] = SPop(&stack);
                    }
                    SPush(&stack, tok);
                    break;
            }   
        }
    }

    // 남아있는 데이터 처리
    while(!SIsEmpty(&stack)) {
        convExp[idx++] = SPop(&stack);
    }
    
    // 이제 결과를 exp에 복사후 메모리를 해제해준다.
    strcpy(exp, convExp);
    free(convExp);
}