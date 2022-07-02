#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertice
{
    // Dados iniciais da encomenda de um livro
    int id; // identificador
    char nome_aluno[500];
    int matricula_aluno;
    char descricao_aluno[500];

    struct Vertice *esq;
    struct Vertice *dir;
} VERTICE;

VERTICE *raiz = NULL;

VERTICE *buscar(int id, VERTICE *aux)
{

    if (aux != NULL)
    {
        if (aux->id == id)
        {
            return aux;
        }
        else if (id < aux->id)
        {
            if (aux->esq != NULL)
            {
                return buscar(id, aux->esq);
            }
            else
            {
                return aux;
            }
        }
        else if (id > aux->id)
        {
            if (aux->dir != NULL)
            {
                return buscar(id, aux->dir);
            }
            else
            {
                return aux;
            }
        }
    }
    else
    {
        return NULL;
    }
}

int add_abb(int id, char nome_aluno[], int matricula_aluno, char descricao_aluno[])
{
    VERTICE *aux = buscar(id, raiz);

    if (aux != NULL && aux->id == id)
    {
        printf("Insercao invalida!\n");
        return 0;
    }
    else
    {
        VERTICE *novo = malloc(sizeof(VERTICE));
        novo->id = id;
        strcpy(novo->nome_aluno, nome_aluno);
        novo->matricula_aluno = matricula_aluno;
        strcpy(novo->descricao_aluno, descricao_aluno);
        novo->esq = NULL;
        novo->dir = NULL;

        if (aux == NULL)
        { // arvore esta vazia
            raiz = novo;
        }
        else
        {
            if (id < aux->id)
            {
                aux->esq = novo;
            }
            else
            {
                aux->dir = novo;
            }
        }
        return 1;
    }
}

void in_ordem(VERTICE *aux)
{
    if (aux == NULL)
    {
        printf("\nArvore vazia");
    }

    printf("%d | %s | %d | %s\n", aux->id, aux->nome_aluno, aux->matricula_aluno, aux->descricao_aluno);
    if (aux->esq != NULL)
    {
        in_ordem(aux->esq);
    }

    if (aux->dir != NULL)
    {
        in_ordem(aux->dir);
    }
}

VERTICE *menorDosMaiores(VERTICE *aux)
{
    VERTICE *atual = aux;

    while (atual && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

VERTICE *remover(int id, VERTICE *aux)
{
    if (aux == NULL)
        return aux;

    if (id < aux->id)
        aux->esq = remover(id, aux->esq);

    else if (id > aux->id)
        aux->dir = remover(id, aux->dir);

    else
    {
        // node with only one child or no child
        if (aux->esq == NULL)
        {
            VERTICE *temp = aux;
            aux = aux->dir;
            free(temp);
            return aux;
        }
        else if (aux->dir == NULL)
        {
            VERTICE *temp = aux;
            aux = aux->esq;
            free(temp);
            return aux;
        }
        else
        {

            // node with two children: Get the inorder successor
            // (smallest in the dir subtree)
            VERTICE *temp = menorDosMaiores(aux->dir);

            // Copy the inorder successor's content to this node
            aux->id = temp->id;
            strcpy(aux->nome_aluno, temp->nome_aluno);
            aux->matricula_aluno = temp->matricula_aluno;
            strcpy(aux->descricao_aluno, temp->descricao_aluno);

            // Delete the inorder successor
            aux->dir = remover(temp->id, aux->dir);
        }
    }
    return aux;
}

VERTICE *remover_abb(int id)
{
    raiz = remover(id, raiz);
    return raiz;
}