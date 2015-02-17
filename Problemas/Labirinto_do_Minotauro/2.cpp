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
int mat[MAX][MAX];
int vis[MAX][MAX];
bool tmp[MAX][MAX]; // marca se o caminho comecando aqui (x,y) leva para fora da matriz (true == leva pra fora)
bool dfs(int x, int y){
	if(x <= 0 || y <= 0 || x > n || y > m) return false;
	if(vis[x][y] && tmp[x][y] == false) return true; // esse caminho nao leva pra fora da matriz
	else if(vis[x][y]) return false;
	
	vis[x][y] = 1;
	
	if(mat[x][y] == '>' || mat[x][y] == '#') 
		if(dfs(x, y + 1)) return true;
	if(mat[x][y] == '<' || mat[x][y] == '#') 
		if(dfs(x, y - 1)) return true;
	if(mat[x][y] == '^' || mat[x][y] == '#') 
		if(dfs(x - 1, y)) return true;
	if(mat[x][y] == 'v' || mat[x][y] == '#')
		if(dfs(x + 1, y)) return true;
	
	tmp[x][y] = true; // leva para fora da matriz
	return false;
}
int main(void){
	while(scanf("%d%d ",&n,&m) != EOF){
		memset(mat, 0, sizeof mat);
		memset(vis, 0, sizeof vis);
		memset(tmp, 0, sizeof tmp);
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j)
				scanf("%c",&mat[i][j]);
			getchar();	
		}
		printf("%c\n",(dfs(1,1)==true)? 'S' : 'N');
	}
	return 0;
}