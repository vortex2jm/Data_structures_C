#include <stdio.h>
#include <stdlib.h>
#include "pilhaDePrato.h"
#include "fila.h"
#include "aluno.h"

int main(){

    int pratos=0, alunos=0, client=0, client2 =0, config=0, prato=0, matricula=0;
    char nome[20];
    float media=0;
    Aluno * aluno;

    printf("Indique a quantidade maxima de pratos que deseja ter em sua pilha: ");
    scanf("%d", &pratos);
    printf("Indique a quantidade maxima de alunos que poderá ter na fila: ");
    scanf("%d", &alunos);

    PilhaPrato* pilhaDePratos = InitPilha(pratos);
    Fila * filaDeAlunos = InitFila(alunos);

    while(1){

        printf("==========Bandejao RU===================\n");

        printf("Digite a operacao que deseja realizar\n");
        printf("Andar fila(1)\n");
        printf("Configurar pilha de pratos(2)\n");
        printf("Configurar fila de alunos(3)\n");
        printf("Sair do programa(0)\n\n");
        printf("-> ");
        scanf("%d", &config);

        if(!config) break;

        else if(config == 1){

            if(TemAlguemNaFila(filaDeAlunos) && TemPratoNaPilha(pilhaDePratos)){
                
                printf("O aluno:\n");
                ImprimeAluno(Fila_Pop(filaDeAlunos));
                printf("pegou o prato: %d\n\n", Pilha_Pop(pilhaDePratos));
            }

            else if(!TemAlguemNaFila(filaDeAlunos) && !TemPratoNaPilha(pilhaDePratos)){

                printf("Nao ha alunos na fila e nem pratos na pilha!\n\n");
            }

            else if(!TemAlguemNaFila(filaDeAlunos)){

                printf("Fila vazia, adicione um aluno!\n\n");
            }

            else if(!TemPratoNaPilha(pilhaDePratos)){

                printf("Pilha vazia, adicione um prato!\n\n");
            }
        }

        else if(config == 2){

            printf("==========Pilha de pratos config========\n");

            while(1){
                printf("\n");
                printf("!!!!!Escolha uma operacao abaixo!!!!!\n");
                printf("Inserir prato(1)\n");
                printf("Retirar prato(2)\n");
                printf("Imprimir pilha(3)\n");
                printf("Sair(0)\n\n");
                printf("-> ");

                scanf("%d", &client);

                if(!client) break;

                else if(client == 1){

                    printf("Digite o prato que deseja inserir: ");
                    scanf("%d", &prato);

                    Pilha_Push(pilhaDePratos, prato);
                }

                else if(client == 2){

                    Pilha_Pop(pilhaDePratos);
                }

                else if(client == 3){

                    PrintPilha(pilhaDePratos);
                }

                else printf("Operacao invalida!\n\n");

            }
        }

        else if(config == 3){

            printf("==========Fila de alunos config========\n");

            while(1){
                printf("\n");
                printf("!!!!!Escolha uma operacao abaixo!!!!!\n");
                printf("Inserir aluno(1)\n");
                printf("Retirar aluno(2)\n");
                printf("Imprimir fila(3)\n");
                printf("Sair(0)\n\n");
                printf("-> ");

                scanf("%d", &client2);

                if(!client2) break;

                else if(client2 == 1){

                    printf("Cadastrar aluno:\n");
                    printf("Nome: ");
                    scanf("%*c%[^\n]", nome);
                    printf("Matricula: ");
                    scanf("%d", &matricula);
                    printf("Media: ");
                    scanf("%f", &media);

                    aluno = IniciaAluno(nome, matricula, media);
                    Fila_Push(filaDeAlunos, aluno);
                }
                
                else if(client2 == 2){

                    Fila_Pop(filaDeAlunos);
                }

                else if(client2 == 3){

                    PrintFila(filaDeAlunos);
                }
            }
        }
    }

    Destructfila(filaDeAlunos);
    DestructPilha(pilhaDePratos);

    return 0;
}