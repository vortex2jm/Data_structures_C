#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct aluno{

    char * nome;
    int matricula;
    float media;
};

Aluno *IniciaAluno(char *nome, int matricula, float media){

    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));

    aluno->matricula = matricula;
    aluno->media = media;
    aluno->nome = strdup(nome);

    return aluno;  
}

int RetornaMatricula(Aluno *aluno){

    return aluno->matricula;
}

float RetornaMedia(Aluno *aluno){

    return aluno->media;
}

char * RetornaNome(Aluno * aluno){

    return aluno->nome;
}

void ImprimeAluno(Aluno *aluno){

    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Media: %.2f\n\n", aluno->media);
}

void DestroiAluno(Aluno *aluno){

    if(aluno != NULL){
        free(aluno->nome);
        free(aluno);
    }
}