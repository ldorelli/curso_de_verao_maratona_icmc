#include <bits/stdc++.h>

using namespace std;
#define MAX 50011
vector <int> adj[MAX],cor[MAX];
int n,m,c,a,b;
int dis[MAX];
int vis[MAX];
int last[MAX];

struct node
{
	int cor;
	int id;
	int dis;

	node(int corr, int idd, int diss)
	{
		cor = corr;
		id = idd;
		dis = diss;
	}
};

void bfs(int curr)
{
	memset(vis, 0, sizeof vis);
	memset(last, -1, sizeof last);

	for (int i = 0; i < MAX; ++i)
		dis[i] = 0x3f3f3f3f;

	queue< node > q;
	node tmp(0, curr, 0);
	q.push(tmp);

	vis[curr] = 1;
	dis[curr] = 0;

	while (!q.empty())
	{
		int v = q.front().id;
		int corv = q.front().cor;
		int disv = q.front().dis;
		q.pop();

		if (vis[v] == 2)
			continue;

		if (corv == last[v])
			continue;

		last[v] = corv;
		vis[v]++;

		for (int i = 0; i < adj[v].size(); ++i)
		{
			int u = adj[v][i];
			int coru = cor[v][i];
			if (vis[u] < 2 && coru != corv)
			{
				dis[u] = min(dis[u], disv + 1);
				node tmp(coru, u, disv + 1);
				q.push(tmp);
			}
		}
	}
}

int main(void)
{
	while (cin >> n >> m >> c)
	{
		for (int i = 0; i <= n; ++i)
			adj[i].clear(), cor[i].clear();

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			cor[a].push_back(c);
			cor[b].push_back(c);
		}
		bfs(1);

		if (dis[n] == 0x3f3f3f3f)
			cout << -1 << "\n";
		else
			cout << dis[n] << "\n";
	}
	return 0;
}
