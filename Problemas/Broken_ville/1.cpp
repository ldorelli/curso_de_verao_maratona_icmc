#include <bits/stdc++.h>

using namespace std;
#define MAX 21

int n,m,k,x,y,X0,X1,Y0,Y1,q;
int mat[MAX][MAX];
int vis[MAX][MAX];
int dis[MAX][MAX][MAX][MAX];
int t[4][2] = { 
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

void bfs(int sti, int stj)
{
	queue< pair<int,int> > q;
	q.push(make_pair(sti,stj));

	dis[sti][stj][sti][stj] = 0;
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (i <= 0 || j <= 0 || i > n || j > m)
			continue;

		if (vis[i][j])
			continue;

		vis[i][j] = 1;

		for (int k = 0; k < 4; ++k)
		{
			int eni = i + t[k][0];
			int enj = j + t[k][1];
			if (!mat[eni][enj])
			{
				int & tmp = dis[sti][stj][eni][enj];
				tmp = min(tmp, dis[sti][stj][i][j] + 1);
				q.push(make_pair(eni, enj));
			}
		}
	}

}

int main(void)
{
	while (cin >> n >> m >> k)
	{
		memset(mat, 0, sizeof mat);
		memset(dis, 0, sizeof dis);

		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				for (int ii = 0; ii <= n; ++ii)
				{
					for (int jj = 0; jj <= m; ++jj)
						dis[i][j][ii][jj] = 0x3f3f3f3f;
				}
			}
		}
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			mat[x][y] = 1;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!mat[i][j])
				{
					memset(vis, 0, sizeof vis);
					bfs(i,j);
				}
			}
		}

		cin >> q;

		for (int i = 0; i < q; ++i)
		{
			cin >> X0 >> Y0 >> X1 >> Y1;
			if (dis[X0][Y0][X1][Y1] != 0x3f3f3f3f)
				cout << dis[X0][Y0][X1][Y1] << "\n";
			else
				cout << -1 << "\n";
		}
	}

	return 0;
}