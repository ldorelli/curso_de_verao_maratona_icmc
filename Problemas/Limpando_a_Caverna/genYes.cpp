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
#define T 15
#define N 10000
#define M 10000
#define A 10000
#define AI 10000
#define L 100000000


int n, m, a;
int ai[N];
bool vis[N];
vi adj[N];
set<ii> edges;
map<ii, ll> edgeLevel;

ll dfs(int cur, int atk){
	vis[cur] = 1;
	ll total = ai[cur];
	atk += ai[cur];
	for(int i = 0; i < adj[cur].size(); i++){
		if(!vis[adj[cur][i]]){
			edgeLevel[mp(min(cur, adj[cur][i]), max(cur, adj[cur][i]))] = atk - 1;
			ll aux = dfs(adj[cur][i], atk);
			atk += aux;
			total += aux;
		}
	}

	return total;
}

int main(int argc, char const *argv[])
{
	srand(clock());
	for(int t = 0; t < T; t++){
		edges.clear();
		edgeLevel.clear();

		// Valores da primeira linha
		int n = rand()%(N-1) + 2;
		int deltam = min(M,(n * (n-1))/2) - (n-1);
		int m = n-1 + rand()%(deltam+1);
		//int a = rand()%A + 1;
		int a = rand()%(A-1) + 2;

		cout << n << " " << m << " " << a << endl;

		// Valores da segunda linha
		ai[0] = 0;
		for(int i = 1; i < n; i++){
			ai[i] = rand()%AI + 1;
			cout << ai[i] << " ";
		}
		cout << endl;

		for(int i = 0; i < n; i++){
			adj[i].clear();
		}

		// criar arestas
		vi auxv;
		for(int i = 0; i < n; i++){
			auxv.pb(i);
		}
		random_shuffle(auxv.begin(), auxv.end());

		// gerar arvore
		for(int i = 1; i < n; i++){
			int a = auxv[i-1];
			int b = auxv[i];

			adj[a].pb(b);
			adj[b].pb(a);
			edges.insert(mp(min(a,b),max(a,b)));
		}

		memset(vis, 0, sizeof vis);

		// colocar pesos validos nas arvores(navegar a partir de 0)
		dfs(0, a);

		// preencher o resto
		for(int i = n-1; i < m; i++){
			int a = rand()%n;
			int b = rand()%n;
			while(a == b || edges.count(mp(min(a,b), max(a,b)))){
				a = rand()%n;
				b = rand()%n;
			}

			edges.insert(mp(min(a,b), max(a,b)));
			adj[a].pb(b);
			adj[b].pb(a);
		}

		for(set<ii> :: iterator it = edges.begin(); it != edges.end(); it++){
			if(!edgeLevel.count(*it))
				edgeLevel[mp((*it).F,(*it).S)] = rand()%L + 1;
		}

		vector<ii> edgesList(edges.begin(), edges.end());
		random_shuffle(edgesList.begin(), edgesList.end());
		for(int i = 0; i < m; i++){
			int a = edgesList[i].F;
			int b = edgesList[i].S;
			int l = edgeLevel[edgesList[i]];
			if(rand()%2){
				cout << a << " " << b << " " << (rand()%2 ? l : max(1, l-1)) << endl;
			}else{
				cout << b << " " << a << " " << (rand()%2 ? l : max(1, l-1)) << endl;
			}
		}

	}
    return 0;
}