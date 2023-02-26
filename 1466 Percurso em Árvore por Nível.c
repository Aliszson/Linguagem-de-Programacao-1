#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int info;
    int nivel;
    struct arv *dir;
    struct arv *esq;
} Arv;

Arv *ins_abb(int c, Arv *raiz)
{
    if (raiz == NULL)
    {
        Arv *n = (Arv *)malloc(sizeof(Arv));
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

void impr_nivel(Arv *a, int n)
{
    if (a != NULL)
    {
        if (a->nivel == n)
        {
            if (a->nivel == 0)
            {
                printf("%i", a->info);
            }
            else
            {
                printf(" %i", a->info);
            }
        }
        impr_nivel(a->esq, n);
        impr_nivel(a->dir, n);
    }
}

void niveis(Arv *a, int n)
{
    if (a != NULL)
    {
        a->nivel = n;          // nível do nó atual é n
        niveis(a->esq, n + 1); // chama a subárvore esquerda com n+1
        niveis(a->dir, n + 1); // chama a subárvore direita com n+1
    }
}

int main()
{
    int numCasos, tamArv, elems;

    scanf("%d", &numCasos);

    for (int i = 1; i <= numCasos; i++)
    {
        scanf("%d", &tamArv);
        Arv *arv2 = NULL;

        for (int j = 0; j < tamArv; j++)
        {
            scanf(" %d", &elems);
            arv2 = ins_abb(elems, arv2);
        }

        printf("Case %d:", i);
        printf("\n");

        niveis(arv2, 0);

        // imprime cada nível da árvore
        for (int j = 0; j < 500; j++)
        {
            impr_nivel(arv2, j);
        }

        printf("\n\n");
        // libera a memória alocada pela árvore
        free(arv2);
    }

    return 0;
}
