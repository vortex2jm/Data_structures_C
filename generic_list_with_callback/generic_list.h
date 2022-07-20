#ifndef generic_list
#define generic_list

typedef struct glist Glist;
typedef void (*print_list)(void * element);
typedef int (*list_remove)(void * element, void * key);

Glist * CreateVoidList();

Glist * PushList(Glist * list, void * element);

void PrintList(Glist * list, print_list print_callback);

void ListRemove(Glist * list, list_remove remove_callback, void * key);

void DestructList(Glist * list);

#endif