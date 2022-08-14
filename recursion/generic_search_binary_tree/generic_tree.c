#include <stdio.h>
#include <stdlib.h>
#include "generic_tree.h"

typedef struct tree Tree;

struct tree{
    void * content;
    Tree * left;
    Tree * right;
};

Tree * CreateVoidTree(){
    return NULL;
}

Tree * CreateNode(Tree * left, Tree *right, void *content);

Tree * PushTree(Tree * tree, void * content);

void PrintTree(Tree * tree, print_callback function);

Tree * RemoveTree(Tree * tree, compare_callback function, void * key); 

void * SearchTree(Tree * tree, compare_callback function, void * key, char * type);

void DeleteTree(Tree * tree);