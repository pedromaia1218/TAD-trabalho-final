#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"
#include "fila.h"
#include "lista_de_usuarios.h"

NO_LISTA *consultarSecretario(char *cpf, char *senha)
{
    NO_LISTA *buscado = buscar_lista(cpf);
    if (buscado != NULL && strcmp(senha, buscado->senha) == 0)
    {
        return buscado;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    srand(time(NULL));

    add_lista("Tati", "497504", "151515", 's', 0);
    add_lista("Sergio", "521443", "656565", 't', 1);

    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while (resp != 0)
    {
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada: ");
        scanf("%d", &resp);

        if (resp == 1)
        {
            printf("Digite o nome do aluno: ");
            char nome[500];
            scanf_s(" %[^\n]s", nome, 500);

            printf("Digite a matricula do aluno: ");
            int matricula;
            scanf("%d", &matricula);

            printf("Digite a descricao do livro (maximo 500 caracteres): ");
            char descricao[500];
            scanf_s(" %[^\n]s", descricao, 500);

            int result = 0;
            while (result == 0)
            {
                result = add_abb(rand(), nome, matricula, descricao);
            }
        }
        else if (resp == 2)
        {
            imprimir_lista();
            in_ordem(raiz);

            printf("Digite seu cpf:");
            char *cpf = malloc(sizeof(char));
            scanf(" %[^\n]s", cpf);

            printf("Digite sua senha:");
            char *senha = malloc(sizeof(char));
            scanf(" %[^\n]s", senha);

            NO_LISTA *retorno = consultarSecretario(cpf, senha);
            if (retorno != NULL)
            {
                printf("\nDigite o ID da solicitacao: ");
                int id_requerido;
                scanf("%d", &id_requerido);

                VERTICE *copia = malloc(sizeof(VERTICE));
                VERTICE *buscado = buscar(id_requerido, raiz);
                copia->id = buscado->id;
                strcpy(copia->nome_aluno, buscado->nome_aluno);
                copia->matricula_aluno = buscado->matricula_aluno;
                strcpy(copia->descricao_aluno, buscado->descricao_aluno);

                remover_abb(id_requerido);
                printf("\n\n%d %s %d %s\n\n", copia->id, copia->nome_aluno, copia->matricula_aluno, copia->descricao_aluno);
                in_ordem(raiz);
                // 4 - setar novos dados (faltando)
                // 5 - add_fila(....);
            }
            else
            {
                printf("\nLogin invalido!\n\n");
            }
        }
        else if (resp == 3)
        {
            // 2 - verificar o usuario
            // int retorno = verificar(cpf, senha);
            // if (retorno == 1)
            // {
            //     // remover da fila de prioridade
            // }
        }
    }
    return 0;
}
