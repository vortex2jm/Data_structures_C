#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista * lista = InitLista();

    InsereLista(lista, 4);
    RetiraLista(lista, 4);

    ImprimeLista(lista);

    return 0;
}