//
//  BinaryTree.c
//  BinarySaver
//
//  Created on 08/11/15.
//  Copyright (c) 2015 Vraiment.
//

#include "BinaryTree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_BinaryTreeNode
{
    uint8_t value;
    Node *left, *right;
};

Node *create(uint8_t value)
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

uint8_t getValue(Node *node)
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

void setLeft(Node *node, uint8_t value)
{
    assert(NULL != node);

    node->left = create(value);
}

void setRight(Node *node, uint8_t value)
{
    assert(NULL != node);

    node->right = create(value);
}

int size(Node *node)
{
    int result = 0;

    if (NULL != node)
    {
        result += size(node->left);
        result += size(node->right);
        ++result;
    }

    return result;
}

char *serializeNode(Node *node, char *result)
{
    assert(NULL != node);

    sprintf(result, "%03d,", node->value);
    result += 4;

    sprintf(result, "%c,", (NULL != node->left) ? 'Y' : 'N');
    result += 2;

    sprintf(result, "%c;", (NULL != node->right) ? 'Y' : 'N');
    result += 2;

    if (NULL != node->left)
    {
        result = serializeNode(node->left, result);
    }

    if (NULL != node->right)
    {
        result = serializeNode(node->right, result);
    }

    // Return the end of the string
    return result;
}

const char *serialize(Node *node)
{
    int totalSize;
    char *result;

    assert(NULL != node);

    totalSize = size(node);
    // format for each node is: ###,B,B;
    result = malloc((8 * sizeof(char) * totalSize) + 1);
    memset(result, 0, (8 * sizeof(char) * totalSize) + 1);

    serializeNode(node, result);

    return result;
}
