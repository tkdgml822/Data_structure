#include <string.h>
#include <stdlib.h>
#include "PostCalcualtor2.c"
#include "InfixToPostfix2.c"

int EvalInfixExp(char exp[]) {
    int len = strlen(exp);
    int ret;
    // 문자열 저장공간 마련
    char * expcpy = (char*)malloc(len+1);   
    // exp를 expcpy에 복사
    strcpy(expcpy, exp);                    

    ConvToRPNExp(expcpy);                  
    ret = EvalRPNExp(expcpy);

    free(expcpy);
    return ret;
}


