#include "aluno.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
    
    //Criando uma lista
    Lista * lista;
    lista = IniciaLista(); //incializando uma lista
    ImprimeLista(lista); //mostrando que a lista esta vazia

    // Criando alunos
    Aluno * a1, *a2, *a3;

    a1 = IniciaAluno("Joao",123,10.5);
    a2 = IniciaAluno("Victoria",456,10);
    a3 = IniciaAluno("Camila",789,12);

    // Inserindo o primeiro aluno
    printf("===============Inserindo o primeiro aluno===============\n\n");
    InsereNaLista(lista,a1);
    ImprimeLista(lista); //imprimindo o unico aluno da lista

    //Inserindo um aluno na ultima posição da lista
    printf("=============Inserindo o segundo aluno===============\n\n");
    InsereNaLista(lista,a2);
    ImprimeLista(lista); //Imprimindo a lista com a ordem dos alunos

    //Inserindo novamente um aluno na ultima posição da lista
    printf("=============Inserindo o terceiro aluno===============\n\n");
    InsereNaLista(lista,a3);
    ImprimeLista(lista);

    printf("=============Imprimindo a lista em ordem reversa==========\n\n");
    ImprimeListaReversa(lista);

    // Retirando um aluno da lista pelo nome
    printf("=============Retirando Camila da lista=============\n\n");
    a3 = RetiraDaLista(lista,"Camila");
    DestroiAluno(a3);
    ImprimeLista(lista);

    DestroiLista(lista);

    return 0;
}