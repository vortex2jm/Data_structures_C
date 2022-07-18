#include <stdio.h>
#include "tree.h"
#include "aluno.h"

int main(){ 

    Aluno * aluno1=NULL, * aluno2=NULL, * aluno3=NULL, * aluno4=NULL, * aluno5=NULL, * aluno6=NULL, * aluno7=NULL;
    
    aluno1 = IniciaAluno("Joao", 2021, 10.0);
    aluno2 = IniciaAluno("Kevin", 2020, 9.8);
    aluno3 = IniciaAluno("Lara", 2019, 8.7);
    aluno4 = IniciaAluno("Caio", 2018, 9.7);
    aluno5 = IniciaAluno("Afonso", 2017, 9.2);
    aluno6 = IniciaAluno("Afonso", 2017, 9.2);
    aluno7 = IniciaAluno("Lara", 2019, 8.7);

    Tree * tree = CreateTree(aluno1, 
                    CreateTree(aluno2,
                        CreateTree(aluno4, CreateVoidTree(), CreateVoidTree()),
                        CreateTree(aluno5, CreateVoidTree(), CreateVoidTree())),
                    CreateTree(aluno3,
                        CreateTree(aluno6, CreateVoidTree(), CreateVoidTree()),
                        CreateTree(aluno7, CreateVoidTree(), CreateVoidTree())));

    PrintTree(tree);

    if(IsInTree(tree, "Joao")) printf("Joao is in tree!\n");
    else printf("Joao is not in tree!\n");

    if(IsInTree(tree, "Matheus")) printf("Matheus is in tree!\n");
    else printf("Matheus is not in tree!\n");

    printf("A quantidade de nós folhas dessa arvore eh = %d\n\n", LeafAmount(tree));
    printf("O nome Afonso aparece na arvore %d vezes\n\n", NameOcurrences(tree, "Afonso"));
    printf("A altura dessa arvore eh %d\n\n", Height(tree));

    DestructTree(tree);

    return 0;
}