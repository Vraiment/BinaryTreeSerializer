//
//  main.c
//  BinarySaver
//
//  Created on 08/11/15.
//  Copyright (c) 2015 Vraiment.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "BinaryTree.h"

#define OPT_WRITE "-write"
#define OPT_READ "-read"

void printHelp();

Node *generateTree();

void writeFile(Node *node, const char *fileName);

Node *readFile(const char *fileName);

int main(int argc, const char * argv[])
{
    Node *tree = NULL;

    if (argc != 3)
    {
        printHelp();
    }
    else if (0 == strcmp(argv[1], OPT_WRITE))
    {
        tree = generateTree();

        writeFile(tree, argv[2]);
    }
    else if (0 == strcmp(argv[1], OPT_READ))
    {
        tree = readFile(argv[2]);
    }
    else
    {
        printHelp();
    }

    if (NULL != tree)
    {
        destroy(tree);
    }

    return 0;
}

void printHelp()
{

}

Node *generateTree()
{
    Node *result = NULL, *left = NULL, *right = NULL;

    result = create(5);

    setLeft(result, 2);
    setRight(result, 7);

    left = getLeft(result); // 2, left children of 5
    setLeft(left, 1);
    setRight(left, 3);

    right = getRight(left); // 3, right children of 2
    setRight(right, 4);

    right = getRight(result); // 7, right children of 5
    setRight(right, 10);

    right = getRight(right); // 10, right children of 7
    setRight(right, 12);

    right = getRight(right); // 12, right children of 10
    setRight(right, 15);

    right = getRight(right); // 15, right children of 12
    setLeft(right, 11);
    setRight(right, 17);

    return result;
}

void writeFile(Node *node, const char *fileName)
{
    FILE *file = fopen(fileName, "w");
    const char *string = NULL;

    assert(NULL != file);

    string = serialize(node);

    fprintf(file, "%s", string);

    fclose(file);
}

Node *readFile(const char *fileName)
{
    return NULL;
}
