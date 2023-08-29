#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

// 최대길이
#define HEAP_LEN 100

// 문자형
typedef char HData;
// 우선순위
typedef int Priority;

typedef struct _heapElem {
    Priority pr;
    HData data;
} HeapElem;

typedef struct _heap {
    // 데이터 수
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

// 초기화
void HeapInit(Heap * ph);
// 데이터 있는지 검사
int HIsEmpty(Heap * ph);

// 데이터 넣기
void HInsert(Heap * ph, HData data, Priority pr);
// 데이터 삭제
HData HDelete(Heap * ph);

#endif