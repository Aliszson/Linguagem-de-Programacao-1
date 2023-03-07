#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char info;
    struct No *esq;
    struct No *dir;
} No;

No *criaNo(char info) {
    No *novo = (No *) malloc(sizeof(No));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *insere(No *raiz, char info) {
    if (raiz == NULL) {
        return criaNo(info);
    } else if (info < raiz->info) {
        raiz->esq = insere(raiz->esq, info);
    } else if (info > raiz->info) {
        raiz->dir = insere(raiz->dir, info);
    }
    return raiz;
}

void infixa(No *raiz) {
    if (raiz != NULL) {
        infixa(raiz->esq);
        printf("%c ", raiz->info);
        infixa(raiz->dir);
    }
}

void prefixa(No *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->info);
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void posfixa(No *raiz) {
    if (raiz != NULL) {
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        printf("%c ", raiz->info);
    }
}

int pesquisa(No *raiz, char info) {
    if (raiz == NULL) {
        return 0;
    } else if (info < raiz->info) {
        return pesquisa(raiz->esq, info);
    } else if (info > raiz->info) {
        return pesquisa(raiz->dir, info);
    } else {
        return 1;
    }
}

int main() {
    char comando[10], info;
    No *raiz = NULL;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &info);
            raiz = insere(raiz, info);
        } else if (strcmp(comando, "INFIXA") == 0) {
            infixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            prefixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            posfixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &info);
            if (pesquisa(raiz, info)) {
                printf("%c existe\n", info);
            } else {
                printf("%c nao existe\n", info);
            }
        }
    }

    return 0;
}
