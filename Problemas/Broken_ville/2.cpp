// Tomas Fonseca 2015
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 2000000000
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

bool broken[20][20];
bool vis[20][20];
int dist[20][20][20][20];
int n, m, I;

void bfs(int l, int c){
	queue<ii> q;
	q.push(mp(l,c));
	dist[l][c][l][c] = 0;
	while(!q.empty()){
		ii aux = q.front();
		q.pop();

		if((aux.F > 0)&&(!broken[aux.F-1][aux.S])&&(dist[l][c][aux.F-1][aux.S] == -1)){
			q.push(mp(aux.F-1, aux.S));
			dist[l][c][aux.F-1][aux.S] = dist[l][c][aux.F][aux.S] + 1;
		}
		if((aux.F < n-1)&&(!broken[aux.F+1][aux.S])&&(dist[l][c][aux.F+1][aux.S] == -1)){
			q.push(mp(aux.F+1, aux.S));
			dist[l][c][aux.F+1][aux.S] = dist[l][c][aux.F][aux.S] + 1;
		}
		if((aux.S > 0)&&(!broken[aux.F][aux.S-1])&&(dist[l][c][aux.F][aux.S-1] == -1)){
			q.push(mp(aux.F, aux.S-1));
			dist[l][c][aux.F][aux.S-1] = dist[l][c][aux.F][aux.S] + 1;
		}
		if((aux.S < m - 1)&&(!broken[aux.F][aux.S+1])&&(dist[l][c][aux.F][aux.S+1] == -1)){
			q.push(mp(aux.F, aux.S+1));
			dist[l][c][aux.F][aux.S+1] = dist[l][c][aux.F][aux.S] + 1;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	while(cin >> n >> m >> I){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				broken[i][j] = 0;
			}
		}

		for(int i = 0; i < I; i++){
			int aux1, aux2;
			cin >> aux1 >> aux2;
			broken[aux1-1][aux2-1] = 1;
		}

		memset(dist, -1, sizeof dist);
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!broken[i][j]){
					bfs(i,j);
				}
			}
		}

		int q;
		cin >> q;
		for(int i = 0; i < q; i++){
			int a1,a2,a3,a4;
			cin >> a1 >> a2 >> a3 >> a4;
			cout << dist[a1-1][a2-1][a3-1][a4-1] << endl;
		}
	}

    return 0;
}