// Shi, 2014

#include <iostream>
#include <vector>

using namespace std;

const int N = 10002;
int mdist, mv;
vector<int> g[N];


void dfs(int v, int p, int d) 
{
	if (d > mdist) mdist = d, mv = v;

	for (int i = 0; i < g[v].size(); ++i)
	{
		int u = g[v][i];
		if (u == p) continue;
		dfs(u, v, d+1);
	}
}

int main (void)
{
	cin.sync_with_stdio(false);

	int n, f, a, b;

	while (cin >> n >> f)
	{

		for (int i = 1; i <= n; ++i) g[i].clear();

		for (int i = 0; i < n-1; ++i)
		{
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		mdist = 0;
		dfs(1, -1, 0);
		mdist = 0;
		dfs(mv, -1, 0);

		int dcount = mdist;

		if (dcount >= f)
		{
			printf("%d\n", f+1);
		} else 
		{
			f -= dcount;
			int r = n - dcount - 1;
			f /= 2;
			int res = dcount + 1;
			if (r >= f) res += f;
			else res += r;
			printf("%d\n", res);
		}
	}
}