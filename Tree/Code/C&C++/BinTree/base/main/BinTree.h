/**
 * Copyright(c)
 * All rights reserved.
 * Author: Louis874
 * Date: 2022-12-11-17.07.38
 * Description: 二叉树基本结构
 */



#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

typedef struct Node{
    DataType data;
    struct Node *leftChild;
    struct Node *rightChild;
} BinTreeNode;


// 初始化
void Initiate(BinTreeNode **root){
    *root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}



// 左插入结点
BinTreeNode * InsertLeftNode(BinTreeNode *curr, DataType x){
    BinTreeNode *s, *t;
    if (curr == NULL){
        return NULL;
    }
    t = curr->leftChild;
    s = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    s->data = x;
    s->leftChild = t;
    s->rightChild = NULL;
    curr->leftChild = s;
    return curr->leftChild;
}

// 右插入结点
BinTreeNode * InsertRightNode(BinTreeNode *curr, DataType x){
    BinTreeNode *s, *t;
    if (curr == NULL){
        return NULL;
    }
    t = curr->rightChild;
    s = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    s->data = x;
    s->leftChild = NULL;
    s->rightChild = t;
    curr->rightChild = s;
    return curr->rightChild;
}

// 撤销二叉树
void Destroy(BinTreeNode ** root){
    if ((*root) != NULL && (*root)->leftChild != NULL){
        Destroy(&(*root)->leftChild);
    }
    if ((*root) != NULL && (*root)->rightChild != NULL){
        Destroy(&(*root)->rightChild);
    }
    free(*root);

}



// 左删除子树
BinTreeNode * DeleteLeftTree(BinTreeNode * curr){
    // 若当前节点curr非空，则删除curr的左子树
    // 若删除成功，则返回删除结点的双亲结点指针，否则返回空指针
    if (curr == NULL || curr->leftChild == NULL){
        return NULL;
    }
    Destroy(&curr->leftChild);
    curr->leftChild = NULL;
    return curr;

}



// 右删除子树
BinTreeNode * DeleteRightTree(BinTreeNode *curr){

    if (curr == NULL || curr->rightChild == NULL){
        return NULL;
    }
    Destroy(&curr->rightChild);
    curr->rightChild = NULL;
    return curr;

}




// 先序遍历
void PreTraverse(BinTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        visit(root->data);
        PreTraverse(root->leftChild, visit);
        PreTraverse(root->rightChild,visit);
    }
}


// 中序遍历
void InTraverse(BinTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        InTraverse(root->leftChild, visit);
        visit(root->data);
        InTraverse(root->rightChild, visit);
    }
}

void PostTraverse(BinTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        PostTraverse(root->leftChild, visit);
        PostTraverse(root->rightChild, visit);
        visit(root->data);
    }
}



void visit(DataType item){
    printf("%c  ", item);
}





#endif // BINTREE_H_INCLUDED
