#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
	//	if(ph->heapArr[GetLChildIDX(idx)].pr 
	//				> ph->heapArr[GetRChildIDX(idx)].pr)
		// 왼쪽 노드의 주소와 오른쪽 주소의 값을 같이 줘서 비교후에 두번째의 인자수가 우선순위가 더 높다.
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		// 첫번째의 인자수가 우선순위가 더 높다.
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		//  우선순위가 첫번째가 더 높은거라면
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	// 양쪽 노드가 있기 때문에 우선순위가 높은것이 나온다.
	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		//if(lastElem.pr <= ph->heapArr[childIdx].pr)
		// 마지막 노드와 비교했을 때 첫번째 인자가 더 높으면 0보다 같은것이 나오는거기 때문에 같거나 같으면 노드의 마지막에 도달했다는 뜻이다.
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) {
			break;
		}

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}	

	// 마지막에 노드를 넣은 다음에 데이터수를 -1을 하면 데이터는 이제 삭제되는것이다. 
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;

	// 내가 생각한 경우 : 값을 덮어쓰면서 노드를 한칸씩 복사를 해서 올린것이고 마지막 그 노드만 없앤거 같다.
}