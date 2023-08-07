#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node * next;  
} Node;

int main(void) {
    Node * head = NULL;
    Node * cur = NULL;
    Node * tail = NULL;

    Node * newNode = NULL;
    int readData;

    while(1) {
        printf("자연수 입력");
        scanf("%d \n", &readData);
        if (readData < 1) {
            break;
        }

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }

        tail = newNode;
        
    }
    printf("\n");

    // 입력 받은 데이터의 출력 과정
    if(head == NULL) {
        printf("저장된 자연수가 존재하지 않습니다! \n");
    }
    else {
        cur = head;
        printf("%d ", cur->data);
        
        while(cur->next != NULL) {
            cur = cur->next;
            printf("%d", cur->data);
        }
    }
    printf("\n\n");

    // 메모리의 해제과정 //
    if(head == NULL) {
        return 0; // 해체할 노드가 존재하지 않음
    }
    else {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d을(를) 삭제합니다. \n", head->data);
        free(delNode); // 첫 번째 노드 삭제

        while(delNextNode != NULL) {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다. \n", delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}