#include <bits/stdc++.h>

using namespace std;
#define MAX 111
int vis[MAX][MAX];
int vdir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0}};
int dp[MAX * MAX][270];
int mat[MAX][MAX];
int n;
vector<int> v;

void getV(int currx, int curry, int dir)
{
	if (vis[currx][curry])
		return;

	vis[currx][curry] = 1;

	v.push_back(mat[currx][curry]);
	
	int tmpx = currx + vdir[dir][0];
	int tmpy = curry + vdir[dir][1];

	if (vis[tmpx][tmpy])
	{
		dir = (dir + 1)%4;
		tmpx = currx + vdir[dir][0];
		tmpy = curry + vdir[dir][1];
	}

	getV(tmpx, tmpy, dir);

	return;
}

int solve(int curr, int last)
{
	if (curr == v.size())
		return 0;

	int & ret = dp[curr][last];
	if (ret != -1)
		return ret;

	ret = solve(curr + 1, last);
	
	if (v[curr] > last)
		ret = max(ret, solve(curr + 1, v[curr]) + 1);
	return ret;
}

int main(void)
{
	while (cin >> n)
	{
		v.clear();
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i <= n + 1; ++i)
		{
			vis[0][i] = vis[i][0] = 1;
			vis[n + 1][i] = vis[i][n + 1] = 1;
		}

		getV(1,1,0);

		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << "\n";
	}
}