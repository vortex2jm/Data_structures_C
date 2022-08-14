#ifndef generic_tree_h
#define generic_tree_h

typedef struct tree Tree;

typedef void (*print_callback)(void * content);
typedef int (*compare_callback)(void * content, void * key, char * type);

Tree * CreateVoidTree();

Tree * CreateNode(Tree * left, Tree *right, void * content);

Tree * PushTree(Tree * tree, void * content);

void PrintTree(Tree * tree, print_callback function);

Tree * RemoveTree(Tree * tree, compare_callback function, void * key); 

void * SearchTree(Tree * tree, compare_callback function, void * key, char * type);

void DeleteTree(Tree * tree);

#endif