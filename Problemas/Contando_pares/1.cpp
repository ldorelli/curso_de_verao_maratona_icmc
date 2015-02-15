#include <bits/stdc++.h>

using namespace std;
#define MAX 100010

int n,m;
int v[MAX];
int v2[MAX];

int main(void)
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> v2[i];
		}

		sort(v, v + n);
		sort(v2, v2 + m);

		long long maior = 0;
		long long menor = 0;
		long long igual = 0;

		for (int i = 0; i < n; ++i)
		{
			//quantos caras sao menor que v[i]
			int pos = lower_bound(v2, v2 + m, v[i]) - v2;
			pos--;
			if (pos >= 0)
			{
				maior += (pos + 1);
			}

			//quantos caras sao iguais a v[i]
			int pos2 = upper_bound(v2, v2 + m, v[i]) - v2;
			pos++;
			pos2--;
			if (pos2 >= pos)
			{
				igual = igual + (pos2 - pos + 1);
			}

			//quantos sao maiores que v[i]
			pos2++;
			menor += (m - pos2);
		}

		cout << maior << " " << menor << " " << igual << "\n";
	}
	return 0;
}