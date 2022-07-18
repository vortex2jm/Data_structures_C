#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct tree{

    Aluno * aluno;
    Tree * left;
    Tree * right;
}Tree;

//================================================================//
Tree * CreateVoidTree(void){
    return NULL;
}

//================================================================//
Tree * CreateTree(Aluno * aluno, Tree * left, Tree * right){

    Tree * newTree = malloc(sizeof(Tree));
    newTree->aluno = aluno;
    newTree->left = left;
    newTree->right = right;
    return newTree;
}

//================================================================//
int IsVoidTree(Tree * tree){
    return !tree;
}

//================================================================//
void PrintTree(Tree * tree){

    if(IsVoidTree(tree)) return;
    ImprimeAluno(tree->aluno);
    PrintTree(tree->left);
    PrintTree(tree->right);   
}

//================================================================//
Tree * DestructTree(Tree * tree){

    if(IsVoidTree(tree)) return NULL;
    DestructTree(tree->left);
    DestructTree(tree->right);
    DestroiAluno(tree->aluno);
    free(tree);

    return NULL;
}

//================================================================//
int IsInTree(Tree * tree, char * nome){

    if(IsVoidTree(tree)) return 0;
    return !strcmp(nome, RetornaNome(tree->aluno)) || IsInTree(tree->left, nome) || IsInTree(tree->right, nome); 
}

//================================================================//
int LeafAmount(Tree * tree){

    if(IsVoidTree(tree)) return 0;
    else if(IsVoidTree(tree->left) && IsVoidTree(tree->right)) return 1;
    else return LeafAmount(tree->left) + LeafAmount(tree->right);
}

//================================================================//
int NameOcurrences(Tree * tree, char * name){

    if(IsVoidTree(tree)) return 0;
    else if(!strcmp(name, RetornaNome(tree->aluno))) return 1 + NameOcurrences(tree->left, name) + NameOcurrences(tree->right, name);
    else return NameOcurrences(tree->left, name) + NameOcurrences(tree->right, name);
}

//================================================================//
int Height(Tree * tree){

    if(IsVoidTree(tree)) return -1;
    else{
        if(Height(tree->left) > Height(tree->right)) return 1 + Height(tree->left);
        else return 1 + Height(tree->right);
    }
}