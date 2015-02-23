#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
int n,k;
int v[10010];
int dp[10010][101];

int main(void)
{
	while (cin >> n >> k)
	{
		for (int i = 1; i <= n; ++i)
			cin >> v[i];

		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				int m = (j + v[i])%k;
				dp[i][j] = dp[i-1][m];
				dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod)%mod;
			}
		}

		cout << dp[n][0] - 1 << "\n";
	}
	return 0;
}