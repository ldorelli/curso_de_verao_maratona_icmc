#include <bits/stdc++.h>

using namespace std;

int n,m,x;
int v[100010];
long long bit[32][2];

long long setBit(long long mask, int pos)
{
	return mask | ( 1LL << pos);
}

int getBit(long long mask, int pos)
{
	return (mask >> pos) & 1LL;
}

int main(void)
{
	while (cin >> n >> m)
	{
		assert(n <= 60);
		memset(bit, 0, sizeof bit);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];

			for (int j = 0; j < 30; ++j)
			{
				if ((v[i] >> j) & 1)
				{
					bit[j][1] = setBit(bit[j][1], i);
				}
				else
				{
					bit[j][0] = setBit(bit[j][0], i);
				}
			}
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> x;
			long long val = (1LL << 60LL) - 1LL;
			for (int j = 0; j < 30; ++j)
			{
				if (!getBit(x, j))
				{
					val = (val & bit[j][0]);
				}
			}

			for (int j = 0; j < 30; ++j)
			{
				if (getBit(x, j))
				{
					if ((val & bit[j][1]) == 0LL)
					{
						val = 0;
						break;
					}
				}
			}

			if (val)
			{
				cout << "Sim" << "\n";
			}
			else
			{
				cout << "Nao" << "\n";
			}
		}
	}
	return 0;
}