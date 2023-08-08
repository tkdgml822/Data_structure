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

    while (1) {
        printf("자연수를 입력하세요 : ");
        scanf("%d", &readData);
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

        // if (head == NULL) {
        //     head = newNode;
        // }
        // else {
        //     tail->next = newNode;
        // }

        // tail = newNode;
    }

    // 데이터 출력
    if(head == NULL) {
        printf("출력할 데이터가 없습니다.");
    }
    else {
        cur = head;

        printf("%d ", cur->data);
        while(cur->next != NULL) {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }

    printf("\n\n");

    // 데이터 삭제
    Node * delNode = head;
    Node * delNextNode = delNode->next;

    printf("%d을 삭제합니다. \n", head->data);
    free(delNode);
    while(delNode->next != NULL) {
        delNode = delNextNode;
        delNextNode = delNextNode->next;
        printf("%d을 삭제합니다. \n", delNode->data);
        free(delNode);
    }


    return 0;
}