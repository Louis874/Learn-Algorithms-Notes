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

    PreTraverse(root, visit);




    return 0;
}
