#include <stdio.h>
#include <stdlib.h>
#include "student_tree.h"
#include "aluno.h"

int main(){

    Aluno *aluno1, *aluno2, *aluno3, *aluno4;
    aluno1 = IniciaAluno("joao",1,10);
    aluno2 = IniciaAluno("clara",2,9);
    aluno3 = IniciaAluno("gustavo",3,8);
    aluno4 = IniciaAluno("tiago",4,7);

    Tree * tree = CreateVoidTree();
    tree = PushStudentTree(tree,aluno1);
    tree = PushStudentTree(tree,aluno2);
    tree = PushStudentTree(tree,aluno3);
    tree = PushStudentTree(tree,aluno4);

    printf("===Imprimindo a arvore===\n\n");
    PrintStudentTree(tree);
    int matricula = RetornaMatricula(aluno2);
    tree = RemoveStudentTree(tree, &matricula, "matricula");
    
    printf("===Imprimindo a arvore===\n\n");
    PrintStudentTree(tree);

    Aluno * aux = SearchStudentTree(tree, RetornaNome(aluno1), "nome");
    printf("===Aluno achado===\n\n");
    ImprimeAluno(aux);

    DeleteStudentTree(tree);
    DestroiAluno(aluno1);
    DestroiAluno(aluno2);
    DestroiAluno(aluno3);
    DestroiAluno(aluno4);
    
    return 0;
}