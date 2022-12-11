/**
 * Copyright(c)
 * All rights reserved.
 * Author: Louis874
 * Date: 2022-12-11-17.07.38
 * Description: �����������ṹ
 */



#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

typedef struct Node{
    DataType data;
    struct Node *leftChild;
    struct Node *rightChild;
} BinTreeNode;


// ��ʼ��
void Initiate(BinTreeNode **root){
    *root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}



// �������
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

// �Ҳ�����
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

// ����������
void Destroy(BinTreeNode ** root){
    if ((*root) != NULL && (*root)->leftChild != NULL){
        Destroy(&(*root)->leftChild);
    }
    if ((*root) != NULL && (*root)->rightChild != NULL){
        Destroy(&(*root)->rightChild);
    }
    free(*root);

}



// ��ɾ������
BinTreeNode * DeleteLeftTree(BinTreeNode * curr){
    // ����ǰ�ڵ�curr�ǿգ���ɾ��curr��������
    // ��ɾ���ɹ����򷵻�ɾ������˫�׽��ָ�룬���򷵻ؿ�ָ��
    if (curr == NULL || curr->leftChild == NULL){
        return NULL;
    }
    Destroy(&curr->leftChild);
    curr->leftChild = NULL;
    return curr;

}



// ��ɾ������
BinTreeNode * DeleteRightTree(BinTreeNode *curr){

    if (curr == NULL || curr->rightChild == NULL){
        return NULL;
    }
    Destroy(&curr->rightChild);
    curr->rightChild = NULL;
    return curr;

}




// �������
void PreTraverse(BinTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        visit(root->data);
        PreTraverse(root->leftChild, visit);
        PreTraverse(root->rightChild,visit);
    }
}


// �������
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
