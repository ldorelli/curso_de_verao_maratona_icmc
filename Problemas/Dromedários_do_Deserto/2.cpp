// Bruno Sanches, 2014

#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod (ll)10e9
#define B 33
#define MAX 100001
#define eps 1e-7
#define ull unsigned long long
#define sync ios :: sync_with_stdio(0)

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

vi adj[MAX];
int color[MAX];
int n,m,x,y;
int dfs(int curr, int p){
	for(int i=0; i<adj[curr].size(); ++i){
		int u = adj[curr][i];
		if(color[u] == -1){
			color[u] = !color[curr];
			if(dfs(u,curr)) return true;
		}
		else if(u != p && color[u] == color[curr])
			return true;
	}
	return false;
}
int main(void){
	while(scanf("%d%d",&n,&m) != EOF){
		for(int i=0; i<=n; ++i) adj[i].clear(), color[i] = -1;
		for(int i=0; i<m; ++i){
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		printf("%c\n", (dfs(1, -1) == true) ? 'N' : 'S');
	}
	return 0;
}