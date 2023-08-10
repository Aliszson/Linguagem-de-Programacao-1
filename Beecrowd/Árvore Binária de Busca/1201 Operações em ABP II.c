#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct No
{

    unsigned info;
    struct No *esq;
    struct No *dir;

} No;

_Bool primeiro;

No *ins_abb(int c, No *raiz)
{
    if (raiz == NULL)
    {
        No *n = (No *)malloc(sizeof(No));
        n->info = c;
        n->dir = n->esq = NULL;
        return n;
    }
    else if (c < raiz->info) // anda a esquerda
        raiz->esq = ins_abb(c, raiz->esq);
    else // anda a direita
        raiz->dir = ins_abb(c, raiz->dir);

    return raiz;
}

No *remover(int c, No *raiz)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->info > c) // elemento está a esquerda
        raiz->esq = remover(c, raiz->esq);
    else if (raiz->info < c) // elemento está a direita
        raiz->dir = remover(c, raiz->dir);
    else
    { // se chegou aqui, encontrou o elemento
        if (raiz->esq == NULL && raiz->dir == NULL)
        { // nó sem filhos
            free(raiz);
            raiz = NULL;
        }
        else if (raiz->esq == NULL)
        { // apenas filho a direita
            No *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        else if (raiz->dir == NULL)
        { // apenas filho a esquerda
            No *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else
        {                        // se chegou aqui, tem dois filhos
            No *aux = raiz->esq; // desce um nível a esquerda
            while (aux->dir != NULL)
            { // busca último elemento a direita
                aux = aux->dir;
            }
            raiz->info = aux->info; // troca as informações
            aux->info = c;
            raiz->esq = remover(c, raiz->esq); // remove c, a partir da esquerda da raiz original
        }
    }
    return raiz;
}

_Bool busca(No *no, int valor)
{

    _Bool direita, esquerda;

    if (!no)
        return false;

    if (no->info == valor)
        return true;

    if (no->info > valor)
        esquerda = busca(no->esq, valor);
    else
        direita = busca(no->dir, valor);
}

void impr_ord(No *no)
{

    if (no)
    {
        
        
            impr_ord(no->esq);
            if (!primeiro)
                printf(" %d", no->info);
            else
                printf("%d", no->info), primeiro = false;

            impr_ord(no->dir);
        
    }
}

void impr_pos(No *no)
{

    if (no)
    {

        impr_pos(no->esq);
        impr_pos(no->dir);

        if (!primeiro)
            printf(" %d", no->info);
        else
            printf("%d", no->info), primeiro = false;
    }
}

void impr_pre(No *no)
{

    if (no)
    {

        if (!primeiro)
            printf(" %d", no->info);
        else
            printf("%d", no->info), primeiro = false;

        impr_pre(no->esq);
        impr_pre(no->dir);
    }
}

void main()
{

    char comando[20];
    int valor;

    No *no = NULL;
    while (scanf("%s%*c", comando) != EOF)
    {
        if (strcmp(comando, "I") == 0)
            scanf("%i%*c", &valor), no = ins_abb(valor, no);
        else if (strcmp(comando, "P") == 0)
        {

            scanf("%d%*c", &valor);

            if (busca(no, valor))
                printf("%i existe\n", valor);
            else
                printf("%i nao existe\n", valor);
        }
        else if (strcmp(comando, "R") == 0)
            scanf("%i%*c", &valor), no = remover(valor, no);
        else
        {

            primeiro = true;
            if (strcmp(comando, "INFIXA") == 0)
            {
                impr_ord(no), printf("\n");
            }
            else if (strcmp(comando, "PREFIXA") == 0)
            {
                impr_pre(no), printf("\n");
            }
            else if (strcmp(comando, "POSFIXA") == 0)
            {
                impr_pos(no), printf("\n");
            }
        }
    }
}
