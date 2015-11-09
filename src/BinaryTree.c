//
//  BinaryTree.c
//  BinarySaver
//
//  Created on 08/11/15.
//  Copyright (c) 2015 Vraiment.
//

#include "BinaryTree.h"

#include <stdlib.h>
#include <assert.h>

struct t_BinaryTreeNode
{
    int value;
    Node *left, *right;
};

Node *create(int value)
{
    Node *node = NULL;

    node = malloc(sizeof(Node));

    assert(NULL != node);

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy(Node *node)
{
    if (NULL == node)
    {
        return;
    }

    destroy(node->left);
    destroy(node->right);

    free(node);
}

int getValue(Node *node)
{
    assert(NULL != node);

    return node->value;
}

Node *getLeft(Node *node)
{
    assert(NULL != node);

    return node->left;
}

Node *getRight(Node *node)
{
    assert(NULL != node);

    return node->right;
}

void setLeft(Node *node, int value)
{
    assert(NULL != node);

    node->left = create(value);
}

void setRight(Node *node, int value)
{
    assert(NULL != node);

    node->right = create(value);
}
