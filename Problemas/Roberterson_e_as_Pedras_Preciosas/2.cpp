#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct bloco
{
	int x,y,val;
	bloco(){}

	bloco(int xx, int yy, int vall)
	{
		x = xx;
		y = yy;
		val = vall;
	}

	bool operator < (bloco a) const
	{
		return val < a.val;
	}
};


int n,m,k;
int matriz[1010][1010];
int vis[1010][1010];

priority_queue <bloco> pq;

bool isValid(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void go(int x, int y)
{
	if (isValid(x, y) && !vis[x][y])
	{
		vis[x][y] = 1;
		bloco tmp(x, y, matriz[x][y]);
		pq.push(tmp);
	}
}

int main(void)
{
	while (cin >> n >> m >> k)
	{
		while (!pq.empty())
			pq.pop();
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> matriz[i][j];
				if (i == 1 || j == 1 ||i == n || j == m)
				{
					bloco tmp(i,j,matriz[i][j]);
					vis[i][j] = 1;
					pq.push(tmp);
				}
			}
		}

		long long sum = 0;
		while (!pq.empty() && k)
		{
			bloco b = pq.top();  pq.pop();
			sum += (long long)b.val;
			k--;

			go(b.x,b.y + 1);
			go(b.x,b.y - 1);
			go(b.x + 1,b.y);
			go(b.x - 1,b.y);
		}

		cout << sum << "\n";
	}
	return 0;
}
