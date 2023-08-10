#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAX 150
#define MAXV 21000
#define INF 1000000000000000LL
using namespace std;
typedef long long int int64;
typedef pair<int, int> ii;
typedef pair<ii, int64> ii_64;
typedef pair<int64, int> ii64;
const double EPS = 1e-10;
struct aresta {
    int a, b;
    int64 c;
};
struct aresta_grafo {
    int u, v, proximo;
    int64 custo, fluxo;
    aresta_grafo(int u = 0, int v = 0, int proximo = 0, int64 custo = 0, int64 fluxo = 0)
        : u(u)
        , v(v)
        , proximo(proximo)
        , custo(custo)
        , fluxo(fluxo)
    {
    }
};
int V, E, A, anterior[MAXV];
int64 f, sp, dist[MAX], p[MAX];
bool visitado[MAX];
vector<aresta_grafo> grafo(MAXV);
vector<aresta> arestas(MAXV);
void adicionarAresta(int u, int v, int64 c, int64 f)
{
    grafo[A] = aresta_grafo(u, v, anterior[u], c, f);
    anterior[u] = A++;
    grafo[A] = aresta_grafo(v, u, anterior[v], -c, 0);
    anterior[v] = A++;
}
void aumentar(int v, int64 minAresta)
{
    for (int i = p[v]; i != -1; i = p[grafo[i].u])
        minAresta = min(minAresta, grafo[i].fluxo);

    for (int i = p[v]; i != -1; i = p[grafo[i].u]) {
        grafo[i].fluxo -= minAresta;
        grafo[i ^ 1].fluxo += minAresta;
    }
    f = minAresta;
}
bool dijkstra(int s, int t)
{
    for (int i = 0; i <= V + 1; ++i) {
        dist[i] = INF;
        p[i] = -1;
        visitado[i] = false;
    }
    queue<int> q;
    dist[s] = 0;
    visitado[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = anterior[u]; i != -1; i = grafo[i].proximo) {
            int v = grafo[i].v;
            if (grafo[i].fluxo && dist[u] + grafo[i].custo < dist[v]) {
                dist[v] = dist[u] + grafo[i].custo;
                p[v] = i;
                if (!visitado[v]) {
                    visitado[v] = true;
                    q.push(v);
                }
            }
        }
        visitado[u] = false;
    }
    sp = dist[t];
    return sp != INF;
}
int main()
{
    int t = 1;
    int64 d, k;
    while (scanf("%d %d", &V, &E) != EOF) {
        printf("Instancia %d\n", t++);
        A = 0;
        for (int i = 0; i <= V + 1; ++i)
            anterior[i] = -1;
        for (int i = 0; i < E; ++i)
            scanf("%d %d %lld", &arestas[i].a, &arestas[i].b, &arestas[i].c);
        scanf("%lld %lld", &d, &k);
        adicionarAresta(0, 1, 0, d);
        adicionarAresta(V, V + 1, 0, d);
        for (int i = 0; i < E; ++i) {
            adicionarAresta(arestas[i].a, arestas[i].b, arestas[i].c, k);
            adicionarAresta(arestas[i].b, arestas[i].a, arestas[i].c, k);
        }
        int64 maxFluxo = 0, resp = 0;
        while (dijkstra(0, V + 1)) {
            f = 0;
            aumentar(V + 1, INF);
            maxFluxo += f;
            resp += sp * f;
            if (maxFluxo == d)
                break;
        }
        if (maxFluxo != d)
            printf("impossivel\n\n");
        else
            printf("%lld\n\n", resp);
    }
    return 0;
}