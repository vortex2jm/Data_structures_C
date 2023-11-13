#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "aluno.h"

int main(){
 
    Aluno * aluno1, *aluno2, *aluno3, *aluno4;

    aluno1 = IniciaAluno("Joao", 1, 10);
    aluno2 = IniciaAluno("Caio",2,9);
    aluno3 = IniciaAluno("Lara",3,8);
    aluno4 = IniciaAluno("Victoria",4,7);

    Tree * tree = CreateVoidTree();
    tree = PushTree(tree, aluno3);
    tree = PushTree(tree, aluno4);
    tree = PushTree(tree, aluno1);
    tree = PushTree(tree, aluno2);
    printf("===Imprimindo a arvore===\n\n");
    PrintTree(tree);

    Aluno * al = SearchStudent(tree, 3);
    if(al){
        printf("\n===Aluno encontrado===\n\n");
        ImprimeAluno(al);
    } 
    else
        printf("Este aluno nao existe na arvore!\n");          

    tree = RemoveNode(tree, RetornaMatricula(aluno4));
    printf("===Imprimindo a arvore===\n\n");
    PrintTree(tree);

    DestroiAluno(aluno1);
    DestroiAluno(aluno2);
    DestroiAluno(aluno3);
    DestroiAluno(aluno4);   
    DeleteTree(tree);

    return 0;
}