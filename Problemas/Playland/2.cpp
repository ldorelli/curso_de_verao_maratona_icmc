#include <bits/stdc++.h>

using namespace std;

int n;
int m[13][13];

int getBit(int mask, int curr)
{
	return (mask >> curr) & 1;
}

bool test(int mid, int mask, int j)
{
	int qnt = 0;

	for (int i = 0; i < 12; ++i)
	{
		if (getBit(mask, i))
		{
			if (mid >= m[i][j])
			{
				if (mid > m[i][j] + 3600 - 1)
				{
					qnt += 3600;
				}
				else
				{
					qnt += mid - m[i][j];
				}
			}
		}
	}

	return qnt >= (3600*j)/2;
}

int bs(int lo, int hi, int mask, int cnt)
{
	while (hi - lo > 1)
	{
		int mid = (hi + lo) / 2;
		if (test(mid, mask, cnt))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	if (test(lo, mask, cnt))
	{
		return lo;
	}

	return hi;
}

int solve(int mask)
{
	int cnt = 0;
	for (int i = 0; i < 12; ++i)
	{
		if (getBit(mask, i))
		{
			cnt++;
		}
	}

	return bs(0, 0x3f3f3f3f, mask, cnt);
}

int main(void)
{
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> m[i][j];
			}
		}

		int maior = 0;
		for (int i = 0; i < (1 << n); ++i)
		{
			// printf("ret = %d\n",solve(i));
			maior = max(maior, solve(i));
		}

		cout << maior << "\n";
	}
	return 0;
}