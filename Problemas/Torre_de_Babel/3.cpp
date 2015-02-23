// Tomas Fonseca 2015
#include <bits/stdc++.h>

using namespace std;

#define N 1001

vector<int> lang[N];
vector<int> adj[N];
bool vis[N];

// DFS que conta nos nao visitados
int dfs(int cur){
	int total = 0;
	if(!vis[cur]){
		vis[cur] = 1;
		total += 1;
	}

	for(int i = 0; i < adj[cur].size(); i++){
		if(!vis[adj[cur][i]])
			total += dfs(adj[cur][i]);
	}

	return total;	
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		// Resetar valores
		for(int i = 0; i <= n; i++){
			lang[i].clear();
			adj[i].clear();
		}
		memset(vis, 0, sizeof vis);

		// Ler entradas e colocar as pessoas nos vetores de lingua certos
		for(int i = 0; i < n; i++){
			int a,b;
			cin >> a >> b;
			lang[a].push_back(i);
			lang[b].push_back(i);
		}

		// Adicionar todas as arestas (todos pares possiveis para cada lingua)
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < lang[i].size(); j++){
				for(int k = j + 1; k < lang[i].size(); k++)	{
					adj[lang[i][j]].push_back(lang[i][k]);
					adj[lang[i][k]].push_back(lang[i][j]);
				}
			}
		}

		// Obter maior grupo
		int curmax = 0;
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				int aux = dfs(i);
				if(aux > curmax)
					curmax = aux;
			}
		}

		cout << curmax << endl;
	}
    return 0;
}