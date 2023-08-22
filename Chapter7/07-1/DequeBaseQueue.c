#include "DequeBaseQueue.h"

void QueueInit(Queue * pq) {
    DequeInit(pq);
}

void QISEmpty(Queue * pq) {
    DequeInit(pq);
}

void Enqueue(Queue * pq, Data data) {
    DQAddLast(pq, data);
}

Data Dequeue(Queue * pq) {
    return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq) {
    return DQGetFirst(pq);
}