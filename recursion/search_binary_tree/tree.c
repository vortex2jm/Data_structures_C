#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "aluno.h"

typedef struct tree Tree;

struct tree{
    Aluno * aluno;
    Tree * left;
    Tree * right;
};

//===================================================================//
Tree * CreateVoidTree(){
    return NULL;
}

//===================================================================//
Tree * CreateNode(Tree * left, Tree * right, Aluno * student){
    Tree * tree = malloc(sizeof(Tree));
    tree->left = left;
    tree->right = right;
    tree->aluno = student;
    return tree;
}

//===================================================================//
Aluno * SearchStudent(Tree * tree, int matricula){
    if(!tree)return NULL;
    Aluno * aluno = NULL;
    if(matricula == RetornaMatricula(tree->aluno)) return tree->aluno;

    aluno = SearchStudent(tree->left, matricula);
    if(aluno) return aluno;
    aluno = SearchStudent(tree->right, matricula);
    if(aluno) return aluno;

    return NULL;
}

//===================================================================//
void PrintTree(Tree * tree){
    if(!tree)return;
    ImprimeAluno(tree->aluno);
    PrintTree(tree->left);
    PrintTree(tree->right);
}

//===================================================================//
Tree * PushTree(Tree * tree, Aluno * student){
    if(!tree){
        return CreateNode(CreateVoidTree(), CreateVoidTree(), student);
    }
    if(RetornaMatricula(student) > RetornaMatricula(tree->aluno))
        tree->right = PushTree(tree->right, student);
    else
        tree->left = PushTree(tree->left, student);
    return tree;
}

//===================================================================//
Tree * RemoveNode(Tree * tree, int matricula){
    if(!tree)return NULL;
    Tree * aux;
    if(RetornaMatricula(tree->aluno) == matricula){
        if(!tree->left && !tree->right){
            free(tree);
            return NULL;
        }
        if(!tree->left){
            aux = tree->right;
            free(tree);
            return aux;
        }
        if(!tree->right){
            aux = tree->left;
            free(tree);
            return aux;
        }
        aux = tree->left;
        while(aux->right){
            aux = aux->right;
        }

        Aluno * alunoAux;
        alunoAux = tree->aluno;
        tree->aluno = aux->aluno;
        aux->aluno = alunoAux;
        
        tree->left = RemoveNode(tree->left,matricula);
    }
    tree->right = RemoveNode(tree->right, matricula);
    tree->left = RemoveNode(tree->left, matricula);
    return tree;
}

//===================================================================//
void DeleteTree(Tree * tree){
    if(!tree)return;
    DeleteTree(tree->left);
    DeleteTree(tree->right);
    free(tree);
}