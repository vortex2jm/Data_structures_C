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

Tree * CreateNode(Tree * left, Tree *right, void *content){
    Tree * tree = malloc(sizeof(Tree));
    tree->left = left;
    tree->right = right;
    tree->content = content;
    return tree;
}

Tree * PushTree(Tree * tree, void * content, equal_callback function){
    if(!tree) return CreateNode(CreateVoidTree(), CreateVoidTree(), content);
    if(function(content, tree->content) > 0)
        tree->right = PushTree(tree->right, content, function);
    else if(function(content, tree->content) < 0)
        tree->left = PushTree(content, tree->content, function);
    return tree;
}

void PrintTree(Tree * tree, print_callback function){
    if(!tree) return;
    function(tree->content);
    PrintTree(tree->left, function);
    PrintTree(tree->right, function);
}

Tree * RemoveTree(Tree * tree, compare_callback function, void * key, char * type){
    if(!tree)return NULL;
    Tree * treeAux;
    if(function(tree->content, key, type)){
        if(!tree->left && !tree->right){
            free(tree);
            return NULL;
        }
        if(!tree->left){
            treeAux = tree->right;
            free(tree);
            return treeAux;
        }
        if(!tree->right){
            treeAux = tree->left;
            free(tree);
            return treeAux;
        }
        //se for nó interno
        treeAux = tree->left;
        while(treeAux->right){
            treeAux = treeAux->right;
        }

        //reposicionando
        void * contentAux;
        contentAux = tree->content;
        tree->content = treeAux->content;
        treeAux->content = contentAux;

        tree->left = RemoveTree(tree->left, function, key, type);
    }
    tree->left = RemoveTree(tree->left, function, key, type);
    tree->right = RemoveTree(tree->right, function, key, type);
    return tree;
} 

void * SearchTree(Tree * tree, compare_callback function, void * key, char * type){

    if(!tree)return NULL;
    if(function(tree->content, key, type)) return tree->content;

    void * aux;
    aux = SearchTree(tree->left, function, key, type);
    if(aux)return aux;
    aux = SearchTree(tree->right, function, key, type);
    if(aux)return aux;

    return NULL;
}

void DeleteTree(Tree * tree){
    if(!tree)return;
    DeleteTree(tree->left);
    DeleteTree(tree->right);
    free(tree);
}