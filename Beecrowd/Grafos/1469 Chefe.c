#include <stdio.h>
#include <string.h>

#define MAXV 500 // quantidade máxima de vértices
#define ADJACENTE 1
#define NAO_ADJACENTE 0

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

char matriz_adj[MAXV + 1][MAXV + 1]; // matriz de adjacências
int quantidade_vertices; // quantidade de vértices
int cor[MAXV + 1]; // cor
int tempo_descoberta[MAXV + 1]; // tempo de descoberta
int tempo_termino[MAXV + 1]; // tempo de término
int antecessor[MAXV + 1]; // antecessor na árvore de busca
int tempo; // tempo corrente durante execução do algoritmo

int idades[MAXV + 1];
int idade;

void DFS_VISIT(int u){
	cor[u] = CINZA;
	tempo++;
	tempo_descoberta[u] = tempo;

	int v;
	for(v = 1; v <= quantidade_vertices; v++){
		if(matriz_adj[u][v] == ADJACENTE){ //se v é adjacente a u
			if(cor[v] == BRANCO){
        if (idades[v] < idade) idade = idades[v];
				antecessor[v] = u;
				DFS_VISIT(v);
			}
		}
	}

	cor[u] = PRETO;
	tempo++;
	tempo_termino[u] = tempo;
}

void DFS(int funcionario){
  idade = 1000;
  int u;
	for(u = 1; u <= quantidade_vertices; u++){
		cor[u] = BRANCO;
		tempo_descoberta[u] = NULO;
		tempo_termino[u] = NULO;
		antecessor[u] = NULO;
	}

	tempo=0;
	
	if(cor[funcionario] == BRANCO)
		DFS_VISIT(funcionario);

}
void imprimir(int vet[]){
	int i;
	for(i = 1; i <= quantidade_vertices; i++){
		printf("%d, ", vet[i]);
	}
	printf("\n");
}

void inicializar(){
	memset(matriz_adj, NAO_ADJACENTE, sizeof(matriz_adj));
}

void troca(int gerente, int gerido) {
  int auxiliar, i, j;
  for (i = 1; i <= quantidade_vertices; i++) {
    auxiliar = matriz_adj[gerente][i];
    matriz_adj[gerente][i] = matriz_adj[gerido][i];
    matriz_adj[gerido][i] = auxiliar;
  }

  for (i = 1; i <= quantidade_vertices; i++) {
    auxiliar = matriz_adj[i][gerente];
    matriz_adj[i][gerente] = matriz_adj[i][gerido];
    matriz_adj[i][gerido] = auxiliar;
  }
}

int main(){
  int numeroDePessoas, numeroDeRelacoes, numeroDeInstrucoes;
  int funcionario;
  while (scanf("%d %d %d",&numeroDePessoas ,&numeroDeRelacoes ,&numeroDeInstrucoes) != EOF) {
    inicializar();
    quantidade_vertices = numeroDePessoas;

    int i, j;
    for (i = 1; i <= numeroDePessoas; i++) {
      scanf("%d", &idades[i]);
    }

    int gerente, gerido;
    for (i = 1; i <= numeroDeRelacoes; i++) {
      scanf("%d %d", &gerente, &gerido);
      matriz_adj[gerido][gerente] = ADJACENTE;
    }

    char tipoInstrucao;
    for (i = 1; i <= numeroDeInstrucoes; i++) {
      scanf(" %c", &tipoInstrucao);

      if (tipoInstrucao == 'P') {
        scanf("%d", &funcionario);
        DFS(funcionario);
        if (idade == 1000) printf("*\n");
        else printf("%d\n", idade);
      }
      if (tipoInstrucao == 'T') {
        scanf("%d %d", &gerente, &gerido);
        troca(gerente, gerido);
      }
    }
  }
	return 0;
}