#ifndef word_h
#define word_h

typedef struct sword Word;

Word *InitWord(char *word, int frequency);

void PrintWord(Word *word);

char *GetWord(Word *word);

int GetFrequency(Word *word);

void SetFrequency(Word *word, int frequency);

void SetNextWord(Word * currentWord, Word * nextWord);

Word * GetNextWord(Word * word);

void DeleteWord(Word *word);

#endif