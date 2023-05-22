#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura para representar um grafo
struct Grafo {
    int vertices;
    int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];
};

// Funcao para inicializar o grafo
void inicializarGrafo(struct Grafo* grafo, int vertices) {
    grafo->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo->matrizAdjacencia[i][j] = 0;
        }
    }
}

// Funcao para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo* grafo, int origem, int destino) {
    grafo->matrizAdjacencia[origem][destino] = 1;
    grafo->matrizAdjacencia[destino][origem] = 1; // Para um grafo nao direcionado
}

// Funcao para exibir a matriz de adjacencia
void exibirMatrizAdjacencia(struct Grafo* grafo) {
    printf("   ");
    for (int i = 0; i < grafo->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < grafo->vertices; i++) {
        printf("%2d [", i);
        for (int j = 0; j < grafo->vertices; j++) {
            printf("%d", grafo->matrizAdjacencia[i][j]);
            if (j < grafo->vertices - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

// Funcao BFS
void BFS(struct Grafo* grafo, int verticeInicial) {
    bool visitado[MAX_VERTICES] = { false };
    int fila[MAX_VERTICES];
    int inicio = 0, proxFila = 0;

    // Marcar o vertice inicial como visitado e adiciona-lo a fila
    visitado[verticeInicial] = true;
    fila[proxFila++] = verticeInicial;

    printf("Busca em Largura (BFS) a partir do vertice %d: ", verticeInicial);

    while (inicio < proxFila) {
        int verticeAtual = fila[inicio++];
        printf("%d ", verticeAtual);

        // Verificar os vertices adjacentes nao visitados
        for (int i = 0; i < grafo->vertices; i++) {
            if (grafo->matrizAdjacencia[verticeAtual][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                fila[proxFila++] = i;
            }
        }
    }

    printf("\n");
}

// Exemplo de uso
int main() {
    struct Grafo grafo;
    int vertices, arestas;
    int origem, destino;

    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &vertices);

    inicializarGrafo(&grafo, vertices);

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &arestas);

    for (int i = 0; i < arestas; i++) {
        printf("Digite a aresta %d (origem destino): ", i + 1);
        scanf("%d %d", &origem, &destino);
        adicionarAresta(&grafo, origem, destino);
    }

    exibirMatrizAdjacencia(&grafo);

    int verticeInicial;
    printf("Digite o vertice inicial para a busca em largura (BFS): ");
    scanf("%d", &verticeInicial);

    BFS(&grafo, verticeInicial);

    return 0;
}
