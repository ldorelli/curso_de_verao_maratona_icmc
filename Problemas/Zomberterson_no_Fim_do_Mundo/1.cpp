#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 257;
const int M = 100;

typedef long long int LL;

LL g[M][8];
LL dp[M][N];
int n, m, d;

LL solve (int x, int mask) {
	if (dp[x][mask] != -1) return dp[x][mask];
	
	LL res = 0;
	for (int i = 0; i < n; ++i) {		
		if (((mask>>i)&1) == 0) { 
			res = max(res, g[x][i]);
			for (int j = x + 1; j < m; ++j) {
				if (abs(g[j][i] - g[x][i]) <= d)  {
					res = max (res, g[x][i] + solve(j, mask | (1<<i)));
				} 
			}
		}
	}
	
	return dp[x][mask] = res;
}

int main (void) {
	while (cin >> n >> m >> d) {
		memset (dp, -1, sizeof dp);
		
		for (int i = 0; i < m; ++i) 
			for (int j = 0; j < n; ++j)
				cin >> g[i][j];

		LL res = 0;
		for (int i = 0; i < m; ++i)
			res = max (res, solve(i, 0));

		cout << res << endl;
	}
	return 0;
}
