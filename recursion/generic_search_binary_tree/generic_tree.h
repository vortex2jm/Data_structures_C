#ifndef generic_tree_h
#define generic_tree_h

typedef struct tree Tree;

typedef void (*print_callback)(void * content);
typedef int (*compare_callback)(void * content, void * key, char * type);
typedef int (*equal_callback)(void * content1, void * content2);

Tree * CreateVoidTree();

Tree * CreateNode(Tree * left, Tree *right, void * content);

Tree * PushTree(Tree * tree, void * content, equal_callback function);

void PrintTree(Tree * tree, print_callback function);

Tree * RemoveTree(Tree * tree, compare_callback function, void * key, char * type); 

void * SearchTree(Tree * tree, compare_callback function, void * key, char * type);

void DeleteTree(Tree * tree);

#endif