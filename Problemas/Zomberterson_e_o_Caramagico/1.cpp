#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100;
const int M = 257;
int C[N][N];
int n;
int dp[N][N][M];
bool vis[N][N];

int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

bool canGo (int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < n and vis[i][j] == 0;
}

int solve (int i, int j, int v, int cdir) {
	
	int &res = dp[i][j][v];
	if (res != -1) return res;

	res = 0;
	vis[i][j] = 1;
	int ni = i + dir[cdir][0];
	int nj = j + dir[cdir][1];
	if (!canGo(ni, nj)) {
		cdir = (cdir + 1)%4;
		ni = i + dir[cdir][0];
		nj = j + dir[cdir][1];
	}
	
	if (canGo(ni, nj)) {
		if (C[i][j] > v) res = 1 + solve(ni, nj, C[i][j], cdir);
		res = max (res, solve(ni, nj,  v, cdir));
	} else if (C[i][j] > v) res = 1;

	vis[i][j] = 0;	

	return res;
}


int main (void) {
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> C[i][j];

		memset (dp, -1, sizeof dp);
		memset (vis, 0, sizeof vis);
		cout << solve(0, 0, 0, 0) << endl;
	}
	return 0;
}