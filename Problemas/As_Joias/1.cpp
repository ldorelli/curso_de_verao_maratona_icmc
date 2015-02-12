#include <bits/stdc++.h>

using namespace std;

inline int setBit(int mask, int curr)
{
	return mask | (1 << curr); 
}

inline int getBit(int mask, int curr)
{
	return (mask >> curr) & 1;
}

int n;
int mat[20][20];
int solve(int curr, int mask)
{
	if (curr == n)
	{
		return 0;
	}

	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!getBit(mask, i))
		{
			ret = max(ret, solve(curr + 1, setBit(mask, i)) + mat[curr][i]);
		}
	}

	return ret;
}

int main(void)
{
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mat[i][j];
			}
		}

		cout << solve(0,0) << "\n";
	}
	return 0;
}