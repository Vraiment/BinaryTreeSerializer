//
//  BinaryTree.h
//  BinarySaver
//
//  Created on 08/11/15.
//  Copyright (c) 2015 Vraiment.
//

#ifndef BinaryTree_h
#define BinaryTree_h

typedef struct t_BinaryTreeNode Node;

Node *create(int value);

void destroy(Node *node);

int getValue(Node *node);

Node *getLeft(Node *node);

Node *getRight(Node *node);

void setLeft(Node *node, int value);

void setRight(Node *node, int value);

#endif /* BinaryTree_h */
