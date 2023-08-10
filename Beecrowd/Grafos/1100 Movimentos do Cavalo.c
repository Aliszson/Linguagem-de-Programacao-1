#include <stdio.h>
#include <string.h>

#define TAM 9
#define INFINITO 999999999

typedef struct {
    int origem;
    int destino;
    int peso;
} ARESTA;

ARESTA arestas[350];

int BellmanFord(int num_aresta, int num_nodos, int origem, int destino) {
    int i, j, trocou = 1;
    int distancia[65];

    for (i = 0; i <= num_nodos; i++) {
        distancia[i] = INFINITO;
    }

    distancia[origem] = 0;

    for (i = 0; i <= num_nodos && trocou; i++) {
        trocou = 0;
        for (j = 0; j < num_aresta; j++) {
            if (distancia[arestas[j].destino] > distancia[arestas[j].origem] + arestas[j].peso) {
                distancia[arestas[j].destino] = distancia[arestas[j].origem] + arestas[j].peso;
                trocou = 1;
            }
        }
    }
    return distancia[destino];
}

int main() {
    int tabuleiro[TAM][TAM];

    int cont = 1, i, j;
    for (i = 1; i < TAM; i++) {
        for (j = 1; j < TAM; j++) {
            tabuleiro[i][j] = cont++;
        }
    }

    cont = 0;
    for (i = 1; i < TAM; i++) {
        for (j = 1; j < TAM; j++) {
            if ((i + 1) < TAM && (j + 2) < TAM) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 1][j + 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i + 1) < TAM && (j - 2) >= 1) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 1][j - 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i + 2) < TAM && (j + 1) < TAM) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 2][j + 1];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i + 2) < TAM && (j - 1) >= 1) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 2][j - 1];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i - 1) > 0 && (j + 2) < TAM) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 1][j + 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i - 1) > 0 && (j - 2) >= 1) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 1][j - 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i - 2) > 0 && (j + 1) < TAM) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 2][j + 1];
                arestas[cont].peso = 1;
                cont++;
            }
            if ((i - 2) > 0 && (j - 1) >= 1) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 2][j - 1];
                arestas[cont].peso = 1;
                cont++;
            }
        }
    }

    int origem;
    int destino;

    char de[3];
    char para[3];

    while (scanf("%2s %2s", de, para) == 2) {
        origem = (de[0] - 'a') * 8 + de[1] - '0';
        destino = (para[0] - 'a') * 8 + para[1] - '0';

        printf("To get from %s to %s takes %d knight moves.\n", de, para, BellmanFord(cont, 64, origem, destino));

        if (strcmp(de, para) == 0) {
            break;
        }
    }

    return 0;
}