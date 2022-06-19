#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"
#include "fila.h"
#include "lista_de_usuarios.h"

void add_aluno(char *nome_aluno, int matricula_aluno, char *descricao_aluno)
{
    int result = 0;
    while (result == 0)
    {
        result = add_abb(rand(), nome_aluno, matricula_aluno, descricao_aluno);
    }
}

int verificar(char *cpf, char *senha)
{
    NO_LISTA buscado = buscar_lista(cpf);
    if (cpf == buscado.cpf && senha == buscado.senha)
    {
        return 1;
    }
    else
    {
        return 0;
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
            printf("\nDigite o nome do aluno:\n");
            char *nome = malloc(sizeof(char));
            scanf(" %[^\n]s", nome);

            printf("\nDigite a matricula do aluno:\n");
            int matricula;
            scanf("%d", &matricula);

            printf("\nDigite a descricao do livro (maximo 500 caracteres):\n");
            char *descricao = malloc(sizeof(char));
            scanf(" %[^\n]s", descricao);

            add_aluno(nome, matricula, descricao);
        }
        else if (resp == 2)
        {
            imprimir_lista();
            in_ordem(raiz);

            printf(" Digite seu cpf:\n");
            char *cpf = malloc(sizeof(char));
            scanf(" %[^\n]s", cpf);

            printf(" Digite sua senha:\n");
            char *senha = malloc(sizeof(char));
            scanf(" %[^\n]s", senha);

            int retorno = verificar(cpf, senha);
            if (retorno == 1)
            {
                printf("deu certo!");
                // 3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                // 4 - setar novos dados (faltando)
                // 5 - add_fila(....);
            }
            else
            {
                printf("deu errado");
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
