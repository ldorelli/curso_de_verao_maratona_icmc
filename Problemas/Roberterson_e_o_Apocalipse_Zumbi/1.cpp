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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vi adj[20001];
int dist[20001];
int n,m;


void bfs(int start){
	queue<int> q;

	q.push(start);

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0; i < adj[cur].size(); i++){
			if(dist[adj[cur][i]] == -1){
				dist[adj[cur][i]] = dist[cur] + 1;
				q.push(adj[cur][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &n, &m) != EOF){

		for(int i = 1; i <= n; i++){
			adj[i].clear();
		}

		for(int i = 0; i < m; i++){
			int aux1,aux2;
			scanf("%d %d", &aux1, &aux2);
			adj[aux1].pb(aux2);
			adj[aux2].pb(aux1);
		}
		memset(dist,-1,sizeof(int) *(n+1));
		dist[1] = 0;
		bfs(1);

		vector<int> ans;
		int mx = -1;
		for(int i = 1; i <= n; i++){
			if(dist[i] > mx){
				ans.clear();
				ans.pb(i);
				mx = dist[i];
			}else if(dist[i] == mx){
				ans.pb(i);
			}
		}

		printf("%d %d %d\n", ans[0], mx, (int)ans.size());
	}





    return 0;
}