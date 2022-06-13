#include <stdio.h>
#include <time.h>
#include "abb.h"

int test_remover_noRoot(){
    raiz = NULL;
    VERTICE *result = remover(50, raiz);

    return result == NULL;
}

void add_aluno(char *nome_aluno, int matricula_aluno, char *descricao_aluno) {
    int result = 0;
    while (result == 0) {
        result = add_abb(rand(), nome_aluno, matricula_aluno, descricao_aluno);
    }
}

int main()
{
    /*if(test_remover_noRoot() == 0){
        printf("Test failed: test_remover_noRoot");
    }

    printf("Test succeded");
    */
    
    srand(time(NULL));

    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    add_aluno("Pedro", 521443, "Livro de vampiros antigos");
    in_ordem(raiz);

    // printf("\n\n");
    // remover(30, raiz);
    // in_ordem(raiz);
    return 0;
}