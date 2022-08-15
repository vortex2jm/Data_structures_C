#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_tree.h"

//callbacks===========================//
int compare_key(void * content, void * key, char * type){
  if(!strcmp(type, "matricula")){
    int matricula = *((int*)key);
    if(RetornaMatricula(content) == matricula)
      return 1;
    return 0;
  }
  if(!strcmp(type, "nome")){
    char*nome = (char*)key;
    if(!strcmp(RetornaNome(content), nome))
      return 1;
    return 0;
  }
}

int compare_content(void * content1, void * content2){
  if(RetornaMatricula(content1) > RetornaMatricula(content2)) return 1;
  if(RetornaMatricula(content1) == RetornaMatricula(content2)) return 0;
  if(RetornaMatricula(content1) < RetornaMatricula(content2)) return -1;
}

void print_content(void * content){
  printf("nome: %s\n", RetornaNome(content));
  printf("matricula: %d\n", RetornaMatricula(content));
  printf("media: %f\n\n", RetornaMedia(content));
}

//public functions====================================//
Tree * CreateVoidStudentTree(){
  return CreateVoidTree();
}

Tree * CreateStudentNode(Tree * left, Tree * right, Aluno * student){
  return CreateNode(left, right, student);
}

Tree * PushStudentTree(Tree * tree, Aluno * student){
  return PushTree(tree, student, compare_content);
}

void PrintStudentTree(Tree * tree){
  return PrintTree(tree, print_content);
}

Tree * RemoveStudentTree(Tree * tree, void * key, char * type){
  return RemoveTree(tree, compare_key, key, type);
}

Aluno * SearchStudentTree(Tree * tree, void * key, char * type){
  return SearchTree(tree, compare_key, key, type);
}

void DeleteStudentTree(Tree * tree){
  return DeleteTree(tree);
}