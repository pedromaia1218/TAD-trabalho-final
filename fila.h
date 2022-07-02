#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido
{
    int id;
    char nome_aluno[500];
    int matricula_aluno;
    char descricao_aluno[500];
    char campus_livro[500];
    char campus_aluno[500];
    char nome_secretario[500];
    int prioridade;
    struct pedido *prox;
} NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void add_fila(int id, char nome_aluno[], int matricula_aluno, char descricao_aluno[], char campus_livro[], char campus_aluno[], char nome_secretario[], int prioridade)
{
    NO *novo = malloc(sizeof(NO));
    novo->id = id;
    strcpy(novo->nome_aluno, nome_aluno);
    novo->matricula_aluno = matricula_aluno;
    strcpy(novo->descricao_aluno, descricao_aluno);
    strcpy(novo->campus_livro, campus_livro);
    strcpy(novo->campus_aluno, campus_aluno);
    strcpy(novo->nome_secretario, nome_secretario);
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (inicio == NULL)
    {
        inicio = novo;
        fim = novo;
        tam++;
    }
    else
    {
        NO *aux = inicio;
        if (inicio->prioridade > prioridade)
        {
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }
        else
        {
            while (aux->prox != NULL && aux->prox->prioridade < prioridade)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        }
    }
}

void imprimir()
{
    NO *aux = inicio;
    for (int i = 0; i < tam; i++)
    {
        printf("\n%d | %s | %d | %s | %s | %s | %s | %d\n", aux->id, aux->nome_aluno, aux->matricula_aluno, aux->descricao_aluno, aux->campus_livro, aux->campus_aluno, aux->nome_secretario, aux->prioridade);
        aux = aux->prox;
    }
}

NO remover_fila()
{
    NO pedido;
    if (inicio != NULL)
    {
        NO *lixo = inicio;
        inicio = inicio->prox;
        pedido.id = lixo->id;
        strcpy(pedido.nome_aluno, lixo->nome_aluno);
        pedido.matricula_aluno = lixo->matricula_aluno;
        strcpy(pedido.descricao_aluno, lixo->descricao_aluno);
        strcpy(pedido.campus_livro, lixo->campus_livro);
        strcpy(pedido.campus_aluno, lixo->campus_aluno);
        strcpy(pedido.nome_secretario, lixo->nome_secretario);
        pedido.prioridade = lixo->prioridade;
        free(lixo);
        tam--;
        if (tam == 1)
        {
            fim = NULL;
        }
    }
    return pedido;
}