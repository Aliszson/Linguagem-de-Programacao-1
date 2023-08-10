#include <iostream>
#include <cstring>
#include <queue>

#define MAX 350000

using namespace std;

int dist[MAX], proibido[MAX];

int main(){
	int origem, destino, numProibidos, a, i;
	while(cin >> origem >> destino >> numProibidos, origem | destino | numProibidos){
		memset(dist, -1, sizeof dist);
		memset(proibido, 0, sizeof proibido);
		queue<int> fila;
		for(i = 0; i < numProibidos; i++){
			cin >> a;
			proibido[a] = 1;
		}
		dist[origem] = 0;
		fila.push(origem);
		while(!fila.empty()){
			if(dist[destino] != -1) break;
			int u = fila.front();
			fila.pop();
			if(!proibido[u-1] && u-1 > 0 && dist[u-1] == -1){
				dist[u-1] = dist[u] + 1;
				fila.push(u-1);
			}
			if(!proibido[u+1] && u+1 <= 100000 && dist[u+1] == -1){
				dist[u+1] = dist[u] + 1;
				fila.push(u+1);
			}
			if(u % 2 == 0 && !proibido[u/2] && dist[u/2] == -1){
				dist[u/2] = dist[u] + 1;
				fila.push(u/2);
			}
			if(u*2 <= 100000 && !proibido[u*2] && dist[u*2] == -1){
				dist[u*2] = dist[u] + 1;
				fila.push(u*2);
			}
			if(u*3 <= 100000 && !proibido[u*3] && dist[u*3] == -1){
				dist[u*3] = dist[u] + 1;
				fila.push(u*3);
			}
		}
		cout << dist[destino] << endl;
	}
	return 0;
}
