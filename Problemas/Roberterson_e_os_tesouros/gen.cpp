#include <bits/stdc++.h>

using namespace std;

void gera(int n, int k)
{
	cout << n << " " << k << "\n";
	for (int i = 0; i < n; ++i)
	{
		cout << rand()%200010010 + 1;
		if (i == n - 1)
			cout << "\n";
		else
			cout << " ";
	}
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 20; ++i)
		gera(rand()%10 + 1, 2);

	for (int i = 0; i < 20; ++i)
		gera(rand()%1000 + 1, 2);
	
	for (int i = 0; i < 20; ++i)
		gera(rand()%1000 + 1, 100);
	
	for (int i = 0; i < 10; ++i)
		gera(10000, 100);

	return 0;
}