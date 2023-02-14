#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct arv
{
    char info;
    struct arv *dir;
    struct arv *esq;
} Arv;

Arv *ins_abb(char c, Arv *raiz)
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

void impr_pre(Arv *a)
{
    if (a != NULL)
    {
        printf(" %c", a->info); // raiz
        impr_pre(a->esq);       // sub esq
        impr_pre(a->dir);       // sub dir
    }
}

void impr_ord(Arv *a)
{
    if (a != NULL)
    {
        impr_ord(a->esq);       // sub esq
        printf(" %c", a->info); // raiz
        impr_ord(a->dir);       // sub dir
    }
}

void impr_pos(Arv *a)
{
    if (a != NULL)
    {
        impr_pos(a->esq);       // sub esq
        impr_pos(a->dir);       // sub dir
        printf(" %c", a->info); // raiz
    }
}

int main(int argc, char const *argv[])
{
    char letraComando, letraArv;
    int valor, numInt, intNN;
    Arv *arv2 = NULL;

    scanf("%c", &letraComando);



    while ((letraComando >= 65 && letraComando <= 90) || (letraComando >= 97 && letraComando <= 122))
    {
      
        if (letraComando == 'I')
        {
            fflush(stdin);
            scanf("%c", &letraArv);
            arv2 = ins_abb(letraArv, arv2);
              printf("A");
        }

        if (letraComando == 'INFIXA')
        {
            impr_ord(arv2);
        }
        
        


        
        // for (int i = 1; i <= letraComando; i++)
        // {
        //     scanf("%i", &numInt);
        //     Arv *arv2 = NULL;

        //     for (int j = 0; j < numInt; j++)
        //     {
        //         scanf("%c", &intNN);
        //         arv2 = ins_abb(intNN, arv2);
        //     }

        //     printf("Case %i:\n", i);
        //     printf("Pre.:");
        //     impr_pre(arv2);
        //     printf("\n");
        //     printf("In..:");
        //     impr_ord(arv2);
        //     printf("\n");
        //     printf("Post:");
        //     impr_pos(arv2);
        //     printf("\n\n");
        // }
    }
    

    return 0;
}
