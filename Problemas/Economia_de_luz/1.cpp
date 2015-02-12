// Bruno Sanches 2015
#include <iostream>

using namespace std;

int n;
int on[1000010];
int main(void)
{
	while (cin >> n)
	{
		memset(on, 0, sizeof on);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <= n; j += i)
			{
				on[j] = !on[j];
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			cnt = cnt + (on[i] == 1);
		}

		cout << cnt << "\n";
	}
	return 0;
}