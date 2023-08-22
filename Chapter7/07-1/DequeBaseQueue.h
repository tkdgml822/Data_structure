#ifndef __Deque_Base_Queue_H__
#define __Deque_Base_Queue_H__
#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue * pq);
void QISEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif


