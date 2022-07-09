#include "lista.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel Cel;

struct lista { //DEFININDO A SENTINELA

  Cel *primeira;
  Cel *ultima;
};

struct cel { //DEFININDO A CELULA

  Aluno *aluno;
  Cel *proxima;
  Cel *anterior;
};

Lista *IniciaLista() {

  Lista *lista = (Lista *)malloc(sizeof(Lista));

  lista->primeira = NULL;
  lista->ultima = NULL;

  return lista;
}

void InsereNaLista(Lista *lista, Aluno *aluno) { //função para inserir no final da lista

  Cel * nova = (Cel*)malloc(sizeof(Cel));

  nova->aluno = aluno;
  nova->proxima = NULL;
  nova->anterior = NULL;

  if(lista->primeira == NULL){

    lista->primeira = nova;
    lista->ultima = nova;

  } 
  else{

    nova->anterior = lista->ultima;
    lista->ultima->proxima = nova;
    lista->ultima = nova;
  }

} 

Aluno *RetiraDaLista(Lista *lista, char *nome){

  Cel * atual = lista->primeira;
  Cel * anterior;
  Aluno * al;

  while(atual!= NULL && strcmp(RetornaNome(atual->aluno), nome)){

    anterior = atual;
    atual = atual->proxima;
  
  }

  if(atual == NULL) return NULL;


  al = atual->aluno; //atribuindo o aluno da célula atual antes das modificações


  //condições possíveis para a posição da célula selecionada
  if(lista->primeira == atual){
    
    lista->primeira = atual->proxima;
  }

  else if(lista->ultima == atual){

    lista->ultima = anterior;
    lista->ultima->proxima = NULL;
    lista->ultima->anterior = anterior->anterior;
  }

  else if(lista->primeira == atual && lista->ultima == atual){

    lista->primeira = NULL;
    lista->ultima = lista->primeira;
  }

  else{

    anterior->proxima = atual->proxima;
    atual->proxima->anterior = atual->anterior;
  }

  free(atual);

  return al;
}

void ImprimeLista(Lista *lista){
  
  Cel * atual = lista->primeira;
  Cel * aux;

  if(atual == NULL) printf("Lista vazia, insira um novo aluno!!!\n");

  while(atual != NULL){

    aux = atual->proxima; 
    ImprimeAluno(atual->aluno);
    atual = aux;
  } 
}

void ImprimeListaReversa(Lista * lista){

  Cel * atual = lista->ultima;
  Cel * aux;

  if(atual == NULL) printf("Lista vazia, insira um novo aluno!!!\n");

  while(atual != NULL){

    aux = atual->anterior;
    ImprimeAluno(atual->aluno);
    atual = aux;
  }
}

void DestroiLista(Lista * lista){

  Cel * atual = lista->primeira;
  Cel * pp;

  while(atual != NULL){

    pp = atual->proxima;
    DestroiAluno(atual->aluno);
    free(atual);
    atual = pp;
  }

  free(lista);
}