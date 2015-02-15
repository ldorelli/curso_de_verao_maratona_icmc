// Bruno Adami, 2014

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;

int vet[N], dir[N], n, d;

int main()
{
	ios::sync_with_stdio(0);
	
	while (cin >> n >> d)
	{
		for (int i = 0; i < n; ++i)
			cin >> vet[i] >> dir[i];
		
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			if (dir[i] == 1) // esquerda
			{
				res = max(res, vet[i]);
			}
			else // direita
			{
				res = max(res, d-vet[i]);
			}
		}
		cout << res << '\n';
	}
}