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
#define MAX 20000
#define eps 1e-7
#define ull unsigned long long
#define sync ios :: sync_with_stdio(0)

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int n,f,x,y;
vi adj[MAX];
int pre[MAX];
set<int> s;
int maior, idx;
void dfs(int curr, int p, int d){
	if(d > maior) maior = d, idx = curr;
	
	for(int i=0; i< adj[curr].size(); ++i){
		int u = adj[curr][i];
		if(u != p)
			pre[u] = curr, dfs(u, curr, d + 1);
	}
}
int main(void){
	sync;
	while(cin >> n >> f){
		maior = -INF;
		for(int i=0; i<=n; ++i) adj[i].clear();
		s.clear();
		for(int i=0; i<n-1; ++i){
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		dfs(1,-1, 0);
		maior = -INF;
		int idxbegin = idx;
		dfs(idx,-1, 0);
		int where = idx;
		pre[idxbegin] = -1;
		while(where != -1){
			s.insert(where);
			where = pre[where];
		}
		if(maior >= f){
			printf("%d\n",f+1);
			continue;
		}
		int answ = maior + 1;
		for(int i=1; i<=n && maior+2 <= f; ++i)
			if(!s.count(i)) maior += 2, answ++;
		printf("%d\n",answ);
	}
	return 0;
}