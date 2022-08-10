#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define SIZE 127

//==================================================================//
int GenerateIndex(int key){
    return key % SIZE;
}

//==================================================================//
void InitHash(Hash map){
    for(int i=0;i<SIZE;i++){
        map[i] = NULL;
    }
}

//==================================================================//
int GetCharSum(char * word){

    int sum=0, index=0;
    while(1){
        if(word[index] == '\0') break;
        sum += word[index];
        index++;
    }
    return sum;
}

//==================================================================//
void HashInsert(Hash map, Word * word){
    
    int index = GenerateIndex(GetCharSum(GetWord(word)));

    //adicionar função de aumentar frequecia

    if(map[index]){
        SetNextWord(word, map[index]);
        map[index] = word;
        return;    
    }
    map[index] = word;
}

//==================================================================//
Word * HashSearch(Hash map, char * word){

    int h = GenerateIndex(GetCharSum(word));
    Word * current = map[h];
    
    while(current){
        if(!strcmp(GetWord(current), word)){
            return current;
        }
        current = GetNextWord(current);
    }
    return NULL;
}

//==================================================================//
void PrintHash(Hash map){

    Word * current;
    for(int i=0;i<SIZE;i++){
        if(map[i]){
            current = map[i];
            while(current){
                PrintWord(current);
                current = GetNextWord(current);
            }
        }
    }
}

//==================================================================//
void DeleteHash(Hash map){
    
    Word *current, *next;
    for(int i=0;i<SIZE;i++){
        if(map[i]){
            current = map[i];
            while(current){
                next = GetNextWord(current);
                DeleteWord(current);
                current = next;
            }                           
        }
    }
}