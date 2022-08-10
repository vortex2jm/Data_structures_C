#ifndef hash_h
#define hash_h
#include "word.h"
#define SIZE 127

typedef Word* Hash[SIZE];

void InitHash(Hash map);

int GenerateIndex(int key);

int GetCharSum(char * word);

void HashInsert(Hash map, Word * word);

Word * HashSearch(Hash map, char * word);

void PrintHash(Hash map);

void DeleteHash(Hash map);

#endif