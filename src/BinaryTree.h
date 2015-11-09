//
//  BinaryTree.h
//  BinarySaver
//
//  Created on 08/11/15.
//  Copyright (c) 2015 Vraiment.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <inttypes.h>

typedef struct t_BinaryTreeNode Node;

Node *create(uint8_t value);

void destroy(Node *node);

uint8_t getValue(Node *node);

Node *getLeft(Node *node);

Node *getRight(Node *node);

void setLeft(Node *node, uint8_t value);

void setRight(Node *node, uint8_t value);

int size(Node *node);

const char *serialize(Node *node);

#endif /* BinaryTree_h */
