// Tomas Fonseca 2015
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
#define N 10000
#define M 10000


vii adj[N];
bool vis[N];
int n, m, a;
int ai[N];

int main(int argc, char const *argv[])
{
	while(scanf("%d%d%d", &n, &m, &a)!=EOF){

		for(int i = 0; i < n; i++){
			adj[i].clear();
			vis[i] = 0;
		}

		ai[0] = 0;

		for(int i = 1; i < n; i++){
			scanf("%d", &ai[i]);
		}

		for(int i = 0; i < m; i++){
			int n1, n2, l;
			scanf("%d%d%d", &n1, &n2, &l);
			adj[n1].pb(mp(n2,l));
			adj[n2].pb(mp(n1,l));
		}

		priority_queue<ii, vii, greater<ii> > pq;
		pq.push(mp(0,0));
		int total = 0;

		while(!pq.empty()){
			ii cur = pq.top();
			pq.pop();

			if(a > cur.F){
				vis[cur.S] = 1;
				total++;
				if(total == n) break;
				a += ai[cur.S];
				for(int i = 0; i < adj[cur.S].size(); i++){
					if(!vis[adj[cur.S][i].F]){
						pq.push(mp(adj[cur.S][i].S, adj[cur.S][i].F));
					}
				}
			}else
				break;
		}

		printf((total == n ? "SIM\n" : "NAO\n"));

	}
    return 0;
}