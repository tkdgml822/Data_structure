#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void) {
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt) {
    return bt->data;
}

void SetData(BTreeNode * bt,BTData data) {
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
    // 원쪽 연결하는 곳에 이미 노드가 있을 시 해당 노드를 삭제하고 노드를 연결
    if(main->left != NULL) {
        free(main->left);
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
    if(main->right != NULL) {
        free(main->right);
    }

    main->right = sub;
}