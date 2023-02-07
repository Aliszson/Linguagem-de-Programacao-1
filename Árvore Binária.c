#include <stdio.h>
#include <stdlib.h>

struct no {
  int dado;
  struct no* esquerda;
  struct no* direita;
};

struct no* criarNo(int dado) {
  struct no* novoNo = (struct no*)malloc(sizeof(struct no));
  novoNo->dado = dado;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  return novoNo;
}

struct no* inserir(struct no* no, int dado) {
  if (no == NULL) {
    return criarNo(dado);
  }

  if (dado < no->dado) {
    no->esquerda = inserir(no->esquerda, dado);
  } else if (dado > no->dado) {
    no->direita = inserir(no->direita, dado);
  }
  return no;
}

struct no* pesquisar(struct no* no, int dado) {
  if (no == NULL || no->dado == dado) {
    return no;
  }

  if (no->dado < dado) {
    return pesquisar(no->direita, dado);
  }
  return pesquisar(no->esquerda, dado);
}

int main() {
  struct no* raiz = NULL;
  raiz = inserir(raiz, 50);
  inserir(raiz, 30);
  inserir(raiz, 20);
  inserir(raiz, 40);
  inserir(raiz, 70);
  inserir(raiz, 60);
  inserir(raiz, 80);

  int numero;
  printf("Digite um numero para pesquisar: ");
  scanf("%d", &numero);

  if (pesquisar(raiz, numero) != NULL) {
    printf("Encontrado\n");
  } else {
    printf("Nao Encontrado\n");
  }
  return 0;
}
