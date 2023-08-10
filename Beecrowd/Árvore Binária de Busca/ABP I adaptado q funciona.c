#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 100

typedef struct No
{

    char info;
    struct No *esq;
    struct No *dir;

} No;

char valorInfixo[MAXSIZE] = {0};
char valorPosfixo[MAXSIZE] = {0};
char valorPrefixo[MAXSIZE] = {0};

int i = 0;
int j = 0;
int k = 0;

No *ins_abb(char c, No *raiz)
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

_Bool busca(No *no, char letra)
{

    _Bool direita, esquerda;

    if (!no)
        return false;

    if (no->info == letra)
        return true;

    if (no->info > letra)
        esquerda = busca(no->esq, letra);
    else
        direita = busca(no->dir, letra);
}

void impr_ord(char *letras)
{

    int z;
    for (z = 0; z < i; ++z)
        if (!z)
            printf("%c", valorInfixo[z]);
        else
            printf(" %c", valorInfixo[z]);

    i = 0;
    printf("\n");
}

void impr_pre(char *letras)
{

    int z;
    for (z = 0; z < k; ++z)
        if (!z)
            printf("%c", valorPrefixo[z]);
        else
            printf(" %c", valorPrefixo[z]);

    k = 0;
    printf("\n");
}

void impr_pos(char *letras)
{

    int z;
    for (z = 0; z < j; ++z)
        if (!z)
            printf("%c", valorPosfixo[z]);
        else
            printf(" %c", valorPosfixo[z]);

    j = 0;
    printf("\n");
}

void impr_ord(No *no)
{

    if (no)
    {

        impr_ord(no->esq);
        valorInfixo[i++] = no->info;
        impr_ord(no->dir);
    }
}

void impr_pos(No *no)
{

    if (no)
    {

        impr_pos(no->esq);
        impr_pos(no->dir);
        valorPosfixo[j++] = no->info;
    }
}

void impr_pre(No *no)
{

    if (no)
    {

        valorPrefixo[k++] = no->info;
        impr_pre(no->esq);
        impr_pre(no->dir);
    }
}

void main()
{

    char comando[20], letra;

    No *no = NULL;
    while (scanf("%s%*c", comando) != EOF)
    {

        if (strcmp(comando, "I") == 0)
        {

            scanf("%c", &letra);
            no = ins_abb(letra, no);
        }
        else if (strcmp(comando, "INFIXA") == 0)
            impr_ord(no), impr_ord(valorInfixo);
        else if (strcmp(comando, "PREFIXA") == 0)
            impr_pre(no), impr_pre(valorPrefixo);
        else if (strcmp(comando, "P") == 0)
        {

            scanf("%c", &letra);
            if (busca(no, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        }
        else
            impr_pos(no), impr_pos(valorPosfixo);
    }
}
