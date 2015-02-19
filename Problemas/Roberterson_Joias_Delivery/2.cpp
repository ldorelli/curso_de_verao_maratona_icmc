// Bruno Sanches 2015
#include <bits/stdc++.h>

using namespace std;


int n;
long long soma;
long long d[14][14];
long long dp[14][(1 << 14)];
int a[14];

int getBit(int mask, int curr)
{
	return (mask >> curr) & 1;
}

int setBit(int mask, int curr)
{
	return mask | (1 << curr);
}

long long solve(int curr, int mask)
{

	long long & ret = dp[curr][mask];
	if (ret != -1)
		return ret;

	ret = 1000010000000LL;

	long long cost = soma;
	for (int i = 0; i <= n; ++i)
	{
		if (getBit(mask,i))
			cost -= a[i];
	}

	for (int i = 0; i <= n; ++i)
	{
		if (i == curr)
			continue;
		if (!getBit(mask, i))
		{
			ret = min(ret, solve(i, setBit(mask, i)) + d[curr][i]*cost);
		}
	}

	if (ret == 1000010000000LL)
		ret = 0;
	return ret;
}

int main(void)
{
	while (cin >> n)
	{
		memset(a, 0, sizeof a);
		soma = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			soma += (long long)a[i];
		}

		for (int i = 0; i < n + 1; i++)
		{
			for (int j = 0; j < n + 1; ++j)
			{
				cin >> d[i][j];
			}
		}

		memset(dp, -1, sizeof dp);
		cout << solve(0,setBit(0,0)) << "\n";
	}
	return 0;
}