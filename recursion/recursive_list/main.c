#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    Lista * lista = InitLista();

    InsereLista(lista,12);
    InsereLista(lista,10);
    InsereLista(lista,4);
    InsereLista(lista,20);
    InsereLista(lista,39);
    InsereLista(lista,98);

    ImprimeLista(lista,0);
    ImprimeLista(lista,1);

    printf("Retirando o 12 da lista\n\n");
    RetiraLista(lista,12);

    ImprimeLista(lista,0);
    ImprimeLista(lista,1);

    printf("Retirando o 20 da lista\n\n");
    RetiraLista(lista,20);

    ImprimeLista(lista,0);
    ImprimeLista(lista,1);  

    printf("Retirando o 98 da lista\n\n");
    RetiraLista(lista,98);

    ImprimeLista(lista,0);
    ImprimeLista(lista,1);

    printf("Verificando o encadeamento da ultima posicao\n\n");
    ImprimeUltima(lista);

    LiberaLista(lista);

    return 0;
}