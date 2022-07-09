#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct lista Lista;

Lista *IniciaLista();

void InsereNaLista(Lista *lista, Aluno *aluno);

Aluno *RetiraDaLista(Lista *lista, char *nome);

void ImprimeLista(Lista *lista);

void ImprimeListaReversa(Lista * lista);

void DestroiLista(Lista * lista);

#endif // !LISTA_H
