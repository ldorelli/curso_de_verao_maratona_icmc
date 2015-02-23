#include <bits/stdc++.h>

using namespace std;

void gera(int n)
{
	cout << n << "\n";
	for (int i = 0; i < n; ++i)
	{
		cout << (char)(rand()%26 + 'a');
		if (i == n - 1)
			cout << "\n";
	}
}

int main(void)
{
	gera(1);
	gera(1);
	gera(2);

	for (int i = 0; i < 10; ++i)
		gera(5);
	for (int i = 0; i < 100; ++i)
		gera(20);

	for (int i = 0; i < 100; ++i)
		gera(1000);

	for (int i = 0; i < 20; ++i)
		gera(100000);
	return 0;
}