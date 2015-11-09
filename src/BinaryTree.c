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

char *serialize(Node *node)
{
    int totalSize;
    char *result;

    assert(NULL != node);

    totalSize = size(node);
    // format for each node is: ###,B,B; (where B is either Y or N)
    result = malloc((8 * sizeof(char) * totalSize) + 1);
    memset(result, 0, (8 * sizeof(char) * totalSize) + 1);

    serializeNode(node, result);

    return result;
}

uint8_t str2byte(char *string)
{
    uint8_t result = 0;

    result += (string[0] - 48) * 100;
    result += (string[1] - 48) * 10;
    result += string[2] - 48;

    return result;
}

char *deserializeNode(Node *node, char *string)
{
    char *value = string;
    char *next = string + 8;
    char hasLeft = *(string + 4);
    char hasRight = *(string + 6);

    node->value = str2byte(value);

    if ('Y' == hasLeft)
    {
        node->left = create(0);
        next = deserializeNode(node->left, next);
    }

    if ('Y' == hasRight)
    {
        node->right = create(0);
        next = deserializeNode(node->right, next);
    }

    return next;
}

Node *deserialize(char *string)
{
    Node *node = create(0);

    assert(NULL != string);

    deserializeNode(node, string);

    return node;
}
