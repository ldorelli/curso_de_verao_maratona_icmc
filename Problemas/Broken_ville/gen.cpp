#include <bits/stdc++.h>

using namespace std;

void gera(int n, int m, int q, int f)
{
	int vis[25][25];
	memset(vis, 0, sizeof vis);
	int k;
	if (f)
		k = n*m;
	else
		k = rand()%(n*m);

	cout << n << " " << m << " " << k << "\n";

	for (int i = 0; i < k; ++i)
	{
		int x = rand()%n + 1;
		int y = rand()%m + 1;
		while (vis[x][y])
		{
			x = rand()%n + 1;
			y = rand()%m + 1;
		}

		vis[x][y] = 1;
		cout << x << " " << y << "\n";
	}

	cout << q << "\n";
	for (int i = 0; i < q; ++i)
	{
		cout << rand()%n + 1 << " " << rand()%m + 1 << " " << rand()%n + 1 << " " << rand()%m + 1 << "\n";
	}
}

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		gera(rand()%20 + 1, rand()%20 + 1, rand()%100 + 1, 0); 
	}


	for (int i = 0; i < 5; ++i)
	{
		gera(20, 20, 100000, 0);
	}

	gera(10,10, 10, 1);

	return 0;
}