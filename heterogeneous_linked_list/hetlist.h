#ifndef het_list_h
#define het_list_h

typedef struct hetlist HetList;

HetList * InitHetList(void);

HetList * Push(HetList * list, char * type, void * veiculo);

void PrintHetList(HetList * list);

void RemoveById(HetList * list, int id);

void DestructList(HetList * list);

#endif