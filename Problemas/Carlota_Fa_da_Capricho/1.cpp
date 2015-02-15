#include <iostream>

using namespace std;

int b[100000];

int main()
{
	cin.sync_with_stdio(false);
	int n, t;
	while (cin >> n >> t)
	{
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		int ans = 0;
		int k = -1;
		int sum = 0;
		int bc = 0;
		for (int i = 0; i < n; ++i)
		{
			if (sum + b[i] <= t)
			{
				if (k == -1)
					k = i;
				bc++;
				sum += b[i];
				ans = bc > ans ? bc : ans;
			}
			else
			{
				if (k > -1)
				{
					sum -= b[k];
					sum += b[i];
					k++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}