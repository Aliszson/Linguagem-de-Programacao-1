#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor;
    struct no *esq, *dir;
} No;

No *criarNo(char valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No *inserir(No *raiz, char valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    else if (valor < raiz->valor)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void impr_ord(No *raiz)
{
    if (raiz != NULL)
    {
        impr_ord(raiz->esq);
        printf("%c ", raiz->valor);
        impr_ord(raiz->dir);
    }
}

void impr_pre(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->valor);
        impr_pre(raiz->esq);
        impr_pre(raiz->dir);
    }
}

void impr_pos(No *raiz)
{
    if (raiz != NULL)
    {
        impr_pos(raiz->esq);
        impr_pos(raiz->dir);
        printf("%c ", raiz->valor);
    }
}

No *buscar(No *raiz, char valor)
{
    if (raiz == NULL || raiz->valor == valor)
    {
        return raiz;
    }
    else if (valor < raiz->valor)
    {
        return buscar(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        return buscar(raiz->dir, valor);
    }
    return NULL;
}

void nula(No *raiz)
{
    if (raiz != NULL)
    {
        nula(raiz->esq);
        nula(raiz->dir);
        free(raiz);
    }
}

int main()
{
    No *raiz = NULL;
    char comando[8];
    char valorChar;

    while (scanf(" %s", comando) != EOF)
    {
        if (strcmp(comando, "I") == 0)
        {
            scanf(" %c", &valorChar);
            raiz = inserir(raiz, valorChar);
        }
        else if (strcmp(comando, "INFIXA") == 0)
        {
            impr_ord(raiz);
            puts("");
        }
        else if (strcmp(comando, "PREFIXA") == 0)
        {
            impr_pre(raiz);
            puts("");
        }
        else if (strcmp(comando, "POSFIXA") == 0)
        {
            impr_pos(raiz);
            puts("");
        }
        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %c", &valorChar);
            No *arv = buscar(raiz, valorChar);
            if (arv)
            {
                printf("%c existe", valorChar);
                printf("\n");
            }
            else
            {
                printf("%c nao existe", valorChar);
                printf("\n");
            }
        }
    }
    

    nula(raiz);

    return 0;
}