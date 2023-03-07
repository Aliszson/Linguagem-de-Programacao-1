#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char info;
    struct no *esq;
    struct no *dir;
} No;

No *constroi_arvore(char *pre_ordem, char *em_ordem, int tam)
{

    if (tam == 0)
        return NULL;

    No *raiz = (No *)malloc(sizeof(No));
    raiz->info = pre_ordem[0];

    int pos_raiz = 0;
    while (em_ordem[pos_raiz] != pre_ordem[0])
        pos_raiz++;

    raiz->esq = constroi_arvore(pre_ordem + 1, em_ordem, pos_raiz);
    raiz->dir = constroi_arvore(pre_ordem + pos_raiz + 1, em_ordem + pos_raiz + 1, tam - pos_raiz - 1);

    return raiz;
}

void imprime_pos_ordem(No *raiz)
{
    if (raiz == NULL)
        return;

    imprime_pos_ordem(raiz->esq);
    imprime_pos_ordem(raiz->dir);
    printf("%c", raiz->info);
}

int main()
{
    char pre_ordem[27], em_ordem[27];
    No *raiz = NULL;

    while (scanf("%s %s", pre_ordem, em_ordem) != EOF)
    {
        int tam = strlen(pre_ordem); // Calcula o tamanho do vetor de pré-ordem (assumindo que ambos os vetores têm o mesmo tamanho)
        raiz = constroi_arvore(pre_ordem, em_ordem, tam);
        imprime_pos_ordem(raiz);
        printf("\n");
        free(raiz);
    }

    return 0;
}
