#ifndef lista_h
#define lista_h

typedef struct lista Lista;

Lista * InitLista();

Lista * InsereLista(Lista * lista, int elemento);

void RetiraLista(Lista * lista, int elemento);

void ImprimeLista(Lista * lista);

void LiberaLista(Lista * lista);

#endif