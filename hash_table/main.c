#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "hash.h"

int main(){

    //Adicionar função para pegar palavras de um arquivo de texto

    Word * word1, *word2, *word3, *word4;
    word1 = InitWord("Joao",2);
    word2 = InitWord("Paulo",1);
    word3 = InitWord("Moura",1); 
    word4 = InitWord("Clevelares",1);

    Hash table;
    InitHash(table);

    HashInsert(table, word1);
    HashInsert(table, word2);
    HashInsert(table, word3);
    HashInsert(table, word4);

    PrintHash(table);
    DeleteHash(table);

    return 0;
}