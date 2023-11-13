#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

typedef struct sword Word;

struct sword
{
    char *word;
    int frequency;
    Word *next;
};

Word *InitWord(char *word, int frequency)
{

    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = frequency;
    newWord->next = NULL;

    return newWord;
}

void PrintWord(Word *word)
{
    printf("palavra = %s\n", word->word);
    printf("frequencia = %d\n\n", word->frequency);
}

char *GetWord(Word *word)
{
    return word->word;
}

int GetFrequency(Word *word)
{
    return word->frequency;
}

void SetFrequency(Word *word, int frequency)
{
    word->frequency += frequency;
}

void SetNextWord(Word * currentWord, Word * nextWord){
    currentWord->next = nextWord;
}

Word * GetNextWord(Word * word){
    return word->next;
}

void DeleteWord(Word *word)
{
    if (word)
    {
        if (word->word)
            free(word->word);
        free(word);
    }
}

int SameWords(Word * word1, Word * word2){
    return !strcmp(word1->word, word2->word);
}