#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void) {
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    
    return nd;
}
BTData GetData(BTreeNode * bt) {
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data) {
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
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

// 전위
void PreOrderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    }

    action(bt->data);
    PreOrderTraverse(bt->left, action);
    PreOrderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    } 

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    }

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode * bt) {
    if(bt == NULL) {
        return;
    }

    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}