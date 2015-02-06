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
#define MAX 2010
#define eps 1e-7
#define ull unsigned long long
#define sync ios :: sync_with_stdio(0)

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int n,m;
char mat[MAX][MAX];
int vis[MAX][MAX];
int dfs(int x, int y){
	if(x <= 0 || y <= 0 || x > n || y > m) return 0;
	if(vis[x][y] || mat[x][y] == 'o') return 0;
	
	
	vis[x][y] = 1;
	
	int ret = dfs(x + 1, y);
	ret += dfs(x, y + 1);
	ret += dfs(x-1, y);
	ret += dfs(x, y-1);
	
	return ret + 1;
}
int main(void){
	while(scanf("%d%d ",&n,&m)!= EOF){
		memset(vis, 0, sizeof vis);
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j)
				scanf("%c ",&mat[i][j]);
		}
		printf("%d\n",dfs(1,1));
	}
	return 0;
}