#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define N 10001

vi adj[N];
bool vis[N];

// Uso de bfs para obter o nó mais longe
int farthestNode(int start){
	queue<int> q;
	q.push(start);

	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		vis[cur] = 1;
		for(int i = 0; i < adj[cur].size(); i++){
			if(!vis[adj[cur][i]])
				q.push(adj[cur][i]);
		}
	}

	return cur;
}

// Uso de dfs para obter a maior distancia
int greatestDistance(int cur){
	vis[cur] = 1;
	int mx = 0;

	for(int i = 0; i < adj[cur].size(); i++){
		if(!vis[adj[cur][i]])
			mx = max(mx, 1 + greatestDistance(adj[cur][i]));
	}

	return mx;	
}

int main(int argc, char const *argv[])
{
	int n, f;
	while (cin >> n >> f){
		// Resetar variaveis
		for(int i = 0 ; i <= n; i++){
			adj[i].clear();
		}

		// Ler arestas	
		for(int i = 0; i < n-1; i++){
			int a,b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		// Obter diametro
		memset(vis, 0, sizeof(bool) * (n+1));
		int node = farthestNode(1);
		memset(vis, 0, sizeof(bool) * (n+1));
		int diameter = greatestDistance(node);

		// 2 casos
		if(f <= diameter){
			cout << f + 1 << endl;
		}else{
			int ans = (diameter + 1) + (f-diameter)/2;
			cout << min(ans,n) << endl;
		}

	}
    return 0;
}