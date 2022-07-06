#ifndef pilha_h
#define pilha_h

typedef struct pilha_prato PilhaPrato;

PilhaPrato * InitPilha(int qtdElementos);

void Pilha_Push(PilhaPrato * pilha, int elemento);

int Pilha_Pop(PilhaPrato * pilha);

void PrintPilha(PilhaPrato * pilha);

void DestructPilha(PilhaPrato * pilha);

int TemPratoNaPilha(PilhaPrato * pilha);

#endif