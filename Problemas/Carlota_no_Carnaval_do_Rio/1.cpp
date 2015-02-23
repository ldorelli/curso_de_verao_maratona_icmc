//Anderson Silva, 2014

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

#define N 1003
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

void dfs(int cur) {
	if(used[cur]) return;

	used[cur] = 1;
	for(int i = 0; i < adj[cur].size(); ++i) 
		dfs(adj[cur][i]);
}

int main () {
	ios::sync_with_stdio(0);
	
	int n, m, a, b;
	while(cin >> n >> m) {

		while(m--) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		dfs(1);
		cout << (used[n] ? "S\n" : "N\n");

		memset(used, 0, sizeof used);
		for(int i = 0; i < n; i++)
			adj[i].clear();
	}
	return 0;
}