#include <bits/stdc++.h>

using namespace std;
#define MAX 100010

int last[257];
int nex[MAX];
int n;
string s;
int dp[MAX];

int solve(int curr)
{
	if (curr == n)
		return 0;
	
	if (curr < 0)
	{
		return -0x3f3f3f3f;
	}

	int & ret = dp[curr];
	if (ret != -1)
		return ret;

	ret = solve(curr + 1);
	ret = max(ret, solve(nex[curr] + 1) + 1);

	return ret;
}

int main(void)
{
	while (cin >> n)
	{
		cin >> s;

		for (int i = 0; i <= 256; ++i)
			last[i] = -0x3f3f3f3f;

		for (int i = s.size()-1; i >= 0; --i)
		{
			nex[i] = last[s[i]];
			last[s[i]] = i;
		}

		memset(dp, -1, sizeof dp);
		cout << solve(0) << "\n";
	}
	return 0;
}