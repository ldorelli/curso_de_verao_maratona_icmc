// Tomas Fonseca 2015
#include <bits/stdc++.h>

using namespace std;

#define N 10001

vector<int> adj[N];
bool vis[N];

// Recursao semelhante a uma DFS
void preOrdem(int prev, int cur){
	vis[cur] = 1;
	cout << cur << " ";

	for(int i = 0; i < adj[cur].size(); i++){
		if(adj[cur][i] != prev and !vis[adj[cur][i]])
			preOrdem(cur, adj[cur][i]);
	}
}

int main(int argc, char const *argv[])
{
	int n;	
	while(cin >> n){
		// Resetar variaveis 
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
		memset(vis, 0, sizeof(bool) * (n+1));

		// Ler arestas
		for(int i = 0; i < n - 1; i ++)	{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		// Chamar preOrdem	
		preOrdem(-1, 1);
		cout << endl;
	}
    return 0;
}