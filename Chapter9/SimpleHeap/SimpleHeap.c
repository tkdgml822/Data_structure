#include "SimpleHeap.h"

// 힙의 초기화
void HeapInit(Heap * ph) {
    ph->numOfData = 0;
}

// 데이터가 있는지 검사
int HIsEmpty(Heap * ph) {
    if(ph->numOfData == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 부모 노드의 인덱스 반환
int GetParentIDX(int idx) { 
    return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 반환 
int GetLChildIDX(int idx) {
    return idx * 2;
}

// 오른쪽 자신 노드의 인덱스 반환
int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인텍스 값 반환 
int GetHiPriChildIDX(Heap * ph, int idx) {
    // 자식 노드가 존재 하지 않을 때, 힙은 완전 이진트리이므로 왼쪽 자식 노드가 없으면 자식노드가 없는 걸로 판단
    if(GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    }
    // 자식 노드가 왼쪽 자식 노드 하나만 존재하면
    else if(GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    }
    // 자식 노드가 둘다 존재 한다면, 
    else {
        // 왼쪽 노드가 왼쪽이 높으면,
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) {
            return GetRChildIDX(idx);
        }
        // 오른쪽 노드가 우선순위가 높다면
        else {
            return GetLChildIDX(idx);
        }
    }

}

// 힙에 데이터 저장
void HInsert(Heap * ph, HData data, Priority pr) {
    // 새노드가 저장이 되어야 되니깐 현재 데이터의 수에서 +1을 한 인덱스 값이 나와야된다.
    int idx = ph->numOfData + 1;
    // 데이터 백업
    HeapElem nelem = {pr, data};

    // 새노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
    while(idx != 1) {
        // GetParentIDX은 부모 노드의 주소값을 가져온다.
        // 마지막노드의 부모와 마지막 노드를 우선순위를 비교한다.
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
            // 지금 마지막 노드와 부모노드의 자리를 바꿈
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            // 인덱스값을 바꾸고 나서
            idx = GetParentIDX(idx);
        }
        // 새 노드의 순위가 높지 않다면
        else { 
            break;
        }
    }

    // 백업을 해둔 값을 현재 저장된 값에 가서 넣는다.
    ph->heapArr[idx] = nelem;
    // 데이터 값 증가
    ph->numOfData += 1;
}

// 힙에 데이터 삭제 (그림으로는 스왑과정으로 하는데 실제 코드는 그렇지 않다.)
HData HDelete(Heap * ph) {
    // root 노드 가져오기
    HData retData = (ph->heapArr[1]).data;
    // 마지막 데이터(우선순위가 제일 낮은)데이터 가져오기
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    
    while(childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        // GetHiPriChildIDX(ph, parentIDX)에 함수가 들어가면서
        if(lastElem.pr <= ph->heapArr[childIdx].pr) {
            break;
        }
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;   
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}