//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

#define N 10001
#define M 100001

vector<pair <int, int> > adj[N];
bool vis[N];

// DFS com valor maximo das arestas
bool dfs(int cur, int target, int mxtime){
	vis[cur] = 1;
	if(cur == target)
		return true;
	else{
		bool found = false;
		for(int i = 0; i < adj[cur].size(); i++){	
			if(!vis[adj[cur][i].first] and adj[cur][i].second <= mxtime){
				if(dfs(adj[cur][i].first, target, mxtime))
					found = true;
			}
		}
		return found;	
	}
}

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n >> m){
		// Resetar variaveis
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}

		// Ler arestas
		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		// Busca binaria no tempo
		int hi = 1000000000;
		int lo = 0;
		while(hi > lo){
			int mid = (hi+lo)/2;
			memset(vis, 0, sizeof(bool) * (n+1));
			if(dfs(1, n, mid)){
				hi = mid;
			}else{
				lo = mid+1;
			}
		}

		cout << lo << endl;
	}

    return 0;
}