#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno *IniciaAluno(char *nome, int matricula, float media);

void ImprimeAluno(Aluno *aluno);

int RetornaMatricula(Aluno *aluno);

float RetornaMedia(Aluno *aluno);

char * RetornaNome(Aluno * aluno);

void DestroiAluno(Aluno *aluno);

#endif