#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int n, m, c, k;
int grafo[1010][1010];
int custo[1010];

typedef struct {
    int front, rear;
    int elementos[1010];
} Queue;

void initQueue(Queue *fila) {
    fila->front = -1;
    fila->rear = -1;
}

void enqueue(Queue *fila, int elemento) {
    if (fila->rear == 1010 - 1) {
        printf("Queue is full.\n");
    } else {
        if (fila->front == -1) {
            fila->front = 0;
        }
        fila->rear++;
        fila->elementos[fila->rear] = elemento;
    }
}

int dequeue(Queue *fila) {
    int elemento;
    if (fila->front == -1 || fila->front > fila->rear) {
        printf("Queue is empty.\n");
        return -1;
    }

    elemento = fila->elementos[fila->front];
    fila->front++;
    return elemento;
}

int isEmpty(Queue *fila) {
    if (fila->front == -1 || fila->front > fila->rear) {
        return 1;
    } else {
        return 0;
    }
}

void infinito() {
    int i, j;
    for (i = 0; i <= n; i++) {
        custo[i] = INF;
        for (j = 0; j <= n; j++) {
            grafo[i][j] = INF;
        }
    }
}

int dijkstra(int ori, int dest) {
    custo[ori] = 0;
    Queue fila;
    initQueue(&fila);
    enqueue(&fila, ori);

    while (!isEmpty(&fila)) {
        int i = dequeue(&fila);
        int j;
        for (j = 0; j < n; j++) {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]) {
                custo[j] = custo[i] + grafo[i][j];
                enqueue(&fila, j);
            }
        }
    }

    return custo[dest];
}

int main() {
    while (scanf("%d %d %d %d", &n, &m, &c, &k), (n || m || c || k)) {
        infinito();

        int i;
        for (i = 1; i <= m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (u >= c && v >= c) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }

            if (u >= c && v < c)
                grafo[u][v] = p;

            if (u < c && v >= c)
                grafo[v][u] = p;

            if (u < c && v < c && abs(u - v) == 1) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        printf("%d\n", dijkstra(k, c - 1));
    }

    return 0;
}