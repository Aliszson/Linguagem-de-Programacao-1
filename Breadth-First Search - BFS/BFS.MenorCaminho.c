#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura para representar um grafo
struct Grafo
{
    int vertices;
    int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];
};

// Funcao para inicializar o grafo
void inicializarGrafo(struct Grafo *grafo, int vertices)
{
    grafo->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            grafo->matrizAdjacencia[i][j] = 0;
        }
    }
}

// Funcao para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo *grafo, int origem, int destino)
{
    grafo->matrizAdjacencia[origem][destino] = 1;
    grafo->matrizAdjacencia[destino][origem] = 1; // Para um grafo nao direcionado
}

// Funcao para exibir a matriz de adjacencia
void exibirMatrizAdjacencia(struct Grafo *grafo)
{
    printf("   ");
    printf("\n   ");
    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("%2d [", i);
        for (int j = 0; j < grafo->vertices; j++)
        {
            printf("%d", grafo->matrizAdjacencia[i][j]);
            if (j < grafo->vertices - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

// Funcao BFS
void BFS(struct Grafo *grafo, int verticeInicial, int verticeDestino)
{
    bool visitado[MAX_VERTICES] = {false};
    int fila[MAX_VERTICES];
    int frente = 0, traseira = 0;
    int predecessores[MAX_VERTICES] = {-1};

    // Marcar o vertice inicial como visitado e adiciona-lo a fila
    visitado[verticeInicial] = true;
    fila[traseira++] = verticeInicial;

    while (frente < traseira)
    {
        int verticeAtual = fila[frente++];
        if (verticeAtual == verticeDestino)
        {
            break;
        }

        // Verificar os vertices adjacentes nao visitados
        for (int i = 0; i < grafo->vertices; i++)
        {
            if (grafo->matrizAdjacencia[verticeAtual][i] == 1 && !visitado[i])
            {
                visitado[i] = true;
                fila[traseira++] = i;
                predecessores[i] = verticeAtual;
            }
        }
    }

    if (predecessores[verticeDestino] == -1)
    {
        printf("Nao existe caminho do vertice %d ao vertice %d\n", verticeInicial, verticeDestino);
    }
    else
    {
        printf("Caminho mais curto do vertice %d ao vertice %d: ", verticeInicial, verticeDestino);

        int caminho[MAX_VERTICES];
        int tamanho = 0;
        int vertice = verticeDestino;
        while (vertice != -1)
        {
            caminho[tamanho++] = vertice;
            vertice = predecessores[vertice];
        }

        for (int i = tamanho - 1; i >= 0; i--)
        {
            printf("%d", caminho[i]);
            if (i > 0)
            {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

// Exemplo de uso
int main()
{
    struct Grafo grafo;
    int vertices, arestas;
    int origem, destino;

    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &vertices);

    inicializarGrafo(&grafo, vertices);

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &arestas);

    for (int i = 0; i < arestas; i++)
    {
        printf("Digite a aresta %d (origem destino): ", i + 1);
        scanf("%d %d", &origem, &destino);
        adicionarAresta(&grafo, origem, destino);
    }

    exibirMatrizAdjacencia(&grafo);

    int verticeInicial, verticeDestino;
    printf("Digite o vertice inicial: ");
    scanf("%d", &verticeInicial);
    printf("Digite o vertice destino: ");
    scanf("%d", &verticeDestino);

    BFS(&grafo, verticeInicial, verticeDestino);

    return 0;
}
