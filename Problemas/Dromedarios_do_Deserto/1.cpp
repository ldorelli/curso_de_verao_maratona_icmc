// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <vector>
#include <string.h>

#define N 100003
#define ll long long
#define mp make_pair
#define pb push_back
#define F first 
#define S second 
#define mod 10e9 + 7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi adj[N];
int used[N];
int n, m;

void dfs(int cur, int color) {
	if(used[cur] != -1) return;
	
	used[cur] = color;
	for(int j = 0; j < adj[cur].size(); ++j)
		dfs(adj[cur][j], !color);
}

bool check(){
	memset(used, -1, sizeof used);
	dfs(1, 0);

	for(int i = 1; i <= n; ++i)  
		for(int j = 0; j < adj[i].size(); ++j)
			if(used[i] == used[adj[i][j]])  return false;
	return true;
}
int main () {
	ios::sync_with_stdio(0);
	
	int a, b;
	while(cin >> n >> m) {

		while(m--) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		bool result = check();

		cout << (result ? "S\n" : "N\n");

		for(int i = 0; i <= n; ++i)
			adj[i].clear();
	}
	return 0;
}