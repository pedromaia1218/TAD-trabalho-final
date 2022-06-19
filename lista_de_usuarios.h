#include <stdio.h>
#include <stdlib.h>

typedef struct no_lista
{
    char *nome;
    char *cpf;
    char *senha;
    char tipo;

    struct no_lista *prox;
} NO_LISTA;

NO_LISTA *inicio_lista = NULL;
NO_LISTA *fim_lista = NULL;
int tam_lista = 0;

void add_lista(char *nome, char *cpf, char *senha, char tipo, int pos)
{

    if (pos >= 0 && pos <= tam_lista)
    {

        NO_LISTA *novo = malloc(sizeof(NO_LISTA));
        novo->nome = nome;
        novo->cpf = cpf;
        novo->senha = senha;
        novo->tipo = tipo;
        novo->prox = NULL;

        if (inicio_lista == NULL)
        {
            inicio_lista = novo;
            fim_lista = novo;
            tam_lista++;
        }
        else if (pos == 0)
        {
            novo->prox = inicio_lista;
            inicio_lista = novo;
            tam_lista++;
        }
        else if (pos == tam_lista)
        {
            fim_lista->prox = novo;
            fim_lista = novo;
            tam_lista++;
        }
        else
        {
            NO_LISTA *aux = inicio_lista;
            for (int i = 0; i < pos - 1; i++)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam_lista++;
        }
    }
    else
    {
        printf("deu ruim!!\n");
    }
}

void imprimir_lista()
{
    NO_LISTA *aux = inicio_lista;
    for (int i = 0; i < tam_lista; i++)
    {
        printf("USUARIO: %s | %s | %s | %c\n", aux->nome, aux->cpf, aux->senha, aux->tipo);
        aux = aux->prox;
    }
}

NO_LISTA buscar_lista(char *cpf)
{
    NO_LISTA usuario;
    NO_LISTA *aux = inicio_lista;
    if (aux->cpf == cpf)
    {
        usuario.nome = aux->nome;
        usuario.cpf = aux->cpf;
        usuario.senha = aux->senha;
        usuario.tipo = aux->tipo;

        return usuario;
    }
    else
    {
        while (cpf != aux->prox->cpf)
        {
            aux = aux->prox;
        }
        usuario.nome = aux->prox->nome;
        usuario.cpf = aux->prox->cpf;
        usuario.senha = aux->prox->senha;
        usuario.tipo = aux->prox->tipo;

        return usuario;
    }
}