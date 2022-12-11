/**
 * Copyright(c)
 * All rights reserved.
 * Author: Louis874
 * Date: 2022-12-11-17.07.38
 * Description: 二叉树基本结构
 */
#include <stdlib.h>
#include <stdio.h>
typedef char DataType;
#include "BinTree.h"


void inorder(BinTreeNode *root, DataType *res, int *resSize){
    if (!root){
        return;
    }
    inorder(root->leftChild, res, resSize);
    res[(*resSize)++] = root->data;
    inorder(root->rightChild, res, resSize);

}

// https://leetcode.cn/problems/binary-tree-inorder-traversal/
// 94 中序遍历
DataType * inorderTraversal(BinTreeNode *root, int *returnSize){
    DataType *res = (DataType *)malloc(sizeof(DataType) * 100);
    *returnSize = 0;
    inorder(root,res, returnSize);
    return res;
}


// https://leetcode.cn/problems/binary-tree-preorder-traversal/
// 144 前序遍历


// https://leetcode.cn/problems/binary-tree-postorder-traversal/
// 145 后序遍历



int main(int args, char *argv[]){
    BinTreeNode *root, *p;
    Initiate(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->leftChild, 'C');
    p = InsertLeftNode(p, 'E');
    p = InsertRightNode(p, 'F');
    InTraverse(root, visit);

    printf("\n");
    int length = 0;
    DataType *res = inorderTraversal(root, &length);
    for (int i=0; i<length; i++){
        printf("%c ", *res++);

    }





    return 0;
}
