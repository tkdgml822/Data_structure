#include <stdio.h>
#include "PriorityQueue.c"

int DataPriorityComp(char ch1, char ch2) {
    return ch2- ch1;
}


int main(void) {
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDeqeue(&pq));

    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDeqeue(&pq));

    while(!PQIsEmpty(&pq)) {
        printf("%c \n", PDeqeue(&pq));
    }

    return 0;
}